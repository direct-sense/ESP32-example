#include <Arduino.h>
#include <SPIFFS.h>
#include<WiFi.h>

#define WIFI_SSID       "58H2F-2.4G"
#define WIFI_POSSWORD   "855358ABC"

void wifiSetup(String ssid, String password)
{
  //for station mode
  WiFi.mode(WIFI_STA); //設置WiFi模式
  WiFi.begin(ssid.c_str(), password.c_str());

  Serial.print("WiFi connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP位址:");
  Serial.println(WiFi.localIP()); //讀取IP位址
}

void setup()
{
  Serial.begin(115200);
  wifiSetup(WIFI_SSID, WIFI_POSSWORD);
  Websetup();
}


void loop()
{
  Webloop();
}
