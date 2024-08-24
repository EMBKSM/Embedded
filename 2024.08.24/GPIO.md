# GPIO 란?
+ GPIO란 General Purpose Input/Ouput 의 줄임말로, 마이크로 컨트롤러의 핀을 입력 또는 출력 용도로 사용할 수 있게 하는 기능
  + 아두이노의 경우 5V 기준의 마이크로 프로세서이기에 헤더 소켓을 통해 0V 또는 5V의 입출력만 가능 함

# digitalWrite()
+ 아두이노는 이 함수를 통해서 GPIO output 기능을 수행함.
+ digitalWrite(pin number, HIGH or LOW)를 통해 실행 할 수 있음

# digitalRead()
+ 아두이노는 이 함수를 통해서 GPIO input 기능을 수행함.
+ digitalRead(pin number)를 통해 실행 할 수 있음
+ 해당되는 핀에 0V가 걸리면 0, 5V가 걸리면 1을 출력함
