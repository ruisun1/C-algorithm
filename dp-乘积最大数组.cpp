//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mine[20005];
        int maxe[20005];
        mine[0]=nums[0];
        maxe[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            mine[i]=min(maxe[i-1]*nums[i],min(mine[i-1]*nums[i],nums[i]));
            maxe[i]=max(maxe[i-1]*nums[i],max(mine[i-1]*nums[i],nums[i]));
            res=maxe[i]>res?maxe[i]:res;
        }
        return res;

    }
};
