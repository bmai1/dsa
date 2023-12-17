class FoodRatings {
private: 
    struct cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first > b.first) return true;
            if (a.first < b.first) return false;
            return a.second < b.second;
        }
    };
    // [cuisine, set({food, rating})]
    unordered_map<string, set<pair<int, string>, cmp>> cuis;
    // [food, cuisine]
    unordered_map<string, string> fc;
    // [food, rating]
    unordered_map<string, int> fr;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            // using negative rating instead of custom comparator
            cuis[cuisines[i]].insert({ ratings[i], foods[i] });
            fc[foods[i]] = cuisines[i];
            fr[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &cuisine = fc.find(food)->second;
        cuis[cuisine].erase({ fr[food], food });
        cuis[cuisine].insert({ newRating, food });
        fr[food] = newRating;
    }

    string highestRated(string cuisine) {
        return cuis[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */