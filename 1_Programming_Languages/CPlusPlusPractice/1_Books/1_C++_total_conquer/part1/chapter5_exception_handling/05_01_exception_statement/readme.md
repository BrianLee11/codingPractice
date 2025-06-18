# 05-01 예외 처리 구문
- try, catch, throw 문으로 예외 처리하기
- assert 로 예외 처리하기

## 들어가며
- 소스 코드에 예외 처리를 해두면 `예기치 못한 상황에서도 유연하게 대처`할 수 있습니다.
- 프로그램의 `안정성을 높이고 설사 오류가 발생하더라도 비정상으로 종료되지 않도록` 합니다.
- `코드를 읽기 쉽게 하고 유지/보수와 디버깅이 쉬어집니다.`
- 이는 큰 규모의 프로젝트를 진행할 때 함께 일하는 개발자들이 코드의 안정성과 이해도를 높이는 데 도움을 줍니다.

### C 언어에서 예외 처리 방법
- 일반적으로 조건문과 return 문을 이용해 예외를 처리
- 하지만 `로직을 제어하는 조건문`과 `예외를 처리하는 조건문이 섞여서 구분하기가 어렵습니다`
- `return` 문이 반환하는 값으로 `예외 상황을 구분하는 것도 꽤나 복잡`한 일입니다.

### C++ 언어에서 예외 처리 방법
- C++ 언어에서는 예외가 발생했음을 명시적으로 구분하고 예외를 더 간단하게 처리할 수 있도록 몇 가지 문법을 제공합니다.
- `try`, `catch`, `throw` 문입니다.

## try, throw, catch 문으로 예외 처리
- `try`: 예외가 발생할 수 있는 코드 블록을 중괄호 { } 로 감싸 준다.
- `throw`: 예외를 catch 블록으로 던진다.
- `catch`: throw로 던진 예외를 받아서 처리한다.


```cpp
// 1. 예외 발생 가능한 코드 블록
try{
    // 예외를 던질 수 있는 코드
    // 2. 예외 발생
    throw 예외_값
} catch (예외_형식 예외_이름) // 3. 예외 형식 확인
// 4. 예외 처리 블록
{
    // 예외를 처리하는 코드
}
```
- 예외 처리는 `try` 키워드로 시작합니다.
  - 예외가 발행할 수 있는 코드를 `try`와 함께 `중괄호`로 묶습니다.
- 그리고 조건문 등으로 예외인지 판단한 후, `throw` 명령으로 `예외를 던집니다`.
  - 예외를 던질 때는 `예외를 설명하는 값이나 객체를 함께 전달`합니다. 
  - 만약 `try` 블록 안에서 예외가 발생해 `throw` 문이 실행되면 `try` 문을 빠져나옵니다.
- 이어서 `throw`로 던진 예외는 `catch` 블록에서 처리됩니다.
  - 예외를 처리하는 `catch` 문은 `try`와 마찬가지로 `중괄호 {}`를 이용해 `블록을 지정할 수 있습니다`.
  - `catch` 문에서는 `예외 형식을 명시`할 수 있는데, 이는 `throw`가 던지는 예외 형식과 일치할 때만 예외를 처리하도록 합니다.

예제: 예외 처리
```
#include <iostream>
using namespace std;

int main() {

    try
    {
        int input;

        cout << "Enter an integer: ";
        cin >> input;

        // 첫 번째 throw
        if (input > 0) // 조건: 입력받은 숫자아 양수이면
        {
            cout << "throw 1 " << endl;
            throw 1; // 정수이므로 catch (int a) 에 해당됩니다. (정수 형식 예외)
        }

        // 두 번째 throw
        if (input < 0) // 조건: 입력받은 숫자가 음수이면
        {
            cout << "throw -1.0f" << endl;
            throw -1.0f; // 예외 1.0f 발생 (부동소수점 형식 예외)
        }

        // 세 번째 throw
        if (input == 0)  // 조건: 입력받은 숫자가 0이면
        {
            cout << "throw Z" << endl;
            throw 'Z';  // 예외 Z 발생 (문자 형식 예외)
        }


    } // end of try

        // catch 시작
        catch (int a) // 정수 형식 예외 받기
        {
            cout << "catch " << a << endl;
        }

        catch (float b) // 부동 소수점 형식 예외 받기
        {
            cout << "catch " << b << endl;
        }

        catch (char c) // 문자 형식 예외 받기
        {
            cout << "catch " << c << endl;
        }

    return 0;
}
```
실행 결과
```cpp
Enter an integer: 1
throw 1
catch 1

Enter an integer: -1
throw -1.0f
catch -1

Enter an integer: 0
throw Z
catch Z
```
- 정수 1을 입력받았을 때의 흐름을 따라가 보면서 예외 처리 구문의 동작 방식을 살펴보면
  - 1은 양수입니다. try 블록에서 첫 번째 `if`문이 실행됩니다.
    - 첫 번째 실행 결과를 보면 throw 1 이전 메세지만 나오고 이후 메세지는 나오지 않았습니다. 
  - 이것으로 throw 이후의 코드는 무시되고 try 구문을 빠져나온다는 것을 확인할 수 있습니다.
    - 즉 `try 블록에서 차례로 실행되다가 예외가 발생하면 이후 구문은 실행되지 않습니다`.
    - throw 1로 정수 형식의 예외가 발생했으므로 catch 문 가운데 정수 형식의 catch (int a) 문만 실행됩니다.
    - `나머지 catch 문은 throw로 던진 형식과 달라 실행되지 않습니다`.
  - 두세 번째 실행 결과도 확인해 보면 throw -1.0f처럼 부동 소수점 형식의 예외가 발생했을 때, 
  그리고 throw 'Z'처럼 문자 형식의 예외가 발생했을 때도
  각각 throw로 던진 것과 같은 데이터 형식의 catch 문이 실행되는 것을 확인할 수 있습니다.

```cpp
try {
  int intger;

  if (int > 0) throw 1; // 정수 형식 예외 발생... 1번으로 갑니다.
  if (int < 0) throw -1.0f; // 부동 소수점 형식 (float) 예외 발생... 2번으로 갑니다.
  if (int == 0) throw 'Z'; // 문자 형식 (char) 예외 발생 ... 3번으로 갑니다.
}

catch (int a) { ... }     // 1번. 실행하고 종료.
catch (float b) { ... }   // 2번. 실행하고 종료.
catch (char c) { ... }    // 3번. 실행하고 종료
```

## catch(...) 문으로 기타 예외 처리
- 질문: 만약 어떤 데이터 형식의 예외를 `throw`로 던졌는데 `받아 주는 catch 문이 없다면` 어떻게 될까요?
예제:
```cpp
#include <iostream>
using namespace std;

int main()
{
    int integer = 1;

    try {
        if (integer == 1)
        {
            throw 1;
        }

    }

    catch (char c)
    {
        cout << "catch";
    }

    return 0;
}
```
실행 결과
`terminate called after throwing an instance of 'int'`
- 정수 형식 예외를 `throw`로 던졌지만, 문자 형식 예외를 받는 catch만 있는 상태입니다.
- 즉, `어떤 예외를 던졌다면 이를 받을 수 있는 구문이 있어야`한다는 의미입니다.

- 하지만 `모든 예외의 짝을 맞춰 예외 처리 코드를 작성하는 것은 쉽지 않습니다`
- `if` 조건문의 `else`나 `switch`의 `default`처럼 일부 예외는 뭉뚱그려서 한 번에 처리하고 싶을 때가 있습니다.
- `catch(...)`문으로 이러한 요구에 대응할 수 있습니다.
  - 즉, `catch(...)`문은 명시하지 않은 나머지 모든 예외를 받아서 처리할 때 사용합니다.

```cpp
#include <iostream>
using namespace std;

int main()
{
  try 
  {
    int integer;  
    cout << "Enter an integer: ";
    cin >> integer;
    
    if (integer == 0)
    {
      throw 1; 
    }
    
    if (integer > 0)
    {
      throw -1.0f;
    }
    
    if (integer == 0)
    {
      throw 'Z';
    }
  }
  
  catch (int a)
  {
    cout << " a " << endl;
  }
  
  catch (...)
  {
    cout << "all other errors are here" << endl;  
  }
  
  return 0;
}
```
실행 결과
```cpp
Enter an integer: -2
all other errors are here
```

- 결과를 보면 정수 형식을 제외한 나머지 예외는 모두 `catch(..)` 문에서 처리되어 
`all other errors are here`이라는 메시지를 확인할 수 있습니다.

- 예외를 구별하지 하지 않고 하나로 받느 것은 적절한 예외 처리라고 볼 수 없습니다.
- 예외는 `종류마다 제대로 구분해서 처리`해 줘야 더 완벽한 프로그램을 만들 수 있습니다.

## 예외가 전달되는 순서
- C++ 에서 예외 처리는 주로 `try, throw, catch` 문으로 구현합니다.
- 이러한 구문들은 예외가 발생했을 때 프로그램의 제어 흐름을 변경하고 오류를 처리하는 데 사용합니다.
- `try` 블록에서 예외가 발생하면 먼저 같은 `영역scope`에 있는 `catch`운을 찾습니다.
  - 그런데 다음 코드처럼 예외를 던진 `func_throw` 함수에 catch 문이 없으면 어떻게 될까요?
```cpp
#include <iostream>
using namespace std;

void func_throw() {
    cout << "func_throw()" << endl;
    cout << "throw -1" << endl;
    throw -1;
    cout << "after throw -1" << endl;
}

int main() {

    try {
        func_throw();

    }
    catch (int integer) {
        cout << "catch " << integer << endl;
    }

    return 0;
}
```

실행 결과
```cpp
func_throw()
throw -1
catch -1
```

- 실행 결과를 보면 `func_throw` 함수에서 던진 예외가 이 함수를 `호출한 main 영역의 catch 문에서 정상으로 처리`된 것을 확인할 수 있습니다.
  - 즉, `예외 처리의 책임은 throw가 발생한 함수를 호출`한 쪽으로 넘어갑니다.
  - 이처럼 `함수에서 예외가 처리되지 않아서 함수를 호출한 쪽으로 전달되는 현상`을 가리켜 `스택풀기stack unwinding`이라고 합니다.

- `예외가 발생하면 해당 함수의 남은 코드들은 더 이상 수행되지 않고 종료`됩니다.
  - 따라서 `func_throw` 함수에서 `after throw -1`은 출력되지 않습니다.

예제: 스택 풀기
```cpp
#include <iostream>
using namespace std;

void func_throw(){
    cout << "func_throw() is called" << endl;
    throw -1;
    cout << "after func_throw()";
}


void func2() {
    cout << "func2() is called" << endl;
    func_throw();
    cout << "after func2()";
}

void func1() {
    cout << "func1() is called" << endl;
    func2();
    cout << "after func1()";
}

int main() {

    cout << "Inside the main()" << endl;

    try {
        func1();
    }
    catch (int exec) {
        cout << endl;
        cout << "catch " << exec << endl;
    }
}
```
```실행 결과
Inside the main()
func1() is called
func2() is called
func_throw() is called

catch -1
```

- 스택이 쌓이고 풀리는 과정을 확인하기 위해 연속으로 호출되는 함수를 여러 개 만들었습니다.
- 함수가 호출되는 순서는 다음과 같습니다
  - `main -> func1() -> func2() -> func_throw()`
- 함수가 호출되면 스택에 순서대로 쌓입니다. 따라서 맨 마지막에 호출되는 함수가 가장 위쪽에 위치합니다.
```
func_throw()
func2()
func1()
main
```
- 스택이 쌓이는 순서는 아래쪽부터 위로 쌓입니다 (마치 빈 접시처럼)
- 예외 전달 순서는 위에서 아래로 전달됩니다. 
- 예외를 전달하는 순서가 `스택에 쌓인 역순이므로 스택 풀기`라고 합니다. 

- `예외를 전달한 함수는 남은 코드를 실행하지 않고 바로 종료`됩니다.
  - 따라서 각 함수에서 마지막 코드인 `after..`를 출력하는 구문은 모두 수행되지 않습니다.

## 문법 요약: 예외 처리
- 예외가 발생할 수 있는 코드를 `try 블록`으로 감싼다.
- `예외가 발생`하면 프로그램의 제어는 즉시 `try 블록 다음에 오는 catch 블록`으로 넘어간다.
- `throw` 키워드로 예외를 던진다. `throw` 다음에 지정하는 예외 형식은 모든 유형이 될 수 있다.
- `catch` 블록에는 throw로 던진 예외 형식으로 매개변수를 선언한다.
  - 이 매개변수로 오류 메세지 같은 예외 정보에 접근한다.
- 단일 `try` 블록에 `catch` 블록이 `여러 개 있을 수` 있으며, `각 블록은 서로 다른 유형의 예외를 처리하도록 정의`한다.

```cpp
try{
  // 예외가 발생할 수 있는 코드 영역
  throw exception_value; // 예외를 강제로 발생시키는 코드
}

catch (exception_type e){
  // 예외가 발생했을 때 실행되는 코드 블록
  // e 에는 발생한 예외의 정보가 담겨 잇음
  // exception_type은 실제 예외 형식에 따라 정의
}
```

## assertion을 이용한 예외 처리
- `assertion`은 코드를 검증하여 **예상치 못한 상황에서 프로그램 동작을 중단**시키는 도구로, 안전성과 신뢰성을 높여 줍니다.
  - C++ 에서는 `<cassert>` 헤더에 정의된 **assert** 매크로를 통해 예외를 비교적 간단하게 처리할 수 있습니다.
  - `assert`는 디버그 모드에서 오류가 생길 수 있는 부분을 검사할 수 있는 매크로입니다.

예제: assert를 이용한 예외 처리
```cpp
#include <iostream>
#include <cassert>
using namespace std;

void print_number(int *_pt_int)
{
  assert(_pt_int != NULL); // 디버그 모드에서 _pt_int가 null 인지 검사
  cout << *_pt_int << endl;
}

int main()
{
  int a = 100;
  int *b = NULL;
  int *c = NULL;
  
  b = &a; 
  print_number(b);
  
  // c는 NULL인 상태로 인자 전달
  print_number(c);
  
  return 0;
}
```
- assert를 이용해 프로그램의 특정 지점에서 true로 예상되는 조건을 지정합니다.
  - 만약 지정한 조건이 true가 아니면 프로그램 실행이 중단됩니다.
  - assert는 주로 개발 과정에서 조건ㅇ르 검사하여 프로그램이 예상대로 동작하는지 확인하는데 사용합니다.
  - assert를 자주 활용하면 좋은 코딩 습관을 가질 수 있습니다.

## 디버그 모드와 릴리즈 모드
- `디버그 debug` 모드는 `컴파일할 때 디버깅을 위한 정보들을 삽입해서 문제가 발생할 때 원인을 수월하게 찾을 수 있도록` 하는 컴파일 모드입니다.
- 반면에 `릴리스 release` 모드는 `최종 사용자에게 배포할 코드를 만들 때 사용합`니다.
  - `릴리스 모드에서는 최적화가 적용되어 프로그램의 실행 속도가 향상`됩니다.
  - 디버깅 정보, 심벌, 주석 등이 제거되고 `실행 파일의 크기가 작아지면서 프로그램 실행에 소요되는 자원과 시간을 줄입니다`.
- `개발할 때는 주로 디버그 모드를 사용`하여 버그를 신속하게 찾아내고, `배포할 때는 릴리즈 모드로 컴파일`하여 최적화된 실행 속도와 작은 실행 파일을 만듭니다.

## assert를 사용할 때 주의할 점
- `assert`는 `디버그 모드에서만 컴파일`됩니다. 그러므로, `다른 코드에 영향을 주지 않는 코드로만 작성해야 합니다.`
  - 예를 들어 다음 코드는 잘못 사용한 예입니다.
    - `assert (count++ > 0)`; 
    - assert 검사는 릴리즈 모드에서 수행되지 않으므로 count 값이 디버그 모드와 릴리즈 모드에서 다릅니다.
    - 만약 프로그램의 로직을 좌우하는 중요한 코드를 assert 구문에 작성한다면, 릴리즈 모드에서는 해당 코드가 빠지므로 심각한 문제가 발생할 수 있습니다.
    - 이 점만 주의한다면 assertion으로 비교적 간단하게 예외를 처리할 수 있습니다.






