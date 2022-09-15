int t=2;
int e=3;
void setup()
{
  Serial.begin(9600);
  pinMode(t,OUTPUT);
  pinMode(e,INPUT);
  pinMode(12,OUTPUT);
}

void loop()
{
  //ultrasonic sensor Code
  digitalWrite(t,LOW);
  digitalWrite(t,HIGH);
  delayMicroseconds(10);
  digitalWrite(t,LOW);
  float dur=pulseIn(e,HIGH);
  int dis = dur * 0.034 / 2;
  Serial.print("Distance is: ");
  Serial.print(dis);
  
    //LED ON Code
  if(dis<=10)
  {
    digitalWrite(8,HIGH);
    
  }
  else{
    digitalWrite(7,HIGH);
  }
  
  //Buzzer For ultrasonic Sensor Code
  if(dis<=30)
  {
  for(int i=0; i<=40; i=i+10)
  {
  tone(12,i);
  delay(1000);
  noTone(12);
  delay(1000);
  }
  }
   
    //Temperate Sensor Code
  double a= analogRead(A0);
  double tem=(((a/1024)*5)-0.5)*100;
  Serial.print("Temp Value: ");
  Serial.println(tem);
  delay(1000);
  
  //LED ON Code
  if(t>=38)
  {
    digitalWrite(8,HIGH);
    
  }
  else
  {
    digitalWrite(7,HIGH);
  }
  
  //Buzzer for Temperature Sensor Code
  if(tem>=38)
  {
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
  for(int i=0; i<=30; i=i+10)
  {
  tone(12,i);
  delay(1000);
  noTone(12);
  delay(1000);
  }
  }

   //LED OFF Code
  if(t<38)
  {
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
  }
  else
  {
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
  }
}