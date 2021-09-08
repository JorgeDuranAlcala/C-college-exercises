#include <bits/stdc++.h>
#include "myqueue.cpp"
using namespace std;
typedef map<string, vector<string>> adjlist;
typedef vector<pair<string, string>> Edges;

adjlist createAdjacencyList(Edges edges, vector<string> nodes);
void printAdjacencyList(adjlist adjencyList);
void depthFirstSearch(adjlist adjl, string start, string end);
void breathFirstSearch(adjlist adjl, string start, string end);

int main()
{
    Edges edges;
    vector<string> nodes;
    /* nodes = {"a", "b", "c", "d", "e"};
    edges.push_back({"b", "a"});
    edges.push_back({"a", "c"});
    edges.push_back({"c", "d"});
    edges.push_back({"d", "e"});
    edges.push_back({"b", "e"}); */

    nodes = {"0", "1", "5", "8", "2", "3", "4"};
    edges.push_back({"0", "8"});
    edges.push_back({"0", "1"});
    edges.push_back({"0", "5"});
    edges.push_back({"5", "8"});
    edges.push_back({"2", "3"});
    edges.push_back({"2", "4"});
    edges.push_back({"3", "4"});

    adjlist adjencyList = createAdjacencyList(edges, nodes);
    /* cout << "depth first search"
         << "\n";
    depthFirstSearch(adjencyList, "b", "d");
    cout << "breath first search"
         << "\n";
    breathFirstSearch(adjencyList, "a", "d"); */
    printAdjacencyList(adjencyList);

    return 0;
}

void DFS_helper(adjlist adjl, string start, string end, set<string> visited, int steps = 0)
{
    visited.insert(start);

    for (auto &&neighbor : adjl[start])
    {
        if (neighbor == end)
        {
            cout << "found: " << neighbor << " in " << steps << " steps"
                 << "\n";
            return;
        }

        if (visited.count(neighbor) == 0)
        {
            //cout << neighbor;
            DFS_helper(adjl, neighbor, end, visited, steps + 1);
        }
    }
}

void depthFirstSearch(adjlist adjl, string start, string end)
{
    set<string> visited;
    DFS_helper(adjl, start, end, visited);
}

void breathFirstSearch(adjlist adjl, string start, string end)
{
    Queue<string> nodes;
    set<string> visited;
    int steps = 0;

    nodes.enqueue(start);
    visited.insert(start);

    while (!nodes.isEmpty())
    {
        string current = nodes.dequeue();
        for (auto neighbor : adjl[current])
        {
            if (neighbor == end)
            {
                cout << "found: " << neighbor << " in " << steps << " steps"
                     << "\n";
                steps = 0;
            }

            if (visited.count(neighbor) == 0)
            {
                nodes.enqueue(neighbor);
                visited.insert(neighbor);
                steps++;
            }
        }
    }
}

void printAdjacencyList(adjlist adjencyList)
{
    for (auto &&v : adjencyList)
    {
        cout << v.first << ": ";
        cout << "(";
        for (auto &&i : v.second)
        {
            cout << i;
            auto endv = v.second.end();
            --endv;
            if (i != *endv)
            {
                cout << ", ";
            }
        }
        cout << ")"
             << "\n";
    }
}

adjlist createAdjacencyList(Edges edges, vector<string> nodes)
{
    adjlist adjencyList;

    for (auto &&currentNode : nodes)
        adjencyList[currentNode];

    for (auto &&edge : edges)
    {
        adjencyList[edge.first].push_back(edge.second);
        adjencyList[edge.second].push_back(edge.first);
    }

    return adjencyList;
}