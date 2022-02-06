// SPIDER INDUCTIONS: TASK 3 (E) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

void update(lli *tree,lli index,lli lb,lli ub,lli pos,lli diff) // update the specific nodes of the tree with the difference value
{
    if(pos<lb||pos>ub) // if position is not part of this segment
        return;
    tree[index]+=diff; // update value of the node
    if(ub!=lb) // if more than one value exists in range
    {
        lli mid=(lb+ub)/2;
        update(tree,2*index,lb,mid,pos,diff); // recursively update value of the nodes in left subtree
        update(tree,2*index+1,mid+1,ub,pos,diff); // recursively update value of the nodes in right subtree
    }
}

lli findSum(lli *tree,lli index,lli lb,lli ub,lli l,lli r) // find the range sum
{
    if (l<=lb && r>=ub) // if segment falls within given range
        return tree[index];
    if (ub<l||lb>r) // if segment is to the left or right of the range
        return 0;
    // otherwise for partial overlap
    lli mid=(lb+ub)/2;
    lli sum=findSum(tree,2*index,lb,mid,l,r)+findSum(tree,2*index+1,mid+1,ub,l,r); // recursively find the sum in left and right subtrees
    return sum;
}

int main()
{
    int n,t;
    cin>>n>>t;
    vector<lli>a;
    a.push_back(0); // as provided set of values will be 1-indexed
    lli *tree=new lli[4*n]; // to hold the tree
    for(int i=1;i<=n;i++)
    {
        lli p;
        cin>>p;
        a.push_back(p);
        update(tree,1,1,n,i,p); // use the update query to construct the segment tree
    }
    while(t--)
    {
        lli q,u,v;
        cin>>q>>u>>v; // q = query type, u = a or l, v = b or r
        if(q==1) // update query
        {
            update(tree,1,1,n,u,v-a[u]);
            a[u]=v;
        }
        else // range sum query
        {
            lli res=findSum(tree,1,1,n,u,v);
            cout<<res<<"\n";
        }
    }
    return 0;
}

