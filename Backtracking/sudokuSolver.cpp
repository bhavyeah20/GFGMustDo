class Solution {
public:
    bool row[9][9], col[9][9], box[9][9];
    
    bool solve(vector<vector<char>> &board, int i, int j){
        if(i == 9)
            return true;
        
        if(board[i][j] != '.'){
            if(j+1 < 9){
                return solve(board,i,j+1);
            }
            
            else{
                return solve(board,i+1,0);
            }
        }
        
        for(int num = 1; num <= 9; num++){
            
            if(row[i][num-1] == 0 && col[j][num-1] == 0 && box[(i/3) * 3 + j/3][num-1] == 0){
                row[i][num-1] = 1;
                col[j][num-1] = 1;
                box[(i/3) * 3 + j/3][num-1] = 1;
                board[i][j] = num + '0';
                if(j+1 < 9){
                    if(solve(board,i,j+1))
                        return true;
                }

                else{
                    if(solve(board,i+1,0))
                        return true;
                }
            
                row[i][num-1] = 0;
                col[j][num-1] = 0;
                box[(i/3) * 3 + j/3][num-1] = 0;
                board[i][j] = '.';
            }
        }
            return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(box,0,sizeof(box));
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j]-'0';
                    row[i][num-1] = 1;
                    col[j][num-1] = 1;
                    box[(i/3) * 3 + j/3][num-1] = 1;
                }
            }
        }
        
        solve(board,0,0);

    }
};