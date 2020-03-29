# Python is forever insame
- Given two arrays, return the intersection of them
- Python use one line...
```
from collections import Counter
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return (Counter(nums1) & Counter(nums2)).elements()
```
- Why do I write so much of C++ kmp algorithm??

# C++ solution
```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> hashTable;
        for(auto x:nums1){
            hashTable.insert(x);
        }
        vector<int> res;
        for(auto x:nums2){
            const unordered_multiset<int>::iterator pointer = hashTable.find(x);
            if(pointer != hashTable.end()){
                res.push_back(x);
                hashTable.erase(pointer);
            }
        }
        return res;
    }
};
```
- Point: use of unordered_multiset
- 开始的时候读题错误，应该是找到集合中的相同元素就可以，但是不是集合，因为元素可以重复
