

#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define VIB_SENSOR A0
#define TOUCH 1


#define deviceID "christD1566871059787"
#define authnRqtNo "b27ptkquf"
#define extrSysID "OPEN_TCP_001PTL001_1000007621"

#define WIFI_SSID "ICT-LAB-2.4G" // SSID
#define WIFI_PASS "12345678" //psswd
#define TAG_ID "spec2"
IoTMakers g_im;
void init_iotmakers()
{
  while(1)
  {
    Serial.print(F("Connect to AP..."));
    while(g_im.begin(WIFI_SSID, WIFI_PASS) < 0)
    {
      Serial.println(F("retrying"));
      delay(100);
    }

    Serial.println(F("Success"));

    g_im.init(deviceID, authnRqtNo, extrSysID);
  
    Serial.print(F("Connect to platform..."));
    while(g_im.connect() < 0)
    {
      Serial.println(F("retrying."));
      delay(100);
    }
    Serial.println(F("Success"));
  
    Serial.print(F("Auth..."));
    if(g_im.auth_device() >= 0)
    {
      Serial.println(F("Success..."));
      return;
    }
  }
}

void setup() {
  Serial.begin(9600);
  init_iotmakers();
  pinMode(VIB_SENSOR, INPUT);
}

void loop (){
  int isTouch = digitalRead(VIB_SENSOR);
  static unsigned long tick = millis();
//  int TOUCH = 1;
  
  
  if(isTouch >= TOUCH){
    Serial.println("TOUCH");
//    Serial.println(analogRead(VIB_SENSOR));
    delay (10);
  }
  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
    }
  if ((millis() - tick) > 1000){
    send_vib();
    tick = millis();
    }
    g_im.loop();
}

int send_vib()
{
  int av = analogRead(VIB_SENSOR);
  Serial.print("Vib : ");
  Serial.println(av);

  if(g_im.send_numdata(TAG_ID, (double)av) < 0){
    Serial.println(F("fail"));
    return -1;
    }
    return 0;
}
