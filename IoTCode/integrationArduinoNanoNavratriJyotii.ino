void setup() {
  Serial.begin(9600);  // Make sure baud rate is the same on NodeMCU
  Serial.println("Starting Flame Sensor...");
}

void loop() {
  int sensorReading = analogRead(A0);  // Read the analog value from pin A0
  int range = map(sensorReading, 0, 1023, 0, 3);  // Map the reading to a range from 0 to 3

  // Convert range to status string
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

  // Send the status over serial
  Serial.println(statusValue);

  delay(1000);  // Adjust delay as needed
}
