#include<bits/stdc++.h>
using namespace std;

unsigned int w;
unsigned int a[50];
vector <unsigned int> v[2];

void roy(int index, int last, unsigned int weight, int konta)
{
    //cout<<index<<" "<<last<<" "<<weight<<" "<<konta<<endl;
    if(weight>w) return ;
    if(index==last)
    {
        v[konta].push_back(weight);
        return ;
    }

    roy(index+1, last, weight, konta);
    roy(index+1, last, weight+a[index], konta);
    return ;
}

int binary(int l, int r, unsigned int val)
{
    if(l==r) return l;

    int m=(l+r)/2;
    if(v[1][m+1]<=val) return binary(m+1, r, val);
    else return binary(l, m, val);
}


int main()
{
    //freopen("input.txt", "r", stdin);

    int t,n,tc;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>w;
        for(int i=0; i<n; i++)
            cin>>a[i];
        if(n==1)
        {
            if(a[0]<=w) cout<<"Case "<<tc<<": 2"<<endl;
            else cout<<"Case "<<tc<<": 1"<<endl;
            continue;
        }
        v[0].clear();
        v[1].clear();
        roy(0, n/2, 0, 0);
        roy(n/2, n, 0, 1);

        sort(v[0].begin(),v[0].end());
        v[0].erase(v[0].begin());
        sort(v[1].begin(), v[1].end());

        int vz1=v[0].size();
        int vz2=v[1].size();
        int sum=vz1+vz2;
        /*
        cout<<"Size: "<<vz1<<" "<<vz2<<endl;
        for(int i=0; i<vz1; i++) cout<<v[0][i]<<" ";
        cout<<endl;
        for(int i=0; i<vz2; i++) cout<<v[1][i]<<" ";
        cout<<endl;
        */


        for(int i=0; i<vz1; i++)
        {
            int l = binary(0, vz2-1, w-v[0][i]);
            sum+=l;
        }
        cout<<"Case "<<tc<<": "<<sum<<endl;
    }

    return 0;
}
