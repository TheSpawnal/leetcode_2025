class Solution{
public:
    int trap(vector<int>& height){
        int water = 0;
        int capacity_tank = height.size();
        int left[capacity_tank];
        int right[capacity_tank];
        left[0] = height[0];
        right[capacity_tank - 1] = height[capacity_tank-1];
        for(int i = 1; i < capacity_tank; i++){
            left[i] = max(height[i], right[i-1]);
        }
        for(int i = capacity_tank -2; i > 0; i--){
            right[i] = max(height[i], right[i+1]);
        }
        for(int i = 1; i < capacity_tank; i++){
            water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
}