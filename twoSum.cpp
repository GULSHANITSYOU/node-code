class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, list<int>> mp;
        int size = nums.size();

        for (int i = 0; i < size; i++)
            mp[nums[i]].push_back(i);

        for (int i = 0; i < size; i++) {
            int rem = target - nums[i];

            if (mp.contains(rem) && rem != nums[i])
                return {i, mp[rem].back()};
            else if (rem == nums[i] && mp[rem].size() >= 2)
                return {i, mp[rem].back()};
        }

        return {0, 0};
    }
};