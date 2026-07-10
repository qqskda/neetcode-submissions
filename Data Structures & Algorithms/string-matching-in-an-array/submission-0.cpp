class Solution {
public:

    vector<string> stringMatching(vector<string>& words) {
        // substring
        // I would first order by word size, so that check from shorter to the longer
        sort(words.begin(), words.end(), [](const string& a, const string& b){
          return a.length() < b.length();
        });
        vector<string> ret;

        for (int i = 0; i < words.size(); ++i)
        {
          for (int j = i+1; j < words.size(); ++j)
          {
            if (words[j].find(words[i]) != string::npos)
            {
              ret.push_back(words[i]);
              break;
            }
          }
        }
        return ret;
    }
};