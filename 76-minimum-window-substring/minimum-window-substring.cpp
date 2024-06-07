class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int ele=mp.size();
        int l=0,r=0,min_len=1e9,st=-1,cnt=0;
        while(r<s.size()){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<min_len){
                    min_len=r-l+1;
                    st=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        if(st==-1){
            return "";
        }
        return s.substr(st,min_len);
    }
};