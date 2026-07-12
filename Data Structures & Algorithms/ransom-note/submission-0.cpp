class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomeLen = ransomNote.length();
        int mgLen = magazine.length();

        if (ransomeLen > mgLen) return false;

        // randsomeLen <= mgLen
        int arr[27] = {};
        for (int i = 0; i < mgLen; ++i)
        {
          int chi = magazine[i] - 'a';
          arr[chi]++;
        }

        for (int i = 0; i < ransomeLen; ++i)
        {
          int chi = ransomNote[i] - 'a';
          arr[chi]--;
          if (arr[chi] < 0) return false;
        }

        return true;
    }
};