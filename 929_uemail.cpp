class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto email : emails) {
            string handle;
            bool local = true;
            for (int i = 0; i < email.size(); ++i) {
                if (email[i] == '.' && local) continue;
                if (email[i] == '+' && local) while (email[i] != '@') ++i;
                if (email[i] == '@') local = false;
                handle += email[i];
            }
            s.insert(handle);
        }
        return s.size();
    }
};