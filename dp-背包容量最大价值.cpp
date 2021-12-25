using namespace std;

int main()
{
    int num;
    cin>>num;
    int values[1000];
    int weights[1000];
    int c;
    cin>>c;
    for(int i=0;i<num;i++)  cin>>values[i];
    for(int i=0;i<num;i++)  cin>>weights[i];
    int dp[1000][1000];
    for(int i=0;i<=num;i++)  dp[i][0]=0;
    for(int j=0;j<=c;j++)   dp[0][j]=0;
    for(int i=1;i<=num;i++)
        for(int j=1;j<=c;j++)
        {
            if(weights[i]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i]]+values[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    cout<<dp[num][c]<<endl;
}
