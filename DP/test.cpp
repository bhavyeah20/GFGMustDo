#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl "\n" 


    vector<vector<int>> dp;
    
    int helper(int i, int j, string &s, string &t){
        if(i == -1 && j == -1){
            return 0;
        }
        
        if(i == -1 || j == -1)
            return 1000;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = helper(i-1,j-1,s,t);
            
        return dp[i][j] = 1 + min(helper(i-1,j-1,s,t), helper(i-1,j,s,t), helper(i,j-1,s,t));
    }
  
    int editDistance(string s, string t) {
        // Code here
        dp.clear();
        dp.resize(s.length(), vector<int> (t.length(), -1));
        return helper(s.length()-1, t.length()-1, s, t);
    }

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<editDistance("geek","gesek");


}