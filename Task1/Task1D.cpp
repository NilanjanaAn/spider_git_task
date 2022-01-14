// SPIDER INDUCTIONS: TASK 1 (D) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool prime(int n) // checks whether a number is prime or not
{
    for(int i=3;i<=sqrt(n);i+=2) // only check for possible odd factors upto square root of the number
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>a;
     /* find prime numbers from 3 upto n and store them
	    2 is not considered as 1+2+(any other prime number) = (an even number other than 2), which will obviously not be prime */
    for(int i=3;i<n;i+=2)
    {
        if(prime(i))
            a.push_back(i);
    }
    int count=0;
    if(x==0) // a count of 0 is always satisfied
        cout<<"YES";
    else if(a.size()<2) // if not enough valid prime numbers are found in that range
        cout<<"NO";
    else
    {
       for(unsigned int i=0;i<a.size()-1;i++)
    	{
            int num=a[i]+a[i+1]+1;
            if(num>n) // if the sum exceeds n but the count is not satisfied
            {
                cout<<"NO";
                break;
            }
            if(prime(num)) // if the sum (1+pair of neighbouring primes) is prime
            {
                count++; // increment HarshPrime count
                if(count>=x) // if count is satisfied within the given range
                {
                    cout<<"YES";
                    break;
                }
            }
        }    
    }
    return 0;
}
