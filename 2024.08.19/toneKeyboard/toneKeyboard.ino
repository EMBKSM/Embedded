
#include "pitches.h"//음계 라이브러리

const int threshold = 10;  // 노트를 생성하는 최소 판독값을 10으로 정의(불변)


int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3
};

void setup() {
}

void loop() {
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {//3번 반복
    int sensorReading = analogRead(thisSensor);//thisSensor에 해당하는 센서의 값을 sensorReading에 저장

    if (sensorReading > threshold) {//sensorReading이 this
      // play the note corresponding to this sensor:
      tone(8, notes[thisSensor], 20);
    }
  }
}
