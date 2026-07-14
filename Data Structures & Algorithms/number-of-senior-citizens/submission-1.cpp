class Solution {
public:
    int countSeniors(vector<string>& details) {
        // <10><M/F><age><2>
        // Senior > 60

        // <11><age><2>
        // substr(11, length-11-2)

        int ret = 0;

        for (const string& detail: details)
        {
          if ((detail[11]-'0')*10 + (detail[12]-'0') > 60) ret++;
        }
        return ret;
    }
};