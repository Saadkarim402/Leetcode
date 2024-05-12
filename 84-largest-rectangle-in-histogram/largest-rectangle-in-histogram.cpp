class Solution {
public:
    int largestRectangleArea(vector<int>&a) {
        stack<int>st;
        int n=a.size();
        int ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||a[st.top()]>=a[i])){
                int h=a[st.top()];
                st.pop();
                int w=i;
                if(!st.empty()) w=i-st.top()-1;
                ans=max(ans,w*h);
            }
            st.push(i);
        }
        return ans; 
    }
};