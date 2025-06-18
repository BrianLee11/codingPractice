//#include <iostream>
//using namespace std;

// pg. 52
// #include <io.h>
// #include <fcntl.h>

// pg. 54: 정수형 크기 출력하기
// #include <iostream>
// using namespace std;

// pg. 56: 부동 소수점 출력하기
// #include <iostream>
// using namespace std;

// pg.57: 부동 소수점의 최대 유효 자릿수만큼 출력하기
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    /*  pg.50: 아스키 코드 출력하기
    cout << "아스키 코드 출력하기 [32 ~ 126]:\n";
    for (char i = 32; i<= 126; i++) // 32부터 126까지 1씩 증가하며 반복
        {
        // 아스키 코드를 출력할 때, 공백을 넣고 16개마다 줄 바꾸기
        cout << i << ((i % 16 == 15)? '\n' : ' ');
        }
    return 0;
    */

    /* pg.52: 다양한 언어로 이사말 출력하기
    // 한글 와이드 문자열 선언
    wchar_t message_korean[] = L"반갑다 세계야!";

    // 콘솔 출력 모드를 유니코드(UTF-16)로 설정
    _setmode(_fileno(stdout), _O_U16TEXT);

    // 와이드 문자열 출력
    wcout << message_korean << endl;
    */

    /* pg.54: 정수형 크기 출력하기
    cout << "short : " << sizeof(short) << " bytes" << endl;
    cout << "unsigned short : " << sizeof(unsigned short) << " bytes" << endl;
    cout << "int : " << sizeof(int) << " bytes" << endl;
    cout << "unsigned int : " << sizeof(unsigned int) << " bytes" << endl;
    cout << "long : " << sizeof(long) << " bytes" << endl;
    cout << "unsigned long : " << sizeof(unsigned long) << " bytes" << endl;
    cout << "long long : " << sizeof(long long) << " bytes" << endl;
    cout << "unsigned long long : " << sizeof(unsigned long long) << " bytes" << endl;

    return 0;
    */
    /* 결과:
        short : 2 bytes
        unsigned short : 2 bytes
        int : 4 bytes
        unsigned int : 4 bytes
        long : 4 bytes
        unsigned long : 4 bytes
        long long : 8 bytes
        unsigned long long : 8 bytes
     */

    /* pg. 56: 부동소수점 출력하기
    cout << 0.97654321f << endl;
    cout << 987654.321f << endl;
    cout << 9876543.21f << endl;
    cout << 0.00000987654321f << endl;
    cout << 0.00000000000987654321f << endl;

    return 0;
    */

    /* 결과
    * 0.976543
    987654
    9.87654e+06
    9.87654e-06
    9.87654e-12
     */

    float float_value = 9.87654321f;
    double double_value = 9.87654321987654321;
    long double long_double_value = 9.87654321987654321l;

    cout << "float: " << sizeof(float) << " bytes" << endl;
    // 유효 자릿수만큼 정밀도 조정
    cout << "float_value: " << setprecision(numeric_limits<float>::digits10 + 1) << float_value << endl << endl;

    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "double_value: " << setprecision(numeric_limits<double>::digits10 + 1) << double_value << endl << endl;

    cout << "long_double: " << sizeof(long double) << " bytes" << endl;
    cout << "long_double_value: " << setprecision(numeric_limits<long double>::digits10 + 1) << long_double_value << endl << endl;

    return 0;

    /* 실행 결과
    * float: 4 bytes
    float_value: 9.876543

    double: 8 bytes
    double_value: 9.876543219876543

    long_double: 16 bytes
    long_double_value: 9.87654321987654321
     *
}