#include "functions.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
using namespace std;
using namespace leavature;


int main()
{
    cout << endl << "Atlantis leavature begin......" << endl << endl;
    vector<Atlantian> population;

    // Read in all the creatures
    fstream fin;
    fin.open("./creatures.txt");
    if (fin.is_open()) 
    {
        while (fin.peek() != EOF)
        {
            creature ct; 
            fin >> ct;
            Atlantian a(ct);
            population.push_back(ct); 
        }
        fin.close();
    }
    else
    {
        cout << "Failed to open creatures.txt..." << endl;
        return 1;
    }


    // Read in all things that can be said
    fstream tin;
    tin.open("./things.txt");
    if (tin.is_open())
    {
        string greeting;
        while (tin.peek() != EOF)
        {
            getline(tin, greeting, '\n');
            Atlantian::things.push_back(greeting);
        }
        tin.close();
    }
    else
    {
        cout << "Failed to open things file!" << endl;
        return 1;
    }

    /* 
        The files have been read
        Bucky is ready to explore atlantis
    */


    Bucky bucky;
    int population_size = population.size();
    srand(37);

    while (!bucky.isPocketFull() && !bucky.isStackFull() && !bucky.isMaxVisits())
    {
        int index = rand();
        Atlantian acquaintance = population.at(index%population_size);
        bucky.meetAtlantian(acquaintance);
    }

    cout << endl;
    cout << "Stack size: " << bucky.stackSize() << endl;
    cout << "Pocket size: " << bucky.pocketSize() << endl;
    cout << "Visits count: " << bucky.visitSize() <<  endl;
    cout << endl;


    if (bucky.isStackFull())
    {
        cout << "Stack is full:" << endl;
        bucky.displayStack();
    } 
    
      else if (bucky.isPocketFull())
    {
        cout << "Pocket is full:" << endl;
        bucky.displayPocket();
    } 
    else if (bucky.isMaxVisits())
    {
        cout << "You have completed 150 visits." <<endl;
    }

    int calories = 0;
    // Calories burned
    // function<void(float, float, float, float)> weight_watchers
    auto weight_watchers = [&](float ht, float wt, float dt, float temp) {
        calories =  (int)6 * wt + 2 * ht + 1 / temp + dt;
    };
    weight_watchers(6, 130, 6, 32);

    cout << endl << "Atlantis Visitors' Bureau: " << "\"" <<"Thank you for spending your vaction in Atlantis, you are free to go." << "\"" << endl;
    cout << "Bucky: " << "\"" << bucky.goodbye() << "\"" <<  endl;
    cout << "Atlantis Visitors' Bureau: " << "\"" << "Mr. Bucky, you burned "<< calories << " calories in the processs." << "\"" << endl << endl;
}
