class Solution {
public:
    int beautySum(string s) {
       int ans=0;
        for(int i=0;i<s.length()-1;i++){
            unordered_map<char,int>mapo;
            mapo[s[i]]++;
            for(int j=i+1;j<s.length();j++){
                mapo[s[j]]++;
                int max=-1;
                int min=501;
                for(auto it : mapo){
                    if(it.second>max){
                        max=it.second;
                    }
                    if(it.second<min){
                        min=it.second;
                    }
                }
                ans=ans+max-min;
            }
        }
        return ans;
        
    }

};