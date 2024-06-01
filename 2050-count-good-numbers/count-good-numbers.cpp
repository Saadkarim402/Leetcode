class Solution {
    int mod=1e9+7;
    private:
    long long solve(long long x,long long y){
        long long res=1;
        x=x%mod;
        if(x==0)return 0;
        while(y){
            if(y&1)res=(res*x)%mod;
            y/=2;
            x=(x*x)%mod;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long n1=n/2,n2=n-(n1);
        long long ans=((solve(4,n1)%mod)*(solve(5,n2)%mod))%mod;
        return ans;

        
    }
};