#include <iostream>
#include <string>
#include <fstream>

using namespace std;


// Converts the input in seconds to its minute and seconds equivalent.
//     inSeconds  : the time to convert in seconds
//     outMinutes : the number of minutes contained in the input
//     outSeconds : the number of remaining seconds contained in the input after taking

//
void toMinutesAndSeconds(int inSeconds, int &outMinutes, int &outSeconds) {

	outMinutes = inSeconds / 60;
	outSeconds = inSeconds % 60;
}

void iterateScores(string str, int runnerData[][10], int lineCount) 
{ 
   string word = "";
   int word_count = 0; 
   for (auto x : str) 
   { 
       if (x == ' ') 
       { 
           //cout << word << endl;
           runnerData[lineCount][word_count] = stoi(word);
           word = "";
           word_count++; 
       } 
       else
       { 
           word = word + x; 
       } 
   }  
   //cout << word << endl;
   runnerData[lineCount][9] = stoi(word); 
} 

// Reads the data from the specified file and stores it in the supplied table.
//     filepath    : a path to the file containing the data
//     runnerData  : the array to store the data read from the file
//     runnerCount : the number of rows of data in the file
//
void importData(string filepath, int runnerData[][10], int &runnerCount){
	
  string line;
  int lineCount = 0;
  ifstream myfile (filepath);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
      iterateScores(line, runnerData,lineCount);
      lineCount++;

    }
    myfile.close();
  }

  else {

   cout << "Unable to open file";
   } 
  
  //set the runner count via the referenced variable
  runnerCount = lineCount;

}

// Outputs a table including runner average and individual mile averages.
//     filepath    : a path to the file where the table should be written
//     runnerData  : the array containing the mile times in seconds
//     runnerCount : the number of rows of data in the table
//
void exportTable(string filepath, int runnerData[][10], int runnerCount) {
	ofstream outputFile(filepath);

	for(int i  = 0; i <= (runnerCount-1);i++) {
		//cout << i;
		int running_count = 0;
		int actual_miles = 0;
		for(int j = 0; j<=9;j++) {
			//cout << j;
			
			int seconds;
			int minutes;
			toMinutesAndSeconds(runnerData[i][j],minutes,seconds);
			if (runnerData[i][j] == 0) {
				outputFile << "     ";
			}
			else {
			char buffer[100];
			sprintf(buffer,"%d:%02d ", minutes, seconds);
			
			outputFile << buffer;
			running_count += runnerData[i][j];
			actual_miles++;
			//cout << minutes << ":"<<seconds << " ";
		    }
		}
		outputFile << "|";
		
		int seconds;
		int minutes;
		//toMinutesAndSeconds(running_count,seconds,minutes);
		//cout << minutes << ":" << seconds;
        int avgDivide = running_count/actual_miles;
        //cout << avgDivide;
        toMinutesAndSeconds(avgDivide,minutes,seconds);
        outputFile << " " << minutes << ":" << seconds;
		outputFile << "\n";
	}
	outputFile << "---------------------------------------------------\n";
	for(int i = 0; i <=9;i++) {
        int running_count = 0;
        int actual_count = 0;
		for (int j = 0; j<=(runnerCount-1);j++) {
			//cout << runnerData[j][i] << " ";
			running_count += runnerData[j][i];
			if (runnerData[j][i] == 0) {
				
				//cout << "data is zero";
			}
			else {
				actual_count += 1;
			}

		}
		int average = running_count / actual_count;
		//cout << average << " ";

		int seconds;
		int minutes;
		toMinutesAndSeconds(average,minutes,seconds);
		char buffer[100];
		sprintf(buffer,"%d:%02d ", minutes, seconds);
		outputFile << buffer;
	}
	outputFile.close();
}



int main() {

  //assume not more then 20 runners so we create 20 spots and 10 spots per runner
 int runnerData[20][10];
 int runnerCount;


 //import the data into a two dimensional array
 importData("C:/eastbot/rundata.txt", runnerData,runnerCount);

 //export the table
 exportTable("C:/eastbot/rundata_processed.txt",runnerData,runnerCount);
 

 }

