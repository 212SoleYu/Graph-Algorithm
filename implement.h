#pragma once
#define MAXNUMBER 100

// adjlist
// the node of the edge in graph
struct edgeNode
{
	int weight;
	int endnode;//the other vex of this edge
	edgeNode* nextedge;
};

// the node of the vex in graph
struct Vnode
{
	int val;//the value or the number of the node
	int indegree = 0;
	int outdegree = 0;
	int degree = 0;
	edgeNode* firstEgde;//in the list,point to the first edge of the vex 
};

//Adjacency table
struct AGraph
{
	Vnode adjList[MAXNUMBER];//the list of Vnode
	int vexnum;//the number of vexes in graph
	int edgenum;//the number of edges in graph
	int direction;//to show whether the graph is directed
	int weightFlag;//to show whether the graph has weights
};

//Adjacency matrix
struct MGraph
{
	int vexnum;
	int edgenum;
	int direction;
	int weightFlag;
	int AM[MAXNUMBER][MAXNUMBER]; //adjacency matrix
};

//Cross-Linked list
struct CedgeNode
{
	int tailvex;
	int headvex;
	CedgeNode* hlink;//the next edge that has same head;
	CedgeNode* tlink;//the next edge that has same tail;
	int info;
};

struct CVnode
{
	int data;
	CedgeNode* firstin;//the first edge ends at this node
	CedgeNode* firstout;//the first edge starts at this node
};

struct CGraph
{
	int vexnum;
	int edgenum;
	int direction;
	int weightFlag;
	CVnode CList[MAXNUMBER];
};