
const int sensorPin = A0;  // 센서핀을 A0으로 정의(불변)
const int ledPin = 9;      // led핀을 9번 핀으로 정의


int sensorValue = 0;   // 센서의 value 값 선언
int sensorMin = 1023;  // 센서의 최소값 선언
int sensorMax = 0;     // 센서의 최대값 선언


void setup() {//왜인지 모르겠으나 13번 핀이 입출력으로 되어 있음 나중에 아두이노를 가지고 실행할때 9번핀으로 수정이 필요한지 확인 요함
  pinMode(13, OUTPUT);//13번 핀을 출력으로 설정
  digitalWrite(13, HIGH);//13번핀의 값을 HIGH로 설정

  while (millis() < 5000) {//5초가 되기 전까지 반복하기
    sensorValue = analogRead(sensorPin);//A0핀의 센서값을 sensorValue에 저장

    if (sensorValue > sensorMax) {//sensorValue값이 센서 최대값보다 크다면 센서 최대값을 갱신
      sensorMax = sensorValue;
    }

    if (sensorValue < sensorMin) {//sensorValue값이 센서 최소값보다 작다면 센서 최소값을 갱신
      sensorMin = sensorValue;
    }
  }


  digitalWrite(13, LOW);//13핀을 LOW값으로 설정
}

void loop() {
  sensorValue = analogRead(sensorPin);//A0핀의 센서값을 sensorValue에 저장


  sensorValue = constrain(sensorValue, sensorMin, sensorMax);
  /*
  sensorValue값이 센서 최소값과 최대값 사이에 있다면 sensorValue값이 변하지 않고,
  sensorValue값이 센서 최소값보다 작으면, 센서 최소값을 sensorValue에 저장하고
  sensorValue값이 센서 최대값보다 크다면, 센서 최대값을 sensorValue에 저장한다.
  */

//sensorValue값을 센서의 최소값과 센서에 최대값에 비례해서 0~255값으로 변환하여 sensorValue값에 저장
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  analogWrite(ledPin, sensorValue);//위에서 변환한 sensorValue만큼 led핀(9번)의 밝기를 조절
}
