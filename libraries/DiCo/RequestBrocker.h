#ifndef  RequestBrocker_h
#define  RequestBrocker_h

#include "Request.h"
#include "Arduino.h"
#include "AssocArrayT.h"

class Dispatcher
{
protected:
  Request::Param result;
public:
  Dispatcher(){};
  ~Dispatcher(){};
  virtual Request::Param dispatch(Request* c){ return result; }
};

class RequestBrocker
{
private:
  static Dispatcher* dispatcher;
  static Stream* transport;
  static AssocArrayT<Request*> requests;
  static String buffer;
  static bool Request_dispatching;
  
public:
  RequestBrocker();
  static Request* RequestAdd(Request* c);
  Request* RequestGet(const char*);
  Request* RequestGet(String);
  void dispatcherAttach(Dispatcher* d){dispatcher = d;}
  void serialEvent();
  void dispatch();
};

//extern RequestBrocker brocker;

#define DISPATCH_BEGIN \
class MyDispatcher:\
public Dispatcher\
{\
public:\
  MyDispatcher():Dispatcher(){}\
  ~MyDispatcher(){};\
  Request::Param dispatch(Request* c)\
  {\
    String action(c->nameGet());

#define DISPATCH_END    return result;\
  }\
}\
dispatcher;

#define DISPATCH_COMMAND(name, type, func) if ( action == name ) ((type*)(c->dev()))->func();
#define DISPATCH_COMMAND_INT(name, type, func) if ( action == name ) ((type*)(c->dev()))->func((int)(*c->paramGet(0)));

#endif