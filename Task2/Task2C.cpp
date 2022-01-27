// SPIDER INDUCTIONS: TASK 2 (C) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void route(int a[], int len, int n, int m, int sum, string res)
{
    int flag=0;
    sum+=a[n]; // increment number of abducted children
    if(sum>m) // if sum exceeds m, stop checking this route
        return;
    res=res+to_string(a[n])+" "; // append value to the path string
    if(2*n<=len)
    {
        if(a[2*n]!=-1) // if left child exists, make recursive call
            route(a,len,2*n,m,sum,res);
        else // it may be an ending point
        {
            flag=1; // used to check later whether both children are null, then considered as an ending point
        }
    }
    else if(sum==m) // left child doesn't exist but is not marked with -1, it's an ending point
        cout<<res<<"\n";
    
    if(2*n+1<=len)
    {
        if(a[2*n+1]!=-1) // if right child exists, make recursive call
            route(a,len,2*n+1,m,sum,res);
        else
        {
            if(sum==m && flag==1) // both children are null and sum equals m
                cout<<res<<"\n";
        }
    }
    return;
}

int main()
{
    int n,m;
    int a[1000000];
    for(int i=0;i<1000000;i++) // clear the array
        a[i]=0;
    cin>>n;
    int k=1;
    for(int i=1;i<=n;i++) // 1-indexed tree representation in array
    {
        int p;
        cin>>p;
        while(a[k]==-1) // for indeces already having -1 value
        {
            a[2*k]=-1; // make null left child
            a[2*k+1]=-1; // make null right child
            k++;
        }
        a[k]=p; // insert input value into empty index
        if(p==-1) // if input is null, its children will also be null
        {
            i--; // does not count as valid input, so decrement
            a[2*k]=-1; // make null left child
            a[2*k+1]=-1; // make null right child
        }
        k++;
    }
    cin>>m;
    k--;
    route(a,k,1,m,0,""); // call recursive function to find all paths
    return 0;
}
