#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef std::vector<int> Data;
typedef Data::size_type Index;

Index get_left(Index i)
{
    return 2*i + 1;
}

Index get_right(Index i)
{
    return get_left(i) + 1;
}

Index get_parent(Index i)
{
    return (i-1)/2;
    
}

void max_heapify(Data& data, Index idx)
{
    auto max = idx;
    
    auto left = get_left(idx);
    if (left < data.size() && data[left] > data[max])
    {
        max = left;
    }
    
    auto right = get_right(idx);
    if (right < data.size() && data[right] > data[max])
    {
        max = right;
    }
    
    if (max != idx)
    {
        std::swap(data[max], data[idx]);
        max_heapify(data, max);
    }    
}

void min_heapify(Data& data, Index idx)
{
    auto min = idx;
    
    auto left = get_left(idx);
    if (left < data.size() && data[left] < data[min])
    {
        min = left;
    }
    
    auto right = get_right(idx);
    if (right < data.size() && data[right] < data[min])
    {
        min = right;
    }
    
    if (min != idx)
    {
        std::swap(data[min], data[idx]);
        min_heapify(data, min);
    }    
}

std::ostream& operator<<(std::ostream& os, const Data& data)
{
    for (auto & n : data)
    {
        os << n << " ";
    }
    return os;
}

int main()
{
    Data d = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    
    std::cout << "before max-heapify: " << d << std::endl;    
    max_heapify(d, 0);
    std::cout << "after max-heapify : " << d << std::endl;    
    
    for (int i = 0; i < d.size(); ++i)
    {
        min_heapify(d, i);
    }
    std::cout << "after min-heapify : " << d << std::endl;
}