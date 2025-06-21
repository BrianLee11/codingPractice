# 07-03: 생성자 constructor 와 소멸자 deconstructor
- 생성자와 소멸자의 개념을 이해하고 클래스에서 활용하기
- 다양한 상황에서 사용할 수 있는 생성자, 소멸자를 학습하고 활용하기

# 생성자 constructor
- 객체가 생성될 때마다 객체 내부나 외부에 초기화해야 할 속성들이 있습니다.
- `생성자 constructor`: **객체가 생성된 직후에 자동으로 호출되는 함수**입니다. 
  - 이러한 특징을 이용해 생성자에서 속성을 초기화하는 등 객체를 사용할 준비를 합니다.
  - 생성자 함수는 클래스와 같은 이름으로 선언합니다.
  - `클래스_이름()`

예제:
```cpp
class character {
    public: 
        character() {
            cout << "character class constructor" << endl;        
        };
}; 
```

## 상속 클래스의 생성자 호출 순서
- 상속 받은 순서대로 해당 class의 생성자가 호출됩니다.

예: monster_a 클래스가 monster와 character 클래스를 다중 상속 받을 경우.
`class monster_a : public monster, character {}`

monster -> character -> monster_a 순으로 생성자가 호출됩니다.

```cpp
#include <iostream>
using namespace std;

class Monster{
public:
    Monster() {
        cout << "Monster constructor" << endl;
    };
};

class Character{
public:
    Character() {
        cout << "Character constructor" << endl;
    };
};

class Monster_a : public Monster, Character{
public:
    Monster_a() {
        cout << "Monster_a constructor" << endl;
    };
};

int main(){

    Monster_a forest_monster;

    return 0;
}
```
실행 결과
```cpp
Monster constructor
Character constructor
Monster_a constructor
```

## 값을 전달받는 생성자
- 객체를 생성할 때 특정 값을 전달할 수 있습니다.
- 이때는 생성자에 매개변수를 추가하면 됩니다. 
그러면 객체를 생성할 때 전달한 인자의 종류에 따라 알맞은 생성자가 자동으로 호출됩니다.
- 만약 기본 생성자는 생략하고 매개변수가 있는 생성자만 작성했을 때는 객체를 생성할 때 반드시 인자를 전달해야 합니다.


```cpp
#include <iostream>
using namespace std;

class Monster{
public:
    Monster(){
        cout << "Monster constructor" << endl;
    };
};

class Monster_a : public Monster{
private:
    int location[2];

public:
    // 기본 생성자
    Monster_a() {
        cout << "monster_a class basic constructor" << endl;
    };

    // C++ 에서는 생성자가 여러 개 있을 수 있습니다.
    // 값을 전달받는 생성자
    Monster_a(int x, int y) : location{x,y} {
        cout << "Monster_a constructor" << endl;
    };

    void show_location() {
        cout << location[0] << ", " << location[1] << endl;
    }
};

int main() {
    Monster_a forest_monster(10, 5); // ➤ 매개변수 있는 생성자 호출
    forest_monster.show_location(); // 10,5

    cout << endl;

    Monster_a wood_moster;        // ➤ 기본 생성자 호출
    wood_moster.show_location(); // 이상한 메모리상 위치 출력: -1431302144, 32759
}
```

실행 결과
```cpp
Monster constructor
Monster_a constructor
10, 5

Monster constructor
monster_a class basic constructor
-1431302144, 32759
```
- 실행 결과를 보면 값을 전달하지 않고 생성한 `wood_monster` 객체는 매개변수가 없는 기본 생성자가 출력됩니다.
  - 이때는 `location 배열이 초기화되지 않아 쓰레기 값 garbage value이 출력`됩니다.
- 그런데 값을 전달하면서 생성한 `forest_monster` 객체는 매개변수가 있는 생성자가 호출됩니다.
  - 이때는 location 배열이 객체를 생성할 때 전달한 값 (예에서는 10과 25)으로 초기화되어 위치가 정상으로 출력됩니다.

- 요약하면 값을 전달하는 생성자를 사용하면 기본 생성자는 실행되지 않습니다.
  - 다른 매개변수를 가지는 생성자를 여럿 만들 수 있지만, 객체를 생성할 때 입력된 인자에 맞는 생성자만 호출됩니다. 

### 생성자에서 다른 생성자 호출
- 생성자에서 다른 생성자를 호출할 수 있습니다.
  - 예를 들어 앞의 코드에서 기본 생성자를 호출하면 위치를 10, 10으로 설정한다고 가정해 볼게요.
  - 기본 생성자에서 매개변수가 있는 생성자를 호출해 보겠습니다.

```cpp
#include <iostream>
using namespace std;

// ... (생략) ...
class Monster_a : public Monster, character{
  private:
    int location[2]; // 위치 정보 저장 (x,y)
    
  public:
    // 기본 생성자
    Monster_a() {
      cout << "Monster_a class constructor" << endl;
      Monster_a(10,10);  // ❌ "다른 생성자"를 호출하는 것처럼 보이지만 실제로는 '임시 객체'를 만드는 것!
    };
    
    // 다른 생성자
    Monster_a(int x, int y ) : location{x, y} {
      cout << "Monster_a class constructor (parameter location{x,y}) added" << endl;
    };  
    
    void show_location() {
      cout << location[0] << " , " << location[1] << endl;
    };
};   // class Monster_a 끝


int main(){
  Monster_a forest_monster;
  forest_monster.show_location();
  return 0; 
}
```
- 이 코드는 생성자 오버로딩처럼 보이지만,
- 실제로는 Monster_a(10, 10);는 새 임시 객체를 만들고 버리는 코드입니다.
  - 즉, this 객체의 location에는 아무런 영향을 주지 않습니다.

- 이러한 현상은 `객체를 생성해서 지역 변수에 저장하지 않았기 때문에 발생`합니다.
  - 기본 생성자가 호출되는 객체 생성 코드를 보면 `monster_a forest_monster`처럼 작성했습니다.
  - 이 코드는 monster_a 클래스의 객체를 생성해 forest_monster라는 지역 변수에 대입합니다.

- 그런데 생성자에서 다른 생성자를 호출하는 코드를 보면 monster_a(10,10)처럼 생성한 객체를 대입할 지역 변수 이름이 빠졌습니다.
  - 즉, 이름이 없는 객체가 됩니다.
  - 생성자에서 다른 생성자를 호출하는 것의 의도였지만,
  - 실제로는 기본 생성자 내부에서 이름이 없는 객체가 생성되었다가 소멸합니다.

- 그렇다면 생성자에서 다른 생성자를 어떻게 호출할까요?
  - C++11 부터는 초기화 목록에서 다른 생성자를 호출할 수 있게 변경되었습니다.

```cpp
class Monster_a : public Monster, Character {
  private:
    int location[2];
  public:
    // 이 부분에 집중하세요
    Monster_a() : Monster_a(10,10) {
      cout << "Monster_a class constructor" << endl;
    };
    
    Monster_a(int x, int y): location{x, y} {
      cout <<"Monster_a class constructor" << endl;
    }
};
```

```markdown
# C++의 `:` 초기화 리스트 용법 정리 by chatGPT

C++에서 생성자의 `:` 뒤에 나오는 구문은 **"멤버 초기화 리스트 (member initializer list)"**입니다.  
용도에 따라 다음과 같이 다양하게 사용됩니다.

---

## ✅ 1. 멤버 변수 초기화 (가장 일반적인 용법)

```cpp
Monster_a(int x, int y) : location{x, y} {
    // 생성자 본문
}
```

- `location` 배열을 `{x, y}`로 초기화합니다.
- 생성자 본문 실행 전에 수행됩니다.
- 특히 `const`, `reference`, `array` 멤버는 반드시 초기화 리스트에서 초기화해야 함.

---

## ✅ 2. 기초 클래스 생성자 호출 (상속)

```cpp
class Monster_a : public Monster {
public:
    Monster_a() : Monster() {
        // 부모 클래스 Monster의 생성자 호출
    }
};
```

- 부모 클래스의 생성자를 명시적으로 호출합니다.
- 명시하지 않으면 기본 생성자가 자동 호출됩니다.

---

## ✅ 3. 생성자 위임 (delegating constructor, C++11 이상)

```cpp
Monster_a() : Monster_a(10, 10) {
    // 기본 생성자가 다른 생성자에게 초기화를 위임
}
```

- 같은 클래스의 다른 생성자를 호출합니다.
- 중복 코드를 줄이는 데 유용합니다.
- 반드시 **초기화 리스트**에서만 호출해야 합니다.

---

## ✅ 요약 표

| 용법 | 예시 | 의미 |
|------|------|------|
| 멤버 초기화 | `: location{x, y}` | 멤버 변수 직접 초기화 |
| 상속 클래스 생성자 호출 | `: Monster()` | 부모 클래스 생성자 호출 |
| 생성자 위임 | `: Monster_a(10, 10)` | 자기 클래스 내 다른 생성자 호출 (C++11+) |

---

## 🧠 팁

- 초기화 리스트는 **생성자 본문보다 먼저 실행**됩니다.
- 모든 멤버 변수는 가능하면 초기화 리스트에서 초기화하세요.
- `const`, `reference`, `array` 멤버는 반드시 초기화 리스트에서 초기화해야 합니다.


## 멤버 변수 초기화 
- `클래스는 멤버 변수를 여러 개 가질 수 있습니다.`
  - 어떤 멤버 변수는 객체가 생성되고 나서 여러 동작 중에 값이 정해지기도 하고
  - 클래스가 생성될 때 값을 정해야 하기도 합니다.
    - 클래스의 멤버 변수는 멤버 함수의 실행 중에 값이 정해지더라도 초깃값을 설정하는 것이 오류 방지에 도움이 됩니다.
  - 그리고 문법적으로 반드시 초기화해야 하는 멤버 변수도 있습니다. 

- 객체가 생성될 때 초기화가 필요한 멤버 벼수는 생성자를 이용합니다.
  - 특별히 레퍼런스 멤버 변수와 상수 멤버 변수는 생성자에게 반드시 초기화해야 합니다.
  - 정적 멤버 변수는 전역 범위에서 초기화해야 합니다.

### 일반 멤버 변수 초기화
- 일반 멤버 변수는 생성자에서 일반적으로 대입 연산(=)으로 초기화하는 방법과 생성자 선언 뒤쪽에 초기화 목록을 이용하는 방법이 있습니다.
- `직접 초기화 direct initialization`: 초기화 목록을 이요할 때는 대입 연산이 아닌 직접 초기화 구문을 사용합니다.

```cpp
Monster_b() : monster_type("일반") {   //  초기화 리스트 (Direct Initialization)
    difficult_level = 10;             //  대입 (Copy Initialization)
}
```

| 방법                      | 이름      | 설명                                  |
| ----------------------- | ------- | ----------------------------------- |
| `: monster_type("일반")`  | 초기화 리스트 | 생성자 시작 전에 멤버에 값을 직접 넣는 방식 → 빠르고 안전함 |
| `difficult_level = 10;` | 대입      | 생성자 본문 안에서 값을 넣는 방식                 |

더 쉽게, 만화로 비유하자면:
- `초기화 리스트는 태어날 때 이름을 짓는 것`이고,
- `대입은 태어난 다음에 이름표를 붙이는 것`입니다.
         (→ 전자가 더 자연스럽고, 어떤 경우는 반드시 필요합니다.)

- 대입 연산은 데이터가 복사되므로 `복사 초기화 copy initialization`라고 합니다.
  - 대입 연산은 메모리 공간이 추가로 필요하고 복사가 일어나므로 성능에 미세한 차이가 있습니다.
  - 일반 변수는 큰 차이가 없지만, 클래스 변수는 직접 초기화(초기화 목록 이용)와 복사 초기화(본문에서 대입 연산) 사이에 차이가 존재합니다.

## 레퍼런스 멤버 변수와 상수 멤버 변수 초기화
- 클래스의 멤버가 아니더라도 레퍼런스 변수와 상수 변수는 선언과 동시에 값이 정해져야 합니다.
- 레퍼런스 변수에는 참조할 변수나 객체를 지정해야 하고, 상수 변수에는 값을 지정해야 합니다.
- 따라서 클래스의 멤버로 선언한 레퍼런스 변수와 상수 변수는 객체를 생성할 때 자동으로 호출되는 생성자에서 초기화 목록이나 본문의 대입 연산을 통해 반드시 초기화해야 합니다.
- 상수 멤버 변수는 선언과 동시에 값을 지정해 주어도 됩니다.
- 정적 멤버 변수는 전역 범위에서 초기화되므로 어떤 클래스에 속한 멤버인지 알 수 있도록 네임스페이스를 추가해 줍니다.
  - 정적 멤버 변수 초기화: `클래스_이름::정적_멤버_변수 = 값; // 클래스 범위 밖의 전역에서 초기화`
- 이처럼 정적 멤버 변수는 전역 범위 어디에서나 초기화할 수 있지만, `가독성을 위해서 클래스가 선언된 소스 파일의 최상단이나 클래스 선언부 밑에 작성하는 편이 좋습니다.`
  - 참고로 헤더 파일에는 정적 멤버 변수를 초기화하는 코드를 작성할 수 없습니다.
  - 헤더 파일은 여러 곳에서 포함할 수 있어서 중복 초기화가 발생할 수 있기 때문입니다.

## 문법 요약: 멤버 변수 초기화
```cpp
class Monster_b : public Monster, character {
  private: // 7. 멤버 변수 목록
   string monster_type;
   int location[2]; 
   static int total_count;
   consst int unique_id;
   player &target;
   int difficult_level;
   char *quiz;

  public:
    Monster_b(player &attack_target)
      : ㅡonster_type("일반"), // 1. 직접 초기화
      location{0, 0},         // 2. 유니폼 초기화
      unique_id(++total_count), // 3. 상수 변수 초기화
      target(attack_target) {   // 4. 레퍼런스 변수 초기화
        difficult_level = 10;   // 5. 복사 초기화
        quiz = new char[1024];  // 6. 동적 메모리 할당
      }
 };
 
 int monster_b::total_count = 0; // 8. 정적 변수 초기화
```
1. **직접 초기화**: 멤버 변수에 값을 직접 대입하는 방법이다. 
   - 초기화 목록에서는 초깃값을 소괄호로 감싼다.

2.**유니폼 초기화**: 배열 형태의 멤버 변수를 초기화하는 방법이다.
   - 생성자 정의부에서도 똑같은 형태로 초기화할 수 있다. 
  - 많은 원소를 가진 배열 형태의 멤버 변수 초기화에 유용하다.

3.**상수 멤버 변수 초기화**: 상수 멤버 변수는 변경할 수 없으므로 객체 생성과 동시에 값이 정해져야 한다.
  - 따라서 초기화 목록에서 초기화해야 한다.
 
4. **레퍼런스 멤버 변수 초기화**: 레퍼런스 멤버 변수는 변경할 수 없으므로 객체 생성과 동시에 값이 정해져야 한다.
  - 따라서 초기화 목록에서 초기화해야 한다.

5. **복사 초기화**: 정의부에서 멤버 변수에 값을 직접 대입한다.

6. **동적 메모리 할당**: 포인터 변수의 메모리는 필요에 따라 생성자에서 초기화할 수 잇다.

7. **멤버 변수 목록**: 포기화할 멤버 변수 목록입니다.

8. **정적 멤버 변수 초기화**: 정적 멤버 변수는 프로그램 시작과 동시에 값이 지정돼야 하므로, 전역 범위에서 초기화 한다.



## 🔍 질문: 왜 레퍼런스 멤버 변수는 한 번 정하면 바꿀 수 없을까?

---

## ✅ 1. 레퍼런스(reference)는 "별명"이에요

```cpp
int a = 10;
int& ref = a;
```

- 여기서 `ref`는 `a`의 **다른 이름(=별명)**이에요.
- 즉, `ref`를 바꾼다는 건 **a를 바꾸는 것**이에요.

---

## 🔗 2. 별명은 바꿀 수 없어요

```cpp
int a = 10;
int b = 20;
int& ref = a;

ref = b;  // ❌ 이건 ref가 b를 가리키게 하는 게 아님!
          // → b의 값을 a(=ref)에 복사하는 것일 뿐
```

- `ref = b;`는 **ref가 b를 가리키게 바꾸는 게 아니고**,  
  **a에 b의 값을 복사하는 것**이에요.
- 즉, **ref가 가리키는 대상을 바꾸는 건 C++에서는 안 됩니다!**

---

## 🧱 3. 클래스 멤버에 적용하면?

```cpp
class A {
private:
    int& ref;  // 레퍼런스 멤버 변수

public:
    A(int& x) : ref(x) {}  // ✅ 생성자에서 한 번만 초기화 가능
};
```

- 클래스 안에서 `int& ref;`를 선언하면,  
  반드시 **생성자에서 딱 한 번 초기화**해야 합니다.
- 그 이후에는 **ref가 어떤 변수를 가리키는지 절대로 바꿀 수 없습니다.**

---

## 🧠 왜 이렇게 만들었을까?

| 이유 | 설명 |
|------|------|
| 참조(reference)는 포인터처럼 바뀌지 않도록 설계됨 | `ref`는 **절대적으로 고정된 연결**을 의미 |
| 안정성 | 한 번 연결된 대상이 중간에 바뀌면 버그 발생 위험 커짐 |
| 직관성 | `ref`는 "얘가 얘를 가리킨다!"는 명확한 의미를 가짐 |

---

## 🎯 비유로 쉽게 말하면

> 📎 `ref`는 마치 누군가의 **"명찰"**이에요.  
> 한 번 "김민준 = ref" 라고 쓰면, 그 명찰은 **다른 사람에게 줄 수 없어요.**  
> 명찰에 적힌 이름은 바꿀 수 없고,  
> **명찰 주인은 영원히 김민준!**

---

## ✅ 정리

| 개념 | 설명 |
|------|------|
| 레퍼런스는 별명이다 | 한 번 붙으면 끝! |
| 대상을 바꿀 수 없다 | 생성자에서만 설정 가능 |
| 멤버로 사용할 땐 반드시 초기화 리스트에서 지정 | `: ref(x)`처럼 사용해야 함 |
| 바꾸고 싶으면 포인터를 써야 함 | `int* ptr`은 바꿀 수 있음 |

---

## 💡 팁

```cpp
class B {
private:
    int* ptr;  // 포인터는 나중에 바꿀 수 있음
public:
    void change(int* new_target) {
        ptr = new_target;
    }
};
```

> ✅ 만약 "가리키는 대상"을 바꿀 수 있어야 한다면,  
> 👉 **레퍼런스가 아니라 포인터를 써야 합니다!**


## 🔍 chatGPT 강의. 핵심 주제: 레퍼런스 변수와 상수 변수는 **반드시 처음에 값을 줘야 한다!**

---

## ✅ 1. 레퍼런스 변수는 "붙잡을 대상"이 필요해요

```cpp
int a = 5;
int& ref = a;   // ✅ ref는 a를 참조 (OK)
```

- 레퍼런스(`&`)는 **"어떤 변수 하나를 꼭 붙잡고 있어야"** 합니다.
- 그런데 붙잡을 대상을 **나중에 지정하면 안 돼요.**  
  → **처음부터 딱 정해줘야** 해요!

---

## ✅ 2. 상수 변수는 "한 번만" 값을 줄 수 있어요

```cpp
const int x = 10;   // ✅ OK
x = 20;             // ❌ 안 됨!
```

- `const`는 **값을 바꾸지 못하는 변수**예요.
- 그래서 **처음 만들 때 값을 꼭 정해줘야** 해요.  
  나중에 바꾸는 건 불가능!

---

## 🧱 그래서 클래스에서 이런 변수들은 꼭 "초기화 리스트"로 설정해야 해요!

```cpp
class A {
private:
    const int c;
    int& ref;

public:
    A(int x, int& y) : c(x), ref(y) {
        // 여기 안에서 = 으로는 초기화 못 함!
    }
};
```

- 위 코드에서 `c(x)` 와 `ref(y)`는 클래스가 만들어질 때 **바로 초기화**됩니다.
- 만약 저걸 생략하면 컴파일 에러 납니다.

---

## 🧠 정리해서 말하면

| 항목 | 설명 |
|------|------|
| 레퍼런스 변수 | 참조할 대상을 처음에 꼭 지정해야 함 |
| 상수 변수 | 처음 한 번만 값을 줄 수 있으니 반드시 초기화해야 함 |
| 클래스 안에서 | 생성자 `: 초기화 리스트`에서 설정해줘야 함 |
| 일반 변수와 차이 | 일반 변수는 생성자 본문에서 나중에 `=` 써도 되지만, const/reference는 안 됨! |

---

## 🎯 쉽게 외우기

> **레퍼런스와 상수는 "처음부터 딱 정해줘야 하는 성격"**  
> 그래서 클래스에서도 만들자마자 값을 줘야 해요!  
> 그냥 놔두면 **에러 납니다.**

## 정적 멤버 변수 초기화
- 함수에서 정적 변수를 사용하면 선언과 동시에 값을 지정해야 합니다.
  - 함수는 메모리에 한 번 할당되고 사용 범위가 함수로 한정되므로 선언과 동시에 값을 지정하면 됩니다.

- 하지만 클래스에 선언한 정적 멤버 변수는 조금 다릅니다.
  - 왜냐며하면 클래스 멤버 변수를 `static`으로 선언하면 해당 클래스로 생성하는 모든 객체에서 참조할 수 있기 때문입니다.
  - 객체가 언제 어디서 생성될지 사전에 알 수 없으므로, 프로그램이 구동되는 시점에 값이 지정되어야 합니다.

## chatGPT 추가 설명
## ✅ 정적 멤버 변수 초기화 (쉽게 설명 + 예시)

---

### 🔹 1. 함수 안의 static 변수: 선언과 동시에 초기화 가능

```cpp
void printCallCount() {
    static int count = 0;  // ✅ 선언 + 초기화 동시에 가능
    count++;
    cout << "호출 횟수: " << count << endl;
}
```

- `count`는 이 함수가 몇 번 호출되었는지를 기억하는 변수예요.
- **`static`이라서 함수가 끝나도 사라지지 않고 한 번만 만들어집니다.**
- 이 경우는 **선언과 동시에 값을 지정해도 됩니다.**

---

### 🔸 2. 클래스의 static 멤버 변수는 다르게 취급됨

```cpp
class Monster {
public:
    static int monster_count;  // ❗ 선언만 함 (초기화 아님)
};
```

- 클래스 안에서 `static` 변수는 **모든 객체가 공유**하는 변수입니다.
- 객체를 100개 만들든, 0개 만들든 이 변수는 **하나만 존재**합니다.
- 하지만 **언제 객체가 만들어질지 알 수 없기 때문에**,  
  → **클래스 바깥에서 초기화해야 합니다.**

---

### 🔸 3. 클래스 바깥에서 실제로 초기화하기

```cpp
int Monster::monster_count = 0;  // ✅ 진짜 초기화 (메모리 할당 + 값 지정)
```

- 이 줄이 있어야만 `monster_count`가 실제로 메모리에 만들어지고 0으로 초기화됩니다.

---

### 🧪 전체 예제: 객체 수 세기

```cpp
#include <iostream>
using namespace std;

class Monster {
public:
    static int monster_count;

    Monster() {
        monster_count++;
        cout << "Monster 생성됨! 총 수: " << monster_count << endl;
    }

    ~Monster() {
        monster_count--;
        cout << "Monster 파괴됨! 남은 수: " << monster_count << endl;
    }
};

// 🔧 클래스 밖에서 static 변수 초기화!
int Monster::monster_count = 0;

int main() {
    Monster a;
    Monster b;

    {
        Monster c;
    } // 여기서 c는 파괴됨

    cout << "현재 Monster 수: " << Monster::monster_count << endl;
    return 0;
}
```

---

### 🧠 정리 요약

| 구분 | 설명 |
|------|------|
| 함수의 static 변수 | 함수 안에서 선언 + 초기화 가능 |
| 클래스의 static 멤버 변수 | 클래스 안에서는 선언만 하고, **클래스 밖에서 초기화해야 함** |
| 이유 | 클래스 변수는 **공유 자원**이고, 객체 생성 전에 메모리에 미리 올려야 하기 때문 |
| 예시 활용 | 객체 수 세기, 전역 설정값 저장, 로깅 상태 유지 등 |

---

### 🎯 비유로 기억하기

> 함수의 static 변수는  
> 📓 "나만 보는 비밀 노트" → 함수 안에서 바로 써도 OK

> 클래스의 static 변수는  
> 🪧 "모두가 보는 공용 칠판" → 밖에서 딱 한 번 준비해놔야 함


---
## 😊 질문: 클래스 안에서 `static int monster_count = 0;` 이렇게 쓰면 어떻게 될까?

---

## 🔴 답: 대부분의 경우 **에러가 나요!**

```cpp
class Monster {
public:
    static int monster_count = 0;  // ❌ 이렇게 쓰면 컴파일 에러!
};
```

### ❓왜 에러가 날까?

- `static` 멤버 변수는 **모든 객체가 함께 쓰는 변수**예요.
- 그런데 C++에서는 이 변수를 **클래스 안에서는 만들 수만 있고, 값을 넣을 수는 없어요!**

> 즉, "이런 변수 있다!"는 말만 할 수 있고,  
> "값은 밖에서 넣어야 해요."

---

## ✅ 올바른 방법

```cpp
// Monster.h (클래스 안에서는 선언만!)
class Monster {
public:
    static int monster_count;  // 👈 선언만!
};

// Monster.cpp (클래스 밖에서 값을 넣기!)
int Monster::monster_count = 0;  // 👈 진짜로 값을 여기에 넣어요!
```

---

## 😊 그럼 언제 클래스 안에서 값을 넣을 수 있을까?

### ✅ 딱 2가지 경우

#### ① `const static int`처럼 상수일 때

```cpp
class Config {
public:
    static const int max_hp = 100;  // ✔️ 상수니까 클래스 안에서 OK!
};
```

#### ② C++17부터는 `inline static` 키워드를 쓰면 돼요

```cpp
class Monster {
public:
    inline static int monster_count = 0;  // ✔️ C++17 이상에서만 가능
};
```

---

## 🧠 요약 정리

| 상황 | 클래스 안에서 초기화 가능? | 설명 |
|------|----------------------------|------|
| 그냥 static int | ❌ 안 돼요! | 클래스 밖에서 초기화해야 해요 |
| static const int | ✅ 돼요 | 상수라서 OK |
| inline static int | ✅ 돼요 | C++17부터 가능해졌어요 |

---

## 🎯 외우는 법

> 클래스 안에서는  
> ✔️ **"이런 변수 있어요!"** 라고 말만 하고,  
> ❌ **"값은 밖에서 줘야 해요!"**

---


## ❌ 클래스 안에서는 왜 안 될까?

```cpp
class Monster {
public:
    static int monster_count = 0;  // ❌ 이렇게 하면 에러!
};
```

- 클래스의 `static` 변수는 **객체가 아닌, 클래스 전체가 공유**하는 변수예요.
- 그런데 이 변수는 클래스가 컴파일될 때 **"설계도 정보만 가지고 있고", 메모리에 아직 없음**!
- 그래서 C++은 "실제 메모리에 언제 만들고, 어디에 둘지"를 **클래스 바깥에서 지정해줘야 해요.**

---

## 📦 비유로 쉽게 설명하면

| 함수 안 static 변수 | 클래스 static 변수 |
|----------------------|------------------------|
| 🎁 "내 방에 두는 개인 상자" | 🪧 "건물 복도에 두는 공용 칠판" |
| 함수가 실행되면 딱 한 번 만들어짐 | 프로그램 시작할 때 정확히 지정해줘야 함 |
| 선언 + 값 넣기 가능 | 선언만 하고 값은 **밖에서 넣기!** |

## 🏗️ 클래스는 무엇인가요?

> 클래스는 "설계도"예요.  
> 실제로 메모리에 올라가는 건 **객체(=인스턴스)**입니다.

```cpp
class Monster {
public:
    int hp;  // 체력
};

// 여기서 객체를 만들어야 진짜 존재함!
Monster goblin;  // ✅ 이게 실체!
```

- `class Monster`는 **이런 구조로 생긴 애가 있을 거야~ 라고 정의하는 것**
- `goblin`은 이 클래스의 설계대로 만들어진 **실제 존재 (객체)**

---

## 🧠 그럼 static 멤버는 왜 클래스 안에서 초기화하면 안 될까?

### 📌 이유 1: 클래스는 "설계도"라서 진짜 메모리를 아직 안 씀

```cpp
class Monster {
public:
    static int monster_count;  // 📣 이 칠판은 "모든 몬스터가 같이 씀"
};
```

- 이건 마치 "몬스터라는 개념이 있다. 그리고 공용 칠판도 있다!"고 말하는 것
- 하지만 칠판을 **실제로 어디다 둘지는 아직 안 정했어요**

### 📌 이유 2: 그래서 클래스 바깥에서 "진짜로 메모리에 만들어야" 해요

```cpp
int Monster::monster_count = 0;  // ✅ 이제 진짜 칠판 하나 생긴 거예요!
```

---

## ✅ 비유: 설계도와 공용 칠판

| 개념 | 설명 |
|------|------|
| 클래스 | 집을 짓기 위한 **설계도** |
| 객체 | 실제로 지어진 **집 한 채** |
| static 멤버 변수 | 여러 집이 함께 보는 **마을 공용 칠판** |
| 클래스 내부 선언 | "칠판이 있을 예정이야~"라고 말하는 것 |
| 클래스 외부 정의 | "진짜 칠판 하나 만들어서 0이라고 써놨어!" |

---

## ✅ 요약

> ✔️ 클래스는 **설계도**  
> ✔️ static 멤버는 **공용 변수**  
> ❌ 설계도 안에서 실제 메모리를 만들 수 없음  
> 👉 그래서 **초기화는 클래스 바깥에서 해줘야 해요**

---

## 🎯 외우는 말

> 클래스는 말만 해요.  
> 진짜 행동(메모리, 값)은 **밖에서 해야 돼요!**



