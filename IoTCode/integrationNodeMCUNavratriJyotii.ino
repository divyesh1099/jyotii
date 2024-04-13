#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "networkbda0917cffgpiwr8645998746";
const char* password = "Omshree1225*";

void setup() {
  Serial.begin(9600);  // Match the baud rate with the Arduino Nano
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");
}

void loop() {
  if (Serial.available() > 0) {
    String statusValue = Serial.readStringUntil('\n');  // Read the data from serial
    statusValue.trim();  // Remove any whitespace

    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;
      HTTPClient http;
      String serverPath = "http://jyotiiflask-0b739e38df99.herokuapp.com/flame-status";

      // Create JSON object string
      String jsonData = "{\"status\":\"" + statusValue + "\"}";

      http.begin(client, serverPath);  // HTTP begin
      http.addHeader("Content-Type", "application/json");

      Serial.println("Sending HTTP POST request...");
      int httpCode = http.POST(jsonData);  // Send the request
      String payload = http.getString();  // Get the response payload

      Serial.print("HTTP Response code: ");
      Serial.println(httpCode);
      Serial.print("Response payload: ");
      Serial.println(payload);

      http.end();  // HTTP end
    } else {
      Serial.println("WiFi Disconnected. Attempting to reconnect...");
      WiFi.begin(ssid, password);
    }
  } else {
    Serial.print("\n Nothing in Serial \n");
    delay(1000);
  }
}
