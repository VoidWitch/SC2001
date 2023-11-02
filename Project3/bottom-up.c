// A Dynamic Programming based 
// solution for 0-1 Knapsack problem 
#include <stdio.h> 
  
// A utility function that returns 
// maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 
  
// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n)
{
    int K[W + 1];
    for (int i = 0; i <= W; i++)
    {
        K[i] = 0;
    }

    for (int w = 1; w <= W; w++)
    {
        for (int i = 0; i < n; i++)
        {
            if (wt[i] <= w)
            {
                K[w] = max(K[w], K[w - wt[i]] + val[i]);
            }
        }
    }

    return K[W];
}

  
// Driver Code 
int main() 
{ 
    int profit_a[] = { 7, 6, 9 }; 
    int weight_a[] = { 4, 6, 8 }; 
    int profit_b[] = { 7, 6, 9 }; 
    int weight_b[] = { 5, 6, 8 };    
    int W = 14; 
    int n = 3; 
    printf("4.(a): ");
    printf("%d\n", knapSack(W, weight_a, profit_a, n)); 
    printf("4.(b): ");
    printf("%d\n", knapSack(W, weight_b, profit_b, n)); 
    return 0; 
}
