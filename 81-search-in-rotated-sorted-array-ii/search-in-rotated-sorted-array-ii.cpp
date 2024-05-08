class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=(h+l)/2;
            if(nums[mid]==tar)return true;
            if(nums[l]==nums[mid]&&nums[mid]==nums[h]){l++;h--;continue;}

            if(nums[l]<=nums[mid]){
                if(nums[l]<=tar&&nums[mid]>=tar){
                    h=mid-1;
                }
                else l=mid+1;
            }
            else{
                if(nums[mid]<=tar&&nums[h]>=tar){
                    l=mid+1;
                }
                else h=mid-1;
            }
        }
        return false;
    }
};