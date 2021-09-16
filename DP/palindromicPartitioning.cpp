class Solution{
public:
    vector<vector<bool>> isPalin;
    vector<int> dp;

    int palindromicPartition(string s){
        int n = s.length();
        dp.clear();
        isPalin.clear();
        dp.resize(n,-1);
        isPalin.resize(n, vector<bool> (n,0));

        for(int i = 0; i < n; i++)
            isPalin[i][i] = 1;

        for(int k = 1; k < n; k++){
            for(int i = 0; i < n; i++){
                int j = i+k;
                if(j < n && s[i] == s[j] && (j-i == 1 || isPalin[i+1][j-1])){
                    isPalin[i][j] = 1;
                }
            }
        }

        for(int i = n-1; i >= 0; i--){
            if(isPalin[i][n-1])
                dp[i] = 0;

            for(int j = i; j < n-1; j++){
                if(isPalin[i][j]){
                    dp[i] = min(dp[i], 1 + dp[j+1]);
                }
            }
        }

        return dp[0];
    }

};