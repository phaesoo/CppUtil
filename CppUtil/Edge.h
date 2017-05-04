#pragma once

#include <utility>

#include "Vertex.h"

template <typename T>
class Edge
{
    std::pair< Vertex<T>, Vertex<T> > _data;
public:
    Edge(const T& vt_i, const T& vt_j)
        : _data(std::make_pair(vt_i, vt_j)) {}

public:
    bool operator==(const Edge<T>& rhs) const
    {
        return this->_data == rhs._data;
    }

    Vertex<T> GetHead() { return _data.first; }
    Vertex<T> GetTail() { return _data.second;  }

    bool IsSorted()
    {
        return _data.first <= _data.second;
    }
};