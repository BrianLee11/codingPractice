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
