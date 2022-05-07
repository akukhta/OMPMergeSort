#pragma once
#include <vector>
#include <omp.h>

#define MAX_THREADING_SIZE 20000

template <class T, class Comp>
std::vector<T> merge(std::vector<T>&& l, std::vector<T>&& r, Comp c)
{

    std::vector<T> res;
    size_t i = 0, j = 0;

    for (; i < l.size() && j < r.size();)
    {
        res.push_back(c(l[i], r[j]) ? l[i++] : r[j++]);
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

template <class T, class Comp = std::less<T>>
std::vector<T> sort(std::vector<T>&& vec, Comp c = Comp())
{
    if (vec.size() < 2)
    {
        return vec;
    }
    else
    {

        std::vector<T> l;
        std::vector<T> r;

        if (vec.size() >= MAX_THREADING_SIZE)
        {

#pragma omp sections
            {
#pragma omp section
                {
                    l = sort(std::vector<T>(vec.begin(), vec.begin() + vec.size() / 2), c);
                }

#pragma omp section
                {
                    r = sort(std::vector<T>(vec.begin() + vec.size() / 2, vec.end()), c);
                }
            }
        }
        else
        {
            l = sort(std::vector<T>(vec.begin(), vec.begin() + vec.size() / 2), c);
            r = sort(std::vector<T>(vec.begin() + vec.size() / 2, vec.end()), c);
        }
        return merge(std::move(l), std::move(r), c);
    }
}