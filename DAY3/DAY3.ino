#include <SimpleDHT.h>
#define relay 5
#define button1 3
#define button 4
int buttonState1 =0;
int buttonState =0;
int temp_max =30;
//int a;

// for DHT22, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT22 = 2;
SimpleDHT22 dht22(pinDHT22);

void setup() {
  Serial.begin(115200);
  pinMode(relay,OUTPUT);
  pinMode(button,INPUT);
  pinMode(button1,INPUT);
}

void loop() {
 
  // start working...
   Serial.println("=================================");
   Serial.println("Sample DHT22...");
  
  // read without samples.
  // @remark We use read2 to get a float data, such as 10.1*C
  //    if user doesn't care about the accurate data, use read to get a byte data, such as 10*C.
  float temperature = 0;
  float humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(&temperature,&humidity,NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err="); Serial.println(err);
    delay(2000);
    return;
  }
  // DHT22 sampling rate is 0.5HZ.
   Serial.print("Sample OK: ");
  Serial.print((float)temperature); Serial.print(" *C, ");
  Serial.print((float)humidity); Serial.println(" RH%");
  //delay(2500);

      {  if((int)temperature>=temp_max)
        {
         //  poweroff relay();
         digitalWrite(relay,HIGH);
         }
       else
       {
        // poweron relay();
         digitalWrite(relay,LOW);
       }
              
        
           buttonState=digitalRead(button);
           buttonState1=digitalRead(button1);
           if(buttonState==HIGH)
          {
            temp_max++;
           }
              while(digitalRead(button==HIGH))
           {
             delay(100);
           }
                if(buttonState1==HIGH)
              {
               temp_max--;
              }
              while(digitalRead(button1==HIGH))
             {
              delay(100);
             }
                 Serial.println(buttonState);
                 
}}
