// reverse the list
ListNode * reverselist(ListNode * head){
    ListNode * prev = head;
    ListNode * curr = head;
    while(curr != null){
        ListNode* nexttemp = curr->next;
        curr.next = prev;
        prev = curr;
        curr = nexttemp;
    }
    return prev;
}

// kth largest number in an array
// use the quick sort way




// use the min stack
int findKthLargest(vector<int> & nums, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i:nums){
        if(pq.size() != k || i> pq.top()){
            if(pq.size() == k)
                pq.pop();
            pq.push();
        }
    }
    return pq.top();
}

// 注意sub sequence 和sub string的区别
// sub sequence指的是不连续的char组成的东西, sub string 说完全连续的东西

// 关键的思想应该是一个sliding windows, 然后维护i, j两个端点值。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> myset;
        if(n == 0) 
            return 0;
        
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n && j < n){
            if(myset.find(s[j])== myset.end()){
                myset.insert(s[j]);
                j++;
                ans = max(ans, j - i);
            }
            else{
                myset.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};

// 用unordered_map做应该可以提升一下效率


// 非常经典的two sum问题
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()){
                ans.push_back(mp[complement]);
                ans.push_back(i);
                return ans;
            }
            else
                mp[nums[i]] = i;
        }
        return ans;
    }
};

// 三数之和
// 大多数问题都出在如何去除重复
// native solution lies in here.
std::sort(res.begin(), res.end());
res.erase(unique(res.begin(), res.end()), res.end());


vector<vector<int>> threeSum(vector<int> num){
    sort(num.begin(), num.end());
    vector<vector<int>> ans;
    for(int i = 0;i < num.size();i++){
        int target = -num[i];
        int front = i + 1;
        int rear = num.size() -1;
        while(front < rear){
            int sum = num[front] + num[rear];
            if(sum > target){
                rear--;
            }else if(sum < target){
                front++;
            }else{
                vector<int> triple;
                triple.push_back(num[i]);
                triple.push_back(num[front]);
                triple.push_back(num[rear]);
                ans.push_back(triple);

                // deal with the second number for dup
                while(front < rear && num[front] == triple[1])
                    front++;
                
                // deal with the third number for dup
                while(front < rear && num[rear] == triple[2])
                    rear--;
            }
        }
        // deal with the first number for dup
        while(i + 1 < num.size() && num[i+1] == num[i])
            i++;
    }
    return ans;
}

//dfs number of islands模板
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    eraseisland(grid, i, j);
                }
            }
        }
        return islands;
    }
    
     void eraseisland(vector<vector<char>>& grid, int i, int j){
         int m = grid.size();
         int n = grid[0].size();
         if(i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0'){
             return;
         }
         grid[i][j] = '0';
         eraseisland(grid, i-1, j);
         eraseisland(grid, i+1, j);
         eraseisland(grid, i, j-1);
         eraseisland(grid, i, j+1);
     }
};

//