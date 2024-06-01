class Solution {
    void solve(int i,vector<vector<int>>&v,vector<int>&temp,vector<int>&nums,int k){
        if(k==0){
            v.push_back(temp);return;
        }

        if(k<0)return;

        if(i==nums.size())return;

        solve(i+1,v,temp,nums,k);
        
        temp.push_back(nums[i]);
        solve(i,v,temp,nums,k-nums[i]);
        temp.pop_back();   
        return;     
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        vector<vector<int>>v;
        vector<int>temp;
        solve(0,v,temp,nums,k);
        return v;
    }
};