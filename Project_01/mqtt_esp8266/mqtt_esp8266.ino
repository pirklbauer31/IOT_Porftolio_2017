/*
 Basic ESP8266 MQTT example

 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.

 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic" every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off

 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.

 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"

*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>

// Update these with values suitable for your network.

const char* ssid = "hainberger_pirklbauer";
const char* password = "password";
const char* mqtt_server = "192.168.12.1";

Servo myservo;  // create servo object to control a servo

const int buttonPin = 0;
const int buzzerPin = 1;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int powerstate = 1;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if(topic=="heater/power"){
      Serial.print("Switching heater power to ");
      if(messageTemp == "on"){
        //digitalWrite(LED_BUILTIN, LOW);
        Serial.print("On");
      }
      else if(messageTemp == "off"){
        //digitalWrite(LED_BUILTIN, HIGH);
        Serial.print("Off");
      }
  }
  if(topic=="heater/gaswarning"){
      if(messageTemp == "on"){
        digitalWrite(LED_BUILTIN, LOW);
      }
      else if(messageTemp == "off"){
        digitalWrite(LED_BUILTIN, HIGH);
      }
  }
  Serial.println();
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      //client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("heater/power");
      client.subscribe("heater/gaswarning");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  digitalWrite(LED_BUILTIN, HIGH); 
  pinMode(buttonPin, INPUT);        // initialize the pushbutton pin as an input
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

    // check if the pushbutton is pressed. If it is, the buttonState is LOW:
    if (buttonState == LOW && powerstate == 1) {
      // turn Power off:
      Serial.println("Publish message: off");
      client.publish("heater/power", "off");
      powerstate = 0;
    }
    else if (buttonState == LOW && powerstate == 0) {
      // turn Power on:
      Serial.println("Publish message: on");
      client.publish("heater/power", "on");
      powerstate = 1;
    }

    
    
  }
}
