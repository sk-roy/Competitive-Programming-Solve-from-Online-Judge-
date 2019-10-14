#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000

int main()
{
    long long i,j,k,n,m;
    set <long long> st;
    set <long long> :: iterator it;
    st.insert(1);
    st.insert(2);

    for(it=st.begin(); it!=st.end(); it++)
    {
        k=*it;
        k*=2;
        if(k>mx) break;
        st.insert(k);
    }
    for(it=st.begin(); it!=st.end(); it++)
    {
        k=*it;
        k*=3;
        if(k>mx) break;
        st.insert(k);
    }
    for(it=st.begin(); it!=st.end(); it++)
    {
        k=*it;
        k*=5;
        if(k>mx) break;
        st.insert(k);
    }

    /*
    cout<<"Size: "<<st.size()<<endl;
    k=0;
    for(it=st.begin(); it!=st.end(); it++)
    {
        cout<<*it<<" ";
        if(k==20) break;
        k++;
    }
    cout<<endl;
    */
    //cout<<st.size()<<endl;

    k=1;
    for(it=st.begin(); it!=st.end(); it++)
    {
       if(k==1500)
       {
           cout<<"The 1500'th ugly number is "<<*it<<'.'<<endl;
           break;
       }
       k++;
    }


    return 0;
}
