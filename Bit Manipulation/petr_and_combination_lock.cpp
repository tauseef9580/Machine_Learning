

//Question -- https://codeforces.com/problemset/problem/1097/B


#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    
    //Apporach -- just like Power sum
    /*
    where we have to print all the subsets of a given array,
    we will use that logic to solve this 
    we will make an analogy that if bits is zero ---- then sign is negative
                                 if bits is one  ---- then sign is positive
    by this all combinations will be tested 
    
    */
    
    bool flag = false;
    
    for(int num = 0; num<(1<<n)-1; num++){
        int sum = 0;
        for(int bit = 0; bit<n; bit++){
            if(num & (1<<bit))
                sum += arr[bit];
                
            else
                sum -= arr[bit];
        }
        
        if(sum%360 == 0)
            flag = true;
    }
    
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
        
    return 0;
}
