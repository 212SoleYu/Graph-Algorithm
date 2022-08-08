#include"implement.h"
#include"function.h"
#include<iostream>
using namespace std;


//the function to get the graph data from user's input
vector<vector<pair<int, int>>> get_input(int weight, int direction)
{
	vector<vector<pair<int, int>>> ans;
	int vexnumebr;
	printf("������ͼ�нڵ������\n");
	cin >> vexnumebr;
	for (int i = 0; i < vexnumebr; i++)
	{
		int per_edge_number;
		printf("���Ϊ%d�Ľڵ�ıߵ���ĿΪ��\n", i);
		cin >> per_edge_number;
		vector<pair<int, int>> per_edge(per_edge_number);
		for (int j = 0; j < per_edge_number; j++)
		{
			int endnode; int per_weight = 0;
			printf("������ߵĽڵ���ţ�\n");
			cin >> endnode;
			if (weight > 0)
			{
				printf("������ߵ�Ȩ�أ�\n");
				cin >> per_weight;
			}
			pair<int, int> temp(endnode, per_weight);
			per_edge[j] = temp;
		}
		ans.push_back(per_edge);
	}
	return ans;
}

//adjList initialize related
//it carries a list of edge to initial the graph ,the pair means <endnode,weight>
//the argument direction means the graph is directed when it is euqal to 1,weight_on means the graph has weights when its positive
//the numbers of vex count from 0 
void InitGraph(AGraph &G, int nodenumber, vector<vector<pair<int, int>>> edgeset, int weight, int direction)
{
	int edgenumber = 0;
	G.vexnum = nodenumber;
	G.direction = direction; G.weightFlag = weight;
	for (int i = 0; i < nodenumber; i++)
	{
		Vnode temp;
		temp.val = i;
		temp.firstEgde = nullptr;
		G.adjList[i] = temp;
	}
	for (int i = 0; i < nodenumber; i++)
	{
		int per = edgeset[i].size();
		G.adjList[i].outdegree = per;
		edgenumber += per;
		if (per == 0)
		{
			G.adjList[i].firstEgde = nullptr;
			continue;
		}
		edgeNode* perlist = new edgeNode;
		edgeNode* pointer = perlist;
		for (int j = 0; j < per; j++)
		{
			edgeNode *temp = new edgeNode;
			temp->nextedge = nullptr;
			temp->endnode = edgeset[i][j].first;
			if (weight > 0)
				temp->weight = edgeset[i][j].second;
			G.adjList[temp->endnode].indegree += 1;
			pointer->nextedge = temp;
			pointer = pointer->nextedge;
		}
		G.adjList[i].firstEgde = perlist->nextedge;
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		G.adjList[i].degree = G.adjList[i].indegree + G.adjList[i].outdegree;
		if (direction == 0) G.adjList[i].degree >>= 1;
	}
	if (direction == 0)
	{
		edgenumber >>= 1;
	}
	G.edgenum = edgenumber;
}
void show(AGraph &G)
{
	printf("ͼ�нڵ����Ϊ��%d\nͼ�бߵ���ĿΪ%d\n", G.vexnum, G.edgenum);
	printf("ÿ���߰����ıߣ�\n");
	int number = G.vexnum;
	for (int i = 0; i < number; i++)
	{
		printf("���Ϊ%d�Ľڵ�����Ϊ%d������Ϊ%d����Ϊ��%d\n", i, G.adjList[i].indegree, G.adjList[i].outdegree, G.adjList[i].degree);
		printf("���Ϊ%d�Ľڵ���صıߣ�\n", i);
		edgeNode* pointer = G.adjList[i].firstEgde;
		while (pointer)
		{
			printf("%d\t", pointer->endnode);
			if (pointer->weight > 0)
				printf("Ȩ�أ�%d;\t", pointer->weight);
			pointer = pointer->nextedge;
		}
		printf("\n");
	}
}
void show_vector(vector<int>input)
{
	int size = input.size();
	for (auto c : input)
	{
		printf("%d ", c);
	}
	printf("\n");
}
AGraph AGraph_Init()
{
	printf("������ͼ�ĳ�ʼ���ԣ�\n0����������Ȩͼ��1����������Ȩͼ\n2����������Ȩͼ��3����������Ȩͼ\n");
	int properties;
	cin >> properties;
	int weight = properties & 0x1;
	int direction = (properties & 0x2) >> 1;;
	vector<vector<pair<int, int>>> input = get_input(weight, direction);
	AGraph G;
	InitGraph(G, input.size(), input, weight, direction);
	show(G);
	return G;
}


//adjacency matrix related
void InitMGraph(MGraph &G, int nodenumber, vector<vector<pair<int, int>>> edgeset, int weight, int direction)
{
	G.direction = direction;
	G.weightFlag = weight;
	G.vexnum = nodenumber;
	int edgenumber = 0;
	if (weight > 0)
	{
		for (int i = 0; i < nodenumber; i++)
		{
			for (int j = 0; j < nodenumber; j++)
			{
					G.AM[i][j] = INT_MAX;
			}
		}
	}
	else if (weight == 0)
	{
		for (int i = 0; i < nodenumber; i++)
		{
			for (int j = 0; j < nodenumber; j++)
			{
				G.AM[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < nodenumber; i++)
	{
		int per = edgeset[i].size();
		edgenumber += per;
		for (int j = 0; j < per; j++)
		{
			if (weight > 0)
			{
				G.AM[i][edgeset[i][j].first] = edgeset[i][j].second;
			}
			else
			{
				G.AM[i][edgeset[i][j].first] = 1;
			}
		}
	}
	if (direction == 0)
	{
		edgenumber >>= 1;
	}
	G.edgenum = edgenumber;
}
void show_MG(const MGraph &G)
{
	printf("ͼ�нڵ����Ϊ��%d\nͼ�бߵ���ĿΪ%d\n", G.vexnum, G.edgenum);
	printf("��ͼ���ڽӾ������£�\n");
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			if (G.AM[i][j] == INT_MAX)
				printf("��\t");
			else 
				printf("%d\t", G.AM[i][j]);
		}
		printf("\n");
	}
}
MGraph MGraph_Init()
{
	printf("������ͼ�ĳ�ʼ���ԣ�\n0����������Ȩͼ��1����������Ȩͼ\n2����������Ȩͼ��3����������Ȩͼ\n");
	int properties;
	cin >> properties;
	int weight = properties & 0x1;
	int direction = (properties & 0x2) >> 1;;
	vector<vector<pair<int, int>>> input = get_input(weight, direction);
	MGraph G;
	InitMGraph(G, input.size(), input, weight, direction);
	show_MG(G);
	return G;
}

//Cross-linked List related
void InitCGraph(CGraph &G, int nodenumber, vector<vector<pair<int, int>>> edgeset, int weight, int direction)
{
	G.direction = direction; G.vexnum = nodenumber; G.weightFlag = weight; int edgenumber = 0;
	CedgeNode* firstInList = new CedgeNode[nodenumber];
	CedgeNode* Inpointer = new CedgeNode[nodenumber];
	for (int i = 0; i < nodenumber; i++)
	{
		Inpointer[i] = firstInList[i];
		CVnode temp;
		temp.data = i;
		int per = edgeset[i].size();
		CedgeNode* firstoutEdge;
		CedgeNode* pointer = firstoutEdge;
		for (int j = 0; j < per; j++)
		{
			CedgeNode *newEdge = new CedgeNode;
			newEdge->tailvex = i;
			newEdge->headvex = edgeset[i][j].first;
			newEdge->tlink = nullptr;

			pointer->tlink = newEdge;
			pointer = pointer->tlink;
		}
		temp.firstout = firstoutEdge->tlink;
		G.CList[i] = temp;
	}



}






void show_CG(const CGraph&G);
CGraph CGraph_Init();