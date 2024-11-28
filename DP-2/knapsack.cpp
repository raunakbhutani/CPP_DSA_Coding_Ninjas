/*
Problem statement
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.'
  What would be the maximum value V, that the thief can steal?
  */


int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	
	if(n == 0 || maxWeight == 0)
	return 0;

	if(weights[0] > maxWeight)  // if first wt is greater than 
	return knapsack(weights + 1, values + 1, n - 1, maxWeight);

	int x = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];  // exclude the first wt & add the first elem of values
	
	int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);  // we are directly putting maxWeight 

	return max(x, y);  // return the max val from both the rec calls
}
