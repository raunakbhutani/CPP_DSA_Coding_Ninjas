/*
Problem statement
You are given a number 'n'.



Return number of digits in ‘n’.



Example:
Input: 'n' = 123

Output: 3

Explanation:
The 3 digits in ‘123’ are 1, 2 and 3. 
  */

int countDigits(int n) {
  if (n == 0) {
    return 0;
  }
        return (1+countDigits(n/10));
}
