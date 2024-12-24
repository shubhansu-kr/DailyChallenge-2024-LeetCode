// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/?envType=daily-question&envId=2024-12-24

#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int findTreeDiameter(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    vector<vector<int>> adjList(n);
    vector<int> degree(n, 0);

    for (auto &p : edges)
    {
        int u = p[0], v = p[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    queue<int> leaves;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            leaves.push(i);
    }

    int remaining_nodes = n, diameter = 0;
    while (remaining_nodes > 0)
    {
        if (remaining_nodes == 2)
        {
            diameter++;
            break;
        }
        if (remaining_nodes == 1)
            break;
        int leaf_count = leaves.size();
        remaining_nodes -= leaf_count;
        diameter += 2;

        for (int i = 0; i < leaf_count; i++)
        {
            int leaf = leaves.front();
            leaves.pop();

            for (int neighbor : adjList[leaf])
            {
                degree[neighbor]--;
                if (degree[neighbor] == 1)
                    leaves.push(neighbor);
            }
        }
    }
    cout << "Diameter : " << diameter << endl;
    return diameter;
}

class Solution
{
public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int d1 = findTreeDiameter(edges1);
        int d2 = findTreeDiameter(edges2);
        int merged = 1 + ceil(d1 / 2.0) + ceil(d2 / 2.0);
        return max(merged, max(d1, d2));
    }
};
