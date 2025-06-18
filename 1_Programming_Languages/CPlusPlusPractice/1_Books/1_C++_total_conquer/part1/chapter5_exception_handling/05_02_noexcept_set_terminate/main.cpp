// pg.191: noexcept로 명시된 함수에서 예외 던지기. 시작
/*
#include <iostream>
using namespace std;

// noexcept 선언으로 예외를 던지지 않음을 명시
void real_noexcept() noexcept
{
    cout << "real_noexcept" << endl;
}

// noexcept로 명시된 함수 안에서 예외 발생
void fake_noexcept() noexcept
{
    cout << "fake_noexcept" << endl;
    throw 1; // 정식 형식 예외 발생
}

int main()
{
    real_noexcept();

    try
    {
        fake_noexcept();
    }

    catch (int exec)
    {
        cout << "catch " << exec << endl;
    }
} */
// pg.191: noexcept로 명시된 함수에서 예외 던지기. 끝

// page.192: 예외 처리 실패에 대응하기. 시작
#include <iostream>
#include <cstdlib>
using namespace std;

// 종료 처리 함수
void myTerminate() {
    cout << "myTerminate is called." << endl;
    exit(-1); // 프로그램을 비정상으로 종료
}

int main(void) {
    // 종료 처리 함수 지정
    set_terminate(myTerminate);

    // 예외 발생
    throw 1;

    // 그러나 예외를 받아줄 catch 없음

    // 비정상으로 종료해야 하지만, 미리 set_terminate()로 지정한  myTerminate 함수 실행


    return 0; // throw로 예외를 던졌으므로 실행되지 않음
}





// page.192: 예외 처리 실패에 대응하기. 끝