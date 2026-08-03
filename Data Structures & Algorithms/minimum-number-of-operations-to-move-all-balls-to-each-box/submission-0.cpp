class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ones;
        
        for (int i = 0; i < boxes.length(); ++i)
        {
            if (boxes[i] == '1') ones.push_back(i);
        }

        vector<int> ret;
        ret.reserve(boxes.length());
        for (int i = 0; i < boxes.length(); ++i)
        {   
            int operations = 0;
            for (const int& one : ones)
            {
                // one is index of where 1 located
                if (i == one) continue;
                operations += abs(one-i);
            }
            ret.push_back(operations);
        }
        return ret;
    }
};