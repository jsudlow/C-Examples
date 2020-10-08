#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;



int main()
{
	int rounds = 10000;
	int stayWins = 0;
	int stayLosses = 0;
	int switchWins = 0;
	int switchLosses = 0;
	int winningDoor;
	int chosenDoor;

    random_device rd;     // used to initialise (seed) engine
    mt19937 mt(rd());    // random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> dist(1, 3); // guaranteed unbiased


for(int i = 0; i < rounds; i++) {
    chosenDoor = dist(mt);
    winningDoor = dist(mt);

	cout << "The chosen door is:" << chosenDoor << '\n';
	
    cout << "{debug}winning door is " << winningDoor << '\n';
    
	//after we select a door monty needs to open a door with the goat
	//what door monty opens depends on what the player intially selected

	//if the player selects the door with the prize, monty needs to open another door with the goat 
    if (chosenDoor == winningDoor) {
    	//open the door to the right
    	if (chosenDoor + 1 > 3) {
           cout << "Door 1 Opens revealing a goat" << '\n';
    	}
    	else {
    		cout << "Door " << chosenDoor +1 << " Opens revealing a goat" << '\n';
    	}

    }
   //if the player picks a non prize door ie goat a or goat b
   else {
       if (chosenDoor == 1 && winningDoor == 2) {
       	   cout <<" Door 3 opens revealing a goat" << '\n';
       }
       if (chosenDoor == 1 && winningDoor == 3) {
       	   cout << " Door 2 opens revealing a goat" << '\n' ;
       }

       if (chosenDoor == 2 && winningDoor == 1) {
       	   cout <<" Door 3 opens revealing a goat" << '\n';
       }
       if (chosenDoor == 2 && winningDoor == 3) {
       	   cout << " Door 1 opens revealing a goat" << '\n';
       }

        if (chosenDoor == 3 && winningDoor == 1) {
       	   cout <<" Door 2 opens revealing a goat" << '\n';
       }
       if (chosenDoor == 3 && winningDoor == 2) {
       	   cout << " Door 1 opens revealing a goat" << '\n';
       }

   	   }

   	   cout << "Do you want to switch or keep your choice???" << '\n';
   	   //we say NO
   	   //we are going to simulate if we simply stay and never switch the door first
       //determine if we have won or lost
   

       //cout << "You have chosen to stay with door " << chosenDoor << '\n';
       if(chosenDoor == winningDoor) {
       	cout << "You win staying";
       	stayWins++;
       }
       else {
       	cout << "You Lose staying";
       	stayLosses++;
       }


        //We Say Sure we'll switch
   if(chosenDoor == winningDoor) {
   	//if we picked the prize door and we switch, then we lose
   	cout << "You lose switching";
   	switchLosses++;
   }
   else {
   	//if we did not pick the prize door and we switch, we win!
   	cout << "You Win switching";
   	switchWins++;
   }
   


   }
   cout << "\nAmount of Wins Staying: " << stayWins; 
   cout << "Total Games: " <<  rounds;
   float winPercentage = (float)stayWins/ (float)rounds;
   cout << " Final Win Percentage: " << winPercentage << "% ";


  

   cout << "\nAmount of Wins Switching: " << switchWins; 
   cout << "Total Games: " << rounds;
   float winPercentageSwitch = (float)switchWins/ (float)rounds;
   cout << " Final Win Percentage: " << winPercentageSwitch << "% ";

   



}

