#define ll long long
class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    
    long long countWays(int n){
        vector<ll> dp(n+1,0);
        dp[0] = 1;
        ll mod = 1e9+7;
        
        for(int i = 1; i <= n; i++){
            if(i-3>=0)
                dp[i] += dp[i-3] % mod;
            if(i-2>=0)
                dp[i] += dp[i-2] % mod;
            if(i-1>=0)
                dp[i] += dp[i-1] % mod;
        }
        
        return dp[n] % mod;
        
    }
};
