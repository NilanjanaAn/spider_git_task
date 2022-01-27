// SPIDER INDUCTIONS: TASK 2 (D) - Nilanjana Thakur (205121064)

#define mod 1000000007
#define modInv 500000004 // modular inverse of 2 for division
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int findpower(unsigned long long int m,unsigned long long int n) // computing 2^n with modulo 1000000007
{
    unsigned long long int ans=1;
    while(n>0)
    {
        if(n%2!=0) // if odd, multiply m with answer
            ans=(m*ans)%mod;
        n/=2; // as m*m is computed in the next step
        m=(m*m)%mod; // continue by multiplying m with m to reduce number of iterations
    }
    return ans;
}

int main()
{
    unsigned long long int n;
    cin>>n;
    unsigned long long int power=findpower(2,n);
    unsigned long long int res=(((power%mod*(power+1)%mod)%mod)*modInv%mod; // we are computing ((2^n)*(2^n+1)/2))%1000000007
    cout<<res<<"\n";
    return 0;
}
