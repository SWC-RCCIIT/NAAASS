#include"DHT.h"
#define relay 5
#define sw1 3
#define sw2 4
#define pin_DHT 2
#define DHTTYPE DHT11
DHT dht(pin_DHT,DHTTYPE);
int buttonstate1 =0;
int buttonstate2=0;
int temp_max=40;
unsigned long previousMillis=0;
long interval=10000;
int temperature;

void setup()
{
  pinMode(relay,OUTPUT);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  Serial.begin(9600);
  dht.begin();
  Serial.begin(115200);
}
void loop()
{
        temperature=dht.readTemperature();
        Serial.println((int)temperature);
         Serial.print("*c , ");
  
    unsigned long currentMillis=millis();
    if(currentMillis-previousMillis>=interval)
     {
        temperature=dht.readTemperature();
        Serial.println((int)temperature);
         Serial.print("*c , ");
        previousMillis=currentMillis;
      } 
       buttonstate1=digitalRead(sw1);
       buttonstate2=digitalRead(sw2);
        if(buttonstate1==1)
          {
            temp_max++;
    
          }
            while(digitalRead(sw1==1))
              {
                delay(100);
              }
         if(buttonstate2==1)
        {
          temp_max--;
    
        }
          while(digitalRead(sw1==1))
         {
          delay(100);
         }
       if(temperature>=temp_max)
        {
         //  poweroff relay();
         digitalWrite(relay,HIGH);
         }
       else
       {
        // poweron relay();
         digitalWrite(relay,LOW);
       }
      delay(1000);
}
//void poweron relay()
//{
  //digitalwrite(relaypin,HIGH);
  //serial.println("relay on");
//}
//void poweroff relay(){
  //digital write(relaypin,LOW);
  //serial println("relay off");
//}
 //Serial.println((int)temperature);
 //serial.print("*c , ");
