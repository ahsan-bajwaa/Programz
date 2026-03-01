#include <iostream>
#include <string>
#include <cctype> // for isdigit()

using namespace std;

class Questions
{
private:
    // Declear variables.
    string Question[3];
    string Answer[3];
    string Option[3][4];
    int marks = 0;
    int currentQuestion;

public:
    Questions() 
    {
        // Remembering (Level 1: Questions 0–4)
        Question[0] = "What is the capital of France?";
        Answer[0] = "Paris";
        Option[0][0] = "Paris";
        Option[0][1] = "London";
        Option[0][2] = "Berlin";
        Option[0][3] = "Madrid";

        Question[1] = "What is the largest planet in our solar system?";
        Answer[1] = "Jupiter";
        Option[1][0] = "Earth";
        Option[1][1] = "Mars";
        Option[1][2] = "Jupiter";
        Option[1][3] = "Saturn";

        Question[2] = "What is the chemical symbol for water?";
        Answer[2] = "H2O";
        Option[2][0] = "H2O";
        Option[2][1] = "CO2";
        Option[2][2] = "O2";
        Option[2][3] = "N2";

        Question[3] = "Who wrote the play 'Romeo and Juliet'?";
        Answer[3] = "William Shakespeare";
        Option[3][0] = "Charles Dickens";
        Option[3][1] = "William Shakespeare";
        Option[3][2] = "Jane Austen";
        Option[3][3] = "Mark Twain";

        Question[4] = "What is the boiling point of water at standard pressure?";
        Answer[4] = "100°C";
        Option[4][0] = "0°C";
        Option[4][1] = "50°C";
        Option[4][2] = "100°C";
        Option[4][3] = "150°C";

        // Understanding (Level 2: Questions 5–9)
        Question[5] = "Which process explains why the sky appears blue?";
        Answer[5] = "Rayleigh scattering";
        Option[5][0] = "Reflection";
        Option[5][1] = "Refraction";
        Option[5][2] = "Rayleigh scattering";
        Option[5][3] = "Absorption";

        Question[6] = "What is the main purpose of the greenhouse effect?";
        Answer[6] = "Traps heat in the atmosphere";
        Option[6][0] = "Cools the Earth";
        Option[6][1] = "Traps heat in the atmosphere";
        Option[6][2] = "Blocks sunlight";
        Option[6][3] = "Increases wind speed";

        Question[7] = "Why do leaves change color in autumn?";
        Answer[7] = "Chlorophyll breaks down";
        Option[7][0] = "Increased sunlight";
        Option[7][1] = "Chlorophyll breaks down";
        Option[7][2] = "More water absorption";
        Option[7][3] = "Temperature increase";

        Question[8] = "What does the term 'democracy' mean?";
        Answer[8] = "Rule by the people";
        Option[8][0] = "Rule by a king";
        Option[8][1] = "Rule by the military";
        Option[8][2] = "Rule by the people";
        Option[8][3] = "Rule by a single leader";

        Question[9] = "What is the primary function of the heart?";
        Answer[9] = "Pumps blood";
        Option[9][0] = "Digests food";
        Option[9][1] = "Pumps blood";
        Option[9][2] = "Filters air";
        Option[9][3] = "Stores energy";

        // Applying (Level 3: Questions 10–14)
        Question[10] = "If a car travels 200 km in 4 hours, what is its average speed?";
        Answer[10] = "50 km/h";
        Option[10][0] = "50 km/h";
        Option[10][1] = "25 km/h";
        Option[10][2] = "100 km/h";
        Option[10][3] = "75 km/h";

        Question[11] = "How would you use a thermometer to measure the temperature of a liquid?";
        Answer[11] = "Place it in the liquid without touching the container";
        Option[11][0] = "Hold it above the liquid";
        Option[11][1] = "Place it in the liquid without touching the container";
        Option[11][2] = "Touch it to the container's surface";
        Option[11][3] = "Shake it in the air";

        Question[12] = "Which tool would you use to measure the volume of a liquid?";
        Answer[12] = "Graduated cylinder";
        Option[12][0] = "Ruler";
        Option[12][1] = "Thermometer";
        Option[12][2] = "Graduated cylinder";
        Option[12][3] = "Balance scale";

        Question[13] = "If a recipe requires 2 cups of flour for 4 servings, how much flour is needed for 6 servings?";
        Answer[13] = "3 cups";
        Option[13][0] = "2 cups";
        Option[13][1] = "3 cups";
        Option[13][2] = "4 cups";
        Option[13][3] = "5 cups";

        Question[14] = "Which equation represents the Pythagorean theorem for a right triangle?";
        Answer[14] = "a² + b² = c²";
        Option[14][0] = "a + b = c";
        Option[14][1] = "a² - b² = c²";
        Option[14][2] = "a² + b² = c²";
        Option[14][3] = "a * b = c";

        // Analyzing (Level 4: Questions 15–19)
        Question[15] = "What is the main difference between renewable and non-renewable energy sources?";
        Answer[15] = "Renewable sources can be replenished naturally";
        Option[15][0] = "Renewable sources are more expensive";
        Option[15][1] = "Renewable sources can be replenished naturally";
        Option[15][2] = "Non-renewable sources are cleaner";
        Option[15][3] = "Non-renewable sources are infinite";

        Question[16] = "Which factor most likely causes a hurricane to form?";
        Answer[16] = "Warm ocean water";
        Option[16][0] = "Cold air masses";
        Option[16][1] = "Warm ocean water";
        Option[16][2] = "High air pressure";
        Option[16][3] = "Low humidity";

        Question[17] = "Why does a desert have less biodiversity than a rainforest?";
        Answer[17] = "Limited water availability";
        Option[17][0] = "Too much sunlight";
        Option[17][1] = "Limited water availability";
        Option[17][2] = "Excessive rainfall";
        Option[17][3] = "High soil fertility";

        Question[18] = "Which part of a cell is responsible for energy production?";
        Answer[18] = "Mitochondria";
        Option[18][0] = "Nucleus";
        Option[18][1] = "Mitochondria";
        Option[18][2] = "Cell membrane";
        Option[18][3] = "Ribosome";

        Question[19] = "What distinguishes a mammal from a reptile?";
        Answer[19] = "Mammals have hair or fur";
        Option[19][0] = "Mammals lay eggs";
        Option[19][1] = "Mammals have hair or fur";
        Option[19][2] = "Reptiles produce milk";
        Option[19][3] = "Reptiles have warm blood";

        // Evaluating (Level 5: Questions 20–24)
        Question[20] = "Which energy source is most sustainable for a coastal city?";
        Answer[20] = "Wind power";
        Option[20][0] = "Coal";
        Option[20][1] = "Wind power";
        Option[20][2] = "Oil";
        Option[20][3] = "Natural gas";

        Question[21] = "Which historical event had the greatest impact on modern democracy?";
        Answer[21] = "Magna Carta";
        Option[21][0] = "World War II";
        Option[21][1] = "Magna Carta";
        Option[21][2] = "French Revolution";
        Option[21][3] = "Industrial Revolution";

        Question[22] = "Which method is most effective for reducing water pollution?";
        Answer[22] = "Implementing stricter regulations";
        Option[22][0] = "Increasing industrial output";
        Option[22][1] = "Implementing stricter regulations";
        Option[22][2] = "Reducing public awareness";
        Option[22][3] = "Ignoring waste disposal";

        Question[23] = "Which book best represents themes of social justice?";
        Answer[23] = "To Kill a Mockingbird";
        Option[23][0] = "The Great Gatsby";
        Option[23][1] = "To Kill a Mockingbird";
        Option[23][2] = "Moby-Dick";
        Option[23][3] = "Pride and Prejudice";

        Question[24] = "Which strategy is best for conserving endangered species?";
        Answer[24] = "Protecting natural habitats";
        Option[24][0] = "Increasing hunting permits";
        Option[24][1] = "Protecting natural habitats";
        Option[24][2] = "Reducing conservation funding";
        Option[24][3] = "Ignoring population declines";

        // Creating (Level 6: Questions 25–29)
        Question[25] = "Which slogan would best promote recycling in a community?";
        Answer[25] = "Reduce, Reuse, Recycle";
        Option[25][0] = "Buy More, Waste More";
        Option[25][1] = "Reduce, Reuse, Recycle";
        Option[25][2] = "Throw It Away Today";
        Option[25][3] = "Use Once, Then Toss";

        Question[26] = "What is the best title for a campaign to save water?";
        Answer[26] = "Every Drop Counts";
        Option[26][0] = "Waste Water Daily";
        Option[26][1] = "Every Drop Counts";
        Option[26][2] = "Water Is Unlimited";
        Option[26][3] = "Ignore the Drip";

        Question[27] = "Which design feature would most improve a solar-powered car?";
        Answer[27] = "More efficient solar panels";
        Option[27][0] = "Heavier batteries";
        Option[27][1] = "More efficient solar panels";
        Option[27][2] = "Smaller wheels";
        Option[27][3] = "Darker paint";

        Question[28] = "Which theme would best suit a poster for environmental awareness?";
        Answer[28] = "Protect Our Planet";
        Option[28][0] = "Increase Pollution";
        Option[28][1] = "Protect Our Planet";
        Option[28][2] = "Cut More Trees";
        Option[28][3] = "Waste Resources";

        Question[29] = "What is the best way to organize a community clean-up event?";
        Answer[29] = "Coordinate volunteer groups";
        Option[29][0] = "Cancel the event";
        Option[29][1] = "Coordinate volunteer groups";
        Option[29][2] = "Limit participation";
        Option[29][3] = "Ignore planning";
    }

    void selecting_level(int level)
    {
        currentQuestion = (level - 1) * 5; 
    }

    // Function to check if a string is a number
    bool invalid_choice(string input, int &choice)
    {
    if (input == "") return false;

    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    // Convert string to int
    choice = stoi(input);
    return true;
    }

    // Display the current question
    void displayQuestions()
    {
        if (currentQuestion >= 5)
        {
            cout << "No more questions!" << endl;
            return;
        }
        
        cout << "Question " << currentQuestion + 1 << ": " << Question[currentQuestion] << endl;
        cout << "Options: " << endl;
        
        for (int j = 0; j <= 4; j++)
        {
            cout << j + 1 << ". " << Option[currentQuestion][j] << endl;
        }
    }

    // Check the answer
    void checkAnswer(int choice)
    {
        if (Option[currentQuestion][choice - 1] == Answer[currentQuestion])
        {
            cout << "Correct answer!" << endl;
            marks++;
        }
        else
        {
            cout << "Wrong answer. The correct answer is: " << Answer[currentQuestion] << endl;
        }
        currentQuestion++; // Move to next question
    }

    // Show the results
    void show_results()
    {
        cout << "You answered " << marks << " questions correctly." << endl;
        cout << "Your total percentage is: " << (marks * 100) / 3 << "%" << endl;
    }
};

int main()
{
    Questions quiz;
    int choice;
    string  input;
    while(true)
    {
        cout << "Welcome to the Quiz!" << endl;
        cout << "--------------------------------\n";
        cout << "Select Bloom's Taxonomy level:\n";
        cout << "1. Remembering\n2. Understanding\n3. Applying\n";
        cout << "4. Analyzing\n 5. Evaluating\n 6. Creating\n";
        cout << "7. Exit!";
        cout << "Enter your choice (1-7): ";
        cin >> input;

        // Validate choice.
        if (quiz.invalid_choice(input, choice))
        {
            // Check if the choice is within the valid range
            if (choice < 0 || choice >= 8)
            {
                cout << "Invalid choice! Please enter a number between 1 and 7." << endl;
                continue; // Prompt again
            }
            if (choice == 7)
            {
                choice = 0; // Exit option
            }
        }

        // Exit condition.
        if (choice == 0)
        {
            cout << "Exiting the quiz. Thank you for playing!" << endl;
            break;
        }

        //Selecting Level.
        quiz.selecting_level(choice);
        
        while (true)
        {
            // Display the questions.
            quiz.displayQuestions();
            
            cout << "Enter your choice (1-4) or 0 to exit: ";
            cin >> input;

            // Validate choice.
            if (quiz.invalid_choice(input, choice))
            {
                if (choice == 0)
                {
                    cout << "Exiting the quiz." << endl;
                    break; // Exit the inner loop
                }
                if (choice < 1 || choice > 4)
                {
                    cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
                    continue; // Prompt again
                }
            }

            // Check answer.
            quiz.checkAnswer(choice);
        }


            // Show results.
            quiz.show_results();
    }

        return 0;
}