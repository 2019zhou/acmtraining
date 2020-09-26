//https://leetcode.com/discuss/interview-experience/859710/sde-amazonreject-googleoffer


// my solution, effective
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int cur = -1;
        if(timeSeries.size() > 0){
            cur = timeSeries[0];
            ans += duration;
        }
        for(int i = 1;i < timeSeries.size(); i++){
            if(timeSeries[i] - cur >= duration){
                ans += duration; 
                cur = timeSeries[i];
            }
            else{
                ans =  ans + timeSeries[i] - cur;
                cur = timeSeries[i];
            }
        }
        return ans;
    }
};


// good start comeon