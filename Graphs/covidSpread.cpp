class Solution {
public:
    
    int n, m;
    vector<vector<int>> dist;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    bool inBound(int i, int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int spread(vector<vector<int>> &arr){
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 2){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int time = 0, maxTime = 0;
        while(!q.empty()){
            int sz = q.size();
            time++;
            for(int t = 0; t < sz; t++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int i = x + dx[k], j = y + dy[k];
                    if(inBound(i,j) && dist[i][j] == -1 && arr[i][j] != 0){
                        q.push(make_pair(i,j));
                        dist[i][j] = time;
                        maxTime = time;
                    }
                }
            }
        }
        
        return maxTime;
    }

    int helpaterp(vector<vector<int>> arr){
        n = arr.size();
        m = arr[0].size();
        dist.resize(n, vector<int> (m,-1));
        
        int maxTime = spread(arr);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 1 && dist[i][j] == -1)
                    return -1;
            }
        }
        
        return maxTime;
        
    }
};
