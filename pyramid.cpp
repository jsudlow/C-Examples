#include <iostream>
using namespace std;

int main() {


        for(int rows = 4; rows >= 1; --rows)
        {
            for(int column = rows; column > 0; --column)
            {
                
                //cout << rows << "\n";
                //cout << column << "\n";
               
                if(rows == 4){
                cout << rows + column + 2;
                cout << " ";
                continue;
                }
                if(rows <= 2) {
                    cout << rows + column -1;
                    cout << " ";
                    continue;
                }
                cout << rows + column;
                cout << " ";
                continue;
                 
              
        }
            cout << "\n";
    
}
        return 0;
    
}