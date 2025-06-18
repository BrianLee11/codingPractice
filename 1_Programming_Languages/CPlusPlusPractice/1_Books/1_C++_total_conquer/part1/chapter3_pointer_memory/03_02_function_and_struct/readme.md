# 03-02 함수와 구조체
- 함수의 형태를 이해하고 사용자 정의 함수를 만들기
- 구조체의 장점을 이해하고 함수의 매개변수로 활용하기

반복해서 수행되는 코드를 함수로 만들면 재활용할 수 있으며, 복잡한 기능도 구조화되어 효율적으로 관리할 수 있습니다. 

하나 이상의 변수를 그룹화하는 `구조체`도 살펴보고, 함수와 함께 활용하는 법도 익혀 보겟습니다.

## 함수 만들기
- `함수`: `특정 작업을 수행하는 코드 집합`
  - 함수의 기본 구성
    - `int func(int _arg1, int _arg)`
      - int: `반환 형식`
      - func: `함수 이름`
      - int _arg1, int _arg2: `매개 면수`
      - { }: `함수 몸체`

- 함수 선언에는 크게 4가지의 필수 요소가 있습니다.
  1. **반환 형식**: 함수가 반환할 값의 자료형입니다. 
    - 반환할 값이 없을 때는 void로 표기합니다.
  2. **함수 이름**: 함수를 호출할 때 사용할 이름입니다.
    - 함수의 이름은 `문자나 밑줄(_)로 시작하며, 숫자나 공백으로 시작할 수는 없습니다`
  3. **매개 변수**: 함수가 호출될 때 전달받은 값을 저장하는 변수
    - 함수 내부에서만 사용할 수 있는 지역 변수입니다.
    - 전달받을 값이 없을 때는 비워 두거나, void로 매개변수가 없음을 표기할 수 있습니다.
  4. **함수 몸체**: 함수의 기능을 정의하는 부분입니다.

예제: 덧셈을 수행하는 함수 작성하고 호출하기
```cpp
#include <iostream>

int add(int _x, int_y)
{
    int result = _x + _y;
    return result;
}

int main()
{
    int add_result = add(2,3) // add 함수 호출
    std::cout << "Result of add: " << add_result << std::endl;
    
    return 0;
}
```
실행 결과
`add 함수 결과: 5`

## 함수의 매개변수 parameter 활용하기
예제 1: 목표는 주어진 변수(숫자)의 부호를 바꾸는 것입니다.
- 예: 함수(-3) = 3, 함수(3) = -3
```cpp
#include <iostream>

void change_sign(int val)
{
    val = - val;
}

int main()
{
    int a = 3;
    int b = 3;

    change_sign(a);
    std::cout << a << std::endl;  // output: 3, expected: -3
}
```
실행 결과: `3`

- 기대했던 결과는 a의 값 3이 -3으로 변경되는 것인데, 출력된 결과를 보면 `원래 값 3이 그대로 출력`되었습니다.
  - 그 이유는 매개변수인 val이 change_sign 함수 내부에서만 효력이 있는 지역 변수이기 때문입니다.
  
- main 에서 change_sign 함수를 호출할 때 넣었던 변수 a는 val 매개변수로 `복사`됩니다.
  - 따라서, change_sign 함수에서는 `val 변숫값만 음수로 만들뿐`, 
  - `main의 a,b 변수에는 아무런 영향이 없습니다`.


## 포인터를 매개변수로 사용하여, 특정 변수의 값을 변화시키기
```cpp
#include <iostream>

void change_sign_using_pointer(int *val)
{
  *val = - (*val);
}

int main()
{
  int a = 3;
  change_sign_using_pointer(&a); // feeds the address of int a
  
  std::cout << a << std::endl; // output: -3

}
```
실행 결과: `-3`

- main 내부에서 change_sign_using_pointer(&a)를 살펴보면, 인자로 넘기는 
변수 앞에 주소 연산자 &가 붙었습니다. 해당 변수의 주소를 불러옵니다.
  - 즉, a 변수에 저장된 3이라는 값 대신에 a 변수의 주소를 전달합니다.


- 이어서 change_sign_using_pointer 함수에서는 매개변수가 포인터 변수로 변경되었습니다.
  - 포인터 변수는 `메모리 주소를 저장하는 변수`입니다.
  - 즉, `함수가 호출될 때 주솟값을 전달했으므로 이를 받으려면 포인터 변수로 선언해야` 합니다.
  - 이제 change_sign_using_pointer 함수 내부에서는 포인터 변수 val 앞에 역참조 연산자 *를 사용해
  포인터 변수가 가리키는 데이터에 직접 접근할 수 있습니다. 
  - 따라서, 실행 결과를 보면 main의 a 변수에 저장된 값이 음수로 변경된 것을 확인할 수 있습니다.

## 배열을 매개변수로 사용하기
- 배열을 사용하면 자료형이 같은 변수 여러 개를 한 번에 전달할 수 있습니다.
```cpp
// page 123: 배열을 매개변수로 사용하기 시작
#include <iostream>

int average(int _array[], int _count)
{
    int sum = 0;
    for (int i = 0; i < _count; i++)
    {
        sum += _array[i];
    }

    return sum / _count;
}

int main()
{
    int score[5] = {90, 75, 80, 100, 65};
    std::cout << average(score, 5) << std::endl;

    return 0;
}
// page 123: 배열을 매개변수로 사용하기 끝 
```

실행 결과: `82`

## 구조체 만들기
- 여러 가지 형식의 데이터를 하나의 매개변수로 전달할 수 있습니다.

예를 들어, 사람의 정보를 나타내는 변수들을 선언해 봅시다.
```cpp
std::string name; // 이름
int age;          // 나이
float height;     // 키
float weight;     // 몸무게
```
- 이 데이터들을 묶어서 하나로 관리할 수 있다면 좋겠습니다.
  - 예를 들어, `사람`이라는 이름으로 데이터를 그룹 지어 사용할 수 있다면 어떨까요?
  - 구조체를 이용하면 이처럼 여러 형식의 데이터들을 묶어서 관리할 수 있습니다.
  - 다음은 `struct` 키워드를 이용해 `Person`이라는 이름으로 구조체를 선언한 예입니다.

```cpp
struct Person
{
  std::string name;  // 이름
  int age;           // 나이
  float height;      // 키
  float weight;      // 몸무게
}
```
- Person 구조체는 자료형과 마찬가지로 `형식만 정의된 형태`입니다.
- 해당 구조체 형식의 변수를 만들어야 비로서 사용할 수 있습니다.
- 구조체 형식의 변수를 만드는 방법은 일반적인 변수 선언과 같습니다.
  - `Person adult;`
  - 구조체 안의 개별적인 멤버에 접근하려면 멤버 선택 연산자 member selection operator 인 `.`을 이용해야 합니다.

```cpp
Person adult;
adult.name = "Brian";
adult.age = 24;
adult.height = 180;
adult.weight =70;
```

구조체 형식으로 배열을 선언할 수도 있습니다. `adult[index]`처럼 각각의 인덱스로
각각의 Person을 구분하고, 각 Person의 정보가 담긴 멤버 변수는 .으로 접근할 수 있습니다.
```cpp
Person adult[3];

adult[0].name = "Brian";
adult[0].age = 24;
adult[0].height = 180;
adult[0].weight = 70;

adult[1].name = "Jessica";
adult[1].age = 22;
adult[1].height = 165;
adult[1].weight = 55;

adult[2].name = "James";
adult[2].age = 30;
adult[2].height = 170;
adult[2].weight = 65;
```

## 구조체를 매개변수로 사용하기
예제: 앞에서 본 Person 구조체를 그대로 사용하되, 나이는 25세 이상인 사람의 정보만 화면에 출력하는 프로그램입니다. 

```cpp
// pg.117: 구조체를 매개변수로 사용하기 시작
#include <iostream>
struct Person
{
    std::string name;
    int age;
    float height;
    float weight;
};

void check_age(Person People[], int _count)
{
    for (int i = 0; i < _count; i++)
    {
        if (People[i].age >= 25)
        {
            std::cout << People[i].name << std::endl;
            std::cout << People[i].age << std::endl;
            std::cout << People[i].height << std::endl;
            std::cout << People[i].weight << std::endl <<std::endl;
        }
    }
}

int main()
{
    Person People[3] =
        {
            {"Brian", 28, 180, 70},
            {"Jessica", 25, 165, 55},
            {"James", 18, 170, 65}
        };

    check_age(People, 3);
    return 0;
}
// pg.117: 구조체를 매개변수로 사용하기 끝
```

실행 결과:
```cpp
Brian
28
180
70

Jessica
25
165
55
```
- 구조체를 사용하면 관련 값을 하나의 객체로 그룹화하므로 `코드를 더 읽기 쉽고 유지/관리하기 좋게 만들 수 있습니다.`
  - 함수에 전달할 인자가 많을 때 특히 유용합니다.
- 그런데, 구조체를 `함수에 전달하면 복사본이 전달`되므로 `구조체가 매우 크면 성는 문제가 발생할 수 있습니다`.
  - 이때는 `복사본 대신 구조체에 대한 포인터(주소)를 전달하면 해결할 수 있습니다`. 
  - 앞의 예시에서 첫 번째 매개변수를 구조체 포인터 변수로 선언해 봅시다.

```cpp
// pg.128: 구조체의 포인터를 전달하여 구현: 시작
#include <iostream>

struct Person
{
    std::string name;
    int age;
    float height;
    float weight;
};

void check_age(Person *_adult, int _count)
{
    for (int i = 0; i < _count; i++)
    {
        if (_adult[i].age >= 25)
        {
            std::cout << std::endl;
            std::cout << _adult[i].name << std::endl;
            std::cout << _adult[i].age << std::endl;
        }
    }
}

int main()
{
    Person adults[3] =
        {
            {"Brian", 27, 180, 74},
            {"Suzie", 24, 175, 55},
            {"Daisy", 34, 172, 65}
        };

    check_age(adults, 3);

    return 0;
}
// pg.128: 구조체의 포인터를 전달하여 구현: 끝
```
실행 결과
```cpp
Brian
27

Daisy
34
```

## 구조체 초기화하기
- 구조체 변수가 하나일 때는 다음처럼 간단하게 초기화할 수 있습니다.
  - `Person adult = {"Brian", 24, 180, 70}`
  - `구조체 배열`일 때는 중괄호 단위로 구분하여 반복해서 나열해 주면 됩니다.
    ```cpp
    Person adult[3] =
    {
      {"Brian", 24, 175, 65},
      {"Jessica", 22, 165, 55},
      {"James", 30, 170, 65}  
    }  
    ```
## 문법 요약: 구조체
- `struct` 키워드로 정의하며, 다른 데이터 형식 여러 개를 묶어 하나의 커스텀 데이터 형식을 만드는데 사용한다.
- 구조체는 `여러 개의 멤버 변수를 가질 수 있으며`, 각 멤버 변수는 `다른 데이터 형식`을 가질 수 있다.
- 구조체를 `함수의 매개변수로 전달하여 복잡한 데이터를 쉽게 관리`할 수 있다.
- `매개변수로 구조체를 전달할 때는 구조체의 복사본이 함수로 전달`된다.
- 구조체는 `메로리에 연속으로 할당`되며, 구조체의 `멤버 변수에는 점(.) 연산자로 접근`할 수 있다.

```cpp
// 구조체 정의
struct Person 
{
  std::string name; 
  int age;
}

// 함수의 매개변수로 복사되어 전달
void printPersonInfo(Person person)
{
  // 구조체의 멤버 접근
  std::cout << "Name: " << person.name << std::endl;
  std::cout << "Age: " << person.age << std::endl;
}

int main()
{
  Person john = {"John", 30}; // 구조체 변수 선언
  printPersonInfo(john);
  return 0;
}
```
## 3분 퀴즈
- 질문 1: 함수에 대해 정의해 보세요.
- 답변 1: 함수란 `특정 작업을 수행하는 코드의 집합 형태`


- 질문 2: 구조체에 대해 정의해 보세요.
- 답변 2: 구조체란 `하나 이상의 변수를 그룹 지어 새로운 자료형으로 정의한 것`


- 질문 3: `int 형식의 포인터 변수를 매개변수로 가지는 함수 정의를 코드로 작성해 보세요.`
`void func(        ) `
- 답변 3: `void func(int *_val);`










