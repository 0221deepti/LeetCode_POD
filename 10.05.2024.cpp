class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
     auto compare = [](const std::vector<double>& arr1, const std::vector<double>& arr2) {
            return arr1[0] > arr2[0]; // Use > for min heap
        };

        std::priority_queue<std::vector<double>, std::vector<std::vector<double>>, decltype(compare)> pq(compare);
        int n = arr.size();

        for (int i = 0; i < n - 1; ++i) {
            double primeFraction = 1.0 + arr[i] / static_cast<double>(arr[n - 1]);
            pq.push({ primeFraction, static_cast<double>(i), static_cast<double>(n - 1) });
        }

        std::vector<int> res(2);
        while (k > 0) {
            auto curVal = pq.top();
            pq.pop();
            int numIndex = static_cast<int>(curVal[1]);
            int denIndex = static_cast<int>(curVal[2]);
            int nextDenIndex = denIndex - 1;

            if (numIndex < nextDenIndex) {
                double primeFraction = 1.0 + arr[numIndex] / static_cast<double>(arr[nextDenIndex]);
                pq.push({ primeFraction, static_cast<double>(numIndex), static_cast<double>(nextDenIndex) });
            }

            k--;
            if (k == 0) {
                res[0] = arr[numIndex];
                res[1] = arr[denIndex];
            }
        }
        return res;
    }
};
