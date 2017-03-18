#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <time.h>
#include <limits>
#include <string>
#include "Character.h"
#include "Room.h"

using namespace std;
int playerAttacks();
void trollAttacks();
void moveRoom(string);
void playGame();
int randomNumGen(int, int);
int playAgain();
int roll;
Character human(25, 10, 10);
Character troll(30, 15, 15);
Room map[34] = {Room(0,0,1,0), Room(0,1,0,1), Room(0,1,0,0), 
                Room(0,0,0,0), Room(0,0,0,0), Room(0,0,0,0), 
                Room(0,0,0,0), Room(0,0,0,0), Room(0,0,0,0), 
                Room(0,0,0,0), Room(0,0,0,0), 
                Room(1,1,1,0), Room(1,0,1,1), Room(0,1,0,1),
                Room(0,0,0,0), Room(0,0,0,0), Room(0,0,0,0), 
                Room(0,0,0,0), Room(0,0,0,0), Room(0,0,0,0), 
                Room(0,1,0,0), Room(1,1,1,0), Room(0,0,1,1),
                Room(1,1,0,1), Room(0,0,0,0), Room(0,0,0,0), 
                Room(0,0,0,0), Room(0,0,0,0), Room(0,0,0,0), 
                Room(0,0,0,0),Room(0,0,1,0), Room(1,0,0,1), 
                Room(0,0,0,0), Room(1,0,0,0)};
string des[34] = {"you see a cave enterance to the east", 
"you see the cave exit to the west and \nthe passage continues to the south",
"you have entered a large chamber\n The passage to the south is the only exit",
"", "", "", "", "", "", "", "","large stalactites hang from the ceiling", 
"the passage widens to the north", "you are deep within the cave",
"","","","","","","You are inside the treasure room",
"you are still in the cave",
"the cave passage seems to narrow",
"you hear noises to the south","","","","","","",
"you see a strange looking door to the north", "the passage curves to the west",
"", "you have found the troll's hideout!"};

string itm[34] = {"","torch","sword","","","","","","","","","",
                  "","shield","","","","","","","loot","","potion","","","","","",
                  "","","","armor","","key"};
string help = "your available commands are: \ne, w, n, s, get, use, attack, inventory, look, help";
int main(int argc, char *argv[])
{
  int again = 1;
  while (again == 1)
  {
  time_t seconds;
  time(&seconds);
  srand((unsigned int) seconds);
  system("CLS");
  cout<<"Welcome to the text adventure game!!!!\n\n";
    playGame();
    again = playAgain();
    } 
    system("CLS");
    cout<<endl<<endl<<"thank you for playing";
    cout<<endl<<endl<<endl<<endl<<endl<<"goodbye"<<endl<<endl<<endl<<endl;
    system("PAUSE");
	return EXIT_SUCCESS;
}

void playGame()
{
    
    int mapNum = 0, torch = 0, itemCheck = 0, troll = 30, lock = 0, fall = 0;
    int loot = 0, end = 0, exit = 0, armor = 0, sword = 0, shield = 0;
    string ui="xxxxxxxxxxxx", choice="look";
    char line[20];
    for (int x = 0; x < 34; x++)
    {
    map[x].setDes(des[x]);
    map[x].setItem(itm[x]);
    map[11].setExits(1,1,1,0);
    map[21].setExits(1,1,1,0);
    }
    cout<<"A troll has been raiding the nearby town \n"; 
    cout<<"You have been charged with killing the troll\n";
    cout<<"and returning the stolen loot to the king\n";
    cout<<"You have tracked the troll to this location\n";
    cout<<endl<<map[mapNum].displayDes();
         if (map[mapNum].displayItem() != "")
         {cout<<endl<<"you see a "<<map[mapNum].displayItem();}
         cout<<endl<<"available directions: ";
         map[mapNum].displayDirections();
         cout<<endl;
    cout<<endl<<help<<endl;
    while ((human.getHealth() > 0)&& (end == 0))
{
    cout<<"\nenter command: ";
    cin.getline(line, 20);
    choice = line;
if((mapNum==33)&&(troll>0)&&(choice!="attack troll")&&(choice!="attack")&&(choice!="use potion")&&(choice!="n"))
         {
         if (troll > 0)
         trollAttacks();
         }   
    else if (choice == "help")
       cout<<endl<<help<<endl;
    else if (choice == "look")
    {
         if ((mapNum == 0)||(mapNum == 1)||(torch == 1))
         {
         cout<<endl<<map[mapNum].displayDes();
         if (map[mapNum].displayItem() != "")
         {cout<<endl<<"you see the "<<map[mapNum].displayItem();}
         cout<<endl<<"available directions: ";
         map[mapNum].displayDirections();
         cout<<endl;
         }
    }
    else if ((choice == "inventory")||(choice == "inv"))
    {
    human.displayInv();
    cout<<endl<<"your current stats:";
    human.displayStats();
    }
    else if ((choice == "attack troll") || (choice == "attack"))
         {
         if((mapNum == 33)&&(troll > 0))
         {
                    troll = playerAttacks();
                    if (troll < 1)
                       {
                    cout<<endl<<"you killed the troll";
                    }
         }           
         else
         cout<<"you swing at the air";
         }   
    else if (choice.find("use",0) == 0)
    {
         if (choice.find("torch",4) == 0)
         ui = "torch";
         if (choice.find("sword",0) == 4)
         ui = "sword"; 
         if (choice.find("potion",0) == 4)
         ui = "potion";
         if (choice.find("shield",0) == 4)
         ui = "shield";
         if (choice.find("key", 0) == 4)
         ui = "key";
         if (choice.find("armor",0) == 4)
         ui = "armor";
         itemCheck = human.useItem(ui);
         if (itemCheck == 1)
         {
         cout<<endl<<"you use your "<<ui;
         if ((ui == "sword")&& (sword == 0))
         {human.addAttack(10);
         cout<<"\nyour attack stat has increased";
         sword = 1;
         }
         if (ui == "potion")
         {
         human.setHealth(25);
         cout<<"\nyour health has been restored";
         human.removeInv("potion");
            if ((mapNum==33)&&(troll > 0))
            trollAttacks();
         }
         if ((ui == "shield")&&(shield == 0))
         {human.addDefense(5);
         cout<<"\nyour defense stat has increased";
         shield = 1;
         }
         if ((ui == "armor")&& (armor == 0))
         {human.addDefense(10);
         cout<<"\nyour defense stat has increased";
         armor = 1;
         }
         if ((ui == "key") && (mapNum == 30))
            {
         cout<<endl<<"your key unlocks the door";
         map[30].setExits(1,0,1,0);
         lock = 1;
              }
         if ((ui == "key") && (mapNum != 30))
              {
              cout<<endl<<"there is nothing to unlock here";
              }
         if ((ui == "torch")&&(torch == 0))
         {
         cout<<endl<<"it illuminates the surroundings";
         torch = 1;
         }
         }
         else
         cout<<endl<<"you do not have that item";
    }
    else if (choice.find("get",0) == 0)
    {
         if (choice.find("torch",0) == 4)
         ui = "torch";
         if (choice.find("sword",0) == 4)
         ui = "sword"; 
         if (choice.find("potion",0) == 4)
         ui = "potion";
         if (choice.find("shield",0) == 4)
         ui = "shield";
         if (choice.find("key",0) == 4)
         ui = "key";
         if (choice.find("armor",0) == 4)
         ui = "armor";
         if (choice.find("loot",0) == 4)
         ui = "loot";
         itemCheck = map[mapNum].getItem(ui);
         if (itemCheck == 1)
            {
            human.addInv(ui);
            map[mapNum].setItem("");
            cout<<endl<<"you pick up the "<<ui;
            if (ui == "loot")
            loot = 1;
            }
            else
            cout<<endl<<"that item is not here";
     }
    else if ((choice == "n")||(choice == "s")||(choice == "e")||(choice == "w"))
{
    exit = map[mapNum].moveCheck(choice);
    if (exit == 1)
       {
       if ((mapNum == 11)&&(choice == "s")&&(fall == 0))
       {
       cout<<endl<<"stalactites fall from the ceiling";
       cout<<endl<<"you take 5 damage";
       human.takeDamage(5);
       map[11].setExits(1,0,1,0);
       map[21].setExits(0,1,1,0);
       map[11].setDes("the passage south has been blocked by fallen stalactites");
       map[21].setDes("the passage north has been blocked by fallen stalactites");
       fall = 1;
       }
       if ((mapNum == 21)&&(choice == "n")&&(fall == 0))
       {
       cout<<endl<<"stalactites fall from the ceiling";
       cout<<endl<<"you take 5 damage";
       human.takeDamage(5);
       map[11].setExits(1,0,1,0);
       map[21].setExits(0,1,1,0);
       map[11].setDes("the passage south has been blocked by fallen stalactites");
       map[21].setDes("the passage north has been blocked by fallen stalactites");
       fall = 1;
       }
       if ((mapNum==33)&&(choice == "n")&&(troll > 0))
       trollAttacks();
       if (choice == "n")
       mapNum -= 10;
       if (choice == "s")
       mapNum += 10;
       if (choice == "e")
       mapNum++;
       if (choice == "w")
       mapNum--;
       if ((mapNum == 23) && (troll <= 0))
       map[23].setDes("all is quiet in this part of the cave");
       if ((mapNum == 0)||(mapNum == 1)||(torch == 1))
         {
         cout<<endl<<map[mapNum].displayDes();
         if (map[mapNum].displayItem() != "")
         {cout<<endl<<"you see the "<<map[mapNum].displayItem();}
         cout<<endl<<"available directions: ";
         map[mapNum].displayDirections();
         cout<<endl;
         }
       if ((mapNum == 33)&&(troll == 30))
       cout<<"the troll is eating some unfortunate creature";
       if((mapNum == 33)&&(troll < 30)&&(troll > 0))
       trollAttacks();
       if ((mapNum == 0)&&(loot == 1))
       {
       cout<<endl<<"YOU WON!!!!!!!";
       end = 1;
       }
       }
    else
        {
    cout<<endl<<"you can not go that way";
    if((mapNum==30)&&(lock==0)&&(choice=="n"))
    cout<<endl<<"the door is locked";
    }
}
    else
    {                  
    cout<<"invalid command\n";       
    }
}
    if (human.getHealth() <= 0)
    cout<<endl<<"you have died";
}

int playerAttacks()
{
    int dieRoll = randomNumGen(1, 20);
    int hit = (dieRoll - 15 + human.getAttack());
    if (hit > 10)
    {
    cout<<endl<<"you hit the troll";
    troll.takeDamage(hit - 10);
    cout<<endl<<"it takes "<<(hit - 10)<<" damage";
    cout<<endl<<"the trolls stats:";
    troll.displayStats();
    }
    else
    cout<<endl<<"you missed";
    if (troll.getHealth() > 0)
    trollAttacks(); 
    return troll.getHealth();
}
void trollAttacks()
{
   int dieRoll = randomNumGen(1, 20);
    int hit = (dieRoll - 15 + troll.getAttack());
    if (hit > 10)
    {
    cout<<endl<<"the troll hit you";
    human.takeDamage(hit - 10);
    cout<<endl<<"you take "<<(hit- 10)<<" damage";
    cout<<endl<<"your stats:";
    human.displayStats();
    }
    else
    cout<<endl<<"the troll swings but missed"; 
}

              
  
int randomNumGen(int low, int high)
    {
    roll = rand() % (high - low + 1) + low;
    return roll;
    }


int playAgain()
    {
    char again1;
    cout<<endl<<endl<<endl<<endl<<endl<<
    "Would you like to play again?  (Y/N)";
    cin>>again1;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    if (again1 == 'Y' || again1 == 'y')
    {
    human.restart(25,10,10);
    troll.restart(30,15,15);
    return 1;
    }
    else
    return 0;
}
