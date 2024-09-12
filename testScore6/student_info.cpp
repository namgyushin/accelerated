#include <stdexcept>
#include "student_info.h"
#include "median.h"

static istream& read_hw(istream& in, vector<double>& homeworks)
{
    if (in)
    {
        homeworks.clear();

        double homework;
        while (in >> homework)
        {
            homeworks.push_back(homework);
        }

        in.clear();
    }
    return in;
}

istream& read(istream& in, Student_info& s)
{
    in >> s.name >> s.midterm >> s.finalterm;

    if (in)
    {
        vector<double> homeworks;
        read_hw(in, homeworks);

        if (homeworks.size() == 0)
        {
            throw domain_error("no homework");
        }

        s.homework = median(homeworks);
    }
    return in;
}