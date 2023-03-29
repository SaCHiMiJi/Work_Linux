#include <bits/stdc++.h>
using namespace std;

vector<char> getAlphabetFromA(char z)
{
    vector<char> alphabet;
    for (char c = 'A'; c <= z; c++)
    {
        alphabet.push_back(c);
    }
    return alphabet;
}

// count connected ghraph
int countConnectedComponents(vector<char> node, vector<pair<char, char>> edges)
{
    int count = 0;
    vector<char> visited;
    for (int i = 0; i < node.size(); i++)
    {
        if (find(visited.begin(), visited.end(), node[i]) == visited.end())
        {
            count++;
            queue<char> q;
            q.push(node[i]);
            while (!q.empty())
            {
                char current = q.front();
                q.pop();
                visited.push_back(current);
                for (int j = 0; j < edges.size(); j++)
                {
                    if (edges[j].first == current)
                    {
                        if (find(visited.begin(), visited.end(), edges[j].second) == visited.end())
                        {
                            q.push(edges[j].second);
                        }
                    }
                    else if (edges[j].second == current)
                    {
                        if (find(visited.begin(), visited.end(), edges[j].first) == visited.end())
                        {
                            q.push(edges[j].first);
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    char A;
    char x, y;

    scanf("%c\n", &A);
    vector<char> node = getAlphabetFromA(A);

    // for (int i = 0; i < node.size(); i++)
    // {
    //     cout << node[i] << " ";
    // }
    // cout << endl;

    vector<pair<char, char>> edges;
    while (scanf("%c%c\n", &x, &y) != EOF)
    {
        edges.push_back(make_pair(x, y));
    }

    // for (int i = 0; i < edges.size(); i++)
    // {
    //     cout << edges[i].first << "-" << edges[i].second << endl;
    // }
    // cout << endl;

    int result = countConnectedComponents(node, edges);
    cout << result << endl;
}
