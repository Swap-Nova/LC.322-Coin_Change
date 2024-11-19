# LC.322-Coin_Change
- You are given an integer array coin representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that you need to make up that amount. If any combination of the coins cannot make up that amount of money, return -1.
### Solution
- To solve this, we need to create a base case and a case that handles recursive calls.
```cpp
/* To create 0 amount, we require no coins */
if(amount == 0) return 0;
```
- We need to return minimum coins, have to traverse across the entire array of coins, and to decrease the work we only focus where <code> amount >= coin </code>
- The recursive call is where we <code> amount - coin </code> because we have already used the 1st coin
- For valid cases where <code> recursionAns != INT_MAX </code> if it is equal then we return -1
```cpp
if(recursionAns != INT_MAX){
    int coins_used = 1 + recursionAns;
    min_coins = min(min_coins, coins_used);
}
else{
    min_coins = -1;
}
```
