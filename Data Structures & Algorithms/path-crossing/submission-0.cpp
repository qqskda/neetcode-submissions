class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;

        set<pair<int, int>> visited;
        visited.insert({0, 0});

        for (char ch : path) {
            switch (ch) {
                case 'N':
                    ++y;
                    break;
                case 'E':
                    ++x;
                    break;
                case 'S':
                    --y;
                    break;
                case 'W':
                    --x;
                    break;
            }

            pair<int, int> location = {x, y};

            if (visited.count(location)) {
                return true;
            }

            visited.insert(location);
        }

        return false;
    }
};