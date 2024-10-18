#include <bits/stdc++.h>

int solvedp(vector<int> &nums, int i , vector<int>&dp) {

  if (i >= nums.size())
    return 0;
  if (i == nums.size() - 1)
    return nums[i];

  if (dp[i] != -1)
    return dp[i];

  int incl = solvedp(nums, i + 2,dp) + nums[i];
  int exlu = solvedp(nums, i + 1,dp);

  dp[i] = max(incl, exlu);
  return dp[i];
}

int maximumNonAdjacentSum(vector<int> &nums) {
     
    // vector<int>dp(nums.size(),-1); 
    // return solvedp(nums,0,dp); 
    //          in , ex
    
    int n = nums.size(); 
    int prev1 = nums[0]; 
    int prev2 = max(nums[0],nums[1]); 

    for(int i = 2 ; i < n ; i++){
      int inc = prev1+nums[i]; 
      int exc = prev2 + 0  ;
      prev1 = prev2 ; 
      prev2 = max(inc,exc) ;

     
    }

    return prev2; 


    

  /*
  if(i >= nums.size()){
      return currsum ;
  }

  //include current index
  int inc = maximumNonAdjacentSum(nums,i+2,currsum+nums[i]);
  // exclude current index
  int exc = maximumNonAdjacentSum(nums,i+1,currsum);

  return max(inc,exc) ;
  */
}