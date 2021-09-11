class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> minq;
    priority_queue<int, std::vector<int>, std::greater<int> > maxq;
    void addNum(int num) {
        if(minq.empty() || minq.top() > num) minq.push(num);
        else maxq.push(num);
        if(minq.size() > maxq.size() + 1)
        {
            maxq.push(minq.top());
            minq.pop();
        }
        else if(minq.size() + 1 < maxq.size())
        {
            minq.push(maxq.top());
            maxq.pop();
        }
    }

    double findMedian() {
        if(minq.size()==maxq.size()) return (minq.size()==0) ? 0.0 : (minq.top() + maxq.top())/2.0;
        else return (minq.size() > maxq.size()) ? minq.top()*1.0 : maxq.top()*1.0;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
