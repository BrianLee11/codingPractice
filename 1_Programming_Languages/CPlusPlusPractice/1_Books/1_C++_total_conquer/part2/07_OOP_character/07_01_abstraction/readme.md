# 07-01: 추상화와 캡슐화
- `추상화`를 이해하고 `클래스 정의`하기
- 캡슐화를 통해 `재사용성이 높으면서 신뢰성이 보장된 클래스 생성`하기

## 추상화란 무엇일까?
- 미술에서 추상화는 표현해야 할 대상을 점, 선, 면과 같은 단순한 요소로 표현하는 것을 의미합니다.
  - 객체지향 프로그래밍에서 추상화도 비슷합니다. 
  - `복잡한 자료, 모듈, 시스템 등으로 핵심 개념이나 기능을 간추리는 것`을 말합니다.
  - 즉, `추상화abstraction는 공통된 특징은 추출하고 불필요한 부분은 제거하여 코드를 간결하고 이해하기 쉽게 만드는 작업`입니다.

### 추상화가 객체지향 프로그래밍에서 중요한 이유
- 클래스는 만드는 과정과 밀접한 관계가 있기 때문입니다.
- 클래스는 표현하고자 하는 대상의 공통 특징을 `속성과 기능으로 구분`
  - 속성: 멤버 변수
  - 기능: 멤버 함수 
- 대상을 추상화하여 클래스로 만들면 생기는 장점 
  - `코드의 불필요한 부분을 줄입니다`
  - `범용성과 재상용성을 높입니다`

### 공통 특징 추출하기
- 추상화는 대상의 공통된 특징을 추출하는 데서 시작합니다.
  - 예를 들어 자동차는 용도에 따라 엔진 종료, 바퀴 개수, 크기 등에는 차이가 있지만
  - `바퀴와 엔진이 있고 사람이나 짐을 싣고 이동할 수 있다`는 공통된 특징이 있습니다.
- 추상화는 이처럼 `어떤 대상이 족한 집단에서 공통된 특징을 추출`하여 정의하는 과정입니다.
  - 추상화한 내용을 바탕으로 클래스를 만들 수 있습니다. 
  - 예를 들어, `자동차` 클래스는

```cpp
class Car{
    // 멤버 변수 2개: 엔진, 바퀴
    private: 
        string engine_name;
        int wheel_number;
    
    // 멤버 함수 3개
    void move_passenger();
    void take_lugguage();
    void move(); 
};
```

### 불필요한 요소 제거하기
- 불필요한 요소를 제거하는 것도 추상화의 한 과정입니다.
- 예를 들어, 병원 운영 애플리케이션을 만든다고 가정해 보죠
  - 병원 운영 애플리케이션에는 고객의 이름, 주소, 직업, 특기, 좋아하는 음식이 저장되어 있습니다
  - 이 중 필요하다고 판단되는 정보인 이름, 주소, 직업만 골라서 추상화를 할 수 있습니다. 
- 추상화란 개별적인 특징은 빼고 대표하는 특징만 뽑아서 정의하는 과정이기도 합니다.

## 캡슐화 encapsulation란 무엇일까요?
- 캡슐화는 `변수와 함수를 클래스로 감싸서 외부에서는 개별적으로 접근할 수 없도록 하나로 묶어서 관리`하는 것을 의미합니다.
- 캡슐화는 `클래스 밖에서 내부의 멤버에 접근할 수 없도록 정보를 은닉화hiding`합니다.
- `외부에서는 내부의 세세한 로직을 알 필요가 없으며, 혹시 로직이 변경되더라도 외부에 영향을 주지 않습니다.`
  - 따라서 복잡도는 낮아지고 재사용성은 높아집니다.

### 은닉화와 접근 지정자
- 여러 클래스를 만들어서 사용할 때 `클래스끼리 변수나 함수에 마음대로 접근하면 의도하지 않은 오류가 발생할 수` 있습니다.
  - 이런 문제를 해결하는 방법이 은닉화입니다.
- `접근 지정자 access specifier`: C++ 에서는 은닉화를 위해 접근 지정자를 제공합니다. 
  - 클래스의 멤버를 선언할 때는 접근 지정자를 지정해야 합니다.
  - 만약 지정하지 않으면 `private`으로 선언됩니다. 
- 참고로 C++ 에서는 구조체(structure)도 멤버 함수를 포함할 수 있습니다.
  - 구조체의 기본 접근 지정자는 클래스와 다르게 `public`으로 선언됩니다.

- 접근 지정자 (Access Specifiers)
  - 클래스 멤버(변수와 함수)의 접근 범위를 정의하는 키워드입니다.

| 접근 지정자 | 접근 범위 설명 |
|-------------|----------------|
| `private`   | 해당 클래스 내부에서만 접근할 수 있습니다. |
| `public`    | 모든 외부 클래스에서 자유롭게 접근할 수 있습니다. |
| `protected` | 해당 클래스와 이를 상속한 하위 클래스에서 접근할 수 있습니다. |

- `private`으로 선언한 멤버는 같은 클래스 안의 멤버 함수에서만 접근할 수 있습니다.
- `public`으로 선언한 멤버는 다른 클래스 어디서든 접근할 수 있습니다. 외부로 노출해야 하는 멤버를 공유하는 접근 지정자입니다.
- `protected`로 선언한 멤버는 같은 클래스 내의 멤버 함수나 상속 관계의 클래스에서 접근할 수 있습니다.

## 접근 지정자 적용하기
예시: bank 클래스 정의하기

```cpp
class bank {
    private: 
        int safe; // 금고는 외부에서 접근 금지
        
    public: 
        bank();   // 기본 생성자
        void use_counter(int _in, int _out); // 입출금 창구 함수
};

//기본 생정자 수정
bank::bank() {
    safe = 1000; // 은행 금고 초기 금액 설정 
    cout << "최초 금고 : " << safe << endl;
    cout << endl;
}

void bank::use_counter(int _in, int _out) {
    safe += _in; // 입금
    safe -= _out; //출금
    
    cout << "입금: " << _in << endl;
    cout << "출금: " << _out << endl;
    cout << "금고: " << safe << endl;
    cout << endl;
}

int main(){
    bank my_bank; // my_bank 인스턴스 생성
    
    my_bank.use_counter(0, 20);    // 출금 20
    my_bank.use_counter(50, 0);    // 입금 50
    my_bank.use_counter(100,50);   // 입금 100, 출금 50    
    
    return 0;
}
```

- `bank my_bank` 코드는 `인스턴스 instance`를 생성하는 코드입니다.
- 인스턴스는 클래스가 메모리에 할당되어 생성된 변수를 말합니다. 객체와 같습니다.
- `객체`: 객체라는 용어는 논리적인 개념으로 사용될 때가 많고,
- `인스턴스`: 메모리에 생성된 객체를 말할 때는 `인스턴스`라는 용어를 사용합니다. 

| 용어        | 정의 |
|-------------|------|
| **객체 (Object)**     | 클래스라는 논리적 틀에 따라 구현하려는 대상. 또는 메모리에 생성된 인스턴스를 지칭할 때 사용되기도 함. |
| **클래스 (Class)**     | 객체를 생성하기 위한 설계도 또는 틀. 속성과 동작을 정의함. |
| **인스턴스 (Instance)** | 클래스에 따라 메모리에 실제로 생성된 객체. 실체화된 클래스의 구체적인 예. |

- 질문: 만약 bank 클래스에서 `private`으로 선언된 멤버(예에서는 safe)를 main 함수에서 바로 접근하면 어떻게 될까요?
```cpp
class bank {
    private:
        int safe; // 금고
};

int main(){
    bank my_bank;
    my_bank.safe -= 100; // private으로 지정된 금고에 직접 접근하여 인출 시도
    
    return 0;
}
```
- 이 코드는 문법 오류가 발생합니다.
  - 오류 메세지를 보면 `bank` 클래스의 `safe` 멤버 변수가 `private` 접근 지정자로 선언되었다고 알려 줍니다.

## 추상화와 캡슐화를 이용한 클래스 설계
- 게임 속 몬스터가 다음과 같은 규칙으로 움직인다고 가정해 보겠습니다.

1. 몬스터는 체력과 공격력이 있다.
2. 몬스터는 데미지를 입으면 체력을 소모한다.
3. 몬스터는 공격할 수 있다.
4. 몬스터는 특수 공격을 할 수 있다.
5. 몬스터의 종류에 따라 공격력과 특수 공격은 다양하다.
    - (tip: 상속성과 다형성을 활용해 보세요)

```
// 캐릭터 클래스
class Character {
    // 해당 속성을 다른 클래스에서도 사용 가능하도록 protected로 구현
    protected:
        int hp;
        int power;

    public:
        // initialization
        Character() {
            hp = 100;
            power = 100;
        }
};

// 플레이어 클래스
// Character 클래스를 상속
class Player : public Character {
    public:
        Player() {};
};

// 기본 몬스터 클래스
class Monster {
    public:
        Monster() {};
        void get_damage(int _damage);
        void attack(Player target_player);
        void attack_special(Player& target_player);
};

void Monster::get_damage(int _damage) {
    hp -= _damage;
}

// monster_a
// 기본 몬스터 클래스, Character 클래스 상속
class Monster_a : public Monster, public Character {
    public:
        // 상속받은 함수 override
        void attack_special(Player& target_player);
};

void Monster_a::attack_special(Player& target_player) {
    hp -= 15;
}

// monster_b
// 기본 몬스터 클래스, Character 클래스 상속
class Monster_b : public Monster, public Character {
    public:
        // 상속받은 함수 override
        void attack_special(Player& target_player);
};

void Monster_b::attack_special(Player& target_player) {
    hp -= 30;
}
```
## 3분 퀴즈
### 질문 1: 객체지향 프로그래밍에서 캡슐화를 통해 얻을 수 있는 장점은 무엇일까요?
- 답변 1: 
  - 캡슐화는 **데이터(속성)**와 **기능(행위)**을 하나의 단위로 묶어 관리함으로써,  
  - 외부에 불필요한 내부 구현을 감추고 **복잡도를 낮추며 유지보수를 쉽게 만들어줍니다**.  
  - 또한 잘못된 접근을 방지하여 **보안성과 안정성도 향상됩니다**.

    - **복잡도 감소**
    - **수정 용이성 증가**
    - **보안성 강화**
    - **외부 영향 최소화**

### 질문 2: C++ 에서 접근 지정자의 정류는 무엇이 있나요?
- 답변 2: 1) private, 2) public, 3) protected

### 질문 3: 추상화는 다양한 분야에서 사용되고 의미도 조금씩 다릅니다. C++ 에서 추성화는 어떤 의미일까요?
- 답변 3: C++ 에서 추상화는 공통된 특징은 추출하고 불필요한 부분은 제거하여 코드를 간결하고 이해하기 쉽게 만드는 작업입니다. 
  - 이를 통해 코드를 **간결하고 이해하기 쉽게** 만들며,  
  - 복잡한 시스템을 **더 높은 수준의 개념으로 표현**할 수 있게 합니다.

    - **공통된 특징 추출**
    - **불필요한 세부 구현 감춤**
    - **코드의 간결성 및 가독성 향상**
    - **복잡한 구조를 단순하게 표현**




















