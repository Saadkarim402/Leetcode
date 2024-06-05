class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int l=0,r=0;
        while(r<n-1){
            int till_pt=0;
            for(int i=l;i<=r;i++){
                till_pt=max(till_pt,nums[i]+i);
            }
            l=r+1;
            r=till_pt;
            ans++;
        }
        return ans;
        
    }
};