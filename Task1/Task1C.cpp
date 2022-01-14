// SPIDER INDUCTIONS: TASK 1 (C) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--) // for each room
    {
        long long box;
        cin>>box;
        /* The pattern of arranging boxes is 1+2+3+.....n, which is = n*(n+1)/2
           Originally, box >= n*(n+1)/2, where n is a natural number.
           Assuming box = n*(n+1)/2, where n is a real number
                 => n^2+n-2*box = 0
            Applying Sridhar Acharya formula (to only find the positive root),
            		n=(-b+sqrt(b^2 - 4*a*c))/(2*a), where a=1,b=1,c=-2*box 
             	 => n=(-1+sqrt(1+8*box))/2 	 
			Number of rows must be a natural number, so we discard the last partially-filled row, if any.
			This is achieved using the floor function. */    
        long long res=floor((-1+sqrt(1+8*box))/2);
        cout<<res<<"\n";
    }
    return 0;
}
