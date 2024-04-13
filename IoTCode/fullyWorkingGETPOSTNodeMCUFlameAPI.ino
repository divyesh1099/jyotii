#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

// Replace with your network credentials
const char* ssid = "networkbda0917cffgpiwr8645998746";
const char* password = "Omshree1225*";

void setup() {
  // Initialize serial communication at a baud rate of 115200
  Serial.begin(115200);

  // Connect to your WiFi network
  WiFi.begin(ssid, password);

  // Check if connection succeeds
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Confirm connection
  Serial.println("");
  Serial.println("Connected to WiFi");
  
  // Ensure the ESP doesn't go to sleep
  WiFi.mode(WIFI_STA);
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    WiFiClient client;  // Create a WiFiClient object
    HTTPClient http;    // Declare an object of class HTTPClient

    // Perform a GET request
    if (http.begin(client, "http://jyotiiflask-0b739e38df99.herokuapp.com/flame-status")) {
      int httpCode = http.GET(); // Send the request

      if (httpCode > 0) { // Check the returning code
        String payload = http.getString(); // Get the request response payload
        Serial.print("HTTP Response code: ");
        Serial.println(httpCode);
        Serial.print("GET Response: ");
        Serial.println(payload);
      } else {
        Serial.print("HTTP GET failed, error: ");
        Serial.println(http.errorToString(httpCode).c_str());
      }

      http.end(); // Close connection
    } else {
      Serial.println("HTTP begin failed");
    }

    delay(5000); // Short delay before the POST request

    // Perform a POST request to update the flame status to "No"
    if (http.begin(client, "http://jyotiiflask-0b739e38df99.herokuapp.com/flame-status")) {
      http.addHeader("Content-Type", "application/json"); // Specify content-type header

      int httpCode = http.POST("{\"status\":\"No\"}"); // Send the post request with the payload

      if (httpCode > 0) { // Check the returning code
        String payload = http.getString(); // Get the request response payload
        Serial.print("HTTP Response code: ");
        Serial.println(httpCode);
        Serial.print("POST Response: ");
        Serial.println(payload);
      } else {
        Serial.print("HTTP POST failed, error: ");
        Serial.println(http.errorToString(httpCode).c_str());
      }

      http.end(); // Close connection
    } else {
      Serial.println("HTTP begin failed");
    }
  } else {
    Serial.println("Error in WiFi connection");
  }

  delay(10000); // Wait a while before repeating the loop
}
