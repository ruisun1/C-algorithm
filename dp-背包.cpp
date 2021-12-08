//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//每个正整数可以选择或者不选择，所以为0-1背包问题，看是否存在一个和为sum/2的选择
//dp[i][j]定义为0到j-1个数的一种选择方式能否将i那么大的空间填满
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)  sum+=nums[i];
        if(sum%2==1)
            return false;
        int target=sum/2;
        int len=nums.size();
        vector<vector<bool>> dp(target+1,vector<bool>(len+1,false)); //dp[i][j]代表0～j-1个物品能否装满i那么大的空间
        for(int j=0;j<=len;j++)
            dp[0][j]=true;
        for(int i=1;i<=target;i++)
            for(int j=1;j<=len;j++)
                if(i<nums[j-1]) dp[i][j]=dp[i][j-1];  //如果当前数已经大于空间了
                else    
                {
                    dp[i][j]=dp[i][j-1]|dp[i-nums[j-1]][j-1];//选择不放或者放，放的话剩余空间减小
                }
        return dp[target][len];

    }
};
