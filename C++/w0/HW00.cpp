#include <iostream>

using namespace std;

class Employee
{

private: // Private attribute
    int salary;

public:
    // Setter
    void setSalary(int s)
    {
        /*
         WRITE YOUR CODE HERE
         */
        salary = s;
    }

    // Getter
    int getSalary()
    {
        /*
         WRITE YOUR CODE HERE
         */
        return salary;
    }
};