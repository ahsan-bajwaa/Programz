#include <iostream>
using namespace std;

class GradeBook
{
private:
    int scores[20][5];
    int studentCount;
    int subjectCount;
public:
    GradeBook() : studentCount(20), subjectCount(5)
    {
        for(int i = 0; i < studentCount; i++)
        {
            for(int j = 0; j < subjectCount; j++)
            {
                scores[i][j] = 0;
            }
        }
    }

    void gradebooks(const GradeBook &gradebook) const
    {
        GradeBook gradebooks_previous;
        for (int i = 0; i < studentCount; i++)
        {
            for (int j = 0; j < subjectCount; j++)
            {
                gradebooks_previous.scores[i][j] += gradebook.scores[i][j];
            }
        }
    }
    
};