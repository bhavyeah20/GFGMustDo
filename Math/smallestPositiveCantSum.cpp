class Solution
{   
public:

    long long sum(vector<long long> &array){
        long long res = 1;

        for(int i = 0; i < array.size() && array[i] <= res; i++){
            res += array[i];
        }

        return res;
    }

    long long smallestpositive(vector<long long> array, int n){ 
        sort(array.begin(), array.end());
        return sum(array);
    }

};