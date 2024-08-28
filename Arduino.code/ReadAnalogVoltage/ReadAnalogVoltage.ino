
void setup() {
  Serial.begin(9600);//시리얼 통신을 9600으로 설정
}

void loop() {
  int sensorValue = analogRead(A0);//아날로그 핀 0에서 핀읽기
  float voltage = sensorValue * (5.0 / 1023.0);//아날로그 판독값 0~1023을 0~5V전압으로 전환
  Serial.println(voltage);//전압값을 출력
}
