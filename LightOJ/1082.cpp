#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+50;
int a[N+5];
int tree[3*N+5];

void build(int n, int s, int e)
{
    if(s==e)
    {
        tree[n]=a[s];
        return ;
    }

    int left=n*2;
    int right=n*2+1;
    int m=(s+e)/2;

    build(left, s, m);
    build(right, m+1, e);

    tree[n]=min(tree[left],tree[right]);

}

int query(int n, int s, int e, int l, int r)
{
    if(l<=s && e<=r) return tree[n];
    if(e<l || s>r) return INT_MAX;

    int left=n*2;
    int right=n*2+1;
    int m=(s+e)/2;

    return min(query(left,s,m,l,r), query(right,m+1,e,l,r));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q,t,l,r;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>n>>q;
        for(int i=1; i<=n; i++)
            cin>>a[i];

        build(1,1,n);
        cout<<"Case "<<tc<<":\n";
        while(q--)
        {
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }

    return 0;
}

