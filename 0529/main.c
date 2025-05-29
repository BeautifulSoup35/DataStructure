#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "graph.h"
#include "stack.h"



int main(void)
{
	srand(time(NULL));

	GraphType g;
	graph_init(&g);
	const char* fname = "topological.txt";
	FILE* fin = fopen(fname, "r");
	if (fin == NULL) {
		fprintf(stderr, "can't open\n", fname);
		exit(EXIT_FAILURE);
	}
	int n_nodes;
	fscanf(fin, "%d", &n_nodes);
	for (int i = 0; i < n_nodes; i++) insert_vertex(&g, i);
	/*
	//�ʱ�ȭ����
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);
	*/
	int fr, to;
	while (fscanf(fin, "%d %d", &fr, &to) == 2) insert_edge(&g, fr, to);
	/*
	//���� 0�� ���� ����Ʈ ����
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	//���� 1�� ���� ����Ʈ ����
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	//���� 2�� ���� ����Ʈ ����
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	//���� 3�� ���� ����Ʈ ����
	insert_edge(&g, 3, 5);
	//���� 4�� ���� ����Ʈ ����
	insert_edge(&g, 4, 5);
	*/
	fclose(fin);
	//���� ���� 
	topo_sort(&g);
	// ���� �޸� ��ȯ �ڵ� ����
	
	return 0;
}