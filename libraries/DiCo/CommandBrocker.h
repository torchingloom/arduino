#ifndef  CommandBrocker_h
#define  CommandBrocker_h

#include "Command.h"
#include "Arduino.h"
#include "AssocArrayT.h"

class ClientProxy
{
protected:
  Command::Param result;
public:
  ClientProxy(){};
  ~ClientProxy(){};
  virtual Command::Param dispatch(Command* c){ return result; }
};

class CommandBrocker
{
private:
  int count;
  ClientProxy* proxy;
  Stream* transport;
  AssocArrayT<Command*>* commands;
  String buffer;
  bool command_dispatching;
  
public:
  CommandBrocker();
  CommandBrocker(int);
  ~CommandBrocker();
  Command* commandAdd(Command* c);
  Command* commandGet(const char*);
  Command* commandGet(String);
  void proxyAttach(ClientProxy* p){proxy = p;}
  void transportAttach(Stream* t){transport = t;}
  void serialEvent();
  void dispatch();
};

#define RPC_BEGIN \
class MyProxy:\
public ClientProxy\
{\
public:\
  MyProxy():ClientProxy(){}\
  ~MyProxy(){};\
  Command::Param dispatch(Command* c)\
  {\
    String action(c->nameGet());\

#define RPC_END    return result;\
  }\
} \
proxy;

#define RPC_COMMAND(name, type, func) if ( action == name ) ((type*)(c->dev()))->func();

#endif