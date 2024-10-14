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

int main(){

}