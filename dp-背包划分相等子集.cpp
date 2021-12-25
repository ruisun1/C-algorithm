//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//每个正整数可以选择或者不选择，所以为0-1背包问题，看是否存在一个和为sum/2的选择
//dp[i][j] 前i个物品是否有填满j那么大空间的选择
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int dp[205][20000];
        int sum=0;
        for(int i=0;i<nums.size();i++)  sum+=nums[i];
        if(sum%2!=0)    return false;
        for(int i=0;i<nums.size();i++)  dp[i][0]=0;
        for(int j=1;j<=sum;j++)
            dp[0][j]=(nums[0]==j);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i]<=j)
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]];
                else
                    dp[i][j]=dp[i-1][j];
            }
            if(dp[i][sum/2]==1)
                return true;
        }
        return false;
    }
};
