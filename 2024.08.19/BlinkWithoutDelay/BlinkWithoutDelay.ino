
//변경되지 않는 핀
const int ledPin = LED_BUILTIN;  //LED 핀 번호 LED_BUILTIN은 13번

int ledState = LOW;  //LED 설정에 사용되는 변수


unsigned long previousMillis = 0;  //마지막으로 LED가 업데이트 되었을때를 저장

// constants won't change:
const long interval = 1000;  //1초의 간격

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();//현재 시간을 밀리초로 가져옴

  if (currentMillis - previousMillis >= interval) {//현재시간과 이전시간에 차이가 interval보다 큰지확인하고 크다면 갱신
    previousMillis = currentMillis;

    if (ledState == LOW) {//led의 상태를 어떻게 정의 할것인지 결정 
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);//led의 상태를 ledState 값으로 정의
  }
}
