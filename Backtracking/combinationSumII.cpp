class Solution {
  public:

    vector<vector<int>> ans;
    void solve(vector<int> &A, int B, vector<int> &curr, int i, bool skipped){
        if(B == 0){
            ans.push_back(curr);
            return ;
        }
        
        if(B < 0 || i == A.size())
            return;
    
           
        if(A[i] <= B && (i == 0 || (i-1 >= 0 && ((A[i-1] != A[i]) || (A[i-1] == A[i] && !skipped))))){
           curr.push_back(A[i]);
           solve(A,B-A[i],curr,i+1,0);
           curr.pop_back();
        }
        
        solve(A,B,curr,i+1,1);
    }
    
    vector<vector<int> > combinationSum2(vector<int> &A, int B) {
        // Your code here
        ans.clear();
        vector<int> curr;
        sort(A.begin(), A.end());
        solve(A,B,curr,0,0);
        return ans;
    }
};

