

const int analogInPin = A0;  // 아날로그 입력 핀
const int analogOutPin = 9;  // 아날로그 출력 

int sensorValue = 0;  // sensorValue 선언
int outputValue = 0;  // outputValue 선언

void setup() {
  Serial.begin(9600);//시리얼 통신을 9600으로 설정
}

void loop() {
  sensorValue = analogRead(analogInPin);//아날로그입력핀에서 들어온 값을 sensorValue에 저장
  outputValue = map(sensorValue, 0, 1023, 0, 255);//0~1023의 입력 값(sensorValue)을 0~255의 값으로 반환.=>>outputValue

  analogWrite(analogOutPin, outputValue);//9번핀의 출력을 outputValue 값으로 지정

  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  /*위 4줄의 출력은
  sensor = (sensorValue의 값)     output = (outputValue의 값)   (줄바꿈)
  */

  delay(2);//딜레이를 0.02초 주
}
