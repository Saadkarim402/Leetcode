class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]>=0)st.push(a[i]);
            else{
            while(!st.empty()&&st.top()>0&&-a[i]>st.top()){
                st.pop();
            }
            if(!st.empty()){
                if(st.top()==-a[i]){
                    st.pop();
                    continue;
                }
                if(st.top()<0){
                    st.push(a[i]);
                }
            }
            else st.push(a[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};