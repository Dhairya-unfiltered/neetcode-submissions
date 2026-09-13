class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {  // i=1

            int left = i;   // 1
            int right = i;  // 1

            while (left >= 0 && right <= n - 1) {
                if (s[left] == s[right]) {  // false
                    count++;                // count=2
                } else {
                    break;
                }
                left--;   //-1
                right++;  // 3
            }

            left = i;       // 1
            right = i + 1;  // 2

            while (left >= 0 && right <= n - 1) {
                if (s[left] == s[right]) {  // false
                    count++;                // 2
                } else {
                    break;
                }
                left--;   // 0
                right++;  // 3
            }
        }
        return count;
    }
};
