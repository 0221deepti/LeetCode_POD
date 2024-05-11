class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
 int n = quality.size();
        vector<pair<double, int>> ratio_quality;
        
        // Calculate the wage-to-quality ratio for each worker
        for (int i = 0; i < n; ++i) {
            ratio_quality.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        
        // Sort workers based on their wage-to-quality ratio
        sort(ratio_quality.begin(), ratio_quality.end());
        
        priority_queue<int> max_quality;
        double min_cost = numeric_limits<double>::max();
        int total_quality = 0;
        
        // Iterate through each worker
        for (auto& rq : ratio_quality) {
            total_quality += rq.second;
            max_quality.push(rq.second);
            
            if (max_quality.size() > k) {
                total_quality -= max_quality.top();
                max_quality.pop();
            }
            
            if (max_quality.size() == k) {
                min_cost = min(min_cost, total_quality * rq.first);
            }
        }
        
        return min_cost;
    }
};
