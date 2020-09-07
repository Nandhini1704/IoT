/* Controlling LED using Firebase console by CircuitDigest(www.circuitdigest.com) */
#include <ESP8266WiFi.h>                                                // esp8266 library
#include <FirebaseArduino.h>

#define FIREBASE_HOST "----------"       // the firebase id
#define FIREBASE_AUTH "----------"       // the secret key from firebase
#define WIFI_SSID "---------"            // wifi name 
#define WIFI_PASSWORD "----------"       //wifi password

String fireStatus = "";                  // led status received from firebase
int led = 16;                           
void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);      
  pinMode(led, OUTPUT);                 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                      //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);        // connect to firebase
  Firebase.setString("LED_STATUS", "OFF");            //send initial string of led status
}

void loop() {
  fireStatus = Firebase.getString("LED_STATUS");  
  if (fireStatus == "ON") {                         // if condition to compare the input of led received from firebase
    Serial.println("Led Turned ON");                         
    digitalWrite(LED_BUILTIN, LOW);                 // make bultin led ON
    digitalWrite(led, HIGH);                        // make external led ON
  } 
  else if (fireStatus == "OFF") {                   // else if condition to compare the input of led status received from firebase
    Serial.println("Led Turned OFF");
    digitalWrite(LED_BUILTIN, HIGH);                 // make bultin led OFF
    digitalWrite(led, LOW);                          // make external led OFF
  }
  else {
    Serial.println("Wrong Credential! Please send ON/OFF");   // else part to wrong credential
  }
}
