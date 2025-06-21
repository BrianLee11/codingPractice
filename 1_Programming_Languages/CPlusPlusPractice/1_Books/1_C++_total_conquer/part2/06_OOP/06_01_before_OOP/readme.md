# 06-01: 객체지향 이전의 프로그래밍 패러다임
- 비구조적 프로그래밍 개념 이해하기
- 절차적 프로그래밍 개념과 한계 알아보기

## 들어가며
- `프로그래밍 패러다임 programming paradigm`은 프로그램을 어떤 절차와 구조로 만들 거인지에 대한 스타일이나 접근 방법을 나타냅니다.
집을 짓는 방식이 여러 가지인 것처럼 프로그래밍 패러다임도 여러 가지가 있으며 복잡도와 필요성에 따라 변화하고 발전했습니다.

- 각 패러다임은 언어가 지원하는 기능, 코드의 구조, 문제 해결 접근 방식 등에 차이가 있습니다.

## 비구조적 프로그래밍 non-structured programming
- `코드를 구조화하지 않고 작성하는 방법`을 말합니다.
- 비구조적 프로그래밍으로 작성한 코드는 첫 번째 줄부터 마지막 줄까지 차례대로 실행되며, 
- 코드의 흐름을 이용하는 `goto`문을 사용하는 특징이 있습니다.
- 대표적인 비구조적 프로그래밍 언어로는 `어셈블리어 assembly language`, 초창기의 `포트란 fortran`이 있습니다.

예제: 비구조적 프로그래밍 언어의 대표 사례인 X86
- 코드에서 보듯 `비구조적 프로그래밍은 명령어를 차례대로 작성`합니다.

```
        global_start
        section.text
_start: mov rax, 1             ; 쓰기를 위한 시스템 호출
        mov rid, 1 
        mov rsi, message       ; 출력 물자열 주소
        mov rdx, 13            ; 바이트 크기 
        (... 생략 ...)
        syscall                ; 종료를 위한 시스템 기능 실행
        section.data
message: db "Hello, World", 10
```
- 비구조적 프로그래밍 언어는 컴퓨터를 사용하기 시작할 즈음에 등장한 기계어와 유사한 형태로 만들어졌습니다.
  - 한눈에 봐도 최근 프로그래밍 언어와는 많이 다른 것을 알 수 있습니다.
  - 요즘은 이런 언어를 많이 사용하지 않지만, `현대 프로그래밍 언어가 동작할 수 없는 환경이나 몇 가지 동작만 허용하는 단순한 환경에서는` 이런 언어를 사용하기도 합니다.

## 절차적 프로그래밍 procedural programming
- 비구조적 프로그래밍과는 다르게 **소스 코드를 여러 부분으로 나눠서 활용하는 패러다임으로, 프로시저를 이용해 구조화하는 방식**을 발합니다.
  - procedure는 `일련의 코드 묶음`을 말하며, 보통 `함수`를 생각하면 됩니다.
  - 절차적 프로그래밍의 대표 언어는 `C`이며 `코볼Cobol`, `포트란fortran`도 있습니다.

- 절차적 프로그래밍에서는 `코드의 논리 구조를 모듈화 modulation`할 수 있습니다.
  - 모듈화하면 `같은 기능을 수행하는 코드를 다시 작성하지 않아도 재사용`할 수 있으며, 
  - 라이브러리처럼 `누군가가 만들어 놓은 기능을 사용하면 프로그램을 더 쉽게 개발`할 수 있습니다.
  - 또한 `구조화된 코드는 다른 사람이 쉽게 읽을 수 있는 장점`도 있습니다.

### 절차적 프로그래밍으로 얻을 수 있는 효과
- 자동차의 adaptive cruise control 기능을 절차적 프로그래밍으로 구현하는 상황을 가정하여
- 절차적 프로그래밍으로 얻을 수 있는 효과를 알아보겠습니다.

## 🚗 제어 로직 개요

### 1. 기능·함수 매핑

| 기능 설명                     | 함수 이름 (`snake_case`)    | 주요 입력 변수 |
|-------------------------------|-----------------------------|----------------|
| 엔진 출력(토크) 조정          | `acceleration_adjusting()`  | `target_speed`, `current_speed` |
| 가속 페달 신호 생성           | `acceleration_output()`     | ― *(내부 센서 기반)* |
| 브레이크 제어                 | `pushing_brake()`           | ― *(내부 센서 기반)* |
| 앞차와의 거리 계측            | `inquiring_range()`         | ― *(레이더·LIDAR)* |
| 주행 중 현재 속도 계측        | `inquiring_current_speed()` | ― *(휠 센서)* |
| 조건에 맞는 목표 속도 산출    | `calculating_fit_speed()`   | `current_speed`, `front_range` |

> **Tip**  
> 함수 이름은 “동사 + 목적어” 형태로 지어야 모듈 역할이 명확해집니다.

---

### 2. 변수·역할 매핑

| 구분          | 변수 이름                | 사용되는 기능(함수)          |
|---------------|--------------------------|-----------------------------|
| 제어 주기(ms) | `acceleration_adjusting_period` | `acceleration_adjusting()` |

```cpp
// 전역 변수들
int user_target_speed;
int acceleration_adjusting_period;

// 전역 함수들
void acceleration_output();
void pushing_break();
int inquiring_current_speed();
int inquiring_range();
int calculating_fit_speed(int range, int original_target_speed);
void acceleration_adjusting(int target_speed, int current_speed) {
    if (target_speed == current_speed) {
        return;
    }
    if (target_speed > current_speed) {
        acceleration_output();
        return;    
    }
    pushing_break();
}

// 메인 소스 코드
void main(){
    int range, current_speed;
    
    while (do_cruise){
        range = inquiring_range();
        current_speed = inquiring_current_speed();
        acceleration_adjusting(calculating_fit_speed(range, user_traget_speed), current_speed);
        sleep(acceleration_adjusting_period);
    }
    return 0;
}
```
- `어떤 기능을 프로시저 단위로 나누어 구현하면 기능을 변경해야 할 때 프로그램의 전체 흐름은 그대로 두고 해당 프로시저만 수정하면` 됩니다.
- 이러한 특징으로 인해 절차적 프로그래밍으로 작성한 코드는 `프로그램의 중심 흐름을 담당하는 코드`와 `프로시저를 구현하는 코드`로 `나뉩니다`
- 프로시저는 또 다른 프로시저를 호출하는 형태로 구현하기도 합니다.
- 프로시저를 직접 만들거나 누군가가 이미 만들어 놓은 프로시저를 가지고 레고 블록을 조립하듯이 적절하게 배치하고 재사용합니다.

### 절차적 프로그래밍의 한계
- 프로그램의 규모가 커지면 흐름 코드가 복잡해지며 프로시저도 대폭 늘어납니다.
  - 그만큼 프로시저 간에 관계도 복잡해 집니다.
- 절차적 프로그래밍에서는 `프로시저의 다층 구조를 표현할 방법이 없습니다`. 
  - 이런 문제를 해결하려면 `소스 파일을 논리적인 단위로 나누고 라이브러리로` 만들어야 합니다.
  - 그리고 `프로그램의 전체 논리 구조를 설명하는 문서를 별도로 만들어 배포`해야 합니다.
- 이러한 노력에도 불구하고 프로젝트에 참여하는 모든 개발자가 프로그램의 논리 구조를 정확하게 이해하지 못하면 `직접 접근하지 말아야 할 프로시저에 접근할 수 있습니다`.
  -  특히 `전역 변수에 접근을 막을 방법이 없습니다`. 
  - 이런 한계점은 프로그램에 치명적인 문제로 이어질 수 있습니다.

```cpp
// 전역 변수들
// 문제 1: 접근을 제어하지 못하고 정보가 공개됨
int user_target_speed;
int acceleration_adjusting_period;

// 전역 함수들
// 문제 2: 프로시저 간에 논리적 계층 구조가 존재하지만 관련 코드를 모두 확인하기 전에는 알아채기 어려움
void acceleration_output();
void pushing_break();
int inquiring_current_speed();
int inquiring_range();
int calculating_fit_speed(int range, int original_target_speed);
void acceleration_adjusting(int target_speed, int current_speed) {
    if (target_speed == current_speed) {
        return;
    }
    if (target_speed > current_speed) {
        acceleration_output();
        return;    
    }
    pushing_break();
}

// 메인 소스 코드
void main(){
    int range, current_speed;
    
    while (do_cruise){
        range = inquiring_range();
        
        // 문제 3: 지역 변수가 아닌 전역 변수를 변경
        user_target_speed = inquiring_current_speed();
        
        current_speed = inquiring_current_speed();
        acceleration_adjusting(calculating_fit_speed(range, user_traget_speed), current_speed);
        
        // 문제 4: 하위 프로시저를 직접 호출
        acceleration_output(); 
        sleep(acceleration_adjusting_period);
    }
    return 0;
}
```
### 절차적 프로그래밍에서 발생할 수 있는 문제점들 

- 문제 1: `전역 함수 사례`. 
    - `모든 곳에서 해당 프로시저에 접근할 수 있다`는 문제
      - 즉, `프로시저 간에 관계를 고려해 접근을 제어할 수 없습니다`.
    - 소스 코드가 복잡해 보이는 문제도 있지만, `별도의 파일로 나누고 라이브러리로 만들더라도 프로시저의 정보가 노출`되는 것에는 변함이 없습니다.

- 문제 2: `논리 구조가 복잡할 때는 프로시저 간의 계층을 파악하기가 어렵습니다.`
  - acceleration_adjusting 함수에는 내부적으로 호출하는 프로시저가 존재
    - 하지만, 논리 구조가 복잡할 때는 프로시저 간의 계층을 파악하기가 어렵다.
    - 따라서 논리 구조를 정확하게 인지하지 못하면, 4처럼 acceleration_output 함수를 중복해서 호출하는 실수를 범할 수 있습니다.

- 문제 3: `절차적 프로그래밍에서는 프로시저에 필요한 데이터를 인자로 전달하거나 전역 변수로 저장`해야 합니다.
  - 이는 프로시저의 매개변수가 많아지는 문제점을 야기하기도 하지만,
  - 더 큰 문제는 `전역 변수를 사용하는 일이 많아지면서 중요한 변수가 엉뚱한 곳에서 변경될 가능성`도 커진다는 점입니다.

- 문제 4: `절차적 프로그래밍으로 작성한 코드는 여러 개의 프로시저를 하나의 흐름으로만 구성해야`
  - `다층 구조를 논리적으로 모델링하기가 매우 복잡`하며
  - `만약 확장이 필요하면 코드 전체를 수정해야` 합니다.

- 결론: 절차적 프로그래밍의 한계를 요약하면 다음과 같습니다.
  - 프로시저가 가진 `논리적 다층 구조`를 프로그래밍 내부에서 `표현하는 데 한계`가 있다.
  - `불필요한 프로시저를 호출`하거나 `전역 변수를 수정`할 수 있다.
    - 이때 프로그램 동작에 치명적인 영향을 줄 수 있다.

- 이러한 한계 때문에 절차적 프로그래밍은 `여러 명이 큰 규모의 프로젝트를 진행할 때에는 적절하지 않습니다.`
  - 따라서 이를 보완하는 프로그래밍 패러다임이 등장했으며
  - 그중 하나가 바로 객제지향 프로그래밍입니다.

## 3분 퀴즈: 절차적 프로그래밍의 한계를 기술했습니다. 
- 질문1: 프로그래밍 대상을 _____로(으로) 표현하는 것이 매우 복잡하다.
- 질문2: 프로시저가 가진 논리적 다층 구조를 프로그래밍 내부에서 표현하는데 _____이(가) 있다.
- 질문3: 불필요한 1) _____을(를) 호출하거나 2) _____ 을(를) 수정할 수 있다. 이때 프로그래밍 동작에 치명적인 영향을 줄 수 있다.

- 답변: 1. 논리 구조인 프로시저, 2. 한계, 3. 1)프로시저, 2)전역 변수

