class Solution {
    public:
    vector<vector<int>>ans;
    void solve(int st,vector<int>nums,int n){
        //base case
        if(st==n){
            ans.push_back(nums);
            return;
        }
        //st is the starting pt we are changing 
        //we keep it fix 
        //and try to gen all perm after it 
        for(int i=st;i<n;i++){
            if(i==st||nums[i]!=nums[st]){
            swap(nums[i],nums[st]);
            solve(st+1,nums,n);
            //swap(nums[i],nums[st]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       // ans.clear();
        solve(0,nums,nums.size());
        return ans;

        
    }
};