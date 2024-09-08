# I2C 통신이란?
+ Inter-Integrated Circut(I2C)는 IC 사이 통신 링크를 제공하는 양방향 2와이어 직렬 버스 이다
  + 두가닥으로 직렬 통신을 하는 통신프로토콜
+ 구성
  + 하나의 마스터와, 다른 하나의 슬레이브로 구성
  + 슬레이브는 127개까지 구성이 가능
    + 메인 *ECU가 있으면, 그 외 여러가지 디바이스들이 묶여 통신이 가능 
![image](https://github.com/user-attachments/assets/410156f1-cf76-48b1-b867-be438975a455)

### SDA
+ 데이터를 주고 받기 위한 선

### SCL
+ 타이밍을 동기화 하기 위한 클럭 선

## 주의할 점
![image](https://github.com/user-attachments/assets/7a5ba25c-b68f-4f80-a2e2-b650a064c2aa)
+ 풀업 저항(위 그림의 Rp 두개)
  + 저항을 다는 이유
    + I2C 통신을 위해 SDA선과 SCL 선이 모두 기본으로 High 상태가 되어야 한다. 풀업 저항은 이를 High 상태로 만들어 줌
      + 아두이노 사용 한다면 이는 내부 풀업 저항을 사용 하기 때문에 직접 달아 줄 필요 X
    + 한가닥의 선으로 *Tx, Rx를 하기 때문에 Floating 현상이 발생 함을 방지 하기 위해 풀업 저항을 달기도 함


#
#### ECU
+ 전자제어유닛(Electronic Control Unit)
#### Tx, Rx
+ Rx는 수신(Receive), Tx는 송신(Transmit)을 의
