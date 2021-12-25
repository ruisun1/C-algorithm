using namespace std;

int main()
{
    string str1;
    string str2;
    cin>>str1>>str2;
    int dp[1000][1000];
    int sum=0;
    dp[0][0]=0;
    for(int i=1;i<=str2.size();i++)
    {
        sum+=int(str2[i-1]);
        dp[0][i]=sum;
    }
    sum=0;
    for(int i=1;i<=str1.size();i++)
    {
        sum+=int(str1[i-1]);
        dp[i][0]=sum;
    }
    for(int i=1;i<=str1.size();i++)
        for(int j=1;j<=str2.size();j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i][j-1]+int(str2[j-1]),dp[i-1][j]+int(str1[i-1]));
        }
    cout<<dp[str1.size()][str2.size()]<<endl;
    
}
