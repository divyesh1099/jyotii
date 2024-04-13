// Arduino Nano doesn't need additional libraries for basic analog read

// Sensor reading ranges
const int sensorMin = 0;     // sensor minimum, typically 0
const int sensorMax = 1024;  // sensor maximum, typically 1023 actually for Arduino

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 1000; // Delay between measurements (1000ms = 1 second)

void setup() {
  Serial.begin(9600);  // Lower baud rate for stability on Nano
  Serial.println("Testing Flame Sensor...");

  // Give some time to establish readings
  delay(2000); // 2-second delay for setup procedures
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    int sensorReading = analogRead(A0);  // Read the analog value from pin A0
    int range = map(sensorReading, sensorMin, sensorMax, 0, 3);  // Map the reading to a range from 0 to 3

    // Use simple character array for status because String class is heavy for Arduino
    char* statusValue;
    switch (range) {
      case 0:
        statusValue = "Normal";
        break;
      case 1:
        statusValue = "Low";
        break;
      case 2:
        statusValue = "High";
        break;
      default:
        statusValue = "Error";
        break;
    }
    
    // Output the results
    Serial.print("Sensor Reading: ");
    Serial.print(sensorReading);
    Serial.print(", Status: ");
    Serial.println(statusValue);

    lastTime = millis();  // Reset the timer
  }
}
