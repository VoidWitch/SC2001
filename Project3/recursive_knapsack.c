#include <stdio.h>
#define N 1000000
int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wtarr[], int profit[], int minW, int n){
    int p = 0;
    //Base case:
    if(W < minW) return 0;  //profit 0 since no item added
    
    for(int i=0; i<n; i++){
        if (wtarr[i] < W){  //include obj and update remaining weight
            p =  max(p, profit[i] + knapSack(W-wtarr[i], wtarr, profit, minW, n));
        }
    }
    return p;
}

int main(){ 
    int minW = N;
    /* part 1
    int weight[] = { 4, 6, 8 };
    int profit[] = { 7, 6, 9 };
    */

    /* part 4
    int weight[] = { 5, 6, 8 };
    int profit[] = { 7, 6, 9 };
    */
   
    for(int i=0; i<sizeof(weight); i++){
        if (weight[i] < minW) minW = weight[i];
    }
    int W = 14; //max cap
    int n = 3; //no. of items
    printf("%d", knapSack(W, weight, profit, minW, n));
}
