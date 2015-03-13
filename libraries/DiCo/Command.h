#ifndef dico_rpc_Command_H
#define dico_rpc_Command_H

#include "Arduino.h"
#include "Device.h"
#include "ArrayT.h"

class Command
{
public:
  class Param
  {
  private:
    String name;
    int type;
    union Val
    {
      char c;
      int i;
      long l;
    } val;

  public:
    enum {CHAR, INT, LONG};
    Param();
    ~Param();
    Param(const char* _name);
    Param(const char* _name, int _type);
    Param(int val);
    operator char(){return val.c;}
    operator int(){return val.i;}
    operator long(){return val.l;}
  };

protected:
  String cmd_name;
  ArrayT<Param>* params;
public:
  Command();
  Command(const char*);
  Command(const char*, int);
  ~Command();
  int paramAdd(Param p);
  String nameGet() { return cmd_name; }
  Param paramGet(int i){ return params->item(i); }
  virtual Device* dev(){ return (Device*)NULL; }
};

template <class pDeviceDerived> class CommandT:
public Command
{
public:
  pDeviceDerived device;
  CommandT(const char* name, const pDeviceDerived, int);
  CommandT(const char* name, const pDeviceDerived);
  virtual pDeviceDerived dev(){return device;}
};

template <class pDeviceDerived> CommandT <pDeviceDerived>::CommandT(const char* name, const pDeviceDerived dev, int param_count):
Command(name, param_count)
{
  device = dev;
}

template <class pDeviceDerived> CommandT <pDeviceDerived>::CommandT(const char* name, const pDeviceDerived dev):
Command(name, 0)
{
  device = dev;
}

#endif