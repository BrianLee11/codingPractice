# 02-06 chapter 되새김 문제 

## 문제 1: C++ 표준 입출력
- `std::cout`과 `std::cin`을 이용하여 이름을 입력받고, 이름이 포함된 환영 메시지를 출력하는 프로그램을 만들어 보세요.

답변 1:
```cpp
#include <iostream>
#include <string>

int main() {
    std::string name("NAME");  // 문자열 변수 초기화

    std::cout << "Enter your name: ";  // 사용자에게 입력 요청 메시지 출력
    std::cin >> name;                  // 사용자로부터 문자열 입력 받기
    std::cout << "Hi! You are " << name << "! Welcome!" << std::endl;  // 환영 메시지 출력

    return 0;
}
```

```cpp
Enter your name: Ronaldo
Hi! You are Ronaldo! Welcome!
```
## 🧪 문제 2: 데이터 형식
> 다음 리터럴 접미사에 어울리는 **변수를 선언하고 값을 출력**해 보세요:

- `0.5f` → `float`
- `5u`   → `unsigned int`
- `5L`   → `long`

---

### ✅ 답변 및 코드 예시

```cpp
#include <iostream>

int main() {
    // float 리터럴 (f)
    float float_variable = 0.5f;
    std::cout << "float_variable = " << float_variable << std::endl;

    // unsigned int 리터럴 (u)
    unsigned int unsigned_variable = 5u;
    std::cout << "unsigned_variable = " << unsigned_variable << std::endl;

    // long 리터럴 (L)
    long long_variable = 5L;
    std::cout << "long_variable = " << long_variable << std::endl;

    return 0;
}
```

실행 결과
```
float_variable = 0.5
unsigned_variable = 5
long_variable = 5
```


## 문제 3: 변수의 유효 범위와 형식 변환 (global variable, local variable)
다음 코드에서 컴파일 오류가 발생하는 부분이 있습니다. 위치와 원인을 설명해 보세요.

```cpp
int outer_variable = 10;
{
    int inner_variable = 5;
    std::cout << "Inner Variable: " << inner_variable << std::endl;
    std::cout << "Outer Variable: " << outer_variable << std::endl;
}
std:: cout << "Inner Variable: " << inner_variable << std::endl;
```

답변 3:
- 오류 발생 위치: 여기에서 컴파일 오류가 발생합니다. 
`std::cout << "Inner Variable: " << inner_variable << std::endl`

  - 오류 원인 설명: 
  `inner_variable`은 `블록 내부에서 선언된 지역 변수 (local variable)`입니다:
          
          >  {     int inner_variable = 5;  // 이 블록 내에서만 유효. local variable.     }
  
    - 따라서 블록 외부의 `std::cout << inner_variable` 문장은 **컴파일 오류**를 발생시킵니다.
  
## 해결 방법
```cpp
// global variable: 함수 외부 전체에서 접근 가능
int outer_variable = 10; 
int inner_variable = 5;   

{
    std::cout << "Inner Variable: " << inner_variable << std::endl;
    std::cout << "Outer Variable: " << outer_variable << std::endl;
}

std::cout << "Inner Variable: " << inner_variable << std::endl; // OK
```

## 문제 4: 키워드와 리터럴
질문: 다음처럼 이름이 있는 심벌릭(symbol) 상수는 `L-value`일까요? 답과 그 이유를 간단하게 설명해 보세요.
`const double PI = 3.14519;`

답변: 
- 결과: 네, L-value 입니다.
- 이유: `L-value`란 **메모리 주소(식별 가능한 위치)**를 가지는 값을 의미합니다.
  - `PI`는 **이름이 있는 상수 변수**이므로 메모리 상에 위치를 가지고 있고, **주소를 참조할 수 있습니다**.
  - 단, `const`로 선언되었기 때문에 **읽기 전용일 뿐,** `L-value`가 아닌 것은 아닙니다.
  - 즉, **수정은 불가능하지만 주소를 가리킬 수 있으므로** `L-value`입니다.

**L-value vs R-value 정리**

| 구분            | 설명                                         |
|-----------------|----------------------------------------------|
| `L-value`        | 이름이 있고, 메모리 주소를 가지는 값          |
| `R-value`        | 일시적인 값(리터럴 등), 메모리 주소가 없음   |
| `const L-value`  | 메모리 주소는 있지만, 값을 수정할 수 없는 L-value |

## 문제 5: 표현식과 연산자
다음 코드에서 문제가 발생할 수 있는 부분을 찾아 개선된 코드로 만들어 보세요.

```cpp
   int a = 10, b = 3;
   float result_1 = a / b;
```

답변 5: 

문제가 발생할 수 있는 부분: `float result_1 = a / b;`
문제점
- `a / b`는 두 **정수형(int)** 사이의 나눗셈이므로 결과는 **정수 나눗셈**이 됩니다.
- 따라서 `10/3`의 결과느 `3`이며, **소수점 이하가 버려집니다.**
- 그 후 `float`으로 저장되더라도 이미 손실된 정보는 복구되지 않습니다.
- 즉, **정수 나눗셈 결과(3)가 float으로 변환되어 3.0이 됩니다.**



개선된 코드 (C 스타일 형)
```cpp
float result_1 = (float) a / b;
```

명시적 형 변환 사용
```cpp
int a = 10, b = 3;
float result_1 = static_cast<float>(a) / b;
```
- `static_cast<float>(a)`로 형 변환을 먼저 하면, **float / int → float 나눗셈**이 됩니다.
- 따라서 정확한 실수 결과 `3.33333...`가 저장됩니다.

| 문법                          | 가능 여부 | 설명                |
| --------------------------- | ----- | ----------------- |
| `(float)a / b`              | ✅ 가능  | C 스타일 형 변환        |
| `static_cast<float>(a) / b` | ✅ 가능  | C++ 스타일 형 변환 (권장) |



 
