class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(),nums.end()); 

        int size = nums.size(); 

        while(k--){
            int min = minHeap.top(); 
            minHeap.pop(); 

            for(int i = 0 ; i < size ; i++){
                if(nums[i] == min){
                    nums[i] *= multiplier ; 
                    minHeap.push(nums[i]) ; 
                    break ;  
                }
            }

        }

        return nums; 

        
        
    }
};