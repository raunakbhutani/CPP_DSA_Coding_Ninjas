/*
Problem statement
Ninja is planning to make dessert. For which he is going to buy ingredients. There are ‘N’ base flavors and ‘M’ toppings. Ninja has a target that he will be needing an amount of ‘K’ for making the dessert.

For making dessert, there are some basic rules

1. There should be exactly one base flavor.
2. Toppings can be one or more or none.
3. There are at most two toppings of each type.
Ninja wants to make a dessert with a total cost as close to the target price as possible.

You will be given an array/list flavor of size N representing the cost of each base flavor and another array/list toppings of size 'M' representing the cost of each topping and the target price.

Your task is to help Ninja to find the closest possible cost of the dessert to the target price 'K'. If there are multiple answers, return the lower one.
  */

#include <bits/stdc++.h> 



void findClosestCost(int baseCost, vector<int>& toppingCosts, int target, int currentIndex, int currentCost, int& closestCost){
    
// upd8 closestCost if current cost is closer to target
    if(abs(currentCost - target) < abs(closestCost - target) || (abs(currentCost - target) == abs(closestCost - target)&& currentCost < closestCost))
    closestCost = currentCost;

    // base case: if we have processed all toppings
    if(currentIndex >= toppingCosts.size())
    return;

// case 1: do not use current topping
    findClosestCost(baseCost, toppingCosts, target, currentIndex + 1, currentCost, closestCost);

// case 2: use current topping once
    findClosestCost(baseCost, toppingCosts, target, currentIndex + 1, currentCost + toppingCosts[currentIndex], closestCost);

// case 3: use current topping twice
    findClosestCost(baseCost, toppingCosts, target, currentIndex + 1, currentCost + 2 * toppingCosts[currentIndex], closestCost);
}


int closestCost(int n, int m, vector<int> &baseCosts, vector<int> &toppingCosts, int target)
{
 
    int closestCost = INT_MAX;

    for(int i = 0; i < n; i++){
// find closest cost by adding toppings to base cost
        findClosestCost(baseCosts[i], toppingCosts, target, 0, baseCosts[i], closestCost);
    }

    return closestCost;
}
