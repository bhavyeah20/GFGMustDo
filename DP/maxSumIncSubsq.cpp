class Solution{
		

	public:
	int maxSumIS(int arr[], int n) {  
		vector<int> dp(n);
		int ans = arr[0];
		for(int i = 0; i < n; i++){
		   	dp[i] = arr[i];
		   	for(int j = 0; j < i; j++){
		       if(arr[j] < arr[i]){
		           dp[i] = max(dp[i], arr[i] + dp[j]);
		       }
		   }
		   ans = max(ans, dp[i]);
		}

		return ans;
		}
};
