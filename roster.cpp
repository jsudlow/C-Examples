#include <iostream>
#include <string>

using namespace std;
string roster [10];

void insertArray(int position, string name) {
	//insert and move positions of array
   
   int size = 9;
   for(size; size>position; size--)
	{
		roster[size]=roster[size-1];
	}
	roster[position] = name;
	
}

int main() {
   int rosterSize = 0;
   while(rosterSize < 10) {


   	   string name;
       cout << "Enter name (or 'quit'): ";
       cin >> name;

       if(name.compare("quit") == 0) {
        cout << "Quit command found. Good bye";
       	break;         
       }

       //If this is our first time through the loop we can set the first name to index 0
       if(rosterSize == 0) {
       	roster[0] = name;
       }
       else {
       	//now we need to start considering what the values are
       	  for(int i = 0; i < 10; i++) {
       	  	//cout << "Comparing " << name << " With " << roster[i] << "\n";
       	  	int compareValue = name.compare(roster[i]);
       	  	//cout << compareValue << "\n";
       	  	if (compareValue == -1) {
       	  		insertArray(i,name);
       	  		break;
       	  	}
       	  	if(roster[i].length() == 0) {
       	  		insertArray(i,name);
       	  		break;
       	  	}

       	  }
        
       }
   rosterSize++;
   }


  

   cout << "\n" << "ROSTER" << "\n" << "----------" << "\n";
   for (int n=0 ; n<10 ; n++ )
  {
    if(roster[n].length() != 0) {
    cout << roster[n] << '\n';
    }
  }
    
	
}