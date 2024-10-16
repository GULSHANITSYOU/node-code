#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int size = position.size();
        set<pair<int, int>> carsOnRoad;

        for (int i = 0; i < size; i++) {
            carsOnRoad.insert({position[i], speed[i]});
        }

        vector<float> TimeToReachTarget(size, 0);
        int i = 0;

        for (auto car : carsOnRoad) {
            int dis = target - car.first;
            int spd = car.second;
            TimeToReachTarget[i++] = (float)((float)(dis) / (float)(spd));
        }

        stack<float> stk;
        i = 0;

        while (i < size) {
            if (stk.empty() || stk.ftop() > TimeToReachTarget[i]) {
                stk.push(TimeToReachTarget[i++]);
            } else {
                stk.pop();
            }
        }

        return stk.size();
    }
};

// dp solution 
class Solution {
    int solvedp(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int mini = INT_MAX;
        for (const auto& coin : coins) {
            int ans = solvedp(coins, amount - coin, dp);
            if (ans != -1)
                mini = min(ans, mini);
        }

        if (INT_MAX != mini)
            dp[amount] = mini + 1;

        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        
        int size = coins.size() ; 
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0 ; 

        
        for(int i = 1 ; i <= amount ; i++ ){
            for(int j = 0 ; j < size ; j++){
                if(i - coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                dp[i]  = min(dp[i],1+dp[i-coins[j]]); 
            }
        }


        return dp[amount] != INT_MAX ? dp[amount] : -1 ; 
    }
};


int main(){

}