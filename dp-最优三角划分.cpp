using namespace std;
int mintriange(int weight[1000][1000],int n)
{
    int dp[1000][1000];
    for(int i=1;i<=n;i++)    dp[i][i]=0;   #dp[i][i]代表从顶点i-1到顶点i的部分的最优划分值
    for(int r=2;r<=n;r++)
    {
        for(int i=1;i<=n-r+1;i++)
        {
            int j=i+r-1;
            dp[i][j]=dp[i+1][j]+weight[i-1][i]+weight[i][j]+weight[j][i-1];
            for(int mid=i+1;mid<j;mid++)     
            {
                dp[i][j]=dp[i][mid]+dp[mid+1][j]+weight[i-1][mid]+weight[mid][j]+weight[j][i-1]<dp[i][j]?dp[i][mid]+dp[mid+1][j]+weight[i-1][mid]+weight[mid][j]+weight[j][i-1]:dp[i][j];
            }
        }
    }
    return dp[1][n-1];
}
int main()
{
    int n;
    cin>>n;
    int weight[1000][1000];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cin>>weight[i][j];
            weight[j][i]=weight[i][j];
        }
    }
    int res=mintriange(weight, n);
    cout<<mintriange(weight, n)<<endl;
    return 0;
}
