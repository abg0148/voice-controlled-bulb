String readString;
#define ledPin 13
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(6,HIGH);
  Serial.begin(9600);
  Serial.println("serial-delimit-21"); // so I can keep track of what is loaded
}

void loop() {
  while (Serial.available()) {
    delay(10);  //small delay to allow input buffer to fill

    char c = Serial.read();  //gets one byte from serial buffer
    if (c == ',') {
      break;
    }  //breaks out of capture loop to print readstring
    readString += c; 
  } //makes the string readString  

  if (readString.length() >0) {
    Serial.println(readString); //prints string to serial port out
    if(readString=="w"){
      digitalWrite(ledPin,HIGH);
      }
     if(readString=="s"){
      digitalWrite(ledPin,LOW);
      }
     if(readString=="switch on"){
      digitalWrite(ledPin,HIGH);
      }
     if(readString=="switch off"){
      digitalWrite(ledPin,LOW);
      }
    readString=""; //clears variable for new input
  }

  
}

