class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int currcount = 0;
        int max = nums[nums.size()-1];
        if (nums.size() <= 2) {
            return nums[0];
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1] || i == nums.size()-1) {
                if (currcount > count) {
                    count = currcount;
                    currcount = 1;
                    max = nums[i-1];
                }
            } else {
                currcount++;
            }
        }
        return max;
    }
};
