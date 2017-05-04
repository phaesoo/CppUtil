#pragma once

template <typename T>
class Vertex
{
    T _data;
public:
    Vertex(const T& data)
    {
        _data = data;
    }

public:
    bool operator==(const Vertex<T>& rhs) const
    {
        return this->_data == rhs._data;
    }

    bool operator<=(const Vertex<T>& rhs) const
    {
        return this->_data <= rhs._data;
    }

    T GetData() { return _data;  }
};