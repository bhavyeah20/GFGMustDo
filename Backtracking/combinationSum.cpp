class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> ans;
    void solve(vector<int> &A, int B, vector<int> &curr, int i){
        if(B == 0){
            ans.push_back(curr);
            return ;
        }
        
        if(B < 0 || i == A.size())
            return;
        
        if(i-1 >= 0 && A[i] == A[i-1]){
            solve(A,B,curr,i+1);
            return ;
        }
           
        if(A[i] <= B){
           curr.push_back(A[i]);
           solve(A,B-A[i],curr,i);
           curr.pop_back();
        }
        
        solve(A,B,curr,i+1);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        ans.clear();
        vector<int> curr;
        sort(A.begin(), A.end());
        solve(A,B,curr,0);
        return ans;
    }
};

