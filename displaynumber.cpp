#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;




int displayProblemAndGetAnswer(int top, int bottom, char op) {
	
    

     // The top and bottom numbers to be displayed in the problem.
    //
	
	
	// The answer to the problem and the user's guess.
	//
	int answer;
	int guess;

    // A flag to indicate whether or not the user entered an expected operator.
    //
    bool badOperator = false;
    
		
	
	// Display the appropriate problem to the user, get their response, and compute
	// the correct answer.
	//
	switch (op) {
	case '+':
	 	cout << setw(5) << top << endl;
	 	cout << "+ " << setw(3) << bottom << endl;
	 	cin >> guess;
	 	
	 	answer = top + bottom;
	    break;
	    
	case '-':
	 	cout << setw(5) << top << endl;
	 	cout << "- " << setw(3) << bottom << endl;
	 	cin >> guess;
	 	
	 	answer = top - bottom;
	    break;
	    
	case '*':
	 	cout << setw(5) << top << endl;
	 	cout << "* " << setw(3) << bottom << endl;
	 	cin >> guess;
	 	
	 	answer = top * bottom;
	    break;
	    
	default:
	    // If the user entered an unexpected operator, flag the situation.
	    //
		badOperator = true;
	}


    // If the selected operator was appropriate, tell the user whether they were 
    // right or wrong. If we encountered a bad operator, inform the user.
    //
	if (!badOperator) {
	
		if (answer == guess) {
			cout << "Correct!" << endl;
		} else {
			cout << "Incorrect." << endl;
		}
	
	} else {
	
		cout << "You selected an unknown operator: " << op << endl;
		
	}
	
	
	return 0;

}


int main() {
 


  
  displayProblemAndGetAnswer (123,45,'+');
  

   
	
}