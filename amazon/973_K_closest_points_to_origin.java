class Solution{
    public int[][] kClosest(int[][] points, int k){
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            (a,b)->Double.compare(
                a[0]*a[0] + a[1]*a[1],
                b[0]*b[0] + b[1]*b[1])
            );
        for(int[] p : points){
            maxHeap.offer(p);
            if(maxHeap.size() > k){
                maxHeap.poll();
            }
        }
        return maxHeap.toArray(new int[k][2]);
    }
}