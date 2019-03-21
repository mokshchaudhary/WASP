
#include "heltec.h"
#include "images.h"
#include "DHT.h"
#define BAND 433E6  //you can set band here directly,e.g. 868E6,915E6

#define DHTTYPE DHT11
#define DHTPIN 12
DHT dht(DHTPIN, DHTTYPE);

unsigned int counter = 0;
String rssi = "RSSI --";
String packSize = "--";
String packet ;
float t;
float h;

void logo()
{
  Heltec.display->clear();
  Heltec.display->drawXbm(0,5,logo_width,logo_height,logo_bits);
  Heltec.display->display();
}

void setup()
{
   //WIFI Kit series V1 not support Vext control
  dht.begin();
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
 
  Heltec.display->init();
  Heltec.display->flipScreenVertically();  
  Heltec.display->setFont(ArialMT_Plain_10);
  logo();
  delay(1000);
  Heltec.display->clear();
  Serial.begin(9600);
  Heltec.display->drawString(0, 0, "Heltec.LoRa Initial success!");
  Heltec.display->display();
  delay(1000);
}

void loop()
{
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_10);
  //DHT Functioning

  delay(1000);

  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();

int temp2 = random(0,100);
int hum2 = random(0,100);

int temp3 = random(0,100);
int hum3 = random(0,100);
   
  Heltec.display->drawString(0, 0, String(t));
  Heltec.display->drawString(45, 0, String(h));
   Heltec.display->drawString(0, 10, String(temp2));
  Heltec.display->drawString(45, 10, String(hum2));
   Heltec.display->drawString(0, 20, String(temp3));
  Heltec.display->drawString(45, 20, String(hum3));
  Heltec.display->drawString(0, 50, "Sent");   
  Heltec.display->display();

  

  // send packet
  Heltec.LoRa.beginPacket();
  // Heltec.LoRa.print();
  Heltec.LoRa.print(String(t)+","+String(h)+","+String(temp2)+","+String(hum2)+","+String(temp3)+","+String(hum3));
  Heltec.LoRa.endPacket();

  counter++;
}
