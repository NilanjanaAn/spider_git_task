// SPIDER INDUCTIONS: TASK 1 (A) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m,n;
    vector <int> arr;
    cin>>n>>m;
    for(int i=0;i<n;i++) // input the list of toffee prices
    {
        int p;
        cin>>p;
        arr.push_back(p);
    }
    sort(arr.begin(),arr.end()); // sorting the list in ascending order to maximize the quantity of toffees that can be bought
    int j=0,count=0;
    for(j=0;j<n;j++)
    {
        count+=arr[j];
        if(count>m) // terminate as budget is not enough to buy any more toffees 
            break;
    }
    cout<<j; // print maximum number of toffees that can be bought
    return 0;
}
