class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;

        string pfix = "";
        for (int i = 0; i < searchWord.size(); ++i) {
            pfix += searchWord[i];
            vector<string> suggest;

            // find first matching prefix with binary search
            string f_pfix;  
            int lo = 0, hi = products.size() - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                f_pfix = products[mid].substr(0, i + 1);
                if (f_pfix < pfix) lo = mid + 1;
                else hi = mid - 1;
            }
             
            // while prefix matches, append suggestions
            while (suggest.size() < 3 && lo < products.size() && pfix == products[lo].substr(0, i + 1)) {
                suggest.push_back(products[lo++]);
            }
            ans.push_back(suggest);
        }
        return ans;
    }
};