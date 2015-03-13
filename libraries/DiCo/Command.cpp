#include "Command.h"
#include "Arduino.h"

//////////////////////////
// Param
//////////////////////////


Command::Param::Param(const char* _name, int _type)
{
  name = String(_name);
  type = _type;
}

Command::Param::Param(const char* _name)
{
  Param(_name, INT);
}

Command::Param::Param(int ival)
{
   Param("", INT);
   val.i = ival;
}

Command::Param::Param()
{
  Param("", INT);
}

Command::Param::~Param()
{
}

//////////////////////////
// Command
//////////////////////////

Command::Command(const char* _name, int param_count)
{
  params = new ArrayT<Param>(param_count);
  cmd_name = _name;
}

Command::Command(const char* _name)
{
  Command(_name, 0);
}

Command::Command()
{
  Command("", 0);
}

Command::~Command()
{
  delete params;
}

int Command::paramAdd(Param p)
{
  return params->add(p);
}
