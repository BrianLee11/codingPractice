// pg.149: 문제 1. 포인터 활용
/*
#include <iostream>

int main() {
    int *int_arrays= new int[5]; // 크기가 5인 정수 배열을 동적으로 할당. 이를 가리키는 포인터를 선언

    for (int i = 0; i < 5; i++)  // 동적으로 할당한 배열에 1부터 5까지의 값을 저장하세요,.
    {
        int_arrays[i] = i + 1;
        std::cout << int_arrays[i] << std::endl; // 출력하세요.
    }

    delete[] int_arrays; //메모리 해제
}
*/


/*## 문제 2: 구조체 활용
- 5가지 속성을 가진 몬스터라는 구조체를 만들어 보세요.
- 해당 구조체 형식의 변수를 인자로 받아 출력하는 함수도 만들어 보고, 잘 동작하는지 main 함수에서 테스트해 보세요.
 *
 */

#include <iostream>

struct Monster
{
    std::string name;
    int age;
    float height;
    float weight;
    bool alive;
};

// Monster 구조체 형식의 변수를 인자로 받아 출력하는 함수
void printMonster(Monster monster)
{
    std::cout << "Name: " << monster.name << std::endl;
    std::cout << "Age: " <<monster.age << std::endl;
    std::cout << "Height: " <<monster.height << std::endl;
    std::cout << "Weight: " <<monster.weight << std::endl;
    std::cout << "Alive: " <<monster.alive << std::endl;
}

int main()
{
    // 구조체 instance 하나 만들어 봅니다.
    Monster darkSnake = {
        "Dark Snake",
        34,
        234,
        120,
        true
    };

    // 테스트
    printMonster(darkSnake);
}


