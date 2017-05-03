#include "Test_math.h"
#include "Graph.h"
#include <type_traits>

int main()
{
    Test_Compare();

    Vertex<int> a(3);

    Graph<int> gr(false);
    gr.AddVertex(std::move(a));

    return 0;
}