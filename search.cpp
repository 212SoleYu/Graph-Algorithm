#include"implement.h"
#include"function.h"
#include<queue>
#include<stack>

//the BFS of the graph
vector<int> BFS(const AGraph & G, int v)
{
	//the BFS of the graph from node v
	vector<int> ans;
	int *visited = new int[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;//0 means unvisited
	queue<Vnode> q;
	q.push(G.adjList[v]);
	while (!q.empty())
	{
		int serial = q.front().val;
		ans.push_back(serial);
		visited[serial] = 1;
		edgeNode* temp = G.adjList[serial].firstEgde;
		while (temp)
		{
			if (visited[temp->endnode] == 0)
			{
				visited[temp->endnode] = 1;
				q.push(G.adjList[temp->endnode]);
			}
			temp = temp->nextedge;
		}
		q.pop();
	}
	show_vector(ans);
	return ans;
}

//the DFS of the graph
vector<int> DFS(const AGraph & G, int v)
{
	vector<int> ans;
	int *visited = new int[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;//0 means unvisited
	stack<Vnode> s;
	s.push(G.adjList[v]);
	while (!s.empty())
	{
		int serial = s.top().val;
		s.pop();
		if (visited[serial] == 0)
		{
			ans.push_back(serial);
			visited[serial] = 1;
		}
		else continue;
		edgeNode* temp = G.adjList[serial].firstEgde;
		stack<Vnode> rev;
		while (temp)
		{
			if (visited[temp->endnode] == 0)
			{
				rev.push(G.adjList[temp->endnode]);
			}
			temp = temp->nextedge;
		}
		while (!rev.empty())
		{
			s.push(rev.top());
			rev.pop();
		}
	}
	show_vector(ans);
	return ans;
}