#include<algorithm>
void rotate(int *input, int d, int n)
{

   reverse(input,input+n);

   reverse(input,input+n-d);
   
   reverse(input+n-d,input+n);
}
