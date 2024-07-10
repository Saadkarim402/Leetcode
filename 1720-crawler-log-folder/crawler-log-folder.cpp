class Solution {
public:
    int minOperations(vector<string>& a) {
        int n=a.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(a[i]=="../"){
                c--;
                if(c<0)c=0;
            }
            else if(a[i]=="./"){
                continue;
            }
            else{
                c++;
            }
        }
        return max(0,c);

        
    }
};