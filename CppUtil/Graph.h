#pragma once

#include <vector>
#include <set>
#include "Edge.h"

template <typename T>
class Graph
{
    std::vector< Vertex<T> > _vertices;
    std::vector< Edge<T> > _edges;

public:
    Graph(bool hasDirection = false)
        : _hasDirection(hasDirection) {}

public:
    bool AddVertex(const Vertex<T>& vt)
    {
        if (IsExistVertex(vt))
        {
            // 중복
            assert(0);
            return false;
        }

        _vertices.push_back(vt);

        return true;
    }

    bool IsExistVertex(const Vertex<T>& vt)
    {
        return find(_vertices.begin(), _vertices.end(), vt) != _vertices.end();
    }

    bool AddEdge(Edge<T>& edge)
    {
        if (IsExistVertex(edge.GetHead()) && IsExistVertex(edge.GetHead()))

        if (!HasDirection())
        {
            if (!edge.IsSorted())
            {
                // 작은수를 key로
                assert(0);
                return false;
            }
        }

        auto itr = find(_edges.begin(), _edges.end(), edge);
        if (itr != _edges.end())
        {
            // 중복
            assert(0);
            return false;
        }

        _edges.push_back(edge);
        return true;
    }

    void GetAdjacent(Vertex<T> vt, std::vector< Vertex<T> >& neighbor) const // 순서 자동정렬을위해 set사용
    {
        neighbor.clear();

        for (auto itr = _edges.begin(); itr != _edges.end(); ++itr)
        {
            if (itr->first == vt)
            {
                neighbor.push_back(itr->second);
            }
            else if (itr->second == vt)
            {
                neighbor.push_back(itr->first);
            }
        }
    }

    void AdjacentMatrix();

    std::vector<Vertex<T>> GetVertices() { return _vertices; }

    bool HasDirection() { return _hasDirection; }

private: // properties
    bool _hasDirection;
};
