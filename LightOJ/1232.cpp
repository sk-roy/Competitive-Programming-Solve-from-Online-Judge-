#include<bits/stdc++.h>
using namespace std;

const int mod = 1e8+7;
int s[20000];
int c[200];


int main()
{
    int t,n,k;
    cin>>t;

    for(int tc=1; tc<=t; tc++)
    {
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>c[i];

        for(int i=0; i<=k; i++) s[i]=0;
        s[0]=1;

        for(int i=0; i<n; i++)
        {
            for(int j=c[i]; j<=k; j++)
            {
                s[j]+=s[j-c[i]];
                s[j]%=mod;
            }
        }

        cout<<"Case "<<tc<<": "<<s[k]<<endl;
    }

    return 0;
}
