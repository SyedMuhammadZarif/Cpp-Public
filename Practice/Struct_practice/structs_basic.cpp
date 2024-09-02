#include <iostream>
using namespace std;
struct weapon
{
    string name;
    int type;
    string weaponclass;
    int damage;

};

int main()
{
    weapon weapon1;
    weapon1.name = "BD_556";
    weapon1.type = 2;
    weapon1.weaponclass = "Assault Rifle";
    weapon1.damage = 30;


    cout<<'\n';

    cout<<"Weapon Info: "<<'\n';
    cout<<"Weapon Name: "<<weapon1.name<<'\n';
    cout<<"Weapon Class: "<<weapon1.weaponclass<<'\n';
    cout<<"Weapon Damage: "<<weapon1.damage<<'\n';
    return 0;
}
