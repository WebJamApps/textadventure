#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

using namespace std;

class Character
{
private:
        int health;
        int attack;
        int defense;
        string inventory[7];
        int invCount;
public:
        Character()
        {}
        Character(int h, int a, int d)
        {
        health = h;
        attack = a;
        defense = d;
        invCount = 0;
        for (int y = 0; y < 7; y++)
        inventory[y] = "";
        }               
        void restart(int h, int a, int d)
        {
        health = h;
        attack = a;
        defense = d;
        invCount = 0;
        for (int y = 0; y < 7; y++)
        inventory[y] = "";
        }  
        
        void setHealth(int h)
        {
        health = h;
        }
        int getHealth()
        {return health;}
        void addHealth(int h1)
        {
        health += h1;
        }
        void addAttack(int a)
        {
        attack += a;
        }
        void addDefense(int d)
        {
        defense += d;
        }
        int getAttack()
        {
        return attack;
        }
        void displayStats()
            {
            cout<<endl<<"health: "<<health;
            cout<<endl<<"attack: "<<attack;
            cout<<endl<<"defense: "<<defense<<endl;
            }
        
        void takeDamage(int d)
        {
        health -= d;
        }
        void addInv(string i)
        {
        inventory[invCount] = i;
        invCount++;
        }
       void removeInv(string i)
       {
       for(int x3 = 0;x3 < invCount; x3++)
       {
       if (inventory[x3] == i)
          {
          int swap = (invCount - x3);
          invCount--;
          for (int x4 = 0; x4 < swap; x4++)
          inventory[x3 + x4] = inventory[x3 + x4 +1]; 
          }
       }
       }
        void displayInv()
{
        cout<<endl<<"you are carrying: ";
        if (invCount == 0)
        {
        cout<<"only the clothes on your back";
        cout<<endl<<"not very well prepared are we?"<<endl;
        }
         for (int x1 = 0; x1 < invCount; x1++)
         {
         if (x1 > 0)
         {cout<<" ,";}
         cout<<inventory[x1];  
         }
}
         int useItem(string item)
         {
          int found = 0;
          for (int x2 = 0;x2 < invCount; x2++)
          {
          if(inventory[x2] == item)     
          found = 1;
          }
          return found;
          }   

};

#endif
