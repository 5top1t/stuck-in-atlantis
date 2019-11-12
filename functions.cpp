//functions.cpp
#include "functions.h"
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
using namespace leavature;



// Struct Card
bool card::operator > (const card& o) const
{
    bool stackable = false;
    if ((length > o.length && width > o.width) ||
        (length > o.width && width > o.length))
        {
            stackable = true;
        }
    return stackable;
}

bool card::operator < (const card& o) const
{
    bool stackable = false;
    if ((length < o.length && width < o.width) ||
        (length < o.width && width < o.length))
        {
            stackable = true;
        }
    return stackable;
}

bool card::operator == (const card& o) const
{
    bool equals = false;
    if ((length == o.length && width == o.width) ||
        (length == o.width && width == o.length))
        {
            equals = true;
        }
    return equals;
}

ostream & leavature::operator <<(ostream &os, const card &cd)
{
    cout << cd.length << " x " << cd.width;
    return os;
}

istream & leavature::operator>>(istream &is, card &cd)
{
    char X = 0;
    return is >> cd.length >> X >> cd.width;

}



// Struct Creature
bool creature::operator > (const creature& o) const
{
    return card > o.card;
}

bool creature::operator < (const creature& o) const
{
    return card < o.card;
}

bool creature::operator == (const creature& o) const
{
    return card == o.card;
}

ostream &leavature::operator<<(ostream &os, const creature &ct)
{
    cout << ct.name << " " << ct.type << " " << ct.card;
    return os;
}

istream &leavature::operator>>(istream &is, creature &ct)
{
    return is >> ct.name >> ct.type >> ct.card;
}



// Class Atlantian
vector<string> Atlantian::things;

Atlantian::Atlantian(creature atlantian)
{
    self = atlantian;
}

creature Atlantian::befriend()
{
    return self;
}

string Atlantian::greeting() 
{
    string message;
    int size = things.size();
    if (size == 0) 
    {
        message= "Atlantians have no THINGS to say to you.\n";
    }
    else 
    {
        //srand(time(NULL));
        message = things.at(rand()%size);
    }
    return message;
}



// Bucky
Bucky::Bucky()
{
    bye = "I knew that place was fishy!";

}

bool Bucky::isStackFull()
{
    return stack.size() == 6;
}

bool Bucky::isPocketFull()
{
    return pocket.size() == 14;
}

bool Bucky::isMaxVisits()
{
    return visits.size() == 150;
}

void Bucky::displayStack()
{
    vector<creature> itr_stack;
    while (!stack.empty())
    {
        creature ct = stack.top();
        stack.pop(); 
        itr_stack.push_back(ct);
    }
    for (vector<creature>::iterator i = itr_stack.begin(); i != itr_stack.end(); i++)
    {
        cout << *i << endl;
        stack.push(*i);
    }
    
}

void Bucky::displayPocket()
{
    for (vector<creature>::iterator i = pocket.begin(); i != pocket.end(); i++)
    {
        cout << i->name << endl;
    }
}
 
void Bucky::meetAtlantian(Atlantian atlantian)
{
    creature it = atlantian.befriend();
    cout << it.name << " the " << it.type << ": " <<  "\"" << atlantian.greeting() << "\"" << endl;
    cout << "Here is my card: " << it.card << endl << endl;
    visits.push_back(it);

    if (isStackable(it.card))
    {
        stack.push(it);
    }
    if (isNewCreature(it))
    {
        pocket.push_back(it);
    }
}

bool Bucky::isStackable(struct card newCard)
{
    vector<creature> itr_stack;
    int foward_index = 0;
    int backward_index = stack.size();
    int equal_index = -1;
    int n = 0;

    while (!stack.empty())
    {
        creature ct = stack.top();
        stack.pop(); 
        itr_stack.push_back(ct);
    }

    // Forward loop for index
    for (vector<creature>::iterator i = itr_stack.begin(); i != itr_stack.end(); i++)
    {
        if (newCard < i->card) 
        {
            foward_index++;
        }

        if (newCard == i->card) 
        {
            equal_index = n;
        }
        n++;
    }

    // Backwards loop for index
    for (vector<creature>::reverse_iterator i = itr_stack.rbegin(); i != itr_stack.rend(); i++ ) 
    { 
        if (newCard > i->card) 
        {
            backward_index--;
        }
    }

    for (vector<creature>::iterator i = itr_stack.begin(); i != itr_stack.end(); i++)
    {
        stack.push(*i);
    }


    if (foward_index == backward_index && equal_index == -1)
    {
        //Debuging
        /* cout << "Newcard: "  << newCard << endl ;
        cout << "Foward_index: " << foward_index << endl;
        cout << "Backward_index: " << backward_index << endl;
        cout << "Equals_index: " << equal_index <<  endl;
        displayStack(); 
        cout << endl; */
        return true;
    }

    return false;
}

bool Bucky::isNewCreature(struct creature atlantian)
{
    for (vector<creature>::iterator i = pocket.begin(); i != pocket.end(); i++)
    {
        if (i->type == atlantian.type)
        {
            return false;
        }
    }
    return true;
}

int Bucky::stackSize()
{
    return stack.size();
}

int Bucky::pocketSize()
{
    return pocket.size();
}

int Bucky::visitSize()
{
    return visits.size();
}

string Bucky::goodbye()
{
    return bye;
}
