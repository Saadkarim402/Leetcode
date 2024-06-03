class Solution {
    vector<vector<int>>ans;
    void solve(int st,vector<int>&nums,int n){
        if(st==n){
            ans.push_back(nums);
            return;
        }
        for(int i=st;i<n;i++){
            swap(nums[i],nums[st]);
            solve(st+1,nums,n);
            swap(nums[i],nums[st]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums,nums.size());
        return ans;
        
    }
};