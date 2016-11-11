
#include <WiFi101.h>
#include <ArduinoCloud.h>

/////// Wifi Settings ///////
char ssid[] = "PLDTHOMEDSL58446";
char pass[] = "PLDTWIFI175338";
//char ssid[] = "Jonnan";
//char pass[] = "jonnan123";


// Arduino Cloud settings and credentials
const char userName[]   = "rlromilla";
const char thingName[] = "button";
const char thingId[]   = "1f2951ab-3437-44b7-841a-1fed295fde6b";
const char thingPsw[]  = "a241f061-7540-46a6-9e91-a9e4efabf2e2";


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
