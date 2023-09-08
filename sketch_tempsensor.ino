#define BLYNK_TEMPLATE_ID "TMPL3ZHxMqzDp"
#define BLYNK_TEMPLATE_NAME "ESP IOT"
#define BLYNK_AUTH_TOKEN "RX6QNhktNZ_zbv14dItygVEF6KXe9PLT"
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#define DHTPIN 4  //data pin is connected to D2 on ESP;
#define DHTTYPE DHT11

char auth[] = "RX6QNhktNZ_zbv14dItygVEF6KXe9PLT";
char ssid[] = "Redmi 9A";
char pass[] = "ashwath11";
DHT dht(DHTPIN, DHTTYPE );



void setup(){
  
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin (auth, ssid, pass);
  Serial.println("Blynk Connected Successfully");
  dht.begin();
}

void loop()

{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true); 
  if (isnan(h) || isnan(t) || isnan(f) ) 
  {
  Serial.println("Something is not working as intended");
  return;
  }
  Serial.println("Humidity");
  Serial.println(h);
  Serial.print("%");
  Serial.println("Temperature");
  Serial.print(t);
  Serial.print("degrees celsius.");
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V0, h);
  delay(2000);
}