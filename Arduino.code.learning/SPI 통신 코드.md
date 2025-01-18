# 아두이노 에서 SPI 통신을 이용할 수 있는 방법
+ shiftln()과 shiftOut()을 사용하는 방법
+ SPI라이브러리를 사용하여 마이크로컨트롤러 내장 SPI 하드웨어를 사용

## 사용할 시 사전 설정해야할 것
+ SPI 통신으로 데이터가 보내지는 순서를 지정해야함
  + MSB
  + LSB
  + setBitOrder() 함수로 제어 가능
+ 슬레이브는 매 클럭신호의 상승엣지나 하강엣지중 하나에 데이터는 읽게 되므로 이에 대해서도 설정이 필요함
  + setDataMode()함수로 설정
+ SPI는 초당 백만 바이트의 데이터를 전송할 수 있을 정도로 빠르게 동작할 수도 있지만 어떤 장치에서는 이와 같은 속도를 너무 빠를수도 있음 
  + 전송속도에 대한 부분은 setClockDivider()함수로 설정 가능
    + 8MHz(/2)에서 125kHz(/128)<br>
![image](https://github.com/user-attachments/assets/4e10225b-3380-4cf0-b638-733233133e78)

master code
```C++
#include<SPI.h>

int ledPin=7;
int buttonPin=2;

int x;
void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH);
  
  
}

void loop()
{
  
  byte masterSend, masterReceive;
  if(digitalRead(buttonPin)==LOW){
    x=1;
  }else{
    x=0;
  }
  

 digitalWrite(SS, LOW); 

  
  masterSend = x;
  masterReceive = SPI.transfer(masterSend);
  
  if(masterReceive==1){
    digitalWrite(ledPin, HIGH); 
    Serial.println("Master Led On");
    
  }else{
    digitalWrite(ledPin, LOW);
    Serial.println("Master Led Off");
   
  }
  delay(1000);
}
```
slave code
```C++
#include<SPI.h>

int buttonPin = 2;
int ledPin =7;
volatile boolean received;
volatile byte slaveReceived, slaveSend;
int buttonValue;
int x;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(MISO, OUTPUT);
  SPCR |=_BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR|=_BV(SPIE);
  received=false;
  
}



ISR(SPI_STC_vect){

  slaveReceived = SPDR;
  Serial.println("some data has been received");
      if (slaveReceived==1) 
      {
        digitalWrite(ledPin,HIGH);         
        Serial.println("Slave LED ON");
      }else
      {
        digitalWrite(ledPin,LOW);          
        Serial.println("Slave LED OFF");
      }
      
      buttonValue = digitalRead(buttonPin);  
      if (buttonValue == LOW)              
        x=1;
        
      }else
      {
        x=0;
      }
      
      slaveSend=x;                             
      SPDR = slaveSend; 
  
}

void loop()
{
}
```
