#include <RequestBrocker.h>
#include "Arduino.h"

AssocArrayT<Request*> RequestBrocker::requests = AssocArrayT<Request*>(1);
Dispatcher* RequestBrocker::dispatcher = NULL;
Stream* RequestBrocker::transport = &Serial;
String RequestBrocker::buffer = "";
bool RequestBrocker::Request_dispatching = false;

RequestBrocker::RequestBrocker()
{
  buffer.reserve(200);
}

Request* RequestBrocker::RequestAdd(Request* r)
{
  RequestBrocker::requests.add(r->nameGet(), r);
}

Request* RequestBrocker::RequestGet(String name)
{
  Request** r = requests.find(name);
  return *r;
}

Request* RequestBrocker::RequestGet(const char* name)
{
  return RequestGet(String(name));
}

void RequestBrocker::serialEvent()
{
  if (Request_dispatching) return;
  char c;
  while (transport->available())
  {
    c = (char) transport->read();
    buffer += c;
    if (c == ';') break;
  }
  if (c == ';') dispatch();
}


void RequestBrocker::dispatch()
{
  Request_dispatching = true;
  // parse
  int first_brace = buffer.indexOf('(');
  if (first_brace > 0)
  {
    String request_name = buffer.substring(0, first_brace);
    Request* r = RequestGet(request_name);
    // parse param
    int second_brace = buffer.indexOf(')');
    if (second_brace > 0 and first_brace != second_brace)
    {
	r->paramSet(0, (int)buffer.substring(first_brace+1, second_brace).toInt());
    }
    if (r) dispatcher->dispatch(*(requests.find(request_name)));	
  }

  buffer ="";
  Request_dispatching = false;
}

