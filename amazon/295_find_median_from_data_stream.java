class MedianFinder {
    
    Queue<Integer> q = new PriorityQueue(), z = q, t,
                   Q = new PriorityQueue(Collections.reverseOrder()); 

    public void addNum(int num) {
        (t=Q).add(num);
        (Q=q).add((q=t).poll());
    }

    public double findMedian() {
        return (Q.peek() + z.peek()) / 2.;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */


 //memory concerns
 class MedianFinder{
    PriorityQueue<Integer> maxHeap;
    PriorityQueue<Integer> minHeap;
    int size;
    public MedianFinder(){
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
        size = 0;
    }
    public void addNum(int num){
        maxHeap.add(num);
        minHeap.add(maxHeap.poll());
        if(maxHeap.size() < minHeap.size()){
            maxHeap.add(minHeap.poll());
        }
        size++;
    }
    public double findMedian(){
        if(size % 2 == 0){
            return(maxHeap.peek() + minHeap.peek()) / 2.0;
        }else{
            return maxHeap.peek();
        }
    }
 }