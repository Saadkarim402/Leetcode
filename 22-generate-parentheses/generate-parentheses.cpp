class Solution {
    private:
    void solve(vector<string>&v,int n,string &cur,int op,int cl){
        //base case
        if(op==n&&cl==n){
            v.push_back(cur);
            return;
        }

        //opening breacket
        if(op<n){
            cur+='(';
            solve(v,n,cur,op+1,cl);
            cur.pop_back();
        }
        if(cl<op){
            cur+=')';
            solve(v,n,cur,op,cl+1);
            cur.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string cur;
        solve(v,n,cur,0,0);
        return v;

        
    }
};