#include <iostream>



using namespace std;



int main()
{


//define a value

int myFavoriteNumber = 420;

//If we want to find the memory address of my favorite number...we need a pointer
int * apointer;

//notice we use that 'address of' operator to get the memory address and not the value
apointer = &myFavoriteNumber;

//this is the actual memory address where 420 is stored...
cout << "Memory Address of the 420 value: " << apointer << "\n";


//now we can use the '*' or the 'de-reference operator'. This will retrieve the value at the
//memory address you supply it

cout << "Retrieving address by deferencing the pointer: " << *apointer;

//so this is how pointers, address or, and de reference work. 




}