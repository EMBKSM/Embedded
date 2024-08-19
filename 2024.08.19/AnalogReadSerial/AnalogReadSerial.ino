void setup() {
  Serial.begin(9600);//초당 9600 비트로 시리얼 통신 초기화.(시리얼 통신:연속적으로 통신 채널이나 컴퓨터 버스를 거쳐 한 번에 하나의 비트 단위로 데이터를 전송하는 과정)
}


void loop() {//무한 반복
  int sensorValue = analogRead(A0);//아놀로그 핀 0에서 입력을 읽기. //read핀이 기본값
  Serial.println(sensorValue);//읽은 값을 출력
  delay(1);  //1ms의 딜레이 
}