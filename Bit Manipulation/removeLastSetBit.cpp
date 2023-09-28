/*

  Question :- remove the last set bit of a given number

-------Approach--------
  to remove that set bit first we have to find out which bit is 1 if we start from the lest side, when we encounter that bit, we will remove that
the code is provided below

----------------------Edit ----------------------------------------------
a direct way is to that by doing n&n-1  this will give you direct answer
-------------------------------------------------------------------------

*/




#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int mask = 1;
    while(mask <= n){ // till mask is less then number
        if((mask & n) == mask){ // if & of n and mask is equal to mask itself that mean that bit is 1 where mask bit is 1
            n = mask^n; // we will remove that bit by this 
            break;
        }
        //else
        mask = mask<<1; // till we don't find out that bit , keep moving mask bitby 1 bit left 
    }
    
    cout<<n<<endl;
    return 0;
}
