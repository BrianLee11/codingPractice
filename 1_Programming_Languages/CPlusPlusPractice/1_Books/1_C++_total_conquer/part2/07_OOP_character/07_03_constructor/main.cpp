/* pg.253
#include <iostream>
using namespace std;

class Monster{
public:
    int hp;
    int power;

    Monster() {
        cout << "Monster constructor" << endl;
    };


};

class Character{
public:
    Character() {
        cout << "Character constructor" << endl;
    };
};

class Monster_a : public Monster, Character{
public:
    Monster_a ()  {
        cout << "Monster_a constructor" << endl;
    };
};

int main(){

    Monster_a forest_monster();

    return 0;
}
pg 253 */

// pg.255 값을 전달받는 생성자
#include <iostream>
using namespace std;

class Monster{
public:
    Monster(){
        cout << "Monster constructor" << endl;
    };
};

class Monster_a : public Monster{
private:
    int location[2];

public:
    // 기본 생성자
    Monster_a() {
        cout << "monster_a class basic constructor" << endl;
    };

    // C++ 에서는 생성자가 여러 개 있을 수 있습니다.
    // 값을 전달받는 생성자
    Monster_a(int x, int y) : location{x,y} {
        cout << "Monster_a constructor" << endl;
    };

    void show_location() {
        cout << location[0] << ", " << location[1] << endl;
    }
};

int main() {
    Monster_a forest_monster(10, 5); //
    forest_monster.show_location(); // 10,5

    cout << endl;

    Monster_a wood_moster;  // 기본 생성자 호출
    wood_moster.show_location(); // 이상한 메모리상 위치 출력: -1431302144, 32759
}