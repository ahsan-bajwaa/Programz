#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Questions
{
private:
    string Question[30];
    string Answer[30];
    string Option[30][4];
    string Explanation[30];
    int marks = 0;
    int current_question = 0;
    int current_level = 0;
    int max_question = 5;

public:
    Questions()
    {
        // Initialize questions, answers, options, and explanations
        Question[0] = "What is the capital of France?";
        Answer[0] = "Paris";
        Option[0][0] = "Paris";
        Option[0][1] = "London";
        Option[0][2] = "Berlin";
        Option[0][3] = "Madrid";
        Explanation[0] = "Paris is the capital city of France, known for landmarks like the Eiffel Tower.";

        Question[1] = "What is the largest planet in our solar system?";
        Answer[1] = "Jupiter";
        Option[1][0] = "Earth";
        Option[1][1] = "Mars";
        Option[1][2] = "Jupiter";
        Option[1][3] = "Saturn";
        Explanation[1] = "Jupiter is the largest planet, with a diameter of about 139,820 km.";

        Question[2] = "What is the chemical symbol for water?";
        Answer[2] = "H2O";
        Option[2][0] = "H2O";
        Option[2][1] = "CO2";
        Option[2][2] = "O2";
        Option[2][3] = "N2";
        Explanation[2] = "H2O represents water, consisting of two hydrogen atoms and one oxygen atom.";

        Question[3] = "Who wrote the play 'Romeo and Juliet'?";
        Answer[3] = "William Shakespeare";
        Option[3][0] = "Charles Dickens";
        Option[3][1] = "William Shakespeare";
        Option[3][2] = "Jane Austen";
        Option[3][3] = "Mark Twain";
        Explanation[3] = "William Shakespeare wrote the famous tragedy 'Romeo and Juliet' in the 1590s.";

        Question[4] = "What is the boiling point of water at standard pressure?";
        Answer[4] = "100°C";
        Option[4][0] = "0°C";
        Option[4][1] = "50°C";
        Option[4][2] = "100°C";
        Option[4][3] = "150°C";
        Explanation[4] = "Water boils at 100°C at standard atmospheric pressure (1 atm).";

        // Understanding (Level 2: Questions 5–9)
        Question[5] = "Which process explains why the sky appears blue?";
        Answer[5] = "Rayleigh scattering";
        Option[5][0] = "Reflection";
        Option[5][1] = "Refraction";
        Option[5][2] = "Rayleigh scattering";
        Option[5][3] = "Absorption";
        Explanation[5] = "Rayleigh scattering causes shorter blue wavelengths of light to scatter more in the atmosphere.";

        Question[6] = "What is the main purpose of the greenhouse effect?";
        Answer[6] = "Traps heat in the atmosphere";
        Option[6][0] = "Cools the Earth";
        Option[6][1] = "Traps heat in the atmosphere";
        Option[6][2] = "Blocks sunlight";
        Option[6][3] = "Increases wind speed";

        Explanation[6] = "The greenhouse effect traps heat, warming the Earth by retaining infrared radiation.";

        Question[7] = "Why do leaves change color in autumn?";
        Answer[7] = "Chlorophyll breaks down";
        Option[7][0] = "Increased sunlight";
        Option[7][1] = "Chlorophyll breaks down";
        Option[7][2] = "More water absorption";
        Option[7][3] = "Temperature increase";
        Explanation[7] = "Chlorophyll breaks down in autumn, revealing other pigments like red and yellow.";

        Question[8] = "What does the term 'democracy' mean?";
        Answer[8] = "Rule by the people";
        Option[8][0] = "Rule by a king";
        Option[8][1] = "Rule by the military";
        Option[8][2] = "Rule by the people";
        Option[8][3] = "Rule by a single leader";
        Explanation[8] = "Democracy means rule by the people, typically through elected representatives.";

        Question[9] = "What is the primary function of the heart?";
        Answer[9] = "Pumps blood";
        Option[9][0] = "Digests food";
        Option[9][1] = "Pumps blood";
        Option[9][2] = "Filters air";
        Option[9][3] = "Stores energy";
        Explanation[9] = "The heart pumps blood to circulate oxygen and nutrients throughout the body.";

        // Applying (Level 3: Questions 10–14)
        Question[10] = "If a car travels 200 km in 4 hours, what is its average speed?";
        Answer[10] = "50 km/h";
        Option[10][0] = "50 km/h";
        Option[10][1] = "25 km/h";
        Option[10][2] = "100 km/h";
        Option[10][3] = "75 km/h";
        Explanation[10] = "Average speed is distance divided by time: 200 km / 4 h = 50 km/h.";

        Question[11] = "How would you use a thermometer to measure the temperature of a liquid?";
        Answer[11] = "Place it in the liquid without touching the container";
        Option[11][0] = "Hold it above the liquid";
        Option[11][1] = "Place it in the liquid without touching the container";
        Option[11][2] = "Touch it to the container's surface";
        Option[11][3] = "Shake it in the air";
        Explanation[11] = "The thermometer must contact the liquid directly for an accurate reading.";

        Question[12] = "Which tool would you use to measure the volume of a liquid?";
        Answer[12] = "Graduated cylinder";
        Option[12][0] = "Ruler";
        Option[12][1] = "Thermometer";
        Option[12][2] = "Graduated cylinder";
        Option[12][3] = "Balance scale";
        Explanation[12] = "A graduated cylinder is designed to measure the volume of liquids accurately.";

        Question[13] = "If a recipe requires 2 cups of flour for 4 servings, how much flour is needed for 6 servings?";
        Answer[13] = "3 cups";
        Option[13][0] = "2 cups";
        Option[13][1] = "3 cups";
        Option[13][2] = "4 cups";
        Option[13][3] = "5 cups";
        Explanation[13] = "Use a proportion: (2 cups / 4 servings) * 6 servings = 3 cups.";

        Question[14] = "Which equation represents the Pythagorean theorem for a right triangle?";
        Answer[14] = "a² + b² = c²";
        Option[14][0] = "a + b = c";
        Option[14][1] = "a² - b² = c²";
        Option[14][2] = "a² + b² = c²";
        Option[14][3] = "a * b = c";
        Explanation[14] = "The Pythagorean theorem states a² + b² = c² for a right triangle.";

        // Analyzing (Level 4: Questions 15–19)
        Question[15] = "What is the main difference between renewable and non-renewable energy sources?";
        Answer[15] = "Renewable sources can be replenished naturally";
        Option[15][0] = "Renewable sources are more expensive";
        Option[15][1] = "Renewable sources can be replenished naturally";
        Option[15][2] = "Non-renewable sources are cleaner";
        Option[15][3] = "Non-renewable sources are infinite";
        Explanation[15] = "Renewable sources, like solar, can be replenished; non-renewable, like coal, cannot.";

        Question[16] = "Which factor most likely causes a hurricane to form?";
        Answer[16] = "Warm ocean water";
        Option[16][0] = "Cold air masses";
        Option[16][1] = "Warm ocean water";
        Option[16][2] = "High air pressure";
        Option[16][3] = "Low humidity";
        Explanation[16] = "Warm ocean water provides the energy needed for hurricane formation.";

        Question[17] = "Why does a desert have less biodiversity than a rainforest?";
        Answer[17] = "Limited water availability";
        Option[17][0] = "Too much sunlight";
        Option[17][1] = "Limited water availability";
        Option[17][2] = "Excessive rainfall";
        Option[17][3] = "High soil fertility";
        Explanation[17] = "Limited water in deserts restricts the variety of life compared to rainforests.";

        Question[18] = "Which part of a cell is responsible for energy production?";
        Answer[18] = "Mitochondria";
        Option[18][0] = "Nucleus";
        Option[18][1] = "Mitochondria";
        Option[18][2] = "Cell membrane";
        Option[18][3] = "Ribosome";
        Explanation[18] = "Mitochondria produce energy through cellular respiration.";

        Question[19] = "What distinguishes a mammal from a reptile?";
        Answer[19] = "Mammals have hair or fur";
        Option[19][0] = "Mammals lay eggs";
        Option[19][1] = "Mammals have hair or fur";
        Option[19][2] = "Reptiles produce milk";
        Option[19][3] = "Reptiles have warm blood";
        Explanation[19] = "Mammals are characterized by hair or fur and milk production.";

        // Evaluating (Level 5: Questions 20–24)
        Question[20] = "Which energy source is most sustainable for a coastal city?";
        Answer[20] = "Wind power";
        Option[20][0] = "Coal";
        Option[20][1] = "Wind power";
        Option[20][2] = "Oil";
        Option[20][3] = "Natural gas";
        Explanation[20] = "Wind power is sustainable and abundant in coastal areas.";

        Question[21] = "Which historical event had the greatest impact on modern democracy?";
        Answer[21] = "Magna Carta";
        Option[21][0] = "World War II";
        Option[21][1] = "Magna Carta";
        Option[21][2] = "French Revolution";
        Option[21][3] = "Industrial Revolution";
        Explanation[21] = "The Magna Carta laid foundational principles for democratic governance.";

        Question[22] = "Which method is most effective for reducing water pollution?";
        Answer[22] = "Implementing stricter regulations";
        Option[22][0] = "Increasing industrial output";
        Option[22][1] = "Implementing stricter regulations";
        Option[22][2] = "Reducing public awareness";
        Option[22][3] = "Ignoring waste disposal";
        Explanation[22] = "Stricter regulations enforce better waste management to reduce pollution.";

        Question[23] = "Which book best represents themes of social justice?";
        Answer[23] = "To Kill a Mockingbird";
        Option[23][0] = "The Great Gatsby";
        Option[23][1] = "To Kill a Mockingbird";
        Option[23][2] = "Moby-Dick";
        Option[23][3] = "Pride and Prejudice";
        Explanation[23] = "To Kill a Mockingbird addresses racial injustice and equality.";

        Question[24] = "Which strategy is best for conserving endangered species?";
        Answer[24] = "Protecting natural habitats";
        Option[24][0] = "Increasing hunting permits";
        Option[24][1] = "Protecting natural habitats";
        Option[24][2] = "Reducing conservation funding";
        Option[24][3] = "Ignoring population declines";
        Explanation[24] = "Protecting habitats preserves ecosystems for endangered species.";

        // Creating (Level 6: Questions 25–29)
        Question[25] = "Which slogan would best promote recycling in a community?";
        Answer[25] = "Reduce, Reuse, Recycle";
        Option[25][0] = "Buy More, Waste More";
        Option[25][1] = "Reduce, Reuse, Recycle";
        Option[25][2] = "Throw It Away Today";
        Option[25][3] = "Use Once, Then Toss";
        Explanation[25] = "This slogan is concise and promotes sustainable recycling habits.";

        Question[26] = "What is the best title for a campaign to save water?";
        Answer[26] = "Every Drop Counts";
        Option[26][0] = "Waste Water Daily";
        Option[26][1] = "Every Drop Counts";
        Option[26][2] = "Water Is Unlimited"; 
        Option[26][3] = "Ignore the Drip";
        Explanation[26] = "This title emphasizes the importance of conserving every drop of water.";

        Question[27] = "Which design feature would most improve a solar-powered car?";
        Answer[27] = "More efficient solar panels";
        Option[27][0] = "Heavier batteries";
        Option[27][1] = "More efficient solar panels";
        Option[27][2] = "Smaller wheels";
        Option[27][3] = "Darker paint";
        Explanation[27] = "Efficient solar panels maximize energy capture for the car.";

        Question[28] = "Which theme would best suit a poster for environmental awareness?";
        Answer[28] = "Protect Our Planet";
        Option[28][0] = "Increase Pollution";
        Option[28][1] = "Protect Our Planet";
        Option[28][2] = "Cut More Trees";
        Option[28][3] = "Waste Resources";
        Explanation[28] = "This theme inspires action to protect the environment.";

        Question[29] = "What is the best way to organize a community clean-up event?";
        Answer[29] = "Coordinate volunteer groups";
        Option[29][0] = "Cancel the event";
        Option[29][1] = "Coordinate volunteer groups";
        Option[29][2] = "Limit participation";
        Option[29][3] = "Ignore planning";
        Explanation[29] = "Coordinating volunteers ensures an effective clean-up event.";
    }

    // Select the level for the quiz.
    void selecting_level(int level)
    {
        current_level = level;
        current_question = (level - 1) * max_question;
        marks = 0;
    }

    // Validate input.
    bool invalid_choice(string input, int &choice)
    {
        if (input == "") return false;

        // Handle A–D input
        if (input.length() == 1 && toupper(input[0]) >= 'A' && toupper(input[0]) <= 'D')
        {
            choice = toupper(input[0]) - 'A' + 1; // Convert A–D to 1–4
            return true;
    
        } 

        for (int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                return false;
            }
        }
        // Convert string to int
        choice = stoi(input);
        return true;
    }

    // Display the current question
    void display_questions()
    {
        if (current_question >= current_level * max_question)   return;

        cout << "\n=======================================\n";
        cout << "Question " << (current_question % max_question + 1) << " of " << max_question << ":\n";
        cout << Question[current_question] << endl;
        cout << "Options:\n";
        for (int j = 0; j < 4; j++)
        {
            cout << char('A' + j) << ") " << Option[current_question][j] << endl;
        }
        cout << "=======================================\n";
    }

    // Check the user's answer
    void check_answer(int choice)
    {
        cout << "\n---------------------------------------\n";
        if (Option[current_question][choice - 1] == Answer[current_question])
        {
            cout << "Correct! " << Explanation[current_question] << endl;
            marks++;
        }
        else
        {
            cout << "Wrong answer. The correct answer is: " << Answer[current_question] << endl;
            cout << Explanation[current_question] << endl;
        }
        cout << "---------------------------------------\n";
        cout << "Press Enter to continue...";
        cin.ignore(1000, '\n'); // Clear up to 1000 characters or newline
        cin.get();
        current_question++;
    }

    // Show quiz results
    void show_results()
    {
        cout << "\n=======================================\n";
        cout << "Quiz Completed!\n";
        cout << "Level: " << get_level_name(current_level) << endl;
        cout << "You answered " << marks << " out of " << max_question << " questions correctly.\n";
        cout << "Your score: " << (marks * 100) / max_question << "%\n";
        cout << "=======================================\n";
    }

    // Review answers
    void review_answers()
    {
        cout << "\n=======================================\n";
        cout << "Answer Review for " << get_level_name(current_level) << endl;
        cout << "=======================================\n";
        for (int i = (current_level - 1) * max_question; i < current_level * max_question; i++) {
            cout << "Question " << (i % max_question + 1) << ": " << Question[i] << endl;
            cout << "Correct Answer: " << Answer[i] << endl;
            cout << "Explanation: " << Explanation[i] << "\n\n";
        }
        cout << "Press Enter to return to the main menu...";
        cin.get();
        cout << "=======================================\n";
    }

    // Get the name of the current level
    string get_level_name(int level)
    {
        switch (level)
        {
            case 1: return "Remembering";
            case 2: return "Understanding";
            case 3: return "Applying";
            case 4: return "Analyzing";
            case 5: return "Evaluating";
            case 6: return "Creating";
            default: return "Unknown";
        }
    }

    // Check if the quiz is complete
    bool complete_quiz()
    {
        return current_question >= current_level * max_question;
    }
};

int main()
{
    Questions quiz;
    string input;
    int choice;

    while (true)
    {
        // Display welcome menu
        cout << "\n========================================\n";
        cout << "    Welcome to Bloom's Taxonomy Quiz    \n";
        cout << "========================================\n";
        cout << "Select a level:\n";
        cout << "1. Remembering\n2. Understanding\n3. Applying\n";
        cout << "4. Analyzing\n5. Evaluating\n6. Creating\n7. Exit\n";
        cout << "Enter your choice (1-7): ";
        getline(cin, input);

        // Validate level selection
        if (!quiz.invalid_choice(input, choice) || choice < 1 || choice > 7)
        {
            cout << "\nInvalid input! Please enter a number between 1 and 7.\n";
            continue;
        }

        if (choice == 7)
        {
            cout << "\n=======================================\n";
            cout << "Thank you for playing! Goodbye.\n";
            cout << "=======================================\n";
            break;
        }

        // Start quiz for selected level
        quiz.selecting_level(choice);
        cout << "\n=======================================\n";
        cout << "Starting " << quiz.get_level_name(choice) << " Quiz\n";
        cout << "Answer 5 questions to test your knowledge!\n";
        cout << "=======================================\n";
        cout << "Press Enter to begin...";
        cin.get();

        // Quiz loop
        while (!quiz.complete_quiz())
        {
            quiz.display_questions();
            if (quiz.complete_quiz()) break;

            cout << "Enter your answer (A-D) or 0 to exit: ";
            getline(cin, input);

            if (!quiz.invalid_choice(input, choice))
            {
                cout << "\nInvalid input! Please enter A-D or 0.\n";
                continue;
            }

            if (choice == 0)
            {
                cout << "\nExiting quiz early.\n";
                break;
            }

            if (choice < 1 || choice > 4)
            {
                cout << "\nInvalid choice! Please enter A-D.\n";
                continue;
            }

            quiz.check_answer(choice);
        }

        // Show results and options
        quiz.show_results();
        cout << "\nOptions:\n";
        cout << "1. Try another level\n";
        cout << "2. Review answers\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        getline(cin, input);

        if (!quiz.invalid_choice(input, choice) || choice < 1 || choice > 3)
        {
            cout << "\nInvalid input! Please enter a number between 1 and 3.\n";
            continue;
        }

        if (choice == 2) {
            quiz.review_answers();
        } else if (choice == 3)
        {
            cout << "\n=======================================\n";
            cout << "Thank you for playing! Goodbye.\n";
            cout << "=======================================\n";
            break;
        }
    }

    return 0;
}