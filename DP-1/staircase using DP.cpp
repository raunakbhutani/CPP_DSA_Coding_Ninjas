/*
Problem statement
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

Time complexity of your code should be O(n).

Since the answer can be pretty large soo print the answer with mod(10^9 +7)
  */


#include<bits/stdc++.h>
using namespace std;

int ways(int n){


    if(n == 0)
    return 1;  // no of ways

    if(n == 1)
    return 1;

    if(n == 2)  // (1,1), (2)
    return 2;

    if(n == 3)  // (1,2,3), (1,3), (2,3), (3)
    return 4;

    int* arr = new int[n + 1];

   // base case
   arr[0] = 1;
   arr[1] = 1;
   arr[2] = 2;
   arr[3] = 4;

   for(int i = 4; i <= n; i++){

    arr[i] = ((arr[i - 1] + arr[i - 2]) % 1000000007 + arr[i - 3]) % 1000000007;
   }

   int result = arr[n]; // store the ans in result for future use

   delete[] arr;

   return result;
    
}

int main()
{
    int t;
    cin>>t;

    while (t--) {
    int n;
    cin >> n;

    int ans = ways(n);

    cout << ans << endl;
    }
    return 0;
}
