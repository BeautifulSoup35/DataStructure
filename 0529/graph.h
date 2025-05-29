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
	int n;	// ������ ����
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;





void graph_init(GraphType* g);// �׷��� �ʱ�ȭ 
void insert_vertex(GraphType* g, int v);// ���� ���� ����
void insert_edge(GraphType* g, int u, int v);// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.

int topo_sort(GraphType* g);//�������� ����

#endif // !__TOPO__

