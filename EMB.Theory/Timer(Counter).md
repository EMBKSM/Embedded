 # 아두이노에서의 타이머
+ 타이머는 아두이노 컨트롤러에 내장된 하드웨어의 한 구성요소이다.
+ 사용자는 특별한 레지스터들을 이용해서 타이머의 동장방식, 주기 등등을 프로그래밍 할 수 있습니다.
+ 아두이노의 Atmel AVR ATmega168, ATmega328 컨트롤러 3개의 타이머 - timer(), timer1(), timer2()를 가지고 있습니다.
  + timer(), timer2() 8비트 타이머이다.
  + timer1()은 16비트 타이머이다.
    + 8비트와 16비트 타이머의 차이점은 해상도이다.
  + (ATmega1280, ATmega2560 칩은 6개의 타이머를 제공합니다. timer0, timer1, timer2 는 ATmega128/328 과 동일한데 timer3, timer4, timer5는 16비트 타이머로 동작합니다.)
+ 모든 타이머는 아두이노의 시스템 쿨럭에 종속적이다.
  + 일반적으로 시스템 클럭이 16MHz이다.
    + Pro mini 보드와 같이 8 MHz로 동작하는 경우는 다르게 적용됨
+ 타이머 하드웨어는 특별한 타이머 레지스터에 의해 설정됨
  + 아두이노 펌웨어에서는 모든 타이머가 1KHz frequency로 맞춰져있음

## TIMER(), TIMER1(), TIMER2()
+ Timer() 시간관련 함수에 사용됨.
  + Timer() 레지스터를 변경하면 delay(), millis(), micros() 와 같은 시간관련 함수들도 영향을 받게 됨
+ 아두이노 UNO 보드의 경우 서보모터 라이브러리(Servo)가 Timer1을 사용합니다. (아두이노 Mega 보드에서는 Timer5 를 사용)
+ Timer2 는 8비트 타이머로 tone() 함수 등에 사용

# 타이머 레지스터
+ 타이머 레지스터를 통해 타이머 동작을 바꿀 수 있음
+ 가장 중요한 타이머 레지스터는 TCCRx (Timer/Counter Control Register)
![image](https://github.com/user-attachments/assets/fc7af2f0-1bdf-4749-828b-4cc41edea523)
  + TCNTx - Timer/Counter Register. 실질적인 타이머 동작 값이 여기에 저장됩니다.
  + OCRx - Output Compare Register
  + ICRx - Input Capture Register (16비트 타이머용)
  + TIMSKx - Timer/Counter Interrupt Mask Register. 타이머 인터럽트 활성화/비활성화 용도
  + TIFRx - Timer/Counter Interrupt Flag Register. pending timer interrupt 용도인지 표시

## 동작 클럭과 타이머 주기
+ CPU 동작 클럭에 따라 타이머 주기(timer frequency)는 아래와 같이 결정
  + CPU 동작 주기 = 16MHz
  + 최대 타이머 카운트 (8비트는 256, 16비트는 65536)
  + CPU 주기를 선택한 prescaler 로 나눔 (16000000 / 256 = 62500)
  + 결과값을 다시 원하는 주기로 나눔 (62500 / 2Hz = 31250)
  + 결과값을 최대 카이머 카운트와 비교 (31250 < 65536 : 적합). 적합하지 않은 경우 더 큰 prescaler 를 선택함

# 레지스터와 타이머 동작
+ 타이머 모드
  + 타이머는 여러가지 타이머 모드로 설정할 수 있음
    + PWM 모드에서는 OCxy output 값이 PWM 신호를 생성하기 위해 사용
    + CTC(Clear timer On Compare match) 모드에서는 타이머 카운터가 compare match register 값에 도달할 때 타이머가 삭제
    + 레지스터에 따라 변화하는 모드 ↓


# 타이머 인터럽트
+ Pending interrupt 가 ISR을 실행하기 위한 조건
  1. 인터럽트가 활성화 되어야 함
      + 인터럽트는 interrupts(), noInterrupts() 함수로 활성화/비활성화 할 수 있음
  2. 관련된 인터럽트 마스크가 활성화 되어야 함
      + 인터럽트 마스크는 interrupt mask register(TIMSKx) 에서 setting/clearing bit 를 설정함으로써 활성화/비활성화 할 수 있음
![image](https://github.com/user-attachments/assets/66e265a5-f5a4-42c3-92a0-47dc2c9a68b0)


+ TIMER OVERFLOW
  + 타이머 오버플로우는 타이머 카운트가 최대값에 도달함을 의미한다. 타이머가 오버플로우되면 인터럽트가 발생하고 TOVx 값이 TIFRx 에 설정됨
  +  만약 TIMSKx에 TOIEx 값이 설정되어 있다면 TIMERx_OVF_vect 함수가 호출됨
 +  PWM 과 TIMER
   + 프로세서의 핀아웃 문서나 데이터 시트를 보면 OCRxA, OCRxB, OCRxC 로 표기된 PWM 핀이 있다. (x는 타이머 숫자 0~5) Mega를 제외한 일반적인 아두이노는 3개의 타이머와 6개의 PWM 핀이 있으며 아래와 같이 연관되도록 설정되어 있다.
     + Pin 5, 6 : timer0 에 의해 컨트롤
     + Pin 9, 10 : timer1 에 의해 컨트롤
     + Pin 11, 3 : timer2 에 의해 컨트롤

 ## 주의사항
 + 서보 라이브러리(Servo library)는 Timer1 을 사용
   + 서보 라이브러리를 사용할 경우 9, 10번 PWM 은 사용할 수 없음
   + 아두이노 Mega 보드의 경우는 좀 더 복잡해서 사용하는 서보의 갯수에 따라 제한이 바뀐다.
 + tone() 함수는 적어도 timer2 를 사용
   + 이 경우 3, 11번 핀의 PWM을 사용할 수 없음
   + Mega 보드의 경우는 9, 10번 핀을 사용할 수 없음
