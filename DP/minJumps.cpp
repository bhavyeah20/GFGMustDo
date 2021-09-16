class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
        
        int curBest = 0, bestPos = 0, attmpts = 0;
        for(int i = 0; i < n; i++){
            bestPos = max(bestPos, i+arr[i]);
            if(i == curBest && i != n-1){
                curBest = bestPos;
                attmpts++;
            }
        }
        
        return curBest >= n-1 ? attmpts : -1;
    }
};