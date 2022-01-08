class Solution:
    def findKthNumber(self, n, k) -> int:
        cur = 1
        prefix = 1

        while cur < k:
            cnt = self.get_count(prefix, n)
            if cur + cnt > k:
                prefix *= 10
                cur += 1
            else:
                prefix += 1
                cur += cnt
        return prefix

    def get_count(self, i, n):

        if i <= n:
            cnt = 1
        else:
            return 0

        a = i
        b = i + 1

        while True:
            a = a * 10
            b = b * 10
            if n >= b:
                cnt += b - a
            elif n >= a:
                cnt += n - a + 1
            else:
                break
        return cnt
