class Solution{
    public:
 
    int maxHeight(int height[],int width[],int length[],int n){
        vector<vector<int>> dp(101,vector<int> (101,0));
        int ans = 0;
        for(int j = 1; j <= 100; j++){
            for(int k = 1; k <= 100; k++){
                for(int i = 0; i < n; i++){
                    if(height[i] < j && width[i] < k)
                        dp[j][k] = max(dp[j][k] , length[i] + dp[height[i]][width[i]]);

                    if(height[i] < k && width[i] < j )
                        dp[j][k] = max(dp[j][k] , length[i] + dp[width[i]][height[i]]);

                    if(length[i] < j && width[i] < k )
                        dp[j][k] = max(dp[j][k] , height[i] + dp[length[i]][width[i]]);


                    if(length[i] < k && width[i] < j )
                        dp[j][k] = max(dp[j][k] , height[i] + dp[width[i]][length[i]]);

                    if(height[i] < j && length[i] < k)
                        dp[j][k] = max(dp[j][k] , width[i] + dp[height[i]][length[i]]);

                    if(height[i] < k && length[i] < j)
                        dp[j][k] = max(dp[j][k] , width[i] + dp[length[i]][height[i]]);
                }
            
                ans = max(ans, dp[j][k]);
            }
        }
        
        return ans;
    }
};
