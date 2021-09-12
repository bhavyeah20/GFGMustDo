class Solution
{
    public:
    vector<vector<int>> dp;
    int helper(int i, int n, vector<int> &arr){
        if(n == 0)
            return 0;
            
        if(i == -1)
            return INT_MIN + 100;
            
        if(dp[i][n] != -1)
            return dp[i][n];
        if(arr[i] <= n)
            return dp[i][n] = max(1 + helper(i,n-arr[i],arr), helper(i-1,n,arr));
            
        return dp[i][n] = helper(i-1,n,arr);
    }
    
    
    int maximizeTheCuts(int n, int x, int y, int z){
        vector<int> arr(3);
        arr[0] = min({x,y,z});
        arr[2] = max({x,y,z});
        arr[1] = x+y+z-arr[0]-arr[2];
        
        dp.clear();
        dp.resize(3, vector<int> (n+1,-1));
        
        return helper(2,n,arr) == INT_MIN + 100 ? 0 : helper(2,n,arr);
        
    }
};
