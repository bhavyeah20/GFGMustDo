class Solution{

  public:
	int minDifference(int arr[], int n)  {
			int sum = 0;
			for(int i = 0; i < n; i++)
				sum += arr[i];
	    vector<vector<bool>> dp(n+1, vector<bool> (sum+1,0));

	    for(int i = 0; i <= n; i++)
	    	dp[i][0] = 1;

	    for(int i = 1; i <= n; i++){
	    	for(int j = 0; j <= sum; j++){
	    		if(arr[i-1] <= j){
	    			dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	    		}
	    		else
	    			dp[i][j] = dp[i-1][j];
	    	}
	    }

	    for(int j = sum/2; j >= 0; j--){
	    	if(dp[n][j])
	    		return sum-2*j;
	    }
	} 
};
