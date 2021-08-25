// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    int n;
    int m;
    unordered_set<string> mp;
    vector<vector<bool>> vis;
    vector<string> ans;
    int dx[8] = {0,1,1,1,0,-1,-1,-1};
    int dy[8] = {1,1,0,-1,-1,-1,0,1};
    
    bool inBound(int i, int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void dfs(vector<vector<char>> &board, int i, int j, string &curr){
        
        curr.push_back(board[i][j]);
        vis[i][j] = 1;


        if(mp.count(curr)){
            mp.erase(curr);
            ans.push_back(curr);
        }
        
        for(int k = 0; k < 8; k++){
            int newX = i + dx[k];
            int newY = j + dy[k];
            
            if(inBound(newX, newY) && !vis[newX][newY]){
                dfs(board,newX,newY,curr);
            }
        }
        
        vis[i][j] = 0;
        curr.pop_back();
    }

    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
        // Code here
        n = board.size();
        m = board[0].size();
        mp.clear();
        ans.clear();
        vis.resize(n, vector<bool> (m,false));
        for(auto word: dictionary)
            mp.insert(word);
           
       string curr = "";
       dfs(board,0,0,curr);
           
       return ans;
           
        
    }
};

// { Driver Code Starts.

int main() {
   
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    
}
  // } Driver Code Ends