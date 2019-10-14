#include<bits/stdc++.h>
using namespace std;


vector <int> pm;

void seive()
{
    for(int i=2; i<100; i++)
    {
        bool no=false;
        for(int j=2; j*j<=i; j++)
        {
            if(i%j==0)
            {
                no=true;
                break;
            }
        }
        if(!no) pm.push_back(i);
    }
    return ;
}


int main()
{
    //freopen("0input.txt", "r", stdin);
   // freopen("0output.txt", "w", stdout);

    seive();

    int n;
    map <int,int> mp;

    while(cin>>n && n)
    {
        if(n==1)
        {
            printf("%3d! =\n", n);
            continue;
        }

        mp.clear();

        for(int i=2; i<=n; i++)
        {
            int m=i;
            for(int j=0; j<pm.size(); j++)
            {
                if(m==1) break;
                while(m%pm[j]==0)
                {
                    mp[pm[j]]++;
                    m/=pm[j];
                }
            }
        }
        int j=pm.size()-1;
        for(int i=j; i>=0; i--)
            if(mp[pm[i]]>0)
            {
                j=i;
                break;
            }

        printf("%3d! =", n);
        for(int i=0; i<=j; i++)
        {
            if(i>0 && i%15==0)
            {
                cout<<endl;
                printf("%9d", mp[pm[i]]);
                continue;
            }
            int k,m=mp[pm[i]];
            if(m>99) k=0;
            else if(m>9) k=1;
            else k=2;
            while(k)
            {
                cout<<" ";
                k--;
            }
            cout<<mp[pm[i]];
        }
        cout<<endl;


    }
    return 0;
}
