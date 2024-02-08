#include "UniversityMembers.h"
#include <iostream>
#include <memory>
#include <vector>

std::unique_ptr<UniversityMember> UM_factory()
{
    // ask for details here using cout / cin

    // use these details to create the appropriate derived class and return
}

int main()
{  
    std::vector<std::unique_ptr<UniversityMember>> universityRoster;
    for(size_t i = 0; i < 3; i++)
    {
        universityRoster.push_back(UM_factory());
    }

    for(auto &p : universityRoster)
    {
        p->printDetails();
    }
}