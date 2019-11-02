#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+6;
int s[N+5];
int cc[N+5];
int a[105],c[105];

int main()
{
    //freopen("input.txt", "r", stdin);

    int t,n,m,i,j,k;
    cin>>t;

    for(int tc=1; tc<=t; tc++)
    {
        cin>>n>>m;
        for(i=0; i<n; i++) cin>>a[i];
        for(i=0; i<n; i++) cin>>c[i];

        s[0]=1;
        for(int i=1; i<=m; i++) s[i]=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=m; j++) cc[j]=0;
            for(int j=a[i]; j<=m; j++)
            {
                if(s[j]) continue;
                if(s[j-a[i]] && cc[j-a[i]]<c[i])
                {
                    cc[j]=cc[j-a[i]]+1;
                    s[j]=1;
                }
            }
        }
        k=0;
        for(int i=1; i<=m; i++)
            if(s[i]) k++;

        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
