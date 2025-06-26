# 07-03: 생성자와 소멸자 (part 2): 복사 생성자

- `복사 생성자`: 객체가 복사될 때 자동으로 호출되는 함수를 의미합니다.
  -  `monster_b` 클래스의 객체를 2개 생성하는 코드를 살펴봅시다.
  - `monster_b`는 수수께끼를 내는 몬스터입니다.

```cpp
#include <iostream>
#include <string>
using namespace std;

... (생략) ...
class monster_b : public monster, character {
    private:
        string monster_type;
        int location[2];
        static int total_count;
        const int unique_id;
        player &target;
        int difficult_level; 
        char *quiz;
    
    public:
        void set_location(int x, int y){ location[0] = x; location[1] = y;};    
        void set_difficult_level(int level) { difficult_level = level; };
        void set_quiz(const char *new_quiz) { strcpy_s(quiz, 1024, new_quiz);};
        void set_type(string type) {monster_type = type; };
        
    public:
        monster_b(player &attack_target)
        : monster_type("일반"),
        location{0,0},
        unique_id(++total_count),
        target(attack_target) {
          difficult_level = 10;
          quiz = new char[1024];        
        }       
   
}

int monster_b::total_count = 0; // 정적 변수 초기화


int main(){
   player first_player;
   monster_b first_mon(first_player);
   first_mon.set_quiz("아침에 네 발, 점심에는 두 발, 주녁에는 두 발인 것은?");
   first_mon.set_difficult_level(100);
   first_mon.set_type("수수께끼 몬스터");
   
   
   monster_b second_mon(first_player);
   second_mon.set_quiz("문이 뒤집어 지면 무엇이 될까?");
   second_mon.set_location(45, 50);
}
```
## 🧠 설명: 복사 생성자와 객체 독립성

### 🧩 코드의 핵심 구조 요약

```cpp
monster_b first_mon(first_player);
...
monster_b second_mon(first_player);
```

위 코드는 `monster_b` 객체를 **두 개 각각 생성**하는 코드입니다.

---

### ✅ 1. 의미: "각자 새로 만든다"

- `first_mon`과 `second_mon`은 **서로 완전히 독립된 몬스터 객체**입니다.
- 둘 다 동일한 플레이어(`first_player`)를 **공격 대상(`target`)으로 공유**하지만,
- 다음과 같은 멤버는 **각자 고유하게 따로 존재합니다**:
  - `quiz`
  - `location`
  - `difficult_level`
  - `unique_id`

🧾 즉, 같은 설정을 기반으로 **서로 다른 몬스터 인스턴스를 각각 새로 만든 것**입니다.

---

### 💥 2. 문제의 핵심: `quiz`는 포인터다

`monster_b` 클래스 내부를 들여다보면:

```cpp
char* quiz;
...
quiz = new char[1024];
```

- `quiz`는 단순한 문자열이 아닙니다.
- `new` 연산자를 통해 **동적 메모리(heap)** 에 공간을 만들고, 그 주소를 가리키는 **포인터**입니다.

## 객체를 대입하는 방법을 생각해 봅시다.
이제 second_mon 몬스터의 타입과 난이도를 first_mon 몬스터와 똑같이 설정하고 싶습니다. 
first_mon 몬스터처럼 모든 설정 함수를 호출할 수도 있지만, monster_b second_mon = first_mon 처럼 
객체를 생성할 때 똑같은 클래스로 생성한 기존 객체를 대입하고 싶을 때가 있습니다. 
그러면 멤버 변수들이 그대로 복사되므로 수수께끼와 몬스터 위치만 다르게 설정해 주고자 합니다.

`monster_b second_mon = first_mon;`

- 이럴 경우 두 몬스터의 quiz를 출력해 보면, 같습니다. 
```
첫 번째 몬스터의 quiz: 문이 뒤집어 지면 무엇이 될까?
두 번째 몬스터의 quiz: 문이 뒤집어 지면 무엇이 될까?
```

- 하지만 우리가 예상한 것은 이것이죠:
```
첫 번째 몬스터의 quiz: 아침에 네 발, 점심에는 두 발, 주녁에는 두 발인 것은?
두 번째 몬스터의 quiz: 문이 뒤집어 지면 무엇이 될까?
```

- 이러한 현상은 수수께끼를 저장하는 char *quiz 변수가 `동적으로 할당`되기 때문에 발생합니다.
- 반면에 위치를 저장하는 int location[2] 변수는 정적으로 할당되므로 이런 현상이 발생하지 않습니다.

## 얕은 복사 shallow copy
- 객체를 초기화할 때 똑같은 클래스로 생성한 객체를 대입하면 멤버 변수들이 그대로 복사됩니다.
  - 이때 `정적으로 할당된 멤버 변수는 변수가 생성되고 값이 복사`됩니다.
  - 반면에 `동적으로 할당된 멤버 변수는 메모리를 할당하지 않고 대입한 객체의 멤버 변수를 포인터로 참조`합니다.
  - 이를 `얕은 복사 shallow copy`라고 합니다.
- 즉, 수수께끼를 저장하는 char *quiz는 동적으로 할당되므로 두 번째 객체는 첫 번째 객체에서 할당한 메모리를 참조합니다.
  - 따라서 두 번째 객체에서 변경한 내용이 첫 번째 객체에도 그대로 반영됩니다.
  - 만약 첫 번째 객체가 소멸되어 메모리가 해제된 후, 두 번째 객체에서 같은 메모리를 해제하려고 시도하면 에러가 발생합니다.

## 깊은 복사 (Deep Copy)

### 얕은 복사의 문제

- 동적 메모리를 사용하는 멤버 변수가 있을 때,
- 단순 복사(= 얕은 복사, shallow copy)를 하면 **같은 메모리 주소를 공유하게 되어 위험합니다**.
  - 예: 두 객체가 같은 포인터(`quiz`)를 가리킴 → 하나가 삭제하면 나머지는 dangling pointer가 됨.

---

### 해결 방법: 깊은 복사

- 이런 문제를 해결하려면, **동적으로 할당된 멤버 변수의 내용까지 복사**해 주는 **깊은 복사(Deep Copy)**를 해야 합니다.
- 이를 위해 **기본 복사 생성자**를 **직접 오버라이딩**해야 합니다.

---

### 기본 복사 생성자의 동작

```cpp
monster_b second_mon = first_mon;  // 기본 복사 생성자 호출됨
```

- 위와 같이 객체를 **같은 클래스로 초기화**하면, C++은 자동으로 **얕은 복사**를 수행합니다.
- 따라서 포인터도 그냥 주소만 복사되고, **데이터를 새로 복사해 주지 않습니다.**

---

### 복사 생성자 오버라이딩

#### 복사 생성자의 일반적인 형태

```cpp
클래스이름::클래스이름(const 클래스이름& ref);
```

#### 몬스터B 클래스 예시

```cpp
monster_b::monster_b(const monster_b& ref);
```

- 이 생성자를 정의하여 `quiz` 포인터가 가리키는 내용을 새롭게 복사하면, 두 객체가 **완전히 독립적인 메모리 공간을 가지게 됩니다.**

---

### 요약

| 항목 | 설명 |
|------|------|
| 얕은 복사 | 포인터 주소만 복사됨 → 메모리 공유 → 위험 |
| 깊은 복사 | 메모리 내용 자체를 새로 복사함 → 안전 |
| 복사 생성자 | `ClassName(const ClassName& other)` 형태로 직접 정의 |
| 몬스터 예시 | `monster_b::monster_b(const monster_b& ref)` 로 선언 및 구현 필요 |

깊은 복사로 재정의하는 방법
```
monster_b(const monster_b &ref); //복사 생성자 선언

// 복사 생성자 정의(깊은 복사)
monster_b::monster_b(const monster_b &ref) 
  : unique_id(++total_count),    // 새 ID 부여
    target(ref.target)           // 대상 플레이어는 그대로
    {
      quiz = new char[1024];
      strcpy_s(quiz, strlen(ref.quiz) + 1, ref.quiz);
      monster_type = ref.monster_type;
      difficult_level = ref.difficult_level;
      location[0] = ref.location[0];
      location[1] = ref.location[1];
    }
```

`monster_b(const monster_b &ref);  // 복사 생성자 선언`
- ref는 복사할 대상 객체입니다.
- const monster_b &ref는:
  - const: 복사 대상(ref)을 수정하지 않겠다는 의미
  - & (참조): 값 복사가 아니라 참조로 전달 → 불필요한 복사를 방지

```
char* quiz;
quiz = new char[1024];
      strcpy_s(quiz, strlen(ref.quiz) + 1, ref.quiz);
```
- `quiz`는 포인터이므로, 얕은 복사를 하면 두 객체가 같은 문자열을 공유하게 됩니다.
- `new char[1024]`: 새 메모리 할당 (힙에)
- `strcpy_s(...)`: 원본 문자열을 안전하게 복사 (버퍼 오버플로 방지)
- `deep copy`를 통해 완전히 새로 메모리를 만들고, 그 안에 내용도 새로 복사해야 합니다.

- 주의할 점은 오버라이딩한 복사 생성자가 호출되면 다른 생성자가 호출되지 않으므로 초기화할 변수를 복사 생성자에서 의도에 맞게 값을 대입해 줘야 합니다.

- 실행 결과를 보면 두 번째 몬스터의 타입(수수께끼 몬스터)과 난이도(100)는 첫 번째 몬스터의 속성이 복사되었고, 위치와 수수께끼 내용은 새로 설정된 값으로 출력

## 문법 요약: 생성자

```cpp
class monster {
  public: 
    // 1. 기본 생성자
    monster(0 {...};
};

class monster_a : public monster {
  public:
     // 2. 자식 클래스 기본 생성자
     monster_a() {...};
     
     // 3. 매개변수가 추가된 생성자
     monster_a(int x, int y) { ... };
     
     // 4. 변수 초기화가 추가된 생성자
     monster_a(int z_order) : z_index(z_order) { ... };
     
     // 5. 기본 복사 생성자를 오버라이딩한 복사 생성자
     monster_a(monster_a& copy_monster) {...};
};
```
- 1. **기본 생성자**: 클래스 이름과 똑같은 이름으로 함수를 정의한다. 
  - 반환값은 작성하지 않으며, 초기화 코드는 함수의 몸체에 작성한다.
- 2. **자식 클래스**: 생성자를 정의하는 방법은 부모와 자식 클래스 모두 같다. 
  - 자식 클래스의 생성자는 상속 받은 부모 클래스의 생성자 다음에 호출된다.
- 3. **매개변수가 추가된 생성자**: 생성자는 매개변수를 전달받아서 적절한 초기화를 진행할 수 있다. 
- 4. **변수 초기화가 추가된 생성자**: 생성자 정의 내에서 초기화할 수 없거나 별도로 초기화할 변수는 함수 선언부와 정의부 사이에서 초기화한다.
- 5. **기본 복사 생성자를 오버라이딩한 복사 생성자**: 기본 복사 생성자 사용으로 문제가 발생할 경우 복사 생성자를 오버라이딩하여 문제를 제거할 수 있다.

`안전성이 강화된 strcpy_s 함수`
- 코드에서 char 배열을 복사하기 위해서 strcpy_s를 사용했습니다.
- char 배열을 복사하기 위해 사용하던 strcpy는 복사할 배열의 범위를 벗어날 수 있는 위험이 있습니다.
- strcpy 대신 strcpy_s를 사용했습니다. 
  - strcpy_s 함수는 복사할 원본과 복사할 대상 메모리의 크기가 다를 때 발생할 수 있는 오류를 방지합니다.
  - strcpy_s 함수를 사용하려면 <string> 헤더를 포함해 주어야 합니다.

## 소멸자 destructor 
- 생성자와 반대 역할을 합니다.
- 생성자에서는 객체가 생성될 때 필요한 여러가지 일을 진행했다면
- `소멸자에서는 객체가 소멸할 때 필요한 메모리 해제나 외부 환경을 객체 생성 이전 상태로 변경하는 등의 일을 진행`합니다.
  - `~클래스_이름()`
- 소멸자는 객체가 소멸되는 시점에 자동으로 호출됩니다. 
- 주로 메모리나 정적 변숫값을 생성 전으로 되돌리는 작업이 많아서 매개변수가 필요하지 않습니다.
- 다중 상속일 때 생성자 호출의 역순으로 소멸자가 호출됩니다.

```cpp
class character {
  public:
    // character constructor
    character() {
      cout << "character class constructor" << endl;
    };
    
    // character deconstructor
    ~character() {
      cout << "character class deconstructor" << endl;
    }
};

class monster{
  public:
    monster() {
      cout << "monster class constructor" << endl;
    };
    
    ~monster() {
      cout << "monster class deconstructor" << endl;
    };
};

class monster_a : public monster, character {
  public:
    monster_a() {
      cout << "monster_a class constructor" << endl;
    };
    
    ~monster_a() {
      cout << "monster_a class deconstructor" << endl;
    }
};

int main(){
  monster_a forest_monster;
  return 0;
}
```
실행 결과
```cpp
monster class constructor
character class constructor
monster_a class constructor
monster_a class deconstructor
character class deconstructor
monster class deconstructor
```

| 개념     | 설명                                           |
| ------ | -------------------------------------------- |
| 생성자 순서 | 기초 클래스 → 파생 클래스                              |
| 소멸자 순서 | 파생 클래스 → 기초 클래스                              |
| 자동 호출됨 | `main()` 안에서 지역 변수로 객체 생성 시, 생성자/소멸자는 자동 호출됨 |
| 중요성    | 상속 구조에서 리소스 해제를 제대로 하려면 소멸자 순서 이해가 꼭 필요      |

**언제 호출되나요?**
- 지역 변수: 해당 블록(scope)이 끝날 때 자동 호출
- 전역 변수: 프로그램 종료 시 호출
```cpp
{
    Monster dragon;
    // dragon 사용 중
}  // ← 이 블럭이 끝나는 순간, 소멸자 `~Monster()` 자동 호출됨
```
- dragon을 더 이상 "사용하지 않게 돼서" 소멸되는 게 아니라,
- dragon이 "속해 있는 블럭이 끝났기 때문에" 소멸자가 호출되는 거예요.

**비교: constructor ↔ destructor vs new ↔ delete**

| 항목       | constructor ↔ destructor    | new ↔ delete                   |
| -------- | --------------------------- | ------------------------------ |
| 호출 시점    | 자동으로 호출됨                    | 수동으로 호출해야 함                    |
| 언제 일어남?  | 객체가 생성/소멸할 때 **무조건 호출**     | `new` 하면 `delete`는 **직접 해야 함** |
| 누가 책임지나? | **컴파일러/언어**가 관리             | **프로그래머**가 관리                  |
| 실수 시 결과  | 거의 없음 (자동 호출)               | ❌ 메모리 누수, double delete 등 위험   |
| 예외 처리 시  | 예외가 발생해도 destructor는 자동 호출됨 | delete 누락 시 리소스 회수 안 됨         |

- **예시 1: 지역 변수 (자동 소멸)**
```cpp
void run() {
    Monster m;  // constructor 자동 호출
    // ...
}  // 블록 종료 → destructor 자동 호출 (절대 누락 안 됨)
```
**- 예시 2: 동적 할당 (주의 필요)**
```cpp
Monster* m = new Monster();  // constructor 호출
// ...
delete m;  // ❗ 이 줄 빼먹으면 destructor 호출도 안 됨
```

## 가상 소멸자 (Virtual Destructor)

### 문제 상황: 부모 포인터로 자식 객체를 삭제할 때 발생하는 문제

- **자식 클래스는 언제든지 부모 클래스를 대신할 수 있어야 한다**  
  → 이것이 [리스코프 치환 원칙 (Liskov Substitution Principle)]의 핵심입니다.

```cpp
class Monster {
public:
    Monster() {
        cout << "Monster class constructor" << endl;
    }
    ~Monster() {
        cout << "Monster class destructor" << endl;
    }
};

class Monster_a : public Monster {
public:
    Monster_a() {
        cout << "Monster_a class constructor" << endl;
    }
    ~Monster_a() {
        cout << "Monster_a class destructor" << endl;
    }
};

int main() {
    Monster* forest_monster = new Monster_a();  // 부모 타입 포인터
    delete forest_monster;  // 소멸자 호출
    return 0;
}
```

### 출력 결과 (가상 소멸자 없음)

```
Monster class constructor
Monster_a class constructor
Monster class destructor   ← 자식 소멸자 호출 안 됨!
```

### 문제 발생

- `forest_monster`는 `Monster_a` 객체를 가리키지만,
- `delete` 시 **부모 소멸자만 호출**되고 **자식 소멸자는 건너뜀**
- 자식 클래스에서 관리하던 리소스(`new`, `파일`, `소켓`)가 **정리되지 않고 메모리 누수 발생**

---

## 해결 방법: 가상 소멸자 사용

- 부모 클래스의 소멸자를 `virtual`로 선언하면,
- `delete` 시 **자식 → 부모 순으로 소멸자 모두 호출**됨

```cpp
class Monster {
public:
    virtual ~Monster() {
        cout << "Monster class destructor" << endl;
    }
};

class Monster_a : public Monster {
public:
    ~Monster_a() {
        cout << "Monster_a class destructor" << endl;
    }
};
```

### 출력 결과 (virtual 사용 시)

```
Monster class constructor
Monster_a class constructor
Monster_a class destructor   
Monster class destructor     
```

---

## 핵심 요약

| 개념 | 설명 |
|------|------|
| 가상 소멸자 | 자식 소멸자를 **부모 포인터로 delete 시에도 호출**할 수 있게 함 |
| 필요 조건 | 부모 클래스 소멸자에 `virtual` 키워드 선언 |
| 사용 이유 | **다형성 하에서 메모리 누수 방지**, 리스코프 치환 원칙 만족 |
| 좋은 습관 | 상속 가능한 클래스에는 항상 `virtual ~Class()` 선언하기 |

---

## Tip: 자식 소멸자에는 `virtual` 안 붙여도 됨

- 부모에만 `virtual` 붙이면, 하위 클래스들도 **자동으로 가상 소멸자**가 됩니다
```cpp
virtual ~Monster() {}  // 부모에만 virtual 붙이면 충분
~Monster_a() {}        // 자식에는 생략 가능
```

---

이 원리를 이해하면, **안전한 메모리 해제와 다형성 설계의 기초**를 확실히 다지게 됩니다. 😊

## virtual keyword 쉽게 기억하는 팁
- virtual = "자식에게 우선권을 줘!"
- 부모가 가진 기본 행동 대신
- 자식이 재정의한 행동(함수/소멸자/상속 구조)을 우선 실행하게 해 줍니다.

| virtual 사용 위치 | 예시                      | 역할                        |
|-------|--------------| -------------------- |
| 함수 앞     | `virtual void sound();` | 자식의 오버라이드 함수 실행 (다형성)     |
| 소멸자      | `virtual ~BaseClass();` | 자식 소멸자 호출 보장 (메모리 안전)     |
| 상속 선언    | `virtual public A`      | 중복 상속 문제 방지 (다이아몬드 상속 해결) |


