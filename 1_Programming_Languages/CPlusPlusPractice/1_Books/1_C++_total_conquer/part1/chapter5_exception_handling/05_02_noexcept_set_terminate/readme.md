# 05- 02 예외 처리 생략과 실패 대응
- noexcept로 예외 처리 생략 명시하기
- set_terminate로 예외 처리 실패에 대응하기

## 들어가며
- 프로그래밍은 예측불허의 여정입니다.
- 코드가 실행되는 동안 예외 상황은 피할 수 없고, 심지어 예외 처리 메너니즘도 떄로는 예외를 처리하지 못할 수 있습니다.


## 예외 처리 생략 - noexcept
- 때로는 예외를 발생시키는 것이 득보다 실이 더 클 때도 있습니다.
- 오류와 예외는 엄연히 다릅니다.
- `값이나 실행 흐름을 충분히 예측할 수 있을 때는 if 문으로 처리하는 것이 성능 면에서 훨씬 이득`입니다.

## noexept 키워드: 함수가 예외를 던지지 않음을 명시
- 함수가 예외를 던지지 않음을 나타낼 때는 다음처럼 `noexcept` 키워드로 명시
  - `int func() noexcept \\ 함수가 예외를 던지지 않음을 명시`
  - 이처럼 함수가 예외를 던지지 않음을 명시하면 컴파일러가 코드를 최적화하고 빠르게 실행하는 데에 도움이 됩니다.

## 함수가 예외를 던지는지 bool 로 확인
- 다음처럼 함수를 호출할 때 noexcept 키워드를 사용할 수도 있습니다.
- `bool does_not_throw = noexcept(my_function())`
- 함수에 noexcept 키워드를 붙였다고 해서 예를 던지지 못하는 것은 아닙니다.
- noexcept가 명시된 함수에서 예외를 던지면 어떻게 되는지 실험해 보겠습니다.

```cpp
#include <iostream>
using namespace std;

// noexcept 선언으로 예외를 던지지 않음을 명시
void real_noexcept() noexcept
{
  cout << "real_noexcept" << endl;
}

// noexcept로 명시된 함수 안에서 예외 발생
void fake_noexcept() noexcept
{
  cout << "fake_noexcept" << endl;
  throw 1; // 정식 형식 예외 발생
}

int main()
{
  real_noexcept();
  
  try
  {
    fake_noexcept();
  }
  
  catch (int exec)
  {
   cout << "catch " << exec << endl;
  }
  return 0;
}
```

실행 결과
```cpp
real_noexcept
fake_noexcept
terminate called after throwing an instance of 'int'
```
- 이 코드를 컴파일하면 경고는 발생하지만 어쨌든 실행 파일은 만들어집니다.
- 컴파일러는 noexcept 키워드가 붙은 함수는 예외를 던지지 않을 것으로 간주하고 그대로 컴파일합니다.
- 하지만 실행해 보면 런타임 오류 메시지가 발생하며 프로그램은 강제로 종료됩니다.

## 예외 처리 실패 대응 - set_terminate
- `throw` 문으로 예외를 던졌는데 해당 예외를 받을 `catch`문이 아예 없거나, 있어도 형식이 맞지 않으면 프로그램은 강제로 종료됩니다.
- 이때 종료 처리 함수를 설정하는 `set_terminate`로 `프로그램을 강제 종료되기 전에 특정 동작을 수행하도록 구성`할 수 있습니다.
  - `set_terminate(종료_처리_함수);`

예제: 예외 처리 실패에 대응하기
```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

// 종료 처리 함수
void myterminate()
{
  cout << "myterminate called" << endl;
  exit(-1); // 프로그램을 비정상으로 종료
}

int main(void)
{
  // 종료 처리 함수 지정
  set_terminate(myterminate);
  
  // 예외 발생, 그러나 catch 없음. 강제로 종료되어야 함.  
  throw -1;
  // 미리 종료 처리 함수를 지정했기에, 지정된 그 함수에서 처리
  
  return 0; // throw로 예외를 던졌으므로 실행되지 않음  
}
```

실행 결과: `myTerminate is called.`

- main 함수에서 throw 1 코드를 만나면 catch 문을 찾을 수 없음 -> 오류 발생 -> 프로그램이 강제로 종료
- 강제로 종료하기 전에 set_terminate로 지정한 종료 처리 함수가 호출
- exit 함수는 <cstdlib> 헤더에 정의되어 있습니다.
  - exit 함수에 상태 코드로 0을 전달하면 프로그램을 정상으로
  - exit 함수에 상태 코드로 -1을 전달하면 비정상으로 종료합니다
  - 이 상태 코드에 따라 내부에 정의된 각종 정리 작업을 수행합니다
  - 비슷한 함수로 `abort`가 있는데, 이 함수는 어떤 정리 작업도 수행하지 않은 채 프로그램을 비정상으로 즉시 종료합니다.

## 3분 퀴즈
- 질문 1: 예외 처리란 무엇인가요?
- 답변 1: `프로그램 실행 흐름상 발생하는 오류에 대응하는 방법`

- 질문 2: 예외를 `던져` catch 블록에서 처리하도록 하는 키워드는 무엇인가요?
- 답변 2: `throw`

- 질문 3: 디버그 모드에서 오류가 생길 수 있는 부분을 검사할 수 있는 `매크로`는 무엇인가요?
- 답변 3: `assert`
- 









