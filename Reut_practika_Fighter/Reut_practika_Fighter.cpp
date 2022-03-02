#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

struct Hero
{
    string nick;
    int HelthPoints;
    int hit;
    int Chance;
    int Money;
    int scale=12;
    int Action;
};

void YourFighter(Hero &you) 
{
    srand(time(NULL));
    
        cout << "Enter your nickname" << endl;
        cin >> you.nick;
        you.HelthPoints = 15+rand() % 30 ;
     
        you.hit = rand() % 4 + 2;
     
        you.Money = 0;
    
}

void GenEnemy(Hero &enemy)
{
    enemy.nick = "Enemy";
    enemy.HelthPoints= 7 + rand() % 14;
    enemy.hit = 1 + rand() % 3;

}

void YourTurn(Hero &you, Hero &enemy)
{
    
    cout << "choose action: " << endl;
    cin >> you.Action;

    while (you.Action != 1 && you.Action != 2 && you.Action != 3 && you.Action != 4)
    {
        cout << "incorrectly action" << endl;
        cout << "choose action: " << endl;
        cin >> you.Action;
    }
    switch (you.Action)
    {
        case 1: 
        {
            you.Chance = 1 + rand() % you.scale;
            if (you.Chance <= 4)
            {
                cout << "enemy dodge your punch" << endl;
            }
            else
            {
                if (you.Chance > 4 && you.Chance<=11)
                {
                    if (enemy.Action != 4)
                    {
                        cout << "you deal enemy " << you.hit << " damage" << endl;
                        enemy.HelthPoints -= you.hit;
                    }
                    else cout<<"enemy block your hit"<<endl;
                }
                else
                {
                    if (enemy.Action != 4)
                    {
                        cout << "Crit! you deal enemy " << you.hit*2 << " damage" << endl;
                        enemy.HelthPoints -= you.hit*2;
                    }
                    else
                    {
                        cout << "Your Crit! break the block" << endl;
                        enemy.HelthPoints -= you.hit;
                    }

                }

            }
            you.Action = 0;
        }
        break;

        case 2: 
        {
            you.Chance = 1 + rand() % you.scale;
            if (you.Chance <= 7)
            {
                cout << "enemy dodge your strong strike" << endl;
            }
            else
            {
                if (you.Chance > 7 && you.Chance <= 11)
                {
                    if (enemy.Action != 4)
                    {
                    cout << "you deal enemy " << you.hit + 2 << " damage" << endl;
                    enemy.HelthPoints -= you.hit + 2;
                    }
                    else cout << "enemy block your strong strike" << endl;
                }
                else
                {
                    if (enemy.Action != 4)
                    {
                    cout << "Crit! you deal enemy " << (you.hit + 2) * 2 << " damage" << endl;
                    enemy.HelthPoints -= (you.hit + 2) * 2;
                    }
                    else
                    {
                        cout << "Your Crit! break the block" << endl;
                        enemy.HelthPoints -= you.hit+2;
                    }
                    
                }

            }
            you.Action = 0;
        }
        break;
        case 3:
        {
            you.Chance = 1 + rand() % you.scale;
            if (you.Chance <= 9)
            {
                cout << "enemy dodge your low kick" << endl;
            }
            else
            {
                if (you.Chance > 9 && you.Chance <= 11)
                {
                    if (enemy.Action != 4)
                    {
                    cout << "you deal enemy " << you.hit + 3 << " damage" << endl;
                    enemy.HelthPoints -= you.hit + 3;
                    }
                    else cout << "enemy block your low kick" << endl;
                }
                else
                {
                    if (enemy.Action != 4)
                    {
                    cout << "Crit! you deal enemy " << (you.hit + 3) * 2 << " damage" << endl;
                    enemy.HelthPoints -= (you.hit + 3) * 2;
                    }
                    else
                    {
                        cout << "Your Crit! break the block" << endl;
                        enemy.HelthPoints -= you.hit + 3;
                    }
                }

            }
            you.Action = 0;
        }
        break;
        case 4: 
        {
            cout << "you are blocking" << endl;
          
        }
        break;
    }
}

void EnemyTurn(Hero& enemy, Hero& you)
{   enemy.Action=1+rand()%4;
    switch (enemy.Action)
    {
    case 1:
    {
        enemy.Chance = 1 + rand() % enemy.scale;
        if (enemy.Chance <= 4)
        {
            cout << "you dodge enemy punch" << endl;
        }
        else
        {
            if (enemy.Chance > 4 && enemy.Chance <= 11)
            {
                if (you.Action != 4)
                {
                    cout << "enemy deal you " << enemy.hit << " damage" << endl;
                    you.HelthPoints -= enemy.hit;
                }
                else  cout << "you block enemy hit" << endl;
                
            }
            else
            {
                if (you.Action != 4)
                {
                    cout << "CRIT! enemy deal you " << enemy.hit * 2 << " damage" << endl;
                    you.HelthPoints -= enemy.hit * 2;
                }
                else
                {
                    cout << "Enemy Crit! break the block" << endl;
                    you.HelthPoints -= enemy.hit ;
                }

            }
        }
    }
    break;

    case 2:
    {
        enemy.Chance = 1 + rand() % enemy.scale;
        if (enemy.Chance <= 7)
        {
            cout << "you dodge enemy strong strike" << endl;
        }
        else
        {
            if (enemy.Chance > 7 && enemy.Chance <= 11)
            {
                if (you.Action != 4)
                {
                    cout << "enemy deal you " << enemy.hit + 2 << " damage" << endl;
                    you.HelthPoints -= enemy.hit + 2;
                }
                else  cout << "you block enemy strong strike" << endl;
            }
            else
            {
                if (you.Action != 4)
                {
                    cout << "CRIT! enemy deal you " << enemy.hit * 2+2 << " damage" << endl;
                    you.HelthPoints -= enemy.hit * 2+2;
                }
                else
                {
                    cout << "Enemy Crit! break the block" << endl;
                    you.HelthPoints -= enemy.hit + 2;
                }
            }
        }
    }
    break;
    case 3:
    {
        enemy.Chance = 1 + rand() % enemy.scale;
        if (enemy.Chance <= 9)
        {
            cout << "you dodge enemy low kick" << endl;
        }
        else
        {
            if (enemy.Chance > 9 && enemy.Chance <= 11)
            {
                if (you.Action != 4)
                {
                    cout << "enemy deal you " << enemy.hit + 3 << " damage" << endl;
                    you.HelthPoints -= enemy.hit + 2;
                }
                else  cout << "you block enemy strong strike" << endl;
            }
            else
            {
                if (you.Action != 4)
                {
                    cout << "CRIT! enemy deal you " << enemy.hit * 2 + 3 << " damage" << endl;
                    you.HelthPoints -= enemy.hit * 2 + 3;
                }
                else
                {
                    cout << "Enemy Crit! break the block" << endl;
                    you.HelthPoints -= enemy.hit + 3;
                }
            }

        }
      
    }
    break;
    case 4:
    {
        cout << "enemy are blocking" << endl;
    }
    break;
    }
}

void Shop(Hero& you)
{
    cout << "Welcom at my shop" << endl;
    int Buy = 0;
    cout << "1)ring of power '+1 ATK' 10 money " << endl << "2)skill book'+1 Crit chance' 8 money" << endl << "3)sandwich'add 9 HP' 9 money" << endl << "4)skip" << endl;
    cin >> Buy;
    while (Buy != 1 && Buy != 2 && Buy != 3 && Buy != 4)
    {
        cout << "incorrectly select" << endl;
        cin >> Buy;
    }
    int repeat = 0;
    while (repeat == 0)
    {
        while (Buy != 1 && Buy != 2 && Buy != 3 && Buy != 4)
        {
            cout << "incorrectly select" << endl;
            cin >> Buy;
        }
        switch (Buy)
        {
        case 1:
        {
            if (you.Money - 10 < 0) cout << "need more money" << endl;
            else
            {
                you.Money -= 10;
                cout << "thank you for buying ring of power" << endl;
                repeat = 1;
                you.hit += 1;
            }
        }; break;

        case 2:
        {
            if (you.Money - 8 < 0) cout << "need more money" << endl;
            else
            {
                you.Money -= 8;
                cout << "thank you for buying skill book" << endl;
                repeat = 1;
                you.scale += 1;
            }
        }; break;
        case 3:
        {
            if (you.Money - 9 < 0) cout << "need more money" << endl;
            else
            {
                you.Money -= 9;
                cout << "thank you for buying sandwitch" << endl;
                repeat = 1;
                you.HelthPoints += 9;
            }
        }; break;
        case 4:; break;
        }
        Buy = 0;
    }
}
void Rules()
{
    string string;
    ifstream FILE("Rules.txt");
    while (!FILE.eof())
    {
        getline(FILE, string);
        cout << string << endl;
    }
    FILE.close();
}
bool WINER(Hero &you,Hero &enemy) 

{
        if (you.HelthPoints <= 0)
        {
            system("cls");
            cout << "you lose( "<<endl;
           
          
            
            return false;
        }
        else if (enemy.HelthPoints <= 0)
        {
          
            cout << "enemy defeated"<<endl;
            
            
            return false;
        }
        else
            return true;
}


int main()
{
    
        Hero you, enemy;
        cout << "Hi! Your play in HERO'S ASCENT" << endl;
        while (true)
        {
        cout << "Press 1 to read rules" << endl << "Press 2 to start game" << endl << "Press 3 to close game" << endl;
        int menu;
        cin >> menu;
        switch (menu)
        {
        case 1:Rules(); break;
        case 2:
        {   int Rounde = 1;
        YourFighter(you);
        cout << "you stats: HP = " << you.HelthPoints << " damage = " << you.hit << endl;
        GenEnemy(enemy);
        cout << "Rounde " << Rounde << endl;
        cout << "enemy stats: HP = " << enemy.HelthPoints << " damage = " << enemy.hit << endl;
        while (true)
        {
            while (true)
            {
                YourTurn(you, enemy);
                EnemyTurn(enemy, you);
                cout << "you HP " << you.HelthPoints << " enemy HP" << enemy.HelthPoints << endl;
                cout << endl;

                if (!WINER(you, enemy))break;
            }

            if (you.HelthPoints <= 0)break;
            if (Rounde >= 15)
            {
                system("cls");
                cout << "you won" << endl;
                break;
            }

            you.Money += 2 + rand() % 5;
            cout << endl;
            cout << "your money " << you.Money << endl;
            if (Rounde % 3 == 0)Shop(you);
            Rounde++;
            cout << endl;

            cout << "Rounde " << Rounde << endl;
            GenEnemy(enemy);
            cout << endl;

            cout << "enemy stats: HP = " << enemy.HelthPoints << " damage = " << enemy.hit << endl;




        }

        }break;
        case 3:exit(0); break;

        }

    }
}


