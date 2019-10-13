#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int pre[N+5];

int Solve(string a)
{
    int M = a.size();
    int j=0;
    pre[0]=0;
    string b=a;
    reverse(b.begin(), b.end());
    for(int i=1; i<M; i++)
    {
        if(b[j]==b[i])
        {
            pre[i]=j+1;
            j++;
        }
        else if(j==0)
        {
            pre[i]=0;
        }
        else
        {
            j=pre[j-1];
            i--;
        }
    }

    int k=0;
    j=0;
    for(int i=0; i+j+1<M; i++)
    {
        if(a[i]==b[j]) j++;
        else if(j>0)
        {
            j=pre[j-1];
            k=max(k, i-j);
            i--;
        }
        else k=max(k, i+1);
    }

    return k;
}


int main()
{
    //freopen("input.txt", "r", stdin);

    int t,tc,n;
    string s;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>s;
        n=Solve(s)+s.size();

        cout<<"Case "<<tc<<": "<<n<<"\n";
    }

    return 0;
}

