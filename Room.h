#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Room
{
private:
int north, south, east, west;
string description;
string item;
public:
       Room(int n, int s, int e, int w)
       {
       north = n;
       south = s;
       east = e;
       west = w;
       }
 void setExits(int n, int s, int e, int w)
      {
      north = n;
      south = s;
      east = e;
      west = w;
      }
 void setDes(string desc)
  {
   description = desc;
   }
   int moveCheck(string c)
   {
   if ((c == "n")&& (north == 1))
   return 1;
   else if ((c == "s") && (south == 1))
   return 1;
   else if ((c == "e") && (east == 1))
   return 1;
   else if ((c == "w") && (west == 1))
   return 1;
   else
   return 0;
   }
   string displayDes()
   {
        return description;
   }
   void setItem(string i)
        {
        item = i;
        }
        string displayItem()
        {
        return item;
        }
   void displayDirections()
{
   int comma = 0;
   if (north == 1)
   {
   cout<<"north";
   comma = 1;
   }
   if (south == 1)
   {
    if (comma == 1)
          {cout<<" ,";}   
    cout<<"south";
    comma = 1;
   }
   if (east == 1)
   {
       if (comma == 1)
          {cout<<" ,";}               
   cout<<"east";
   comma = 1;
   }
   if (west == 1)
    {     
         if (comma == 1)
          {cout<<" ,";}  
   cout<<"west";
   }  
}
   int getItem(string item1)
         {
          int check = 0;
          if(item == item1)     
          {
          check = 1;
          }
          return check;
          }   
   
};

#endif
