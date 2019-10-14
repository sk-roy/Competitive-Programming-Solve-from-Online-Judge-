#include<bits/stdc++.h>
using namespace std;



int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);


    int n,i,k,j,m,sum;
    int a[105][105];
    int c[105][105];
    int sm[105];

    while(cin>>n)
    {
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                cin>>a[i][j];

        m=INT_MIN;
        for(i=0; i<n; i++)
        {
            for(k=0; k<n; k++) sm[k]=0;
            for(j=i; j<n; j++)
            {
                sum=0;
                for(k=0; k<n; k++) sm[k]+=a[k][j];
                for(k=0; k<n; k++)
                {
                    sum+=sm[k];
                    if(m<sum) m=sum;
                    if(sum<0) sum=0;
                }
            }
        }

        cout<<m<<endl;
    }

    return 0;
}
