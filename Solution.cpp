class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<pair<int, int>> vec(26);
        for (int i = 0; i < 26; i++) {
            vec[i] = make_pair(-1, -1);
        }
        for (int i = 0; i < s.size(); i++) {
            int letter_id = s[i] - 'a';
            if (vec[letter_id].first == -1) {
                vec[letter_id].first = i;
            } else {
                vec[letter_id].second = i;
            }
        }
        for (int i = 0; i < 26; i++) {
            // cout << char('a' + i) << " = " << vec[i].first << " " << vec[i].second << "\n";
            if (vec[i].first == -1 && vec[i].second == -1) {
                continue;
            }
            if (vec[i].second - vec[i].first - 1 != distance[i]) {
                return false;
            }
        }
        return true;
    }
};
