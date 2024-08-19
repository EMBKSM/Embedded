int pushButton = 2;
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);//푸시버튼의 핀을 입력으로 함
}

void loop() {
  int buttonState = digitalRead(pushButton);//입력된 핀을 읽는다
  Serial.println(buttonState);//버튼 상태출력
  delay(1);  //1ms의 딜레이
}
