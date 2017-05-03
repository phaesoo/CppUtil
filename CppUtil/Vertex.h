#pragma once

template <typename T>
class Vertex
{
    T _data;
public:
    Vertex(T data)
    {
        _data = data;
    }

public:
    bool operator==(const Vertex<T>& rhs)
    {
        return this->_data == rhs._data;
    }
};