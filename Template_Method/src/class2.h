#pragma once

#include "template.h"

class Class2 : public TemplateMethodClass {
    bool check(int i, int j) { return i < j; }
};