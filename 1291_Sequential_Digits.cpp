class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        // Count digits in low
        int lowDigits = 0, temp = low;
        while (temp > 0) {
            lowDigits++;
            temp /= 10;
        }

        // Count digits in high
        int highDigits = 0;
        temp = high;
        while (temp > 0) {
            highDigits++;
            temp /= 10;
        }

        // Generate sequential numbers of every possible length
        for (int len = lowDigits; len <= highDigits; len++) {

            // Starting digit
            for (int start = 1; start <= 10 - len; start++) {

                int num = 0;
                int digit = start;

                // Build the sequential number
                for (int i = 0; i < len; i++) {
                    num = num * 10 + digit;
                    digit++;
                }

                // Check if it lies in the required range
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};
