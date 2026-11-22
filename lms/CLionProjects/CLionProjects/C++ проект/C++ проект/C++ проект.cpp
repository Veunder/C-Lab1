#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class GunType {
    Pistol,
    Rifle,
    Shotgun,
    Sniper
};

class Gun {
private:
    GunType gt;
    int damage;
    int firetime;
    int reloadtime;
public:
    Gun(GunType gt) {
        if (gt == GunType::Pistol) {

        }
        else if (gt == GunType::Sniper) {

        }
        else if (gt == GunType::Shotgun) {

        }
        else { //rifle

        }
    }
};

enum class typesofbullets {
    bulletsofAK47,
    bulletsofSniper,
    bulletsofPistol,
    bulletsofShotGun
};

int main()
{
    vector <vector<int>> cells;
    cout << "Hello World!\n";
    for (int v = 0; v <= cells.size(); v++) { cout << v; }
}