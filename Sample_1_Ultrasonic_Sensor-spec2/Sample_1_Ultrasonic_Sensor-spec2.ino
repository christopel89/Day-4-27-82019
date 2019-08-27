#define trigPin 9                 
#define echoPin 10                
#define BUZZER 6

#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13

void setup()
{
  Serial.begin (9600);       
     
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);   
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  
}

void loop()
{
//******************************************************//
  // Sample Code
  long duration, distance;                   
  // (1) : generate ultrasonic waveform
  digitalWrite(trigPin, LOW);                
  delayMicroseconds(2);                
  digitalWrite(trigPin, HIGH);            
  delayMicroseconds(10);               

  // (2) : Waveform length - the time from the launch
  //       of the ultrasound to the return
  digitalWrite(trigPin, LOW);
  // pulseIn(pin_number, pulse)
  // Read a pulse (HIGH or LOW) on the pin.
  // For example, if value is HIGH, first pulseIn() waits until the pin goes HIGH,
  // second starts a timer, finally waits for the pin to go low and stops the timer.
  //  - Parameter 1 [pin_number] : Pin Number
  //  - Parameter 2 [pulse]      : pulse (HIGH or LOW)
  duration = pulseIn(echoPin, HIGH);   

  distance = duration * 17 / 1000;
  // Why write "distance = duration * 17 / 1000" code
  // Distance is time x speed.
  // The speed is 340mm per second at the speed of sound,
  // so the time * 340m is converted to 34,000cm in order to change in cm.
  // The duration that the time value is stored in is stored in microseconds,
  // so it divides 1,000,000 for conversion.
  // So the time x 34,000 / 1,000,000 comes out and the sum is the distance * 34 / 1,000.
  // However, it took two times to reach and return to the obstacle, so divide by two.
  // Then comes the formula of time x 17 / 1,000.

  if (distance >= 170 || distance <= 0)       
  {
    Serial.println("Unable to measure distance");
    analogWrite(LED_RED, 0);
    analogWrite(LED_GREEN,255);
  }
  else                                           
  {
    Serial.print(distance);                      
    Serial.println(" cm");  
    analogWrite(LED_RED, 255);                     
    //analogWrite(LED_GREEN,0);

    if (distance <=20){
//    tone (BUZZER,600);
//    delay(distance*10);
//    noTone(BUZZER);
    analogWrite(LED_GREEN,0);
    delay(distance*10);
  } else {
    delay(500);
  
  }
  }

  
  delay(500);                                    
}
