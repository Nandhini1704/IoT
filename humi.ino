void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
}
void loop() {
   unsigned int HumValue;
   HumValue = analogRead(A0);
   Serial.println(HumValue);
   if(HumValue<1017){
    Serial.println("There is less humidity ");
    digitalWrite(5, HIGH);
      delay(200);
   }
   else
   {
    Serial.println("There is humidity");
    digitalWrite(5, LOW);
   }
   delay(10);
}
