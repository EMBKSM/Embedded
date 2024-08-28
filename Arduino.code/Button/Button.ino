
const int buttonPin = 2;  // buttonPin 2로 설정
const int ledPin = 13;    //ledPin을 13으로 설정
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT); //2번핀을 출력으로 설정
  pinMode(buttonPin, INPUT); //13번 핀을 입력으로 출력
}

void loop() {
  buttonState = digitalRead(buttonPin); //버튼의 상태를 buttonState 값을 저장
  if (buttonState == HIGH) {//버튼을 눌렀는지 확인
    digitalWrite(ledPin, HIGH);//눌렀다면 버튼이 켜짐
  } else {
    digitalWrite(ledPin, LOW);//안눌렸다면 꺼짐
  }
}
