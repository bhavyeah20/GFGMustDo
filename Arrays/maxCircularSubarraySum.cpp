
class Solution{
    public:
    int circularSubarraySum(int arr[], int n){
        
        // your code here
        int maxx = INT_MIN, minn = INT_MAX;
        bool pos = 0;
        int curr = 0, total = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] >= 0){
                pos = 1;
            }
            
            curr += arr[i];
            maxx = max(curr, maxx);
            
            if(curr < 0){
                curr = 0;
            }
        }
        
        curr = 0;
        
        for(int i = 0; i < n; i++){
            total += arr[i];
            curr += arr[i];
            minn = min(curr, minn);
            
            if(curr > 0){
                curr = 0;
            }
        }
        
        
        if(!pos){
            return *max_element(arr,arr+n);
        }
        return max(maxx, total-minn);
        
        
    }
};