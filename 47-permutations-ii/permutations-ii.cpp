class Solution {
    public:
    vector<vector<int>>res;
    void solve(int st,vector<int>nums){
        //base case
        if(st==nums.size()){
            res.push_back(nums);
            return;
        }
        //st is the starting pt we are changing 
        //we keep it fix 
        //and try to gen all perm after it 
        for(int i=st;i<nums.size();i++){
            if(i==st||nums[i]!=nums[st]){
            swap(nums[i],nums[st]);
            solve(st+1,nums);
            //swap(nums[i],nums[st]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       // ans.clear();
       int st=0;
        solve(st,nums);
        return res;

        
    }
};