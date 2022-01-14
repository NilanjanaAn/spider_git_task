// SPIDER INDUCTIONS: TASK 1 (B) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int p,q,r,s,t;
    cin>>p>>q>>r>>s;
    if(p>r) // swap (p,q) with (r,s) so that the first set (p,q) belongs to the one that began pressing the button first
    {
        t=p;
        p=r;
        r=t;
        
        t=q;
        q=s;
        s=t;
    }
    if(s<q) // if one person's time is contained within the other person's time
        cout<<s-r; // result is the entire duration of the smaller press
    else if(r<q) // if the two people have some overlapping time
        cout<<q-r; // result is the difference between starting time of second person and ending time of first person
    else // if the two people do not have any overlapping time
        cout<<0;
    return 0;
}
