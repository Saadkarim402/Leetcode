class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        long long ans=0;
        int m=1e9+7;
        for(int i=0;i<=n;i++){
        while(!st.empty()&&nums[st.top()]>(i==n?-2e9:nums[i])){
            int j=st.top();
            st.pop();
            long long k=(st.empty()?-1:st.top());
            long long  l=(i-j),r=(j-k);
            long long h=((l%m)*(r%m))%m;
            ans+=(nums[j]*h)%m;
            ans%=m;
        }
        st.push(i);
        }
        return ans;
    }
};