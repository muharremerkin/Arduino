#define trig_Pin 8
#define echo_Pin 9
#define buzzer_Pin 10
long mesafe = 0;
long sure = 0;
int gosterge = 0;

void setup()
{ 
for (int i = 2; i < 7; i++) 
{ 
pinMode(i, OUTPUT); 
} 
pinMode(trig_Pin, OUTPUT);
pinMode(echo_Pin, INPUT); 
Serial.begin(9600);
}
void loop() 
{
  buzzer_uyari(mesafe_olc() *8);
  gosterge = mesafe_olc() / 10+1;
  for(int i=7; i> gosterge; i--)
  {
    digitalWrite (i,HIGH);
  }
  for(int i = gosterge; i >= 2; i--)
  {
    digitalWrite (i,LOW);
  
  }
}
int mesafe_olc()
{
digitalWrite(trig_Pin, HIGH);
delayMicroseconds(1000);
digitalWrite(trig_Pin, LOW); 
sure = pulseIn(echo_Pin, HIGH); 
mesafe = (sure / 29.1) / 2; 
if (mesafe > 50)
mesafe = 50;
Serial.print("Olculen Mesafe = ");
Serial.print(mesafe); 
Serial.println(" cm ");
return mesafe;
}

void buzzer_uyari (int bekle)
{
  tone(buzzer_Pin, 500);
  delay(bekle);
  noTone(buzzer_Pin);
  delay(bekle);
}
