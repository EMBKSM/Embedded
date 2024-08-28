
const int numReadings = 10; //숫자를 읽을 갯수를 10개로 정의(불변)

int readings[numReadings];  // 읽어들일 배열을 10개로 정의
int readIndex = 0;          // 읽기 인덱스를 0으로 초기화
int total = 0;              // 몇번 실행했는지를 0 으로 초기화
int average = 0;            // 평균값을 정의

int inputPin = A0; //입력핀을 A0핀으로 정의

void setup() {
  Serial.begin(9600);//시리얼 통신값을 9600으로 설정
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {//10번반복
    readings[thisReading] = 0;//반복할때마다 배열크기가 하나씩, 0~9까지 증가
  }
}

void loop() {

  total = total - readings[readIndex];//총합에 기존 총합에 읽어들일배열의 읽기 인덱스 위치의 값을 뺀값을 대입
  readings[readIndex] = analogRead(inputPin);//A0의 아날로그 입력신호값을 읽어들일배열의 읽기 인덱스 위치에 저장
  total = total + readings[readIndex];//총합 값에 기존 총합에 읽어들일배열의 읽기 인덱스 위치의 값을 더한값을 대입
  readIndex = readIndex + 1;//읽기 인덱스를 1증가

  if (readIndex >= numReadings) {//읽기 인덱스의 값이 읽어들일 값보다 같거나 커지면 초기화
    readIndex = 0;
  }


  average = total / numReadings;//평균값에 총합에서 읽어들일값(10)으로 나눈값을 대입
  Serial.println(average);//평균값을 출력
  delay(1);  // 0.001초의 딜레이
}
