// LED에 연결된 디지털IO핀 설정
int Led1 = 1;
int Led2 = 2;
int Led3 = 3;
int Led4 = 4;
int Led5 = 5;
int Led6 = 6;

void LR(void)
{
  unsigned char j;
  for(j=1;j<=6;j++)//200ms(0.2초) 마다 1번부터 6번까지의 LED를 점등합니다.
  {
    digitalWrite(j,HIGH);//j핀에 연결된 LED를 점등
    delay(200);//delay 200msec
    digitalWrite(j,LOW);//j핀에 연결된 LED를 소등
  }
}

void RL(void)
{
  unsigned char j;
  for(j=6;j>=1;j--)//200ms(0.2초) 마다 6번부터 1번까지의 LED를 점등합니다.
  {
    digitalWrite(j,HIGH);
    delay(200);
    digitalWrite(j,LOW);
  } 
}

void flash(void)
{   
  unsigned char j,k;
  for(k=0;k<=1;k++)//두번 점멸
  {
    for(j=1;j<=6;j++)
      digitalWrite(j,HIGH);
    delay(200);
    for(j=1;j<=6;j++)
      digitalWrite(j,LOW);
    delay(200);
  }
}

void inout(void)
{
  unsigned char j,k;
  k=1;//k변수를 1로 설정
  for(j=3;j>=1;j--)
  {   
    digitalWrite(j,HIGH);
    digitalWrite(j+k,HIGH);
    delay(400);
    k +=2;
  }
  k=5;//k변수를 5로 설정
  for(j=1;j<=3;j++)
  {
    digitalWrite(j,LOW);
    digitalWrite(j+k,LOW);
    delay(400);
    k -=2;
  }
}

void outin(void)
{
  unsigned char j,k;
  k=5;
  for(j=1;j<=3;j++)
  {
    digitalWrite(j,HIGH);
    digitalWrite(j+k,HIGH);
    delay(400);
    digitalWrite(j,LOW);
    digitalWrite(j+k,LOW);
    k -=2;
  }
  k=3;
  for(j=2;j>=1;j--)
  {   
    digitalWrite(j,HIGH);
    digitalWrite(j+k,HIGH);
    delay(400);
    digitalWrite(j,LOW);
    digitalWrite(j+k,LOW);
    k +=2;
  } 
}

void jump()
{
  for(int i=1; i<=3; i++) {
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
    digitalWrite(i+3, HIGH);
    delay(200);
    digitalWrite(i+3, LOW);
  }
  for(int i=3; i>=1; i--) {
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
    digitalWrite(i+3, HIGH);
    delay(200);
    digitalWrite(i+3, LOW);
  }
}

void acceleration()
{
  int delayTime = 600;
  unsigned char k;
  for(k=0;k<=3;k++)
  {
    for(int i=1; i<=6; i++) {
    digitalWrite(i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
    delayTime -= 20;
    }
  }
}

void deceleration()
{
  int delayTime = 50;
  unsigned char k;
  for(k=0;k<=3;k++){
    for(int i=1; i<=6; i++) {
    digitalWrite(i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
    delayTime += 20;
    }
  }
}

void setup()
{ 
  unsigned char i;
  for(i=1;i<=6;i++)//디지털IO 1~6번까지 출력모드로 설정
    pinMode(i,OUTPUT);//i번째 핀을 출력모드로 설정
}

void loop()
{   
  RL();
  LR();
  RL();
  LR();
  RL();
  LR();
  flash();
  inout();
  outin();
  jump();
  acceleration();
  deceleration();
  flash();
}