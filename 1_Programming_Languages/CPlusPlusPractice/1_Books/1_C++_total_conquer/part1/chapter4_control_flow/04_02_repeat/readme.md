# 04-02 반복문으로 흐름 제어
- 반복문 이해하기
- while, do~while, for 문으로 반복 제어하기.

## while 문으로 반복하기
- `while`문은 주어진 조건이 참인 동안에만 특정 코드 블록을 반복해서 실행합니다.

예시: while 반복문
```cpp
#include <iostream>
using namespace std:

int main()
{
    int count = 0;
    while (count < 0)
    {
        cout << "count: " << count << endl;
        count++;
    }
    
    return 0;
}
```

실행 결과
```cpp
count: 0
count: 1
count: 2
count: 3
count: 4
```

## do~while 문의 동작 방식
- `do~while`은 `while`문처럼 동작하지만, `while` 조건식이 구문의 처음이 아닌 마지막에 나옵니다.
- 따라서 `코드 블록을 먼저 실행한 다음`, 조건을 검사하므로 `최소한 한 번은 실행`되도록 보장할 수 있습니다.

```cpp
int main()
{
    int count = 0;
    do {
        cout << "count : " << count << endl;
        count++;    
    } while (count < 5);    
}
```
## for 문으로 반복하기
- for 문은 `반복 횟수를 정확히 제어해야 할 때 효과적으로 사용`할 수 있습니다.
- 또한 `초기화, 조건식, 증감식을 모두 한곳에서 관리`하여 코드를 더 간결하게 작성할 수 있습니다.

```cpp
for (1. 초기화; 2. 조건식; 3. 증감식)
{
    // 반복 실행 코드
}
```
1. **초기화**: 반복이 시작되기 전에 한 번만 실행되며 변수를 선언하고 초기화한다.
2. **조건식**: 반복이 실행되기 전에 매번 평가된다. 참이면 반복이 실행되고 그렇지 않으면 종료한다.
3. **증감식**: 반복한 후에 실행되며 조건식에 사용한 변수를 업데이트한다.

```cpp
for (int count = 0; count < 5; count++)
{
    cout << "count: " << count << endl;
}
```

실행 결과:
```python
count: 0
count: 1
count: 2
count: 3
count: 4
```

## for vs while
- for 문의 장점을 요약하면 다음과 같습니다:
    1. 간결한 구문
  2. 더 나은 반복 제어
  3. 배열 같은 데이터 구조에서 사용하기 쉬움
  4. 특정 횟수만큼 실행되는 반복을 더 쉽게 만들 수 있음
  5. 무한 반복 방지

- `for` 문은 반복 횟수를 미리 알 수 있고, 배열을 순회하거나 특정 범위의 값에 연속해서 접근할 때 유용합니다.
- `while` 문은 반복 횟수를 미리 알 수 없고 특정 조건이 충족되는 한 계속 반복해야 할 때 유용합니다.







