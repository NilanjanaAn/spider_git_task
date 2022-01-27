// SPIDER INDUCTIONS: TASK 2 (B) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long int x;

bool compute(int a[], int i, long double val)
{
    if(i==n) // if last element is reached, check result equality
    {
        if(val==(long double)x)
            return true;
        else
            return false;
    }
    bool res;
    if(a[i]==0) // try only (+ or -) and *
        res=compute(a,i+1,val)||compute(a,i+1,0);
    else // try all operations
        res=compute(a,i+1,val+a[i])||compute(a,i+1,val-a[i])||compute(a,i+1,val*a[i])||compute(a,i+1,val/((long double)(a[i])));
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        long double v=a[0];
        bool ans = compute(a,1,v); // recursively try combinations of operations to check for result equality
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
