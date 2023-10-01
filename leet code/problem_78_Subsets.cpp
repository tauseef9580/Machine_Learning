//Question -- https://leetcode.com/problems/subsets/description/

// solution 👇👇

class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>&ans, vector<int>&v, int index){
        //base case
        //store the output whenever the input get empty in choice diagram
        if(index == nums.size()){
            ans.push_back(v);
            return;           
        }

        // as choice diagram , in one sub-output i am not considering the element
        vector<int> v1 = v;
        
        //in other, i am considering that element
        vector<int> v2 = v;
        v2.push_back(nums[index]);

        solve(nums,ans,v1,index+1);
        solve(nums,ans,v2,index+1);
        return;

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>v;
        solve(nums,ans,v,0);

        return ans;
    }
};
