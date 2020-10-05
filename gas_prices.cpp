#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void splitString(string str, string months[12], int lineCount, float prices[12]) 
{ 

   string word = "";
   int word_count = 0;
   float accumulator = 0; 
   for (auto x : str) 
   { 
       if (x == ' ') 
       { 
       	   if(word == "") { continue; }
           if(word_count == 0) { months[lineCount] = word; }
           if(word_count > 1) {accumulator += stof(word);}
           //cout << word << endl;
           //runnerData[lineCount][word_count] = stoi(word);
           word = "";
           word_count++; 
       } 
       else
       { 
           word = word + x; 
       } 
   }
   if(word !="") {
   	//cout << word;
   	word_count += 1;
   	accumulator += stof(word);
   }  
   //cout << "The accumulator is: " << accumulator;
   //cout << "The word count is: " << (word_count -2 );
   float avgGasPrice = accumulator / (word_count - 2);
   //cout << "The average as price is: " << avgGasPrice;
   prices[lineCount] = avgGasPrice;
   //cout << word << endl;
   //runnerData[lineCount][9] = stoi(word); 
} 

int main() {

  //assume not more then 20 runners so we create 20 spots and 10 spots per runner
 string months[12];
 float prices[12];

 string line;
  int lineCount = 0;
  ifstream myfile ("C:/eastbot/gas_input_data.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << '\n' <<  line << '\n';
      splitString(line, months,lineCount,prices);
      lineCount++;

    }
    myfile.close();
  }

  else {

   cout << "Unable to open file";
   } 




//directly sort via bubble sort...
 int i, j=0;
 float temp;
 string tempString;
  
   for(i = 0; i<12; i++) {
   for(j = i+1; j<12; j++)
   {
      if(prices[j] < prices[i]) {
         
         //sort the price array
         temp = prices[i];
         prices[i] = prices[j];
         prices[j] = temp;

         //don't forget when we move the price array we also have to move the month array in parrallel
         //this is almost the same thing except the temporary variable needs to be a string instead of a float
         tempString = months[i];
         months[i] = months[j];
         months[j] = tempString;
      }
   }

}


//display the table in reverse sort, set a custom width via the string size and set a fixed position of n digits to 3 for the decimal
   for(i = 11; i>=0; i--) {
      string strSize = months[i];
      cout << months[i] << ":" << setw(15-strSize.length()) << fixed << setprecision(3) << prices[i] <<"\n";
   }

 }

