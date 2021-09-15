
class Solution{
public:
    int equalPartition(int n, int arr[]){
    
    
    
    	int sum = 0;
    	for(int i = 0; i < n; i++)
    		sum += arr[i];
    		
    		
    	if(sum & 1)
    	    return 0;
    	    
    	    sum /= 2;
    		
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

	    return dp[n][sum];
	} 
};
