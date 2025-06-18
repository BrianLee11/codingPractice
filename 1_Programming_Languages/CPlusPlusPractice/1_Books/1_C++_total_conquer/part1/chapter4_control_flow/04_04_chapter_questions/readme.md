# 04-04: 되새김 문제
- 이번 장에서는 if, switch 문, 그리고 while, for 문을 사용해 봤습니다.
- 표현식과 구문의 차이도 알아보았습니다.

## 문제 1: if 문 활용하기
if 문을 활용하여 사용자로부터 입력받은 문자가 '양수'인지 '음수'인지 판별하는 프로그램을 만들어 보세요. 0은 양수로 취급합니다.

답변 1:
```cpp
#include <iostream>
using namespace std;

int main() {

    int user_integer_input = 0;

    cout << "Enter a number: ";
    cin >> user_integer_input;

    if (user_integer_input > 0 || user_integer_input == 0) {
        cout << "Positive integer input!" << endl;
    }
    else {
        cout << "Negative integer input!" << endl;
    }

}
```
       
## 문제 2: `switch`문 활용하기
switch 문을 활용하여 사용자에게 1~7까지의 숫자 중 하나를 입력받아, 
숫자에 해당되는 요일을 출력하는 프로그램을 만들어 보세요.

답변 2:
```cpp
#include <iostream>
using namespace std;

int main()
{
    int user_input_integer = 0;

    cout << "Insert a number from 1 to 7, inclusive: ";
    cin >> user_input_integer;

    switch (user_input_integer)
    {
        case 1:
            cout << "Sunday" << endl;
            break;

        case 2:
            cout << "Monday" << endl;
            break;

        case 3:
            cout << "Tuesday" << endl;
            break;

        case 4:
            cout << "Wednesday" << endl;
            break;

        case 5:
            cout << "Thursday" << endl;
            break;

        case 6:
            cout << "Friday" << endl;
            break;

        case 7:
            cout << "Saturday" << endl;
            break;

        default:
            cout << "Invalid input" << endl;
            break;
    }

    return 0;
}
```
실행 결과
```
Insert a number from 1 to 7, inclusive:3

Tuesday
```

## Q3: while 문으로 반복하기
while 반복문을 활용하여 1~10까지 숫자 중 짝수만 출력하는 프로그램을 만들어 보세요.
```cpp
#include <iostream>
using namespace std;

int main()
{
    int integer_target = 1;

    while (integer_target < 11)
    {
        if (integer_target % 2 == 0)
        {
            cout << integer_target << endl;
        }

        ++integer_target;
    }

    return 0;
}
```
실행 결과
```cpp
2
4
6
8
10
```

## Q4: for 문으로 반복하기
for 반복문을 활용하여 사용자에게 정수를 입력받고,
해당 정수가 포함된 구구단을 출력하는 프로그램을 만들어 보세요.
사용자는 1~9까지 정수만 입력하도록 제한합니다.

답변 4:
```cpp
#include <iostream>
using namespace std;

int main()
{
    int user_input_integer = 0;
    
    cout << "Insert an integer, from 1 to 9, inclusive: ";
    cin >> user_input_integer;
    
    for (int i = 1; i < 10; i++)
    {
        cout << user_input_integer << " * " << i << " = " << (user_input_integer * i) << endl;    
    }       
    
    return 0;       
}
```
실행 결과
```
Insert an integer, from 1 to 9, inclusive:3

3 * 1 = 3
3 * 2 = 6
3 * 3 = 9
3 * 4 = 12
3 * 5 = 15
3 * 6 = 18
3 * 7 = 21
3 * 8 = 24
3 * 9 = 27
```

## 문제 5: 표현식과 구문 개념 복습하기
다음 코드에는 표현식과 구문이 모두 포함되어 있습니다. 
어느 부분이 표현식이고 구문인지 표시해 보세요.
`int result = a + b;`

답변 5:
- 표현식: `a + b`
- 구문: `int result = a + b;`

| 구성 요소                | 예시                    | 설명                            |
| -------------------- | --------------------- | ----------------------------- |
| **표현식 (Expression)** | `a + b`               | 값을 계산하여 결과를 생성함 (`a + b = ?`) |
| **구문 (Statement)**   | `int result = a + b;` | 어떤 **동작을 수행하는 완전한 문장**        |

**표현식 (expression):**
- 하나의 값을 만들어내는 코드 조각
- 예: `a + b`, `x * y`, `func(3)`

**구문 (statement):**
- **실행 가능한 하나의 명령**이며, 세미콜론 `;`으로 끝남
= 예: `int x = 10;`, `return y;`












