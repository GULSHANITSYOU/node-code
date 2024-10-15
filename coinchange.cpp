class Solution {
    int RecursivSoloution(vector<int>& coins, int& amount, long long int makeAmount , unordered_map<int,int> &dp) {
        // base conditon
        if (makeAmount == amount)
            return 1;
        else if (makeAmount > amount)
            return -1;


        if(dp[makeAmount])
        return dp[makeAmount];

        int Min = INT_MAX;

        for (auto coin : coins) {
        int rec = RecursivSoloution(coins, amount, (makeAmount + coin) ,dp);

        if(rec != -1)
        Min = min(rec ,Min);

        }


        if(Min == INT_MAX){
        dp[makeAmount] = -1 ; 

         return -1 ;
        }
        dp[makeAmount] = Min+1 ; 

        return Min+1;
    }

public:
    long long coinChange(vector<int>& coins, int amount) {

        if (!amount)
            return 0;

            unordered_map<int,int>dp;

        int ans = RecursivSoloution(coins, amount, 0 , dp);

       
        
        return (ans == -1) ? ans : ans-1;
    }
};