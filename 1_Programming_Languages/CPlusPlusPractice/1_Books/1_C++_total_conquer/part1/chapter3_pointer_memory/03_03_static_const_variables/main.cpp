/* pg. 131: static 변수 활용 시작
#include <iostream>

void func() {

    int a = 10;
    static int b = 10;

    a++;
    b++;

    std::cout << "a: " << a << " b: " << b << std::endl;
}

int main()
{
    func();
    func();
    func();
    func();
    func();
}

pg. 131: static 변수 활용 끝 */

// pg.133: static 변수를 이용한 아이디 생성 함수 만들기. 시작
#include <iostream>

int getNewID()
{
    static int ID = 0;
    return ++ID;
}

int main()
{
    std::cout << getNewID() << std::endl;
    std::cout << getNewID() << std::endl;
    std::cout << getNewID() << std::endl;
    std::cout << getNewID() << std::endl;
    std::cout << getNewID() << std::endl;
}






// pg.133: static 변수를 이용한 아이디 생성 함수 만들기. 끝
