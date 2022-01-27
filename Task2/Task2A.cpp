// SPIDER INDUCTIONS: TASK 2 (A) - Nilanjana Thakur (205121064)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        if(a==b) // if no mistake is present
            cout<<"YES\n";
        else
        {
            int flag=0;
            unsigned int i=0,j=0;
            while(1)
            {
                if(j>=b.length()) // checking faulty string is complete
                {
                    if(i<a.length()) // but checking correct string is not complete
                        flag=1; // guess is wrong
                    break;
                }
                if(i>=a.length()) // if checking correct string is complete
                {
                    if(b[j]==b[j-1]) // remaining letters in faulty string must all be same and equal to last letter of correct string
                        j++;
                    else // if a new letter is found
                    {
                        flag=1; // guess is wrong
                        break;
                    }
                }
                else if(b[j]!=a[i])
                {
                    if(j==0) // first letter of both strings must be same
                    {
                        flag=1;
                        break;
                    }
                    if(b[j]==b[j-1]) // if faulty letter is a repetition of last correct letter
                    {
                        j++; // continue checking for next letter
                    }
                    else // guess is wrong
                    {
                        flag=1;
                        break;
                    }
                }
                else // if matching letters are found in both strings, check for next letter
                {
                    i++;
                    j++;
                }
            }
            if(flag==0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
