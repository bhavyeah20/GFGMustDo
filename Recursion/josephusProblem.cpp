class Solution {
public:
    int helper(int n, int k){
        
        if(n == 1)
            return 0;
        
        return ((helper(n-1,k)+k)%n);
    
    }
    
    int findTheWinner(int n, int k) {
        
        return helper(n,k) + 1;
    }
};

//or


int josephus(int n, int k){
   //Your code here
   unordered_set<int> vis;
   int i = 0;
   while(vis.size() != n-1){
       i = (i+1)%(n+1);
       if(!i)
        i++;
        
        if(!(vis.count(i)))
            cnt++;
            
        if(cnt == k){
            cnt = 0;
            vis.insert(i);
        }
   }
   
   for(int i = 1; i <= n; i++){
       if(!(vis.count(i)))
        return i;
   }
    
    
    
    
}