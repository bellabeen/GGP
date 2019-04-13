//tes sensor pH tanah 

/*
wiring:
kabel putih -> GND
kabel hitam -> output to A0
*/

//analog pin 
#define analogInPin1 A1  //sambungkan kabel hitam (output) ke pin A0
#define analogInPin2 A0
//variable
int sensorValue1 = 0;
int sensorValue2 = 0;           //ADC value from sensor
float outputValue1 = 0;        //pH value after conversion
int sensor = 8;
void setup() {
  pinMode (8,INPUT);
  //initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  //read the analog in value:
  sensorValue1 = analogRead(analogInPin1);
  //sensorValue2 = analogRead(analogInPin2);
  sensorValue2 = digitalRead (8);
  
  //Mathematical conversion from ADC to pH
  //rumus didapat berdasarkan datasheet 
  outputValue1 = (-0.0693*sensorValue1)+7.3855;

  //print the results to the serial monitor:
  Serial.print("sensor ADC= ");
  Serial.print(sensorValue1);
  Serial.print("  output Ph= ");
  Serial.println(outputValue1);
  Serial.print("Flyingfish = ");
  Serial.println(sensorValue2); 
  Serial.println(analogRead(analogInPin2));
  delay(1000);
}
