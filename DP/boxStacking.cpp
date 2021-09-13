class Solution{
    public:

    //dp[j][k] -> at base area j*k how much stacking can be done
 
    int maxHeight(int height[],int width[],int length[],int n){
        vector<vector<int>> dp(101,vector<int> (101,0));
        int ans = 0;
        for(int j = 1; j <= 100; j++){
            for(int k = 1; k <= j; k++){
                for(int i = 0; i < n; i++){
                    if(max(height[i],width[i]) < j && min(height[i],width[i]) < k)
                        dp[j][k] = max(dp[j][k] , length[i] + dp[max(height[i],width[i])][min(height[i],width[i])]);

                    if(max(length[i],width[i]) < j && min(length[i],width[i]) < k)
                        dp[j][k] = max(dp[j][k] , height[i] + dp[max(length[i],width[i])][min(length[i],width[i])]);
                        
                    if(max(height[i],length[i]) < j && min(height[i],length[i]) < k)
                        dp[j][k] = max(dp[j][k] , width[i] + dp[max(height[i],length[i])][min(height[i],length[i])]);

                }
            
                ans = max(ans, dp[j][k]);
            }
        }
        
        return ans;
    }
};

//or

// Instead of checking for all j*k , Sort area in desc order and apply LIS O(n^3) -> O(n^2)

bool myComp(vector<int> &box1, vector<int> &box2){
    return box1[0]*box1[1] > box2[0]*box2[1];
}

class Solution{
    public:
    int maxHeight(int height[],int width[],int length[],int n){
        vector<vector<int>> boxes;
        int res = 0;
        for(int i = 0; i < n; i++){
            vector<int> box(3);
            vector<int> temp(3);
            temp[0] = height[i];
            temp[1] = width[i];
            temp[2] = length[i];

            for(int j = 0; j < 3; j++){
                box[0] = min(temp[(j+1)%3], temp[(j+2)%3]);
                box[1] = max(temp[(j+1)%3], temp[(j+2)%3]);
                box[2] = temp[j];
                boxes.push_back(box);
            }

        }

        sort(boxes.begin(), boxes.end(), myComp);
        vector<int> ans(boxes.size());
        
        for(int i = 0; i < boxes.size(); i++){
            ans[i] = boxes[i][2];
            for(int j = 0; j < i; j++){
                if(boxes[j][0] > boxes[i][0] && boxes[j][1] > boxes[i][1]){
                    ans[i] = max(ans[i],ans[j] + boxes[i][2]);
                }
            }
            res = max(res, ans[i]);
        }

        return res;
    }
};
