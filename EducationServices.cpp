#include "EducationServices.h"
#include <iostream>

EducationServices::EducationServices() : Services("Education", 100) {}

void EducationServices::provideService() {
    std::cout << "Providing education services..." << std::endl;
}

void EducationServices::scheduleClass(const std::string& className) {
    classes.push_back(className);
    std::cout << "Scheduling class: " << className << std::endl;
}

void EducationServices::recruitTeacher(const std::string& teacherName) {
    teachers.push_back(teacherName);
    std::cout << "Recruiting teacher: " << teacherName << std::endl;
}