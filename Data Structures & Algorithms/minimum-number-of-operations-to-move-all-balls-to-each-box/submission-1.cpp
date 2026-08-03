class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ret(boxes.length(), 0);
        int moves = 0; // Number of moves to move balls to position i
        int balls = 0; // Number of balls on the left to position i

        // If there are two balls left to position i,
        // When we move to position  i+1, the extra moves we need is two 

        for (int i = 0; i < boxes.length(); ++i)
        {
            ret.at(i) += moves;
            if(boxes[i] == '1') ++balls;
            moves += balls;
        }
        moves = 0; balls = 0;
        for (int i = boxes.length()-1; i >= 0; --i)
        {
            ret.at(i) += moves;
            if (boxes[i] == '1') ++balls;
            moves += balls;
        }

        return ret;
    }
};