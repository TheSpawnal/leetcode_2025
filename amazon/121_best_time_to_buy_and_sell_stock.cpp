#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p1 = 0;
        int p2 = 0;
        int maxP = 0;

        for(int i =1; i < prices.size(); i++){
            if(prices[i] > prices[p1]){
                int p = prices[i] - prices[p1];
                if(p > maxP){
                    maxP = p;
                }
            }
            else{
                p1 = i;
            }
        }
        return maxP;
    }
};
