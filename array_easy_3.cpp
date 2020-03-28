//easy with vector function
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()) k = k%nums.size();
        nums.insert(nums.begin(), nums.end()-k, nums.end());
        while(k--) nums.pop_back();
    }
};

//k might be larger than nums.size()!!
//vector用法: 成批复制 vector_name.insert(position, iterator1, iterator2) 就是上面用的方法
//vector_name.insert(position, size, val) 重复的多个值为val的元素
//vector_name.insert (position, val) 插入一个元素
//vector_name.pop_back() 删除末尾元素
