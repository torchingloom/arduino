#include <CommandBrocker.h>

CommandBrocker::CommandBrocker(int command_count)
{
  commands = new AssocArrayT<Command*>(command_count);
  buffer.reserve(200);
  command_dispatching = false;
}

CommandBrocker::CommandBrocker()
{
  CommandBrocker(5);
}

CommandBrocker::~CommandBrocker()
{
  delete commands;
}

Command* CommandBrocker::commandAdd(Command* c)
{
  commands->add(c->nameGet(), c);
}

Command* CommandBrocker::commandGet(String name)
{
  Command** c = commands->find(name);
  return *c;
}

Command* CommandBrocker::commandGet(const char* name)
{
  return commandGet(String(name));
}

void CommandBrocker::serialEvent()
{
  if (command_dispatching) return;
  char c;
  while (transport->available())
  {
    c = (char) transport->read();
    buffer += c;
    if (c == ';') break;
  }
  if (c == ';') dispatch();
}


void CommandBrocker::dispatch()
{
  command_dispatching = true;
  // parse
  int first_brace = buffer.indexOf('(');
  if (first_brace > 0)
  {
    String command_name = buffer.substring(0, first_brace);
    Command* c = commandGet(command_name);
    if (c) proxy->dispatch(*commands->find(command_name));	
  }

  buffer ="";
  command_dispatching = false;
}