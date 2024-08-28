
void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);//LED_BUILTIN을 출력으로 초기화
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);//LED를 킴
  delay(1000);//1초 기다림
  digitalWrite(LED_BUILTIN, LOW);//LED를 끔
  delay(1000);//1초 기다
}
