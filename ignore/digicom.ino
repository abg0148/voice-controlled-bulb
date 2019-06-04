#define ledPin 13
String state = "0";
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    String state = Serial.read(); // Reads the data from the serial port
    Serial.println(state);
    delay(10);
    if(state=="w"){
      digitalWrite(ledPin,HIGH);
      }
   if(state=="s"){
      digitalWrite(ledPin,LOW);
      }
 } 
}
