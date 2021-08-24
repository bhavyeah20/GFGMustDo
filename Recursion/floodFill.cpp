
class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    vector<vector<bool>> vis;
    void bfs(vector<vector<int>> &image, int sr,int sc, int newColor){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = true;
        while(!q.empty()){
            int i = q.front().first , j = q.front().second;
            q.pop();
            for(int it = 0; it < 4; it++){
                if(i+dx[it] >= 0 &&  j+dy[it] >= 0 && i+dx[it] < image.size() &&  j+dy[it] < 
                image[0].size() && !vis[i+dx[it]][j+dy[it]] && image[i+dx[it]][j+dy[it]] 
                    == image[i][j]){
                   vis[i+dx[it]][j+dy[it]] = true;
                   q.push({i+dx[it], j+dy[it]});
                }
            }
            image[i][j] = newColor;
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vis.clear();
        int n = image.size(), m = image[0].size();
        vis.resize(n, vector<bool> (m, false));
        bfs(image, sr, sc, newColor);
        
        return image;
    }
};
