# Graph-Algorithm
数据结构图相关结构和算法

## 图的实现方式
三种实现方式：邻接矩阵Adjacency Matrix、邻接表Adjacency table、十字链表Cross-Linked List（还有一种邻接多重表，类似于十字链表的无向图版本）

implement.h和implement.cpp代码中分别定义和实现了对于邻接矩阵和邻接表的实现以及初始化函数，十字链表暂时尚待补充。

## 图的搜索方式
两种搜索方式BFS和DFS均在search.cpp代码中实现

## 图的相关应用
### 最小生成树
两种找到最小生成树的办法：Prim算法和Kruskal算法，分别根据顶点和边进行检索，算法尚待补充。
### 最短路径
两种求最短路径的办法：迪杰斯特拉算法和弗洛伊德算法。algorithm.cpp文件中实现了基于邻接表实现的迪杰斯特拉算法。弗洛伊德算法尚待补充。
### 拓扑排序
AOV网的拓扑排序在algorithm.cpp文件中实现了基于邻接表的拓扑排序算法。
### 关键路径
AOE网尚待补充
