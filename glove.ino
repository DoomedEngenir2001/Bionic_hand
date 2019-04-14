#include <Servo.h>
Servo fingers[5];
const int flexpin[5] = {0,1,2,3,4}; // пины к которым подключены датчики
int flex_pred[5];
int flex_now[5];
int flexposition[5];
int angle[5];
void setup()  
{
  Serial.begin(9600);
  fingers[0].attach(5);
  fingers[1].attach(6);
  fingers[2].attach(7);
  fingers[3].attach(B0);
  fingers[4].attach(B1);
 }
int counter=1;

void loop()
{
  if (counter%2==0)
  {
    for(int i=0;i<5;i++)
    {
      flex_pred[i]=analogRead(flexpin[i]);
     }
  }
  else
  {
      for(int i=0;i<5;i++)
    {
       flex_now[i]=analogRead(flexpin[i]);
    }
  }

 
   for(int i=0;i<5;i++)
   {
   flexposition[i] = flex_now[i]-flex_pred[i];
   delay(1000);
   Serial.println(flexposition[i]);
   if(flexposition[i]>=3 )
   {
      //   Serial.println(i);
        angle[i]=0;
        Serial.print("angel");
        Serial.println(angle[i]);
        fingers[i].write(angle[i]);
     
   } 
  if (flexposition[i]<=-3)
   {
     Serial.print("angel");
     Serial.println(angle[i]);
     angle[i]=90;
     fingers[i].write(angle[i]);
     
      //  Serial.println(flexposition[2]);  
    
    
    }
 
 }
  counter++;

}
