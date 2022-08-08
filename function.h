#pragma once
#include"implement.h"
#include<vector>
using namespace std;


//adjList initialize function
void InitGraph(AGraph &G, int nodenumber, vector<vector<pair<int, int>>> edgeset, int weight, int direction);
vector<vector<pair<int, int>>> get_input(int weight, int direction);
void show(AGraph &G);
AGraph AGraph_Init();

//adjacency matrix
void InitMGraph(MGraph &G, int nodenumber, vector<vector<pair<int, int>>> edgeset, int weight, int direction);
void show_MG(const MGraph &G);
MGraph MGraph_Init();

//Cross-linked List
void InitCGraph(CGraph &G, int nodenumber, vector<vector<pair<int, int>>> edgeset, int weight, int dierction);
void show_CG(const CGraph&G);
CGraph CGraph_Init();

//search
vector<int> BFS(const AGraph & G, int v);
vector<int> DFS(const AGraph & G, int v);
void show_vector(vector<int>input);

//algorithm
int dij(const AGraph &G, int src, int dst);
vector<vector<pair<int, int>>> get_sample1();
bool TopoSort_A(AGraph G);