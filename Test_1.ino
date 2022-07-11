

#include "SoftwareSerial.h"
#include "Arduino.h"
#include "ESP8266WiFi.h"


// #include <WiFi.h>
 #include <WiFiClient.h>
 #include <WiFiServer.h>
 #include <WiFiUdp.h>

int val = 0;

////////////////////Choisir le WiFi////////////////////////////////////////
const char *ssid = "USTH_GUEST";
// const char *password = "NULL"; //Useless si pas de mot de passe



////////////////////////////////////WIFI///////////////////////////////////
void connectToWiFi() {
//Connect to WiFi Network
   Serial.println();
   Serial.println();
   Serial.print("Connecting to WiFi");
   Serial.println("...");
   WiFi.begin(ssid, password);
   int retries = 0;
while ((WiFi.status() != WL_CONNECTED) && (retries < 15)) {
   retries++;
   delay(500);
   Serial.print(".");
}
if (retries > 14) {
    Serial.println(F("WiFi connection FAILED"));
}
if (WiFi.status() == WL_CONNECTED) {
    Serial.println(F("WiFi connected!"));
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
    Serial.println(F("Setup ready"));
}
/////////////////////////////////////////////////////////::

void setup() {

  connectToWiFi();
  Serial.begin(115200L);

  //////////////////Relais//////////////////////////////////////////
  pinMode(5, OUTPUT);    // sets the digital pin 13 as output
  pinMode(15, INPUT);   //_PULLUP Mettre une résistance de pull-down entre l'entrée et la masse pour mettre à 0 quand il n'y a pas de tension
  pinMode(14, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  //////////////////////////////////////////////////////////////////
  
}

// the loop function runs over and over again forever
void loop() {

  if (WiFi.isConnected())
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  

  ////////////////////////////////////////Relay////////////////////////////////////////////////////////////////
  /*
  digitalWrite(14, LOW);
  Serial.println("Tension OFF");
  
  digitalWrite(5, HIGH); // sets the digital pin 13 on
  Serial.println("Activé");
  val = digitalRead(15);
  Serial.println(val);
  digitalWrite(LED_BUILTIN, val);
  delay(2000);            // waits for a second
  
  digitalWrite(5, LOW);  // sets the digital pin 13 off
  Serial.println("Désactivé");
  val = digitalRead(15);
  Serial.println(val);
  digitalWrite(LED_BUILTIN, val);
  delay(5000);            // waits for a second
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
  digitalWrite(14, HIGH);
  Serial.println("Tension ON");
  
  digitalWrite(5, HIGH); // sets the digital pin 13 on
  Serial.println("Activé");
  val = digitalRead(15);
  Serial.println(val);
  digitalWrite(LED_BUILTIN, val);
  delay(2000);            // waits for a second
  
  digitalWrite(5, LOW);  // sets the digital pin 13 off
  Serial.println("Désactivé");
  val = digitalRead(15);
  Serial.println(val);
  digitalWrite(LED_BUILTIN, val);
  delay(5000);            // waits for a second
  */
///////////////////////////////////////////////////////////////////


}
