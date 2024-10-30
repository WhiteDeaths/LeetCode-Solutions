class Encrypter {
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < size(keys); ++i) {
            lookup_[keys[i]] = values[i];
        }
        for (const auto& x : dictionary) {
            ++cnt_[encrypt(x)];
        }
    }
    
    string encrypt(string word1) {
        string result;
        for (const auto& c : word1) {
            if (!lookup_.count(c)) {
                return "";
            }
            result += lookup_[c];
        }
        return result;
    }
    
    int decrypt(string word2) {
        return cnt_[word2];
    }

private:
    unordered_map<char, string> lookup_;
    unordered_map<string, int> cnt_;
};