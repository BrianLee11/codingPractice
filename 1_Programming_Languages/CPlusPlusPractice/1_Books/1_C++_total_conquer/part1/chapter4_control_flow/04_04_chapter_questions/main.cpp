
/* pg. 174: 돼새김 문제 Q1: if문 활용하기

#include <iostream>
using namespace std;


int main() {

    int user_integer_input = 0;

    cout << "Enter a number: ";
    cin >> user_integer_input;

    if (user_integer_input > 0 || user_integer_input == 0) {
        cout << "Positive integer input!" << endl;
    }
    else {
        cout << "Negative integer input!" << endl;
    }

}
pg.174 되새김 문제 Q1. if 문 활용하기 */

/* Q2: switch 문 활용하기 시작
#include <iostream>
using namespace std;

int main()
{
    int user_input_integer = 0;

    cout << "Insert a number from 1 to 7, inclusive: ";
    cin >> user_input_integer;

    switch (user_input_integer)
    {
        case 1:
            cout << "Sunday" << endl;
            break;

        case 2:
            cout << "Monday" << endl;
            break;

        case 3:
            cout << "Tuesday" << endl;
            break;

        case 4:
            cout << "Wednesday" << endl;
            break;

        case 5:
            cout << "Thursday" << endl;
            break;

        case 6:
            cout << "Friday" << endl;
            break;

        case 7:
            cout << "Saturday" << endl;
            break;

        default:
            cout << "Invalid input" << endl;
            break;
    }

    return 0;
}
Q2 switch 문 활용하기 끝 */

// Q3: while 문으로 반복하기 시작
// while 반복문을 활용하여 1~10까지 숫자 중 짝수만 출력하는 프로그램을 만들어 보세요.
/*
#include <iostream>
using namespace std;

int main()
{
    int integer_target = 1;

    while (integer_target < 11)
    {
        if (integer_target % 2 == 0)
        {
            cout << integer_target << endl;
        }

        ++integer_target;
    }

    return 0;
}
*/
// Q3: while 문으로 반복하기 끝


// Q4: for 문으로 반복하기
/*
#include <iostream>
using namespace std;

int main()
{
    int user_input_integer = 0;

    cout << "Insert an integer, from 1 to 9, inclusive: ";
    cin >> user_input_integer;

    for (int i = 1; i < 10; i++)
    {
        cout << user_input_integer << " * " << i << " = " << (user_input_integer * i) << endl;
    }

    return 0;
}
*/




