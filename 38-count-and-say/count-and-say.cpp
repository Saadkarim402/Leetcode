class Solution {
public:
    string countAndSay(int n) {
        string prev="1";
        for(int i=2;i<=n;i++){
            int c=0;
            string temp="";
            for(int j=0;j<prev.size();j++){
                if(j==0||prev[j]==prev[j-1])c++;
                else{
                    temp+=to_string(c);
                    temp+=prev[j-1];
                    c=1;
                }
            }
            cout<<c<<endl;
            temp+=to_string(c);
            temp+=prev[(prev).size()-1];
            prev=temp;
            cout<<prev<<endl;
        }
        return prev;

        
    }
};