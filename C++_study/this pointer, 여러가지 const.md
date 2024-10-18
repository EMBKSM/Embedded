

- this pointer
    - 자신을 호출한 객체를 가리키는 포인터이다.
        
        ```cpp
        #include <iostream>
        
        using namespace std;
        
        class Pointer_practice {
        private:
        	int n;
        public:
        	void change_number(int n);
        	void print();
        };
        
        void Pointer_practice::change_number(int n) {
        	this->n = n;
        }
        
        void Pointer_practice::print() {
        	cout << n << "\n";
        }
        
        int main() {
        	Pointer_practice* ptr = new Pointer_practice;
        	ptr->change_number(10);
        	ptr->print();
        	delete(ptr);
        }
        ```
        
        - 위와 같이 포인터 객체를 사용할때 this를 사용하고 또한 함수의 파라미터와 필드에 있는 변수와 이름이 겹친 경우에도 사용한다.
- const + pointer 같은 경우는 사용하는 방법에 따라 달라진다
    - const T* value
        - value가 가리키는 위치에 있는 변수의 값을 바꿀 수 없음
        
        ```cpp
        #include <iostream>
        
        using namespace std;
        
        int main() {
        	const int* a;
        	int b = 10;
        	a = &b;
        	cout << *a << endl;
        	//*a = 10;
        	cout << *a << endl;
        }
        ```
        
    - T* const value
        - value에 저장된 주소 값을 바꿀 수 없음
        
        ```cpp
        #include <iostream>
        
        using namespace std;
        
        int main() {
        	int b = 10;
        	int c = 20;
        	int* const a = &c;
        
        	cout << *a << endl;
        	//a = &b;
        	*a = 30;
        	cout << *a << endl;
        }
        ```
        
    - const T* const value
        - pa가 가리키는 위치에 있는 변수의 값을 바꿀 수 없음과 동시에 저장된 주소 값 마저도 바꿀 수 없음
        
        ```cpp
        #include <iostream>
        
        using namespace std;
        
        int main() {
        	int b = 10;
        	int c = 20;
        	const int* const a = &c;
        
        	cout << *a << endl;
        	//a = &b;
        	//*a = 30;
        	cout << *a << endl;
        }
        ```
        
- const + pointer는 메모리 해제를 할 필요가 없다
- const and class
    - member 함수 뒤에 const를 붙이면 그 함수 내에서는 member 변수를 수정할 수 없다.
    
    ```cpp
    #include <iostream>
    
    using namespace std;
    
    class class_and_const {
    private:
    	int a;
    public:
    	class_and_const(int a) : a(a) {}
    	void change_private(int n) const {
    		//this->a = n;
    	}
    	void print() {
    		cout << this->a;
    	}
    };
    int main() {
    	class_and_const* ptr = new class_and_const(100);
    	ptr->print();
    	ptr->change_private(1010);
    	ptr->print();
    }
    ```
    
    - class 객체를 가리키는 pointer가 const 이면  const member function만 호출할 수 있다.
    
    ```cpp
    #include <iostream>
    
    using namespace std;
    
    class class_and_const {
    private:
    	int a;
    public:
    	class_and_const(int a) : a(a) {}
    	void change_private(int n) const {
    		//this->a = n;
    	}
    	void print() {
    		cout << this->a;
    	}
    };
    int main() {
    	const class_and_const* ptr = new class_and_const(100);
    	ptr->print();//실행 되지 않음
    	ptr->change_private(1010);//주석을 지우지 않으면 실행됨
    	ptr->print();//실행 되지 않음
    }
    ```
