#pragma once
#include <string> 

class UniversityMember
{
public:
    virtual void printDetails() = 0;

private: 
    std::string email;
};