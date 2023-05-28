#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <Adafruit_Sensor.h>


FirebaseData <YOUR_NAME>;


const char* ssid     = ""; // Change this to your WiFi SSID
const char* password = ""; // Change this to your WiFi password
const char* url   = "<FIREBASE_URL>"; 
const char* key = "<FIREBASE_KEY>"; 


const int sensor=A0; // Assigning analog pin A0 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading


void setup()
{
   

    Serial.begin(115200);
    pinMode(sensor,INPUT);
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println("******");
    Serial.print("Connecting to ");
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
    Firebase.begin(url,key);
    Firebase.reconnectWiFi(true);
    Firebase.begin(url,key);
    Firebase.reconnectWiFi(true);
   
   
}
void loop()
{
   vout=analogRead(sensor);
   vout=(vout*500)/1024;
   tempc=vout; // Storing value in Degree Celsius
   tempf=(vout*1.8)+32; // Converting to Fahrenheit 
   Serial.print("in DegreeC=");
   Firebase.setFloat(<YOUR_NAME>, "TemperatureInCelsius", tempc)
   Serial.print("\t");
   Serial.print(tempc);
   Serial.println();
   Serial.print("in Fahrenheit=");
   Firebase.setFloat(<YOUR_NAME>, "TemperatureInFahrenheit", tempf)
   Serial.print("\t");
   Serial.print(tempf);
   Serial.println();
   delay(1000); 
 }