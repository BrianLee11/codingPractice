// pg.60 지역 범위가 적용된 변수
#include <iostream>
using namespace std;

// pg.60 지역 범위가 적용된 변수
// 함수 설정
void print() {
    // 함수 내부의 지역 변수
    int value = 10;
    cout << "print 함수 내부에서의 지역 변수 value: " << value << endl;
}

int main() {
    //  pg.60 지역 범위가 적용된 변수
    int value = 5;
    cout << "main 함수 내부에서의 지역 변수 value: " << value << endl;
    print();  // output: 5

    // print 함수 호출 후에도 main 함수의 value에 영향을 주지 않음
    cout << "다시 main 함수 내부에서의 지역 변수 value: " << value << endl;

    return 0;

}