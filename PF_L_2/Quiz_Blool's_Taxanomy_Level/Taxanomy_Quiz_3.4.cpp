#include <iostream>
#include <ctime> // To get custom random numbers.
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

class Questions
{
protected:
    int current_level;
    int current_topic;

public:
    void get_info(int level, int topic)
    {
        // Set the current level and topic based on user input.
        current_level = level;
        current_topic = topic;
    }

    void selecting_level()
    {
        // Selecting the desired level of questions.
        if (current_level == 0)
            easy_questions();
        else if (current_level == 1)
            medium_questions();
        else if (current_level == 2)
            hard_questions();
    }

protected:
    void easy_questions()
    {
        // Initialize easy questions, answers, options, and explanations.

        // Science - Taxonomy Level 1: Remembering (Easy)
        question[0][0][0][0] = "What is the chemical symbol for water?";
        question[0][0][0][1] = "H2O";
        question[0][0][0][2] = "CO2";
        question[0][0][0][3] = "O2";
        question[0][0][0][4] = "N2";
        question[0][0][0][5] = "H2O";
        question[0][0][0][6] = "Water is a compound made of hydrogen and oxygen.";
        question[0][0][1][0] = "What is the main source of energy for Earth?";
        question[0][0][1][1] = "The Sun";
        question[0][0][1][2] = "The Sun";
        question[0][0][1][3] = "Wind";
        question[0][0][1][4] = "Water";
        question[0][0][1][5] = "The Moon";
        question[0][0][1][6] = "The Sun provides heat and light to Earth.";
        question[0][0][2][0] = "What gas do humans breathe to survive?";
        question[0][0][2][1] = "Oxygen";
        question[0][0][2][2] = "Nitrogen";
        question[0][0][2][3] = "Oxygen";
        question[0][0][2][4] = "Carbon dioxide";
        question[0][0][2][5] = "Helium";
        question[0][0][2][6] = "Oxygen is essential for human respiration.";
        question[0][0][3][0] = "What is the unit of force in physics?";
        question[0][0][3][1] = "Newton";
        question[0][0][3][2] = "Watt";
        question[0][0][3][3] = "Joule";
        question[0][0][3][4] = "Newton";
        question[0][0][3][5] = "Volt";
        question[0][0][3][6] = "Named after Sir Isaac Newton, it measures force.";
        question[0][0][4][0] = "What is the freezing point of water in Celsius?";
        question[0][0][4][1] = "0 degrees";
        question[0][0][4][2] = "0 degrees";
        question[0][0][4][3] = "-10 degrees";
        question[0][0][4][4] = "100 degrees";
        question[0][0][4][5] = "50 degrees";
        question[0][0][4][6] = "Water turns to ice at this temperature.";
        question[0][0][5][0] = "What is the name of our planet?";
        question[0][0][5][1] = "Earth";
        question[0][0][5][2] = "Jupiter";
        question[0][0][5][3] = "Mars";
        question[0][0][5][4] = "Earth";
        question[0][0][5][5] = "Venus";
        question[0][0][5][6] = "Our planet is the third from the Sun.";

        // Science - Taxonomy Level 2: Understanding (Easy)
        question[0][1][0][0] = "Why does ice float on water?";
        question[0][1][0][1] = "Ice is less dense than water";
        question[0][1][0][2] = "Ice is heavier";
        question[0][1][0][3] = "Ice is less dense than water";
        question[0][1][0][4] = "Ice has salt";
        question[0][1][0][5] = "Ice is warmer";
        question[0][1][0][6] = "Lower density makes ice buoyant.";
        question[0][1][1][0] = "What happens to water when it boils?";
        question[0][1][1][1] = "It turns into steam";
        question[0][1][1][2] = "It freezes";
        question[0][1][1][3] = "It shrinks";
        question[0][1][1][4] = "It stays liquid";
        question[0][1][1][5] = "It turns into steam";
        question[0][1][1][6] = "Boiling changes water to a gas.";
        question[0][1][2][0] = "Why do plants need sunlight?";
        question[0][1][2][1] = "To make food through photosynthesis";
        question[0][1][2][2] = "To attract insects";
        question[0][1][2][3] = "To make food through photosynthesis";
        question[0][1][2][4] = "To stay warm";
        question[0][1][2][5] = "To grow roots";
        question[0][1][2][6] = "Sunlight powers food production in plants.";
        question[0][1][3][0] = "What does a thermometer measure?";
        question[0][1][3][1] = "Temperature";
        question[0][1][3][2] = "Temperature";
        question[0][1][3][3] = "Weight";
        question[0][1][3][4] = "Length";
        question[0][1][3][5] = "Volume";
        question[0][1][3][6] = "It shows how hot or cold something is.";
        question[0][1][4][0] = "Why is the sky blue?";
        question[0][1][4][1] = "Light scatters in the atmosphere";
        question[0][1][4][2] = "The Sun is blue";
        question[0][1][4][3] = "Clouds are blue";
        question[0][1][4][4] = "Light scatters in the atmosphere";
        question[0][1][4][5] = "The sky reflects the ocean";
        question[0][1][4][6] = "Blue light scatters more than other colors.";
        question[0][1][5][0] = "What does gravity do?";
        question[0][1][5][1] = "Pulls objects toward each other";
        question[0][1][5][2] = "Pushes objects apart";
        question[0][1][5][3] = "Heats objects up";
        question[0][1][5][4] = "Pulls objects toward each other";
        question[0][1][5][5] = "Stops objects moving";
        question[0][1][5][6] = "Gravity keeps us on the ground.";

        // Science - Taxonomy Level 3: Applying (Easy)
        question[0][2][0][0] = "If you mix red and blue light, what color do you get?";
        question[0][2][0][1] = "Purple";
        question[0][2][0][2] = "Purple";
        question[0][2][0][3] = "Yellow";
        question[0][2][0][4] = "White";
        question[0][2][0][5] = "Green";
        question[0][2][0][6] = "Light colors combine differently than paint.";
        question[0][2][1][0] = "If a plant is kept in the dark, what happens?";
        question[0][2][1][1] = "It stops growing";
        question[0][2][1][2] = "It produces fruit";
        question[0][2][1][3] = "It grows faster";
        question[0][2][1][4] = "It stops growing";
        question[0][2][1][5] = "It turns red";
        question[0][2][1][6] = "Plants need light for photosynthesis.";
        question[0][2][2][0] = "If you drop a ball, what will happen?";
        question[0][2][2][1] = "It will fall";
        question[0][2][2][2] = "It will fly";
        question[0][2][2][3] = "It will float";
        question[0][2][2][4] = "It will stop";
        question[0][2][2][5] = "It will fall";
        question[0][2][2][6] = "Gravity pulls objects downward.";
        question[0][2][3][0] = "If water is heated to 100°C, what happens?";
        question[0][2][3][1] = "It boils";
        question[0][2][3][2] = "It boils";
        question[0][2][3][3] = "It freezes";
        question[0][2][3][4] = "It stays the same";
        question[0][2][3][5] = "It cools";
        question[0][2][3][6] = "Water turns to steam at its boiling point.";
        question[0][2][4][0] = "If you use a magnifying glass in sunlight, what can happen?";
        question[0][2][4][1] = "It can start a fire";
        question[0][2][4][2] = "It creates water";
        question[0][2][4][3] = "It can start a fire";
        question[0][2][4][4] = "It stops light";
        question[0][2][4][5] = "It cools objects";
        question[0][2][4][6] = "The glass focuses sunlight to a point.";
        question[0][2][5][0] = "If you push a toy car, what will it do?";
        question[0][2][5][1] = "Move forward";
        question[0][2][5][2] = "Move forward";
        question[0][2][5][3] = "Stay still";
        question[0][2][5][4] = "Fly upward";
        question[0][2][5][5] = "Move backward";
        question[0][2][5][6] = "A push applies force to the car.";

        // Science - Taxonomy Level 4: Analyzing (Easy)
        question[0][3][0][0] = "What is the difference between a solid and a liquid?";
        question[0][3][0][1] = "Solids have a fixed shape, liquids do not";
        question[0][3][0][2] = "Solids are invisible";
        question[0][3][0][3] = "Liquids are heavier";
        question[0][3][0][4] = "Solids have a fixed shape, liquids do not";
        question[0][3][0][5] = "Liquids are solid";
        question[0][3][0][6] = "Solids keep their shape, liquids flow.";
        question[0][3][1][0] = "What makes day and night different?";
        question[0][3][1][1] = "Earth's rotation";
        question[0][3][1][2] = "Earth's rotation";
        question[0][3][1][3] = "Cloud cover";
        question[0][3][1][4] = "Wind speed";
        question[0][3][1][5] = "The Moon's orbit";
        question[0][3][1][6] = "Earth turns to face or away from the Sun.";
        question[0][3][2][0] = "How is a star different from a planet?";
        question[0][3][2][1] = "Stars produce light, planets reflect it";
        question[0][3][2][2] = "Planets are hotter";
        question[0][3][2][3] = "Stars produce light, planets reflect it";
        question[0][3][2][4] = "Stars are smaller";
        question[0][3][2][5] = "Planets produce light";
        question[0][3][2][6] = "Stars shine, planets do not.";
        question[0][3][3][0] = "What is the difference between a push and a pull?";
        question[0][3][3][1] = "Push moves away, pull moves closer";
        question[0][3][3][2] = "Both are the same";
        question[0][3][3][3] = "Push stops motion";
        question[0][3][3][4] = "Push moves away, pull moves closer";
        question[0][3][3][5] = "Pull makes things heavier";
        question[0][3][3][6] = "Push and pull are levels of force.";
        question[0][3][4][0] = "How is rain different from snow?";
        question[0][3][4][1] = "Rain is liquid, snow is solid";
        question[0][3][4][2] = "Rain is liquid, snow is solid";
        question[0][3][4][3] = "Snow is warmer";
        question[0][3][4][4] = "Both are the same";
        question[0][3][4][5] = "Rain is frozen";
        question[0][3][4][6] = "Temperature affects water's form.";
        question[0][3][5][0] = "What makes a shadow different from a reflection?";
        question[0][3][5][1] = "Shadows block light, reflections bounce light";
        question[0][3][5][2] = "Shadows are brighter";
        question[0][3][5][3] = "Reflections are darker";
        question[0][3][5][4] = "Both are the same";
        question[0][3][5][5] = "Shadows block light, reflections bounce light";
        question[0][3][5][6] = "Shadows form when light is blocked.";

        // Science - Taxonomy Level 5: Evaluating (Easy)
        question[0][4][0][0] = "Which is the best way to save water at home?";
        question[0][4][0][1] = "Turn off the tap when brushing teeth";
        question[0][4][0][2] = "Turn off the tap when brushing teeth";
        question[0][4][0][3] = "Fill a bucket";
        question[0][4][0][4] = "Use more water";
        question[0][4][0][5] = "Leave the tap running";
        question[0][4][0][6] = "Small actions reduce water waste.";
        question[0][4][1][0] = "Which is the safest way to observe the Sun?";
        question[0][4][1][1] = "Use special solar glasses";
        question[0][4][1][2] = "Use a mirror";
        question[0][4][1][3] = "Look directly at it";
        question[0][4][1][4] = "Use special solar glasses";
        question[0][4][1][5] = "Close your eyes";
        question[0][4][1][6] = "Protect your eyes from bright sunlight.";
        question[0][4][2][0] = "Which is the best way to keep food fresh?";
        question[0][4][2][1] = "Store it in a refrigerator";
        question[0][4][2][2] = "Leave it outside";
        question[0][4][2][3] = "Store it in a refrigerator";
        question[0][4][2][4] = "Heat it up";
        question[0][4][2][5] = "Put it in sunlight";
        question[0][4][2][6] = "Cold slows down food spoilage.";
        question[0][4][3][0] = "Which is the best way to stay warm in winter?";
        question[0][4][3][1] = "Wear layers of clothing";
        question[0][4][3][2] = "Stay outside longer";
        question[0][4][3][3] = "Wear layers of clothing";
        question[0][4][3][4] = "Drink cold water";
        question[0][4][3][5] = "Wear thin clothes";
        question[0][4][3][6] = "Layers trap body heat.";
        question[0][4][4][0] = "Which is the best way to clean a spill?";
        question[0][4][4][1] = "Use a cloth or sponge";
        question[0][4][4][2] = "Add more liquid";
        question[0][4][4][3] = "Leave it to dry";
        question[0][4][4][4] = "Use a cloth or sponge";
        question[0][4][4][5] = "Ignore it";
        question[0][4][4][6] = "A cloth absorbs the spill.";
        question[0][4][5][0] = "Which is the best way to see in the dark?";
        question[0][4][5][1] = "Use a flashlight";
        question[0][4][5][2] = "Shout loudly";
        question[0][4][5][3] = "Use a flashlight";
        question[0][4][5][4] = "Wave your hands";
        question[0][4][5][5] = "Close your eyes";
        question[0][4][5][6] = "Light helps you see at night.";

        // Science - Taxonomy Level 6: Creating (Easy)
        question[0][5][0][0] = "Design a simple model of the solar system.";
        question[0][5][0][1] = "Use balls to represent planets";
        question[0][5][0][2] = "Use balls to represent planets";
        question[0][5][0][3] = "Use only paper";
        question[0][5][0][4] = "Draw a square";
        question[0][5][0][5] = "Write a story";
        question[0][5][0][6] = "A model shows planet positions.";
        question[0][5][1][0] = "Create a poster about saving water.";
        question[0][5][1][1] = "Show ways to reduce water use";
        question[0][5][1][2] = "Draw a car";
        question[0][5][1][3] = "Show ways to reduce water use";
        question[0][5][1][4] = "Write a song";
        question[0][5][1][5] = "List food recipes";
        question[0][5][1][6] = "A poster teaches conservation.";
        question[0][5][2][0] = "Plan a garden for a school.";
        question[0][5][2][1] = "Choose plants that need less water";
        question[0][5][2][2] = "Add a playground";
        question[0][5][2][3] = "Build a fountain";
        question[0][5][2][4] = "Choose plants that need less water";
        question[0][5][2][5] = "Pave the area";
        question[0][5][2][6] = "Gardens support local plants.";
        question[0][5][3][0] = "Design a toy that uses wind power.";
        question[0][5][3][1] = "Make a simple windmill";
        question[0][5][3][2] = "Use glue";
        question[0][5][3][3] = "Add water";
        question[0][5][3][4] = "Make a simple windmill";
        question[0][5][3][5] = "Use batteries";
        question[0][5][3][6] = "Wind can move objects.";
        question[0][5][4][0] = "Create a chart of animal habitats.";
        question[0][5][4][1] = "Show animals and their homes";
        question[0][5][4][2] = "Show animals and their homes";
        question[0][5][4][3] = "Draw shapes";
        question[0][5][4][4] = "List only colors";
        question[0][5][4][5] = "Write numbers";
        question[0][5][4][6] = "Habitats show where animals live.";
        question[0][5][5][0] = "Plan a recycling project for home.";
        question[0][5][5][1] = "Sort paper, plastic, and glass";
        question[0][5][5][2] = "Throw everything away";
        question[0][5][5][3] = "Sort paper, plastic, and glass";
        question[0][5][5][4] = "Mix all waste";
        question[0][5][5][5] = "Burn trash";
        question[0][5][5][6] = "Recycling reduces waste.";

        // History - Taxonomy Level 1: Remembering (Easy)
        question[1][0][0][0] = "Who was the first president of the United States?";
        question[1][0][0][1] = "George Washington";
        question[1][0][0][2] = "Thomas Jefferson";
        question[1][0][0][3] = "George Washington";
        question[1][0][0][4] = "John Adams";
        question[1][0][0][5] = "Abraham Lincoln";
        question[1][0][0][6] = "He led the country from 1789 to 1797.";
        question[1][0][1][0] = "In which year did Christopher Columbus sail to America?";
        question[1][0][1][1] = "1492";
        question[1][0][1][2] = "1620";
        question[1][0][1][3] = "1776";
        question[1][0][1][4] = "1492";
        question[1][0][1][5] = "1812";
        question[1][0][1][6] = "He sailed across the Atlantic Ocean.";
        question[1][0][2][0] = "What was the name of the ship that carried the Pilgrims to America?";
        question[1][0][2][1] = "Mayflower";
        question[1][0][2][2] = "Mayflower";
        question[1][0][2][3] = "Santa Maria";
        question[1][0][2][4] = "Pinta";
        question[1][0][2][5] = "Nina";
        question[1][0][2][6] = "It arrived in 1620.";
        question[1][0][3][0] = "Who built the Great Wall of China?";
        question[1][0][3][1] = "Emperor Qin Shi Huang";
        question[1][0][3][2] = "Marco Polo";
        question[1][0][3][3] = "Genghis Khan";
        question[1][0][3][4] = "Emperor Qin Shi Huang";
        question[1][0][3][5] = "Confucius";
        question[1][0][3][6] = "It was built to protect China.";
        question[1][0][4][0] = "What ancient wonder was located in Egypt?";
        question[1][0][4][1] = "Great Pyramid of Giza";
        question[1][0][4][2] = "Great Pyramid of Giza";
        question[1][0][4][3] = "Colosseum";
        question[1][0][4][4] = "Hanging Gardens";
        question[1][0][4][5] = "Statue of Zeus";
        question[1][0][4][6] = "It is the oldest wonder still standing.";
        question[1][0][5][0] = "Who was the famous queen of ancient Egypt?";
        question[1][0][5][1] = "Cleopatra";
        question[1][0][5][2] = "Isis";
        question[1][0][5][3] = "Nefertiti";
        question[1][0][5][4] = "Cleopatra";
        question[1][0][5][5] = "Hatshepsut";
        question[1][0][5][6] = "She ruled during the Ptolemaic period.";

        // History - Taxonomy Level 2: Understanding (Easy)
        question[1][1][0][0] = "Why did the Pilgrims come to America?";
        question[1][1][0][1] = "To find religious freedom";
        question[1][1][0][2] = "To find religious freedom";
        question[1][1][0][3] = "To mine gold";
        question[1][1][0][4] = "To fight wars";
        question[1][1][0][5] = "To build ships";
        question[1][1][0][6] = "They wanted to worship freely.";
        question[1][1][1][0] = "What was the purpose of the Great Wall of China?";
        question[1][1][1][1] = "To protect against invaders";
        question[1][1][1][2] = "To create a city";
        question[1][1][1][3] = "To protect against invaders";
        question[1][1][1][4] = "To mark a trade route";
        question[1][1][1][5] = "To grow crops";
        question[1][1][1][6] = "It kept enemies out of China.";
        question[1][1][2][0] = "Why was the Declaration of Independence written?";
        question[1][1][2][1] = "To announce freedom from Britain";
        question[1][1][2][2] = "To elect a king";
        question[1][1][2][3] = "To start a war";
        question[1][1][2][4] = "To announce freedom from Britain";
        question[1][1][2][5] = "To build a city";
        question[1][1][2][6] = "It was signed in 1776.";
        question[1][1][3][0] = "What did ancient Egyptians use pyramids for?";
        question[1][1][3][1] = "As tombs for pharaohs";
        question[1][1][3][2] = "As tombs for pharaohs";
        question[1][1][3][3] = "As schools";
        question[1][1][3][4] = "As markets";
        question[1][1][3][5] = "As forts";
        question[1][1][3][6] = "Pyramids held royal burials.";
        question[1][1][4][0] = "Why did people build castles in the Middle Ages?";
        question[1][1][4][1] = "For protection and defense";
        question[1][1][4][2] = "To hold markets";
        question[1][1][4][3] = "For protection and defense";
        question[1][1][4][4] = "To grow food";
        question[1][1][4][5] = "To teach children";
        question[1][1][4][6] = "Castles were strongholds for safety.";
        question[1][1][5][0] = "What was the purpose of the Roman Colosseum?";
        question[1][1][5][1] = "To host gladiator fights";
        question[1][1][5][2] = "To house people";
        question[1][1][5][3] = "To store food";
        question[1][1][5][4] = "To host gladiator fights";
        question[1][1][5][5] = "To grow plants";
        question[1][1][5][6] = "It was a place for public entertainment.";

        // History - Taxonomy Level 3: Applying (Easy)
        question[1][2][0][0] = "If you were a Pilgrim, what would you bring to America?";
        question[1][2][0][1] = "Clothes and tools";
        question[1][2][0][2] = "Cars and phones";
        question[1][2][0][3] = "Clothes and tools";
        question[1][2][0][4] = "Books and TVs";
        question[1][2][0][5] = "Toys and games";
        question[1][2][0][6] = "Pilgrims needed basics to survive.";
        question[1][2][1][0] = "If you lived in ancient Egypt, where would you bury a pharaoh?";
        question[1][2][1][1] = "In a pyramid";
        question[1][2][1][2] = "In a forest";
        question[1][2][1][3] = "In a river";
        question[1][2][1][4] = "In a pyramid";
        question[1][2][1][5] = "In a house";
        question[1][2][1][6] = "Pyramids were tombs for royalty.";
        question[1][2][2][0] = "If you were building a castle, what would you include?";
        question[1][2][2][1] = "High walls and a moat";
        question[1][2][2][2] = "High walls and a moat";
        question[1][2][2][3] = "Glass windows and carpets";
        question[1][2][2][4] = "Swimming pools";
        question[1][2][2][5] = "Flat roofs";
        question[1][2][2][6] = "Castles needed defenses.";
        question[1][2][3][0] = "If you were an explorer like Columbus, what would you need?";
        question[1][2][3][1] = "A ship and a map";
        question[1][2][3][2] = "A plane and a radio";
        question[1][2][3][3] = "A bike and a book";
        question[1][2][3][4] = "A ship and a map";
        question[1][2][3][5] = "A car and a phone";
        question[1][2][3][6] = "Explorers needed navigation tools.";
        question[1][2][4][0] = "If you were in the Colosseum, what would you see?";
        question[1][2][4][1] = "Gladiator fights";
        question[1][2][4][2] = "Teachers lecturing";
        question[1][2][4][3] = "Gladiator fights";
        question[1][2][4][4] = "Painters drawing";
        question[1][2][4][5] = "Farmers working";
        question[1][2][4][6] = "The Colosseum was for entertainment.";
        question[1][2][5][0] = "If you were a knight, what would you wear?";
        question[1][2][5][1] = "Armor and a helmet";
        question[1][2][5][2] = "A suit and tie";
        question[1][2][5][3] = "A robe and sandals";
        question[1][2][5][4] = "Armor and a helmet";
        question[1][2][5][5] = "A hat and gloves";
        question[1][2][5][6] = "Knights needed protection in battle.";

        // History - Taxonomy Level 4: Analyzing (Easy)
        question[1][3][0][0] = "What is the difference between a king and a president?";
        question[1][3][0][1] = "A king is born, a president is elected";
        question[1][3][0][2] = "A president rules forever";
        question[1][3][0][3] = "A king is born, a president is elected";
        question[1][3][0][4] = "Both are born rulers";
        question[1][3][0][5] = "Both are elected";
        question[1][3][0][6] = "Leadership roles have different origins.";
        question[1][3][1][0] = "How is a pyramid different from a castle?";
        question[1][3][1][1] = "Pyramids are tombs, castles are homes";
        question[1][3][1][2] = "Both are tombs";
        question[1][3][1][3] = "Pyramids are for defense";
        question[1][3][1][4] = "Pyramids are tombs, castles are homes";
        question[1][3][1][5] = "Both are homes";
        question[1][3][1][6] = "Each served a unique purpose.";
        question[1][3][2][0] = "What makes the Great Wall different from a city wall?";
        question[1][3][2][1] = "The Great Wall is longer";
        question[1][3][2][2] = "The Great Wall is longer";
        question[1][3][2][3] = "City walls are taller";
        question[1][3][2][4] = "City walls are longer";
        question[1][3][2][5] = "Both are the same";
        question[1][3][2][6] = "The Great Wall spans a country.";
        question[1][3][3][0] = "How is a knight different from a soldier?";
        question[1][3][3][1] = "Knights serve lords, soldiers serve countries";
        question[1][3][3][2] = "Soldiers ride horses";
        question[1][3][3][3] = "Knights use guns";
        question[1][3][3][4] = "Knights serve lords, soldiers serve countries";
        question[1][3][3][5] = "Both are the same";
        question[1][3][3][6] = "Knights lived in the Middle Ages.";
        question[1][3][4][0] = "What is the difference between a ship and a boat?";
        question[1][3][4][1] = "Ships are larger than boats";
        question[1][3][4][2] = "Boats are larger";
        question[1][3][4][3] = "Ships are larger than boats";
        question[1][3][4][4] = "Ships stay on land";
        question[1][3][4][5] = "Both are the same";
        question[1][3][4][6] = "Size defines their use.";
        question[1][3][5][0] = "How is ancient Egypt different from ancient Rome?";
        question[1][3][5][1] = "Egypt had pharaohs, Rome had emperors";
        question[1][3][5][2] = "Egypt had pharaohs, Rome had emperors";
        question[1][3][5][3] = "Rome had pyramids";
        question[1][3][5][4] = "Egypt had a Colosseum";
        question[1][3][5][5] = "Both had kings";
        question[1][3][5][6] = "Each had unique rulers and buildings.";

        // History - Taxonomy Level 5: Evaluating (Easy)
        question[1][4][0][0] = "Which was the best reason for building the Great Wall?";
        question[1][4][0][1] = "To protect China";
        question[1][4][0][2] = "To make a road";
        question[1][4][0][3] = "To grow food";
        question[1][4][0][4] = "To protect China";
        question[1][4][0][5] = "To build houses";
        question[1][4][0][6] = "Defense was the main goal.";
        question[1][4][1][0] = "Which was the best way to travel in ancient times?";
        question[1][4][1][1] = "By ship";
        question[1][4][1][2] = "By ship";
        question[1][4][1][3] = "By car";
        question[1][4][1][4] = "By plane";
        question[1][4][1][5] = "By train";
        question[1][4][1][6] = "Ships crossed oceans.";
        question[1][4][2][0] = "Which was the best place to live in ancient Egypt?";
        question[1][4][2][1] = "Near the Nile River";
        question[1][4][2][2] = "On a mountain";
        question[1][4][2][3] = "Near the Nile River";
        question[1][4][2][4] = "In a forest";
        question[1][4][2][5] = "In the desert";
        question[1][4][2][6] = "The Nile provided water and food.";
        question[1][4][3][0] = "Which was the best job in a castle?";
        question[1][4][3][1] = "Knight";
        question[1][4][3][2] = "Knight";
        question[1][4][3][3] = "Farmer";
        question[1][4][3][4] = "Merchant";
        question[1][4][3][5] = "Sailor";
        question[1][4][3][6] = "Knights were respected warriors.";
        question[1][4][4][0] = "Which was the best invention of ancient Rome?";
        question[1][4][4][1] = "Aqueducts";
        question[1][4][4][2] = "Pyramids";
        question[1][4][4][3] = "Aqueducts";
        question[1][4][4][4] = "Great Wall";
        question[1][4][4][5] = "Airplanes";
        question[1][4][4][6] = "Aqueducts brought water to cities.";
        question[1][4][5][0] = "Which was the best reason to explore new lands?";
        question[1][4][5][1] = "To find resources";
        question[1][4][5][2] = "To stay home";
        question[1][4][5][3] = "To avoid trade";
        question[1][4][5][4] = "To find resources";
        question[1][4][5][5] = "To build walls";
        question[1][4][5][6] = "Explorers sought wealth.";

        // History - Taxonomy Level 6: Creating (Easy)
        question[1][5][0][0] = "Design a flag for ancient Egypt.";
        question[1][5][0][1] = "Use symbols like the ankh or pyramid";
        question[1][5][0][2] = "Draw a car";
        question[1][5][0][3] = "Use only dots";
        question[1][5][0][4] = "Use symbols like the ankh or pyramid";
        question[1][5][0][5] = "Write numbers";
        question[1][5][0][6] = "Symbols represent culture.";
        question[1][5][1][0] = "Create a model of a castle.";
        question[1][5][1][1] = "Include walls and towers";
        question[1][5][1][2] = "Include walls and towers";
        question[1][5][1][3] = "Use only paper";
        question[1][5][1][4] = "Make a flat square";
        question[1][5][1][5] = "Draw a circle";
        question[1][5][1][6] = "Castles had defensive features.";
        question[1][5][2][0] = "Plan a festival for ancient Rome.";
        question[1][5][2][1] = "Include games and food";
        question[1][5][2][2] = "Build a wall";
        question[1][5][2][3] = "Include games and food";
        question[1][5][2][4] = "Grow crops";
        question[1][5][2][5] = "Make tools";
        question[1][5][2][6] = "Festivals were for fun.";
        question[1][5][3][0] = "Design a map of a new colony.";
        question[1][5][3][1] = "Show houses and a river";
        question[1][5][3][2] = "Write a story";
        question[1][5][3][3] = "Draw only trees";
        question[1][5][3][4] = "Show houses and a river";
        question[1][5][3][5] = "Use one color";
        question[1][5][3][6] = "Maps help plan settlements.";
        question[1][5][4][0] = "Create a story about a knight.";
        question[1][5][4][1] = "Describe his adventures";
        question[1][5][4][2] = "List numbers";
        question[1][5][4][3] = "Describe his adventures";
        question[1][5][4][4] = "Draw shapes";
        question[1][5][4][5] = "Write a poem";
        question[1][5][4][6] = "Stories bring history to life.";
        question[1][5][5][0] = "Plan a museum exhibit on explorers.";
        question[1][5][5][1] = "Show maps and ships";
        question[1][5][5][2] = "Show maps and ships";
        question[1][5][5][3] = "Grow plants";
        question[1][5][5][4] = "Display only rocks";
        question[1][5][5][5] = "Build a wall";
        question[1][5][5][6] = "Exhibits teach about exploration.";

        // Geography - Taxonomy Level 1: Remembering (Easy)
        question[2][0][0][0] = "What is the capital of France?";
        question[2][0][0][1] = "Paris";
        question[2][0][0][2] = "Paris";
        question[2][0][0][3] = "Berlin";
        question[2][0][0][4] = "Madrid";
        question[2][0][0][5] = "London";
        question[2][0][0][6] = "Capital city of France due to its famous landmarks like the Eiffel Tower.";
        question[2][0][1][0] = "What is the largest continent?";
        question[2][0][1][1] = "Asia";
        question[2][0][1][2] = "Africa";
        question[2][0][1][3] = "Asia";
        question[2][0][1][4] = "Australia";
        question[2][0][1][5] = "Europe";
        question[2][0][1][6] = "It is home to many countries.";
        question[2][0][2][0] = "What is the tallest mountain in the world?";
        question[2][0][2][1] = "Mount Everest";
        question[2][0][2][2] = "K2";
        question[2][0][2][3] = "Mount Kilimanjaro";
        question[2][0][2][4] = "Mount Everest";
        question[2][0][2][5] = "Mount Fuji";
        question[2][0][2][6] = "It is located in the Himalayas.";
        question[2][0][3][0] = "What is the largest ocean?";
        question[2][0][3][1] = "Pacific Ocean";
        question[2][0][3][2] = "Indian Ocean";
        question[2][0][3][3] = "Pacific Ocean";
        question[2][0][3][4] = "Atlantic Ocean";
        question[2][0][3][5] = "Arctic Ocean";
        question[2][0][3][6] = "It is the biggest body of water.";
        question[2][0][4][0] = "What is the longest river in the world?";
        question[2][0][4][1] = "Nile River";
        question[2][0][4][2] = "Nile River";
        question[2][0][4][3] = "Mississippi River";
        question[2][0][4][4] = "Amazon River";
        question[2][0][4][5] = "Yangtze River";
        question[2][0][4][6] = "It flows through Africa.";
        question[2][0][5][0] = "What is the name of the hottest desert?";
        question[2][0][5][1] = "Sahara Desert";
        question[2][0][5][2] = "Kalahari Desert";
        question[2][0][5][3] = "Gobi Desert";
        question[2][0][5][4] = "Sahara Desert";
        question[2][0][5][5] = "Mojave Desert";
        question[2][0][5][6] = "It is in northern Africa.";

        // Geography - Taxonomy Level 2: Understanding (Easy)
        question[2][1][0][0] = "Why is the equator hot?";
        question[2][1][0][1] = "It gets direct sunlight";
        question[2][1][0][2] = "It has no mountains";
        question[2][1][0][3] = "It gets direct sunlight";
        question[2][1][0][4] = "It is always cloudy";
        question[2][1][0][5] = "It is near the ocean";
        question[2][1][0][6] = "Sunlight hits the equator straight on.";
        question[2][1][1][0] = "What causes rain in a rainforest?";
        question[2][1][1][1] = "Warm air holds moisture";
        question[2][1][1][2] = "Warm air holds moisture";
        question[2][1][1][3] = "Dry air creates clouds";
        question[2][1][1][4] = "Cold air stops rain";
        question[2][1][1][5] = "No air movement";
        question[2][1][1][6] = "Heat makes water evaporate.";
        question[2][1][2][0] = "Why do mountains have snow on top?";
        question[2][1][2][1] = "Higher areas are colder";
        question[2][1][2][2] = "They are near the Sun";
        question[2][1][2][3] = "Higher areas are colder";
        question[2][1][2][4] = "They have less wind";
        question[2][1][2][5] = "They get more rain";
        question[2][1][2][6] = "Cold air at high altitudes freezes water.";
        question[2][1][3][0] = "What makes a desert dry?";
        question[2][1][3][1] = "Little rainfall";
        question[2][1][3][2] = "Too much water";
        question[2][1][3][3] = "Little rainfall";
        question[2][1][3][4] = "Cold temperatures";
        question[2][1][3][5] = "Many trees";
        question[2][1][3][6] = "Deserts get very little water.";
        question[2][1][4][0] = "Why do rivers flow to the sea?";
        question[2][1][4][1] = "Gravity pulls water downhill";
        question[2][1][4][2] = "Rivers are flat";
        question[2][1][4][3] = "Gravity pulls water downhill";
        question[2][1][4][4] = "The sea pushes water";
        question[2][1][4][5] = "Wind moves water";
        question[2][1][4][6] = "Water flows to lower areas.";
        question[2][1][5][0] = "What causes waves in the ocean?";
        question[2][1][5][1] = "Wind blows over water";
        question[2][1][5][2] = "Wind blows over water";
        question[2][1][5][3] = "Fish swim fast";
        question[2][1][5][4] = "Rocks fall in";
        question[2][1][5][5] = "The Moon pulls water";
        question[2][1][5][6] = "Wind creates ripples on water.";

        // Geography - Taxonomy Level 3: Applying (Easy)
        question[2][2][0][0] = "If you are in Paris, what country are you in?";
        question[2][2][0][1] = "France";
        question[2][2][0][2] = "Spain";
        question[2][2][0][3] = "France";
        question[2][2][0][4] = "Italy";
        question[2][2][0][5] = "Germany";
        question[2][2][0][6] = "Paris is the capital of France.";
        question[2][2][1][0] = "If you see Mount Everest, what continent are you on?";
        question[2][2][1][1] = "Asia";
        question[2][2][1][2] = "South America";
        question[2][2][1][3] = "Africa";
        question[2][2][1][4] = "Asia";
        question[2][2][1][5] = "Australia";
        question[2][2][1][6] = "Mount Everest is in the Himalayas.";
        question[2][2][2][0] = "If you are sailing in the Pacific, what are you crossing?";
        question[2][2][2][1] = "An ocean";
        question[2][2][2][2] = "A river";
        question[2][2][2][3] = "An ocean";
        question[2][2][2][4] = "A desert";
        question[2][2][2][5] = "A mountain";
        question[2][2][2][6] = "The Pacific is the largest ocean.";
        question[2][2][3][0] = "If you are in the Sahara, what are you crossing?";
        question[2][2][3][1] = "A desert";
        question[2][2][3][2] = "A desert";
        question[2][2][3][3] = "A river";
        question[2][2][3][4] = "A forest";
        question[2][2][3][5] = "A city";
        question[2][2][3][6] = "The Sahara is very dry.";
        question[2][2][4][0] = "If you follow the Nile, where will you end up?";
        question[2][2][4][1] = "Mediterranean Sea";
        question[2][2][4][2] = "Red Sea";
        question[2][2][4][3] = "Pacific Ocean";
        question[2][2][4][4] = "Mediterranean Sea";
        question[2][2][4][5] = "Atlantic Ocean";
        question[2][2][4][6] = "The Nile flows north.";
        question[2][2][5][0] = "If you are on a rainforest trail, what continent might you be on?";
        question[2][2][5][1] = "South America";
        question[2][2][5][2] = "Europe";
        question[2][2][5][3] = "South America";
        question[2][2][5][4] = "Antarctica";
        question[2][2][5][5] = "Australia";
        question[2][2][5][6] = "The Amazon is in South America.";

        // Geography - Taxonomy Level 4: Analyzing (Easy)
        question[2][3][0][0] = "What is the difference between a river and a lake?";
        question[2][3][0][1] = "Rivers flow, lakes are still";
        question[2][3][0][2] = "Rivers flow, lakes are still";
        question[2][3][0][3] = "Lakes flow, rivers are still";
        question[2][3][0][4] = "Rivers are deeper";
        question[2][3][0][5] = "Both are the same";
        question[2][3][0][6] = "Rivers move water, lakes hold it.";
        question[2][3][1][0] = "How is a desert different from a forest?";
        question[2][3][1][1] = "Deserts are dry, forests are green";
        question[2][3][1][2] = "Forests are dry";
        question[2][3][1][3] = "Deserts are dry, forests are green";
        question[2][3][1][4] = "Deserts have more trees";
        question[2][3][1][5] = "Both are the same";
        question[2][3][1][6] = "Water makes forests lush.";
        question[2][3][2][0] = "What makes a mountain different from a hill?";
        question[2][3][2][1] = "Mountains are taller";
        question[2][3][2][2] = "Hills are steeper";
        question[2][3][2][3] = "Hills are taller";
        question[2][3][2][4] = "Mountains are taller";
        question[2][3][2][5] = "Both are the same";
        question[2][3][2][6] = "Height defines mountains.";
        question[2][3][3][0] = "How is an ocean different from a sea?";
        question[2][3][3][1] = "Oceans are larger";
        question[2][3][3][2] = "Oceans are larger";
        question[2][3][3][3] = "Seas are larger";
        question[2][3][3][4] = "Seas are deeper";
        question[2][3][3][5] = "Both are the same";
        question[2][3][3][6] = "Oceans cover more area.";
        question[2][3][4][0] = "What is the difference between the equator and the poles?";
        question[2][3][4][1] = "Equator is hot, poles are cold";
        question[2][3][4][2] = "Poles are hot";
        question[2][3][4][3] = "Both are the same";
        question[2][3][4][4] = "Equator is hot, poles are cold";
        question[2][3][4][5] = "Equator is cold";
        question[2][3][4][6] = "Temperature varies by location.";
        question[2][3][5][0] = "How is a city different from a village?";
        question[2][3][5][1] = "Cities are larger";
        question[2][3][5][2] = "Villages are larger";
        question[2][3][5][3] = "Cities are larger";
        question[2][3][5][4] = "Villages have more buildings";
        question[2][3][5][5] = "Both are the same";
        question[2][3][5][6] = "Size and population differ.";

        // Geography - Taxonomy Level 5: Evaluating (Easy)
        question[2][4][0][0] = "Which is the best place to grow crops?";
        question[2][4][0][1] = "Near a river";
        question[2][4][0][2] = "Near a river";
        question[2][4][0][3] = "On a mountain";
        question[2][4][0][4] = "In a desert";
        question[2][4][0][5] = "In the ocean";
        question[2][4][0][6] = "Rivers provide water for crops.";
        question[2][4][1][0] = "Which is the best way to travel across an ocean?";
        question[2][4][1][1] = "By ship";
        question[2][4][1][2] = "By bike";
        question[2][4][1][3] = "By ship";
        question[2][4][1][4] = "By car";
        question[2][4][1][5] = "By walking";
        question[2][4][1][6] = "Ships are built for ocean travel.";
        question[2][4][2][0] = "Which is the best place to build a city?";
        question[2][4][2][1] = "Near a water source";
        question[2][4][2][2] = "In a desert";
        question[2][4][2][3] = "Near a water source";
        question[2][4][2][4] = "On a cliff";
        question[2][4][2][5] = "In a forest";
        question[2][4][2][6] = "Water supports city life.";
        question[2][4][3][0] = "Which is the best way to stay cool in a desert?";
        question[2][4][3][1] = "Wear light clothing";
        question[2][4][3][2] = "Wear heavy coats";
        question[2][4][3][3] = "Stay in the Sun";
        question[2][4][3][4] = "Wear light clothing";
        question[2][4][3][5] = "Avoid water";
        question[2][4][3][6] = "Light clothes reflect heat.";
        question[2][4][4][0] = "Which is the best way to find north?";
        question[2][4][4][1] = "Use a compass";
        question[2][4][4][2] = "Follow the wind";
        question[2][4][4][3] = "Use a compass";
        question[2][4][4][4] = "Guess randomly";
        question[2][4][4][5] = "Look at the ground";
        question[2][4][4][6] = "A compass points to north.";
        question[2][4][5][0] = "Which is the best place to see animals?";
        question[2][4][5][1] = "In a rainforest";
        question[2][4][5][2] = "In a city";
        question[2][4][5][3] = "In the ocean";
        question[2][4][5][4] = "In a rainforest";
        question[2][4][5][5] = "On a mountain";
        question[2][4][5][6] = "Rainforests have many species.";

        // Geography - Taxonomy Level 6: Creating (Easy)
        question[2][5][0][0] = "Design a map of a small island.";
        question[2][5][0][1] = "Show a beach and trees";
        question[2][5][0][2] = "Write a story";
        question[2][5][0][3] = "Show a beach and trees";
        question[2][5][0][4] = "Draw only rocks";
        question[2][5][0][5] = "Use one color";
        question[2][5][0][6] = "Maps show land features.";
        question[2][5][1][0] = "Create a poster about the Nile River.";
        question[2][5][1][1] = "Show its path and animals";
        question[2][5][1][2] = "Show its path and animals";
        question[2][5][1][3] = "List numbers";
        question[2][5][1][4] = "Draw a city";
        question[2][5][1][5] = "Write a song";
        question[2][5][1][6] = "Posters teach about geography.";
        question[2][5][2][0] = "Plan a park for a city.";
        question[2][5][2][1] = "Include trees and a pond";
        question[2][5][2][2] = "Pave the area";
        question[2][5][2][3] = "Include trees and a pond";
        question[2][5][2][4] = "Add a desert";
        question[2][5][2][5] = "Build a factory";
        question[2][5][2][6] = "Parks provide green spaces.";
        question[2][5][3][0] = "Design a flag for a new country.";
        question[2][5][3][1] = "Use colors and symbols";
        question[2][5][3][2] = "Write numbers";
        question[2][5][3][3] = "Draw a square";
        question[2][5][3][4] = "Use colors and symbols";
        question[2][5][3][5] = "Use only lines";
        question[2][5][3][6] = "Flags represent a country.";
        question[2][5][4][0] = "Create a model of a mountain.";
        question[2][5][4][1] = "Use clay or paper";
        question[2][5][4][2] = "Use clay or paper";
        question[2][5][4][3] = "Use water";
        question[2][5][4][4] = "Draw a flat line";
        question[2][5][4][5] = "Write a story";
        question[2][5][4][6] = "Models show land shapes.";
        question[2][5][5][0] = "Plan a trip across a continent.";
        question[2][5][5][1] = "Choose cities and routes";
        question[2][5][5][2] = "Draw a circle";
        question[2][5][5][3] = "Choose cities and routes";
        question[2][5][5][4] = "Write a poem";
        question[2][5][5][5] = "Stay in one place";
        question[2][5][5][6] = "Trips explore new places.";

        // Mathematics - Taxonomy Level 1: Remembering (Easy)
        question[3][0][0][0] = "What is 2 + 2?";
        question[3][0][0][1] = "4";
        question[3][0][0][2] = "4";
        question[3][0][0][3] = "5";
        question[3][0][0][4] = "3";
        question[3][0][0][5] = "6";
        question[3][0][0][6] = "Addition combines numbers.";
        question[3][0][1][0] = "What is 5 - 3?";
        question[3][0][1][1] = "2";
        question[3][0][1][2] = "4";
        question[3][0][1][3] = "2";
        question[3][0][1][4] = "1";
        question[3][0][1][5] = "8";
        question[3][0][1][6] = "Subtraction takes one number away.";
        question[3][0][2][0] = "What is 3 × 2?";
        question[3][0][2][1] = "6";
        question[3][0][2][2] = "8";
        question[3][0][2][3] = "6";
        question[3][0][2][4] = "9";
        question[3][0][2][5] = "5";
        question[3][0][2][6] = "Multiplication repeats addition.";
        question[3][0][3][0] = "What is 8 ÷ 2?";
        question[3][0][3][1] = "4";
        question[3][0][3][2] = "6";
        question[3][0][3][3] = "3";
        question[3][0][3][4] = "4";
        question[3][0][3][5] = "2";
        question[3][0][3][6] = "Division splits numbers.";
        question[3][0][4][0] = "What is the shape with 4 equal sides?";
        question[3][0][4][1] = "Square";
        question[3][0][4][2] = "Circle";
        question[3][0][4][3] = "Square";
        question[3][0][4][4] = "Rectangle";
        question[3][0][4][5] = "Triangle";
        question[3][0][4][6] = "A square has equal sides.";
        question[3][0][5][0] = "What is the number after 9?";
        question[3][0][5][1] = "10";
        question[3][0][5][2] = "11";
        question[3][0][5][3] = "8";
        question[3][0][5][4] = "10";
        question[3][0][5][5] = "7";
        question[3][0][5][6] = "Counting goes up by one.";

        // Mathematics - Taxonomy Level 2: Understanding (Easy)
        question[3][1][0][0] = "Why is 4 + 3 the same as 3 + 4?";
        question[3][1][0][1] = "Addition is commutative";
        question[3][1][0][2] = "Numbers are different";
        question[3][1][0][3] = "Addition is commutative";
        question[3][1][0][4] = "It is subtraction";
        question[3][1][0][5] = "Order changes the answer";
        question[3][1][0][6] = "Order does not affect addition.";
        question[3][1][1][0] = "What does a circle look like?";
        question[3][1][1][1] = "A round shape";
        question[3][1][1][2] = "A round shape";
        question[3][1][1][3] = "A straight line";
        question[3][1][1][4] = "A triangle";
        question[3][1][1][5] = "A square shape";
        question[3][1][1][6] = "Circles have no corners.";
        question[3][1][2][0] = "Why is 10 - 5 different from 5 - 10?";
        question[3][1][2][1] = "Subtraction is not commutative";
        question[3][1][2][2] = "It is addition";
        question[3][1][2][3] = "Subtraction is not commutative";
        question[3][1][2][4] = "Order does not matter";
        question[3][1][2][5] = "Both are the same";
        question[3][1][2][6] = "Order matters in subtraction.";
        question[3][1][3][0] = "What does 2 × 3 mean?";
        question[3][1][3][1] = "Two groups of three";
        question[3][1][3][2] = "Three minus two";
        question[3][1][3][3] = "Two groups of three";
        question[3][1][3][4] = "Two plus three";
        question[3][1][3][5] = "Three groups of one";
        question[3][1][3][6] = "Multiplication shows groups.";
        question[3][1][4][0] = "Why is a square a level of rectangle?";
        question[3][1][4][1] = "It has four right angles";
        question[3][1][4][2] = "It is round";
        question[3][1][4][3] = "It has three sides";
        question[3][1][4][4] = "It has four right angles";
        question[3][1][4][5] = "It has no angles";
        question[3][1][4][6] = "Rectangles include squares.";
        question[3][1][5][0] = "What does a number line show?";
        question[3][1][5][1] = "Order of numbers";
        question[3][1][5][2] = "Order of numbers";
        question[3][1][5][3] = "Colors";
        question[3][1][5][4] = "Shapes";
        question[3][1][5][5] = "Letters";
        question[3][1][5][6] = "Numbers are placed in sequence.";

        // Mathematics - Taxonomy Level 3: Applying (Easy)
        question[3][2][0][0] = "If you have 3 apples and add 2 more, how many do you have?";
        question[3][2][0][1] = "5";
        question[3][2][0][2] = "6";
        question[3][2][0][3] = "5";
        question[3][2][0][4] = "4";
        question[3][2][0][5] = "3";
        question[3][2][0][6] = "Add the numbers together.";
        question[3][2][1][0] = "If you have 6 cookies and eat 2, how many are left?";
        question[3][2][1][1] = "4";
        question[3][2][1][2] = "8";
        question[3][2][1][3] = "4";
        question[3][2][1][4] = "5";
        question[3][2][1][5] = "2";
        question[3][2][1][6] = "Subtract what you ate.";
        question[3][2][2][0] = "If you buy 2 packs of 3 pens, how many pens do you have?";
        question[3][2][2][1] = "6";
        question[3][2][2][2] = "5";
        question[3][2][2][3] = "6";
        question[3][2][2][4] = "8";
        question[3][2][2][5] = "4";
        question[3][2][2][6] = "Multiply packs by pens.";
        question[3][2][3][0] = "If you share 10 candies among 2 friends, how many does each get?";
        question[3][2][3][1] = "5";
        question[3][2][3][2] = "4";
        question[3][2][3][3] = "6";
        question[3][2][3][4] = "5";
        question[3][2][3][5] = "2";
        question[3][2][3][6] = "Divide equally.";
        question[3][2][4][0] = "If a square has a side of 3, what is its perimeter?";
        question[3][2][4][1] = "12";
        question[3][2][4][2] = "9";
        question[3][2][4][3] = "12";
        question[3][2][4][4] = "6";
        question[3][2][4][5] = "15";
        question[3][2][4][6] = "Add all four sides.";
        question[3][2][5][0] = "If you count by 2s, what is the 3rd number?";
        question[3][2][5][1] = "6";
        question[3][2][5][2] = "4";
        question[3][2][5][3] = "8";
        question[3][2][5][4] = "6";
        question[3][2][5][5] = "2";
        question[3][2][5][6] = "Skip count by twos.";

        // Mathematics - Taxonomy Level 4: Analyzing (Easy)
        question[3][3][1][0] = "How is a square different from a triangle?";
        question[3][3][1][1] = "Square has 4 sides, triangle has 3";
        question[3][3][1][2] = "Square has 4 sides, triangle has 3";
        question[3][3][1][3] = "Both have 4 sides";
        question[3][3][1][4] = "Both have 3 sides";
        question[3][3][1][5] = "Square has 3 sides";
        question[3][3][1][6] = "Side count defines them.";
        question[3][3][2][0] = "What is the difference between even and odd numbers?";
        question[3][3][2][1] = "Even is divisible by 2, odd is not";
        question[3][3][2][2] = "Odd is divisible by 2";
        question[3][3][2][3] = "Even is divisible by 2, odd is not";
        question[3][3][2][4] = "Both are the same";
        question[3][3][2][5] = "Even is not divisible by 2";
        question[3][3][2][6] = "Divisibility determines level.";
        question[3][3][3][0] = "How does counting differ from measuring?";
        question[3][3][3][1] = "Counting uses whole numbers, measuring uses units";
        question[3][3][3][2] = "Measuring uses whole numbers";
        question[3][3][3][3] = "Both are the same";
        question[3][3][3][4] = "Counting uses whole numbers, measuring uses units";
        question[3][3][3][5] = "Counting uses units";
        question[3][3][3][6] = "Purpose differs.";
        question[3][3][4][0] = "What distinguishes a circle from a square?";
        question[3][3][4][1] = "Circle is round, square has straight sides";
        question[3][3][4][2] = "Circle is round, square has straight sides";
        question[3][3][4][3] = "Square is round";
        question[3][3][4][4] = "Circle has straight sides";
        question[3][3][4][5] = "Both are the same";
        question[3][3][4][6] = "Shape defines their properties.";
    }

    void medium_questions()
    {
        // Initialize easy questions, answers, options, and explanations.

        // Science - Taxonomy Level 1: Remembering (Medium)
        question[0][0][0][0] = "What is the chemical symbol for gold?";
        question[0][0][0][1] = "Au";
        question[0][0][0][2] = "Fe";
        question[0][0][0][3] = "Au";
        question[0][0][0][4] = "Cu";
        question[0][0][0][5] = "Ag";
        question[0][0][0][6] = "Gold is a precious metal on the periodic table.";
        question[0][0][1][0] = "Which planet is known as the Red Planet?";
        question[0][0][1][1] = "Mars";
        question[0][0][1][2] = "Venus";
        question[0][0][1][3] = "Mercury";
        question[0][0][1][4] = "Mars";
        question[0][0][1][5] = "Jupiter";
        question[0][0][1][6] = "Its reddish color comes from iron oxide.";
        question[0][0][2][0] = "What is the primary gas in Earth’s atmosphere?";
        question[0][0][2][1] = "Nitrogen";
        question[0][0][2][2] = "Nitrogen";
        question[0][0][2][3] = "Helium";
        question[0][0][2][4] = "Carbon dioxide";
        question[0][0][2][5] = "Oxygen";
        question[0][0][2][6] = "It makes up about 78% of the atmosphere.";
        question[0][0][3][0] = "What is the unit of electric current?";
        question[0][0][3][1] = "Ampere";
        question[0][0][3][2] = "Watt";
        question[0][0][3][3] = "Ampere";
        question[0][0][3][4] = "Ohm";
        question[0][0][3][5] = "Volt";
        question[0][0][3][6] = "It measures the flow of electricity.";
        question[0][0][4][0] = "What is the boiling point of water at standard pressure?";
        question[0][0][4][1] = "100 degrees Celsius";
        question[0][0][4][2] = "50 degrees Celsius";
        question[0][0][4][3] = "0 degrees Celsius";
        question[0][0][4][4] = "100 degrees Celsius";
        question[0][0][4][5] = "200 degrees Celsius";
        question[0][0][4][6] = "Water turns to steam at this temperature.";
        question[0][0][5][0] = "What is the name of the closest star to Earth?";
        question[0][0][5][1] = "Sun";
        question[0][0][5][2] = "Sirius";
        question[0][0][5][3] = "Sun";
        question[0][0][5][4] = "Alpha Centauri";
        question[0][0][5][5] = "Proxima Centauri";
        question[0][0][5][6] = "It is the center of our solar system.";

        // Science - Taxonomy Level 2: Understanding (Medium)
        question[0][1][0][0] = "Why does a balloon filled with helium float?";
        question[0][1][0][1] = "Helium is lighter than air";
        question[0][1][0][2] = "Helium is magnetic";
        question[0][1][0][3] = "Helium is heavier than air";
        question[0][1][0][4] = "Helium is lighter than air";
        question[0][1][0][5] = "Helium is a liquid";
        question[0][1][0][6] = "Lighter gases rise in the atmosphere.";
        question[0][1][1][0] = "What causes the seasons on Earth?";
        question[0][1][1][1] = "Earth’s tilt on its axis";
        question[0][1][1][2] = "Earth’s magnetic field";
        question[0][1][1][3] = "Earth’s tilt on its axis";
        question[0][1][1][4] = "Earth’s rotation speed";
        question[0][1][1][5] = "Earth’s distance from the Sun";
        question[0][1][1][6] = "The tilt changes sunlight angles.";
        question[0][1][2][0] = "Why do metals conduct electricity?";
        question[0][1][2][1] = "They have free electrons";
        question[0][1][2][2] = "They have free electrons";
        question[0][1][2][3] = "They lack electrons";
        question[0][1][2][4] = "They are magnetic";
        question[0][1][2][5] = "They are insulators";
        question[0][1][2][6] = "Electrons move easily in metals.";
        question[0][1][3][0] = "What does the pH scale measure?";
        question[0][1][3][1] = "Acidity or alkalinity";
        question[0][1][3][2] = "Volume";
        question[0][1][3][3] = "Acidity or alkalinity";
        question[0][1][3][4] = "Density";
        question[0][1][3][5] = "Temperature";
        question[0][1][3][6] = "It ranges from 0 to 14.";
        question[0][1][4][0] = "Why do leaves change color in autumn?";
        question[0][1][4][1] = "Less chlorophyll is produced";
        question[0][1][4][2] = "Leaves become denser";
        question[0][1][4][3] = "More sunlight is absorbed";
        question[0][1][4][4] = "Less chlorophyll is produced";
        question[0][1][4][5] = "Leaves grow larger";
        question[0][1][4][6] = "Chlorophyll gives leaves their green color.";
        question[0][1][5][0] = "What causes a rainbow?";
        question[0][1][5][1] = "Refraction of light in water droplets";
        question[0][1][5][2] = "Scattering of dust";
        question[0][1][5][3] = "Absorption of sunlight";
        question[0][1][5][4] = "Refraction of light in water droplets";
        question[0][1][5][5] = "Reflection of clouds";
        question[0][1][5][6] = "Light splits into colors in rain.";

        // Science - Taxonomy Level 3: Applying (Medium)
        question[0][2][0][0] = "If a plant lacks sunlight, what will happen to its growth?";
        question[0][2][0][1] = "It will slow or stop";
        question[0][2][0][2] = "It will produce fruit";
        question[0][2][0][3] = "It will slow or stop";
        question[0][2][0][4] = "It will turn red";
        question[0][2][0][5] = "It will grow faster";
        question[0][2][0][6] = "Sunlight is needed for photosynthesis.";
        question[0][2][1][0] = "If you mix equal amounts of red and blue light, what color results?";
        question[0][2][1][1] = "Magenta";
        question[0][2][1][2] = "White";
        question[0][2][1][3] = "Yellow";
        question[0][2][1][4] = "Magenta";
        question[0][2][1][5] = "Green";
        question[0][2][1][6] = "Light mixing follows additive color rules.";
        question[0][2][2][0] = "If a circuit has a 12-volt battery and 4 ohms resistance, what is the current?";
        question[0][2][2][1] = "3 amperes";
        question[0][2][2][2] = "12 amperes";
        question[0][2][2][3] = "3 amperes";
        question[0][2][2][4] = "2 amperes";
        question[0][2][2][5] = "6 amperes";
        question[0][2][2][6] = "Use Ohm’s Law: Current = Voltage ÷ Resistance.";
        question[0][2][3][0] = "If a substance has a pH of 3, how would you classify it?";
        question[0][2][3][1] = "Acidic";
        question[0][2][3][2] = "Alkaline";
        question[0][2][3][3] = "Neutral";
        question[0][2][3][4] = "Acidic";
        question[0][2][3][5] = "Basic";
        question[0][2][3][6] = "A pH below 7 is acidic.";
        question[0][2][4][0] = "If an object is dropped from a height, what force acts on it?";
        question[0][2][4][1] = "Gravity";
        question[0][2][4][2] = "Gravity";
        question[0][2][4][3] = "Electricity";
        question[0][2][4][4] = "Friction";
        question[0][2][4][5] = "Magnetism";
        question[0][2][4][6] = "Gravity pulls objects toward Earth.";
        question[0][2][5][0] = "If you heat water to 150°C at standard pressure, what state is it in?";
        question[0][2][5][1] = "Gas";
        question[0][2][5][2] = "Solid";
        question[0][2][5][3] = "Gas";
        question[0][2][5][4] = "Plasma";
        question[0][2][5][5] = "Liquid";
        question[0][2][5][6] = "Water boils at 100°C.";

        // Science - Taxonomy Level 4: Analyzing (Medium)
        question[0][3][0][0] = "What is the key difference between a physical and chemical change?";
        question[0][3][0][1] = "Chemical changes form new substances";
        question[0][3][0][2] = "Physical changes are permanent";
        question[0][3][0][3] = "Chemical changes form new substances";
        question[0][3][0][4] = "Both are the same";
        question[0][3][0][5] = "Physical changes form new substances";
        question[0][3][0][6] = "Chemical changes alter molecular structure.";
        question[0][3][1][0] = "How do planets differ from stars in our solar system?";
        question[0][3][1][1] = "Planets orbit stars, stars produce light";
        question[0][3][1][2] = "Planets are brighter";
        question[0][3][1][3] = "Both produce light";
        question[0][3][1][4] = "Planets orbit stars, stars produce light";
        question[0][3][1][5] = "Stars orbit planets";
        question[0][3][1][6] = "Stars generate energy, planets do not.";
        question[0][3][2][0] = "What distinguishes conductors from insulators?";
        question[0][3][2][1] = "Conductors allow electricity, insulators resist it";
        question[0][3][2][2] = "Conductors resist electricity";
        question[0][3][2][3] = "Both are the same";
        question[0][3][2][4] = "Conductors allow electricity, insulators resist it";
        question[0][3][2][5] = "Insulators conduct electricity";
        question[0][3][2][6] = "Materials differ in electron flow.";
        question[0][3][3][0] = "How is evaporation different from condensation?";
        question[0][3][3][1] = "Evaporation turns liquid to gas, condensation turns gas to liquid";
        question[0][3][3][2] = "Condensation turns liquid to solid";
        question[0][3][3][3] = "Evaporation turns liquid to gas, condensation turns gas to liquid";
        question[0][3][3][4] = "Both are the same";
        question[0][3][3][5] = "Both turn liquid to gas";
        question[0][3][3][6] = "They are opposite processes in the water cycle.";
        question[0][3][4][0] = "What makes a mammal different from a reptile?";
        question[0][3][4][1] = "Mammals have fur, reptiles have scales";
        question[0][3][4][2] = "Mammals have scales";
        question[0][3][4][3] = "Both have scales";
        question[0][3][4][4] = "Mammals have fur, reptiles have scales";
        question[0][3][4][5] = "Reptiles have fur";
        question[0][3][4][6] = "Body coverings differ between them.";
        question[0][3][5][0] = "How is kinetic energy different from potential energy?";
        question[0][3][5][1] = "Kinetic is motion, potential is stored";
        question[0][3][5][2] = "Kinetic is stored, potential is motion";
        question[0][3][5][3] = "Both are motion";
        question[0][3][5][4] = "Kinetic is motion, potential is stored";
        question[0][3][5][5] = "Both are stored";
        question[0][3][5][6] = "Energy levels depend on state.";

        // Science - Taxonomy Level 5: Evaluating (Medium)
        question[0][4][0][0] = "Which is the most effective way to conserve energy at home?";
        question[0][4][0][1] = "Use energy-efficient bulbs";
        question[0][4][0][2] = "Open windows in winter";
        question[0][4][0][3] = "Use energy-efficient bulbs";
        question[0][4][0][4] = "Keep lights on";
        question[0][4][0][5] = "Use more heaters";
        question[0][4][0][6] = "Efficient bulbs reduce energy use.";
        question[0][4][1][0] = "Which is the best method to test water purity?";
        question[0][4][1][1] = "Use a water testing kit";
        question[0][4][1][2] = "Smell the water";
        question[0][4][1][3] = "Check its color";
        question[0][4][1][4] = "Use a water testing kit";
        question[0][4][1][5] = "Taste the water";
        question[0][4][1][6] = "Kits detect contaminants accurately.";
        question[0][4][2][0] = "Which renewable energy source is best for a windy area?";
        question[0][4][2][1] = "Wind power";
        question[0][4][2][2] = "Wind power";
        question[0][4][2][3] = "Geothermal energy";
        question[0][4][2][4] = "Solar power";
        question[0][4][2][5] = "Hydropower";
        question[0][4][2][6] = "Wind turbines use wind effectively.";
        question[0][4][3][0] = "Which is the best way to protect endangered species?";
        question[0][4][3][1] = "Create wildlife reserves";
        question[0][4][3][2] = "Cut down forests";
        question[0][4][3][3] = "Hunt more animals";
        question[0][4][3][4] = "Create wildlife reserves";
        question[0][4][3][5] = "Build roads through habitats";
        question[0][4][3][6] = "Reserves protect animal habitats.";
        question[0][4][4][0] = "Which is the best way to measure temperature?";
        question[0][4][4][1] = "Use a thermometer";
        question[0][4][4][2] = "Count clouds";
        question[0][4][4][3] = "Use a thermometer";
        question[0][4][4][4] = "Look at the sky";
        question[0][4][4][5] = "Feel the air";
        question[0][4][4][6] = "Thermometers give accurate readings.";
        question[0][4][5][0] = "Which is the best material for conducting electricity?";
        question[0][4][5][1] = "Copper";
        question[0][4][5][2] = "Plastic";
        question[0][4][5][3] = "Rubber";
        question[0][4][5][4] = "Copper";
        question[0][4][5][5] = "Wood";
        question[0][4][5][6] = "Copper is a good conductor.";

        // Science - Taxonomy Level 6: Creating (Medium)
        question[0][5][0][0] = "Design an experiment to test plant growth with different lights.";
        question[0][5][0][1] = "Use red, blue, and white lights on plants";
        question[0][5][0][2] = "Change plant levels";
        question[0][5][0][3] = "Use different soils";
        question[0][5][0][4] = "Use red, blue, and white lights on plants";
        question[0][5][0][5] = "Water plants differently";
        question[0][5][0][6] = "Control light to study growth effects.";
        question[0][5][1][0] = "Propose a plan to reduce air pollution in a city.";
        question[0][5][1][1] = "Promote electric vehicles";
        question[0][5][1][2] = "Promote electric vehicles";
        question[0][5][1][3] = "Cut down trees";
        question[0][5][1][4] = "Build more factories";
        question[0][5][1][5] = "Increase car use";
        question[0][5][1][6] = "Electric vehicles reduce emissions.";
        question[0][5][2][0] = "Create a model to show the water cycle.";
        question[0][5][2][1] = "Include evaporation and condensation";
        question[0][5][2][2] = "List temperatures";
        question[0][5][2][3] = "Include evaporation and condensation";
        question[0][5][2][4] = "Show only clouds";
        question[0][5][2][5] = "Draw animals";
        question[0][5][2][6] = "The water cycle shows water movement.";
        question[0][5][3][0] = "Design a simple solar-powered device.";
        question[0][5][3][1] = "Use a solar panel to power a fan";
        question[0][5][3][2] = "Use water power";
        question[0][5][3][3] = "Use a solar panel to power a fan";
        question[0][5][3][4] = "Use wind power";
        question[0][5][3][5] = "Use batteries";
        question[0][5][3][6] = "Solar panels capture sunlight.";
        question[0][5][4][0] = "Plan a campaign to promote recycling.";
        question[0][5][4][1] = "Educate about sorting waste";
        question[0][5][4][2] = "Mix all trash";
        question[0][5][4][3] = "Ban recycling bins";
        question[0][5][4][4] = "Educate about sorting waste";
        question[0][5][4][5] = "Encourage more waste";
        question[0][5][4][6] = "Recycling reduces landfill use.";
        question[0][5][5][0] = "Create a chart of planet distances from the Sun.";
        question[0][5][5][1] = "List planets and their distances";
        question[0][5][5][2] = "Write a story";
        question[0][5][5][3] = "List planets and their distances";
        question[0][5][5][4] = "Show only colors";
        question[0][5][5][5] = "Draw shapes";
        question[0][5][5][6] = "Charts organize solar system data.";

        // History - Taxonomy Level 1: Remembering (Medium)
        question[1][0][0][0] = "In which year did World War I begin?";
        question[1][0][0][1] = "1914";
        question[1][0][0][2] = "1920";
        question[1][0][0][3] = "1914";
        question[1][0][0][4] = "1900";
        question[1][0][0][5] = "1939";
        question[1][0][0][6] = "It was triggered by an assassination.";
        question[1][0][1][0] = "Who was the first woman to fly solo across the Atlantic?";
        question[1][0][1][1] = "Amelia Earhart";
        question[1][0][1][2] = "Eleanor Roosevelt";
        question[1][0][1][3] = "Bessie Coleman";
        question[1][0][1][4] = "Amelia Earhart";
        question[1][0][1][5] = "Harriet Quimby";
        question[1][0][1][6] = "She flew in 1932.";
        question[1][0][2][0] = "What was the name of the treaty ending World War I?";
        question[1][0][2][1] = "Treaty of Versailles";
        question[1][0][2][2] = "Treaty of Versailles";
        question[1][0][2][3] = "Treaty of Tordesillas";
        question[1][0][2][4] = "Treaty of Lisbon";
        question[1][0][2][5] = "Treaty of Paris";
        question[1][0][2][6] = "It was signed in 1919.";
        question[1][0][3][0] = "Who was the leader of the American Civil Rights Movement?";
        question[1][0][3][1] = "Martin Luther King Jr.";
        question[1][0][3][2] = "Rosa Parks";
        question[1][0][3][3] = "Martin Luther King Jr.";
        question[1][0][3][4] = "Malcolm X";
        question[1][0][3][5] = "Abraham Lincoln";
        question[1][0][3][6] = "He gave the 'I Have a Dream' speech.";
        question[1][0][4][0] = "What ancient civilization built Machu Picchu?";
        question[1][0][4][1] = "Inca";
        question[1][0][4][2] = "Olmec";
        question[1][0][4][3] = "Aztec";
        question[1][0][4][4] = "Inca";
        question[1][0][4][5] = "Maya";
        question[1][0][4][6] = "It is in Peru.";
        question[1][0][5][0] = "Who discovered penicillin?";
        question[1][0][5][1] = "Alexander Fleming";
        question[1][0][5][2] = "Thomas Edison";
        question[1][0][5][3] = "Alexander Fleming";
        question[1][0][5][4] = "Marie Curie";
        question[1][0][5][5] = "Louis Pasteur";
        question[1][0][5][6] = "He found it in 1928.";

        // History - Taxonomy Level 2: Understanding (Medium)
        question[1][1][0][0] = "Why did the Industrial Revolution begin in Britain?";
        question[1][1][0][1] = "Abundant coal and iron resources";
        question[1][1][0][2] = "Weak government";
        question[1][1][0][3] = "Abundant coal and iron resources";
        question[1][1][0][4] = "Fewer colonies";
        question[1][1][0][5] = "Lack of population";
        question[1][1][0][6] = "Resources fueled factories.";
        question[1][1][1][0] = "What was the main purpose of the Magna Carta?";
        question[1][1][1][1] = "Limit the king’s power";
        question[1][1][1][2] = "Build castles";
        question[1][1][1][3] = "Increase taxes";
        question[1][1][1][4] = "Limit the king’s power";
        question[1][1][1][5] = "Start a war";
        question[1][1][1][6] = "It was signed in 1215.";
        question[1][1][2][0] = "Why was the Silk Road important?";
        question[1][1][2][1] = "It connected trade between Asia and Europe";
        question[1][1][2][2] = "It was for education";
        question[1][1][2][3] = "It connected trade between Asia and Europe";
        question[1][1][2][4] = "It was for war";
        question[1][1][2][5] = "It was for farming";
        question[1][1][2][6] = "Trade spread goods and ideas.";
        question[1][1][3][0] = "What caused the French Revolution?";
        question[1][1][3][1] = "Social inequality and economic hardship";
        question[1][1][3][2] = "Natural disasters";
        question[1][1][3][3] = "Social inequality and economic hardship";
        question[1][1][3][4] = "Foreign invasion";
        question[1][1][3][5] = "New technology";
        question[1][1][3][6] = "It began in 1789.";
        question[1][1][4][0] = "Why was the printing press significant?";
        question[1][1][4][1] = "It spread knowledge widely";
        question[1][1][4][2] = "It grew food";
        question[1][1][4][3] = "It stopped wars";
        question[1][1][4][4] = "It spread knowledge widely";
        question[1][1][4][5] = "It built roads";
        question[1][1][4][6] = "Books became more accessible.";
        question[1][1][5][0] = "What was the purpose of the Underground Railroad?";
        question[1][1][5][1] = "To help enslaved people escape";
        question[1][1][5][2] = "To trade goods";
        question[1][1][5][3] = "To help enslaved people escape";
        question[1][1][5][4] = "To mine gold";
        question[1][1][5][5] = "To build trains";
        question[1][1][5][6] = "It aided freedom seekers.";

        // History - Taxonomy Level 3: Applying (Medium)
        question[1][2][0][0] = "If you were a merchant on the Silk Road, what would you trade?";
        question[1][2][0][1] = "Silk and spices";
        question[1][2][0][2] = "Books and pens";
        question[1][2][0][3] = "Silk and spices";
        question[1][2][0][4] = "Cars and bikes";
        question[1][2][0][5] = "Computers and phones";
        question[1][2][0][6] = "Goods were traded across continents.";
        question[1][2][1][0] = "If you lived during the French Revolution, what might you protest?";
        question[1][2][1][1] = "High taxes";
        question[1][2][1][2] = "More schools";
        question[1][2][1][3] = "High taxes";
        question[1][2][1][4] = "Better roads";
        question[1][2][1][5] = "New technology";
        question[1][2][1][6] = "Taxes caused unrest.";
        question[1][2][2][0] = "If you were in the Industrial Revolution, what would you use to power a factory?";
        question[1][2][2][1] = "Steam engine";
        question[1][2][2][2] = "Batteries";
        question[1][2][2][3] = "Wind turbines";
        question[1][2][2][4] = "Steam engine";
        question[1][2][2][5] = "Solar panels";
        question[1][2][2][6] = "Steam powered early machines.";
        question[1][2][3][0] = "If you were part of the Underground Railroad, what would you do?";
        question[1][2][3][1] = "Hide escaping slaves";
        question[1][2][3][2] = "Write laws";
        question[1][2][3][3] = "Sell crops";
        question[1][2][3][4] = "Hide escaping slaves";
        question[1][2][3][5] = "Build trains";
        question[1][2][3][6] = "It was a secret network.";
        question[1][2][4][0] = "If you were an Inca, where would you build Machu Picchu?";
        question[1][2][4][1] = "On a mountain";
        question[1][2][4][2] = "In a forest";
        question[1][2][4][3] = "On a mountain";
        question[1][2][4][4] = "By a river";
        question[1][2][4][5] = "In a desert";
        question[1][2][4][6] = "Mountains provided safety.";
        question[1][2][5][0] = "If you used a printing press, what would you print?";
        question[1][2][5][1] = "Books and pamphlets";
        question[1][2][5][2] = "Tools";
        question[1][2][5][3] = "Books and pamphlets";
        question[1][2][5][4] = "Food";
        question[1][2][5][5] = "Clothes";
        question[1][2][5][6] = "Printing spread ideas.";

        // History - Taxonomy Level 4: Analyzing (Medium)
        question[1][3][0][0] = "What was the main difference between the American and French Revolutions?";
        question[1][3][0][1] = "American sought independence, French sought reform";
        question[1][3][0][2] = "Both were the same";
        question[1][3][0][3] = "French sought independence";
        question[1][3][0][4] = "American sought independence, French sought reform";
        question[1][3][0][5] = "Both sought independence";
        question[1][3][0][6] = "Goals shaped their outcomes.";
        question[1][3][1][0] = "How did the printing press differ from handwritten books?";
        question[1][3][1][1] = "Printing was faster and cheaper";
        question[1][3][1][2] = "Printing was slower";
        question[1][3][1][3] = "Handwriting was faster";
        question[1][3][1][4] = "Printing was faster and cheaper";
        question[1][3][1][5] = "Both were the same";
        question[1][3][1][6] = "Printing revolutionized knowledge.";
        question[1][3][2][0] = "What distinguished the Silk Road from sea trade routes?";
        question[1][3][2][1] = "Silk Road was over land, sea routes were over water";
        question[1][3][2][2] = "Sea routes were on land";
        question[1][3][2][3] = "Silk Road was over land, sea routes were over water";
        question[1][3][2][4] = "Both were the same";
        question[1][3][2][5] = "Both were over land";
        question[1][3][2][6] = "Routes affected trade speed.";
        question[1][3][3][0] = "How was the Industrial Revolution different from the Renaissance?";
        question[1][3][3][1] = "Industrial focused on machines, Renaissance on art";
        question[1][3][3][2] = "Renaissance focused on machines";
        question[1][3][3][3] = "Both were the same";
        question[1][3][3][4] = "Industrial focused on machines, Renaissance on art";
        question[1][3][3][5] = "Both focused on art";
        question[1][3][3][6] = "Eras had different focuses.";
        question[1][3][4][0] = "What made the Underground Railroad different from other escape routes?";
        question[1][3][4][1] = "It was a secret network";
        question[1][3][4][2] = "It was for trade";
        question[1][3][4][3] = "It used trains";
        question[1][3][4][4] = "It was a secret network";
        question[1][3][4][5] = "It was a public road";
        question[1][3][4][6] = "Secrecy protected escapees.";
        question[1][3][5][0] = "How did World War I differ from World War II?";
        question[1][3][5][1] = "World War I had trench warfare, World War II had more mobility";
        question[1][3][5][2] = "World War II had trenches";
        question[1][3][5][3] = "World War I had trench warfare, World War II had more mobility";
        question[1][3][5][4] = "World War I was global";
        question[1][3][5][5] = "Both were the same";
        question[1][3][5][6] = "War tactics evolved.";

        // History - Taxonomy Level 5: Evaluating (Medium)
        question[1][4][0][0] = "Which was the most significant invention of the Industrial Revolution?";
        question[1][4][0][1] = "Steam engine";
        question[1][4][0][2] = "Wheel";
        question[1][4][0][3] = "Steam engine";
        question[1][4][0][4] = "Compass";
        question[1][4][0][5] = "Printing press";
        question[1][4][0][6] = "It powered factories and trains.";
        question[1][4][1][0] = "Which event had the greatest impact on civil rights?";
        question[1][4][1][1] = "March on Washington";
        question[1][4][1][2] = "Industrial Revolution";
        question[1][4][1][3] = "March on Washington";
        question[1][4][1][4] = "French Revolution";
        question[1][4][1][5] = "World War I";
        question[1][4][1][6] = "It featured a famous speech.";
        question[1][4][2][0] = "Which was the best strategy for the Underground Railroad?";
        question[1][4][2][1] = "Using secret safe houses";
        question[1][4][2][2] = "Building roads";
        question[1][4][2][3] = "Using secret safe houses";
        question[1][4][2][4] = "Traveling openly";
        question[1][4][2][5] = "Using trains";
        question[1][4][2][6] = "Safe houses protected escapees.";
        question[1][4][3][0] = "Which was the most effective outcome of the Magna Carta?";
        question[1][4][3][1] = "Establishing rule of law";
        question[1][4][3][2] = "Increasing taxes";
        question[1][4][3][3] = "Building castles";
        question[1][4][3][4] = "Establishing rule of law";
        question[1][4][3][5] = "Starting a war";
        question[1][4][3][6] = "It influenced modern democracy.";
        question[1][4][4][0] = "Which was the best contribution of the Inca civilization?";
        question[1][4][4][1] = "Advanced road systems";
        question[1][4][4][2] = "Sailing ships";
        question[1][4][4][3] = "Advanced road systems";
        question[1][4][4][4] = "Writing system";
        question[1][4][4][5] = "Pyramids";
        question[1][4][4][6] = "Roads connected their empire.";
        question[1][4][5][0] = "Which was the most important effect of the printing press?";
        question[1][4][5][1] = "Increased literacy";
        question[1][4][5][2] = "Slower communication";
        question[1][4][5][3] = "Fewer books";
        question[1][4][5][4] = "Increased literacy";
        question[1][4][5][5] = "More wars";
        question[1][4][5][6] = "Books became widely available.";

        // History - Taxonomy Level 6: Creating (Medium)
        question[1][5][0][0] = "Design a timeline of the Industrial Revolution.";
        question[1][5][0][1] = "Include key inventions and dates";
        question[1][5][0][2] = "Write a story";
        question[1][5][0][3] = "Include key inventions and dates";
        question[1][5][0][4] = "List only wars";
        question[1][5][0][5] = "Draw a map";
        question[1][5][0][6] = "Timelines show historical progress.";
        question[1][5][1][0] = "Plan a museum exhibit on the French Revolution.";
        question[1][5][1][1] = "Show key events and artifacts";
        question[1][5][1][2] = "Show modern art";
        question[1][5][1][3] = "Show key events and artifacts";
        question[1][5][1][4] = "Focus on food";
        question[1][5][1][5] = "Display only weapons";
        question[1][5][1][6] = "Exhibits educate about history.";
        question[1][5][2][0] = "Create a map of the Silk Road.";
        question[1][5][2][1] = "Mark major trade cities";
        question[1][5][2][2] = "Show one city";
        question[1][5][2][3] = "Mark major trade cities";
        question[1][5][2][4] = "List animals";
        question[1][5][2][5] = "Draw only rivers";
        question[1][5][2][6] = "Maps show trade routes.";
        question[1][5][3][0] = "Propose a law inspired by the Magna Carta.";
        question[1][5][3][1] = "Ensure fair trials";
        question[1][5][3][2] = "Limit trade";
        question[1][5][3][3] = "Ban education";
        question[1][5][3][4] = "Ensure fair trials";
        question[1][5][3][5] = "Increase taxes";
        question[1][5][3][6] = "Laws protect rights.";
        question[1][5][4][0] = "Design a monument for civil rights.";
        question[1][5][4][1] = "Include symbols of equality";
        question[1][5][4][2] = "Write numbers";
        question[1][5][4][3] = "Include symbols of equality";
        question[1][5][4][4] = "Show only buildings";
        question[1][5][4][5] = "Draw animals";
        question[1][5][4][6] = "Monuments honor history.";
        question[1][5][5][0] = "Create a story about the Underground Railroad.";
        question[1][5][5][1] = "Describe a journey to freedom";
        question[1][5][5][2] = "Write a song";
        question[1][5][5][3] = "Describe a journey to freedom";
        question[1][5][5][4] = "List dates";
        question[1][5][5][5] = "Draw shapes";
        question[1][5][5][6] = "Stories bring history to life.";

        // Geography - Taxonomy Level 1: Remembering (Medium)
        question[2][0][0][0] = "What is the capital of Brazil?";
        question[2][0][0][1] = "Brasilia";
        question[2][0][0][2] = "Sao Paulo";
        question[2][0][0][3] = "Brasilia";
        question[2][0][0][4] = "Salvador";
        question[2][0][0][5] = "Rio de Janeiro";
        question[2][0][0][6] = "It is a planned city in Brazil.";
        question[2][0][1][0] = "Which continent is home to the Amazon Rainforest?";
        question[2][0][1][1] = "South America";
        question[2][0][1][2] = "Australia";
        question[2][0][1][3] = "South America";
        question[2][0][1][4] = "Africa";
        question[2][0][1][5] = "Asia";
        question[2][0][1][6] = "It is the largest rainforest.";
        question[2][0][2][0] = "What is the longest river in South America?";
        question[2][0][2][1] = "Amazon River";
        question[2][0][2][2] = "Sao Francisco River";
        question[2][0][2][3] = "Orinoco River";
        question[2][0][2][4] = "Amazon River";
        question[2][0][2][5] = "Parana River";
        question[2][0][2][6] = "It flows through the rainforest.";
        question[2][0][3][0] = "Which mountain range runs along South America’s west coast?";
        question[2][0][3][1] = "Andes";
        question[2][0][3][2] = "Alps";
        question[2][0][3][3] = "Andes";
        question[2][0][3][4] = "Himalayas";
        question[2][0][3][5] = "Rockies";
        question[2][0][3][6] = "It is the longest mountain range.";
        question[2][0][4][0] = "What is the largest desert in Asia?";
        question[2][0][4][1] = "Gobi Desert";
        question[2][0][4][2] = "Thar Desert";
        question[2][0][4][3] = "Kalahari Desert";
        question[2][0][4][4] = "Gobi Desert";
        question[2][0][4][5] = "Sahara Desert";
        question[2][0][4][6] = "It spans China and Mongolia.";
        question[2][0][5][0] = "Which ocean lies between Africa and Australia?";
        question[2][0][5][1] = "Indian Ocean";
        question[2][0][5][2] = "Arctic Ocean";
        question[2][0][5][3] = "Indian Ocean";
        question[2][0][5][4] = "Pacific Ocean";
        question[2][0][5][5] = "Atlantic Ocean";
        question[2][0][5][6] = "It is south of Asia.";

        // Geography - Taxonomy Level 2: Understanding (Medium)
        question[2][1][0][0] = "Why do coastal areas have milder climates?";
        question[2][1][0][1] = "Oceans moderate temperatures";
        question[2][1][0][2] = "Less sunlight";
        question[2][1][0][3] = "Oceans moderate temperatures";
        question[2][1][0][4] = "Higher altitudes";
        question[2][1][0][5] = "More rainfall";
        question[2][1][0][6] = "Water retains heat longer.";
        question[2][1][1][0] = "What causes earthquakes?";
        question[2][1][1][1] = "Movement of tectonic plates";
        question[2][1][1][2] = "Ocean waves";
        question[2][1][1][3] = "Strong winds";
        question[2][1][1][4] = "Movement of tectonic plates";
        question[2][1][1][5] = "Heavy rainfall";
        question[2][1][1][6] = "Plates shift along faults.";
        question[2][1][2][0] = "Why are rainforests biodiverse?";
        question[2][1][2][1] = "Warm climate and abundant rain";
        question[2][1][2][2] = "High altitude";
        question[2][1][2][3] = "Warm climate and abundant rain";
        question[2][1][2][4] = "Dry conditions";
        question[2][1][2][5] = "Cold climate";
        question[2][1][2][6] = "Rainforests support many species.";
        question[2][1][3][0] = "What causes tides in the ocean?";
        question[2][1][3][1] = "Moon’s gravitational pull";
        question[2][1][3][2] = "Earth’s rotation";
        question[2][1][3][3] = "Moon’s gravitational pull";
        question[2][1][3][4] = "Sun’s heat";
        question[2][1][3][5] = "Wind speed";
        question[2][1][3][6] = "The Moon affects water levels.";
        question[2][1][4][0] = "Why do deserts have extreme temperatures?";
        question[2][1][4][1] = "Lack of water and vegetation";
        question[2][1][4][2] = "High clouds";
        question[2][1][4][3] = "Dense forests";
        question[2][1][4][4] = "Lack of water and vegetation";
        question[2][1][4][5] = "Too much water";
        question[2][1][4][6] = "No water means no cooling.";
        question[2][1][5][0] = "What causes volcanic eruptions?";
        question[2][1][5][1] = "Pressure from molten rock";
        question[2][1][5][2] = "Cold temperatures";
        question[2][1][5][3] = "Pressure from molten rock";
        question[2][1][5][4] = "Strong winds";
        question[2][1][5][5] = "Heavy rain";
        question[2][1][5][6] = "Magma builds up underground.";

        // Geography - Taxonomy Level 3: Applying (Medium)
        question[2][2][0][0] = "If a city is at 35°N, 139°E, what city is it?";
        question[2][2][0][1] = "Tokyo";
        question[2][2][0][2] = "Sydney";
        question[2][2][0][3] = "Tokyo";
        question[2][2][0][4] = "New York";
        question[2][2][0][5] = "Paris";
        question[2][2][0][6] = "Coordinates pinpoint locations.";
        question[2][2][1][0] = "If you are in the Andes, what continent are you on?";
        question[2][2][1][1] = "South America";
        question[2][2][1][2] = "Africa";
        question[2][2][1][3] = "Asia";
        question[2][2][1][4] = "South America";
        question[2][2][1][5] = "North America";
        question[2][2][1][6] = "The Andes run along South America.";
        question[2][2][2][0] = "If a river flows into the Indian Ocean, what continent might it be on?";
        question[2][2][2][1] = "Africa";
        question[2][2][2][2] = "Antarctica";
        question[2][2][2][3] = "Africa";
        question[2][2][2][4] = "South America";
        question[2][2][2][5] = "Europe";
        question[2][2][2][6] = "The Indian Ocean borders Africa.";
        question[2][2][3][0] = "If you are in the Gobi Desert, what countries might you be in?";
        question[2][2][3][1] = "China and Mongolia";
        question[2][2][3][2] = "Egypt and Libya";
        question[2][2][3][3] = "China and Mongolia";
        question[2][2][3][4] = "Brazil and Peru";
        question[2][2][3][5] = "India and Pakistan";
        question[2][2][3][6] = "The Gobi is in Asia.";
        question[2][2][4][0] = "If you follow the Amazon River, where will you end up?";
        question[2][2][4][1] = "Atlantic Ocean";
        question[2][2][4][2] = "Arctic Ocean";
        question[2][2][4][3] = "Indian Ocean";
        question[2][2][4][4] = "Atlantic Ocean";
        question[2][2][4][5] = "Pacific Ocean";
        question[2][2][4][6] = "The Amazon flows east.";
        question[2][2][5][0] = "If you are in a rainforest, what climate would you expect?";
        question[2][2][5][1] = "Hot and humid";
        question[2][2][5][2] = "Cold and snowy";
        question[2][2][5][3] = "Hot and humid";
        question[2][2][5][4] = "Cool and windy";
        question[2][2][5][5] = "Cold and dry";
        question[2][2][5][6] = "Rainforests have heavy rain.";

        // Geography - Taxonomy Level 4: Analyzing (Medium)
        question[2][3][0][0] = "What is the main difference between a tundra and a desert?";
        question[2][3][0][1] = "Tundra is cold, desert is hot";
        question[2][3][0][2] = "Both are cold";
        question[2][3][0][3] = "Tundra is hot";
        question[2][3][0][4] = "Tundra is cold, desert is hot";
        question[2][3][0][5] = "Both are hot";
        question[2][3][0][6] = "Climate defines these biomes.";
        question[2][3][1][0] = "How does a peninsula differ from an island?";
        question[2][3][1][1] = "Peninsula is connected to land, island is surrounded by water";
        question[2][3][1][2] = "Peninsula is larger";
        question[2][3][1][3] = "Both are connected to land";
        question[2][3][1][4] = "Peninsula is connected to land, island is surrounded by water";
        question[2][3][1][5] = "Both are surrounded by water";
        question[2][3][1][6] = "Land connection defines a peninsula.";
        question[2][3][2][0] = "What distinguishes a plateau from a mountain?";
        question[2][3][2][1] = "Plateau is flat, mountain is peaked";
        question[2][3][2][2] = "Both are peaked";
        question[2][3][2][3] = "Plateau is higher";
        question[2][3][2][4] = "Plateau is flat, mountain is peaked";
        question[2][3][2][5] = "Both are flat";
        question[2][3][2][6] = "Shape defines their features.";
        question[2][3][3][0] = "How is a tropical climate different from a polar climate?";
        question[2][3][3][1] = "Tropical is warm, polar is cold";
        question[2][3][3][2] = "Tropical is cold";
        question[2][3][3][3] = "Both are warm";
        question[2][3][3][4] = "Tropical is warm, polar is cold";
        question[2][3][3][5] = "Both are cold";
        question[2][3][3][6] = "Temperature defines climate zones.";
        question[2][3][4][0] = "What makes a delta different from a valley?";
        question[2][3][4][1] = "Delta is at a river’s mouth, valley is between mountains";
        question[2][3][4][2] = "Delta is higher";
        question[2][3][4][3] = "Both are between mountains";
        question[2][3][4][4] = "Delta is at a river’s mouth, valley is between mountains";
        question[2][3][4][5] = "Both are at river mouths";
        question[2][3][4][6] = "Deltas form from sediment.";
        question[2][3][5][0] = "How does a monsoon climate differ from a temperate climate?";
        question[2][3][5][1] = "Monsoon has heavy seasonal rain, temperate is moderate";
        question[2][3][5][2] = "Monsoon is dry";
        question[2][3][5][3] = "Both are moderate";
        question[2][3][5][4] = "Monsoon has heavy seasonal rain, temperate is moderate";
        question[2][3][5][5] = "Both have heavy rain";
        question[2][3][5][6] = "Rainfall patterns differ.";

        // Geography - Taxonomy Level 5: Evaluating (Medium)
        question[2][4][0][0] = "Which is the best method to prevent soil erosion?";
        question[2][4][0][1] = "Planting trees";
        question[2][4][0][2] = "Building roads";
        question[2][4][0][3] = "Paving the land";
        question[2][4][0][4] = "Planting trees";
        question[2][4][0][5] = "Removing plants";
        question[2][4][0][6] = "Tree roots hold soil in place.";
        question[2][4][1][0] = "Which is the best location for a port city?";
        question[2][4][1][1] = "Near a deep harbor";
        question[2][4][1][2] = "In a forest";
        question[2][4][1][3] = "Near a deep harbor";
        question[2][4][1][4] = "On a mountain";
        question[2][4][1][5] = "In a desert";
        question[2][4][1][6] = "Harbors support ship docking.";
        question[2][4][2][0] = "Which is the best way to conserve water in a dry region?";
        question[2][4][2][1] = "Use drip irrigation";
        question[2][4][2][2] = "Build pools";
        question[2][4][2][3] = "Remove plants";
        question[2][4][2][4] = "Use drip irrigation";
        question[2][4][2][5] = "Flood fields";
        question[2][4][2][6] = "Drip irrigation saves water.";
        question[2][4][3][0] = "Which is the best renewable resource for a sunny region?";
        question[2][4][3][1] = "Solar energy";
        question[2][4][3][2] = "Coal";
        question[2][4][3][3] = "Solar energy";
        question[2][4][3][4] = "Hydropower";
        question[2][4][3][5] = "Wind energy";
        question[2][4][3][6] = "Sunlight is abundant in sunny areas.";
        question[2][4][4][0] = "Which is the best way to navigate a desert?";
        question[2][4][4][1] = "Use a GPS and map";
        question[2][4][4][2] = "Look at the sky";
        question[2][4][4][3] = "Use a GPS and map";
        question[2][4][4][4] = "Walk randomly";
        question[2][4][4][5] = "Follow animals";
        question[2][4][4][6] = "GPS provides accurate directions.";
        question[2][4][5][0] = "Which is the best way to protect a rainforest?";
        question[2][4][5][1] = "Create protected areas";
        question[2][4][5][2] = "Increase farming";
        question[2][4][5][3] = "Build roads";
        question[2][4][5][4] = "Create protected areas";
        question[2][4][5][5] = "Cut down trees";
        question[2][4][5][6] = "Protected areas save wildlife.";

        // Geography - Taxonomy Level 6: Creating (Medium)
        question[2][5][0][0] = "Design a plan to reduce flooding in a coastal city.";
        question[2][5][0][1] = "Build sea walls and drainage systems";
        question[2][5][0][2] = "Build taller buildings";
        question[2][5][0][3] = "Pave the city";
        question[2][5][0][4] = "Build sea walls and drainage systems";
        question[2][5][0][5] = "Remove all plants";
        question[2][5][0][6] = "Walls and drains manage water.";
        question[2][5][1][0] = "Create a map of the Andes Mountains.";
        question[2][5][1][1] = "Show peaks and rivers";
        question[2][5][1][2] = "Use one color";
        question[2][5][1][3] = "Show peaks and rivers";
        question[2][5][1][4] = "List animals";
        question[2][5][1][5] = "Draw only cities";
        question[2][5][1][6] = "Maps show geographic features.";
        question[2][5][2][0] = "Plan a sustainable farm in a dry region.";
        question[2][5][2][1] = "Use drought-resistant crops";
        question[2][5][2][2] = "Build houses";
        question[2][5][2][3] = "Use drought-resistant crops";
        question[2][5][2][4] = "Remove soil";
        question[2][5][2][5] = "Flood the fields";
        question[2][5][2][6] = "Sustainable crops save water.";
        question[2][5][3][0] = "Design a poster about the Amazon Rainforest.";
        question[2][5][3][1] = "Show biodiversity and rivers";
        question[2][5][3][2] = "Write a story";
        question[2][5][3][3] = "List cities";
        question[2][5][3][4] = "Show biodiversity and rivers";
        question[2][5][3][5] = "Draw only deserts";
        question[2][5][3][6] = "Posters educate about ecosystems.";
        question[2][5][4][0] = "Propose a tourism plan for a mountain region.";
        question[2][5][4][1] = "Offer guided hikes and eco-lodges";
        question[2][5][4][2] = "Pave trails";
        question[2][5][4][3] = "Offer guided hikes and eco-lodges";
        question[2][5][4][4] = "Cut down trees";
        question[2][5][4][5] = "Build large resorts";
        question[2][5][4][6] = "Eco-tourism protects nature.";
        question[2][5][5][0] = "Create a model of a volcanic island.";
        question[2][5][5][1] = "Show the volcano and coast";
        question[2][5][5][2] = "Write numbers";
        question[2][5][5][3] = "Show the volcano and coast";
        question[2][5][5][4] = "List animals";
        question[2][5][5][5] = "Draw only flat land";
        question[2][5][5][6] = "Models show land features.";

        // Mathematics - Taxonomy Level 1: Remembering (Medium)
        question[3][0][0][0] = "What is the formula for the area of a triangle?";
        question[3][0][0][1] = "1/2 × base × height";
        question[3][0][0][2] = "Base + height";
        question[3][0][0][3] = "1/2 × base × height";
        question[3][0][0][4] = "Base × height";
        question[3][0][0][5] = "1/2 × base";
        question[3][0][0][6] = "It measures a triangle’s space.";
        question[3][0][1][0] = "What is 12 × 3?";
        question[3][0][1][1] = "36";
        question[3][0][1][2] = "9";
        question[3][0][1][3] = "36";
        question[3][0][1][4] = "24";
        question[3][0][1][5] = "15";
        question[3][0][1][6] = "Multiplication gives the total.";
        question[3][0][2][0] = "What is the value of π to two decimal places?";
        question[3][0][2][1] = "3.14";
        question[3][0][2][2] = "3.00";
        question[3][0][2][3] = "2.14";
        question[3][0][2][4] = "3.14";
        question[3][0][2][5] = "3.16";
        question[3][0][2][6] = "Pi is used for circles.";
        question[3][0][3][0] = "What is the formula for the perimeter of a rectangle?";
        question[3][0][3][1] = "2 × (length + width)";
        question[3][0][3][2] = "2 × length";
        question[3][0][3][3] = "Length + width";
        question[3][0][3][4] = "2 × (length + width)";
        question[3][0][3][5] = "Length × width";
        question[3][0][3][6] = "It measures the boundary.";
        question[3][0][4][0] = "What is 20 ÷ 4?";
        question[3][0][4][1] = "5";
        question[3][0][4][2] = "10";
        question[3][0][4][3] = "5";
        question[3][0][4][4] = "6";
        question[3][0][4][5] = "4";
        question[3][0][4][6] = "Division splits evenly.";
        question[3][0][5][0] = "What is the shape with 5 sides?";
        question[3][0][5][1] = "Pentagon";
        question[3][0][5][2] = "Square";
        question[3][0][5][3] = "Pentagon";
        question[3][0][5][4] = "Triangle";
        question[3][0][5][5] = "Hexagon";
        question[3][0][5][6] = "It has five equal sides.";

        // Mathematics - Taxonomy Level 2: Understanding (Medium)
        question[3][1][0][0] = "Why does multiplying by zero always give zero?";
        question[3][1][0][1] = "Zero means no groups";
        question[3][1][0][2] = "Zero subtracts numbers";
        question[3][1][0][3] = "Zero means no groups";
        question[3][1][0][4] = "Zero divides numbers";
        question[3][1][0][5] = "Zero adds numbers";
        question[3][1][0][6] = "No groups yield nothing.";
        question[3][1][1][0] = "What does the slope of a line represent?";
        question[3][1][1][1] = "Rate of change";
        question[3][1][1][2] = "Distance from origin";
        question[3][1][1][3] = "Area under the line";
        question[3][1][1][4] = "Rate of change";
        question[3][1][1][5] = "Length of the line";
        question[3][1][1][6] = "Slope shows steepness.";
        question[3][1][2][0] = "Why is the area of a circle πr²?";
        question[3][1][2][1] = "It measures the space inside";
        question[3][1][2][2] = "It measures angles";
        question[3][1][2][3] = "It measures the space inside";
        question[3][1][2][4] = "It measures height";
        question[3][1][2][5] = "It measures the edge";
        question[3][1][2][6] = "Pi relates to the radius.";
        question[3][1][3][0] = "What does a fraction represent?";
        question[3][1][3][1] = "Part of a whole";
        question[3][1][3][2] = "A decimal";
        question[3][1][3][3] = "A negative number";
        question[3][1][3][4] = "Part of a whole";
        question[3][1][3][5] = "A whole number";
        question[3][1][3][6] = "Fractions show division.";
        question[3][1][4][0] = "Why are parallel lines important in geometry?";
        question[3][1][4][1] = "They never intersect";
        question[3][1][4][2] = "They are perpendicular";
        question[3][1][4][3] = "They never intersect";
        question[3][1][4][4] = "They form curves";
        question[3][1][4][5] = "They always intersect";
        question[3][1][4][6] = "Parallel lines have equal slopes.";
        question[3][1][5][0] = "What does the Pythagorean theorem calculate?";
        question[3][1][5][1] = "Hypotenuse of a right triangle";
        question[3][1][5][2] = "Volume of a cube";
        question[3][1][5][3] = "Hypotenuse of a right triangle";
        question[3][1][5][4] = "Perimeter of a circle";
        question[3][1][5][5] = "Area of a triangle";
        question[3][1][5][6] = "It uses side lengths.";

        // Mathematics - Taxonomy Level 3: Applying (Medium)
        question[3][2][0][0] = "If a triangle has a base of 6 and height of 4, what is its area?";
        question[3][2][0][1] = "12 square units";
        question[3][2][0][2] = "18 square units";
        question[3][2][0][3] = "12 square units";
        question[3][2][0][4] = "24 square units";
        question[3][2][0][5] = "10 square units";
        question[3][2][0][6] = "Use the formula: 1/2 × base × height.";
        question[3][2][1][0] = "If you have 15 apples and divide them into 3 groups, how many in each?";
        question[3][2][1][1] = "5";
        question[3][2][1][2] = "4";
        question[3][2][1][3] = "6";
        question[3][2][1][4] = "5";
        question[3][2][1][5] = "3";
        question[3][2][1][6] = "Divide equally among groups.";
        question[3][2][2][0] = "If a rectangle’s length is 8 and width is 5, what is its perimeter?";
        question[3][2][2][1] = "26 units";
        question[3][2][2][2] = "20 units";
        question[3][2][2][3] = "13 units";
        question[3][2][2][4] = "26 units";
        question[3][2][2][5] = "40 units";
        question[3][2][2][6] = "Use: 2 × (length + width).";
        question[3][2][3][0] = "If a circle has a radius of 3, what is its area?";
        question[3][2][3][1] = "28.26 square units";
        question[3][2][3][2] = "37.68 square units";
        question[3][2][3][3] = "9 square units";
        question[3][2][3][4] = "28.26 square units";
        question[3][2][3][5] = "18.84 square units";
        question[3][2][3][6] = "Use: π × radius².";
        question[3][2][4][0] = "If 2x + 6 = 12, what is x?";
        question[3][2][4][1] = "3";
        question[3][2][4][2] = "9";
        question[3][2][4][3] = "3";
        question[3][2][4][4] = "2";
        question[3][2][4][5] = "6";
        question[3][2][4][6] = "Solve by isolating x.";
        question[3][2][5][0] = "If a right triangle has legs of 3 and 4, what is the hypotenuse?";
        question[3][2][5][1] = "5";
        question[3][2][5][2] = "8";
        question[3][2][5][3] = "5";
        question[3][2][5][4] = "6";
        question[3][2][5][5] = "7";
        question[3][2][5][6] = "Use: a² + b² = c².";

        // Mathematics - Taxonomy Level 4: Analyzing (Medium)
        question[3][3][1][0] = "How does a fraction differ from a decimal?";
        question[3][3][1][1] = "Fraction is a ratio, decimal is a number";
        question[3][3][1][2] = "Fraction is a number";
        question[3][3][1][3] = "Decimal is a ratio";
        question[3][3][1][4] = "Fraction is a ratio, decimal is a number";
        question[3][3][1][5] = "Both are the same";
        question[3][3][1][6] = "Representation differs.";
        question[3][3][2][0] = "What distinguishes mean from median?";
        question[3][3][2][1] = "Mean is average, median is middle value";
        question[3][3][2][2] = "Mean is middle value";
        question[3][3][2][3] = "Mean is average, median is middle value";
        question[3][3][2][4] = "Median is average";
        question[3][3][2][5] = "Both are the same";
        question[3][3][2][6] = "They measure central tendency.";
        question[3][3][3][0] = "How does a linear equation differ from a quadratic equation?";
        question[3][3][3][1] = "Linear is degree 1, quadratic is degree 2";
        question[3][3][3][2] = "Linear is degree 2";
        question[3][3][3][3] = "Quadratic is degree 1";
        question[3][3][3][4] = "Linear is degree 1, quadratic is degree 2";
        question[3][3][3][5] = "Both are the same";
        question[3][3][3][6] = "Degree affects graph";
    }

    void hard_questions()
    {
        // Initialize easy questions, answers, options, and explanations.

        // Science - Taxonomy Level 1: Remembering (Hard)
        question[0][0][0][0] = "What is the primary source of energy for Earth’s climate system?";
        question[0][0][0][1] = "Geothermal heat";
        question[0][0][0][2] = "Tidal energy";
        question[0][0][0][3] = "Solar radiation";
        question[0][0][0][4] = "Nuclear fusion";
        question[0][0][0][5] = "Solar radiation";
        question[0][0][0][6] = "It drives global weather patterns.";
        question[0][0][1][0] = "Which subatomic particle has no electric charge?";
        question[0][0][1][1] = "Proton";
        question[0][0][1][2] = "Neutron";
        question[0][0][1][3] = "Electron";
        question[0][0][1][4] = "Positron";
        question[0][0][1][5] = "Neutron";
        question[0][0][1][6] = "It resides in the nucleus.";
        question[0][0][2][0] = "What gas, discovered on the sun before Earth, is the second most abundant element in the universe?";
        question[0][0][2][1] = "Helium";
        question[0][0][2][2] = "Hydrogen";
        question[0][0][2][3] = "Oxygen";
        question[0][0][2][4] = "Nitrogen";
        question[0][0][2][5] = "Helium";
        question[0][0][2][6] = "It was found via spectroscopy.";
        question[0][0][3][0] = "What is the name of the process by which plants convert carbon dioxide and water into glucose?";
        question[0][0][3][1] = "Respiration";
        question[0][0][3][2] = "Transpiration";
        question[0][0][3][3] = "Photosynthesis";
        question[0][0][3][4] = "Fermentation";
        question[0][0][3][5] = "Photosynthesis";
        question[0][0][3][6] = "It uses sunlight as energy.";
        question[0][0][4][0] = "What is the SI unit for measuring thermodynamic temperature?";
        question[0][0][4][1] = "Kelvin";
        question[0][0][4][2] = "Celsius";
        question[0][0][4][3] = "Fahrenheit";
        question[0][0][4][4] = "Rankine";
        question[0][0][4][5] = "Kelvin";
        question[0][0][4][6] = "It starts at absolute zero.";
        question[0][0][5][0] = "Which level of electromagnetic radiation has the shortest wavelength?";
        question[0][0][5][1] = "X-rays";
        question[0][0][5][2] = "Gamma rays";
        question[0][0][5][3] = "Ultraviolet";
        question[0][0][5][4] = "Microwaves";
        question[0][0][5][5] = "Gamma rays";
        question[0][0][5][6] = "Wavelengths decrease with energy.";

        // Science - Taxonomy Level 2: Understanding (Hard)
        question[0][1][0][0] = "Why does the greenhouse effect warm the Earth?";
        question[0][1][0][1] = "Gases block ultraviolet rays";
        question[0][1][0][2] = "Gases trap infrared radiation";
        question[0][1][0][3] = "Gases reflect sunlight";
        question[0][1][0][4] = "Gases increase air pressure";
        question[0][1][0][5] = "Gases trap infrared radiation";
        question[0][1][0][6] = "Carbon dioxide plays a key role.";
        question[0][1][1][0] = "What causes the Coriolis effect?";
        question[0][1][1][1] = "Earth’s rotation";
        question[0][1][1][2] = "Earth’s tilt";
        question[0][1][1][3] = "Solar radiation";
        question[0][1][1][4] = "Ocean currents";
        question[0][1][1][5] = "Earth’s rotation";
        question[0][1][1][6] = "It deflects moving objects.";
        question[0][1][2][0] = "Why do noble gases rarely form compounds?";
        question[0][1][2][1] = "They lack electrons";
        question[0][1][2][2] = "They have full electron shells";
        question[0][1][2][3] = "They are highly reactive";
        question[0][1][2][4] = "They form ionic bonds";
        question[0][1][2][5] = "They have full electron shells";
        question[0][1][2][6] = "Stable electron configurations resist bonding.";
        question[0][1][3][0] = "What explains the Doppler effect in sound waves?";
        question[0][1][3][1] = "Change in amplitude";
        question[0][1][3][2] = "Change in frequency due to relative motion";
        question[0][1][3][3] = "Change in medium density";
        question[0][1][3][4] = "Change in wave speed";
        question[0][1][3][5] = "Change in frequency due to relative motion";
        question[0][1][3][6] = "It affects pitch of moving sources.";
        question[0][1][4][0] = "Why do some stars appear brighter than others?";
        question[0][1][4][1] = "They are smaller";
        question[0][1][4][2] = "They are closer or more luminous";
        question[0][1][4][3] = "They are colder";
        question[0][1][4][4] = "They are denser";
        question[0][1][4][5] = "They are closer or more luminous";
        question[0][1][4][6] = "Brightness depends on distance and energy.";
        question[0][1][5][0] = "What causes superconductivity at low temperatures?";
        question[0][1][5][1] = "Electrons gain mass";
        question[0][1][5][2] = "Electrons form pairs with zero resistance";
        question[0][1][5][3] = "Protons stop moving";
        question[0][1][5][4] = "Atoms vibrate faster";
        question[0][1][5][5] = "Electrons form pairs with zero resistance";
        question[0][1][5][6] = "It occurs in certain materials.";

        // Science - Taxonomy Level 3: Applying (Hard)
        question[0][2][0][0] = "If a star’s light is redshifted, what can you infer about its motion?";
        question[0][2][0][1] = "It is moving closer";
        question[0][2][0][2] = "It is moving away";
        question[0][2][0][3] = "It is stationary";
        question[0][2][0][4] = "It is rotating";
        question[0][2][0][5] = "It is moving away";
        question[0][2][0][6] = "Redshift indicates increasing distance.";
        question[0][2][1][0] = "If a circuit has a 24V battery, 6Ω resistor, and 2A current, what is the total resistance?";
        question[0][2][1][1] = "6Ω";
        question[0][2][1][2] = "12Ω";
        question[0][2][1][3] = "8Ω";
        question[0][2][1][4] = "24Ω";
        question[0][2][1][5] = "12Ω";
        question[0][2][1][6] = "Use Ohm’s Law: V = IR.";
        question[0][2][2][0] = "If a gas is compressed at constant temperature, what happens to its pressure?";
        question[0][2][2][1] = "It decreases";
        question[0][2][2][2] = "It increases";
        question[0][2][2][3] = "It stays the same";
        question[0][2][2][4] = "It becomes zero";
        question[0][2][2][5] = "It increases";
        question[0][2][2][6] = "Boyle’s Law applies here.";
        question[0][2][3][0] = "If a plant is exposed to only green light, what will happen to its growth?";
        question[0][2][3][1] = "It will grow normally";
        question[0][2][3][2] = "It will grow poorly";
        question[0][2][3][3] = "It will grow faster";
        question[0][2][3][4] = "It will stop growing";
        question[0][2][3][5] = "It will grow poorly";
        question[0][2][3][6] = "Plants absorb red and blue light best.";
        question[0][2][4][0] = "If an object’s velocity is 10 m/s and it accelerates at 2 m/s² for 5 seconds, what is its final velocity?";
        question[0][2][4][1] = "15 m/s";
        question[0][2][4][2] = "20 m/s";
        question[0][2][4][3] = "25 m/s";
        question[0][2][4][4] = "10 m/s";
        question[0][2][4][5] = "20 m/s";
        question[0][2][4][6] = "Use: v = u + at.";
        question[0][2][5][0] = "If a solution has a pH of 2, what is its hydrogen ion concentration?";
        question[0][2][5][1] = "0.1 mol/L";
        question[0][2][5][2] = "0.01 mol/L";
        question[0][2][5][3] = "0.001 mol/L";
        question[0][2][5][4] = "1 mol/L";
        question[0][2][5][5] = "0.01 mol/L";
        question[0][2][5][6] = "pH = -log[H⁺].";

        // Science - Taxonomy Level 4: Analyzing (Hard)
        question[0][3][0][0] = "What distinguishes a covalent bond from an ionic bond?";
        question[0][3][0][1] = "Ionic shares electrons";
        question[0][3][0][2] = "Covalent shares electrons, ionic transfers them";
        question[0][3][0][3] = "Both transfer electrons";
        question[0][3][0][4] = "Both are the same";
        question[0][3][0][5] = "Covalent shares electrons, ionic transfers them";
        question[0][3][0][6] = "Bond level depends on electron behavior.";
        question[0][3][1][0] = "How does nuclear fusion differ from nuclear fission?";
        question[0][3][1][1] = "Fission combines nuclei";
        question[0][3][1][2] = "Fusion combines nuclei, fission splits them";
        question[0][3][1][3] = "Both split nuclei";
        question[0][3][1][4] = "Both are the same";
        question[0][3][1][5] = "Fusion combines nuclei, fission splits them";
        question[0][3][1][6] = "Fusion powers stars.";
        question[0][3][2][0] = "What is the key difference between prokaryotic and eukaryotic cells?";
        question[0][3][2][1] = "Prokaryotes have a nucleus";
        question[0][3][2][2] = "Eukaryotes have a nucleus, prokaryotes do not";
        question[0][3][2][3] = "Both lack a nucleus";
        question[0][3][2][4] = "Both are the same";
        question[0][3][2][5] = "Eukaryotes have a nucleus, prokaryotes do not";
        question[0][3][2][6] = "Nucleus stores DNA.";
        question[0][3][3][0] = "How does convection differ from conduction in heat transfer?";
        question[0][3][3][1] = "Conduction involves fluid motion";
        question[0][3][3][2] = "Convection involves fluid motion, conduction does not";
        question[0][3][3][3] = "Both involve fluid motion";
        question[0][3][3][4] = "Both are the same";
        question[0][3][3][5] = "Convection involves fluid motion, conduction does not";
        question[0][3][3][6] = "Fluids carry heat in convection.";
        question[0][3][4][0] = "What distinguishes a supernova from a neutron star?";
        question[0][3][4][1] = "Neutron star is an explosion";
        question[0][3][4][2] = "Supernova is an explosion, neutron star is a remnant";
        question[0][3][4][3] = "Both are explosions";
        question[0][3][4][4] = "Both are the same";
        question[0][3][4][5] = "Supernova is an explosion, neutron star is a remnant";
        question[0][3][4][6] = "Supernovae create neutron stars.";
        question[0][3][5][0] = "How does an exothermic reaction differ from an endothermic reaction?";
        question[0][3][5][1] = "Endothermic releases heat";
        question[0][3][5][2] = "Exothermic releases heat, endothermic absorbs it";
        question[0][3][5][3] = "Both absorb heat";
        question[0][3][5][4] = "Both are the same";
        question[0][3][5][5] = "Exothermic releases heat, endothermic absorbs it";
        question[0][3][5][6] = "Heat flow defines reaction level.";

        // Science - Taxonomy Level 5: Evaluating (Hard)
        question[0][4][0][0] = "Which is the most effective method to reduce greenhouse gas emissions?";
        question[0][4][0][1] = "Increase fossil fuel use";
        question[0][4][0][2] = "Transition to renewable energy";
        question[0][4][0][3] = "Reduce forest cover";
        question[0][4][0][4] = "Ignore emissions";
        question[0][4][0][5] = "Transition to renewable energy";
        question[0][4][0][6] = "Renewables produce less CO₂.";
        question[0][4][1][0] = "Which is the best way to measure the age of a fossil?";
        question[0][4][1][1] = "Tree ring counting";
        question[0][4][1][2] = "Carbon-14 dating";
        question[0][4][1][3] = "Rock layer analysis";
        question[0][4][1][4] = "Visual estimation";
        question[0][4][1][5] = "Carbon-14 dating";
        question[0][4][1][6] = "Carbon-14 decays predictably.";
        question[0][4][2][0] = "Which is the most reliable way to predict volcanic eruptions?";
        question[0][4][2][1] = "Measure air temperature";
        question[0][4][2][2] = "Monitor seismic activity";
        question[0][4][2][3] = "Observe cloud patterns";
        question[0][4][2][4] = "Check ocean levels";
        question[0][4][2][5] = "Monitor seismic activity";
        question[0][4][2][6] = "Earthquakes signal magma movement.";
        question[0][4][3][0] = "Which is the best method to prevent antibiotic resistance?";
        question[0][4][3][1] = "Increase antibiotic use";
        question[0][4][3][2] = "Limit antibiotic overuse";
        question[0][4][3][3] = "Avoid vaccinations";
        question[0][4][3][4] = "Use expired drugs";
        question[0][4][3][5] = "Limit antibiotic overuse";
        question[0][4][3][6] = "Overuse strengthens bacteria.";
        question[0][4][4][0] = "Which is the most effective way to study distant galaxies?";
        question[0][4][4][1] = "Use microscopes";
        question[0][4][4][2] = "Use radio telescopes";
        question[0][4][4][3] = "Use binoculars";
        question[0][4][4][4] = "Use cameras";
        question[0][4][4][5] = "Use radio telescopes";
        question[0][4][4][6] = "Radio waves reveal cosmic structures.";
        question[0][4][5][0] = "Which is the best way to purify contaminated water?";
        question[0][4][5][1] = "Boiling alone";
        question[0][4][5][2] = "Reverse osmosis";
        question[0][4][5][3] = "Adding sugar";
        question[0][4][5][4] = "Freezing";
        question[0][4][5][5] = "Reverse osmosis";
        question[0][4][5][6] = "Membranes remove impurities.";

        // Science - Taxonomy Level 6: Creating (Hard)
        question[0][5][0][0] = "Design an experiment to test the effect of pH on enzyme activity.";
        question[0][5][0][1] = "Change temperature only";
        question[0][5][0][2] = "Vary pH levels and measure reaction rates";
        question[0][5][0][3] = "Use different enzymes";
        question[0][5][0][4] = "Ignore pH levels";
        question[0][5][0][5] = "Vary pH levels and measure reaction rates";
        question[0][5][0][6] = "Enzymes have optimal pH ranges.";
        question[0][5][1][0] = "Propose a system to harness tidal energy.";
        question[0][5][1][1] = "Use solar panels";
        question[0][5][1][2] = "Use underwater turbines";
        question[0][5][1][3] = "Use windmills";
        question[0][5][1][4] = "Use coal plants";
        question[0][5][1][5] = "Use underwater turbines";
        question[0][5][1][6] = "Tides provide consistent energy.";
        question[0][5][2][0] = "Create a model to predict climate change impacts.";
        question[0][5][2][1] = "Focus on animal behavior";
        question[0][5][2][2] = "Include temperature and sea level data";
        question[0][5][2][3] = "Use only wind data";
        question[0][5][2][4] = "Ignore measurements";
        question[0][5][2][5] = "Include temperature and sea level data";
        question[0][5][2][6] = "Models use multiple variables.";
        question[0][5][3][0] = "Design a device to measure atmospheric CO₂ levels.";
        question[0][5][3][1] = "Use thermometers";
        question[0][5][3][2] = "Use infrared gas analyzers";
        question[0][5][3][3] = "Use barometers";
        question[0][5][3][4] = "Use hydrometers";
        question[0][5][3][5] = "Use infrared gas analyzers";
        question[0][5][3][6] = "CO₂ absorbs infrared light.";
        question[0][5][4][0] = "Plan a campaign to promote biodiversity.";
        question[0][5][4][1] = "Increase urban development";
        question[0][5][4][2] = "Protect habitats and educate communities";
        question[0][5][4][3] = "Cut down forests";
        question[0][5][4][4] = "Promote monoculture";
        question[0][5][4][5] = "Protect habitats and educate communities";
        question[0][5][4][6] = "Biodiversity supports ecosystems.";
        question[0][5][5][0] = "Create a diagram of the carbon cycle.";
        question[0][5][5][1] = "Draw only plants";
        question[0][5][5][2] = "Show carbon movement through ecosystems";
        question[0][5][5][3] = "List temperatures";
        question[0][5][5][4] = "Show one process";
        question[0][5][5][5] = "Show carbon movement through ecosystems";
        question[0][5][5][6] = "Carbon cycles through air, land, and sea.";

        // History - Taxonomy Level 1: Remembering (Hard)
        question[1][0][0][0] = "In which year was the Treaty of Tordesillas signed?";
        question[1][0][0][1] = "1519";
        question[1][0][0][2] = "1494";
        question[1][0][0][3] = "1453";
        question[1][0][0][4] = "1600";
        question[1][0][0][5] = "1494";
        question[1][0][0][6] = "It divided the New World.";
        question[1][0][1][0] = "Who led the Haitian Revolution?";
        question[1][0][1][1] = "Simon Bolivar";
        question[1][0][1][2] = "Toussaint Louverture";
        question[1][0][1][3] = "Napoleon Bonaparte";
        question[1][0][1][4] = "George Washington";
        question[1][0][1][5] = "Toussaint Louverture";
        question[1][0][1][6] = "It led to Haiti’s independence.";
        question[1][0][2][0] = "What was the name of the code of laws created by Napoleon?";
        question[1][0][2][1] = "Code of Hammurabi";
        question[1][0][2][2] = "Napoleonic Code";
        question[1][0][2][3] = "Magna Carta";
        question[1][0][2][4] = "Justinian Code";
        question[1][0][2][5] = "Napoleonic Code";
        question[1][0][2][6] = "It influenced modern legal systems.";
        question[1][0][3][0] = "Which empire built the Great Wall of China?";
        question[1][0][3][1] = "Qing Dynasty";
        question[1][0][3][2] = "Ming Dynasty";
        question[1][0][3][3] = "Han Dynasty";
        question[1][0][3][4] = "Tang Dynasty";
        question[1][0][3][5] = "Ming Dynasty";
        question[1][0][3][6] = "It was built for defense.";
        question[1][0][4][0] = "Who was the first woman to win a Nobel Peace Prize?";
        question[1][0][4][1] = "Marie Curie";
        question[1][0][4][2] = "Bertha von Suttner";
        question[1][0][4][3] = "Jane Addams";
        question[1][0][4][4] = "Mother Teresa";
        question[1][0][4][5] = "Bertha von Suttner";
        question[1][0][4][6] = "She won in 1905.";
        question[1][0][5][0] = "What was the name of the ship that carried the Pilgrims to America in 1620?";
        question[1][0][5][1] = "Santa Maria";
        question[1][0][5][2] = "Mayflower";
        question[1][0][5][3] = "Nina";
        question[1][0][5][4] = "Pinta";
        question[1][0][5][5] = "Mayflower";
        question[1][0][5][6] = "It landed at Plymouth.";

        // History - Taxonomy Level 2: Understanding (Hard)
        question[1][1][0][0] = "Why did the Treaty of Tordesillas cause disputes?";
        question[1][1][0][1] = "It banned exploration";
        question[1][1][0][2] = "It divided land without clear boundaries";
        question[1][1][0][3] = "It united empires";
        question[1][1][0][4] = "It ended trade";
        question[1][1][0][5] = "It divided land without clear boundaries";
        question[1][1][0][6] = "Spain and Portugal disagreed.";
        question[1][1][1][0] = "What was the main goal of the Haitian Revolution?";
        question[1][1][1][1] = "Expand French control";
        question[1][1][1][2] = "End slavery and gain independence";
        question[1][1][1][3] = "Increase trade";
        question[1][1][1][4] = "Build cities";
        question[1][1][1][5] = "End slavery and gain independence";
        question[1][1][1][6] = "It was a slave revolt.";
        question[1][1][2][0] = "Why was the Napoleonic Code significant?";
        question[1][1][2][1] = "It banned trade";
        question[1][1][2][2] = "It standardized laws across Europe";
        question[1][1][2][3] = "It ended wars";
        question[1][1][2][4] = "It limited rights";
        question[1][1][2][5] = "It standardized laws across Europe";
        question[1][1][2][6] = "It influenced legal systems.";
        question[1][1][3][0] = "What was the purpose of the Great Wall during the Ming Dynasty?";
        question[1][1][3][1] = "Promote trade";
        question[1][1][3][2] = "Protect against invasions";
        question[1][1][3][3] = "Mark borders";
        question[1][1][3][4] = "Build cities";
        question[1][1][3][5] = "Protect against invasions";
        question[1][1][3][6] = "It defended against Mongols.";
        question[1][1][4][0] = "Why was the Berlin Conference of 1884–1885 important?";
        question[1][1][4][1] = "It ended colonialism";
        question[1][1][4][2] = "It divided Africa among European powers";
        question[1][1][4][3] = "It promoted African unity";
        question[1][1][4][4] = "It banned trade";
        question[1][1][4][5] = "It divided Africa among European powers";
        question[1][1][4][6] = "It led to colonial borders.";
        question[1][1][5][0] = "What caused the fall of the Roman Empire?";
        question[1][1][5][1] = "Technological advances";
        question[1][1][5][2] = "Economic decline and invasions";
        question[1][1][5][3] = "Strong leadership";
        question[1][1][5][4] = "Increased trade";
        question[1][1][5][5] = "Economic decline and invasions";
        question[1][1][5][6] = "Multiple factors weakened it.";

        // History - Taxonomy Level 3: Applying (Hard)
        question[1][2][0][0] = "If you were a diplomat in 1494, how would you enforce the Treaty of Tordesillas?";
        question[1][2][0][1] = "Ban all exploration";
        question[1][2][0][2] = "Use maps and naval patrols";
        question[1][2][0][3] = "Build walls";
        question[1][2][0][4] = "Ignore boundaries";
        question[1][2][0][5] = "Use maps and naval patrols";
        question[1][2][0][6] = "Clear borders were needed.";
        question[1][2][1][0] = "If you were in the Haitian Revolution, what would you do to support it?";
        question[1][2][1][1] = "Support French rule";
        question[1][2][1][2] = "Organize resistance groups";
        question[1][2][1][3] = "Increase taxes";
        question[1][2][1][4] = "Build plantations";
        question[1][2][1][5] = "Organize resistance groups";
        question[1][2][1][6] = "Resistance fought for freedom.";
        question[1][2][2][0] = "If you were a lawyer using the Napoleonic Code, what would you focus on?";
        question[1][2][2][1] = "Royal privileges";
        question[1][2][2][2] = "Equal property rights";
        question[1][2][2][3] = "Military laws";
        question[1][2][2][4] = "Religious rules";
        question[1][2][2][5] = "Equal property rights";
        question[1][2][2][6] = "It emphasized legal equality.";
        question[1][2][3][0] = "If you were defending the Great Wall, what strategy would you use?";
        question[1][2][3][1] = "Open all gates";
        question[1][2][3][2] = "Station troops at key points";
        question[1][2][3][3] = "Abandon the wall";
        question[1][2][3][4] = "Build more walls";
        question[1][2][3][5] = "Station troops at key points";
        question[1][2][3][6] = "Strategic points were fortified.";
        question[1][2][4][0] = "If you were at the Berlin Conference, what would you propose?";
        question[1][2][4][1] = "Divide randomly";
        question[1][2][4][2] = "Negotiate fair boundaries";
        question[1][2][4][3] = "Ban colonization";
        question[1][2][4][4] = "Ignore Africa";
        question[1][2][4][5] = "Negotiate fair boundaries";
        question[1][2][4][6] = "Borders caused conflicts.";
        question[1][2][5][0] = "If you lived in the Roman Empire, how would you address its decline?";
        question[1][2][5][1] = "Increase taxes";
        question[1][2][5][2] = "Strengthen economy and defenses";
        question[1][2][5][3] = "Expand rapidly";
        question[1][2][5][4] = "Ignore invasions";
        question[1][2][5][5] = "Strengthen economy and defenses";
        question[1][2][5][6] = "Multiple issues needed addressing.";

        // History - Taxonomy Level 4: Analyzing (Hard)
        question[1][3][0][0] = "What was the key difference between the Haitian and American Revolutions?";
        question[1][3][0][1] = "Both focused on slavery";
        question[1][3][0][2] = "Haitian focused on slavery, American on independence";
        question[1][3][0][3] = "Both were identical";
        question[1][3][0][4] = "American focused on slavery";
        question[1][3][0][5] = "Haitian focused on slavery, American on independence";
        question[1][3][0][6] = "Social issues shaped outcomes.";
        question[1][3][1][0] = "How did the Napoleonic Code differ from feudal laws?";
        question[1][3][1][1] = "Feudal laws abolished privileges";
        question[1][3][1][2] = "It abolished privileges, feudal laws upheld them";
        question[1][3][1][3] = "Both were identical";
        question[1][3][1][4] = "Code upheld privileges";
        question[1][3][1][5] = "It abolished privileges, feudal laws upheld them";
        question[1][3][1][6] = "Equality was a key change.";
        question[1][3][2][0] = "What distinguished the Ming Dynasty’s Great Wall from earlier walls?";
        question[1][3][2][1] = "Earlier used brick";
        question[1][3][2][2] = "Ming used brick and stone, earlier used earth";
        question[1][3][2][3] = "Both were identical";
        question[1][3][2][4] = "Ming used earth";
        question[1][3][2][5] = "Ming used brick and stone, earlier used earth";
        question[1][3][2][6] = "Materials improved durability.";
        question[1][3][3][0] = "How did the Berlin Conference differ from earlier colonial agreements?";
        question[1][3][3][1] = "Others divided Africa";
        question[1][3][3][2] = "It formalized Africa’s division, others were regional";
        question[1][3][3][3] = "Both were identical";
        question[1][3][3][4] = "Conference was regional";
        question[1][3][3][5] = "It formalized Africa’s division, others were regional";
        question[1][3][3][6] = "It involved multiple powers.";
        question[1][3][4][0] = "What was the main difference between the Roman and Byzantine Empires?";
        question[1][3][4][1] = "Roman was Eastern";
        question[1][3][4][2] = "Byzantine was Eastern, Roman was unified";
        question[1][3][4][3] = "Both were identical";
        question[1][3][4][4] = "Byzantine was unified";
        question[1][3][4][5] = "Byzantine was Eastern, Roman was unified";
        question[1][3][4][6] = "Byzantine continued Roman legacy.";
        question[1][3][5][0] = "How did World War I’s causes differ from World War II’s?";
        question[1][3][5][1] = "Both were alliances";
        question[1][3][5][2] = "World War I was alliances, World War II was ideology";
        question[1][3][5][3] = "Both were identical";
        question[1][3][5][4] = "World War II was alliances";
        question[1][3][5][5] = "World War I was alliances, World War II was ideology";
        question[1][3][5][6] = "Causes shaped global impact.";

        // History - Taxonomy Level 5: Evaluating (Hard)
        question[1][4][0][0] = "Which was the most significant outcome of the Haitian Revolution?";
        question[1][4][0][1] = "Increased French control";
        question[1][4][0][2] = "First Black-led republic";
        question[1][4][0][3] = "More plantations";
        question[1][4][0][4] = "Stronger slavery";
        question[1][4][0][5] = "First Black-led republic";
        question[1][4][0][6] = "It inspired other revolts.";
        question[1][4][1][0] = "Which was the most impactful effect of the Napoleonic Code?";
        question[1][4][1][1] = "Increased monarchy power";
        question[1][4][1][2] = "Spread of legal equality";
        question[1][4][1][3] = "More wars";
        question[1][4][1][4] = "Less trade";
        question[1][4][1][5] = "Spread of legal equality";
        question[1][4][1][6] = "It shaped modern laws.";
        question[1][4][2][0] = "Which was the best defense strategy for the Great Wall?";
        question[1][4][2][1] = "Open gates";
        question[1][4][2][2] = "Garrisons with signal towers";
        question[1][4][2][3] = "No troops";
        question[1][4][2][4] = "Single outpost";
        question[1][4][2][5] = "Garrisons with signal towers";
        question[1][4][2][6] = "Towers enabled quick response.";
        question[1][4][3][0] = "Which was the most significant impact of the Berlin Conference?";
        question[1][4][3][1] = "African independence";
        question[1][4][3][2] = "Colonial borders in Africa";
        question[1][4][3][3] = "Global trade bans";
        question[1][4][3][4] = "European unity";
        question[1][4][3][5] = "Colonial borders in Africa";
        question[1][4][3][6] = "Borders caused long-term conflicts.";
        question[1][4][4][0] = "Which was the most effective reform of the Progressive Era?";
        question[1][4][4][1] = "Increased taxes";
        question[1][4][4][2] = "Women’s suffrage";
        question[1][4][4][3] = "Banned unions";
        question[1][4][4][4] = "Child labor expansion";
        question[1][4][4][5] = "Women’s suffrage";
        question[1][4][4][6] = "It expanded voting rights.";
        question[1][4][5][0] = "Which was the most important cause of the Roman Empire’s fall?";
        question[1][4][5][1] = "Strong leadership";
        question[1][4][5][2] = "Economic instability";
        question[1][4][5][3] = "More trade";
        question[1][4][5][4] = "New technology";
        question[1][4][5][5] = "Economic instability";
        question[1][4][5][6] = "It weakened the empire.";

        // History - Taxonomy Level 6: Creating (Hard)
        question[1][5][0][0] = "Design a museum exhibit on the Haitian Revolution.";
        question[1][5][0][1] = "Display only weapons";
        question[1][5][0][2] = "Show leader artifacts and battle maps";
        question[1][5][0][3] = "Focus on trade";
        question[1][5][0][4] = "Show modern art";
        question[1][5][0][5] = "Show leader artifacts and battle maps";
        question[1][5][0][6] = "Exhibits highlight key figures.";
        question[1][5][1][0] = "Create a timeline of the Napoleonic Wars.";
        question[1][5][1][1] = "List only dates";
        question[1][5][1][2] = "Include major battles and treaties";
        question[1][5][1][3] = "Draw landscapes";
        question[1][5][1][4] = "Show one event";
        question[1][5][1][5] = "Include major battles and treaties";
        question[1][5][1][6] = "Timelines organize conflicts.";
        question[1][5][2][0] = "Propose a policy inspired by the Ming Dynasty.";
        question[1][5][2][1] = "Ban trade";
        question[1][5][2][2] = "Strengthen border defenses";
        question[1][5][2][3] = "Reduce taxes";
        question[1][5][2][4] = "Expand cities";
        question[1][5][2][5] = "Strengthen border defenses";
        question[1][5][2][6] = "Defense was a priority.";
        question[1][5][3][0] = "Design a monument for the Berlin Conference.";
        question[1][5][3][1] = "Display only flags";
        question[1][5][3][2] = "Show colonial impacts and African resistance";
        question[1][5][3][3] = "Focus on trade";
        question[1][5][3][4] = "Show modern cities";
        question[1][5][3][5] = "Show colonial impacts and African resistance";
        question[1][5][3][6] = "Monuments reflect history.";
        question[1][5][4][0] = "Create a documentary on the Roman Empire’s fall.";
        question[1][5][4][1] = "Focus on one event";
        question[1][5][4][2] = "Highlight economic and military causes";
        question[1][5][4][3] = "Show only art";
        question[1][5][4][4] = "List dates";
        question[1][5][4][5] = "Highlight economic and military causes";
        question[1][5][4][6] = "Documentaries explain complex events.";
        question[1][5][5][0] = "Plan a campaign to teach about the Progressive Era.";
        question[1][5][5][1] = "Show only wars";
        question[1][5][5][2] = "Focus on reforms and social change";
        question[1][5][5][3] = "List inventions";
        question[1][5][5][4] = "Ignore reforms";
        question[1][5][5][5] = "Focus on reforms and social change";
        question[1][5][5][6] = "Reforms shaped society.";

        // Geography - Taxonomy Level 1: Remembering (Hard)
        question[2][0][0][0] = "What is the deepest point in the Pacific Ocean?";
        question[2][0][0][1] = "Tonga Trench";
        question[2][0][0][2] = "Mariana Trench";
        question[2][0][0][3] = "Kermadec Trench";
        question[2][0][0][4] = "Philippine Trench";
        question[2][0][0][5] = "Mariana Trench";
        question[2][0][0][6] = "It reaches over 10,000 meters.";
        question[2][0][1][0] = "Which African country has the most active volcanoes?";
        question[2][0][1][1] = "Ethiopia";
        question[2][0][1][2] = "Democratic Republic of Congo";
        question[2][0][1][3] = "Kenya";
        question[2][0][1][4] = "South Africa";
        question[2][0][1][5] = "Democratic Republic of Congo";
        question[2][0][1][6] = "It lies in the Rift Valley.";
        question[2][0][2][0] = "What is the largest coral reef system in the world?";
        question[2][0][2][1] = "Belize Barrier Reef";
        question[2][0][2][2] = "Great Barrier Reef";
        question[2][0][2][3] = "Red Sea Coral Reef";
        question[2][0][2][4] = "Mesoamerican Reef";
        question[2][0][2][5] = "Great Barrier Reef";
        question[2][0][2][6] = "It is off Australia’s coast.";
        question[2][0][3][0] = "Which desert spans parts of Mongolia and China?";
        question[2][0][3][1] = "Taklamakan Desert";
        question[2][0][3][2] = "Gobi Desert";
        question[2][0][3][3] = "Kyzylkum Desert";
        question[2][0][3][4] = "Karakum Desert";
        question[2][0][3][5] = "Gobi Desert";
        question[2][0][3][6] = "It is in northern Asia.";
        question[2][0][4][0] = "What is the highest peak in South America?";
        question[2][0][4][1] = "Huascaran";
        question[2][0][4][2] = "Aconcagua";
        question[2][0][4][3] = "Chimborazo";
        question[2][0][4][4] = "Ojos del Salado";
        question[2][0][4][5] = "Aconcagua";
        question[2][0][4][6] = "It is in the Andes.";
        question[2][0][5][0] = "Which river is the second longest in Africa?";
        question[2][0][5][1] = "Nile River";
        question[2][0][5][2] = "Congo River";
        question[2][0][5][3] = "Zambezi River";
        question[2][0][5][4] = "Niger River";
        question[2][0][5][5] = "Congo River";
        question[2][0][5][6] = "It flows through central Africa.";

        // Geography - Taxonomy Level 2: Understanding (Hard)
        question[2][1][0][0] = "Why does the Mariana Trench have such high pressure?";
        question[2][1][0][1] = "Warm water increases pressure";
        question[2][1][0][2] = "Depth increases water weight";
        question[2][1][0][3] = "Low salinity reduces pressure";
        question[2][1][0][4] = "Currents reduce pressure";
        question[2][1][0][5] = "Depth increases water weight";
        question[2][1][0][6] = "Pressure rises with depth.";
        question[2][1][1][0] = "What causes the high volcanic activity in the Democratic Republic of Congo?";
        question[2][1][1][1] = "Plate convergence";
        question[2][1][1][2] = "Tectonic plate divergence";
        question[2][1][1][3] = "Stable plates";
        question[2][1][1][4] = "Ocean currents";
        question[2][1][1][5] = "Tectonic plate divergence";
        question[2][1][1][6] = "Rift Valley causes activity.";
        question[2][1][2][0] = "Why is the Great Barrier Reef vulnerable to climate change?";
        question[2][1][2][1] = "Lower temperatures help corals";
        question[2][1][2][2] = "Rising sea temperatures cause coral bleaching";
        question[2][1][2][3] = "More rainfall strengthens reefs";
        question[2][1][2][4] = "Stable pH protects corals";
        question[2][1][2][5] = "Rising sea temperatures cause coral bleaching";
        question[2][1][2][6] = "Heat stresses coral ecosystems.";
        question[2][1][3][0] = "What makes the Gobi Desert’s climate so extreme?";
        question[2][1][3][1] = "Low altitude and high rain";
        question[2][1][3][2] = "High altitude and low moisture";
        question[2][1][3][3] = "Stable temperatures";
        question[2][1][3][4] = "Dense vegetation";
        question[2][1][3][5] = "High altitude and low moisture";
        question[2][1][3][6] = "Aridity amplifies temperature swings.";
        question[2][1][4][0] = "Why is Aconcagua’s summit so challenging to climb?";
        question[2][1][4][1] = "Low altitude and heat";
        question[2][1][4][2] = "High altitude and low oxygen";
        question[2][1][4][3] = "Flat terrain";
        question[2][1][4][4] = "Dense forests";
        question[2][1][4][5] = "High altitude and low oxygen";
        question[2][1][4][6] = "Thin air affects breathing.";
        question[2][1][5][0] = "What causes the Congo River’s high biodiversity?";
        question[2][1][5][1] = "Desert surroundings";
        question[2][1][5][2] = "Dense rainforest and stable climate";
        question[2][1][5][3] = "Cold temperatures";
        question[2][1][5][4] = "Low water flow";
        question[2][1][5][5] = "Dense rainforest and stable climate";
        question[2][1][5][6] = "Rainforests support diverse life.";

        // Geography - Taxonomy Level 3: Applying (Hard)
        question[2][2][0][0] = "If a submarine is at 11,000 meters in the Mariana Trench, what pressure would it face?";
        question[2][2][0][1] = "100 atmospheres";
        question[2][2][0][2] = "About 1100 atmospheres";
        question[2][2][0][3] = "500 atmospheres";
        question[2][2][0][4] = "2000 atmospheres";
        question[2][2][0][5] = "About 1100 atmospheres";
        question[2][2][0][6] = "Pressure increases 1 atm per 10m.";
        question[2][2][1][0] = "If you are studying volcanoes in the Democratic Republic of Congo, what region would you visit?";
        question[2][2][1][1] = "Sahara Desert";
        question[2][2][1][2] = "Virunga Mountains";
        question[2][2][1][3] = "Kalahari Basin";
        question[2][2][1][4] = "Nile Delta";
        question[2][2][1][5] = "Virunga Mountains";
        question[2][2][1][6] = "It is in the Rift Valley.";
        question[2][2][2][0] = "If you want to protect the Great Barrier Reef, what would you monitor?";
        question[2][2][2][1] = "Air pressure";
        question[2][2][2][2] = "Sea temperature and pH";
        question[2][2][2][3] = "Wind speed";
        question[2][2][2][4] = "Soil quality";
        question[2][2][2][5] = "Sea temperature and pH";
        question[2][2][2][6] = "Corals are sensitive to heat and acid.";
        question[2][2][3][0] = "If you are crossing the Gobi Desert, what would you prepare for?";
        question[2][2][3][1] = "Heavy rainfall";
        question[2][2][3][2] = "Extreme temperature swings";
        question[2][2][3][3] = "Dense forests";
        question[2][2][3][4] = "Stable weather";
        question[2][2][3][5] = "Extreme temperature swings";
        question[2][2][3][6] = "Deserts have hot days, cold nights.";
        question[2][2][4][0] = "If you climb Aconcagua, what equipment would you need?";
        question[2][2][4][1] = "Swimming gear";
        question[2][2][4][2] = "Oxygen tanks and warm clothing";
        question[2][2][4][3] = "Light clothing";
        question[2][2][4][4] = "No equipment";
        question[2][2][4][5] = "Oxygen tanks and warm clothing";
        question[2][2][4][6] = "High altitude requires preparation.";
        question[2][2][5][0] = "If you study fish in the Congo River, what would you expect?";
        question[2][2][5][1] = "Few species";
        question[2][2][5][2] = "High species diversity";
        question[2][2][5][3] = "No fish";
        question[2][2][5][4] = "Only large fish";
        question[2][2][5][5] = "High species diversity";
        question[2][2][5][6] = "Rainforests boost river diversity.";

        // Geography - Taxonomy Level 4: Analyzing (Hard)
        question[2][3][0][0] = "What distinguishes the Mariana Trench from other ocean trenches?";
        question[2][3][0][1] = "It is the shallowest";
        question[2][3][0][2] = "It is the deepest";
        question[2][3][0][3] = "It is the widest";
        question[2][3][0][4] = "It is the same";
        question[2][3][0][5] = "It is the deepest";
        question[2][3][0][6] = "Depth sets it apart.";
        question[2][3][1][0] = "How does the Great Barrier Reef differ from other coral reefs?";
        question[2][3][1][1] = "It is the smallest";
        question[2][3][1][2] = "It is the largest and most biodiverse";
        question[2][3][1][3] = "It is less diverse";
        question[2][3][1][4] = "It is the same";
        question[2][3][1][5] = "It is the largest and most biodiverse";
        question[2][3][1][6] = "Size and species variety define it.";
        question[2][3][2][0] = "What makes the Gobi Desert different from the Sahara?";
        question[2][3][2][1] = "Sahara is colder";
        question[2][3][2][2] = "Gobi is colder, Sahara is hotter";
        question[2][3][2][3] = "Both are the same";
        question[2][3][2][4] = "Gobi is hotter";
        question[2][3][2][5] = "Gobi is colder, Sahara is hotter";
        question[2][3][2][6] = "Climate shapes desert levels.";
        question[2][3][3][0] = "How does Aconcagua differ from Mount Everest?";
        question[2][3][3][1] = "Everest is shorter";
        question[2][3][3][2] = "Aconcagua is shorter and in South America";
        question[2][3][3][3] = "Both are the same";
        question[2][3][3][4] = "Aconcagua is taller";
        question[2][3][3][5] = "Aconcagua is shorter and in South America";
        question[2][3][3][6] = "Location and height differ.";
        question[2][3][4][0] = "What distinguishes the Congo River from the Nile?";
        question[2][3][4][1] = "Nile has more volume";
        question[2][3][4][2] = "Congo is shorter but has more volume";
        question[2][3][4][3] = "Both are the same";
        question[2][3][4][4] = "Congo is longer";
        question[2][3][4][5] = "Congo is shorter but has more volume";
        question[2][3][4][6] = "Water flow sets them apart.";
        question[2][3][5][0] = "How does a volcanic island differ from a continental island?";
        question[2][3][5][1] = "Both form from eruptions";
        question[2][3][5][2] = "Volcanic forms from eruptions, continental from land separation";
        question[2][3][5][3] = "Both are the same";
        question[2][3][5][4] = "Continental forms from eruptions";
        question[2][3][5][5] = "Volcanic forms from eruptions, continental from land separation";
        question[2][3][5][6] = "Formation processes differ.";

        // Geography - Taxonomy Level 5: Evaluating (Hard)
        question[2][4][0][0] = "Which is the most effective way to protect the Great Barrier Reef?";
        question[2][4][0][1] = "Increase fishing";
        question[2][4][0][2] = "Reduce carbon emissions globally";
        question[2][4][0][3] = "Build artificial reefs";
        question[2][4][0][4] = "Ignore bleaching";
        question[2][4][0][5] = "Reduce carbon emissions globally";
        question[2][4][0][6] = "Emissions drive coral bleaching.";
        question[2][4][1][0] = "Which is the best method to monitor volcanic activity in the Congo?";
        question[2][4][1][1] = "Observe animals";
        question[2][4][1][2] = "Use satellite and seismic sensors";
        question[2][4][1][3] = "Check rainfall";
        question[2][4][1][4] = "Measure air pressure";
        question[2][4][1][5] = "Use satellite and seismic sensors";
        question[2][4][1][6] = "Sensors detect ground movement.";
        question[2][4][2][0] = "Which is the most sustainable way to farm in the Gobi Desert?";
        question[2][4][2][1] = "Flood irrigation";
        question[2][4][2][2] = "Use hydroponics with solar power";
        question[2][4][2][3] = "Clear vegetation";
        question[2][4][2][4] = "Use heavy machinery";
        question[2][4][2][5] = "Use hydroponics with solar power";
        question[2][4][2][6] = "Water scarcity requires efficiency.";
        question[2][4][3][0] = "Which is the best way to climb Aconcagua safely?";
        question[2][4][3][1] = "Climb quickly";
        question[2][4][3][2] = "Acclimatize and use oxygen";
        question[2][4][3][3] = "Avoid gear";
        question[2][4][3][4] = "Ignore weather";
        question[2][4][3][5] = "Acclimatize and use oxygen";
        question[2][4][3][6] = "Altitude sickness is a risk.";
        question[2][4][4][0] = "Which is the most effective way to conserve the Congo River’s ecosystem?";
        question[2][4][4][1] = "Increase logging";
        question[2][4][4][2] = "Protect rainforests and regulate fishing";
        question[2][4][4][3] = "Build dams";
        question[2][4][4][4] = "Allow pollution";
        question[2][4][4][5] = "Protect rainforests and regulate fishing";
        question[2][4][4][6] = "Rainforests support river life.";
        question[2][4][5][0] = "Which is the best way to explore the Mariana Trench?";
        question[2][4][5][1] = "Use scuba gear";
        question[2][4][5][2] = "Use deep-sea submersibles";
        question[2][4][5][3] = "Use satellites";
        question[2][4][5][4] = "Use fishing boats";
        question[2][4][5][5] = "Use deep-sea submersibles";
        question[2][4][5][6] = "Submersibles handle high pressure.";

        // Geography - Taxonomy Level 6: Creating (Hard)
        question[2][5][0][0] = "Design a plan to restore the Great Barrier Reef.";
        question[2][5][0][1] = "Increase tourism";
        question[2][5][0][2] = "Reduce emissions and replant corals";
        question[2][5][0][3] = "Build artificial islands";
        question[2][5][0][4] = "Ignore bleaching";
        question[2][5][0][5] = "Reduce emissions and replant corals";
        question[2][5][0][6] = "Coral health depends on climate.";
        question[2][5][1][0] = "Create a monitoring system for Congo volcanoes.";
        question[2][5][1][1] = "Rely on visual checks";
        question[2][5][1][2] = "Use seismic sensors and drones";
        question[2][5][1][3] = "Use weather stations";
        question[2][5][1][4] = "Ignore data";
        question[2][5][1][5] = "Use seismic sensors and drones";
        question[2][5][1][6] = "Sensors predict eruptions.";
        question[2][5][2][0] = "Propose a sustainable city in the Gobi Desert.";
        question[2][5][2][1] = "Rely on fossil fuels";
        question[2][5][2][2] = "Use solar power and water recycling";
        question[2][5][2][3] = "Use river water";
        question[2][5][2][4] = "Build skyscrapers";
        question[2][5][2][5] = "Use solar power and water recycling";
        question[2][5][2][6] = "Sustainability is key in deserts.";
        question[2][5][3][0] = "Design a map of the Congo River basin.";
        question[2][5][3][1] = "Draw only cities";
        question[2][5][3][2] = "Show tributaries and rainforests";
        question[2][5][3][3] = "Show deserts";
        question[2][5][3][4] = "List animals";
        question[2][5][3][5] = "Show tributaries and rainforests";
        question[2][5][3][6] = "Maps show ecosystem connections.";
        question[2][5][4][0] = "Plan a climbing expedition to Aconcagua.";
        question[2][5][4][1] = "Climb without gear";
        question[2][5][4][2] = "Include acclimatization and safety protocols";
        question[2][5][4][3] = "Ignore weather";
        question[2][5][4][4] = "Rush the climb";
        question[2][5][4][5] = "Include acclimatization and safety protocols";
        question[2][5][4][6] = "Planning prevents risks.";
        question[2][5][5][0] = "Create a model of the Mariana Trench.";
        question[2][5][5][1] = "Draw flat land";
        question[2][5][5][2] = "Show depth and tectonic features";
        question[2][5][5][3] = "List fish species";
        question[2][5][5][4] = "Show surface only";
        question[2][5][5][5] = "Show depth and tectonic features";
        question[2][5][5][6] = "Models show ocean floor.";

        // Mathematics - Taxonomy Level 1: Remembering (Hard)
        question[3][0][0][0] = "What is the formula for the volume of a sphere?";
        question[3][0][0][1] = "πr²";
        question[3][0][0][2] = "(4/3)πr³";
        question[3][0][0][3] = "4πr²";
        question[3][0][0][4] = "(1/3)πr³";
        question[3][0][0][5] = "(4/3)πr³";
        question[3][0][0][6] = "It measures 3D space.";
        question[3][0][1][0] = "What is the value of sin(60°) in a right triangle?";
        question[3][0][1][1] = "1/2";
        question[3][0][1][2] = "√3/2";
        question[3][0][1][3] = "√2/2";
        question[3][0][1][4] = "1";
        question[3][0][1][5] = "√3/2";
        question[3][0][1][6] = "Use a 30-60-90 triangle.";
        question[3][0][2][0] = "What is the quadratic formula?";
        question[3][0][2][1] = "x = [-b ± √(b²+4ac)]/(2a)";
        question[3][0][2][2] = "x = [-b ± √(b²-4ac)]/(2a)";
        question[3][0][2][3] = "x = [b ± √(b²-4ac)]/(2a)";
        question[3][0][2][4] = "x = [-b ± √(b²-4ac)]/a";
        question[3][0][2][5] = "x = [-b ± √(b²-4ac)]/(2a)";
        question[3][0][2][6] = "It solves ax² + bx + c = 0.";
        question[3][0][3][0] = "What is the derivative of x³?";
        question[3][0][3][1] = "x²";
        question[3][0][3][2] = "3x²";
        question[3][0][3][3] = "3x";
        question[3][0][3][4] = "x³";
        question[3][0][3][5] = "3x²";
        question[3][0][3][6] = "Use the power rule.";
        question[3][0][4][0] = "What is the sum of angles in a hexagon?";
        question[3][0][4][1] = "540°";
        question[3][0][4][2] = "720°";
        question[3][0][4][3] = "360°";
        question[3][0][4][4] = "900°";
        question[3][0][4][5] = "720°";
        question[3][0][4][6] = "Use (n-2)×180°.";
        question[3][0][5][0] = "What is the formula for compound interest?";
        question[3][0][5][1] = "A = P(1 + r)^t";
        question[3][0][5][2] = "A = P(1 + r/n)^(nt)";
        question[3][0][5][3] = "A = Prt";
        question[3][0][5][4] = "A = P + rt";
        question[3][0][5][5] = "A = P(1 + r/n)^(nt)";
        question[3][0][5][6] = "It accounts for compounding.";

        // Mathematics - Taxonomy Level 2: Understanding (Hard)
        question[3][1][0][0] = "Why does the quadratic formula work?";
        question[3][1][0][1] = "It finds the vertex";
        question[3][1][0][2] = "It solves for roots by completing the square";
        question[3][1][0][3] = "It calculates area";
        question[3][1][0][4] = "It measures slope";
        question[3][1][0][5] = "It solves for roots by completing the square";
        question[3][1][0][6] = "It derives from ax² + bx + c = 0.";
        question[3][1][1][0] = "What does the derivative of a function represent?";
        question[3][1][1][1] = "Total area";
        question[3][1][1][2] = "Rate of change";
        question[3][1][1][3] = "Initial value";
        question[3][1][1][4] = "Constant term";
        question[3][1][1][5] = "Rate of change";
        question[3][1][1][6] = "It shows how y changes with x.";
        question[3][1][2][0] = "Why is the Pythagorean theorem limited to right triangles?";
        question[3][1][2][1] = "It applies to all triangles";
        question[3][1][2][2] = "Right angles create unique side relationships";
        question[3][1][2][3] = "It measures area";
        question[3][1][2][4] = "It finds angles";
        question[3][1][2][5] = "Right angles create unique side relationships";
        question[3][1][2][6] = "It relies on 90° angles.";
        question[3][1][3][0] = "What does the sine function represent in a unit circle?";
        question[3][1][3][1] = "X-coordinate of a point";
        question[3][1][3][2] = "Y-coordinate of a point";
        question[3][1][3][3] = "Radius length";
        question[3][1][3][4] = "Circle area";
        question[3][1][3][5] = "Y-coordinate of a point";
        question[3][1][3][6] = "Sine relates to angles.";
        question[3][1][4][0] = "Why does compound interest grow faster than simple interest?";
        question[3][1][4][1] = "It has a fixed rate";
        question[3][1][4][2] = "It earns interest on interest";
        question[3][1][4][3] = "It grows linearly";
        question[3][1][4][4] = "It uses a lower rate";
        question[3][1][4][5] = "It earns interest on interest";
        question[3][1][4][6] = "Compounding accelerates growth.";
        question[3][1][5][0] = "What does the volume of a sphere measure?";
        question[3][1][5][1] = "Surface area";
        question[3][1][5][2] = "Space inside a 3D sphere";
        question[3][1][5][3] = "Surface area";
        question[3][1][5][4] = "Circumference";
        question[3][1][5][5] = "Radius length";
        question[3][1][5][6] = "It uses the radius.";
    }

};

class Randomizer
{
private:
    int rand = 3;
    int number;
    int count = 0;
    time_t Time = time(0);
    void randomizer(int rand)
    {
        number = ((Time * rand) / 36248) % 6;
        number = abs(number);
    }

protected:
    int random_types[3];
    int random_questions[3];

public:
    void get_random_types()
    {

        while (count < SIZE)
        {
            rand *= 28;
            // Calling the randomizer functin.
            randomizer(rand);

            // Check for duplicates
            bool exist = false;

            for (int i = 0; i < count; i++)
            {
                if (random_types[i] == number)
                {
                    exist = true;
                    break;
                }
            }
            if (!exist)
            {
                random_types[count] = number;
                count++;
            }
        }
    }

    void get_randdom_question()
    {
        // Rest the count to 0.
        count = 0;

        while (count < SIZE)
        {
            rand *= 27;
            // Calling the randomizer functin.
            randomizer(rand);

            // Check for duplicates
            bool exist = false;

            for (int i = 0; i < count; i++)
            {
                if (random_questions[i] == number)
                {
                    exist = true;
                    break;
                }
            }
            if (!exist)
            {
                random_questions[count] = number;
                count++;
            }
        }
    }
};

class Display_Questions : public Questions, public Randomizer
{
private:
    bool easy_question = false;
    bool medium_question = false;
    bool hard_question = false;
    const int MAX_QUESTION = 9;
    int index_of_question = 0, index_of_type = 0;
    int current_question;
    int current_type;
    int selected_level;
    int question_no = 1;

public:
    void set_level()
    {
        if (current_level == 0)
            easy_question = true;
        else if (current_level == 1)
            medium_question = true;
        else if (current_level == 2)
            hard_question = true;
    }

    void display_question()
    {
        cout << "Displaying questions for level: " << level_names[current_level]
             << " and topic: " << topic_names[current_topic] << endl;
        cout << "Question " << question_no << " of " << MAX_QUESTION << ": \n";
        cout << question[current_topic][current_type][current_question][0] << endl;
        for (int i = 0; i < 4; i++) // Always 4 options
        {
            cout << char('A' + i) << ") " << question[current_topic][current_type][current_question][i + 2] << endl;
        }
    }

    // This function can be used to get questions based on the current level and topic.
    void get_questions()
    {
        // First get the type, then questions.
        current_type = random_types[index_of_type];
        current_question = random_questions[index_of_question];

        //  Display Question.
        display_question();
    }

    void ready_next_question()
    {
        index_of_question++;
        // Generate another Random number for more questions and topic.
        if (index_of_question == 3)
        {
            get_randdom_question();
            index_of_type++;
            index_of_question = 0; // Reset question index for the next type
        }
        // Increment the current question index
        question_no++;
    }

    // Getter function for current questions, and types.
    int get_current_question() const
    {
        return current_question;
    }
    int get_current_type() const
    {
        return current_type;
    }
    int get_question_no() const
    {
        return question_no;
    }
};

class Miscellaneous_Functions : public Questions
{
private:
    int current_type, current_Level, user_option;
    int current_question, current_topic, marks;
    int marks_part_1 = 0, marks_part_2 = 0, marks_part_3 = 0;
    int type_1, type_2, type_3;
    const int MAX_PARTS = 3;
    bool is_true_answer = false;

public:
    void initallizing_values(int option, int type, int level, int question, int topic)
    {
        user_option = option + 1;
        current_type = type;
        current_question = question;
        current_topic = topic;
        current_Level = level;
    }

    bool is_valid_input(string input, char range)
    {
        if (!isdigit(input[0]) || input.length() != 1 || input[0] < '1' || input[0] > range)
        {
            cout << "Invalid input! Please enter a number between 1 and " << range << ".\n";
            return false;
        }
        return true;
    }

    bool is_valid_option(string choice, int &option)
    {
        // Handle A–D input.
        if (choice.length() == 1 && toupper(choice[0]) >= 'A' && toupper(choice[0]) <= 'D')
        {
            option = toupper(choice[0]) - 'A' + 1; // Convert A–D to 1–4
            return true;
        }
        // Handdle 1-4 input.
        else if (choice[0] >= '1' && choice[0] <= '4' && choice.length() == 1)
        {
            option = choice[0] - '0';
            return true;
        }
        return false;
    }

    void check_answer()
    {
        // Initallizing the question for verifiction.
        if (question[current_topic][current_type][current_question][user_option] == question[current_topic][current_type][current_question][1])
        {
            cout << "Correct answer! Not bad.\n";
            is_true_answer = true;
        }

        else
        {
            cout << "Oh. That's Wrong answer! \nThe correct answer is: "
                 << question[current_topic][current_type][current_question][1] << endl;
        }
        cout << "Explaination: "
             << question[current_topic][current_type][current_question][6] << endl;
    }

    void calculate_marks(int question_No, int current_Topic)
    {
        //  Calculate marks.
        if (question_No <= 4)
        {
            type_1 = current_Topic;
            if (is_true_answer)
            {
                marks_part_1++;
            }
        }
        else if (question_No <= 7)
        {
            type_2 = current_Topic;
            if (is_true_answer)
            {
                marks_part_2++;
            }
        }
        else if (question_No <= 10)
        {
            type_3 = current_Topic;
            if (is_true_answer)
            {
                marks_part_3++;
            }
        }

        // Reset the true option.
        is_true_answer = false;

        if (question_No == 10)
        {
            cout << "Alright now you can see your result!!\n";
            cout << "--------------------------------------\n";
            cout << "           RESULT\n";
            cout << "--------------------------------------\n";
            cout << "Dificulty: " << level_names[current_Level] << endl;
            cout << "Topic: " << topic_names[current_topic] << endl;
            cout << "--------------------------------------\n";
            cout << "Taxanomy type: " << type_names[type_1] << endl;
            cout << "You answered correctly " << marks_part_1 << " questions out of 3.\n";
            cout << "-------------------------------------\n";
            cout << "Taxanomy type: " << type_names[type_2] << endl;
            cout << "You answered correctly " << marks_part_2 << " questions out of 3.\n";
            cout << "-------------------------------------\n";
            cout << "Taxanomy type: " << type_names[type_3] << endl;
            cout << "You answered correctly " << marks_part_3 << " questions out of 3.\n";
            cout << "-------------------------------------\n";
            cout << "-------------------------------------\n";

            cout << "Total marks: " << (marks_part_1 + marks_part_2 + marks_part_3) << " out of 9.\n";
            cout << "-------------------------------------\n";
            cout << "-------------------------------------\n";
        }
    }
};

int main()
{
    int level, topic, question, option, type, question_no = 0;
    char range;
    bool is_valid;
    string input, choice;
    bool main_loop = true, main_menu = true, selecting_level_menu = false;
    bool selecting_topic_menu = false, start_quiz = false;
    // Initalizing the other functions.
    Miscellaneous_Functions miscellaneous;

    while (main_loop)
    {
        // Display the menu.
        if (main_menu)
        {
            cout << "Welcome to Bloom's Taxonomy Quiz!\n";
            cout << "Please select an option:\n";
            cout << "1. Start Quiz\n";
            cout << "2. Exit\n";
            cout << "Enter your choice (1-2): ";
            cin >> input;

            // Check if the input is a valid number.
            range = '2';
            if (!(miscellaneous.is_valid_input(input, range)))
                continue;
            // Exit condition.
            else if (input[0] == '2')
            {
                cout << "Seems like you are too afraid to go on....Hope that you will be back!!\n";
                main_loop = false; // Exit the loop
            }
            else
            {
                main_menu = false;           // Proceed to level selection
                selecting_level_menu = true; // Enable level selection menu
            }
        }

        if (selecting_level_menu)
        {
            cout << "Enter the level Level:\n";
            cout << "1. Easy\n 2. Medium\n 3. Hard\n 4. Back to the Main Menu5.Exit\n";
            cout << "Enter your choice (1-4): ";
            cin >> input;

            // Check if the input is a valid number.
            range = '5';
            if (!(miscellaneous.is_valid_input(input, range)))
                continue;
            // Exit condition.
            else if (input[0] == '4')
            {
                main_menu = true;
                selecting_level_menu = false;
                continue;
            }
            else if (input[0] == '5')
            {
                cout << "Exiting the quiz. Thank you for playing!\n";
                main_loop = false; // Exit the loop
            }
            else
            {
                level = (input[0] - '1'); // Convert char to int
                selecting_level_menu = false;
                selecting_topic_menu = true;
            }
        }

        // Display level of courses.
        if (selecting_topic_menu)
        {
            cout << "Now slect the topic...\n";
            cout << "1. Science\n2. History\n3. Geography\n4. Mathematics\n";
            cout << "5. Back to the selecting Level Menu\n6. Exit\n";
            cout << "Enter your choice (1-5): ";
            cin >> input;

            // Validate topic choice.
            range = '6';
            if (!(miscellaneous.is_valid_input(input, range)))
                continue;
            else if (input[0] == '6')
            {
                cout << "So you are afriad!! I thought so...\n";
                break; // Exit the loop
            }
            else if (input[0] == '5')
            {
                selecting_topic_menu = false;
                selecting_level_menu = true;
                continue;
            }
            else
            {
                topic = (input[0] - '1');
                start_quiz = true;
            }
        }

        if (start_quiz)
        {
            // Initializing the variables.
            bool invalid_option = true, show__question = true;
            // Initalizing the quiz based on level and topic.
            Questions quiz;

            // Initallizing the random number for type and questions.
            Randomizer randomizer;
            Display_Questions display_Questions;
            display_Questions.get_random_types();

            // Selecting the random questions.
            display_Questions.get_randdom_question();

            // Selecting the level of questions.
            display_Questions.get_info(level, topic);
            display_Questions.set_level();

            // Updating the info of level.
            miscellaneous.selecting_level();
            display_Questions.selecting_level();

            // Starting the quiz..
            while (show__question)
            {
                invalid_option = true;
                while (invalid_option)
                {
                    // Show questions.
                    display_Questions.get_questions();

                    // Get user option info.
                    cout << "Acceptable entry: (A-D, a-d, 1-4)\n";
                    cout << "Choose wisely: ";
                    cin >> choice;

                    // Checking the valid input.
                    if (miscellaneous.is_valid_option(choice, option))
                        invalid_option = false;
                    else
                    {
                        cout << "Can you see? I gave you wide range of entery!!!\n";
                        continue;
                    }
                }

                // Ready next qeustion.
                display_Questions.ready_next_question();

                // Getting Random question and type, and current number question.
                question = display_Questions.get_current_question();
                type = display_Questions.get_current_type();
                question_no = display_Questions.get_question_no();

                // Display Quetions and options.
                miscellaneous.initallizing_values(option, type, level, question, topic);

                //  Check answer.
                miscellaneous.check_answer();

                // Calculate the result.
                miscellaneous.calculate_marks(question_no, type);

                //  Condition to stop quiz at question 9.
                if (question_no == 10)
                {
                    cout << "So tell me what's your next plan??\n";
                    cout << "=> Enter 1 to Play agian\n=> Enter anything to exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if (choice == "1")
                    {
                        show__question = false;
                        start_quiz = false;
                        main_menu = true;
                    }
                    else
                    {
                        main_loop = false;
                        show__question = false;
                        cout << "It was a pleasure to have you here!!\n";
                    }
                }
            }
        }
    }

    return 0;
}