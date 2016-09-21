
#include <WiFi101.h>
#include <ArduinoCloud.h>

/////// Wifi Settings ///////
//char ssid[] = "PLDTHOMEDSL58446";
//char pass[] = "PLDTWIFI175338";
char ssid[] = "Jonnan";
char pass[] = "jonnan123";


// Arduino Cloud settings and credentials
const char userName[]   = "ivin_lim";
const char thingName[] = "button";
const char thingId[]   = "41a2e2f8-9d66-485a-b6c2-e7b1081467d5";
const char thingPsw[]  = "132e5037-ba9e-4b7b-8299-f0da645e5da7";


WiFiSSLClient sslClient;


// build a new object "button"
ArduinoCloudThing button;


void setup() {
  Serial.begin (9600);
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // attempt to connect to WiFi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // unsuccessful, retry in 4 seconds
    Serial.print("failed ... ");
    delay(4000);
    Serial.print("retrying ... ");
  }


  button.begin(thingName, userName, thingId, thingPsw, sslClient);
  button.enableDebug();
  // define the properties
  button.addProperty("power", STATUS, R);
  
}

void loop() {
  button.poll();

  button.writeProperty("power", "on");

  
  delay(1000);
  button.writeProperty("power", "off");
  
  delay(1000);
}
