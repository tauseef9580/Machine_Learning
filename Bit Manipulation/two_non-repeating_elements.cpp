#include<iostream>


vector<int> singleNumber(vector<int> nums) 
    {
        // find XOR of all element to remove the N repeating number's
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
            ans = ans^nums[i]; 
        // after this only ans is ans1^ans2
        // so by doing all the steps we have to know ans1 and ans2
        // now part array such that ans1 lie in one part and ans2 in other
        int temp=1;
        while((temp&ans)==0)
        temp*=2;
        int num1,num2;
        num1=num2=0;
        for(int i=0; i<nums.size(); i++){
            if((temp&nums[i])==0)
            num1^=nums[i]; //2 2 4
            else 
            num2^=nums[i]; //1 3 1
        }
        vector<int>v(2);
        v[0]=num1;
        v[1]=num2;
        sort(v.begin(), v.end());
        return v;
    }

int main(){
  int n;
  cin>>n;
vector<int> nums;
for(int i=0; i<n; i++){
  cin>>nums[i];
vector<int> ans;
ans = singleNumber(nums);

return 0;
}
