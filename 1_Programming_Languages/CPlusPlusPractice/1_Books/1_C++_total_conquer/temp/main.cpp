#include <iostream>

int main() {

    // 안녕하세요?
    std::cout << "Hello! How is weather today? ";

    // 날씨 변수를 선언합니다.
    std::string user_input_weather;

    // 오늘 날씨는 어떤가요? 사용자에게 날씨를 물어봅니다.
    std::cin >> user_input_weather;

    // 손님이 얘기한 날씨를 대답해 줍니다.
    std::cout << std::endl << "The customer said that the weather is: " << user_input_weather << ". ";

    // 손님이 rain이라고 답하면 우산 챙기라고 말합니다.
    if (user_input_weather == "rain")
        {
        std::cout << "Take your umbrella";
        }
    else {
        std::cout << "No umbrella is needed";
    }



    return 0;
}