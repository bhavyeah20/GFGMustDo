class Solution{
	public:
	int MinSquares(int n){
	    vector<int> dp(n+1,1e9);
	    for(int i = 0; i*i <= n; i++){
	       dp[i*i] = 1;
	    }
	    
	    for(int i = 2; i <= n; i++){
	        if(dp[i] != 1){
    	        for(int j = 0; j * j <= i; j++){
    	            dp[i] = min(dp[i], 1 + dp[i-(j*j)]);
    	        }
	        }
	    }
	    
	    return dp[n];
	}
};
