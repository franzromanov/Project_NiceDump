const int capSensorPin = 2;  // Pin digital untuk sensor kapasitif
const int indSensorPin = 3;  // Pin digital untuk sensor induktif

void setup() {
  pinMode(capSensorPin, INPUT);
  pinMode(indSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int capSensorValue = digitalRead(capSensorPin);
  int indSensorValue = digitalRead(indSensorPin);
  Serial.println(capSensorValue);
  Serial.println(indSensorValue);


  if (capSensorValue == HIGH && indSensorValue == HIGH) {
    Serial.println("Plastik terdeteksi!");
  } else {
    Serial.println("Tidak ada plastik terdeteksi.");
  }

  delay(1000);  // Delay untuk menghindari deteksi berulang-ulang
}
