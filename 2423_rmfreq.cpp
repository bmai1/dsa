class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        for (const auto &c : word) freq[c]++;
        if (freq.size() == 1) return true; // word has one unique letter 
    
        map<int, int> freqfreq;
        for (const auto& it : freq) { freqfreq[it.second]++; } 
        if (freqfreq.size() > 2) return false; // cannot fix 3 frequencies
        if (freqfreq.size() == 1) return freqfreq[1]; // if all freq 1, del any

        auto it = freqfreq.begin();
        int freq_dif = (*next(it)).first - (*it).first; // the 2 freq have to be one off 
        int ff       = (*next(it)).second;              // greater freq freq must be 1 (to remove)
    
        return (freq_dif == 1 && ff == 1) || freqfreq[1] == 1; // check if one freq of 1
    }
};