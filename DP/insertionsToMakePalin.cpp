class Solution{   
public:
    int findMinInsertions(string s){
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n,0));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
            
        int len = 1;

        for(int k = 1; k < n; k++){
            for(int i = 0; i < n; i++){
                int j = i+k;
                if(j < n && s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                
                }
                
                else if(j < n)
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                
                if(j < n)
                len = max(len, dp[i][j]);
            }
        }
        
        return n-len;
    }
};