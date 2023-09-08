#pragma once

#include "template.h"

class Class1 : public TemplateMethodClass {
    bool check(int i, int j) { return i > j; }
};