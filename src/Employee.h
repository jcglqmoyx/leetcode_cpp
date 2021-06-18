#ifndef LEETCODE_EMPLOYEE_H
#define LEETCODE_EMPLOYEE_H

#include <vector>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

#endif //LEETCODE_EMPLOYEE_H