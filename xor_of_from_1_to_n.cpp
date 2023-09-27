// one solution is using the loop - O(n)
//another is recursion - O(n)

// the best one is - O(1)
/*
here the analysis will play the role

let says for n = 8,
ans = 1^2^3^4^5^6^7^8

and here is the anaylsis,
for n = 1 , ans = 1
for n = 2, ans = 3 (2 + 1)
for n = 3, ans = 0
for n = 4, ans = 4 (n)
for n = 5, ans = 1
for n = 6, ans = 7(6 + 1)
for n = 7, ans = 0
for n = 8, ans = 8 (n)
, so it means there will be a pattern regarding what is the n/%4 is, based on that , answer will follow the pattern


  */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int modulo = n%4;
    int ans = (modulo == 0? n : (modulo == 1? 1 : (modulo == 2? n+1 : 0)));
    cout<<ans;
    return 0;
}
  
