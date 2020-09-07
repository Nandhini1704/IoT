void setup() {

Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {
   unsigned int RainSensor,buzzer;
   RainSensor = analogRead(A5);
   Serial.println(RainSensor);
     if(RainSensor<850){
      Serial.println("Rain");
     digitalWrite(13, HIGH);
     delay(2000);
  }
   else
   {
    Serial.println("No Rain");
    digitalWrite(13, LOW);
    tone(buzzer,1000,800);
   }
    delay(500);
}
