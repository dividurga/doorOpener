/*************************************************************

  This is a simple demo of sending and receiving some data.
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL39IPuuPfy"
#define BLYNK_TEMPLATE_NAME "doorOpener"
#define BLYNK_AUTH_TOKEN "3p0B4uIgPAUfEmcEeAxx1785et4jwxcc"          

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
char ssid[] = "bigbang";
char pass[] = "divij@123";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  if (value==1){
    for(int j=0; j<=180; j++){
      servo.write(j);
      delay(3);
    }
    delay(500);
    for(int j=180; j>=0; j--){
      servo.write(j);
      delay(3);
    }
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
  pinMode(15,OUTPUT);

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