// Tiny example:
int countdown(int n) {
    if (n == 0) return 0;   // base case — stop here
    return countdown(n - 1); // recursive call
}