// Given an array of points where points[i] = [xi, yi] 
// represents a point on the X-Y plane and an integer k, 
// return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the 
// Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. 
// The answer is guaranteed to be unique (except for the order that it is in).

// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public : 
    vector<vector<int>> kCLosest(vector<vector<int>>& points, int k){
        vector<vector<int>> result;
        priority_queue<vector<int>> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            const vector<int>& p = points[i];
            int x = p.at(0), y = p.at(1);
            maxHeap.push({x*x + y*y, x, y});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        for(int i = 0; i < k; i++){
            vector<int> p = maxHeap.top();
            maxHeap.pop();
            result.at(i) = {p.at(1), p.at(2)};
        }
        return result;
    }
};

// The time complexity of the kClosest function is O(n log k), where n is
//  the number of points in the input vector and k is the value of
//   the parameter. This is because we iterate through all the points and perform
//    operations such as pushing and popping elements from the
//     priority queue, which takes O(log k) time.

// The space complexity of the kClosest function is O(k), where k is the value
//  of the parameter. This is because we use a priority queue to store the
//   k closest points, which requires O(k) space.



