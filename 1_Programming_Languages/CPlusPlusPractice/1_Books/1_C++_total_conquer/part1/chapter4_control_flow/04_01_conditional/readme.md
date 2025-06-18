# 04-01 조건문으로 흐름 제어
- if 조건문 이해하기
- if, else, else if, switch를 이용해 조건 분기 다루기

## if 문으로 분기하기
- C와 C++ 언어에서는 조건에 따라 분기할 때 `if`나 `switch`문을 사용합니다.

### if 문의 동작 방식
- `if` 조건문은 프로그램 내에서 특정 조건이 참일 때만 코드 블록을 실행하도록 하는 프로그래밍 구문입니다.
```cpp
if (조건식)  #
{
    // 실행문
}
```
1. if 조건식이 `참`일 때 실행문 동작
2. if 조건식이 `거짓`일 때 실행문 무시

### else 문을 포함하는 if문
- 조건이 참일 때뿐만 아니라 조건이 거짓일 때에 대응하는 동작을 구현합시다.
```cpp
if (조건식)
{
    // 실행문1
}
else
{
    // 실행문2
}
```
1. if 조건식이 `참`일 때 실행문1 동작, 실행문2 무시
2. if 조건식이 `거짓`일 때 실행문2 동작, 실행문1 무시

if 조건이 `참`일 때: 실행문 1 동작
if 조건이 `거짓`일 때: 실행문 2 동작
```cpp
int a = 5, b = 2;
if (a > b)
{
    // 실행문 1
}
else
{
    // 실행문 2
}
```

### else if 문
```cpp
if (조건식1)
{
    // 실행문1
}
else if (조건식2)
{
}
else
{
}
```

## if 문에 중괄호 생략
- 만약 if나 else if, else의 본문에 실행할 구문이 오직 하나만 있다면, 블록을 지정하는 중괄호 {}를 생략할 수 있습니다.
- 그러나, 이렇게 하면 코드의 줄 수는 줄겠지만, 분기별로 실행할 구문이 여러 개일 때 블록 지정을 빠뜨리는 실수를 할 수 있습니다.
  - 그러므로 될 수 있으면 블록을 확실하게 지정해 주는 것이 좋습니다.

```cpp
if (조건식)
{
    // 조건식이 참일 때
}

else if (조건식 2)
{
    // 조건식 1이 거짓이고, 조건식2가 참일 때
}
else (조건식 3)
{
    // 조건식1, 조건식2가 모두 거짓일 때
}
```

## switch 문으로 분기하기
- 조건에 따른 분기가 여럿일 때에도 `if else`문으로 처리할 수 있지만
- 갈래가 많아지면 코드를 읽기가 어려워집니다.
- 이때 `switch`문을 사용할 수 있습니다. `switch`문은 여러 경우의 수 가운데 하나를 선택해 실행할 때 사용합니다.

### switch 문의 동작 방식
- `switch` 문은 하나의 변수나 표현식을 평가한 결과에 따라 다양한 경우(`case`)중 하나를 선택해 해당 코드를 실행합니다.
- 이때 `switch` 문을 사용할 수 있습니다.
- `break` 키워드가 없다면, `switch`문이 한번 활성화되면 나머지 아래 내용들도 활성화됩니다.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int input_number;
    
    cout << "Insert an integer from 1 to 5, inclusive";
    cin >> input_number;
    
    switch (input_number)
    {
        case 1:
            cout << "The number is 1" << endl;
            break; // break 가 없으면 case에 속한 내용의 아래 구문들도 실행됩니다.
        
        case 2:
            cout << "The number is 2" << endl;
            break;
        
        case 3:
            cout << "The number is 3" << endl;
            break;
        
        case 4:
            cout << "The number is 4" << endl;
            break;
        
        case 5:
            cout << "The number is 5" << endl;
            break;
        
        default:
            cout << "outside 1 ~ 5" << endl;
            break;
    }
    return 0;
}
```

실행 결과
```cpp
Insert an integer from 1 to 5, inclusive: 1
The number is 1
```


```cpp
Insert an integer from 1 to 5, inclusive: 5
The number is 5
```

```cpp
Insert an integer from 1 to 5, inclusive: 7
outside 1 ~ 5
```

## case 문에서 break 문 생략
- 만약 case 문에 switch 문을 빠져나가게 하는 
`break 키워드를 쓰지 않으면, 일치하는 case 부터 default까지 모든 구문이 실행됩니다.` 

```cpp
#include <iostream>
using namespace std;

int main()
{
    int input_number;
    
    cout << "Insert an integer from 1 to 5, inclusive";
    cin >> input_number;
    
    switch (input_number)
    {
        case 1:
            cout << "The number is 1" << endl;
            // break 가 없으면 case에 속한 내용의 아래 구문들도 실행됩니다.
        
        case 2:
            cout << "The number is 2" << endl;
            
        case 3:
            cout << "The number is 3" << endl;
            
        
        case 4:
            cout << "The number is 4" << endl;

        case 5:
            cout << "The number is 5" << endl;

        default:
            cout << "outside 1 ~ 5" << endl;
            
    }
    return 0;
}
```
실행 결과
```cpp
Insert an integer from 1 to 5, inclusive: 2
The number is 2.
The number is 3.
The number is 4.
The number is 5.
outside 1~5
```

## ❓ if 문과 switch 문 중 어느 것이 더 빠를까요? (출처: chatGPT)

### ✅ 간단한 결론부터!

> **일반적으로 `switch` 문이 `if` 문보다 빠를 수 있습니다.**
> 하지만 **항상 그런 것은 아니며**, 성능 차이는 조건의 개수, 값의 분포, 컴파일러 최적화 여부에 따라 달라집니다.

---

### 🧪 왜 switch 문이 더 빠를 수 있나요?

- 컴파일러는 `switch` 문을 다음과 같이 **최적화**할 수 있습니다:
  - **Jump Table** 생성 (값이 연속적일 경우)
  - **Binary Search Tree** 방식 사용 (값이 불규칙할 경우)

```cpp
switch (value) {
  case 1: ...
  case 2: ...
  case 3: ...
}
```
❌ if 문은 왜 느릴 수 있나요?
- if, else if 연속 조건은 하나씩 순차적으로 평가됩니다:
```cpp
if (value == 1) { ... }
else if (value == 2) { ... }
else if (value == 3) { ... }
```
- 위와 같은 구조는 조건이 많을수록 **평가 횟수 증가 → 느려질 수 있음**

| 항목         | `if` 문                   | `switch` 문                      |
| ---------- | ------------------------ | ------------------------------- |
| 지원되는 조건식   | 다양한 논리식, 범위 조건, 복합 조건 가능 | 단일 값 비교 (`int`, `char`, enum 등) |
| 평가 방식      | 순차적 비교                   | jump table, 이진 탐색 등 최적화 가능      |
| 조건 수가 많을 때 | 성능 저하 가능                 | 상대적으로 빠름                        |
| 유연성        | 매우 높음                    | 제한적 (상수 값 비교만 가능)               |

- 조건이 많고 **값이 분기 상수**일 경우 → `switch`가 더 빠를 가능성이 높음
- 조건이 **복잡하거나 범위/논리식 포함** → `if`만 가능
- **실제 성능 차이는 크지 않을 수도 있으며, 가독성과 명확성**이 더 중요할 수 있습니다

## switch - case 문법
```cpp
switch (표현식)
{
  case 상수1:
    // 상수1과 표현식이 일치할 때 실행할 코드
    break;
  case 상수2:
    // 상수2와 표현식이 일치할 때 실행할 코드
    break;
   default:
    // 어떤 case에도 해당하지 않을 때 실행할 코드   
}
```






