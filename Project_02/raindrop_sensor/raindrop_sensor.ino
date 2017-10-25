int nRainIn = A0;
int nRainDigitalIn = 0;
int nRainVal;
boolean bIsRaining = false;
String strRaining;


void setup() {
  Serial.begin(115200);
  pinMode(2,INPUT);
}
void loop() {
  nRainVal = analogRead(nRainIn);
  bIsRaining = !(digitalRead(nRainDigitalIn));
  
  if(bIsRaining){
    strRaining = "YES";
  }
  else{
    strRaining = "NO";
  }
  
  Serial.print("Raining?: ");
  Serial.print(strRaining);  
  Serial.print("\t Moisture Level: ");
  Serial.println(nRainVal);
  
  delay(200);

}
