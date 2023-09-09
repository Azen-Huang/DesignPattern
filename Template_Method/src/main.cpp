#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <sstream>

#include "template.h"
#include "class1.h"
#include "class2.h"
using namespace std;
/*
// run code //
make
./main
// run code //
*/

int main() {
    vector<int> arr = {2, 3, 4, 5, 6, 7, 1, 2};
    TemplateMethodClass* method = new Class2();
    method->templateMethod(arr);
    for_each(arr.begin(), arr.end(), [](int x) { cout << x << ", "; });
}