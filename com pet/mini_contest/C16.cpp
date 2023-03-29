#include <iostream>
#include <vector>

using namespace std;

pair<int, int> mediant(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

vector<char> stern_brocot_path(int x, int y) {
    vector<char> path;
    pair<int, int> a = make_pair(0, 1), b = make_pair(1, 0);
    pair<int, int> c;

    while (true) {
        c = mediant(a, b);
        if (c.first == x && c.second == y) break;
        if (double(c.first) / c.second < double(x) / y) {
            a = c;
            path.push_back('R');  // Move right in the tree
        } else {
            b = c;
            path.push_back('L');  // Move left in the tree
        }
    }

    return path;
}

int main() {
    int x, y;
    cin >> x >> y;

    vector<char> path = stern_brocot_path(x, y);
    string path_str(path.begin(), path.end());

    cout << path_str << endl;

    return 0;
}
