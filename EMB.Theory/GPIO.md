# GPIO란?

**GPIO**는 **General Purpose Input/Output**의 약자로, 마이크로컨트롤러의 핀을 입력 또는 출력 용도로 사용할 수 있게 하는 기능입니다.  
예를 들어, **아두이노**의 경우 5V 기반의 마이크로프로세서를 사용하며, GPIO 핀을 통해 0V 또는 5V의 입력 및 출력을 제어할 수 있습니다.

---

## GPIO 핀의 특징
1. **범용성**  
   - 특정 기능에 제한되지 않고, 다양한 장치와의 인터페이스에 사용할 수 있습니다.  
2. **입력(Input)**  
   - 외부 신호를 읽어들입니다. (예: 버튼, 센서 신호)
3. **출력(Output)**  
   - 외부 장치로 신호를 보냅니다. (예: LED, 모터 제어)

---

## GPIO 관련 함수 (아두이노)

### 1. `pinMode()`
이 함수는 GPIO 핀의 동작 모드를 설정하는 함수입니다.  
해당 핀을 **입력**(INPUT), **출력**(OUTPUT), 또는 **풀업 입력**(INPUT_PULLUP)으로 설정할 수 있습니다.

**사용 형식:**  
`pinMode(pin, mode)`  
- **pin**: 설정할 핀 번호  
- **mode**: 핀의 동작 모드 (`INPUT`, `OUTPUT`, `INPUT_PULLUP`)  

---

### 2. `digitalWrite()`
GPIO 핀의 **출력** 상태를 설정하는 함수입니다.  
핀에 **HIGH(5V)** 또는 **LOW(0V)**를 출력할 수 있습니다.

**사용 형식:**  
`digitalWrite(pin, value)`  
- **pin**: 설정할 핀 번호  
- **value**: 출력 상태 (`HIGH`, `LOW`)  

---

### 3. `digitalRead()`
GPIO 핀의 **입력** 상태를 읽는 함수입니다.  
핀에 연결된 신호가 **0V**일 경우 `0`, **5V**일 경우 `1`을 반환합니다.

**사용 형식:**  
`digitalRead(pin)`  
- **pin**: 읽을 핀 번호  

---

## 추가 내용: GPIO와 관련된 주요 개념

### 1. **INPUT_PULLUP**
- 일부 마이크로컨트롤러는 내부 풀업 저항을 제공합니다.  
  이 모드를 사용하면 외부 풀업 저항 없이 핀을 HIGH 상태로 유지할 수 있습니다.

---

### 2. **PWM (Pulse Width Modulation)**
- 일부 GPIO 핀은 아날로그 출력을 흉내 내는 **PWM** 기능을 지원합니다.  
  이를 통해 LED의 밝기를 조절하거나 모터의 속도를 제어할 수 있습니다.  
  아두이노에서는 `analogWrite(pin, value)`를 통해 구현 가능합니다.
