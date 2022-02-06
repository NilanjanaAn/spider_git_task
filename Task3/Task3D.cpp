// SPIDER INDUCTIONS: TASK 3 (D) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;

int store[1002]; // storage for dp

int main() {
    int n,k,flag=0;
    cin>>n>>k;
    memset(store,-1,sizeof(store)); //  all values set to -1
    store[0]=1; // initial value
    store[1]=1; // initial value
    for(int i=0;i<k;i++)
    {
        int p;
        cin>>p;
        if(p==n)
        {
            flag=1;
            break;
        }
        store[p]=0; // setting dirty steps to 0
    }
    if(flag==1) // if the topmost step is dirty, we cannot reach the top
        cout<<0;
    else
    {
        for(int i=2;i<=n;i++)
        {
            if(store[i]!=0) // for a clean step
            {
                store[i]=(store[i-1]%mod+store[i-2]%mod)%mod; // use the stored results of the two previous steps to calculate the value
            }
        }
        cout<<store[n];
    }
    return 0;
}

