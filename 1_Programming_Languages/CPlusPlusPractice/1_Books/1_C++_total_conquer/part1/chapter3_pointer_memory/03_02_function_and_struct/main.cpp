/* pg 122 : 포인터 변수를 매개변수를 사용하기
#include <iostream>

void change_sign(int val)
{
    val = - val;
}

void change_sign_by_pointer(int *val)
{
    *val = -(*val);
}

int main()
{
    int a = 3;
    int b = 3;

    change_sign(a);
    std::cout << a << std::endl;  // output: 3, expected: -3

    change_sign_by_pointer(&b);
    std::cout << b << std::endl; // output: -3, expected: -3
}
pg. 122 포인터 변수를 매개변수로 사용하기 END*/

// page 123: 배열을 매개변수로 사용하기 시작
/*
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
*/
//page 123: 배열을 매개변수로 사용하기 끝


// pg.117: 구조체를 매개변수로 사용하기 시작
/*
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
*/
// pg.117: 구조체를 매개변수로 사용하기 끝

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