class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>st;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<=n;i++){
        while(!st.empty()&&nums[st.top()]>(i==n?-2e9:nums[i])){
            int j=st.top();
            st.pop();
            int k=(st.empty()?-1:st.top());
            ans-=(long)nums[j]*(i-j)*(j-k);
        }
        st.push(i);
        }
        st=stack<int>();
        for(int i=0;i<=n;i++){
        while(!st.empty()&&nums[st.top()]<(i==n?2e9:nums[i])){
            int j=st.top();
            st.pop();
            int k=(st.empty()?-1:st.top());
            ans+=(long)nums[j]*(i-j)*(j-k);
        }
        st.push(i);
        }
        return ans;


        
    }
};