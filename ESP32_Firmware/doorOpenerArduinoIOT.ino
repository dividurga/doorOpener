#include <ESP32Servo.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


Servo servo;

#define servoPin 13


const char DEVICE_LOGIN_NAME[]  = "Redacted";

const char SSID[]               = "Redacted";    // Network SSID (name)
const char PASS[]               = "Redacted";    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = "Redacted";    // Secret device password
void onDoorOpenerChange();
bool doorOpener;


void initProperties(){

  ArduinoCloud.setBoardId("Redacted");
  ArduinoCloud.setSecretDeviceKey("Redacted");
  ArduinoCloud.addProperty(doorOpener, READWRITE, ON_CHANGE, onDoorOpenerChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);


void setup() {
 ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	servo.setPeriodHertz(50);    // standard 50 hz servo
	servo.attach(servoPin, 500, 2400); // attaches the servo on pin 18 to the servo object
	// using default min/max of 1000us and 2000us
	// different servos may require different min/max settings
	// for an accurate 0 to 180 sweep
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
   
}

void onDoorOpenerChange(){
  if (doorOpener){
for (int j=0; j<=180; j++){
    servo.write(j);
    delay(3);
   }

    for (int j=180; j>=0; j--){
    servo.write(j);
    delay(3);
   }

    doorOpener=false;
	  Blynk.virtualWrite(V5, sensorData);

}}

