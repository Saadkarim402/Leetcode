class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>>v;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());

        string ans="";
        for(auto it:v){
            int k=it.first;
            while(k--){
                ans+=it.second;
            }
        }
        return ans;  
    }
};