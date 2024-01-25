/*************************************************************

Firmware for triggering a servo evertime the API request is sent
*************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "Redacted"
#define BLYNK_TEMPLATE_NAME "Redacted"
#define BLYNK_AUTH_TOKEN "Redacted"          

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define servoPin 13

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
Servo servo;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "redacted";
char pass[] = "redacted";

BlynkTimer timer;

void wait(int delay_value){
  //this function is used instead of the delay function since blynk recommends millis()
  unsigned long starttime=millis();
  while(millis()-starttime<delay_value){
    //do nothing
    //used instead of delay so that connection is not severed

  }

}
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  if (value==1){
    for(int j=0; j<=180; j++){
      servo.write(j);
      wait(3);
    }
wait(1000);
    }
    for(int j=180; j>=0; j--){
      servo.write(j);
      wait(3);
    value=0;
}
    
  }



// This function is called every time the device is connected to the Blynk.Cloud

// This function sends Arduino's uptime every second to Virtual Pin 2.

void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	servo.setPeriodHertz(50);    // standard 50 hz servo
	servo.attach(servoPin, 500, 2400);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
