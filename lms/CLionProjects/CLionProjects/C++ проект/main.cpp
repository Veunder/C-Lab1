#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum class WeaponType {
    Pistol,
    Rifle,
    Shotgun,
    Sniper
};

enum class CellType {
    Empty,
    Wall,
    Glass,
    Partition,
    Item,
    Creature,
    Operative
};

class Operative {

};

class Creature {

};

string enumToString(WeaponType wt) {
    switch (wt) {
        case WeaponType::Pistol:
            return "Pistol";
        case WeaponType::Rifle:
            return "Rifle";
        case WeaponType::Shotgun:
            return "Shotgun";
        case WeaponType::Sniper:
            return "Sniper";
        default:
            return "Unknown";
    }
}

class AmmoContainer {
protected:
    WeaponType wt;
    int currentAmmo;
    int maxAmmo;
public:
    explicit AmmoContainer (WeaponType wt_) {
        if (wt_ == WeaponType::Pistol) {
            wt = wt_;
            currentAmmo = 90;
            maxAmmo = 90;
            return;
        }
        if (wt_ == WeaponType::Sniper) {
            wt = wt_;
            currentAmmo = 25;
            maxAmmo = 25;
            return;
        }
        if (wt_ == WeaponType::Shotgun) {
            wt = wt_;
            currentAmmo = 75;
            maxAmmo = 75;
            return;
        }
        if (wt_ == WeaponType::Rifle) {
            wt = wt_;
            currentAmmo = 150;
            maxAmmo = 150;
        }
    };
};

class Weapon : public AmmoContainer{
private:
    int damage;
    int fireTime;
    int reloadTime;
public:
    explicit Weapon(WeaponType wt_) : AmmoContainer(wt_){
        if (wt == WeaponType::Pistol) {
            damage = 15;
            fireTime = 1;
            reloadTime = 2;
            return;
        }
        if (wt == WeaponType::Sniper) {
            damage = 15;
            fireTime = 1;
            reloadTime = 2;
            return;
        }
        if (wt == WeaponType::Shotgun) {
            damage = 15;
            fireTime = 1;
            reloadTime = 2;
            return;
        }
        if (wt == WeaponType::Rifle) {
            damage = 15;
            fireTime = 1;
            reloadTime = 2;
        }
    }
    void get_info () {
        cout << "WeaponType " << enumToString(wt) << endl
             << "currentAmmo " << currentAmmo << endl
             << "maxAmmo " << maxAmmo << endl
             << "damage " << damage << endl
             << "fireTime " << fireTime << endl
             << "reloadTime " << reloadTime << endl;
    }
};

class Cell {
    CellType ct;
    Operative * op;
    Creature * creature;
    Weapon *weapon;
    AmmoContainer *ammoContainer;
};

class Level {
private:
    int width;
    int height;
    vector<vector<Cell>> cells;
public:
    Level(int height, int width) : width(width), height(height) {
        cells.resize(height);
        for (auto &v : cells) {
            v.resize(width);
        }
    }
    [[nodiscard]] int get_width () const { return width; }
    [[nodiscard]] int get_height () const { return height; }
    /*
    1. . - пустая клетка пола;
    2. # - стена;
    3. = - перегородка;
    4. - - стекло;
    5. a, b, c ... - оперативники, подконтрольные пользователю;
    6. A, B, C ... - противники;
    7. ) - предметы на земле;
    */
//    void set_cell (int i, int j, char c) {
//        if (c == '#') {
//            ((cells[i])[j]).set_type(CellType::Wall);
//        }
//        else if (c == '.') {
//            ct = CellType::Empty;
//        }
//        else if (c == '=') {
//            ct = CellType::Partition;
//        }
//        else if (c == '-') {
//            ct = CellType::Glass;
//        }
//        else if (c >= 'a' && c <= 'z') {
//            ct = CellType::Operative;
//        }
//        else if (c >= 'A' && c <= 'Z') {
//            ct = CellType::Creature;
//        }
//        else ct = CellType::Item;
//        cells[i][j] = ct;
//    }
};

int main() {
    /*
     * std::ios::in - открыть файл для чтения.
std::ios::out - открыть файл для записи.
std::ios::app - открыть файл для записи в конец файла (добавление данных).
std::ios::binary - открыть файл в бинарном режиме.
     */
    ifstream InputFile("cmake-build-debug/map.txt");
    if (InputFile.is_open()) {
        int height, width;
        InputFile >> height >> width;
        Level lvl(height, width);
        string s;
        for (int i = 0; i < lvl.get_height(); ++i) {
            InputFile >> s;
            for (int j = 0; j < lvl.get_width(); ++j) {
//                lvl.set_cell(i, j, s[j]);
            }
        }
        InputFile.close();
    }
    else {
        cout << "Не удалось открыть файл" << endl;
    }
    Weapon pistol(WeaponType::Pistol);
    pistol.get_info();
    foo();
    return 0;
}