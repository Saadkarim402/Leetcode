class Solution {
public:
    bool rotateString(string s, string goal) {
        string ans=s+s;
        int l=goal.size();
        int n=s.size();
        if(l!=n)return false;
        for(int i=0;i<n;i++){
            string temp=ans.substr(i,l);
            cout<<temp<<endl;
            if(goal==temp)return true;
        }
        return false; 
    }
};