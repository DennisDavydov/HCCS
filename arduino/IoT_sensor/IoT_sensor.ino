#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "iPhone";
const char* password = "Agrepina";

const String serverName = "http://172.20.10.4:80/home/includes";

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

const String id = "1";
double request_temp = 0;
double current_temp = 0;

void setup() {
   Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
  
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      getRequest();
      postRequest();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }

  if(request_temp<=25){
    digitalWrite(D1, HIGH);
    }
    else{
      digitalWrite(D1, LOW);
      }
  digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(D0, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
void getRequest(){
 HTTPClient http;
 http.begin(serverName+"/nodegetrequest.inc.php?id=" + id + "&temp=" + String(request_temp));
  int httpResponseCode = http.GET(); 
  String payload = http.getString();
  Serial.println(payload);
  request_temp = payload.toDouble();
  http.end();
  }
void postRequest(){
      HTTPClient http;
      http.begin(serverName+"/nodereciever.inc.php");
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      String httpRequestData = "id="+ id +"&temp=" + String(current_temp) ;           
      http.addHeader("Content-Length", String(httpRequestData.length()));
      
      int httpResponseCode = http.POST(httpRequestData);

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      Serial.println(http.getString());  
      http.end();
  }
