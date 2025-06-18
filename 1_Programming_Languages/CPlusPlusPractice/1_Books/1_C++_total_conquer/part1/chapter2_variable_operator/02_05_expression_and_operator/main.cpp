#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<4> a ("0101");
    bitset<4> a_right_shift_1 = a >> 1;
    cout << a << endl;                // output: 0101
    cout << a_right_shift_1 << endl;  // output: 0010

    bitset<4> b(string("1101"));             // 4비트 이진수 생성
    bitset<4> b_right_shift_1 = b >> 1;      // 오른쪽으로 1칸 시프트
    cout << b << endl;              // 출력: 1101
    cout << b_right_shift_1 << endl; // 출력: 0110

    bitset<4> c ("0101");
    bitset<4> c_left_shift_1 = c << 1;
    cout << c << endl;               // output: 0101
    cout << c_left_shift_1 << endl;  // output: 1010
}