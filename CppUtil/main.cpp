#include "Test_math.h"
#include "Graph.h"
#include <type_traits>

int main()
{
    Test_Compare();

    Vertex<int> a(3);

    //Edge<int> edge(1, 4);

    Graph<int> gr(false);
    gr.AddVertex(std::move(a));
    gr.AddVertex(Vertex<int>(4));
    gr.AddVertex(5);
    gr.AddEdge(Edge<int>(4,3));

    return 0;
}