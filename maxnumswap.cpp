class Solution {
public:
    int maximumSwap(int num) {

        string snum = to_string(num); 
        int size = snum.size(); 
        string res = snum; 

        for(int i = 0 ; i < size ; i++){
            for(int j = i+1; j < size ; j++){
                swap(snum[i],snum[j]);
                res = max(snum,res); 
                swap(snum[i],snum[j]);
            }
        }

        return stoi(res) ;
        
    }
};