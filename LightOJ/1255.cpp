#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int pre[N+5];

int FindSubstring(string a, string b)
{
    int j=0;
    pre[0]=0;
    for(int i=1; i<b.size(); i++)
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
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]==b[j]) j++;
        else if(j>0)
        {
            j=pre[j-1];
            i--;
        }
        if(j==b.size())
        {
            k++;
            j=pre[j-1];
        }
    }

    return k;
}


int main()
{
    //freopen("input.txt", "r", stdin);

    int t,tc,n,m;
    string a,b;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>a;
        cin>>b;
        n=FindSubstring(a,b);

        cout<<"Case "<<tc<<": "<<n<<endl;
    }

    return 0;
}

