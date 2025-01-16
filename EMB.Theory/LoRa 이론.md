### IoT의 무선기술들
- Short Range
	- WiFi
	- ZigBee
	-Bluetooth
- Long Range
	-  비면허대역 ← 면허대역의 가격 비쌈의 대체제들
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
- Gateway : radio 값만 받아서 네트워크 서버로 포워딩만 한다. ← 인터넷 베이스로, 1:N(One-to-Many)구조로
- 네트워크 끼리 주고 받을때는 네트워크 세션 키를 사용하여 암호화 한다.
- 앱끼리 주고 받을때는 앱세션 키를 사용하여 암호와 한다.


### LoRaWAN의 네트워크 레이어
![image](https://github.com/user-attachments/assets/8cc9b6fb-e8d7-4717-aaaa-8502b56aaf3e)
- ISM 대역이란, 산업·과학·의료 등에 쓰이는 주파수 대역이다.
