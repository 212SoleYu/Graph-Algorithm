#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<queue>
#include"implement.h"
#include"function.h"
using namespace std;

/*本文件首先实现通过邻接表来实现的图结构，然后在次基础上实现以下算法：
	1. 迪杰斯特拉算法
	2. Floyd算法
	3. 拓扑排序
	*/

int main()
{
	/*
	//the initialization of all sorts of graphs
	G = Agraph_Init();
	
	//test the BFS and the DFS
	for (int i = 0; i < G.vexnum; i++)q
	{
		int startnode = i;
		printf("以节点%d为起点的广度优先搜索序列：\n", startnode);
		BFS(G, startnode);
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		int startnode = i;
		printf("以节点%d为起点的深度优先搜索序列：\n", startnode);
		DFS(G, startnode);
	}
	AG = AGraph_Init();
	//the dij
	AGraph G;
	InitGraph(G, 5, get_sample1(), 1, 1);
	show(G);
	cout << dij(G, 0, 2) << endl;
	
	MGraph MG;
	InitMGraph(MG, 5, get_sample1(), 1, 1);
	show_MG(MG);
	*/
	AGraph AG;
	AG = AGraph_Init();
	TopoSort_A(AG);

}