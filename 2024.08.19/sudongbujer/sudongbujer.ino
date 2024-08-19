/*
가운도 261
도# 277
레 293
레# 311
미 329
파 349
파# 370
솔 392
솔# 415
라 440
라# 466
시 493
높도 523
높도# 554
높레 587
높레# 622
높미 659
높파698
높파# 739
높솔 783
높솔# 830
높라 880
높라# 932
높시 987
*/





int buzzerPin = 2;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 523);
  delay(200);
  noTone(buzzerPin);
  
  tone(buzzerPin, 392);
  delay(200);
  noTone(buzzerPin);

  tone(buzzerPin, 523);
  delay(200);
  noTone(buzzerPin);

  tone(buzzerPin, 587);
  delay(200);
  noTone(buzzerPin);

  tone(buzzerPin, 523);
  delay(200);
  noTone(buzzerPin);

  tone(buzzerPin, 587);
  delay(200);
  noTone(buzzerPin);
  }