#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Find largest window with 2 distinct fruits
// Use a hasmap to act as window, which should contain 2 elements with thier frequency, and if there's a third
// move the window start forward until there's only 2 elements again
// i and j are the window indicies
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> window;
    int i{ 0 }, j{ 0 }, out{ 0 };
    while (j < fruits.size()) {
        window[fruits[j]]++;
        while (window.size() > 2) {
            window[fruits[i]]--;
            if (window[fruits[i]] == 0) window.erase(fruits[i]);
            i++;
        }
        out = max(out, j - i + 1);
        j++;
    }
    return out;
}

double myPow(double x, int n) {
    double out{ x };
    if (n == 0 || x == 1) {
        return 1;
    }
    else if (n > 0) {
        int i = 1;
        while (i < n) {
            out *= x;
            i++;
        }
    }
    else {
        int i = -1;
        while (i < abs(n)) {
            out /= x;
            i++;
        }
    }
    return out;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
        });

    vector<vector<int>> merged;
    vector<int> prev = intervals[0];

    for (int i = 1; i < intervals.size(); ++i) {
        vector<int> interval = intervals[i];
        if (interval[0] <= prev[1]) {
            prev[1] = max(prev[1], interval[1]);
        }
        else {
            merged.push_back(prev);
            prev = interval;
        }
    }

    merged.push_back(prev);
    return merged;
}