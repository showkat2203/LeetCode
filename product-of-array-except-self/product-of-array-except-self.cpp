class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int zero = 0, total = 1;
        for(int i = 0; i < nums.size(); i++){
            if( nums[i] == 0 ){
                zero++;
            }
            else{
                total *= nums[i];
            }
        }
        int pre = 1;
        for(int i = 0; i < nums.size(); i++ ){
            if( nums[i] == 0 ){
                if( zero - 1 > 0 ){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(total);
                }
            }
            else{
                int rgt = total / ( pre * nums[i]);
                if( zero ) ans.push_back(0);
                else
                    ans.push_back(pre * rgt);
                pre *= nums[i];
            }
        }

        return ans;
    }
};