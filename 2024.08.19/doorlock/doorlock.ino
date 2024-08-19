#include <Wire.h>                   //i2c통신을 사용하기 때문에 아두이노의 i2c 통신용 라이브러리가 필요
#include <Adafruit_GFX.h>           // adafruit의 그래픽 관련 라이브러리
#include <Adafruit_SSD1306.h>        // ssd1306 제어용 라이브러리

#define SCREEN_WIDTH 128              // OLED 디스플레이의 가로 픽셀수
#define SCREEN_HEIGHT 64              // OLED 디스플레이의 세로 픽셀수

#define OLED_RESET     4             // 리셋핀이 있는 oled의 리셋핀에 연결할 아두이노의 핀 번호, 리셋핀이 없는 모듈은 임의의 숫자를 넣어도 됨.
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);    // 디스플레이 객체 생성

byte password[8] = {1,1,1,1,1,1,1,1};
byte answer[8] = {0,};


#define SCL_PIN 8
#define SDO_PIN 9

byte Key;
byte cnt;

void setup(){
  Serial.begin(9600);
  pinMode(SCL_PIN, OUTPUT);
  pinMode(SDO_PIN, INPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop(){
  Key = Read_Keypad();
  if (Key){
    if(cnt < 8){
      answer[cnt++] = Key;
      tone(7, 262,200);
    }
    else if(cnt == 8){
      for(int i = 0; i < 8 ; i++){
        if(answer[i] != password[i]){
          tone(7, 262,100);
          delay(100);
          tone(7, 262,100);
          delay(200);
          tone(7, 262,100);
          delay(200);
          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(WHITE);
          display.setCursor(0,28);
          display.println("Wrong password");
          display.display();
          delay(200);
          display.clearDisplay();
          break;
          
        }
        if(i == 7){
          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(WHITE);
          display.setCursor(0,28);
          display.println("Hello, master!");
          display.display();
          delay(2000);
          tone(7, 262,100);
          delay(100);
          tone(7, 362,100);
          delay(200);
          tone(7, 462,100);
          delay(200);
          display.clearDisplay();
        }
      }
      cnt =0;
    }
  }
    
  delay(100);
}

byte Read_Keypad(void){
  digitalWrite(SCL_PIN, LOW);
  byte Count;
  byte Key_State = 0;
  for(Count = 1; Count <= 8; Count++){
    digitalWrite(SCL_PIN, LOW);
    if (!digitalRead(SDO_PIN))
      Key_State = Count; 
    digitalWrite(SCL_PIN, HIGH);
  }
  return Key_State; 
}