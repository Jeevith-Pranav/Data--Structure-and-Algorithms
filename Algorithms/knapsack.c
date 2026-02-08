/*Knapsack:
Knapsack Problem Definition
The Knapsack Problem is a classic optimization problem in which:

You have a knapsack (bag) with a maximum weight capacity.

You have several items, each with a weight and a value.

The goal is to select items to maximize the total value in the knapsack without exceeding the weight capacity.

Types of Knapsack:

0/1 Knapsack: Each item can be taken completely (1) or not taken (0).

Fractional Knapsack: You can take part of an item, using a greedy approach to maximize value.
*/
    
#include <stdio.h>
  
int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    for(int i = 0; i < n; i++) 
    {
        printf("Enter value and weight of item %d: ", i+1);
        scanf("%d %d", &val[i], &wt[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[W+1];

   
    for(int i = 0; i <= W; i++)
        dp[i] = 0;

   
    for(int i = 0; i < n; i++) 
    {
        for(int w = W; w >= wt[i]; w--) 
        {
           
            if(dp[w - wt[i]] + val[i] > dp[w])
            {
                dp[w] = dp[w - wt[i]] + val[i];
            }
        }
    }
    printf("Maximum value in knapsack = %d\n", dp[W]);
    return 0;
}
