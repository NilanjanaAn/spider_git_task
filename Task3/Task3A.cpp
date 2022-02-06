// SPIDER INDUCTIONS: TASK 3 (A) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int counter=0;

int* swap(int a[], int m, int n) // swap two indeces of the array
{
    int temp=a[m];
    a[m]=a[n];
    a[n]=temp;
    return a;
}

void permute(int a[], int n, int index) // permute the array and check for condition
{
    int i,j,flag;
    if(index==n) // if last index is reached (all previous indeces already satisfy divisibility
    {
        if(a[index]%(index)==0||(index)%a[index]==0) // if the last index matches the divisibility condition
            counter++;
        return;
    }
    for(i=index;i<=n;i++)
    {
        flag=0;
        for (j=index;j<i;j++) // checking to avoid duplicate permutations
            if (a[j]==a[i])
                flag=1;
        
        if(flag==0)
        {
            a=swap(a,index,i); // swap indeces for the current permutation
            if(a[index]%(index)==0||(index)%a[index]==0) // do not permute if divisibility fails
                permute(a,n,index+1);
            a=swap(a,index,i); // reset the swapped indeces for the next permutation
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int a[20];
    for(int i=1;i<=n;i++) // creating the 1-n permutation array
        a[i]=i;
    permute(a,n,1);
    cout<<counter;
    return 0;
}

