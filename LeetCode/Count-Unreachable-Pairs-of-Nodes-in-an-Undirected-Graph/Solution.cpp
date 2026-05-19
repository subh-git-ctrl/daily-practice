result = 0L;
for (i = 1; i < n; ++i) {
    for (j = 0; j < i; ++j) {
        result += clusterSizes[i] * clusterSizes[j];
}