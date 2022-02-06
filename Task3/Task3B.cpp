// SPIDER INDUCTIONS: TASK 3 (B) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int d[101]; // to store depth
int n;

void Tree(vector<int>a, int start, int end, int depth)
{
    if(start==end) // if only a single element exists in that range
    {
        d[a[start]]=depth;
        return; // terminate creating this subtree
    }
    int min=*min_element(a.begin()+start,a.begin()+end+1); // find the minimum element in the given range
    d[min]=depth; // assign the corresponding depth to the minimum element as it is going to become to root of the subtree
    auto it=find(a.begin(),a.end(),min); // find the index of the minimum element
    int index=it-a.begin();
    if(index-1>=start) // if any element exists to the left of the min
        Tree(a,start,index-1,depth+1);
    if(index+1<=end) // if any element exists to the right of the min
        Tree(a,index+1,end,depth+1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            int p;
            cin>>p;
            a.push_back(p);
        }
        Tree(a,0,n-1,0);
        for(int i=0;i<n;i++)
            cout<<d[a[i]]<<" ";
        cout<<"\n";
    }
    return 0;
}
