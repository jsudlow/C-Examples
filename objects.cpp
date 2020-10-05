#include <bits/stdc++.h> 
#include <typeinfo>



using namespace std; 
class IntArr 
{ 
    // Access specifier 
    public: 
    // Data Members 
     
    int array_size;
    int *arrPtr;
    int stackPtr = 0;

    //Default Constructor
    IntArr()
    {
        //cout << "Default Constructor Called\n";
        array_size = 0;
        
        arrPtr = NULL;

    }
    
    // Overloading [] operator to access elements in array style 
    int& operator[](int); 

      // Overloaded assignment
     IntArr& operator= (const IntArr &IntArr);


   

   //copy constructor
    IntArr(const IntArr &i2) {
       // cout << "copy constructor activated \n";
        array_size = i2.array_size;
        arrPtr = i2.arrPtr;
        stackPtr = i2.stackPtr;
        
    }
    //parametrizied constructor
      IntArr(int x) 
    { 
        //cout << "Parametrized Constructor called" << endl; 
        array_size=x;
        arrPtr = new int[x];
           
    } 
  
     //Destructor
    ~IntArr(){
   // cout<<"Destructor is called"<<endl;
    delete[] arrPtr;
   }


    // Member Functions() 
    

    void grow() 
    {
        
        int newSize = array_size * 2;
        array_size = newSize;
        stackPtr *=2;
        int *arrPtr2 = new int[array_size];
        for(int i = 0; i <= (array_size+1); i++) {
            arrPtr2[i] = 0;
        }
        for(int i = 0; i <=array_size/2; i++) {
            arrPtr2[i] = arrPtr[i];
        }
        arrPtr = arrPtr2;
    }
    int getSize() 
    {
      
        return stackPtr;
    }

    void push_back(int val)
    {
  
        arrPtr[stackPtr] = val;
        stackPtr++;
    }
    void pop_back()
    {

        arrPtr[stackPtr-1] = 0;
        stackPtr--;
    }
}; 
 
 int& IntArr::operator[](int index) 
{ 
    //if (index >= size) { 
      //  cout << "Array index out of bound, exiting"; 
        //exit(0); 
    //} 
    return *(arrPtr + index); 
}  

IntArr& IntArr::operator= (const IntArr &intarr)
{
    // do the deep copy
    arrPtr = intarr.arrPtr;
    stackPtr = intarr.stackPtr;
    array_size = intarr.array_size;
      
    // return the existing object so we can chain this operator
    return *this;
}
int main() { 
    cout << endl;
    IntArr a{5};

    for(int i = 0; i < 5; i++) {a.push_back((i+1)*5);}
    cout << "Array size: " << a.getSize() << endl;

    cout << "Array A: ";
    for(int i=0; i<a.getSize(); i++) { cout << a[i] << " "; }
    cout << endl << endl;
     

    cout << "Pushing 30\n"; 
    a.push_back(30);
    cout << "Pushing 35 \n";
    a.push_back(35);

    cout << "Array size: " << a.getSize() << endl;

        
    IntArr b = a;
    
    
    cout << "Array A: ";
    for(int i =0; i<a.getSize(); i++) { cout << a[i] << " ";}
    
    cout << "\nPArray B: ";
    for(int i =0; i<a.getSize(); i++) { cout << b[i] << " ";}
    cout << endl << endl;

    
    a.pop_back();
    cout << "Array size: " << a.getSize() << endl;

   

    b = a;
    
    cout << "Array A: ";
    for(int i =0; i<a.getSize(); i++) { cout << a[i] << " ";}
    cout << "\nArray B: ";
    for(int i =0; i<a.getSize(); i++) { cout << b[i] << " ";}
    cout << endl << endl;
    
    cout << "growing array b \n";
    b.grow();
    cout << "\nArray B: ";
    for(int i =0; i<b.getSize(); i++) { cout << b[i] << " ";}

    
    cout << endl;   
    return 0; 
} 