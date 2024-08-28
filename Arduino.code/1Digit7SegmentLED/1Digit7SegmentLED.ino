int arr[][8] = {
  {2, 3, 4, 5, 6, 7},
  {3, 4},
  {2, 3, 5, 6, 8},
  {2, 3, 4, 5, 8},
  {3, 4, 7, 8},
  {2, 4, 5, 7, 8},
  {2, 4, 5, 6, 7, 8},
  {2, 3, 4, 7},
  {2, 3, 4, 5, 6, 7, 8},
  {2, 3, 4, 5, 7, 8}
};

int num = 0;

void activePinAt(int pin[], int len) {
  for (int i = 0; i < len; i++) {
    digitalWrite(pin[i], HIGH);
  }
}

void disableAllPins() {
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
  }
}



void setup() {
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
}

void loop() {
  disableAllPins();
  num = ++num%(sizeof(arr)/sizeof(arr[0]));//반복할때마다 숫자가 증가, 나머지 연산자로인해 숫자가 저장된 숫자를 초과하지 않음
  activePinAt(arr[num], sizeof(arr[num])/sizeof(arr[num][0]));//어떤핀이 움직일지 정하는 함수에 arr[num]과 arr[]의 size를 
  delay(200);//딜레이
}