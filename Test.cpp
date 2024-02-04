// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<string, unordered_set<string>> tree;
// unordered_map<string, string> parent;

// void remove(string node) {
//     for(auto child : tree[node]) {
//         remove(child);
//     }
//     tree.erase(node);
//     tree[parent[node]].erase(node);
//     parent.erase(node);
// }

// int count(string node) {
//     int total = 1; // count the node itself
//     for(auto child : tree[node]) {
//         total += count(child);
//     }
//     return total;
// }

// vector<int> getSubFolders(vector<vector<string>> existingStructureEdges, vector<string> queries) {
//     vector<int> result;
//     for(auto edge : existingStructureEdges) {
//         tree[edge[0]].insert(edge[1]);
//         parent[edge[1]] = edge[0];
//     }
//     for(auto query : queries) {
//         stringstream ss(query);
//         string operation, x, y;
//         ss >> operation >> x;
//         if(operation == "mkdir") {
//             ss >> y;
//             tree[x].insert(y);
//             parent[y] = x;
//         } else if(operation == "rmdir") {
//             remove(x);
//         } else if(operation == "count_subdir") {
//             result.push_back(count(x));
//         }
//     }
//     return result;
// }

// int main() {
//     vector<vector<string>> existingStructureEdges = {{"folder-2", "folder-1"}, {"folder-2", "folder-3"}, {"folder-2", "folder-4"}};
//     vector<string> queries = {"mkdir folder-1 folder-5", "count_subdir folder-2", "count_subdir folder-1", "count_subdir folder-3", "count_subdir folder-4", "count_subdir folder-5"};
//     vector<int> result = getSubFolders(existingStructureEdges, queries);
//     for(int i : result) {
//         cout << i << endl;
//     }
//     return 0;
// }
 


/*
 * Complete the 'getMinimumOperations' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY executionTime
 *  2. INTEGER x
 *  3. INTEGER y
 */

int getMinimumOperations(vector<int> executionTime, int x, int y) {
    int sum = 0; 
    for(auto &it: executionTime) sum += it;

    return sum/x;
}

int main()
{
    vector<int> executionTime = {4, 4, 4, 4, 4, 4, 4, 4};
    cout << getMinimumOperations(executionTime, 3, 2);
    return 0;
}

#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> createAdjacencyList(int nodes, vector<int>& from, vector<int>& to) {
    vector<vector<int>> adjacencyList(nodes);
    for (int i = 0; i < from.size(); i++) {
        adjacencyList[from[i]-1].push_back(to[i]-1);
        adjacencyList[to[i]-1].push_back(from[i]-1);
    }
    return adjacencyList;
}

pair<int, int> findCenterAndDiameter(vector<vector<int>>& network, vector<int>& depth) {
    int farthestNode = farthestNode(network, 0, -1, depth);
    farthestNode = farthestNode(network, farthestNode, -1, depth);

    int diameter = depth[farthestNode];
    vector<int> path(diameter + 1);
    getPath(network, farthestNode, -1, path, diameter);

    int center = path[diameter / 2];
    return {center, diameter};
}

int farthestNode(vector<vector<int>>& network, int node, int parent, vector<int>& depth) {
    if (depth[node] == network.size() - 1) {
        return node;
    }

    int farthestNode = node;
    for (int neighbor : network[node]) {
        if (neighbor != parent) {
            depth[neighbor] = depth[node] + 1;
            int farthestNodeInSubtree = farthestNode(network, neighbor, node, depth);
            if (depth[farthestNodeInSubtree] > depth[farthestNode]) {
                farthestNode = farthestNodeInSubtree;
            }
        }
    }
    return farthestNode;
}

bool getPath(vector<vector<int>>& network, int node, int parent, vector<int>& path, int depth) {
    if (depth == 0) {
        path[0] = node;
        return true;
    }
    for (int neighbor : network[node]) {
        if (neighbor != parent && getPath(network, neighbor, node, path, depth - 1)) {
            path[depth] = node;
            return true;
        }
    }
    return false;
}

int calculateMin(int networkANodes, vector<int>& networkAFrom, vector<int>& networkATo, int networkBNodes, vector<int>& networkBFrom, vector<int>& networkBTo) {
    vector<vector<int>> networkA = createAdjacencyList(networkANodes, networkAFrom, networkATo);
    vector<vector<int>> networkB = createAdjacencyList(networkBNodes, networkBFrom, networkBTo);

    vector<int> depthA(networkANodes);
    vector<int> depthB(networkBNodes);

    pair<int, int> centerAndDiameterA = findCenterAndDiameter(networkA, depthA);
    pair<int, int> centerAndDiameterB = findCenterAndDiameter(networkB, depthB);

    int minDistanceAfterConnection = max(max(centerAndDiameterA.second, centerAndDiameterB.second),
            max(centerAndDiameterA.second, centerAndDiameterB.second / 2) + max(centerAndDiameterB.second, centerAndDiameterA.second / 2) + 1);

    return minDistanceAfterConnection;
}