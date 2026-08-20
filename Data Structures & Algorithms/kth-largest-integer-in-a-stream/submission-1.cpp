class KthLargest {
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        // maintain pq in size k, and use min heap;
        for (const int& num : nums) pq.push(num);

        while (pq.size() > k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > _k) pq.pop();
        return pq.top();
    }
};
