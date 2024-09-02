/*
Problem statement
Take two numbers as input and swap them and print the swapped values by using the concept of functions and pointers.
*/

#include <iostream>
#include "solution.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        swap(&a , &b);
        cout<<a<<" "<<b;
        cout<<endl;
    }
}
