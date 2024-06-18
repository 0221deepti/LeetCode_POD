You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.
For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.
*******************
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = difficulty.size();

        // Combine difficulty and profit into a single vector of pairs
        for (int i = 0; i < n; ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        // Sort jobs by difficulty, then by profit (if difficulties are equal)
        sort(jobs.begin(), jobs.end());

        // Sort workers
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int maxWorkProfit = 0;
        int j = 0;

        // Iterate through each worker
        for (int i = 0; i < worker.size(); ++i) {
            // Update the maximum profit achievable for the current worker
            while (j < n && worker[i] >= jobs[j].first) {
                maxWorkProfit = max(maxWorkProfit, jobs[j].second);
                j++;
            }
            // Add the maximum profit achievable to the total profit
            maxProfit += maxWorkProfit;
        }

        return maxProfit;
    }
};
