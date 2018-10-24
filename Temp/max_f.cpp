#include<iostream>
#include<algorithm>
using namespace std;
long long dp[16][16];
long long ans[16];
void init(int n,int k)
{
    long long num;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num);
        ans[i]=num;
        sum+=num;
        dp[i][0]=sum;//在没有使用乘号的情况全部使用加法
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    init(n,k);
    for(int i=1;i<=n;i++)//n个数
    {
        for(int j=1;j<=i-1;j++)//最多有i-1个乘号，数量级较小，就不剪枝了
        {
            for(int p=2;p<=i;p++)//第j个乘号插入的位置，如果和前面的乘号位置重叠了，也不影响，还是原来的dp[i][j]
            {
                dp[i][j]=max(dp[i][j],dp[p-1][j-1]*(dp[i][0]-dp[p-1][0]));//从车如位置到i的和，一起乘总比一个乘要大
            }
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}
