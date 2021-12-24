int mindeal(int num,int* row,int* line)
{
    int dp[1000][1000];
    for(int i=0;i<num;i++)  dp[i][i]=0;
    for(int k=2;k<=num;k++)
        for(int i=0;i<num-k+1;i++)
        {
            int min=INT_MAX;
            for(int mid=i;mid<i+k-1;mid++)
                min=dp[i][mid]+dp[mid+1][i+k-1]+row[i]*line[mid]*line[i+k-1]<min?dp[i][mid]+dp[mid+1][i+k-1]+row[i]*line[mid]*line[i+k-1]:min;
            dp[i][i+k-1]=min;
        }
    return dp[0][num-1];
}
int main()
{
    int num;
    cin>>num;
    int row[1000];
    int line[1000];
    for(int i=0;i<num;i++)
    {
        cin>>row[i];
        cin>>line[i];
    }
    int res=mindeal(num, row, line);
    cout<<res<<endl;
    return res;
}
