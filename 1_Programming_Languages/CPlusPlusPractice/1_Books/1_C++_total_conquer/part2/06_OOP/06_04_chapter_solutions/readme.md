# 06-03: 되새김 문제

## 문제 1: 객체지향 프로그래밍 이외 프로그래밍 패러다임
비구조적 프로그래밍과 절차적 프로그래미의 장/단점을 비교하고
각 패러다임을 대표하는 언어가 무엇인지 기술해 보세요.

## ✅ 문제 1: 객체지향 프로그래밍 이외의 프로그래밍 패러다임 비교

### 🔷 1. 비구조적 프로그래밍 (Unstructured Programming)

#### 📌 개요
- 프로그램의 흐름을 **`goto` 문** 등으로 제어
- 흐름 제어가 자유롭지만 **복잡성**이 증가함

#### ✅ 장점
- 초기 컴퓨터 시대에 **하드웨어에 가까운 제어**가 가능
- 컴파일러가 간단했고 **빠른 개발**이 가능함

#### ❌ 단점
- **스파게티 코드** 발생: 코드가 복잡하고 이해/유지보수가 어려움
- 재사용성과 모듈화가 떨어짐
- 버그 발생 시 **디버깅이 매우 어려움**

#### 💻 대표 언어
- `Assembly`  
- 초기 버전의 `BASIC`  
- 초기 버전의 `Fortran`

---

### 🔷 2. 절차적 프로그래밍 (Procedural Programming)

#### 📌 개요
- 프로그램을 **절차(함수)**로 나누어 작성
- **순차, 조건, 반복** 흐름 제어 구조를 사용함

#### ✅ 장점
- 논리적인 **흐름을 따라가며 코드 구성**이 쉬움
- 함수(서브루틴) 단위로 **모듈화 가능**
- 프로그램이 **간결하고 구조적**

#### ❌ 단점
- 데이터와 함수가 **분리되어 있어 캡슐화가 어려움**
- 대형 프로젝트에서 **재사용성과 유지보수에 한계**
- **상속, 다형성 등 확장성 부족**

#### 💻 대표 언어
- `C`  
- `Pascal`  
- 구조화 이후 버전의 `Fortran`  
- `Python` (초기 사용 방식)

---

### 📊 요약 비교

| 항목 | 비구조적 프로그래밍 | 절차적 프로그래밍 |
|------|--------------------|------------------|
| **구조화 수준** | 거의 없음 (`goto` 사용) | 함수 단위로 구조화 |
| **유지보수성** | 매우 낮음 | 중간 수준 |
| **코드 흐름** | 제어문 중심, 비선형 | 순차, 조건, 반복 |
| **장점** | 빠른 개발, 낮은 추상화 | 가독성 좋음, 모듈화 용이 |
| **단점** | 스파게티 코드, 디버깅 어려움 | 대규모 확장 어려움 |
| **대표 언어** | Assembly, BASIC(초기) | C, Pascal, Fortran |

---

## 문제 2: 객체 관계 `is-a`, `has-a`
객체 간에 `is-a`, `has-a`관계를 잘 생각하면서 진공 청소기의 부품과 다양한 진공 청소기(무선, 유선 등)을 설계해서 클래스 다이어그램으로 표현해 보세요.

- 답변 2

```cpp
#include <iostream>
using namespace std;

// VacuumCleaner 클래스
class VacuumCleaner {
protected:
    string color;
    int moving_speed;
    bool is_remote;

public:
    VacuumCleaner(string given_color, int speed, bool remote) {
        color = given_color;
        moving_speed = speed;
        is_remote = remote;
        }

    void operate() {
        cout << color << " 청소기가 "
             << moving_speed << " 속도로 작동합니다. ";
        if (is_remote)
            cout << "(유선)" << endl;
        else
            cout << "(무선)" << endl;
    }
};

// WirelessVacuum is-a VacuumCleaner
class WirelessVacuum : public VacuumCleaner {
public:
    WirelessVacuum(string c, int s)
        : VacuumCleaner(c, s, false) {} 

    void charge() {
        cout << "🔋 무선 청소기 충전 중..." << endl;
    }
};

// WiredVacuum is-a VacuumCleaner
class WiredVacuum : public VacuumCleaner {
public:
    WiredVacuum(string c, int s)  
        : VacuumCleaner(c, s, true) {}

    void locateWire() {
        cout << "🔌 유선 청소기 전원선 정리 중..." << endl;
    }
};

int main() {
    WirelessVacuum wireless("빨간색", 12);
    WiredVacuum wired("파란색", 8);

    wireless.operate();
    wireless.charge();

    cout << "------" << endl;

    wired.operate();
    wired.locateWire();

    return 0;
    }
```

## 문제 3 다형성 이해하기
다형성을 적용할 수 있는 클래스 예를 3개 만들고 어떤 기능에 다형성을 적용할지 정해 보세요.

답변 3:
```cpp
// 부모 클래스 Animal
class Animal {
    // 자식 클래스에서 접근할 수 있도록 protected 사용
    protected: 
        string name;
        int leg_number;
        bool has_wing;
        
    public:
        Animal(string given_name, int given_leg_number, bool given_wings) {
            name = given_name;
            leg_number = given_leg_number;
            has_wing = given_wings;        
        }
        
        // 가상 함수 → 다형성의 핵심
        virtual void is_fed(){
            cout << name << " is fed." << endl;
        }
        
        virtual ~Animal() {} //소멸자도 virtual
};

// Cat 클래스 (Animal을 상속)
class Cat : public Animal {
    public:
        // 생성자 추가
        Cat(string given_name) : Animal(given_name, 4, false) {}   
    
        void is_fed() override{
            cout << name << " eats fish." << endl;        
        }
};

// Dog 클래스 (Animal을 상속)
class Dog : public Animal {
    public:
        // 생성자 추가
        Dog(string given_name) : Animal(given_name, 4, false) {}
    
        void is_fed() override{
            cout << name << " eats meat." << endl;
        }
};

// main 함수
int main() {
    Cat* c1 = new Cat("Nabi");
    Dog* d1 = new Dog("Choco");
    
    c1 -> is_fed(); // Nabi easts fish.
    d1 -> is_fed(); // Choco easts meat.
    
    delete c1;
    delete d1;
    
    return 0;
}
```

## 문제 4: 객체지향 설계 #1
[문제 2]에서 설계한 진공 청소기 최상위 부모 클래스를 문법에 맞게 C++로 작성해 보세요.

답변 4:
```cpp
class VaccumCleaner{
    // 자식 클래스에서 접근할 수 있도록 protected 사용
    protected:
        string machine_name;
        int price;
        bool has_wire;
        int motor_clean_speed;
        
    public:
        // 생성자
        VaccumCleaner(string given_name, int given_price, bool given_wire, int given_speed){
            machine_name = given_name;
            price = given_price;
            has_wire = given_wire;
            motor_clean_speed = given_speed;
        }
};

// WiredCleaner 클래스 (VaccumCleaner 상속)
class WiredCleaner : public VaccumCleaner {
    // 생성자
    public:
    WiredCleaner(string given_name, int given_price, int given_speed) 
        :  VaccumCleaner(given_name, given_price, true, given_speed) {}  
}; 

int main(){
    // 객체 생성 시 C++에서는 위치 기반 인자 전달
    WiredCleaner wired1("WireMagic", 70, 12);  
}
```


## 문제 5: 객체지향 설계 #2
`is-a`, `has-a`와 객체 간에 접근 제어를 고민해서 주변의 특정 대상을 객체로 모델링해 보세요.

답변 5:
```cpp
class Animal {
    // has a
    protected:
        string name;
        int age;
        int number_legs;
    
    public: 
        Animal (string given_name, int given_age, int given_legs){
            name = given_name;
            age = given_age;
            number_legs = given_legs;
        }
};

// is-a : polymorphism으로 구현
class Cat : public Animal {
    public: 
        Cat (string given_cat_name, int given_cat_age, int given_legs) : Animal(given_cat_name, given_cat_age, 4) {}
};
```


