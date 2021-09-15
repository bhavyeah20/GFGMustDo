class Solution {
	public:
		int CountWays(string s){
        int mod = 1e9+7;
        int n = s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));

        dp[n] = 1;
        
        for(int i = n-1; i >= 0; i--){

            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }

            if(i+1 <= n)
                dp[i] += dp[i+1] % mod;

            if(i+2 <= n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
                dp[i] += dp[i+2] % mod;
        }

        return dp[0] % mod;
    }

};
