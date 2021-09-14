
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m){
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        // dp[i][j] -> lenght of lcs ending at i and j chars

        int res = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = 0;

                res = max(res, dp[i][j]);

            }
        }

        return res;
    }
};
