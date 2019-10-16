#include<bits/stdc++.h>
using namespace std;

const int sz = 1e6;

bool flag[sz+5];
int prime[sz+5];

int seive()
{
    for(int i=3; i*i<sz; i+=2)
        if(!flag[i])
            for(int j=i*i; j<sz; j+=i)
                flag[j]=1;
    prime[0]=2;
    int total=1;
    for(int i=3; i<sz; i+=2)
        if(!flag[i])
            prime[total++]=i;
    return total;
}


int CountDiv(int n, int total)
{
    int div=1;
    for(int k=0; k<total && n!=1; k++)
    {
        int m=0;
        while(n%prime[k]==0)
        {
            m++;
            n/=prime[k];
        }
        div*= (m+1);
    }
    return div;
}

int main()
{
    int total=seive();

    int t,l,r,p,m,n;
    map <int,int> mp;

    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>l>>r;

        int d=0,h;
        for(int j=l; j<=r; j++)
        {
            if(!mp[j]) mp[j]= CountDiv(j,total);

            if(mp[j]>d)
            {
                h=j;
                d=mp[j];
            }
        }
        cout<<"Between "<<l<<" and "<<r<<", "<<h<<" has a maximum of "<<d<<" divisors."<<endl;
        //for(int j=l; j<=r;j++)
          //  cout<<j<<" "<<mp[j]<<endl;
    }


    return 0;
}

