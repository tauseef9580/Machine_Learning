//SWapping two numbers using XOR operator

#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b = 7;
    
    cout<<"a is: "<<a<<" and b is: "<<b<<endl;
    // swap the number i.e. after swapping a = 7 and b = 5
    
    //step1
    a = a^b;
    
    //step2
    b = a^b;  // b = (a^b)^b ,since a = a^b . this will give us b = a
    
    //step3
    a = a^b; // a = (a^b)^a , since now b = a
    
    cout<<"after swapping "<<endl<<"a is: "<<a<<" and b is: "<<b<<endl;

    return 0;
}
  
