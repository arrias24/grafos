#include "graph.hpp"
#include "../../model/person.h"

template <class T>
Graph<T>::Graph(int numVertices) 
{
    this->numVertices = numVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    vertices = new T[numVertices];
    currentVertexCount = 0;
}

template <class T>
Graph<T>::~Graph() 
{
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] vertices;
}

template <class T>
void Graph<T>::addVertex(T vertex) {
    if (currentVertexCount < numVertices) {
        vertices[currentVertexCount] = vertex;
        currentVertexCount++;
    } else {
        cout << "No se pueden agregar más vértices" << endl;
    }
}

template <class T>
void Graph<T>::follow(T follower, T followed) {
    int followerIndex = getIndex(follower);
    int followedIndex = getIndex(followed);
    if (followerIndex != -1 && followedIndex != -1) {
        adjMatrix[followerIndex][followedIndex] = 1;
    } else {
        cout << "[ERROR] - Uno o ambos vertices no existen" << endl;
    }
}

template <class T>
void Graph<T>::unfollow(T follower, T followed) {
    int followerIndex = getIndex(follower);
    int followedIndex = getIndex(followed);
    if (followerIndex != -1 && followedIndex != -1) {
        adjMatrix[followerIndex][followedIndex] = 0;
    } else {
        cout << "[ERROR] - Uno o ambos vértices no existen" << endl;
    }
}

template <class T>
void Graph<T>::printFollowers() {
    for (int i = 0; i < currentVertexCount; i++) {
        cout << "Followers de " << vertices[i].nombre << ": ";
        for (int j = 0; j < currentVertexCount; j++) {
            if (adjMatrix[j][i] == 1) {
                cout << vertices[j].nombre << " " << vertices[j].apellido << ", ";
            }
        }
        cout << endl;
    }
}

template <class T>
T Graph<T>::getVertex(int index) {
    return vertices[index];
}

template <class T>
int Graph<T>::getIndex(T vertex) {
    for (int i = 0; i < currentVertexCount; i++) {
        if (vertices[i].nombre == vertex.nombre && vertices[i].apellido == vertex.apellido) {
            return i;
        }
    }
    return -1; // vertex no encontrado
}

template <class T>
void Graph<T>::shortestPath(T startVertex, T endVertex) 
{
    int max = 1000;  // un valor grande para representar "infinito"
    int startIndex = getIndex(startVertex);
    int endIndex = getIndex(endVertex);

    if (startIndex == -1 || endIndex == -1) 
    {
        cout << "[ERROR] - Uno o ambos vertices no existen" << endl;
        return;
    }

    int* dist = new int[numVertices];
    bool* visited = new bool[numVertices];
    int* prev = new int[numVertices];

    for (int i = 0; i < numVertices; ++i) 
    {
        dist[i] = max;
        visited[i] = false;
        prev[i] = -1;
    }

    dist[startIndex] = 0;

    for (int i = 0; i < numVertices; ++i) 
    {
        int u = -1;

        for (int j = 0; j < numVertices; ++j) 
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == max) 
        {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < numVertices; ++v) 
        {
            if (adjMatrix[u][v] && !visited[v]) 
            {
                int alt = dist[u] + 1; // Peso de cada arista es 1
                if (alt < dist[v]) 
                {
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }

    if (dist[endIndex] == max) 
    {
        cout << "No existe un camino desde " << startVertex.nombre << " a " << endVertex.nombre << endl;
    } 
    else 
    {
        cout << "El camino mas corto desde " << startVertex.nombre << " a " << endVertex.nombre << " es: ";
        int* path = new int[numVertices];
        int count = 0;
        for (int at = endIndex; at != -1; at = prev[at]) 
        {
            path[count++] = at;
        }

        // Imprimir el camino en el orden correcto
        for (int i = count - 1; i >= 0; --i) 
        {
            if (i < count - 1) cout << " -> ";
            cout << vertices[path[i]].nombre << " " << vertices[path[i]].apellido;
        }
        cout << endl;
        
        delete[] path;
    }

    delete[] dist;
    delete[] visited;
    delete[] prev;
}