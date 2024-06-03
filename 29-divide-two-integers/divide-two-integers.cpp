class Solution {
public:
    int divide(int p, int q) {
        bool f=true;
        if(p>=0&&q<0)f=false;
        if(p<=0&&q>0)f=false;

        long long n=abs(p);
        long long d=abs(q);
        long long ans=0;

        while(n>=d){
            int c=0;
            while(n>=(d<<(c+1))){
                c++;
            }
            ans+=1<<c;
            n-=(d<<c);
        }
        if(ans==(1<<31)&&f){
            return INT_MAX;
        }
        if(ans==(1<<31)&&!f){
            return INT_MIN;
        }
        if(f){
            return ans;
        }
        return -ans;


        
    }
};