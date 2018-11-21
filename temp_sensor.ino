int redPin=9;
int greenPin=10;
int bluePin=11;
int tempPin=A0;
int tempVolt;
float temp;
void setup()
{
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(tempPin,INPUT);
}
void loop()
{
  tempVolt=analogRead(tempPin);
  temp=(((((float)tempVolt*5.0*1000.0)/1023.0))/10.0);
  Serial.println(temp);
  if (temp>19.06)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(bluePin,LOW);
    digitalWrite(greenPin,LOW);
  }
  else
  {
    if (temp<17.56)
    {
      digitalWrite(redPin,LOW);
      digitalWrite(bluePin,HIGH);
      digitalWrite(greenPin,LOW);
    }
    else
    {
      digitalWrite(redPin,LOW);
      digitalWrite(bluePin,LOW);
      digitalWrite(greenPin,HIGH);
    }
  }
}

