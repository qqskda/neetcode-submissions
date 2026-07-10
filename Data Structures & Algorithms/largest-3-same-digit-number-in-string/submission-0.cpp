class Solution {
public:
    string largestGoodInteger(string num) {
        int counter = 0;
        char currnum = num.front();
        char currmax = '\0';

        for (int i = 0; i < num.length(); ++i)
        {
          if (num[i] == currnum) counter++;
          else
          {
            counter = 1;
            currnum = num[i];
          }

          if (counter == 3)
          {
            currmax = max(currnum, currmax);
          }
        }
        if (currmax == '\0') return "";
        return string(3, currmax);
    }
};