# stuck-in-atlantis
This project simulates the leaving conditions for Bucky who is now stuck in Atlantis. Bucky is require to randomly meet a finite set of Atlantians until he meets one of the three leavature conditions set by the Atlantis Visitors' Bureau. The results are printed acording to the condition that was met. In leave.cpp srand is seeded with 37.<br />

# Atlantian:
Upon meeting an Atlantian, the Atlantian randomly selects a greeting from things.txt. An atlantian is defined by of combination of name, breed and card. For example: Andy Seahorse 6 x 10

# Three conditions:
 collect 6 stackable cards <br />
 Meet 14 different "Type" of inhabitant <br />
 Make 150 interactions <br />

# Stackable:
Two cards are said to be stackable if the two dimension of one are less than the two dimesion of the other.
Ex: 6 x 10 and 7 x 4 are stackable
non-Ex: 1 x 3 and 5 x 1 are not stackable

# Compile:
clang++ -stdlib=libc++ -std=c++11 leave.cpp functions.cpp

# run:
./a.out
