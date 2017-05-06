#pragma once

#include <vector>
#include <algorithm>
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
        return std::find(_vertices.begin(), _vertices.end(), vt) != _vertices.end();
    }

    bool AddEdge(Edge<T>& edge)
    {
        // 존재하지 않는 vertex일 경우 실패
        if (!IsExistVertex(edge.GetHead()))
        {
            if (!IsExistVertex(edge.GetTail()))
            {
                assert(0);
                return false;
            }
        }

        if (!HasDirection())
        {
            if (!edge.IsSorted())
            {
                // 작은수를 key로
                assert(0);
                return false;
            }
        }

        auto itr = std::find(_edges.begin(), _edges.end(), edge);
        if (itr != _edges.end())
        {
            // 중복
            assert(0);
            return false;
        }

        _edges.push_back(edge);
        return true;
    }

    void GetAdjacent(Vertex<T> vt, std::vector< Vertex<T> >& neighbor) const
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

    void GetAdjacentMatrix(std::vector< std::vector<int> >& matrix)
    {
        matrix.clear();

        size_t sz = _vertices.size();

        matrix.resize(sz);

        for (auto i = 0; i < sz; ++i)
        {
            matrix[i].resize(sz, 0);

            for (auto j = 0; j < sz; ++j)
            {
                if (std::find(_edges.begin(), _edges.end(), Edge<T>(_vertices[i], _vertices[j])) != _edges.end())
                {
                    matrix[i][j] = 1;
                }
            }
        }
    }

    std::vector<Vertex<T>> GetVertices() { return _vertices; }

    bool HasDirection() { return _hasDirection; }

private: // properties
    bool _hasDirection;
};
