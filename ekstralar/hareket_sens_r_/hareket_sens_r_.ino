//5v
int counter=0;
void setup() {
 Serial.begin(9600);
 pinMode(2, INPUT);// set pin as input

}

void loop() {
  
  int detect = digitalRead(2);// read obstacle status and store it into "detect"
  if(detect == LOW){
    
   Serial.println("Obstacle on the way");
   counter++;
   Serial.println(counter);
  }else{
    
   Serial.println("All clear");  
  }
  delay(100);
}
