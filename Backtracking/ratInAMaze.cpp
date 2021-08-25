class Solution{
    public:
    vector<string> ans;
    int n;
    
    void solve(int i, int j, string &curr,vector<vector<int>> &maze){
        
        if(i == n-1 && j == n-1){
            ans.push_back(curr);
            return;
        }
        
        if(maze[i][j] != 1)
            return ;
        
        int org = maze[i][j];
        maze[i][j] = 2;
        
             
        if(i+1 < n && maze[i+1][j] == 1){
            curr.push_back('D');
            solve(i+1,j,curr,maze);
            curr.pop_back();
        }
        
       if(j-1 >= 0 && maze[i][j-1] == 1){
            curr.push_back('L');
            solve(i,j-1,curr,maze);
            curr.pop_back();
        }
            
        
        if(j+1 < n && maze[i][j+1] == 1){
            curr.push_back('R');
            solve(i,j+1,curr,maze);
            curr.pop_back();
        }
        
        if(i-1 >= 0 && maze[i-1][j] == 1){
            curr.push_back('U');
            solve(i-1,j,curr,maze);
            curr.pop_back();
        }
   
   
        
        maze[i][j] = org;
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int m) {
        // Your code goes here
        n = m;
        ans.clear();
        string curr = "";
        solve(0,0,curr,maze);
        return ans;
        
    }
};

    
