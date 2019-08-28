



#define VIB_SENSOR A0
#define TOUCH 1




void setup() {
  Serial.begin(9600);

  pinMode(VIB_SENSOR, INPUT);
}

void loop (){
  int isTouch = digitalRead(VIB_SENSOR);
  static unsigned long tick = millis();
//  int TOUCH = 1;
  
  
  if(isTouch >= TOUCH){
    Serial.println("TOUCH");
//    Serial.println(analogRead(VIB_SENSOR));
    delay (100);
  }}
  

//int send_vib()
//{
//  int av = analogRead(VIB_SENSOR);
//  Serial.print("Vib : ");
//  Serial.println(av);
//
//  if(g_im.send_numdata(TAG_ID, (double)av) < 0){
//    Serial.println(F("fail"));
//    return -1;
//    }
//    return 0;
//}
