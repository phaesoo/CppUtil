#pragma once

#include <string>
#include <vector>

class CSVFileUtil
{
public:
    template <typename T>
    using vector2D = std::vector< std::vector<T> >;

public:
    CSVFileUtil() = delete;

    static bool ReadFile(const std::string& filepath, vector2D<std::string>& dataList);
    static bool WriteFile(const std::string& filepath, const vector2D<std::string>& dataList);

public:
    static const char g_token = ',';
};
