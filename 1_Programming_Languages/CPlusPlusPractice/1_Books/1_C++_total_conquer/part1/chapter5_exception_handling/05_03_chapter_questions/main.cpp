// pg.194: 되새김 문제
// 문제 1: try, catch, throw
/*
#include <iostream>

int main() {
 int divisor = 0;

 try {
  if (divisor == 0) {
   throw std::runtime_error("division by zero");
  }
  int result = 10 / divisor;
  std::cout << "result: " << result << std::endl;
 }

 // const는 오류 상황 보고서이므로, 변경하면 안 됨. const로 안전 보장
 // &로 reference variable 처리. 값으로 받을 경우 불필요한 복사 발생
 // 타입 명시로 std::runtime_error
 catch (const std::runtime_error& e) {
   std::cout << "Shall not divide by 0  " << e.what() << std::endl;
 }

 return 0;
}
*/

// 문제 2: 예외 처리 생략과 실패 대응
/*
#include <iostream>
using namespace std;

void process(int value){
 if (value < 0)
 {
  cout << "Exception occured!" << endl;
 }
 else
 {
  cout << "value is: " << value << endl;
 }
}

int main() {
 process(10);
 process(-5);
 return 0;
}
*/

// ## 문제 3: assertion 을 이용한 예외 처리
/*
#include <iostream>
#include <cassert>
using namespace std;

void divide(int a, int b) {
  // b가 0일 때 assert로 예외 처리
 assert(b != 0);
 int result = a / b;

 cout << "result: " << result << endl;
}

int main() {
 divide(10,2 );
 divide(5,0);
 return 0;
}
*/


// 문제 4: 에외 처리 실전 연습 1
/*
#include <iostream>
using namespace std;

void check_inputs(int month, int day) {
 if (day < 1 || day > 31){
  throw out_of_range("day must be 1-31");
 }
 else if (month < 1 || month > 12) {
  throw out_of_range("month must be 1-12");
 }
}


void print_season(int month, int day) {
 check_inputs(month, day);

 string season_names[4] = {"spring", "summer", "autumn", "winter"};
 string season = "";

 if (month == 3 || month == 4 || month == 5) {
  season = season_names[0];
 }
 else if (month == 6 || month == 7 || month == 8) {
  season = season_names[1];
 }
 else if (month == 9 || month == 10 || month == 11) {
  season = season_names[2];
 }
 else if (month == 12 || month == 1 || month == 2) {
  season = season_names[3];
 }

 cout << "Month: " << month << ", day: " << day
         << ". Season: " << season << '\n';
}


int main(){

 try {
  // print_season(3, 3);   // 정상
  // print_season(12, 25); // winter
  // print_season(10, 40); // day 오류

  int month = -1;
  int day = -1;

  cout << "Enter month, 1-12: ";
  cin >> month;

  cout << "Enter day, 1-31: ";
  cin >> day;


  print_season(month, day);
 }

  catch (out_of_range dayError) {
   cout << dayError.what() << endl;
  }

  return 0;
}
*/


#include<iostream>
#include<random>
using namespace std;

int randomNumberGenerator(int begin, int end) {
 // 1부터 100까지 랜덤 숫자 생성
 // ① 시드(seed) 생성: 하드웨어 엔트로피를 이용해 불규칙한 시드 확보
 random_device rd;

 // ② 난수 엔진(engine) 선택: Mersenne Twister 32비트
 mt19937 gen(rd());

 // ③ 분포(distribution) 설정: [1, 100] 균등 분포
 uniform_int_distribution<> dist(begin, end);

 // ④ 난수 생성
 int random_num = dist(gen);

 return random_num;
}

int main() {

 int answer = randomNumberGenerator(1, 100);
 bool bool_is_correct = false;
 int trial_number = 0;
 const int max_trial_number = 20;

 int user_guess = -1;

 while (bool_is_correct == false && trial_number < max_trial_number) {

   cout << "Enter a number between 1 and 100: ";
   cin >> user_guess;

  try {
   if (user_guess < 1 ) {
    throw out_of_range ("Too small invalid number");
   }
   else if (user_guess > 100) {
    throw out_of_range ("Too large invalid number");
   }

   if (user_guess == answer) {
    bool_is_correct = true;
    cout << "Congratulations!" << endl;
    cout << "The correct answer was: " << answer << endl;
    trial_number++;
    cout << "Trial number: " << trial_number << endl;
   }
   else if (user_guess > answer) {
    cout << "Too big! Try again." << endl;
    trial_number++;
   }
   else if (user_guess < answer) {
    cout << "Too small! Try again." << endl;
    trial_number++;
   }

  }
  catch (const exception& e) {
   cout << e.what() << endl;
   cout << "The number of valid trials: " << trial_number << endl;
  }

  if (bool_is_correct == false && trial_number == max_trial_number) {
   cout << "The correct answer was: " << answer << endl;
   cout << "The number of valid trials was: " << trial_number << endl;
  }

 }

 return 0;
}








