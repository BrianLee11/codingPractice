// C++ 에서는 isostream header 파일을 불러와 입출력을 처리할 수 있습니다.
// C++ 언어의 표준 입력과 출력은 iostream에 정의되어 있는 cin, cout을 사용합니다.
// C++ 언어에서도 C 언어에서처럼 scanf, printf로 입출력을 할 수는 있습니다. 다만, 표준은 아닙니다.
/*
 * 구분          C                  C++
 * 헤더 파일     stdio.h            iostream
 * 입력문        scanf              cin
 * 출력문        printf             cout
 */


// C++ 에서 입출력 코드를 어떻게 작성하는지 알아보겠습니다.
#include <iostream>

int main() {
    // 변수 선언
    int i, j;
    std::cout << "Enter number_1: "; // 문자열 "Enter number 1: " 출력
    std::cin >> i;                   // 사용자에게 정수를 입력받아, 변수 i에 저장

    std::cout << "Enter number_2: "; // 문자열 "Enter number 2: " 출력
    std::cin >> j;                   // 사용자에게 정수를 입력받아, 변수 j에 저장

    std::cout << "num_1 + num2 = " << i + j << std::endl; // 두 수의 합 출력

    return 0;
}

/* 실행 결과
 * Enter num_1: 10
 * Enter num_2: 15
 * num_1 + num2_2 = 25
 */




