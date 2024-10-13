class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int size = nums.size(); 
        vector<int>sufix(size); 
        int suf = 1 ; 
        int pre = 1 ; 

        for(int i = size -1 ; i >= 0 ; i--){
            suf *= nums[i]; 
            sufix[i] = suf ; 
        }

        for(int i = 0 ; i < size ; i++){            
            sufix[i] = pre * ((i < size-1) ? sufix[i+1] : 1);           
            pre *= nums[i]; 
        }

        return sufix ;
        
    }
};