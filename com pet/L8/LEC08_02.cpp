#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,q,l,r,x,y,z;
int a[N];
int t[N*4];

void build(int p,int l,int r)
{
    if(l==r)
    {
        t[p]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p]=min(t[p*2],t[p*2+1]);
}

void update(int p,int l,int r,int x,int y)
{
    if(l==r)
    {
        t[p]=y;
        return ;
    }
    int mid=(l+r)/2;
    if(x<=mid)
        update(p*2,l,mid,x,y);
    else
        update(p*2+1,mid+1,r,x,y);
    t[p]=min(t[p*2],t[p*2+1]);
}

int query(int p,int l,int r,int x,int y)
{
    if(l>=x&&r<=y)
        return t[p];
    int mid=(l+r)/2,ans=1e9;
    if(x<=mid)
        ans=min(ans,query(p*2,l,mid,x,y));
    if(y>mid)
        ans=min(ans,query(p*2+1,mid+1,r,x,y));
    return ans;
}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        char opt;
        cin>>opt;
        if(opt=='M')
        {
            cin>>x>>y;
            update(1,1,n,x,y);
        }
        else
        {
            cin>>x>>y>>z;
            int k=query(1,1,n,x,y);
            if(k<=z)
                cout<<y-x+1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return 0;
}
