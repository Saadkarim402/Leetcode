class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        int ans=1e9;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[l]<=nums[h]){
                ans=min(ans,nums[l]);
                break;
            }
            //left part is sorted 
            if(nums[l]<=nums[mid]){
                ans=min(ans,nums[l]);
                l=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                h=mid-1;
            }
        }
        return ans;
        
    }
};