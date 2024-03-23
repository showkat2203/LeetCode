class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor = 0;
        for(auto x : nums){
            Xor ^= x;
        }
        for(int i = 0; i <= nums.size(); i++){
            Xor ^= i;
        }
        return Xor;
    }
};