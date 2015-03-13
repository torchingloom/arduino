

#include <AssocArrayT.h>

AssocArrayT<int> i(3);
AssocArrayT<String> s(2);

void setup()
{

  Serial.begin(9600);
  delay(15);

  i.add("a", 72);
  i.add("b", 55);
  i.add("c", 144);

  Serial.println(*i["a"]);
  Serial.println(*i["b"]);
  Serial.println(*i["c"]);
  
  s.add("first", "hello");
  s.add("second", "world");
  Serial.println(*s["first"]);
  Serial.println(*s["second"]);

}

void loop()
{
}



