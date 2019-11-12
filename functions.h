//functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <functional>
using namespace std;



namespace leavature
{
    struct card {
        int length;
        int width;
        
        bool operator>(const card& o) const;
        bool operator<(const card &o) const;
        bool operator==(const card &o) const;
        friend ostream &operator<<(ostream &os, const struct leavature::card &cd);
        friend istream &operator>>(istream &is, struct leavature::card &cd);
    };


    struct creature {
        string name;
        string type;
        struct card card;

        bool operator>(const struct creature &o) const;
        bool operator<(const struct creature &o) const;
        bool operator==(const struct creature &o) const;

        friend ostream &operator<<(ostream &os, const struct leavature::creature &ct);
        friend istream &operator>>(istream &is, struct leavature::creature &ct);
    };

    class Atlantian {
        private:
            creature self;
        public:
            static vector<string> things;
            Atlantian(struct creature atlantian);   
            creature befriend();
            string greeting();

    };

    class Bucky {
        private:
            string bye;
            priority_queue<creature> stack;
            vector<creature> pocket;
            vector<creature> visits;
            bool isStackable(struct card newCard);
            bool isNewCreature(struct creature atlantian);
    
        public:
            Bucky();
            void meetAtlantian(Atlantian atlantian);
            bool isStackFull();
            bool isPocketFull();
            bool isMaxVisits();
            void displayPocket();
            void displayStack();
            int stackSize();
            int pocketSize();
            int visitSize();
            string goodbye();
    };
}
#endif
