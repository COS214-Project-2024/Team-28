// EducationServices.h
#ifndef EDUCATIONSERVICES_H
#define EDUCATIONSERVICES_H

#include "Services.h"
#include <string>
#include <vector>

/**
 * @class EducationServices
 * @brief Class to manage educational services.
 *
 * The EducationServices class provides functionalities related to
 * managing educational services, including scheduling classes and
 * recruiting teachers.
 */
class EducationServices : public Services {
public:
    /**
     * @brief Default constructor for EducationServices.
     */
    EducationServices();

    /**
     * @brief Provides educational services.
     *
     * This method overrides the provideService method from the
     * Services base class, implementing the logic for providing
     * educational services.
     */
    void provideService() override;

    /**
     * @brief Schedules a new class.
     *
     * @param className The name of the class to be scheduled.
     */
    void scheduleClass(const std::string& className);

    /**
     * @brief Recruits a new teacher.
     *
     * @param teacherName The name of the teacher to be recruited.
     */
    void recruitTeacher(const std::string& teacherName);

private:
    std::vector<std::string> classes;  ///< List of scheduled classes.
    std::vector<std::string> teachers; ///< List of recruited teachers.
};

#endif // EDUCATIONSERVICES_H
