class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int res = 0;

        for (const auto& num : nums) {
            int curr = num;
            int len = 0;

            while (st.contains(curr)) {
                len++;
                st.erase(curr++);
            }

            curr = num - 1;

            while (st.contains(curr)) {
                len++;
                st.erase(curr--);
            }

            res = max(res, len);
        }

        return res;
    }
};