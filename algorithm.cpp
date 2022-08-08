#include"function.h"
#include"implement.h"


//get sample graph to test
vector<vector<pair<int, int>>> get_sample1()
{
	vector<vector<pair<int, int>>> ans;
	vector<pair<int, int>>t1;
	pair<int, int> p1(1, 10);
	t1.push_back(p1);
	pair<int, int> p2(4, 5);
	t1.push_back(p2);
	ans.push_back(t1);
	pair<int, int> p3(2, 1);
	pair<int, int> p4(4, 2);
	vector<pair<int, int>>t2;
	t2.push_back(p3);
	t2.push_back(p4);
	ans.push_back(t2);
	vector<pair<int, int>> t3;
	pair<int, int> p5(3, 4);
	t3.push_back(p5);
	ans.push_back(t3);
	vector<pair<int, int>> t4;
	pair<int, int> p6(0, 7);
	pair<int, int> p7(2, 6);
	t4.push_back(p6);
	t4.push_back(p7);
	ans.push_back(t4);
	vector<pair<int, int>> t5;
	pair<int, int> p8(1, 3);
	pair<int, int> p9(2, 9);
	pair<int, int> p10(3, 2);
	t5.push_back(p8);
	t5.push_back(p9);
	t5.push_back(p10);
	ans.push_back(t5);
	return ans;
}

//Find the shortest path and return the length of it
int dij(const AGraph &G, int src, int dst)
{
	int *dist = new int[G.vexnum];
	int *visited = new int[G.vexnum];
	int *path = new int[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
	{
		path[i] = 0;
		dist[i] = INT_MAX;
		visited[i] = 0;
	}
	visited[src] = 1; dist[src] = 0;
	edgeNode* temp = G.adjList[src].firstEgde;
	while (temp)
	{
		dist[temp->endnode] = temp->weight;
		temp = temp->nextedge;
	}
	//init phase
	int setnumber = 1;
	int pre = src;
	while (setnumber < G.vexnum)
	{
		int turn = src;//the node which has the shortest path to the src node we set
		int min = INT_MAX;
		for (int i = 0; i < G.vexnum; i++)
		{
			if (visited[G.adjList[i].val] == 0)
			{
				turn = dist[G.adjList[i].val] < min ? i : turn;
				min = dist[G.adjList[i].val] < min ? dist[G.adjList[i].val] : min;
			}
		}
		//node turn is the shortest node from src in every turn
		//update the dist from src
		//as we set the graph with adjlist, we just update the node that connected with turn 
		visited[turn] = 1; setnumber++;
		edgeNode* temp = G.adjList[turn].firstEgde;
		while (temp)
		{
			if (visited[temp->endnode] == 0)
			{
				if (dist[temp->endnode] < dist[turn] + temp->weight)
				{
					dist[temp->endnode] = dist[temp->endnode];
				}
				else
				{
					dist[temp->endnode] = dist[turn] + temp->weight;
					path[temp->endnode] = turn;
				}
			}
			temp = temp->nextedge;
		}
	}
	vector<int> shortest;
	//show the path 
	int index = dst;
	printf("路径逆序：");
	while (index != src)
	{
		shortest.push_back(index);
		index = path[index];
	}
	shortest.push_back(src);
	reverse(shortest.begin(), shortest.end());
	for (auto c : shortest)
	{
		printf("%d\t", c);
	}
	printf("\n");
	return dist[dst];
}

//Topological Sorting
//implement by adjacency matrix
//if the graph can be sorted then return TRUE and print the array
//else return false;
bool TopoSort_A(AGraph G)
{
	//find the node that indegree is 0,remove it and its edges.repeat.
	vector<int> ans;
	int nodenumber = G.vexnum;
	int* visited = new int[nodenumber];
	for (int i = 0; i < nodenumber; i++)
	{
		visited[i] = 0;
	}
	while (ans.size() < nodenumber)
	{
		int serial=-1;
		for (int i = 0; i < nodenumber; i++)
		{
			if (G.adjList[i].indegree == 0 && visited[i] == 0)
			{
				serial = i; break;//the node which indegree is 0 in every turn
			}
		}
		if (serial == -1) return false;//it means there is a circle in the graph
		visited[serial] = 1;
		ans.push_back(G.adjList[serial].val);
		edgeNode* temp = G.adjList[serial].firstEgde;
		while (temp)
		{
			G.adjList[temp->endnode].indegree--;
			temp = temp->nextedge;
		}
	}
	printf("该图的一种拓扑排序为：");
	show_vector(ans);
	return true;
}