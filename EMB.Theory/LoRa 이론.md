### IoT의 무선기술들
- Short Range
  - WiFi
  - ZigBee
  -Bluetooth
- Long Range
  - 비면허대역 ← 면허대역의 가격 비쌈의 대체제들
    - LoRa  ← SKT(계속 지원중)
    - sigfox ← KT(접음)
  - 면허대역 ← 가격이 비쌈
    - Lte
- IP Base의 소프트웨어가 굉장히 무겁고, 배터리 소모량도 엄청남

## LPWA & LoRaWan
- 저전력 소모
- 저가 단말기
- 낮은 구축비용
- 안정적 커버리지
- 대규모 단말기 접속

- 누구나 기술만 있으면 사용할 수 있다
- LoRaWAN은 규약 단체에서 내놓은 네트워크 시스템
- LoRa는 기술 이름
#### LoRaWAN의 아키텍쳐

![image](https://github.com/user-attachments/assets/87a715e7-39e7-4d81-87fa-fb5c37c168ca)


- 네트워크 서버와 애플리케이션 서버 사이에는 aes 128 암호화 방식을 사용하여 전달한다.


## LoRaWAN의 구조
![image](https://github.com/user-attachments/assets/3bd9ff41-f129-4d60-8c8a-0a285cf6bad2)

- end device : RTOS 기반에 아주 작은 단말기들이 올라감
- Gateway : radio 값만 받아서 네트워크 서버로 포워딩만 한다. ← 인터넷 베이스로, 1:N(One-to-Many)구조 및 OneM2M으로 이는 IoT 기술에 대한 표준.
- 네트워크 끼리 주고 받을때는 네트워크 세션 키를 사용하여 암호화 한다.
- 앱끼리 주고 받을때는 앱세션 키를 사용하여 암호와 한다.


### LoRaWAN의 네트워크 레이어
![image](https://github.com/user-attachments/assets/8cc9b6fb-e8d7-4717-aaaa-8502b56aaf3e)
- ISM 대역이란, 산업·과학·의료 등에 쓰이는 주파수 대역이다.

- LoRa 맵 레이어들은 크게 클레스 A,B,C로 구성되어 있고 이것은, 서버단의 데이터들을 어떻게 단말기에 줄거냐에 대한 규약이다.
  - A : 디폴트, 단말기단에서 구현
  - B,C : 단말기에 사용법에 따라 다름

### class A,B,C 방식
![image](https://github.com/user-attachments/assets/f8a1ebe3-b5de-471a-8795-ac9e068fac6b)

- A : 단말단에서 데이터를 올리면, 일정 딜레이 타임 이후에 Rx윈도우를 열고, 서버단에서 데이터를 내려야하는데 데이터가 안내려오면 단말단이 무시한다. 데이터가 안들어왔으면 Rx2를 다시연다. 2채널은 tx와 rx채널과 무관하게 따로 채널이 연결이되고, 여기에도 데이터가 안들어오면 끝이다. 이 상황에는 서버단에서 단말기에 데이터를 내려다 줄수 없게된다.
- B : 비콘과 연동해서 중간중간에 한번씩 서버와 동기화하는것, 비콘 타임에 맞춰서 바꾸는 시간을 연다.
- C : Rx2 원도우를 상시열어두는 것, 배터리 소비량이 매우 높음

### LoRaWAN 네트워크에 접속 절차
1. 단말 기기 앱 단에서 켜졌다는 인디케이션을 단말기기 맥 단에 전달한다.
2. 맥 단에서 디바이스 값, 어플리케이션과 같이 중요한 앱키라는 값을 가지고 있어 앱키로 join Request를 네트워크 서버에 날린다.
3. 네트워크 서버가 join Request를 받으면 앱키로 MSG 암호화
4. (경우에 따라 없을 수 있음) join 인디케이션을 앱서버에 날린다.
5. 네트워크 서버가 join Accept를 단말기기의 맥 단으로 날린다
6. 맥단에서 받은 join Accept 인디케이션을 앱 단으로 보낸다.

### LoRaWAN의 데이터 흐름
1. 단말 기기 앱 단에서 앱데이터를 맥 단으로 데이터를 보낸다.
2. 맥 단에서 받은 데이터를 APPSKey로 MSG 암호화를 하고 그걸 네트워크 서버로 보낸다.
3. 네트워크 서버에서 APPSKey로 MSG 복호화 하여 앱서버로 보낸다.

- 단말기기 맥단과 서버가 명령어 리퀘스트를 NWSKey로 MSG 암호화와 복호화 해서 서로 통신

### LoRaWan과 SKT LoRa의 다른점
- 간단한 구조로 인한 해킹의 취약점을 과정을 추가함으로써 해결함
- DB 단에서 Thing-plug에다가 저장하는 과정이 더 있다. 이 과정으로 어떤 정보가 들어왔는지에 대한 모든것을 알아낼 수 있다.
- Thing-Plug에서 단말단에 요청하는 절차가 있는데, 단말기기 단에 추가 해야할 절차가 있다.


#### SKT LoRa의 구조
![image](https://github.com/user-attachments/assets/5318cf6d-89ef-4a75-9b0b-1fc32df02a8c)

- LoRa Device와 네트워크 서버간에 개통 할 정보가 있을텐데 그걸 ThingPlug와 무언가를 주고 받음(접속 정보라던지, 어플리케이션 데이터 포트를 이용하여 디바이스를 제어하는 네트워크 메세지라던가, 단말기기 제어 등)


#### SKT OTAA 접속 절차
1. 단말 기기단는 여느 LoRa와 동일
2. 가짜 앱키로 암호화 하고 암호와 된것을 가지고 던지면 복호화 해서 진짜 앱키를 단말기기 맥 단으로 보내게 되고 받았는지 확인절차를 밟고 난 후 사용하게 되는데, 확인 절차를 밟지 않으면 진짜 앱키가 확정되지 않게 된다. 그말은 즉 진짜 앱키가 진짜 앱키가 아니게 된다는 뜻(효력x)
3. 그후 진짜 앱키를 가지고 Real Join을 날린다.
4. 서버에서 단말기기 맥단으로 Join Accept를 보넴
5. 단말기기 맥단에서 Real APPSKey, Real NWSKey를 생성

- 진짜 앱키는 모듈 저안에 저장되어 있고 아무도 빼갈수 없다. 모듈업체마다 다 다른곳에 저장되기 때문. <br>-> 해킹에 강한상태
- Real Join 전 과정은 개통후 처음만 이루어진다. 이 후에는 3~5번만 반복된다.

#### SKT 데이터 흐름
- Real APPSKey로 데이터를 주고 받는다.
- 네트워크도 Real NWSKey로 주고 받는다.
- 데이터 흐름은 일반 LoRa와 거의 비슷하나 Thing-Pulg가 생김으로써 mqtt를 이용해 Thing-Plug에 앱서버를 하나 등록하고, Subscribe를 등록을 해놓으면 Thing-Plug가 OneM2M 방식으로 앱데이터가 올때마다 Push로 알려준다.
- SKT 같은경우는 LoRaWAN과 다르게 단말기기만 데이터를 보내지 않고 앱이 단말기기로 데이터를 보네기도 한다.
  - 앱서버 없이 Thing-Plug 자체가 보내기도 한다.
  - 단말단에서 데이터를 보내지 않으면 보낼수 없다.
  1. 앱서버가 보낸 어떤 요청을 OneM2M으로 Thing-Plug가 네트워크 서버에 요청
  2. 네트워크서버가 앱세션키로 요청을 MSG 암호화하고 맥단으로 보넨다.
  3. 맥단은 해석만해서 단말기기 앱단으로 보낸다.
  4. 요청을 실행하고 상태를 Real APPSKey MSG 암호화 한 후 Thing-Plug까지 날린다.
 
#### SKT LoRa를 사용할때 해야하는 것
![image](https://github.com/user-attachments/assets/ace29525-a843-44b9-956c-abacf3e7468c)

