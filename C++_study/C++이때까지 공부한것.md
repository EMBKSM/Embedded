# C++

- C 언어에서 작성된 코드를 그대로 C++ 에 붙여 넣기 해도 큰 문제가 없다고 말해도 과언이 아닌 만큼 C++ 은 C 언어의 문법을 거의 완전하게 포함

## 변수 선언 규칙

### 변수의 이름은 변수의 이름만을 딱 보았을 때 무엇을 하는지 확실히 알 수 있어야 함

```cpp
int number_of_people;  // OK
double interest_rate;  // OK
```

- 맨 위의 두 변수 이름들은 딱 보았을 때 '아, 사람의 인원수이고 아래는 이자율 이구나' 라는 느낌이 확 들지만 아래의 두 변수 이름을 보았을 때에는 그러한 느낌을 받기 힘듭니다. 따라서 변수 이름이 조금 길더라도 확실히 이해할 수 있는 변수 이름을 짓는 것이 매우 중요합니다.

### 변수 이름의 띄어쓰기에 관한 규칙

```cpp
int number_of_people;  // OK
int NumberOfPeople;    // OK
```

- 위 처럼 두 가지 방법을 사용하는데 하나는 이름의 띄어쓰기 부분에 `_` 를 넣는 것이고 다른 하나는 띄어쓰기 부분에 대문자로 구분하는 것인데, 저의 경우 전자의 방법을 선호합니다. 물론 이는 사람 마다 개인차가 있겠지만, 가장 중요한 것은 한 코드 안에 위 두 방식을 혼용하지 않는 것입니다.

## C++의 입출력 헤더파일

- **`<iostream>`**
    - C++에서 표준 입출력에 필요한 것들을 포함하는 헤더파일
    - ****C언어의**`<stdio.h>`** 와 비슷함
    - C와 다르게 헤더파일 이름뒤에 **`.h`** 가 붙지 않음
    - **`std::cont`**
        - 화면에 출력
        - `ostream` 클래스의 객체로 표준 출력을 담당
            
            ```cpp
            std::cout << /* 출력할 것 */ << /* 출력할 것 */ << ... << /* 출력할 것 */;
            ```
            
    - **`std::endl`**
        - 한 줄 엔터
    - **`std::cin`**
        - 입력을 받음(레퍼런스를 이용해서 &를 쓸 필요가 없음)
        - C언어 scanf와 같음
            - 허나 C언어에서 %d, %c 등과 같은 것을 사용해서 문자형을 정해준 것과 달리, 자동으로 int, char 등 형을 정해준다.

## `namespace`(이름 공간)

- 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 것과 동일합니다.
- 중복된 이름을 가진 함수가 많아져 이를 구분하기 위해 만들어짐
- 아래 코드를 보면 std 라는 namespace에 정의되어있는 cout를 의미함
    
    ```cpp
    std::cout
    ```
    
    - std::없이 그냥 cout를 쓰는 컴파일러가 찾지 못함
- 자기 자신이 포함되어 있는 공간에서는 이름공간을 명시하지 않고도 자윩베 부를 수 있다.
- 어떠한 이름공간에도 소속되지 않는 경우 명시적으로 이름 공간을 지정해야함
- namespace를 정의하는 방법
    
    ```cpp
    namespace header1 {
    int foo();
    void bar();
    }
    ```
    
    - namespace를 쓰고 이름공간의 이름을 쓴다음 내용을 입력하면 된다.
- 반복적으로 호출하는 경우 using을 사용해서 이름공간의 이름없이 사용할 수 있다.
    
    ```cpp
    #include "header1.h"
    #include "header2.h"
    
    using header1::foo;
    int main() {
      foo();  // header1 에 있는 함수를 호출
    }
    ```
    
    - 여기서 **`using namespace 이름공간의이름`** 을 사용해서 이름공간의 이름 없이 그 이름공간의 코드를 쓸 수 있다.

## 이름 없는 이름공간

```cpp
#include <iostream>

namespace {
// 이 함수는 이 파일 안에서만 사용할 수 있습니다.
// 이는 마치 static int OnlyInThisFile() 과 동일합니다.
int OnlyInThisFile() {}

// 이 변수 역시 static int x 와 동일합니다.
int only_in_this_file = 0;
}  // namespace

int main() {
  OnlyInThisFile();
  only_in_this_file = 3;
}
```

- 이 경우 이름 공간의 이름을 지정하지 않아도 됨
- 이름 공간에 정의된 것들은 해당 파일 안에서만 접근할 수 있다
- 간단히 광범위 **`static`**

## 참조자(reference)

- `a` 의 참조자 `another_a` 를 정의하였다. 이 때 참조자를 정하는 방법은, 가리키고자 하는 타입 뒤에 `&` 를 붙이면 됨
    
    ```cpp
    #include <iostream>
    
    int main() {
      int a = 3;
      int& another_a = a;
    
      another_a = 5;
      std::cout << "a : " << a << std::endl;
      std::cout << "another_a : " << another_a << std::endl;
    
      return 0;
    }
    ```
    
- `int` 형 변수의 참조자를 만들고 싶을 때에는 `int&` 를, `double` 의 참조자를 만드려면 `double&` 로 하면 된다. 심지어 `int*` 와 같은 포인터 타입의 참조자를 만드려면 `int*&` 로 쓰면 됨
- **레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 합니다.**
- C++ 문법 상 참조자의 참조자를 만드는 것은 금지

### 상수의 대한 참조자

- 아래 코드는 오류가 나는 코드이다. `int& ref = 4;` 를 `const int ref = 4;` 방식으로 선언하면 된다.
    
    ```cpp
    #include <iostream>
    
    int main() {
    	int& ref = 4;//상수를 레퍼런스로 참조할 수 없다.
    
    	std::cout << ref << std::endl;
    }
    ```
    
- 상수값 자체는 리터럴이기 때문에 바꾸지 못한다.

### 레퍼런스 배열

- 레퍼런스 배열 자체는 불법이다.
    
    ```
    C++ 표준안: 8.3.2/4
    
    There shall be no references to references, no arrays of references, and no pointers to references
    레퍼런스의 레퍼런스,레퍼런스의 배열, 레퍼런스의 포인터는 존재할 수 없다.
    ```
    
- C++의 배열이 처리되는 방식
    - 문법 상 배열의 이름은 (`arr`) 첫 번째 원소의 주소값으로 변환이 될 수 있어야 한다. 이 때문에 `arr[1]` 과 같은 문장이 `*(arr + 1)` 로 바뀌어서 처리될 수 있기 때문.
- 배열을 할 수 있는 방식
    - 배열의 레퍼런스의 경우 참조하기 위해선 반드시 배열의 크기를 명시

### 레퍼런스를 리턴하는 함수

- 함수가 종료되면 레퍼런스는 사라지기 때문에 사라진 것을 리턴하게 됩니다(NULL과 비슷)
- 주의사항
    - **레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지 않도록 조심**해야 합니다.
- 외부 변수 레퍼런스의 리턴
    - 외부 변수를 함수의 레퍼런스 인자 값으로 받은 경우는 레퍼런스가 사라지더레도 외부 변수의 레퍼런스 였기에 외부변수가 바뀌면서 출력이 됨
    - 장점
        - **레퍼런스가 참조하는 타입의 크기와 상관 없이 딱 한 번의 주소값 복사로 전달이 끝나게 됩니다**.
- 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
    - 위에 상수에 대한 참조자에서 적은 것처럼 const를 사용하여 상수 레퍼런스로 받게 되면 해당 리턴 값의 수명을 연장 시킬 수 있다.

## 메모리

### `new`

- `new` = `malloc`(C)
    
    ```cpp
    T* pointer = new T;
    ```
    
    - T는 type, pointer는 변수명

### `delete`

- `delete` = `free`(C)
- 만약 지역 변수를 무리하게 delete로 해제하려한다면,  `Heap` 이 아닌 공간을 해제하려고 한다는 경고 메세지가 나타나게 된다.

### `new`로 배열 할당받고, `delete`로 배열 해제하기

- 배열을 생성할 때 에는 `[]` 를 이용해 배열의 크기를 넣어주면 됨
    
    ```cpp
    T* pointer = new T[size];
    ```
    
- 배열을 삭제할 때는 []를 `delete` 옆에 붙여 해제하면 됨
    
    ```cpp
    delete[] list;
    ```
    

## 객체 지향 시작

- **객체란, 변수들과 참고 자료들로 이루어진 소프트웨어 덩어리이다.**
- 인스턴트 메소드
    - 객체에 정의되어 있는 함수
- 인스턴트 변수
    - 객체에 정의되어 있는 변수
- 접근 지시자
    - 키워드 명시를 하지 않았다면 자동으로 private로 설정
    - private
        - 객체 내부에서만 접근할 수 있는 변수
        - 객체 외부에서 접근하면 오류가 발생
    - public
        - 객체 내부 외에서도 사용할 수 있는 변수

## 함수의 오버로딩

- 함수의 이름이 같다면, 인자값에 따라 같은 이름의 다른 함수를 불러옴
    
    ```cpp
    /* 함수의 오버로딩 */
    #include <iostream>
    
    void print(int x) { std::cout << "int : " << x << std::endl; }
    void print(double x) { std::cout << "double : " << x << std::endl; }
    
    int main() {
      int a = 1;
      char b = 'c';
      double c = 3.2f;
    
      print(a);
      print(b);
      print(c);
    
      return 0;
    }
    /*출력
    int
    ```
    
- 함수의 오버로딩 과정
    1. 단계
        1. 자신과 타입이 정확히 일치하는 함수를 찾는다.
    2. 단계
        - 정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
        - `Char, unsigned char, short` 는 `int` 로 변환된다.
        - `Unsigned short` 는 `int` 의 크기에 따라 `int` 혹은 `unsigned int` 로 변환된다.
        - `Float` 은 `double` 로 변환된다.
        - `Enum` 은 `int` 로 변환된다.
    3. 단계
        - 위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.
        - 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 `float -> int)`
        - `Enum` 도 임의의 숫자 타입으로 변환된다 (예를 들어 `Enum -> double)`
        - `0` 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다
        - 포인터는 `void` 포인터로 변환된다.
    4. 단계
        - 유저 정의된 타입 변환으로 일치하는 것을 찾는다 (이 부분에 대해선 나중에 설명!) ([출처](http://www.learncpp.com/cpp-tutorial/76-function-overloading/))
        - 만약에 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나 같은 단계에서 두 개 이상이 일치하는 경우에 **모호하다 (ambiguous)** 라고 판단해서 오류를 발생하게 됩니다.
    - 모호한 오버로딩 코드
        
        ```cpp
        #include <iostream>
        
        void print(int x) { std::cout << "int : " << x << std::endl; }
        void print(char x) { std::cout << "double : " << x << std::endl; }
        
        int main() {
          int a = 1;
          char b = 'c';
          double c = 3.2f;
        
          print(a);
          print(b);
          print(c);//double형은 1,2 단계로 넘어가도 맞는 타입이 없기 때문에, 3단계로
        //넘어가게 되는데 임의의 숫자 타입이 임의의 숫자 타입' 으로 변환되서 생각되기
        //때문에 double 은 char 도, int 도 변환 될 수 있게 되는 것 그래서 오류가 발생
          return 0;
        }
        ```
        

## 생성자

```cpp
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();

  Date(int year, int month, int day) {//생성자 선언
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

// 생략

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() {
  Date day(2011, 3, 1);// 객체 선언과 동시에 선언함
  day.ShowDate();

  day.AddYear(10);
  day.ShowDate();

  return 0;
}
```

- 객체 생성시 자동으로 호출되는 함수
- 객체 생성하자마자 초기화 하는 역할

### 디폴트 생성자

- 클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않았을 경우에 컴파일러가 자동으로 추가해주는 생성자

```cpp
// 디폴트 생성자 정의해보기
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void ShowDate();

  Date() {//디폴트 생성자 정의
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }
};

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

int main() {
  Date day = Date();//day와 day2는 같다.
  Date day2;

  day.ShowDate();
  day2.ShowDate();

  return 0;
}
```

- 위코드는 디폴트 생성자를 정의하는 코드
- **주의점**
    
    ```cpp
    Date day3();
    ```
    
    - 위와 같이 사용하면 **리턴값이 `Date` 이고 인자가 없는 함수 `day3` 을 정의하게 된 것으로 인식. 이는 암시적 표현으로 객체를 선언할 때 반드시 주의해 두어야 할 사항**

### 명시적으로 디폴트 생성자 사용하기

- 디폴트 생성자를 사용하는지 알 방도가 없기때문에 알려주기 위해 사용

```cpp
#include <iostream>

using namespace std;

class Test {
private:
	int num;
public:
	Test() = default;//디폴트 생성자를 정의 하겠다는 것
	void number() {
		cout << num << endl;
	}
};
int main() {
	Test n;
	n.number();
	return 0;
}
```

### 생성자의 오버로딩

- 함수의 오버로딩과 같다

```cpp
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void ShowDate();

  Date() {
    std::cout << "기본 생성자 호출!" << std::endl;
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }

  Date(int year, int month, int day) {
    std::cout << "인자 3 개인 생성자 호출!" << std::endl;
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() {
  Date day = Date();
  Date day2(2012, 10, 31);

  day.ShowDate();
  day2.ShowDate();

  return 0;
}
```
