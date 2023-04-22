class Solution {
public:
    long getCount(long prefix, long n) {
        long cur = prefix;
        long next = cur + 1;
        long nodeCount = 0;
        while (cur <= n) {
            nodeCount += min(n+1, next) - cur;
            cur *= 10;
            next *= 10;
        }
    }

    int findKthNumber(int n, int k) {
        long p = 1;
        long prefix = 1;
        while (p < k) {
            long count = getCount(prefix, n);
            if (p + count > k) {
                prefix *= 10;
                p++;
            }
            else {
                prefix++;
                p += count;
            }
        }
        
        return static_cast<int>(prefix);
    }
};