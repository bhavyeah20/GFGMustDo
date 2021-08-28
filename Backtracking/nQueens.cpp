class Solution{
public:
    
    vector<bool> row, col, leftD, rightD;
    vector<vector<int>> ans;
    
    bool isSafe(int i, int j, int n){
        return !row[i] && !col[j] && !rightD[n-1+i-j] && !leftD[i+j];
    }
    
    void solve(int j, int n, vector<int> &curr){
        if(j == n){
            ans.push_back(curr);
            return ;
        }
        
        for(int i = 0; i < n; i++){
            if(isSafe(i,j,n)){
                curr.push_back(i+1);
                row[i] = 1;
                col[j] = 1;
                leftD[i+j] = 1;
                rightD[n-1+i-j] = 1;
                solve(j+1,n,curr);
                
                curr.pop_back();
                row[i] = 0;
                col[j] = 0;
                leftD[i+j] = 0;
                rightD[n-1+i-j] = 0;
                
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // return in sorted order as well
        row.resize(n,0);
        col.resize(n,0);
        leftD.resize(2*n-1,0);
        rightD.resize(2*n-1,0);
        ans.clear();
        
        vector<int> curr;
        solve(0,n,curr);
        return ans;
        
        
    }
};
