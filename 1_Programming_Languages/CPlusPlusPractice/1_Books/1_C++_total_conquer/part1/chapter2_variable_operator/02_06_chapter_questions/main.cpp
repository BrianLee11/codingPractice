// 1번: C++ 표준 입출력
// #include <iostream>
// #include <string>

// 2번: 데이터 형식
#include <iostream>

int main() {
    /* 1번: C++ 표준 입출력
    std::string name("NAME");  // 문자열 변수 초기화

    std::cout << "Enter your name: ";  // 사용자에게 입력 요청 메시지 출력
    std::cin >> name;                  // 사용자로부터 문자열 입력 받기
    std::cout << "Hi! You are " << name << "! Welcome!" << std::endl;  // 환영 메시지 출력

    return 0;
    */

    // 2번: 데이터 형식
    float float_variable = 0.5f;
    std::cout << "float_variable = " << float_variable << std::endl;

    unsigned int unsigned_variable = 5u;
    std::cout << "unsigned_variable = " << unsigned_variable << std::endl;

    long long_variable = 5L;
    std::cout << "long_variable = " << long_variable << std::endl;

    return 0;
}