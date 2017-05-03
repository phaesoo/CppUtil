#pragma once

#include <vector>
#include <set>
#include "Vertex.h"

template <typename T>
class Graph
{
    using Edge = std::pair<Vertex<T>, Vertex<T>>;

public:
    Graph(bool hasDirection = false)
        : _hasDirection(hasDirection) {}

public:
    bool AddVertex(Vertex<T> vt)
    {
        auto itr = find(_vertices.begin(), _vertices.end(), vt);
        if (itr != _vertices.end())
        {
            // 중복
            assert(0);
            return false;
        }
        _vertices.push_back(vt);
        return true;
    }

    bool AddEdge(const Edge&& edge)
    {
        if (!HasDirection())
        {
            if (edge.first > edge.second)
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

    void FindNeighbor(Vertex<T> vt, std::set< Vertex<T> >& neighbor) const // 순서 자동정렬을위해 set사용
    {
        neighbor.clear();

        for (auto itr = _edges.begin(); itr != _edges.end(); ++itr)
        {
            if (itr->first == vt)
            {
                neighbor.insert(itr->second);
            }
            else if (itr->second == vt)
            {
                neighbor.insert(itr->first);
            }
        }
    }

    std::vector<Vertex<T>> GetVertexes() { return _vertices; }

    bool HasDirection() { return _hasDirection; }

private:
    std::vector< Vertex<T> > _vertices;
    std::vector<Edge> _edges;

    bool _hasDirection;
};