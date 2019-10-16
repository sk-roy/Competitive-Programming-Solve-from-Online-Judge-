#include<bits/stdc++.h>
using namespace std;

int ten[10];

bool check(int n, int k)
{
    if(k==2 && n>99) return 0;
    if(k==4 && n>9999) return 0;
    if(k==6 && n>999999) return 0;

    int a=n%ten[k/2];
    int b=n/ten[k/2];
    if((a+b)*(a+b)==n) return 1;
    else return 0;
}


int main()
{
    int i,j,k,n;

    vector <int> v[10];
    ten[0]=1;
    for(i=1; i<=4; i++) ten[i]=ten[i-1]*10;
    //cout<<"Roy"<<endl;
    for(i=0; (i*i)<1000000000; i++)
    {
        k=i*i;
        for(j=2; j<=8; j+=2)
        {
            if(check(k,j)) v[j].push_back(k);
            //cout<<i<<" "<<j<<endl;
        }
    }

    k=v[8].size();
    v[8].erase(v[8].begin()+k-1);

    while(cin>>n)
    {
        //cout<<"Size: "<<v[n].size()<<endl;
        for(i=0; i<v[n].size(); i++)
        {
            k=v[n][i];
            j=0;
            while(k>0)
            {
                k/=10;
                j++;
            }
            for(k=0; k<(n-j); k++)
                cout<<0;
            if(v[n][i]) cout<<v[n][i];
            cout<<endl;
        }


    }

    return 0;
}
