class Solution {
public:

    int solve(vector<int>&coins, int amount){
        /* base case */
        if(amount == 0){ 
            // to create 0 amount we need no coins
            return 0;
        }

        /* minimum coins */
        int min_coins = INT_MAX;
        // traversing entire array for amount
        for(int i=0; i<coins.size(); i++){
            int coin = coins[i];
            // if coin_value > amount : no recursive call
            if(coin <= amount){
                // use 1 coin: amt - coin : rest by recursive call
                int recursionAns = solve(coins, amount - coin);

                // for invalid case: recursionAns = INT_MAX
                if(recursionAns != INT_MAX){
                    // valid case
                    // since we have used 1 coin
                    int coins_used = 1 + recursionAns;
                    min_coins = min(min_coins, coins_used);
                }
                else{
                    min_coins = -1;
                }
            }
        }
        return min_coins;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        return ans;
    }
};
