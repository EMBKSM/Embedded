
const int buttonPin = 2;  // 버튼 핀을 2번으로 지정(불변)
const int ledPin = 13;    // led핀을 13번으로 지정(불변)

int ledState = HIGH;        // 출력핀의 현재 상태
int buttonState;            // buttonState 선언
int lastButtonState = LOW;  // 마지막 출력의 상태

unsigned long lastDebounceTime = 0;  // 출력 핀이 마지막으로 토글된 시간
unsigned long debounceDelay = 50;    // 딜레이를 50으로 설정
void setup() {
  pinMode(buttonPin, INPUT);//입력을 버튼핀(2번)으로 설정
  pinMode(ledPin, OUTPUT);//출력을 led핀(13번핀)으로 설정

  digitalWrite(ledPin, ledState);//13번핀의 led핀을 ledState의 상태로 정의
}

void loop() {
  int reading = digitalRead(buttonPin);//reding의 값을 버튼핀의 상태로 설정

  if (reading != lastButtonState) {//마지막으로 토글된 값과 다르다면 마지막으로 토글된 시간을 저장
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {//시간에서 마지막으로 토글된 시간 뺀값이 딜레이보다 큰가 확인

    if (reading != buttonState) {//버튼 핀의 현재 상태가 변수 buttonState에 저장된 마지막 상태와 다른지 체크
      buttonState = reading;//버튼핀의 현제 상태를 buttonState에 저장


      if (buttonState == HIGH) {//버튼핀의 현제상태가 HiGH이면 ledState값을 반전합니다.
        ledState = !ledState;
      }
    }
  }


  digitalWrite(ledPin, ledState);//led(13번)핀을 ledState에 저장되어 있는 값의 상태로 만든다.


  lastButtonState = reading;//마지막으로 토글된 시간 갱신
}
