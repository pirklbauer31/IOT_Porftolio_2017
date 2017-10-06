/*
 *  HTTP over TLS (HTTPS) example sketch
 *
 *  This example demonstrates how to use
 *  WiFiClientSecure class to access HTTPS API.
 *  We fetch and display the status of
 *  esp8266/Arduino project continuous integration
 *  build.
 *
 *  Created by Ivan Grokhotkov, 2015.
 *  This example is in public domain.
 */

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <LiquidCrystal_I2C.h>

void sendHttpRequest();

const char* ssid = "hainberger_pirklbauer";
const char* password = "password";

const char* host = "maker.ifttt.com";
const int httpsPort = 443;

const int buttonPin = 14;     // the number of the pushbutton pin

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char* fingerprint = "CF 05 98 89 CA FF 8E D8 5E 5C E0 C2 E4 F7 E6 C3 C7 50 DD 5C";
LiquidCrystal_I2C lcd(0x27, 16, 2);

int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  //comment this line if button is not connected to arduino board
  pinMode(buttonPin, INPUT);

  // initialize the LCD
  lcd.begin(4,5);  // sda=4, scl=5

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello, world!");
  
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  
}

void loop() {
  //Serial.print(buttonState);
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is LOW:
  if (buttonState == LOW) {
    Serial.println("BUTTON");
    sendHttpRequest();
    delay(1000);
  }
  else {
    //Serial.println("Button not pressed");
  }

  
}

void sendHttpRequest() {
  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "/trigger/button_pressed/with/key/mfVYP1moOYQ7FaHecVCjc07785SLkHjn4GIsf9GQG8b";
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}

