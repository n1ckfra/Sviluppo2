#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Global variables for input data
int N, M;
vector<int> K;

// Function to compute the minimum number of steps required
int minSteps(vector<int>& dp, int start, int end) {
    // Base case: If the subarray is empty or invalid
    if (start >= end) return 0;

    // Finding the actual indexes from K that lie within the current range
    vector<int> relevantIndexes;
    for (int idx : K) {
        if (idx >= start && idx <= end) {
            relevantIndexes.push_back(idx);
        }
    }

    // If there are no relevant indexes in the range, return 0
    if (relevantIndexes.empty()) return 0;

    // If the value is already computed
    int dpIndex = start * M + end;
    if (dp[dpIndex] != -1) return dp[dpIndex];

    // Initialize the minimum steps to a large value
    int min_steps = numeric_limits<int>::max();

    // Try partitioning at each relevant index and calculate the cost
    for (int i : relevantIndexes) {
        int cost = end - start + 1; // Base cost for partitioning
        if (i > start) cost += minSteps(dp, start, i - 1);
        if (i < end) cost += minSteps(dp, i + 1, end);
        min_steps = min(min_steps, cost);
    }

    // Save the computed value
    dp[dpIndex] = min_steps;
    return min_steps;
}

int main() {
    // Reading N and M
    cin >> N >> M;
    K.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> K[i];
    }

    // Initialize dp vector with -1 to indicate uncomputed values
    vector<int> dp(M * M, -1);

    // Compute and print the minimum steps
    cout << minSteps(dp, 0, M - 1) << endl;

    return 0;
}
