#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int x;
    int y;
    int z;
    // constructor
    Node(int x, int y, int z): x(x), y(y), z(z) {}
    // overload the operator<
    bool operator<(const Node &r) const
    {
        if (z !=
) {
           return

        }
       if (x !=
) {
            return

        }
        return

    }
};

int main(){
    vector<Node> v = {
        {1,2,3}, {1,3,2}, {3,2,1},
        {3,2,2}, {3,1,2}, {3,1,1}
    };
    sort(v.begin(), v.end());
    for (const Node &node: v)
    {
        cout << '{' << node.x << ',' << node.y << ',' << node.z << '}';
        cout << endl;
    }
    return 0;
}