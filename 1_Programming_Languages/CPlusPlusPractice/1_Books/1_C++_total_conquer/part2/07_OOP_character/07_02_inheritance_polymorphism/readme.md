# 07-02: 상속성 inheritance 과 다형성 polymorphism
- 상속성 이해와 자식 클래스 만들기
- 다형성 이해와 자식 클래스에 다형성 적용하기

## 상속성이란 무엇일까?
- `상속`: 클래스를 만들 때 `다른 클래스의 멤버를 물려받는 것입니다`
  - 즉, 상속성이란 `다양한 특성으로 추상화`하고 `캡슐화한 클래스를 확장하고 변형하는 방법`입니다.
  - 이때 상속받은 클래스를 `자식 클래스 child class`, `파생 클래스 derived class`, 혹은 `하위 클래스 sub class`라고 합니다.
  - 반대로 상속해 주는 클래스를 `바모 클래스 parent class`, `기본 클래스 base class`, 혹은 `슈퍼 클래스 super class`라고 합니다.
  - 이 문서에서는 `부모 클래스`와 `자식 클래스`라고 하겠습니다.

### 부모 속성 상속받기
- 상속을 이용하면 `공통된 특징은 부모 클래스의 멥머를 사용`하고 `자식 클래스에서는 고유한 특징만 별도로 저으이해서 사용`할 수 있습니다.
  - 따라서 부모 클래스는 `각 멤버를 일반화하여 범용으로 설계`하고
  - 자식 클래스는 `개별적이거나 특수한 멤버`를 가지도록 설계합니다.

### 부모 클래스를 대신할 수 있는 자식 클래스
- 상속에는 중요한 특징이 한 가지 있습니다.
- `자식 클래스는 부모 클래스를 대체할 수 있습니다.`
  - 즉, 부모 클래스는 자식 클래스로 `치환 substitution`할 수 있어야 합니다.
  - 그러려면 부모가 가진 속성과 기능을 변경해서는 안 됩니다.
  - 프로그맹 문법적으로 이야기하면 부모가 외부로 노출한 함수의 **시그니처**를 그대로 상속해야 합니다.
  - `함수의 시그니처`: 함수의 이름, 매개변수 구성, 변환 형식을 아우르는 말입니다.
- 부모 클래스를 자식 클래스로 치환한다는 것은 `단순히 형식만 캍은 것이 아니라, 부모 클래스의 모든 제약 사항과 동작 방식을 그대로 유지`한다는 뜻입니다.
  - 이를 `리스코프 치환 원칙`이라고 합니다. 
  - 지금은 자식 클래스는 어떠한 위치에서도 부모 클래스를 대체할 수 있어야 한다는 특징으로 알고 있습니다. 

### 단일 상속 single inheritance 과 다중 상속 multiple inheritance
- `단일 상속 single inheritance`: 클래스를 상속받을 때 부모 클래스를 하나만 지정
- `다중 상속 multiple inheritance`: 다른 종류의 클래스를 둘 이상 상속

예제: 
```
#include <iostream>
using namespace std;

class Character {
protected:
    int hp;
    int power;

public:
    Character() {};
    virtual void _attacked(Character& character) {
        cout << "Default character _attacked." << endl;
    }
};

// 단일 상속
class Player : public Character {
public:
    Player() {};
    void _attacked(Character& character) override;
};

class Monster {
public:
    Monster() {};
};

// 다중 상속
class MonsterCharacter : public Monster, public Character {
public:
    MonsterCharacter() {};
    void _attacked(Character& character) override;
};

void Player::_attacked(Character& character) {
    cout << "Character is attacked! Look at his HP: " << hp << endl;
}

void MonsterCharacter::_attacked(Character& character) {
    cout << "The Monster character is attacked! Look at his HP: " << hp << endl;
}
```


## 문법 요약: 다중 상속
- 다중 상속을 구현할 때는 상속받을 부모 클래스를 나열합니다.
- 주의할 점은 `상속 접근 지정하지 않으면 private으로 지정`된다는 것입니다.
- 다음 예에서 monster는 public으로 상속받고, character는 private으로 상속받습니다.
  - 만약 모두 public 으로 상속받으려면 각 클래스에 접근 지정자를 붙여야 합니다.

```cpp
class Monster_a : public Monster, Character {
    // 접근 지정자
    public:
        // 상속받을 함수 구현
        void attack_special(Player target_player); 
};
```
`class Monster_a : public Monster, Character`
이 구문은 다음과 같은 의미입니다:
- Monster는 public 상속 → 외부에서도 여전히 접근 가능
- Character는 private 상속 → MonsterA 외부에서는 Character 멤버를 직접 사용할 수 없음

## 다형성 polymorphism 이란 무엇일까?
- `상속받은 클래스들이 부모와 다른 다양한 특성을 가지는 것`을 말합니다.
- 엔진의 예를 다시 생각해 봅시다
  - 자동차 엔진은 연료를 소모하여 발생한 운동 에너지를 바퀴로 전달합니다.
  - 가솔린과 디젤, 가스, 전기 엔진은 연료만 다를 뿐 엔진이라는 사실은 변함이 없습니다.
- 이처럼 `상위 개념(부모 클래스)`의 `역할을 대신할 수 있으면서 각자의 고유한 특징으로 동작하는 것이 다형성입`니다.
  - 다형성은 앞으로 만들 새로운 기능을 예상할 수는 없지만, `꼭 해야 할 역할이나 기능을 호출하는 방식은 고정하여 실현`할 수 있습니다.
  - 다형성을 적용하면 `새로운 기능이 추가될 때 호출하는 소스 코드는 변경하지 않고, 새로운 클래스를 정의하는 것만으로 기능을 확장`할 수 있습니다.

### 다향성을 활용한 유지/보수성 향상
- 다향성은 `하위 호환성 backward compatability`을 처리할 때도 사용됩니다.
  - 하위 호환성의 예: 새로운 버전(version 2.0)의 소프트웨어가 이전 버전(v1.0)에서 생성한 파일을 읽을 수 있는 것을 말합니다.
  - 하휘 버전 호환성을 구현하는 방법은 다양하지만, `다형성을 이용하면 유연하고 유지/보수가 편리한 코드로 구현`할 수 있습니다.

예제: 파일 읽기 인스턴스 생성
```cpp
... (생략) ...
file_reader_original* file_reader_original::get_reader_instance(){
    file_reader_original* reader = nullptr;
    
    switch (file_reader_original::read_header()){ // 파일 헤더를 읽어 버전 확인
        case 1:
            reader = new file_reader_v0100(); // v1.0으로 파일 리더기 생성
            break;
        case 2:
            default:
                reader = new file_reader_v0200(); // v2.0으로 파일 리더기 생성
                break;
            }     
        return reader;
    }
}
... (생략) ...
```

## 🔍 한 줄씩 해설

---

### 🔹 1. 함수 시그니처

```cpp
file_reader_original* file_reader_original::get_reader_instance()
```

- 이 함수는 `file_reader_original` 클래스에 속한 **정적(static) 팩토리 함수**입니다.  
- **반환값**: `file_reader_original*` 타입 → **다형성(polymorphism)**을 위해 **상위 타입 포인터로 반환**합니다.

---

### 🔹 2. 포인터 선언 및 초기화

```cpp
file_reader_original *reader = nullptr;
```

- 포인터 `reader`를 미리 선언하고 `nullptr`로 초기화합니다.  
- 생성 조건에 따라 알맞은 객체를 나중에 동적으로 할당합니다.

---

### 🔹 3. switch문: 버전 판별

```cpp
switch (file_reader_original::read_header())
```

- `read_header()`는 파일의 버전을 판단하는 **정적(static) 함수**라고 가정합니다.  
- 예: 파일 시작 부분(헤더)을 읽어 `1`, `2` 등 버전 번호를 반환합니다.

---

### 🔹 4. case 처리: 버전에 따라 다른 클래스 생성

```cpp
case 1:
    reader = new file_reader_v0100();
    break;
case 2:
default:
    reader = new file_reader_v0200();
    break;
```

- `case 1`: 파일 버전이 1이면 `file_reader_v0100` 인스턴스를 생성  
- `case 2` 또는 그 외: 기본값으로 `file_reader_v0200` 인스턴스를 생성  

> ※ 각 클래스는 `file_reader_original`을 상속한 **구체 클래스(concrete class)**입니다.

---

### 🔹 5. 다형성의 핵심

```cpp
return reader;
```

- `reader`는 `file_reader_original` 포인터 타입이지만,  
- 실제 객체는 `file_reader_v0100` 또는 `file_reader_v0200`입니다.  
- 호출한 쪽에서는 **공통 함수 (`read_contents()` 등)**만 호출하면 됩니다.

---

## ✅ 전체 흐름 예시로 요약

```cpp
file_reader_original* reader = file_reader_original::get_reader_instance();
// 내부적으로: 파일 버전이 1이면 -> file_reader_v0100 생성됨
//            파일 버전이 2면 -> file_reader_v0200 생성됨

reader->read_contents();  // 파일 버전에 따라 실제 동작이 다르게 실행됨 (다형성)
delete reader;
```


## 함수 재정의하기 - 오버라이딩 overriding
- 객체지향 프로그래밍에서 다형성을 구현하려면 함수의 **오버라이딩overriding**을 이용해야 합니다.
  - 부모 클래스로부터 상속받은 함수는 자식 클래스에서 부모 클래스에 정의된 내용을 그대로 사용합니다.
  - 하지만 `다향성을 구현하려면 함수의 시그니처는 그대로 유지하며서 다르게 정의`해야 합니다.

예시: 오버라이딩 함수 호출과 네임스페이스 활용
```cpp
#include <iostream>
using namespace std;

class Target{
    int hp;
    int power;

    public:     
        Target() {};
};

class Monster{
    int hp;
    int power;
    
    public: 
        Monster() {};
        virtual void attack_special(Target t){
            cout << "Monster attacks!";
        };
};

class MonsterChild : public Monster {

    public: 
        MonsterChild() {};
        void attack_special(Target t) override{
            cout << "Monster's child attacks!";    
        }
};


int main(){

    MonsterChild monsterChild_a;
    Target target_a;
     
    cout << "override attack!" << endl;
    monsterChild_a.attack_special(target_a); 
    
    cout << "original attack!" << endl;
    monsterChild_a.Monster::attack_special(target_a);    

    return 0;
}
```

- 만약 자식 클래스를 부모 클래스의 레퍼런스로 접근하면 어떤 함수가 호출될까요?
```cpp
... (생략) ...
int main(){
    player player_1;
    monster_a forest_monster;     // 자식 클래스
    
    monster &mon = forest_monster;     // 부모 클래스의 레퍼런스에 대입
    monster_a &mon_a = forest_monster; // 자식 클래스의 레퍼런스에 대입
    
    cout << endl << "부모 클래스 레퍼런스로 공격" << endl;
    mon.attack_special(player_1);
    
    cout << endl << "자식 클래스 레퍼런스로 공격" << endl;
    mon_a.attack_special(player_1);
    
    return 0;    
} 
```
- `monster_a` 클래스의 인스턴스인 `forest_monster`를 생성합니다.
- 이를 부모 클래스(`monster`) 타입의 레퍼런스에 대입합니다.
- 같은 객체를 자식 클래스(`monster_a`) 타입의 레퍼런스에도 대입합니다.

- 호출 결과:
  - 부모 클래스 타입의 레퍼런스로 접근하면 `monster` 클래스에 정의된 함수가 호출됩니다.
  - 자식 클래스 타입의 레퍼런스로 접근하면 `monster_a` 클래스에 정의된 함수가 호출됩니다.
  - 즉, virtual 키워드가 없는 경우, 호출되는 함수는 **객체의 실제 타입이 아니라, 참조 변수의 타입에 따라 결정됩니다.**


## 가상 함수를 활용한 오버라이딩
- 앞의 코드에서 forest_monster는 monster_a 의 클래스의 인스턴스입니다.
  - 그러므로, 부모클래스인 monster를 참조하더라도 자신의 오버라이딩 함수가 호출돼야 합니다.
  - 즉, 앞의 코드에서 mon.attack_special 함수를 호출해도 monster_a 클래스에 오버라이딩 함수가 호출되어야 합니다.
  - 그래야만 자식마다 다양한 특성을 지니는 다향성이 적용되었다고 할 수 있습니다.
- `가상 함수 virtual function`를 활용합니다.
  -  virtual 함수는 "어떻게 바라보느냐"가 아니라, "누구냐(실제 객체가 무엇이냐)"에 따라 함수가 결정되도록 합니다.
  - 멤버 함수의 이름 앞에 virtual 이라는 키워드로 선언하면 가상 함수가 됩니다.
  - 그리고 자식 클래스에서 가상 함수를 오버라이딩하면 런타임 때에 올바른 버전의 함수가 호출됩니다.
- 즉, 부모 클래스를 참조하더라도 객체에서 가장 마지막에 오버라이딩된 함수를 호출합니다.
```cpp
... (생략) ...
class Player {
    // 예시용 간단한 클래스
};


class Monster{
    
    public: 
        virtual void attack_special(Player player){
            // 내용 
        }
};

class Monster_a : public Monster {
    
    public:
        virtual void attack_special(Player player){
            // 내용
        }
};

int main(){
    Player player_1;
    Monster_a forest_monster;     // 자식 클래스
    
    Monster& mon = forest_monster;      // 부모 클래스의 레퍼런스에 대입
    Monster_a& mon_a = forest_monster;  // 자식 클래스의 레퍼런스에 대입
    
    cout << endl << "부모 클래스 레퍼런스로 공격" << endl;
    mon.attack_special(player_1); // 부모 클래스 함수 호출
    
    cout << endl << "자식 클래스 레퍼런스로 공격" << endl;
    mon_a.attack_special(player_1); // 자식 클래스 함수 호출
    
    cout << endl << "자식 인스턴스로 부모 클래스 함수로 공격" << endl;
    mon_a.Monster::attack_special(player_1); // 부모 클래스 함수 호출
    
    return 0;    
} 
```




## 객체지향 프로그래밍 특징 정리

1. **추상화**  
   - 여러 개의 복잡한 자료, 모듈, 시스템 등으로부터 공통된 핵심 개념이나 기능으로 간추리는 것을 말합니다.  
   - 불필요한 부분은 제거하고 공통된 특징을 추출하여 클래스를 간결하게 만들어 이해하기 쉽게 만드는 작업입니다.

2. **캡슐화**  
   - 클래스의 구체적인 동작을 외부로 노출하지 않도록 감추는 것입니다.  
   - 멤버 변수와 멤버 함수를 낱개로 외부에서 사용할 수 있게 하는 것이 아니라, 일련의 과정 하나로 묶어서 관리하는 것입니다.  
   - 캡슐화를 잘 활용하면 프로그램의 복잡도는 낮아지고 재사용성은 높아집니다.

3. **상속성**  
   - 부모 클래스의 데이터(속성)와 함수(기능)를 자식 클래스가 물려받아 확장하는 것입니다.  
   - 상속을 통해서 논리적인 포함 관계와 공통의 특징을 더 명확하게 모델링할 수 있습니다.

4. **다형성**  
   - 하나의 클래스가 다양한 형태의 속성과 기능을 할 수 있음을 나타냅니다.  
   - 부모 클래스에서 정의한 함수도 자식 클래스에서 재정의한 후, 부모 클래스처럼 사용할 수 있습니다.  
   - 이를 통해서 기능이 확장, 변경되어도 소스코드 변경을 최소화할 수 있습니다.

## 객체지향 프로그래밍이 주는 이점
- 확정성과 유지/보수성이 뛰어난 프로그램을 만들 수 있습니다.
- 즉, 변경 사항이 생겼을 때 소스 코드를 쉽고 빠르게 변경할 수 있는 장점이 생깁니다.
- 그리고 수정하거나 추가한 내용이 이전 코드에 영향을 주는 부작용이 발생하지도 않습니다.
- 이처럼 필요한 부분만 추가하더라도 변경 사항을 잘 적용할 수 있는 것을 `확장에는 열려 있고, 수정에는 닫혀 있다`고 표현합니다.


## 3분 퀴즈
- 질문 1: 객체지향 프로그래밍에서 상속성이 무엇이고 왜 중요할까요?
- 답변 1: 부모 클래스의 속성과 기능을 이어받아서 확장하는 것이 상속입니다. 클래스를 설계하고 잴활용하는 핵심 개념입니다.

- 질문 2: 다형성 구현을 위해서 C++ 에서 사용하는 문법이나 기법은 무엇일까요?
- 답변 2: 가상 함수를 사용한 함수의 오버라이딩

- 질문 3: 가상 함수를 사용하지 않고 오버라이딩하면 어떤 문제가 발생하나요?
- 답변 3: 자식 클래스를 부모 클래스의 포인터로 접근하면, 자식 클래스의 오버라이딩된 함수가 아닌 부모 클래스의 함수가 호출됩니다. 


 