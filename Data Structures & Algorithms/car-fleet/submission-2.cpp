class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> vec;
        int sz = position.size();
        vec.reserve(sz);

        for (int i = 0; i < sz; ++i)
        {
            double turns = (static_cast<double>(target - position[i]))/speed[i];
            vec.push_back({position[i], turns});
        }

        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b){
            return a.first < b.first;
        });

        double minTurns = -1;
        int fleets = 0;

        for (int i = sz-1; i >= 0; --i)
        {
            // beginning of new fleet
            if (minTurns < vec[i].second)
            {
                minTurns = vec[i].second;
                fleets++;
            }
        }
        return fleets;
    }

    // 3 5 10 3
    // 10 5 3 3
};
