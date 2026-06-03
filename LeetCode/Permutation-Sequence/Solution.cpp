1class Solution {
2public:
3    int factorial(int n) {
4        if (n == 0)
5            return 1;
6        return n * factorial(n - 1);
7    }
8
9    string buildPermutation(int currFact, int remainingDigits, int k,
10                            string& answer, string& available) {
11
12        if (remainingDigits == 0)
13            return answer;
14
15        // Number of permutations in each block
16        int blockSize = currFact / remainingDigits;
17
18        // Find which block the kth permutation belongs to
19        int index = k / blockSize;
20
21        // Pick the corresponding digit
22        answer += available[index];
23
24        // Remove the chosen digit from future consideration
25        available.erase(index, 1);
26
27        // Move to the position inside the chosen block
28        return buildPermutation(blockSize, remainingDigits - 1, k % blockSize,
29                                answer, available);
30    }
31
32    string getPermutation(int n, int k) {
33
34        string available = "";
35
36        // Available digits: "123...n"
37        for (int i = 1; i <= n; i++) {
38            available += (i + '0');
39        }
40
41        string answer = "";
42
43        // Convert k to 0-based indexing
44        return buildPermutation(factorial(n), n, k - 1, answer, available);
45    }
46};