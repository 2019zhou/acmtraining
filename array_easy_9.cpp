//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/

// 这个是google小哥哥示范面试的题目，他示范的太优秀了，可以有空再看看
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x] = target - x;
        }
        vector<int> res;
        for(int i = 0;i < nums.size();i++){
            if(mp.find(mp[nums[i]]) == mp.end()) continue;
            else res.push_back(i);
        }
        if(res.size() > 2){
            for(int i = 0;i < res.size();i++){
                if(nums[res[i]] == target/2 ) res.erase(res.begin() + i);
            }
        }
        return res;
    }
};

// use a hashmap to fasten the speed
// 注意开始还是有两个样例没很好的通过，一个 [3,2,6] 3 会输出3个 [3,3]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};

//Note that each time before we add num to mp, we search for target - num first and so we will not hit the same element.
// 还有vector<int> 的方法也非常值得借鉴
