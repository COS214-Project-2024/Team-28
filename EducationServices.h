#ifndef EDUCATIONSERVICES_H
#define EDUCATIONSERVICES_H

#include "Services.h"
#include <string>
#include <vector>

class EducationServices : public Services {
public:
    EducationServices();
    void provideService() override;
    void scheduleClass(const std::string& className);
    void recruitTeacher(const std::string& teacherName);

private:
    std::vector<std::string> classes;
    std::vector<std::string> teachers;
};

#endif // EDUCATIONSERVICES_H