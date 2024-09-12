# ADC란?
+ Analog to Digital Converter의 준말로 아날로그의 신호를 디지털로 바꿔주는 장치를 뜻함.
+ 연속적인 아날로그 신호를 이산적인 디지털로 바꾸는 것
  + 수치화된 신호로 나누는 것을 표본화 또는 샘플링이라 함
    + 단위 시간 동안 샘플링 횟수를 나타낸 분해능은 샘플링 주파수



## 아날로그 신호란?
+ 어떤 양 또는 데이터를 연속적으로 변환하는 물리량(전압, 전류 등)으로 표현 하는 것
+ Arduino 에서의 아날로그
  + 아두이노에서는 아날로그 입력신호를 0 ~ 1023까지, 1024단계로 표현하지만, analogWrite는 0 ~ 255까지 256단계로 이루어져 있다.
    + map 함수를 사용하여 입력신호를 출력신호로 조정
    + map 함수
      + map(value, INmin, INmax, OUTmin, OUTmax) 방식으로 사용
        + map함수는 4개의 인수를 보유
          + INmin = value의 최소값
          + INmin = value의 최대값
          + OUTmin = 반환될 값의 최소값
          + OUTmax = 반환될 값의 최대값
        + map() 함수는 정수 값만 반환
        + map() 함수는 입력 범위와 출력 범위가 서로 일치하지 않아도 작동한다. 예를 들어, 입력 범위가 0~50이고 출력 범위가 -10~10인 경우 sensorValue 가 25일 때 outputValue 는 0이 된다
        + constrain() 함수를 사용하여 변환된 값이 출력 범위 밖으로 나가는 것을 방지할 수 있다.
       
## 디지털 신호란?
+ 데이터를 일련의 *이산 값들로 표현하기 위해 사용되는 신호
+ 흔히 2진수인 0과 1로 표현되는 신호

#
+ 위와 같은 디지털 신호와 아날로그 신호의 차이를 해결하기 위해 사용됨
+ 아날로그 신호를 디지털 데이터로 변환 시키는 방법
  + 3V의 아날로그 전압을 4bit의 *레졸루션 ADC(기준 전압 5V) IC를 거쳐 출력된 디지털 데이터를 계산하여 표현하면 4비트 이므로 2^4 = 16이고 데이터 변환 수식(16 X 3V / 5V(기준 전압)) = 9.6 이므로 정수인 9를 데이터로 표현하면 1001의 데이터가 출력된다.

#
#### 이산
+ 수치적인 의미를 가지나 소수점의 형태로 표현되지 못하는 데이터를 의미
#### 레졸루션
+ 해상도