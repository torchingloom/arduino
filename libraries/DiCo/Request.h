#ifndef dico_rpc_Request_H
#define dico_rpc_Request_H

#include "Arduino.h"
#include "Device.h"
#include "ArrayT.h"

class Request
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
    void set(int val);
    operator char(){return val.c;}
    operator int(){return val.i;}
    operator long(){return val.l;}
  };

protected:
  String cmd_name;
  ArrayT<Param*>* params;
public:
  Request();
  Request(const char*);
  Request(const char*, int);
  ~Request();
  int paramAdd(int);
  void paramSet(int, int);
  String nameGet() { return cmd_name; }
  Param* paramGet(int);
  virtual Device* dev(){ return (Device*)NULL; }
};

template <class pDeviceDerived> class RequestT:
public Request
{
public:
  pDeviceDerived device;
  RequestT(const char* name, const pDeviceDerived, int);
  RequestT(const char* name, const pDeviceDerived);
  virtual pDeviceDerived dev(){return device;}
};

template <class pDeviceDerived> RequestT <pDeviceDerived>::RequestT(const char* name, const pDeviceDerived dev, int param_count):
Request(name, param_count)
{
  device = dev;
}

template <class pDeviceDerived> RequestT <pDeviceDerived>::RequestT(const char* name, const pDeviceDerived dev):
Request(name, 0)
{
  device = dev;
}

#endif