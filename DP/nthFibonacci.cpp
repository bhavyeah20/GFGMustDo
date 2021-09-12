#define ll long long 
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        ll f1 = 1, f2 = 1, f = 1;
        ll mod = 1e9+7;
        n -= 2;
        for(int i = 1; i <= n; i++){
            f = f1 % mod + f2 % mod;
            f1 = f2 % mod;
            f2 = f % mod;
        }
        
        return f % mod;
    }
};
