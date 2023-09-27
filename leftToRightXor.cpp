/*
question :- Given a range of number (from left to right) print the XOR

-------APPROACH----------

since we know the XOR of from 1 to N(modulo of 4 trick)
Now, here
first find the XOR of 1 to Right, then 1 to Left-1, then the XOR of Both the result, by doing this the extra number that we are added
for solving the problem will comes two times , i.e. They will add 0 value to the result

*/
#include <stdio.h>

int main()
{
    int l,r;
    cin>>l>>r;
    
    // xor of 1 to l-1 & l to r and to compensate  1 to l-1 again
    // 1 to l-1 can be found out with the help of modulo of 4 approach
    // and also 1 to r too
    
    // find the xor of 1 to l-1
    int moduloLeft = l-1%4;
    int leftPart = (moduloLeft == 0? l-1 : (moduloLeft == 1? 1 : (moduloLeft == 2? l : 0)));

    int moduloRight = r%4;
    int rightPart = (moduloRight == 0? r : (moduloRight == 1? 1 : (moduloRight == 2? r+1 : 0)));

    int ans = leftPart^rightPart;
    cout<<ans<<endl;
  
    return 0;
}
