
int led = 9;//led 핀
int brightness = 0;//led가 얼마나 밝은지
int fadeAmount = 5;//led가 얼마나 바래지고 희미해 지는지


void setup() {
  pinMode(led, OUTPUT); //9번핀을 출력으로 선언
}


void loop() {
  analogWrite(led, brightness);//9번핀의 밝기를 설정

  
  brightness = brightness + fadeAmount;//다음번 밝기 변경

  
  if (brightness <= 0 || brightness >= 255) {//fade의 방향을 바꿔줌(밝기의 증가율이나 감소율을 바꿔줌)
    fadeAmount = -fadeAmount;
  }
  delay(30);//30ms 딜레
}
