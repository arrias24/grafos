#ifndef GRAF_H
#define GRAF_H

#include <iostream>
using namespace std;

template <class T>
class Graph {
private:
    int numVertices;
    int** adjMatrix;
    T* vertices;
    int currentVertexCount;

public:
    Graph(int numVertices);
    ~Graph();
    void addVertex(T vertex);
    void follow(T follower, T followed);
    void unfollow(T follower, T followed);
    void printFollowers();
    T getVertex(int index);
    int getIndex(T vertex);
    void shortestPath(T startVertex, T endVertex);
};

#endif
