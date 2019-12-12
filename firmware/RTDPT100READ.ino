//TMP36 Pin Variables
int sensorPin = PA0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
float temperature = 0;
 
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
  pinMode(PA1,OUTPUT);
}
 
void loop()                     // run over and over again
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1023.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 int temperatureC = map(reading,205,1023,-500,1500);  //converting from 10 mv per degree wit 500 mV offset
 temperature = temperatureC/10.0;//to degrees ((voltage - 500mV) times 100)
 
 Serial.print(temperature); Serial.println(" degrees F");
 
 // now convert to Fahrenheit
 //float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 //Serial.print(temperatureF); Serial.println(" degrees F");

 if (temperature > 75){
  analogWrite(PA1,HIGH);
  delay(1000);
  analogWrite(PA1,LOW);
  delay(1000);
 }
 delay(1000);                                     //waiting a second
}