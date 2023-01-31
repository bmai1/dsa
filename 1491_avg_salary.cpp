class Solution {
public:
    double average(vector<int>& salary) {
        double max = 0, min = INT_MAX;
        for (int i = 0; i < salary.size(); ++i) {
            if (salary[i] > max) { max = salary[i]; }
            if (salary[i] < min) { min = salary[i]; }
        }
        
        double average = 0;
        for (int j = 0; j < salary.size(); ++j) {
            if (salary[j] != max && salary[j] != min) { average += salary[j]; }
        }

        average /= double(salary.size() - 2);
        return average;
    }
};
