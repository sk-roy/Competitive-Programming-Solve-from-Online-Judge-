#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int data[1000000];
int tempIndex[1000000];
int prevIndex[1000000];


int ceilIndex(int l, int r, int val)
{
    if(l==r) return l;
    int mid=(l+r)/2;

    if(data[tempIndex[mid]]>val) return ceilIndex(mid+1,r,val);
    else return ceilIndex(l,mid,val);
}


int find_lis(int sz)
{
    int lc,len=1;
    tempIndex[0]=0;
    for(int i=0; i<sz; i++)
        prevIndex[i]=-1;

    for(int i=1; i<sz; i++)
    {
        if(data[i]<=data[tempIndex[len-1]])
        {
            prevIndex[i]=tempIndex[len-1];
            tempIndex[len++]=i;
        }
        else
        {
            lc=ceilIndex(0,len-1,data[i]);
            if(lc) prevIndex[i]=tempIndex[lc-1];
            tempIndex[lc]=i;
        }
    }

    /*
    for(int i=tempIndex[len-1]; i!=-1; i=prevIndex[i])
        cout<<data[i]<<" ";
    cout<<endl;

    //cout<<"Data: ";
    //for(int i=0; i<sz; i++)
       // cout<<data[i]<<" ";
    cout<<endl;
    cout<<"Temp Index: ";
    for(int i=0; i<len; i++)
        cout<<tempIndex[i]<<" ";
    cout<<endl;
    cout<<"Previous Index: ";
    for(int i=0; i<sz; i++)
        cout<<prevIndex[i]<<" ";
    cout<<endl;
*/
    return len;
}


int main()
{
   // freopen("0input.txt", "r", stdin);
   // freopen("0output.txt", "w", stdout);

    int n,tc=1,sz;

    while(cin>>n && n>=0)
    {
        data[0]=n;
        sz=1;
        while(cin>>n && n>=0)
            data[sz++]=n;
        /*
        if(tc==8)
        {
            cout<<"Roy"<<endl;
            for(int i=0; i<sz; i++)
                cout<<data[i]<<" ";
            cout<<endl;
        }
        else continue;
            */

        //cout<<"Roy 1"<<endl;
        sz=find_lis(sz);

        if(tc>1) cout<<endl;
        cout<<"Test #"<<tc++<<":"<<endl;
        cout<<"  maximum possible interceptions: ";
        cout<<sz<<endl;

    }


    return 0;
}

