class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c==')'){
                string temp="";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0;j<temp.size();j++){
                    st.push(temp[j]);
                }
            }
            else st.push(c);
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};