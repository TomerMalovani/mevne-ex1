#include "myList.h"
#include <vector>

class List {
public:
    void add(int element) {
        vec.push_back(element);
    }

    void remove(int index) {
        vec.erase(vec.begin() + index);
    }

    int operator[](int index) {
        return vec[index];
    }

private:
    std::vector<int> vec;
};