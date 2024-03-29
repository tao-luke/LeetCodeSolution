class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last =  nums.size()-1;
        for(int i = nums.size()-1; i >= 0;i--){
            if (nums[i] + i >= last){
                last = i;
            }
        }
        return (last == 0);
    }
};