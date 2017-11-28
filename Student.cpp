#include "Student.h"
#include <string>
#include <vector>

Student::Student(std::string fn, std::string ln, int y, Major m){
    _first_name = fn;
    _last_name = ln;
    _grad_year = y;
    _major = m;
    return;
}

Student::~Student(){}

void Student::addGrade(float grade){
    _grades.push_back(grade);
}

float Student::getGpa(){
    float GPA = 0;
    int subjectnum = _grades. size();
    for (int i=0; i<subjectnum; i++) {
        GPA = GPA + _grades[i];
    }
    float average = GPA / subjectnum;
    return average;
}
std::string Student::majorString(Major m){
    std::string stumajor;
    switch(m){
        case Major::EE:
            stumajor = "EE";
            break;
        case Major::ME:
            stumajor = "ME";
            break;
        case Major::CE:
            stumajor = "CE";
            break;
        case Major::CHE:
            stumajor = "CHE";
            break;
        case Major::BSE:
            stumajor = "BSE";
            break;
        case Major::ART:
            stumajor = "ART";
            break;
        case Major::ARCH:
            stumajor = "ARCH";
            break;
        default:
            return "not exist";
    }
    return stumajor;
}


void Student::printInfo(){
    printf("%s, %s\n", _last_name.c_str(), _first_name.c_str() );
    printf("%s %d\n", majorString(_major).c_str(), _grad_year);
    printf("GPA: %.2f\n", Student::getGpa());
}

