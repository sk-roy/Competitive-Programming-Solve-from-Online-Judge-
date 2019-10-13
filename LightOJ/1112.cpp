#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int tree[N+5];

void update(int idx, int value)
{
    while(idx<N)
    {
        tree[idx]+=value;
        idx += idx & -idx;
    }
}

int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int readSingle(int idx)
{
    int sum = tree[idx];
    int temp = idx - (idx & -idx);
    idx--;
    while(temp<idx)
    {
        sum -= tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int readRange(int l, int r)
{
    int sum = 0;
    l--;
    while(l!=r)
    {
        if(l>r)
        {
            sum -= tree[l];
            l -= l & -l;
        }
        else
        {
            sum += tree[r];
            r -= r & -r;
        }
    }
    return sum;
}


int main()
{
    int t,tc,n,q,i,j,k,idx;
    int tp, l, r;

    scanf("%d", &t);
    for(tc=1; tc<=t; tc++)
    {
        scanf("%d %d", &n, &q);
        for(int i=0; i<N; i++)
            tree[i]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &k);
            update(i,k);
        }

        printf("Case %d:\n", tc);
        for(int i=1; i<=q; i++)
        {
            scanf("%d %d", &tp, &l);

            if(tp==1)
            {
                k = readSingle(l+1);
                update(l+1, -k);
                printf("%d\n", k);
            }
            else if(tp==2)
            {
                scanf("%d", &k);
                update(l+1, k);
            }
            else
            {
                scanf("%d", &r);
                printf("%d\n", readRange(l+1,r+1));
            }
        }


    }

    return 0;
}
