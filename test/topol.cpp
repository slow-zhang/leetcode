#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 1000000;
const int INF = (1 << 29);
int n;
vector<int> G[MAX];
vector<int> result;
queue<int> line;
int indeg[MAX];
bool V[MAX];
void bfs(int s)
{
    line.push(s);
    V[s] = true;
    while (!line.empty())
    {
        int u = line.front();
        line.pop();
        result.push_back(u);
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            indeg[v]--;
            if (indeg[v] == 0 && V[v] == false)
            {
                V[v] = true;
                line.push(v);
            }
        }
    }
}
void tsort()
{
    for (int i = 0; i < n; i++)
    {
        for (int u = 0; u < G[i].size(); u++)
        {
            int v = G[i][u];
            indeg[v]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0 && V[i] == false)
            bfs(i);
    }
    for (int u = 0; u < result.size(); u++)
        cout << result[u] << endl;
}
int main()
{
    memset(indeg, 0, sizeof(indeg));
    memset(V, 0, sizeof(V));
    int num, a, b;
    cin >> n >> num;
    while (num--)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }
    tsort();
    return 0;
}
