# 02-03 변수의 유효 범위와 형식 변환
- 변수의 유효 범위를 이해하고 적절한 위치에 선언하기
- 변수에 저장된 값을 다른 데이터 형식으로 변환하여 사용하기
- `global`변수, `local`변수

## 변수의 유효 범위
- 변수를 선언했다고 해서 프로그램 어느 곳에서나 사용할 수 있는 것은 아닙니다.
- `변수가 선언된 위치에 따라 사용할 수 있는 범위가 결정`됩니다.

### 지역 범위 `local scope`
- 예를 들어 함수에서 `value`라는 변수를 선언하면 `value`는 해당 함수에서만 사용할 수 있습니다.
- 이것을 지역 범위 `local scope`라고 말합니다.
- 같은 지역 범위에서 이름이 같은 변수가 없는 '단일 정의 규칙'만 잘 지킨다면,
다른 범위에서는 같은 이름으로 변수를 선언해도 오류가 발생하지 않습니다.
- 다음 코드에서 `main`과 `print`함수에는 이름이 같은 변수 `value`가 있지만,
서로 영향을 주고받지 않습니다. 각각의 함수에 정의된 `value`에만 접근할 수 있습니다.

**지역 범위가 적용된 변수**
## 📘 예제: 지역 변수의 범위 (Local Scope)

이 예제는 `main()`과 `print()` 함수 각각에 **동일한 이름의 지역 변수 `value`**가 존재할 때,  
서로 영향을 주지 않는다는 것을 보여줍니다.

---

### 🔤 C++ 코드 (pg.60 예제)

```cpp
#include <iostream>
using namespace std;

// print 함수 정의
void print() {
    // 함수 내부의 지역 변수
    int value = 10;
    cout << "print 함수 내부에서의 지역 변수 value: " << value << endl;
}

int main() {
    // main 함수 내부의 지역 변수
    int value = 5;
    cout << "main 함수 내부에서의 지역 변수 value: " << value << endl;

    // print 함수 호출
    print();

    // print() 호출 후에도 main의 value는 그대로 유지됨
    cout << "다시 main 함수 내부에서의 지역 변수 value: " << value << endl;

    return 0;
}
```

실행 결과
```cpp
main 함수 내부에서의 지역 변수 value: 5
print 함수 내부에서의 지역 변수 value: 10
다시 main 함수 내부에서의 지역 변수 value: 5
```

### 변수 범위
C++ 언어에는 더 많은 종류의 범위가 있습니다. 대표적인 범위를 정리하면 다음과 같습니다.
- `구문 범위`: if, for, while 등의 안에서만 유효합니다.
- `지역 범위`: 매개변수 이름을 포함하여 함수 안에 선언한 이름은 해당 함수 내에서만 유효합니다.
지역 범위는 `블록 범위(block scope)`라고도 합니다.
- `전역 범위`: 네임스페이스나 클래스, 함수 등에 속하지 않고 외부에 선언한 이름입니다.
선언 지점부터 파일 끝까지 유효합니다.
- `클래스 범위`: 클래스 멤버의 이름은 선언 지점에 관계없이 클래스 정의 전체에 걸쳐 확장됩니다.
클래스 멤버에 대한 접근성은 `접근 지정자(public, private 등)`로 제어할 수 있습니다.
- `네임스페이스 범위`: 네임스페이스 안에 선언한 이름은 네임스페이스 안에서만 유효합니다.
네임스페이스는 서로 다른 파일들의 여러 블록에서 선언될 수 있습니다.

### 예제: 전역 범위와 지역 범위에 선언한 변수의 이름이 같을 때
전역 변수, 지역 변수 구분하여 접근하기
```cpp
#include <iostream>
using namespace std;

// 전역 변수 선언
int value = 1;

int main()
{
    // 지역 변수 선언
    int value = -1;
    
    // 지역 변수 출력 (기본값)
    // 이유: 지역 범위 내에 전역 변수와 이름이 같은 변수가 있다면
    // 지역 변수의 우선권이 더 높습니다.
    cout << value << endl; // output: -1. 지역 변수 출력
    cout << ::value << endl; // ouptut: 1. 전역 변수 출력
}
```

### local variable, global variable
- 지역 범위 내에 전역 변수와 `이름이 같은 변수가 없다면`: 컴파일러는 전역 변수에 접근합니다.
- 그러나, 지역 범위 내에 전역 변수와 `이름이 같은 변수가 있다면`: `지역 변수의 우선권이 더 높습니다.`
  - 이때 전역 범위 연산자 `::`를 사용하면 전역 변수에 접근할 수 있습니다.

- `하지만 전역 변수와 이름이 같은 지역 변수를 정의하는 것은 피해야 합니다.`
  - 의도치 않은 실수가 발행할 수 있기 때문입니다.
  - 전역 변수에는 `g_`와 같은 접두사를 붙여 `g_value`처럼 정의한다면
  이름만으로도 지역 변수와 구분할 수 있어 실수를 방지할 수 있습니다.

## L-value와 R-value 비교
 - `L-value`:  `왼쪽 값 left value`을 의미
 - `R-value`: `오른쪽 값 right value`을 의미
    - 대입 연산자(=) 기준으로 왼쪽 항을 L-value라 하고, 오른쪽 항을 R-value 라고 구분하던 것이서 유례합니다.
    - 대표적인 예로 L-value는 변수, R-value는 상수가 있습니다.

- 하지만 C++ 언어에서는 L-value와 R-value를 단순히 대입 연산자 기준으로만 구분하지 않습니다. 
  - `L-value`: 주로 대입 연산자의 왼쪽에 나타나는 값입니다. 메모리 위치를 가리키거나 수정할 수 있는 표현 식. 예) 변수 이름, 배열 요소, 클래스 멤버
  - `R-value`: 주로 대입 연산자의 오른쪽에 나타나는 값입니다. 임시 값이나 메모리상에 위치가 없는 값을 가리키는 표현식. 예) 임시 객체, 리터럴

```cpp
a = 1; // 성공. a는 L-value, 1은 R-value
1 = a; // 오류. 1은 L-value가 될 수 없음

a = b + 1; // 성공. a는 L-value, b + 1은 R-value
b + 1 = a; // 오류. b + 1는 L-value가 될 수 없음

a = b      // 성공. a와 b 모두 L-value
```

### 📘 L-value vs R-value 비교

| 구분               | **L-value**                                           | **R-value**                                               |
|--------------------|--------------------------------------------------------|------------------------------------------------------------|
| 위치               | 주로 대입 연산자의 **좌변**에 나타난다                | 주로 대입 연산자의 **우변**에 나타난다                    |
| 메모리 주소        | **메모리 위치를 가리킨다**                             | **메모리 위치를 직접 가리키지 않는다**                    |
| 이름 유무          | **이름이 있는** 식별자이다                            | **대개 이름이 없는** 임시 값이다                           |
| 수명               | **식 외부에서도 유효**하다                             | **해당 식 내부에서만 일시적으로 유효**하다                 |

### 형식 변환 (type casting)
1. `암시적 형 변환(impicit cast)`: 컴파일러가 자동으로 변경
2. `명시적 형 변환(explicit cast)`: 개발자가 의도적으로 직접 변경

암시적 형 변환의 예.
```cpp
#include <iostream>
using namespace std;

int main()
{
    float float_value = 1.5f; // 원본 데이터는 부동 소수점 형 1.5
    
    double double_value = float_value; // 숫자 승격: 데이터 유실 없음. 여전히 1.5
    int int_value = float_value;       // 숫자 변환: 데이터 유실 발생
    
    cout << "float_value: " << float_value << endl;
    cout << "double_value: " << double_value << endl;
    cout << "int_value: " << int_value << endl;
    
    return 0;
}
```

실행 결과
```cpp
float_value: 1.5
double_value: 1.5
int_value: 1
```

### `숫자승격(데이터 유지)`
- 다음 코드에서는 `float`형과 같은 계열이면서
- 더 큰 부동 소수점 자료형인 `double`로 변환됩니다.
- 이를 `숫자 승격 numeric promotion`이라고 하며, 이때 데이터는 그대로 유지됩니다.
- `double double_value = float_value;`
- 
### '숫자 변환 numeric conversion': 데이터 유실 가능
- 다음 코드처럼 부동 소수점에서 정수로 서로 다른 자료형으로 변환하거나, 
- 또는 크기가 더 작은 자료형으로 변환하면 `숫자 변환 numeric conversion`이 발생됩니다.
- 이때는 데이터가 유실될 가능성이 있습니다.
- `int int_value = float_value;`
- 관련 경고 메세지: `warning C4244: '초기화 중': 'float'에서 'int'로 변환하면서 데이터가 유실될 수 있습니다.`

### 명시적 형 변환
예시:
```cpp
#incldue <iostream>
using namespace std;

int main()
{
    int int_a = 10;
    itn int_b = 5;
    
    int int_avg = (int_a + int_b) / 2;  // 15/2 = 7 (정수 부분만 처리)
    float float_avg_1 = (int_a + int_b) / 2; 15 / 2 = 7 -> 7을 float 처리: 7.0
    float float_avg_2 = float(int_a + int_b) / 2; // float(10+5) = 15.0 -> float(15.0 /2  = 7.5) = 7.5
    
    cout << "int_avg: " << int_avg << endl;
    cout << "float_avg_1: " << float_avg << endl;
    cout << "float_avg_2: " << float_avg_2 << endl;   
}
```
실행결과
```cpp
int_avg: 7
float_avg_1: 7 // 데이터가 유실됨
float_avg_2: 7.5
```
```cpp
int(5 + 10) = 15
float(5+10) = 15.0

int(15/2) = 7
float(15.0/2) = 7.5
```
- 컴파일러는 `int_a + int_b` 부분을 정수형 R-value로 처리함으로서, 정수형 R-value/2 의 결과도 정수가 되었습니다.
  - 이미 정수끼리 나누기 연산에서 소수점 데이터가 사라져 의도하지 않은 결과가 나온 것이죠.


- `명시적 형 변환`: 개발자가 의도적으로 원하는 시점에 형식을 변환
  - `float float_avg_2 = float(int_a + int_b) /2;`
  - `int_a + int_b` 부분을 `float`형 R-value로 변환할 것을 명시적으로 표기
  - 이후의 연산은 모두 `float`형으로 처리됩니다.
  - 데이터가 유실되지 않고 온전한 결괏값을 얻을 수 있습니다.

- C++ 언어에서는 `float()` 형태뿐만 아니라 `float()`처럼 C 언어 방식의 명시적 형 변환도 지원합니다.
  - `float float_avg_2 = (float) (int_a + int_b) /2;`

### 🎯 C++ 명시적 형 변환 방법 (`cast` 연산자)

| 변환 방식                         | 설명 |
|----------------------------------|------|
| `static_cast<변환_형식>(값)`      | 논리적으로 허용되는 대부분의 형 변환에 사용. <br>상속 관계에 있는 포인터/레퍼런스 간 변환도 가능 |
| `const_cast<변환_형식>(값)`       | `const`, `volatile` 속성을 제거하거나 추가할 때 사용. <br>포인터 또는 레퍼런스 형식에서만 사용 가능 |
| `reinterpret_cast<변환_형식>(값)` | 메모리 수준에서의 비트 단위 해석 변경. <br>서로 관련 없는 포인터 간 변환에 사용. <br>`const`가 있는 경우에는 사용 불가 |
| `dynamic_cast<변환_형식>(값)`     | 클래스 간 포인터 또는 레퍼런스 형 변환에 사용. <br>안전한 `다운캐스팅(down-casting)`을 위해 사용되며, RTTI(Runtime Type Info)를 필요로 함 |

### C++ 명시적 형 변환법 추가 설명 (chatGPT
| 캐스트 종류             | 용도                 | 위험도   | 특징                    |
| ------------------ | ------------------ | ----- | --------------------- |
| `static_cast`      | 기본 타입 간 변환, 논리적 변환 | 낮음    | 컴파일 타임에 확인 가능         |
| `const_cast`       | const/volatile 제거  | 중간    | 수정 불가한 메모리 수정 시 위험    |
| `reinterpret_cast` | 포인터/비트 해석 강제 변환    | 매우 높음 | 하드웨어 수준 접근 용도         |
| `dynamic_cast`     | 클래스 간 안전한 다운캐스팅    | 낮음    | RTTI 기반, `virtual` 필수 |

## 🔄 C++ 명시적 형 변환 (`cast`) 실전 예제

C++에서 자주 사용되는 네 가지 `cast` 연산자를 실전 예제로 설명합니다.

---

### ✅ 1. `static_cast` 예제  
**논리적이고 안전한 타입 간 변환**에 사용됩니다.

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 10;
    double d = static_cast<double>(i);  // int → double

    cout << "static_cast result: " << d << endl;

    return 0;
}
```

### ✅ 2. const_cast 예제
**const 또는 volatile 속성 제거** 시 사용됩니다.
```cpp
#include <iostream>
using namespace std;

void print(char* str) {
    cout << str << endl;
}

int main() {
    const char* msg = "Hello, const_cast!";
    // print(msg);  // 컴파일 에러

    print(const_cast<char*>(msg));  // const 제거 후 호출

    return 0;
}
```
- ⚠️ 주의: const를 제거해도 정말 수정하면 안 되는 값을 수정하면 미정의 동작이 발생합니다.

### ✅ 3. reinterpret_cast 예제
**비트 수준에서 강제로 다른 타입으로 해석**합니다.
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 1234;
    char* p = reinterpret_cast<char*>(&a);  // int* → char*

    cout << "reinterpret_cast result: ";
    for (int i = 0; i < sizeof(int); ++i)
        cout << static_cast<int>(p[i]) << ' ';
    cout << endl;

    return 0;
}
```
- ⚠️ 아주 조심해야 하며, 보통 **저수준 메모리 작업**에 사용됩니다.

### ✅ 4. dynamic_cast 예제
**상속 관계에서 안전한 다운캐스팅**을 지원합니다.
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void greet() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    void greet() override { cout << "Derived\n"; }
};

int main() {
    Base* b = new Derived();  // 업캐스팅 (자동)
    Derived* d = dynamic_cast<Derived*>(b);  // 다운캐스팅 (명시적)

    if (d) {
        d->greet();  // 출력: Derived
    }

    delete b;
    return 0;
}
```
- dynamic_cast는 반드시 기준 클래스에 virtual 함수가 있어야 하며, 그렇지 않으면 컴파일 오류 발생합니다.

### 명시적 형 변환이 필요한 이유는 무엇인가요?
- 명시적 형 변환은 데이터 손실을 방지할 때, 
- 변수의 범위를 초과하는 값을 적절한 범위로 조절할 때, 
- 서로 다른 데이터 유형끼리 계산할 때 등 
- 데이터 유형 간의 호환성이나 연산의 정확성을 유지할 목적으로 사용해요.
- 그러나 형 변환을 남용하면 코드를 해석하기 어렵게 되므로 신중하게 사용해야 합니다.

### 문법 요약: 형식 변환 
- **암시적 변환**(implicit conversion)
  - 컴파일러가 필요에 따라 자동으로 수행한다.
  - 주로 `작은 크기의 자료형에서 큰 크기의 형식으로 변환`한다.

- **명시적 변환**(explicit conversion)
  - 개발자가 직접 형식 변환을 명시한다.
  - 데이터 손실이 발행할 수 있다.
  - C 스타일 형 변환과 C++ 의 static_cast, dynamic_cast, const_cast, reinterpret_cast 등을 활용할 수 있다.

```cpp
int int_value = 10;
double double_value = int_value;    // int를 double로 암시적 변환

double double_value = 3.14;
int int_value = int(double_value); // double을 int로 명시적 변환
```



