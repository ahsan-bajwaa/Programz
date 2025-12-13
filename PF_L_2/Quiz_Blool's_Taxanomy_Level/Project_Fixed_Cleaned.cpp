
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int SIZE = 3;
const int MAX_TYPE = 6;
const int INFO_COUNT = 7;
const int MAX_TOPICS = 4;
const int MAX_QUESTIONS = 6;

string question[MAX_TOPICS][MAX_TYPE][MAX_QUESTIONS][INFO_COUNT];
string level_names[3] = {"Easy", "Medium", "Hard"};
string type_names[MAX_TYPE] = {"Remembering", "Understanding", "Applying", "Analyzing", "Evaluating", "Creating"};
string topic_names[MAX_TOPICS] = {"Science", "History", "Geography", "Mathematics"};

int correct_answers[SIZE][MAX_TOPICS][MAX_TYPE] = {0};
int total_attempts[SIZE][MAX_TOPICS][MAX_TYPE] = {0};

class Questions
{
protected:
    int current_level;
    int current_topic;

public:
    void get_info(int level, int topic)
    {
        current_level = level;
        current_topic = topic;
    }

    void selecting_level()
    {
        if (current_level == 0) easy_questions();
        else if (current_level == 1) medium_questions();
        else if (current_level == 2) hard_questions();
    }

protected:
    void easy_questions()
    {
        // Sample only one question to keep short
        question[0][0][0][0] = "What is H2O?";
        question[0][0][0][1] = "Water";
        question[0][0][0][2] = "Water";
        question[0][0][0][3] = "Oxygen";
        question[0][0][0][4] = "Hydrogen";
        question[0][0][0][5] = "Air";
        question[0][0][0][6] = "H2O is the chemical formula for water.";
    }

    void medium_questions()
    {
        question[0][5][0][0] = "Invent a new use for a spoon.";
        question[0][5][0][1] = "Build a catapult";
        question[0][5][0][2] = "Build a catapult";
        question[0][5][0][3] = "Use as a mirror";
        question[0][5][0][4] = "Eat pizza";
        question[0][5][0][5] = "Make music";
        question[0][5][0][6] = "Spoons can be used creatively.";
    }

    void hard_questions()
    {
        // Placeholder
    }
};

void display_result(int current_level, int current_topic)
{
    cout << "--------------------------------------\n";
    cout << "Difficulty: " << level_names[current_level] << "\n";
    cout << "Topic: " << topic_names[current_topic] << "\n";
    cout << "--------------------------------------\n";

    for (int type = 0; type < MAX_TYPE; ++type)
    {
        if (total_attempts[current_level][current_topic][type] > 0)
        {
            cout << "Taxonomy type: " << type_names[type] << "\n";
            cout << "Correct answers: " << correct_answers[current_level][current_topic][type]
                 << " out of " << total_attempts[current_level][current_topic][type] << "\n";
            cout << "--------------------------------------\n";
        }
    }

    cout << "           END OF QUIZ\n";
    cout << "--------------------------------------\n";
}
