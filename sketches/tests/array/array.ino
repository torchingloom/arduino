
#include <ArrayT.h>


int i;

ArrayT<int> vi(3);
ArrayT<String> vs(2);


void setup()
{
  
  Serial.begin(9600);
  delay(15);
  
  i = vi.add(72);
 
  Serial.print(i);
  Serial.print(" ");
  i = vi.add(55);
  Serial.print(i);
  Serial.print(" ");
  i = vi.add(144);
  Serial.print(i);
  Serial.print(" ");
  
  i = vi.add(13);
  Serial.print(i);
  Serial.print(" ");
  
  Serial.println(vi[0]);
  Serial.println(vi[1]);
  Serial.println(vi[2]);
  
  vs.add("first");
  vs.add("second");
  Serial.println(vs[0]);
  Serial.println(vs[1]);

}

void loop()
{
}
