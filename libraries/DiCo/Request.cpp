#include "Request.h"
#include "Arduino.h"
#include "RequestBrocker.h"

//////////////////////////
// Param
//////////////////////////


Request::Param::Param(const char* _name, int _type)
{
  name = String(_name);
  type = _type;
}

Request::Param::Param(const char* _name)
{
  Param(_name, INT);
}

Request::Param::Param(int ival)
{
   Param("", INT);
   val.i = ival;
}

Request::Param::Param()
{
  Param("", INT);
}

void Request::Param::set(int _val)
{
  val.i = _val;
}

Request::Param::~Param()
{
}

//////////////////////////
// Request
//////////////////////////

Request::Request(const char* _name, int param_count)
{
  params = new ArrayT<Param*>(param_count);
  cmd_name = _name;
}

Request::Request(const char* _name)
{
  Request(_name, 0);
}

Request::Request()
{
  Request("", 0);
}

Request::~Request()
{
  int size = params->sizeGet();
  if (size)
  {
    for (int i=0; i < size; i++) delete &params[i];
  }
  delete params;
}

Request::Param* Request::paramGet(int i)
{
  return params->item(i);
}

int Request::paramAdd(int val)
{
  Param* p = new Param(val);
  return params->add(p);
}

void Request::paramSet(int i, int val)
{
  if (i < params->sizeGet()) params->item(i)->set(val);
  else paramAdd(val);
}
