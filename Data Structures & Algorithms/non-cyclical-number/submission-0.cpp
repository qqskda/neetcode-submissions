class Solution {
public:
    bool isHappy(int n) {
        // Repeat until the number equals 1
        // Or it realizzs the cycle is infinite

        int num = n;
        unordered_set<int> st;
        while (num != 1)
        {
          if (st.contains(num))
            return false;

          st.insert(num);
          int temp = 0;
          while (num > 0)
          {
            temp += pow((num % 10), 2);
            num /= 10;
          }
          num = temp;
        }
        return true;
    }
};
