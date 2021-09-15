class Solution
{
    public:
    
    vector<int> cuts;
    vector<int> dp;
    
    int helper(int n){
        if(n == 0)
            return 0;
            
        if(n < 0)
            return INT_MIN;
            
        if(dp[n] != -1)
            return dp[n];
        
        int res = INT_MIN;
        
        for(int i = 0; i < 3; i++){
            if(n-cuts[i] >= 0)
               res = max(res, 1 + helper(n-cuts[i]));
        }
        
        return dp[n] = res;
    }
    
    int maximizeTheCuts(int n, int x, int y, int z){
        cuts.clear();
        dp.clear();
        cuts.resize(3);
        dp.resize(n+1,-1);
        cuts[0] = x, cuts[1] = y, cuts[2] = z;
        return helper(n) < 0 ? 0 : helper(n);
    }
};