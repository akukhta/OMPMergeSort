#pragma once
#include "merge.h"

template <class T>
std::vector<T> merge(std::vector<T>&& l, std::vector<T>&& r)
{

    std::vector<T> res;
    size_t i = 0, j = 0;

    for (; i < l.size() && j < r.size();)
    {
        res.push_back(l[i] < r[j] ? l[i++] : r[j++]);
    }

    while (i < l.size())
    {
        res.push_back(l[i++]);
    }

    while (j < r.size())
    {
        res.push_back(r[j++]);
    }

    return res;
}

template <class T>
std::vector<T> sort(std::vector<T>& vec)
{
    if (vec.size() < 2)
    {
        return vec;
    }
    else
    {
        auto l = std::vector<T>(vec.begin(), vec.begin() + vec.size() / 2);
        auto r = std::vector<T>(vec.begin() + vec.size() / 2, vec.end());
        return merge(sort(l), sort(r));
    }
}