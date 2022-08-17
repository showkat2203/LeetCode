class Solution {
public:
    
    int my_lower_bound(vector<int> & numbers, int low, int high, int sz, int key)
    {
        while( low < high )
        {
            int mid = low + (high - low) / 2;
            
            if( key <= numbers[mid]  )
                high = mid;
            else 
                low = mid + 1;
        }
        
        if( low < sz && numbers[low] < key )
            low++;
        return low;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans_pos;
        
        int sz = numbers.size();
        
        for(int i = 0; i < sz; i++ )
        {
            int key = target - numbers[i];
            
            int key_pos = my_lower_bound(numbers, i + 1, sz - 1, sz - 1, key);
            
            if( numbers[i] + numbers[key_pos] == target )
            {
                ans_pos.push_back(i + 1);
                ans_pos.push_back(key_pos + 1);
                break;
            }
        }
        
        return ans_pos;
    }
};