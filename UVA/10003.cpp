#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n;
int a[100];
int dp[N][N];

void ini()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            dp[i][j]=-1;
}

int chain(int l, int r)
{
    if(dp[l][r]!=-1) return dp[l][r];

    bool get=false;
    int k, m = INT_MAX;
    for(int j=0; j<n; j++)
    {
        if(a[j]<=l || a[j]>=r) continue;
        k = chain(l, a[j]) + chain(a[j], r) + r-l;
        m = min(m, k);
        get=true;
    }
    if(!get) m=0;
    return dp[l][r]=m;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int l;

    while(cin>>l && l)
    {
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];

        ini();
        int m = chain(0,l);

        cout<<"The minimum cutting is "<<m<<".\n";
    }

    return 0;
}
