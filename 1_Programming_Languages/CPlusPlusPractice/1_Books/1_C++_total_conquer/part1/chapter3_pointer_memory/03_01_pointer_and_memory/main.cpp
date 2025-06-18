#include <iostream>

int main() {
    /* pg. 102: 역참조 역산자로 데이터 접근
    char char_value = 'A';
    int int_value = 123;
    double double_value = 123.456;

    // 포인터 변수 선언
    char *char_pointer_value = &char_value;
    int *int_pointer_value = &int_value;
    double *double_pointer_value = &double_value;

    // 포인터 주소 출력
    std::cout << std::endl << "address of point variables";
    std::cout << "address of char_value: " << &char_value << std::endl;
    std::cout << "address of int_value: " << &int_value << std::endl;
    std::cout << "address of double_value: " << &double_value << std::endl;

    // 포인터 데이터 출력
    std::cout << std::endl <<  "original data: " << std::endl;
    std::cout << "*char_pointer_value: " << *char_pointer_value << std::endl;
    std::cout << "*int_pointer_value: " << *int_pointer_value << std::endl;
    std::cout << "*double_pointer_value: " << *double_pointer_value << std::endl;

    // 역참조 연산자로 원본 데이터 덮어쓰기
    *char_pointer_value = 'Z';
    *int_pointer_value = 321;
    *double_pointer_value = 654.321;

    // 일반 변수의 데이터 출력(업데이트 확인)
    std::cout << std::endl << "after update: " << std::endl;
    std::cout << "char_value: " << char_value << std::endl;
    std::cout << "int_value: " << int_value << std::endl;
    std::cout << "double_value : " << double_value << std::endl;

    return 0;
    pg.102 역참조 연산자로 데이터 접근 */

    /* pg.104 다중 오인터 변수 선언: 시작
    int int_value = 123;

    int *int_pt_value = &int_value;
    int **int_pt_value_ptr = &int_pt_value;
    int ***int_pt_value_ptr_ptr = &int_pt_value_ptr;

    std::cout << ***int_pt_value_ptr_ptr << std::endl; // output: 123

    return 0;

    pg.104 다중 오인터 변수 선언: 끝 */

    /* pg.106 배열 선언과 원소에 접근하기: 시작
    int lotto[10] = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "Today's Lotto numbers: " << lotto[0] << ", " << lotto[3] << ", " << lotto[9] << std::endl;

    std::cout <<"lotto[0] address: " << &lotto[0] << std::endl;
    std::cout <<"lotto[1] address: " << &lotto[1] << std::endl;
    std::cout <<"lotto[2] address: " << &lotto[2] << std::endl;
    std::cout <<"lotto[3] address: " << &lotto[3] << std::endl;

    pg.106 배열 선언과 원소에 접근하기: 끝 */


    /* pg.107 배열 원소의 메모리 주소 확인하기: 시작
    int lotto[10] = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "Today's Lotto numbers: " << lotto[0] << ", " << lotto[3] << ", " << lotto[9] << std::endl;

    std::cout <<"lotto[0] address: " << &lotto[0] << std::endl;
    std::cout <<"lotto[1] address: " << &lotto[1] << std::endl;
    std::cout <<"lotto[2] address: " << &lotto[2] << std::endl;
    std::cout <<"lotto[3] address: " << &lotto[3] << std::endl;

    pg.107 배열 원소의 메모리 주소 확인하기: 끝 */

    /* 실행 결과
    *
    * lotto[0] address: 0x5fd2bffd60
    * lotto[1] address: 0x5fd2bffd64
    * lotto[2] address: 0x5fd2bffd68
    * lotto[3] address: 0x5fd2bffd6c
    */

    /* pg.108: 배열 원소의 주소와 포인터 연산의 결과를 비교하기: 시작 */
    /*
    int lotto[10]  = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "lotto[0] address: " << &lotto[0] << std::endl;
    std::cout << "lotto[1] address: " << &lotto[1] << std::endl;
    std::cout << "lotto[2] address: " << &lotto[2] << std::endl;

    std::cout << "(lotto+0) address: " << lotto + 0 << std::endl;
    std::cout << "(lotto+1) address: " << lotto + 1 << std::endl;
    std::cout << "(lotto+2) address: " << lotto + 2 << std::endl;

    // check for the same address
    std::cout << "lotto[0] address vs lotto + 0 address: " << (&lotto[0] == lotto + 0) << std::endl; // output: 1 (true)
    std::cout << "lotto[1] address vs lotto + 1 address: " << (&lotto[1] == lotto + 1) << std::endl; // output: 1 (true)
    std::cout << "lotto[2] address vs lotto + 2 address: " << (&lotto[2] == lotto + 2) << std::endl; // output: 1 (true)
    */
    /* pg.108: 배열 원소의 주소와 포인터 연산의 결과를 비교하기: 끝 */

    /* 실행결과
    lotto[0] address: 0x2b113ff7d0
    lotto[1] address: 0x2b113ff7d4
    lotto[2] address: 0x2b113ff7d8
    (lotto+0) address: 0x2b113ff7d0
    (lotto+1) address: 0x2b113ff7d4
    (lotto+2) address: 0x2b113ff7d8
    lotto[0] address vs lotto + 0 address: 1
    lotto[1] address vs lotto + 1 address: 1
    lotto[2] address vs lotto + 2 address: 1
    */

    /* pg.110 배열과 포인트가 같은지 확인하기: 시작 */
    /*
    int array[5] = {1,2,3,4,5};
    int *pointer_to_array = &array[0];

    std::cout << "array: " << array << std::endl;
    std::cout << "pointer_to_array: " << pointer_to_array << std::endl;

    std::cout << "sizeof(array): " << sizeof(array) << std::endl;
    std::cout << "sizeof(pointer_to_array): " << sizeof(pointer_to_array) << std::endl;

    return 0;
    */
    /* pg.110 배결과 포인트가 같은지 확인하기: 끝 */

    /* 실행 결과:
    array: 0x50cb1ffb10
    pointer_to_array: 0x50cb1ffb10
    sizeof(array): 20
    sizeof(pointer_to_array): 8
    */

    // pg.111: 배열 원소 접근을 포인터 연산으로 수행하기: 시작
    /*
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << array[0] << ", " << *(array + 1) << std::endl;
    */
    // pg.111: 배열 원소 접근을 포인터 연산으로 수행하기: 끝

    /* 실행 결과:
     * 1, 2
     */

    // pg.113: new, delete로 동적 메모리 할당하고 해제하기. 시작
    /*
    int *pointer_to_integer_value = new int; // 동적 메모리 할당
    *pointer_to_integer_value = 100;

    std::cout << *pointer_to_integer_value << std::endl;

    delete pointer_to_integer_value; // 동적 메모리 해제

    return 0;
    */
    // pg.113: new, delete로 동적 메모리 할당하고 해제하기. 끝

    // pg.115: new, delete로 배열 형태의 동적 메모리를 할당하고 해제하기: 시작
    /*
    int *pt_int_array_value = new int[5]; // 동적 메모리 할당(배열, 정수, 크기는 5)

    // 할당된 배열 변수에 0~4까지 순서대로 넣기
    for (int i = 0; i < 5; i++)
    {
        pt_int_array_value[i] = i;
    }

    // 배열 변수 출력
    for (int i = 0; i < 5; i++)
    {
        std::cout << pt_int_array_value[i] << std::endl;
    }

    // 동적 메모리 해제(배열)
    delete[] pt_int_array_value;

    return 0;
    */
    // pg.115: new, delete로 배열 형태의 동적 메모리를 할당하고 해제하기: 끝

    /* 실행결과
     * 0
     * 1
     * 2
     * 3
     * 4
     */

    // pg.116: 방문하는 손님 수만큼만 빵 만들기

    // 손님 숫자 변수 선언 및 초기화
    int customer_number = 0;

    // 손님 숫자 입력 받음 from 사용자
    std::cout << "Today's number of customer: ";
    std::cin >> customer_number;

    // 손님 수만큼 string 배열 생성
    std::string *bread = new std::string[customer_number];

    // 입력받은 손님 수만큼 반복
    for (int i = 0; i < customer_number; i++)
    {
        bread[i] = "Bread_" + std::to_string(i); // '빵_숫자' 형태로 배열에 저장
    }

    // 빵 생성 출력
    std::cout << std::endl << "--Produced Bread--" << std::endl;
    for (int i = 0; i < customer_number; i++)
    {
        std::cout << *(bread + i) << std::endl;
    }

    // string 배열 삭제
    delete[] bread;

    return 0;
}