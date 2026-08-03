class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // 1. Choose shortest processing time among the available ones
        // 2. If multiple options, choose the smallest index

        // First intuition -> min heap?
        // Second intuition -> queue?


        // 1. Find the min enque time and start from there (sort)
        // 2. Update the available options at the time the current task is done
        // 3. Pick the shortest processing time & min index
        // 4. Repeat

        // To know the first/next available task, need to sort by enque time
        // To know the shortest processing time, we need min heap.
        // To know the min index, we need Data Structure that keep tracks while sorting
        int n = tasks.size();
        // enque, process, index
        vector<array<long long, 3>> sortedTasks;

        for (int i = 0; i < n; ++i)
        {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(sortedTasks.begin(), sortedTasks.end());

        // Now we need min-heap that stores the available task at the current time
        // priority_queue<data type, internal storage, comparison method>
        // pair<long long, int> = {processing time, orig_index}
        // Note taht in priority queue compaison method, if the data type is pair,
        // it compares first val, and then second val
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> availableTasks;

        long long currentTime = 0;
        vector<int> ret;
        // Since our sortedTask is vector, use index to traverse
        int i = 0;
        while (i < n || !availableTasks.empty())
        {
            if (availableTasks.empty() && currentTime < sortedTasks[i][0])
            {
                // very first task + when there is big idle
                currentTime = sortedTasks[i][0];
            }

            // Tasks that are now available
            while (i < n && sortedTasks[i][0] <= currentTime)
            {
                availableTasks.push({sortedTasks[i][1], sortedTasks[i][2]});
                ++i;
            }

            // Now lets work on it
            auto [processingTime, origIndex] = availableTasks.top();
            availableTasks.pop();

            ret.push_back(origIndex);
            currentTime += processingTime;
        }
        return ret;
    }
};