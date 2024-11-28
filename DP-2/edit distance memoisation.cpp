/*
Problem statement
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.

Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:

1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
  */

#include<string>
int editDistance(string s1, string s2)
{
	
	int m = s1.length();
	int n = s2.length();


	// create a 2D O/P array
	int** output = new int*[m + 1];

	for(int i = 0; i <= m; i++){

		output[i] = new int[n + 1];
	}

	// fill 1st row
	for(int j = 0; j <= n; j++){

		output[0][j] = j;
	}

// fill 1st col
	for(int i =0 ; i <= m; i++){

		output[i][0] = i;
	}

// fill rem rows & cols
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){

			if(s1[m - i] == s2[n - j])
			output[i][j] = output[i - 1][j - 1];

			else{

				int a = output[i - 1][j];
				int b = output[i][j - 1];
				int c = output[i - 1][j - 1];

				output[i][j] = min(a, min(b, c)) + 1;
			}
		}
	}

	return output[m][n];
}
