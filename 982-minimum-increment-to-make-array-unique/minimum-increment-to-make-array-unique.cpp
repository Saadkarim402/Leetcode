class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int sm=nums[0];
        for(int i=0;i<nums.size();i++){
            ans+=max(0,sm-nums[i]);
            sm=max(sm+1,nums[i]+1);
        }
        return ans;   
    }
};