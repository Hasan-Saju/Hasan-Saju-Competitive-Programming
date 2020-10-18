#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int dp[6000][6000],vis[6000][6000];

int lcs(int i,int j)
{
    if(i>=s1.size() or j>=s2.size()) return 0;
    if(vis[i][j]) return dp[i][j];

    vis[i][j] = 1;

    if(s1[i]==s2[j])
    {
        return dp[i][j] = 1 + lcs(i+1,j+1);
    }
    else
    {
        return dp[i][j] = max(lcs(i+1,j),lcs(i,j+1));
    }
}

int main()
{

    while(getline(cin,s1))
    {
        getline(cin,s2);
        cout<<lcs(0,0)<<"\n";
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
    }
}
