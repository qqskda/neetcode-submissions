class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Q: Use all the card we have to form group/s of groupSize.

        map<int,int> mp; // key-freq

        for (int i = 0; i < hand.size(); ++i)
        {
            mp[hand[i]] += 1;
        }

        // we have to use all the cards so start from the first
        auto itr = mp.begin();
        for (auto itr = mp.begin(); itr != mp.end(); )
        {
            if (itr->second == 0)
            {
                itr++;
                continue;
            }

            int start = itr->first;
            itr->second--;

            for (int i = 1; i < groupSize; ++i)
            {
                int next = start+1;
                int next_freq = mp[next];

                if (mp[next] == 0) return false;
                else mp[next]--;

                start = next;
            }
        }
        return true;

    }
};
