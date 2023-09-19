#pragma once
// assume the following API, which is not under our control

#include <vector>
#include <stdexcept>

class Frobulator
{
public:
    Frobulator(int x, int y) : x_(x), y_(y) {}

    std::vector<double> compute(const std::vector<double> &data) const
    {
        if (data.size() < 10)
        {
            throw std::runtime_error("not enough data");
        }
        // do something with data
        std::vector<double> result;
        result.reserve(data.size());
        for (int i = 0; i < data.size(); ++i)
        {
            result[i] = i * i * data[i] + x_ + y_ * i;
        }
        return result;
    }

private:
    int x_;
    int y_;
};
