
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int> maxHeap;
    MedianFinder(){}

    void addNum(int num) {
        if (maxHeap.empty() or maxHeap.top() > num) {
			maxHeap.push(num);
		} else {
			minHeap.push(num);
		}

		if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} else if (minHeap.size() > maxHeap.size() + 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
			if (maxHeap.empty()) {
				return 0;
			} else {
				double avg = (maxHeap.top() + minHeap.top()) / 2.0;
				return avg;
			}

		} else {
			return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
		}
    }
};

/*
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


//even faster
class MedianFinder{
public:
	priority_queue<int, vector<int>, greater<>> second;
	priority_queue<int, vector<int>> first;
	int size1;
	int size2;
	MedianFinder(){
		size1 = 0;
		size2 = 0;
	}
	
	void addNum(int num){
		if(first.empty() && second.empty()){
			first.push(num);
			size1++;
		}
		else if(first.empty() || second.empty()){
			if(!first.empty()){
				if(num >= first.top()){
					second.push(num);
					size2++;
				}else{
					first.push(num);
					size2++;
					second.push(first.top());
					first.pop();
				}
			}
			else {
				if(num <= second.top()){
					first.push(num);
					size1++;
				}else{
					second.push(num);
					first.push(second.top());
					second.pop();
					size1++;
				}
			}
		}
		else if(size1 > size2){
			if(num>=first.top()){
				second.push(num);
				size2++;
			}else if(num < first.top()){
				first.push(num);
				second.push(first.top());
				first.top();
				size2++;
			}
		}else if(size2 > size1){
			if(num >= first.top()){
				second.push(num);
				first.push(second.top());
				second.pop();
				size1++;
			}else if(num < first.top()){
				first.push(num);
				size1++;
			}
		}else{
			if(num>= first.top()){
				second.push(num);
				size2++;
			}else if(num < first.top()){
				first.push(num);
				size1++;
			}
		}
	}

	double findMedian(){
		if(size1==size2){
			return ((double)first.top()+(double)second.top())/(double)2;
		}else{
			if(size1>size2){
				return first.top();
			}else{
				return second.top();
			}
		}
	}
};