/*
Problem statement
A thief wants to loot houses. He knows the amount of money in each house.
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
  */

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
// edge cases
	if(n == 0)  // if there is no house
	return 0;

	if(n == 1)  // if there is only 1 house
	return arr[0];  // loot money from that only

	if(n == 2)  // if there are 2 houses
	return max(arr[0], arr[1]);  // loot house with max money 

	int* maxMoney = new int[n + 1] ;  // array to store max money looted in each house

	// base cases
	maxMoney[0] = arr[0];  // looting the first house
	maxMoney[1] = max(arr[0], arr[1]);  // max of looting 1st & 2nd houses

	for(int i = 2; i <= n; i++){
// maxMoney[i - 1] -> skip it & take the monety looted upto the prev house
// arr[i] + maxMoney[i - 2] -> loot the current house & add it to the money looted in prev house i.e(i-2)
		maxMoney[i] = max(maxMoney[i - 1], arr[i] + maxMoney[i - 2]);

	}

	int result = maxMoney[n - 1];  // last elem of array will hold the result

	delete[] maxMoney;

	return result;
}
