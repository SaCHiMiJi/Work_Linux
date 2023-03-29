#include <iostream>
#include <vector>

using namespace std;

int find_general(int player, vector<int> &generals)
{
    if (generals[player] == player)
    {
        return player;
    }
    else
    {
        generals[player] = find_general(generals[player], generals);
        return generals[player];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> soldiers(n + 1);
    vector<int> generals(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> soldiers[i];
        generals[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        int general_a = find_general(a, generals);
        int general_b = find_general(b, generals);

        if (general_a == general_b)
        {
            cout << -1 << endl;
        }
        else
        {
            if (soldiers[general_a] == soldiers[general_b])
            {
                if (general_a < general_b)
                {
                    soldiers[general_a] += soldiers[general_b] / 2;
                    generals[general_b] = general_a;
                    cout << general_a << endl;
                }
                else
                {
                    soldiers[general_b] += soldiers[general_a] / 2;
                    generals[general_a] = general_b;
                    cout << general_b << endl;
                }
            }
            else if (soldiers[general_a] > soldiers[general_b])
            {
                soldiers[general_a] += soldiers[general_b] / 2;
                generals[general_b] = general_a;
                cout << general_a << endl;
            }
            else
            {
                soldiers[general_b] += soldiers[general_a] / 2;
                generals[general_a] = general_b;
                cout << general_b << endl;
            }
        }
    }

    return 0;
}
