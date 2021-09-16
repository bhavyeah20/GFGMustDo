class Solution{
    public:

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};	

    int minimumCostPath(vector<vector<int>>& grid) {
    	int n = grid.size();
    	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    	vector<vector<int>> dist(n, vector<int> (n,1e8));

    	dist[0][0] = grid[0][0];
    	pq.push({dist[0][0],{0,0}});
    
    	while(!pq.empty()){
    		int currDist = pq.top().first;
    		int i = pq.top().second.first, j = pq.top().second.second;

    		pq.pop();
    		for(int k = 0; k < 4; k++){
    			int newI = i + dx[k], newJ = j + dy[k];
    			if(newI >= 0 && newJ >= 0 && newI < n && newJ < n && (currDist + grid[newI][newJ] < dist[newI][newJ])){
    				dist[newI][newJ] = currDist + grid[newI][newJ]; 
    				pq.push({dist[newI][newJ], {newI, newJ}});
    			}
    		}
    	}

    	return dist[n-1][n-1];

    }
};