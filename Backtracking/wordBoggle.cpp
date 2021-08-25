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
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    dfs(board,i,j,curr);
                }
            }
        }
        return ans;
           
        
    }
};


//or


class Solution {
public:
    int n;
    int m;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<string> ans;
    
    bool inBound(int i, int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    struct TrieNode{
        unordered_map<char, TrieNode*> child;
        bool endOfWord;
        
        TrieNode(){
            child.clear();
            endOfWord = false;
        }
    };
    
    TrieNode *insert(vector<string> &words){
        TrieNode *root = new TrieNode();
        for(auto word: words){
            TrieNode *curr = root;
            for(auto ch: word){
                if(curr->child.find(ch) == curr->child.end()){
                    TrieNode *temp = new TrieNode();
                    curr->child[ch] = temp;
                }
                
                curr = curr->child[ch];
            }
            
            curr->endOfWord = true;
        }
        
        return root;
    }
    
    void dfs(vector<vector<char>> &board, int i, int j, string &s, TrieNode *curr){
        char ch = board[i][j];
        
        if(ch == '#' || curr->child.find(ch) == curr->child.end()){
            return ;
        }
        
        curr = curr->child[ch];
        s.push_back(board[i][j]);
        board[i][j] = '#';
        
        if(curr->endOfWord){
            ans.push_back(s);
            curr->endOfWord = false;
        }
        
        for(int k = 0; k < 4; k++){
            int newX = i + dx[k];
            int newY = j + dy[k];
            
            if(inBound(newX, newY)){
                dfs(board,newX,newY,s,curr);
            }
        }
        
        board[i][j] = ch;
        s.pop_back();
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        ans.clear();
        TrieNode *root = insert(words);

        string s = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(board,i,j,s,root);
            }
        }
        return ans;
           
    }
};