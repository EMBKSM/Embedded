# Floating 현상이란?
+ 아무것도 연결되어있지 않아 전압을 모르는 상태를 뜻한다.
  + 처음엔 아래와 같은 경우에서 첫번째 회로는 스위치가 눌렸을때 5v 안눌리면 1v로 나오고 두번째 회로는 그 반대가 나올 줄 알았으나...
    실상은 두 회로 다 안눌렸을 때 값을 알수 없었다. 아니, 계속 바뀌었다. 찾아보니 그 이유는 스위치를 눌렀을때 아무것도 연결이 되지 않아있으니 주변 환경에 영향을 받아서 그렇다는 거였다.
    + 정전기와 전자기파가 주요 원인이다.
  ![image](https://github.com/user-attachments/assets/f680b85e-d7b9-4c02-ab25-07d6c70b0883)

### Floating 현상의 원인을 해결하는 방법
+ PULLUP 저항
+ PULLDOWN 저항


## PULL UP 저항
+ PULL UP 저항은 저항이 위에. 즉, 전력이 공급되는 쪽에 달려있는 저항이다.(아래 사진 참고)
+ PULL UP 저항은 저항이 아래 사진을 기준으로 5v 위치에 달려있기 때문에 스위치를 누르지 않으면 5v가 들어와 HIGH 상태가 되고 눌렀을 경우 저항으로 인해 GND(0v)가 연결되며 LOW가 출력 되게 된다.

![image](https://github.com/user-attachments/assets/72f93ff4-0226-4d13-9e3b-9b5492736189)

## PULL DOWN 저항
+ PULL DOWN 저항은 저항이 아래, 즉 GND 쪽에 달려있는 저항이다.(아래 사진 참고)
+ PULL DOWN 저항은 아래 사진을 기준으로 GND 위치에 달려있기에 스위치를 누르지 않으면 GND(0v)가 들어와 LOW 상태가 되고 눌렀을 경우 저항으로 인해 5v가 연결되며 HIGH가 출력되게 된다.

![image](https://github.com/user-attachments/assets/03f0714c-8ed5-4e92-8886-d5d7d21225b8)
