// pg. 178 - 9: try, throw, catch 예제 시작

/*
#include <iostream>
using namespace std;

int main() {

    try
    {
        int input;

        cout << "Enter an integer: ";
        cin >> input;

        // 첫 번째 throw
        if (input > 0) // 조건: 입력받은 숫자아 양수이면
        {
            cout << "throw 1 " << endl;
            throw 1; // 정수이므로 catch (int a) 에 해당됩니다. (정수 형식 예외)
        }

        // 두 번째 throw
        if (input < 0) // 조건: 입력받은 숫자가 음수이면
        {
            cout << "throw -1.0f" << endl;
            throw -1.0f; // 예외 1.0f 발생 (부동소수점 형식 예외)
        }

        // 세 번째 throw
        if (input == 0)  // 조건: 입력받은 숫자가 0이면
        {
            cout << "throw Z" << endl;
            throw 'Z';  // 예외 Z 발생 (문자 형식 예외)
        }


    } // end of try

        // catch 시작
        catch (int a) // 정수 형식 예외 받기
        {
            cout << "catch " << a << endl;
        }

        catch (float b) // 부동 소수점 형식 예외 받기
        {
            cout << "catch " << b << endl;
        }

        catch (char c) // 문자 형식 예외 받기
        {
            cout << "catch " << c << endl;
        }

    return 0;
} */

// pg. 178 - 9: try, throw, catch 예제 끝

// pg.179: 예외를 던졌지만, 받아 주는 catch 문이 없다면? 시작
/*
#include <iostream>
using namespace std;

int main()
{
    int integer = 1;

    try {
        if (integer == 1)
        {
            throw 1;
        }

    }

    catch (char c)
    {
        cout << "catch";
    }

    return 0;
}
*/
// pg.179: 예외를 던졌지만, 받아 주는 catch 문이 없다면? 끝

// pg.180: 처리되지 않은 모든 예외 받기. 시작
/*
#include <iostream>
using namespace std;

int main()
{
    try {
        int n;

        cout << "Enter n: ";
        cin >> n;

        if (n > 0) {
            throw 1; // integer 1
        }

        if (n < 0) {
            throw -1.0f; // throw error -1.0f floating
        }

        if (n == 0) {
            throw 'Z'; // throw error Z character
        }
    }

    // 정수 integer 에러를 받아 줍니다.
    catch (int a) {
        cout << a << endl;
    }

    // 그 밖의 모든 다른 에러들을 받아 줍니다.
    catch (...) {
        cout << "catch all" << endl;
    }
}

*/
// pg.180: 처리되지 않은 모든 예외 받기. 끝

// pg. 181: 처리되지 않은 모든 예와 받기. catch(...) 활용. 시작
/*
#include <iostream>
using namespace std;

int main()
{
    try
    {
        int integer;
        cout << "Enter an integer: ";
        cin >> integer;

        if (integer == 0)
        {
            throw 1;
        }

        if (integer > 0)
        {
            throw -1.0f;
        }

        if (integer == 0)
        {
            throw 'Z';
        }
    }

    catch (int a)
    {
        cout << " a " << endl;
    }

    catch (...)
    {
        cout << "all other errors are here" << endl;
    }

    return 0;
}
*/
// pg. 181: 처리되지 않은 모든 예와 받기. catch(...) 활용. 끝

// pg.182: 예외가 전달되는 동작 확인하기. 시작
/*
#include <iostream>
using namespace std;

void func_throw() {
    cout << "func_throw()" << endl;
    cout << "throw -1" << endl;
    throw -1;
    cout << "after throw -1" << endl;
}

int main() {

    try {
        func_throw();

    }
    catch (int integer) {
        cout << "catch " << integer << endl;
    }

    return 0;
}
*/
// pg.182: 예외가 전달되는 동작 확인하기. 끝
/*
#include <iostream>
using namespace std;

void func_throw(){
    cout << "func_throw() is called" << endl;
    throw -1;
    cout << "after func_throw()";
}


void func2() {
    cout << "func2() is called" << endl;
    func_throw();
    cout << "after func2()";
}

void func1() {
    cout << "func1() is called" << endl;
    func2();
    cout << "after func1()";
}

int main() {

    cout << "Inside the main()" << endl;

    try {
        func1();
    }
    catch (int exec) {
        cout << endl;
        cout << "catch " << exec << endl;
    }
}
*/

// pg.186: assertion을 이용한 예외처리
// assert(조건);
/*
#include <iostream>
#include <cassert>
using namespace std;

void print_number(int *_pt_int) {
    assert(_pt_int != NULL);
    cout << *_pt_int << endl;
}

int main() {
    int a = 100;
    int *b = NULL;
    int *c = NULL;

    b = &a;
    print_number(b);

    print_number(c);


    return 0;
}
*/



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

  catch (int exc)
  {
   cout << "catch " << exe << endl;
  }

}
