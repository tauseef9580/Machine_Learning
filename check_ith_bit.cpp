/*
	Question ---- Given n and i, check that ith bit of n is set or not(i.e. 1 or not)

------------Approach------------
by doing & of n and a number whose only ith bit is 1, if the result is 0 , i.e. ith bit of n was 0, otherwise 1

*/


#include <iostream>
using namespace std;

int main()
{
    int n,i;
    cin>>n>>i;
    
    int mask = (1<<i);
    
    if(n&mask  != 0)
        cout<<"YES"<<endl;     
    else
        cout<<"NO"<<endl;
    return 0;
}
