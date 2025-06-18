/* 소속을 알리는 네임스페이스
네임스페이스 namespace 소속을 지정해 주는 역할을 합니다.

표준(standard) 라이브러리를 의미하는 std
std::cin 와 std::cout 에서 std:: 는 std라는 네임스페이스에 접근할 때 쓰는 표현입니다.
std 에는 C++ 흔히 사용하는 여러 가지 함수와 클래스, 객체, 유틸리티가 정의된 네임스페이스입니다.

네임스페이스는 내부 식별자(identifier) 형식, 함수, 변수 등에 범위를 부여해
여러 라이브러리를 포함할 때 이름이 충돌하는 것을 방지하려고 사용합니다.
코드의 양이 늘거나 다른 사람이 만든 코드를 가져다 쓸 때 이름이 같은 함수를 사용할 수 있습니다.
C++ 에서는 이를 구분할 수 있게 같은 이름이라도 소속된 네임스페이스가 다르면 서로 다른 것으로 취급합니다.

현실적으로는 입출력문 앞에 매번 std::를 붙이는 것이 번거롭습니다.
그래서, 소스 앞부분에 using namespace std 코드를 작성해 생략할 수 있습니다.
이 선언문은 "cin, cout 등이 사용될 때는 무조건 std에 속한 것을 호출한다"라고 미리 선언하는 것입니다.

네임스페이스를 사용하는 예를 보겠습니다.
다음 코드에서 using 문으로 std 네임스페이스 사용을 선언하고
cout, cin, endl 등을 사용할 때 소속을 생략합니다.
*/

#include <iostream>
using namespace std; // 네임스페이스 사용 선언. 선언 네임스페이스는 std (standard)

int main() {
    int i, j;

    cout << "Enter num_1: "; // std::cout 대신 cout으로 충분. 이는 using namespace std로 선언되었기 때문
    cin >> i;

    cout << "Enter num_2: ";
    cin >> j;                // 마찬가지로 std::cout 대신 cin으로 충분.

    cout << "num_1 + num2: " << i +j << endl;

    return 0;
}


