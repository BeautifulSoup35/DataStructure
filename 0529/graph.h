#ifndef __GRAPH__
#define __GRAPH__

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50


typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;





void graph_init(GraphType* g);// 그래프 초기화 
void insert_vertex(GraphType* g, int v);// 정점 삽입 연산
void insert_edge(GraphType* g, int u, int v);// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.

int topo_sort(GraphType* g);//위상정렬 수행

#endif // !__TOPO__

