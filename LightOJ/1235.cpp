#include<bits/stdc++.h>
using namespace std;

int n,k;
int c[30];
vector <int> va, vc;

void roy(int i, int l, int val)
{
    if(val>k) return ;
    if(i==l)
    {
        if(l<n) va.push_back(val);
        else vc.push_back(val);
        return ;
    }
    roy(i+1, l, val);
    roy(i+1, l, val+c[i]);
    roy(i+1, l, val+c[i]+c[i]);
}

bool binary(int l, int r, int val)
{
    if(l==r) return (vc[l]==val);

    int m = (l+r)/2;
    if(vc[m+1]<=val) return binary(m+1, r, val);
    else return binary(l, m, val);
}


int main()
{
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,tc;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>k;

        for(int i=0; i<n; i++)
            cin>>c[i];

        va.clear();
        vc.clear();
        roy(0,n/2,0);
        roy(n/2,n,0);

        sort(vc.begin(), vc.end());

        int vaz = va.size();
        int vcz = vc.size();
        bool yes = false;
        for(int i=0; i<vaz && !yes; i++)
            yes |= binary(0, vcz-1, k-va[i]);

        if(yes) cout<<"Case "<<tc<<": Yes\n";
        else cout<<"Case "<<tc<<": No\n";
    }

    return 0;
}


