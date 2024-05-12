class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size())return "0";
        vector<char>st;
        string ans="";
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty()&&k>0&&st.back()>num[i]){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        for (auto it: st) {
      if (it == '0' && ans.empty())
        continue;
      ans += it;
    }
          return ans.empty() ? "0" : ans;
       


        
    }
};