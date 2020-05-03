//https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/798/
/*  1 0 2 2 1 0
    ^         ^
    L         H
    M

    Mid != 0 || 2
    Mid++

    1 0 2 2 1 0
    ^ ^       ^
    L M       H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 1 2 2 1 0
      ^ ^     ^
      L M     H

    Mid == 2
    Swap High and Mid
    High--

    0 1 0 2 1 2
      ^ ^   ^
      L M   H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 0 1 2 1 2
        ^ ^ ^
        L M H

    Mid == 2
    Swap High and Mid
    High--

    0 0 1 1 2 2
        ^ ^
        L M
          H

    Mid <= High is our exit case
*/
void sortColors(vector<int>& nums) {
    int l{}, mid{}, h{nums.size() - 1};
    while (mid <= h)
        if (nums[mid] == 0)
            swap(nums[mid++], nums[l++]);
        else if (nums[mid] == 1)
            mid++;
        else 
            swap(nums[mid], nums[h--]);
}
// 这个应该可以继续优化，如果low和hi的值已经知道是0或者是1的话
