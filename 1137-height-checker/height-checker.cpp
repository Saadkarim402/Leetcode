class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int>e;
        int c=0;
        for(int i=0;i<h.size();i++){
            e.push_back(h[i]);
        }
        sort(e.begin(),e.end());
        for(int i=0;i<h.size();i++){
            if(e[i]!=h[i])c++;
        }
        return c; 
    }
};