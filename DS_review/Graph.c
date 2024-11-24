#include "DS_config.h"
#include "DataStruct.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(void) {
    // input graph data
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);
    
    Array graph[nodes];
    for (int i=0; i<nodes; ++i) {
        graph[i] = GetArray(4);
    }

    for (int i=0; i<edges; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        ArrayPushElem(graph[from], to);
    }


    // BFS Traverse
    bool visited[nodes];
    memset(visited, 0, nodes * sizeof(bool));
    Queue qe = GetQueue();

    for (int i=0; i<nodes; ++i) {
        if (visited[i]) {
            continue;
        }

        printf("%d ", i);
        visited[i] = true;
        QueuePushElem(qe, i);

        while (!IsEmptyQueue(qe)) {
            QueueElemType top = QueuePopElem(qe);

            for (int i=0; i<GetArrLen(graph[top]); ++i) {
                ArrayElemType adjnode = ArrayGetElem(graph[top], i);

                if (!visited[adjnode]) {
                    visited[adjnode] = true;
                    printf("%d ", adjnode);
                    QueuePushElem(qe, adjnode);
                }
                
            }
        }
    }

    putchar('\n');


    // TopoSort
    int indegree[nodes];
    memset(indegree, 0, nodes * sizeof(int));

    for (int i=0; i<nodes; ++i) {
        for (int j=0; j<GetArrLen(graph[i]); ++j) {
            indegree[j]++;
        }
    }

    for (int i=0; i<nodes; ++i) {
        if (!indegree[i]) {
            QueuePushElem(qe, i);
        }
    }

    while (!IsEmptyQueue(qe)) {
        QueueElemType top = QueuePopElem(qe);
        printf("%d ", top);

        for (int i=0; i<GetArrLen(graph[top]); ++i) {
            ArrayElemType adjnode = ArrayGetElem(graph[top], i);
            --indegree[adjnode];
            
            if (!indegree[adjnode]) {
                QueuePushElem(qe, adjnode);
            }

        }
    }

    putchar('\n');

    for (int i=0; i<nodes; ++i) {
        if (indegree[i]) {
            puts("Not an AOV !");
            break;
        }
    }


    // // DFS Traverse
    memset(visited, 0, nodes * sizeof(bool));

    Stack stk1 = GetStack();
    Stack stk2 = GetStack();

    for (int j=0; j<nodes; ++j) {
        if (visited[j]) {
            continue;
        }
        printf("%d ", j);
        visited[j] = true;

        int node = j;
        int index = 0;

        POS:

        for (int i=index; i<GetArrLen(graph[node]); ++i) {
            ArrayElemType adjnode = ArrayGetElem(graph[node], i);

            if (!visited[adjnode]) {
                printf("%d ", adjnode);
                visited[adjnode] = true;

                StackPushElem(stk1, node);
                StackPushElem(stk2, i);

                node = adjnode;
                index = 0;
                goto POS;
            }

        }

        if (!IsEmptyStack(stk1)) {
            node = StackPopElem(stk1);
            index = StackPopElem(stk2);
            goto POS;
        } else {
            continue;
        }
    }
    
    putchar('\n');


    // gc
    DeleteQueue(qe);
    DeleteStack(stk1);
    DeleteStack(stk2);
    for (int i=0; i<nodes; ++i) {
        DeleteArray(graph[i]);
    }

    puts("Done !");

    return 0;
}

// gcc Graph.c Array/Array.c List/List.c Stack/Stack.c Queue/Queue.c -o test.exe

// 20 100
// 12 4
// 7 17
// 17 3
// 5 1
// 3 13
// 19 9
// 9 8
// 11 5
// 0 5
// 8 18
// 9 17
// 13 8
// 6 2
// 7 1
// 13 17
// 18 1
// 3 6
// 8 2
// 14 15
// 5 12
// 8 11
// 19 11
// 2 4
// 11 16
// 1 8
// 13 10
// 16 6
// 7 3
// 15 16
// 9 3
// 14 17
// 5 14
// 11 0
// 11 9
// 0 9
// 13 12
// 1 19
// 15 18
// 17 0
// 14 10
// 11 2
// 9 14
// 17 2
// 12 15
// 14 12
// 17 11
// 11 4
// 6 1
// 16 3
// 1 14
// 5 2
// 16 5
// 10 19
// 18 2
// 7 11
// 12 1
// 9 2
// 4 15
// 8 6
// 1 0
// 8 15
// 10 12
// 1 9
// 16 7
// 12 3
// 3 0
// 14 0
// 3 18
// 19 8
// 0 4
// 19 17
// 16 9
// 7 18
// 3 11
// 10 7
// 11 6
// 9 18
// 0 15
// 2 12
// 6 12
// 3 4
// 12 16
// 19 12
// 8 12
// 7 13
// 12 9
// 14 6
// 5 15
// 10 11
// 0 19
// 6 7
// 7 15
// 4 16
// 10 4
// 2 0
// 9 15
// 6 0
// 13 15
// 6 9
// 7 8