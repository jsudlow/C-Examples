#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;



// This function simulates a coin flip and randomly returns 'H' (heads) or 'T' (tails).
//    headWeight : the probability of a head. must be in [0, 1]
//
char flipCoin(double headWeight){
	int rounds = 30000;
	int heads = 0;
	int tails = 0;
	char lastFlip;
	char thisFlip;
	int sequenceStreak = 0;
    srand( (unsigned)time(NULL) );
    int adjustmentFactor = (headWeight - 0.5) * 100;
 
	for(int i = 0; i < rounds; i++) {
      
         int flip = rand() % 100;
         
         //apply the weight to our flip               
         if ((flip + adjustmentFactor) > 50) {
         	//set this flip
            thisFlip = 'T';

            //output the flip	
         	cout << 'T';

         	//increment our tails counter
         	tails++;
         	

         	//if this is the first time through the loop
         	//set lastFlip to the first flip we made
         	if(i == 0) {
         	lastFlip = 'T';
         }
                  
         }         
         else {
         	thisFlip = 'H';
         	cout << 'H';
         	heads++;
         	if(i == 0) {
         	lastFlip = 'H';
         }
         }

         //if its our first time through the loop we don't have enough to compare...this is like the fib sequence we need to get a view values before we can loop the sequence
         if(i == 0) {
         	continue;
         }

            
         //compare the two flips
         if (thisFlip == lastFlip) {
         	//If they match increaese the streak counter
         	sequenceStreak++;
         }
         //if they don't match set sequence counter back to zero.
         else {
         	sequenceStreak = 0;
         }


         //if sequenceCounter is greater  then 3 or 4....
         if (sequenceStreak > 2) {
         	cout <<"\n" << "Found Sequence of 4 repeating flips";
         	break;
         }
         //make sure we set thie flip to last flip before we go around in the loop again
          lastFlip = thisFlip;

	}
	
	//some stats so you can be assured the weights are correct
	cout << "\n" << "Heads Flips" << heads << "\n";
	cout << "Tails Flips" << tails << "\n";
	

    return 1;
}


int main() {
 
   flipCoin(0.5);
  
	
}