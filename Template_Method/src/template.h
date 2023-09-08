#pragma once

#include <vector>

class TemplateMethodClass {
public:
    void templateMethod (std::vector<int>& arr);
    virtual bool check(int i, int j) = 0;
};

void TemplateMethodClass::templateMethod(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (check(arr[j], arr[j + 1])) {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    return;
}