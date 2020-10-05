#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


void importTable(string filepath, int** &table, int& rowCount, int& colCount) {
  
  string line;
  int lineCount = 0;
  

  //find the R and C values to setup the table  
  ifstream myfile (filepath);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
      //set the row and cols
      if(lineCount == 0) {rowCount = stoi(line);}
      if(lineCount == 1) {colCount = stoi(line);}
    
      lineCount++;
    }
    myfile.close();
  }

  else {
   cout << "Unable to open file";
   }
   //use row and cols to setup the table
   table = new int*[rowCount,colCount];

   //we need to initilize our values in the array to the proper settings
   for (int i = 0; i < rowCount; ++i) {
    table[i] = new int[colCount];
   }
  

  lineCount = 0;
  //lets add in the values
  ifstream myfile2 (filepath);
   if (myfile2.is_open())
  {
    while ( getline (myfile2,line) )
    {
      if(lineCount > 1) 
      {
      //cout << line << '\n';


      string word = "";
   int word_count = 0; 
   for (auto x : line) 
   { 
       if (x == ' ') 
       { 
       	if(word == "") {continue;}
           //cout << word << endl;

           //cout << "About to assign: " << word << "\n";
            //cout << "Word Count: " << word_count << "\n";
           //cout << "line Count: " << (lineCount -2 ) << "\n";
           
           table[(lineCount - 2)][word_count] = stoi(word);
           word = "";

           word_count++; 
       } 
       else
       { 
           word = word + x; 
       } 
   }  
   //cout << word << endl;
     //cout << "About to assign: " << word << "\n";
     //cout << "Word Count: " << word_count << "\n";
     //cout << "line Count: " << (lineCount -2) << "\n";
     table[(lineCount - 2)][word_count] = stoi(word);
     }
      //cout << "\n" << lineCount;
      
      lineCount++;
    }
    myfile2.close();
  }

  else {
   cout << "Unable to open file";
   }
  //table[3][5] = 120225;
  //cout << table[3][5];
	
}

void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void selectionSort(int *array, int size, int** rowReferences) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
         //placing in correct position
         swap(array[i], array[imin]);

         //just like when we had parrallel arrays, everytime we swap a column number with another, we also need to swap the rowReference posoition
         //so we can get the whole column to adjust 
         swap(rowReferences[i],rowReferences[imin]);
   }
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void sort(int** rowReferences, int rowCount, int colCount, int sortColumn) {
	cout << "Sorting on Column: " << sortColumn << "\n\n";

	//pull the column to be sorted out of the 2d table
	int column[rowCount];

	for(int i = 0; i < rowCount; i++) {
		column[i] = rowReferences[i][sortColumn];
    }
	
	
	
	//display(column,rowCount);

	selectionSort(column,rowCount,rowReferences);

	//display(column,rowCount);
	
}

void showTable(int** table, int rowCount, int colCount){

	for(int i = 0; i < rowCount; i++) {
		for(int j = 0; j < colCount; j++) {
			cout << *(table[i] + j) << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
	//cout << *table[0];
	//cout << *table[1];
	//cout << *table[2];
	//cout << *table[3];
}
int main() {

	//init row and col count 
    int rowCount;
    int colCount;
    
    //init table pointer
    int **table;

    //init row reference pointer
    int **rowReferences;

    //pass file path, table pointer, rowCount reference and colCount reference
	importTable("C:/eastbot/matrix_data.txt",table,rowCount,colCount);

    //load up the array of row references from the table
    for(int i = 0; i < rowCount; i++) {
		rowReferences[i] = *&table[i];
		//cout << rowReferences[i] << "\n";
	}

    showTable(rowReferences,rowCount,colCount); 
	sort(rowReferences, rowCount, colCount, 1);
    showTable(rowReferences,rowCount,colCount);
}