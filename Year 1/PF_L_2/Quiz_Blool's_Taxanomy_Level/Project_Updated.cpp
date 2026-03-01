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
        question[0][0][0][2] = "H2O";
        question[0][0][0][3] = "CO2";
        question[0][0][0][4] = "O2";
        question[0][0][0][5] = "N2";
        question[0][0][0][6] = "Water is a compound made of hydrogen and oxygen.";
        question[0][0][1][0] = "What is the main source of energy for Earth?";
        question[0][0][1][1] = "The Sun";
        question[0][0][1][2] = "The Sun";
        question[0][0][1][3] = "The Moon";
        question[0][0][1][4] = "Wind";
        question[0][0][1][5] = "Water";
        question[0][0][1][6] = "The Sun provides heat and light to Earth.";
        question[0][0][2][0] = "What gas do humans breathe to survive?";
        question[0][0][2][1] = "Oxygen";
        question[0][0][2][2] = "Oxygen";
        question[0][0][2][3] = "Carbon dioxide";
        question[0][0][2][4] = "Nitrogen";
        question[0][0][2][5] = "Helium";
        question[0][0][2][6] = "Oxygen is essential for human respiration.";
        question[0][0][3][0] = "What is the unit of force in physics?";
        question[0][0][3][1] = "Newton";
        question[0][0][3][2] = "Newton";
        question[0][0][3][3] = "Joule";
        question[0][0][3][4] = "Watt";
        question[0][0][3][5] = "Volt";
        question[0][0][3][6] = "Named after Sir Isaac Newton, it measures force.";
        question[0][0][4][0] = "What is the freezing point of water in Celsius?";
        question[0][0][4][1] = "0 degrees";
        question[0][0][4][2] = "0 degrees";
        question[0][0][4][3] = "100 degrees";
        question[0][0][4][4] = "50 degrees";
        question[0][0][4][5] = "-10 degrees";
        question[0][0][4][6] = "Water turns to ice at this temperature.";
        question[0][0][5][0] = "What is the name of our planet?";
        question[0][0][5][1] = "Earth";
        question[0][0][5][2] = "Earth";
        question[0][0][5][3] = "Mars";
        question[0][0][5][4] = "Jupiter";
        question[0][0][5][5] = "Venus";
        question[0][0][5][6] = "Our planet is the third from the Sun.";

        // Science - Taxonomy Level 2: Understanding (Easy)
        question[0][1][0][0] = "Why does ice float on water?";
        question[0][1][0][1] = "Ice is less dense than water";
        question[0][1][0][2] = "Ice is less dense than water";
        question[0][1][0][3] = "Ice is heavier";
        question[0][1][0][4] = "Ice is warmer";
        question[0][1][0][5] = "Ice has salt";
        question[0][1][0][6] = "Lower density makes ice buoyant.";
        question[0][1][1][0] = "What happens to water when it boils?";
        question[0][1][1][1] = "It turns into steam";
        question[0][1][1][2] = "It turns into steam";
        question[0][1][1][3] = "It freezes";
        question[0][1][1][4] = "It shrinks";
        question[0][1][1][5] = "It stays liquid";
        question[0][1][1][6] = "Boiling changes water to a gas.";
        question[0][1][2][0] = "Why do plants need sunlight?";
        question[0][1][2][1] = "To make food through photosynthesis";
        question[0][1][2][2] = "To make food through photosynthesis";
        question[0][1][2][3] = "To stay warm";
        question[0][1][2][4] = "To grow roots";
        question[0][1][2][5] = "To attract insects";
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
        question[0][1][4][2] = "Light scatters in the atmosphere";
        question[0][1][4][3] = "The sky reflects the ocean";
        question[0][1][4][4] = "Clouds are blue";
        question[0][1][4][5] = "The Sun is blue";
        question[0][1][4][6] = "Blue light scatters more than other colors.";
        question[0][1][5][0] = "What does gravity do?";
        question[0][1][5][1] = "Pulls objects toward each other";
        question[0][1][5][2] = "Pulls objects toward each other";
        question[0][1][5][3] = "Pushes objects apart";
        question[0][1][5][4] = "Stops objects moving";
        question[0][1][5][5] = "Heats objects up";
        question[0][1][5][6] = "Gravity keeps us on the ground.";

        // Science - Taxonomy Level 3: Applying (Easy)
        question[0][2][0][0] = "If you mix red and blue light, what color do you get?";
        question[0][2][0][1] = "Purple";
        question[0][2][0][2] = "Purple";
        question[0][2][0][3] = "Green";
        question[0][2][0][4] = "Yellow";
        question[0][2][0][5] = "White";
        question[0][2][0][6] = "Light colors combine differently than paint.";
        question[0][2][1][0] = "If a plant is kept in the dark, what happens?";
        question[0][2][1][1] = "It stops growing";
        question[0][2][1][2] = "It stops growing";
        question[0][2][1][3] = "It grows faster";
        question[0][2][1][4] = "It turns red";
        question[0][2][1][5] = "It produces fruit";
        question[0][2][1][6] = "Plants need light for photosynthesis.";
        question[0][2][2][0] = "If you drop a ball, what will happen?";
        question[0][2][2][1] = "It will fall";
        question[0][2][2][2] = "It will fall";
        question[0][2][2][3] = "It will float";
        question[0][2][2][4] = "It will fly";
        question[0][2][2][5] = "It will stop";
        question[0][2][2][6] = "Gravity pulls objects downward.";
        question[0][2][3][0] = "If water is heated to 100°C, what happens?";
        question[0][2][3][1] = "It boils";
        question[0][2][3][2] = "It boils";
        question[0][2][3][3] = "It freezes";
        question[0][2][3][4] = "It cools";
        question[0][2][3][5] = "It stays the same";
        question[0][2][3][6] = "Water turns to steam at its boiling point.";
        question[0][2][4][0] = "If you use a magnifying glass in sunlight, what can happen?";
        question[0][2][4][1] = "It can start a fire";
        question[0][2][4][2] = "It can start a fire";
        question[0][2][4][3] = "It cools objects";
        question[0][2][4][4] = "It creates water";
        question[0][2][4][5] = "It stops light";
        question[0][2][4][6] = "The glass focuses sunlight to a point.";
        question[0][2][5][0] = "If you push a toy car, what will it do?";
        question[0][2][5][1] = "Move forward";
        question[0][2][5][2] = "Move forward";
        question[0][2][5][3] = "Stay still";
        question[0][2][5][4] = "Move backward";
        question[0][2][5][5] = "Fly upward";
        question[0][2][5][6] = "A push applies force to the car.";

        // Science - Taxonomy Level 4: Analyzing (Easy)
        question[0][3][0][0] = "What is the difference between a solid and a liquid?";
        question[0][3][0][1] = "Solids have a fixed shape, liquids do not";
        question[0][3][0][2] = "Solids have a fixed shape, liquids do not";
        question[0][3][0][3] = "Liquids are heavier";
        question[0][3][0][4] = "Solids are invisible";
        question[0][3][0][5] = "Liquids are solid";
        question[0][3][0][6] = "Solids keep their shape, liquids flow.";
        question[0][3][1][0] = "What makes day and night different?";
        question[0][3][1][1] = "Earth’s rotation";
        question[0][3][1][2] = "Earth’s rotation";
        question[0][3][1][3] = "The Moon’s orbit";
        question[0][3][1][4] = "Cloud cover";
        question[0][3][1][5] = "Wind speed";
        question[0][3][1][6] = "Earth turns to face or away from the Sun.";
        question[0][3][2][0] = "How is a star different from a planet?";
        question[0][3][2][1] = "Stars produce light, planets reflect it";
        question[0][3][2][2] = "Stars produce light, planets reflect it";
        question[0][3][2][3] = "Planets are hotter";
        question[0][3][2][4] = "Stars are smaller";
        question[0][3][2][5] = "Planets produce light";
        question[0][3][2][6] = "Stars shine, planets do not.";
        question[0][3][3][0] = "What is the difference between a push and a pull?";
        question[0][3][3][1] = "Push moves away, pull moves closer";
        question[0][3][3][2] = "Push moves away, pull moves closer";
        question[0][3][3][3] = "Both are the same";
        question[0][3][3][4] = "Push stops motion";
        question[0][3][3][5] = "Pull makes things heavier";
        question[0][3][3][6] = "Push and pull are levels of force.";
        question[0][3][4][0] = "How is rain different from snow?";
        question[0][3][4][1] = "Rain is liquid, snow is solid";
        question[0][3][4][2] = "Rain is liquid, snow is solid";
        question[0][3][4][3] = "Snow is warmer";
        question[0][3][4][4] = "Rain is frozen";
        question[0][3][4][5] = "Both are the same";
        question[0][3][4][6] = "Temperature affects water’s form.";
        question[0][3][5][0] = "What makes a shadow different from a reflection?";
        question[0][3][5][1] = "Shadows block light, reflections bounce light";
        question[0][3][5][2] = "Shadows block light, reflections bounce light";
        question[0][3][5][3] = "Shadows are brighter";
        question[0][3][5][4] = "Reflections are darker";
        question[0][3][5][5] = "Both are the same";
        question[0][3][5][6] = "Shadows form when light is blocked.";

        // Science - Taxonomy Level 5: Evaluating (Easy)
        question[0][4][0][0] = "Which is the best way to save water at home?";
        question[0][4][0][1] = "Turn off the tap when brushing teeth";
        question[0][4][0][2] = "Turn off the tap when brushing teeth";
        question[0][4][0][3] = "Leave the tap running";
        question[0][4][0][4] = "Fill a bucket";
        question[0][4][0][5] = "Use more water";
        question[0][4][0][6] = "Small actions reduce water waste.";
        question[0][4][1][0] = "Which is the safest way to observe the Sun?";
        question[0][4][1][1] = "Use special solar glasses";
        question[0][4][1][2] = "Use special solar glasses";
        question[0][4][1][3] = "Look directly at it";
        question[0][4][1][4] = "Use a mirror";
        question[0][4][1][5] = "Close your eyes";
        question[0][4][1][6] = "Protect your eyes from bright sunlight.";
        question[0][4][2][0] = "Which is the best way to keep food fresh?";
        question[0][4][2][1] = "Store it in a refrigerator";
        question[0][4][2][2] = "Store it in a refrigerator";
        question[0][4][2][3] = "Leave it outside";
        question[0][4][2][4] = "Heat it up";
        question[0][4][2][5] = "Put it in sunlight";
        question[0][4][2][6] = "Cold slows down food spoilage.";
        question[0][4][3][0] = "Which is the best way to stay warm in winter?";
        question[0][4][3][1] = "Wear layers of clothing";
        question[0][4][3][2] = "Wear layers of clothing";
        question[0][4][3][3] = "Wear thin clothes";
        question[0][4][3][4] = "Stay outside longer";
        question[0][4][3][5] = "Drink cold water";
        question[0][4][3][6] = "Layers trap body heat.";
        question[0][4][4][0] = "Which is the best way to clean a spill?";
        question[0][4][4][1] = "Use a cloth or sponge";
        question[0][4][4][2] = "Use a cloth or sponge";
        question[0][4][4][3] = "Leave it to dry";
        question[0][4][4][4] = "Add more liquid";
        question[0][4][4][5] = "Ignore it";
        question[0][4][4][6] = "A cloth absorbs the spill.";
        question[0][4][5][0] = "Which is the best way to see in the dark?";
        question[0][4][5][1] = "Use a flashlight";
        question[0][4][5][2] = "Use a flashlight";
        question[0][4][5][3] = "Close your eyes";
        question[0][4][5][4] = "Wave your hands";
        question[0][4][5][5] = "Shout loudly";
        question[0][4][5][6] = "Light helps you see at night.";

        // Science - Taxonomy Level 6: Creating (Easy)
        question[0][5][0][0] = "Design a simple model of the solar system.";
        question[0][5][0][1] = "Use balls to represent planets";
        question[0][5][0][2] = "Use balls to represent planets";
        question[0][5][0][3] = "Draw a square";
        question[0][5][0][4] = "Use only paper";
        question[0][5][0][5] = "Write a story";
        question[0][5][0][6] = "A model shows planet positions.";
        question[0][5][1][0] = "Create a poster about saving water.";
        question[0][5][1][1] = "Show ways to reduce water use";
        question[0][5][1][2] = "Show ways to reduce water use";
        question[0][5][1][3] = "Draw a car";
        question[0][5][1][4] = "List food recipes";
        question[0][5][1][5] = "Write a song";
        question[0][5][1][6] = "A poster teaches conservation.";
        question[0][5][2][0] = "Plan a garden for a school.";
        question[0][5][2][1] = "Choose plants that need less water";
        question[0][5][2][2] = "Choose plants that need less water";
        question[0][5][2][3] = "Build a fountain";
        question[0][5][2][4] = "Add a playground";
        question[0][5][2][5] = "Pave the area";
        question[0][5][2][6] = "Gardens support local plants.";
        question[0][5][3][0] = "Design a toy that uses wind power.";
        question[0][5][3][1] = "Make a simple windmill";
        question[0][5][3][2] = "Make a simple windmill";
        question[0][5][3][3] = "Use batteries";
        question[0][5][3][4] = "Add water";
        question[0][5][3][5] = "Use glue";
        question[0][5][3][6] = "Wind can move objects.";
        question[0][5][4][0] = "Create a chart of animal habitats.";
        question[0][5][4][1] = "Show animals and their homes";
        question[0][5][4][2] = "Show animals and their homes";
        question[0][5][4][3] = "List only colors";
        question[0][5][4][4] = "Draw shapes";
        question[0][5][4][5] = "Write numbers";
        question[0][5][4][6] = "Habitats show where animals live.";
        question[0][5][5][0] = "Plan a recycling project for home.";
        question[0][5][5][1] = "Sort paper, plastic, and glass";
        question[0][5][5][2] = "Sort paper, plastic, and glass";
        question[0][5][5][3] = "Throw everything away";
        question[0][5][5][4] = "Mix all waste";
        question[0][5][5][5] = "Burn trash";
        question[0][5][5][6] = "Recycling reduces waste.";

        // History - Taxonomy Level 1: Remembering (Easy)
        question[1][0][0][0] = "Who was the first president of the United States?";
        question[1][0][0][1] = "George Washington";
        question[1][0][0][2] = "George Washington";
        question[1][0][0][3] = "Abraham Lincoln";
        question[1][0][0][4] = "Thomas Jefferson";
        question[1][0][0][5] = "John Adams";
        question[1][0][0][6] = "He led the country from 1789 to 1797.";
        question[1][0][1][0] = "In which year did Christopher Columbus sail to America?";
        question[1][0][1][1] = "1492";
        question[1][0][1][2] = "1492";
        question[1][0][1][3] = "1776";
        question[1][0][1][4] = "1620";
        question[1][0][1][5] = "1812";
        question[1][0][1][6] = "He sailed across the Atlantic Ocean.";
        question[1][0][2][0] = "What was the name of the ship that carried the Pilgrims to America?";
        question[1][0][2][1] = "Mayflower";
        question[1][0][2][2] = "Mayflower";
        question[1][0][2][3] = "Santa Maria";
        question[1][0][2][4] = "Nina";
        question[1][0][2][5] = "Pinta";
        question[1][0][2][6] = "It arrived in 1620.";
        question[1][0][3][0] = "Who built the Great Wall of China?";
        question[1][0][3][1] = "Emperor Qin Shi Huang";
        question[1][0][3][2] = "Emperor Qin Shi Huang";
        question[1][0][3][3] = "Marco Polo";
        question[1][0][3][4] = "Genghis Khan";
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
        question[1][0][5][2] = "Cleopatra";
        question[1][0][5][3] = "Nefertiti";
        question[1][0][5][4] = "Hatshepsut";
        question[1][0][5][5] = "Isis";
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
        question[1][1][1][2] = "To protect against invaders";
        question[1][1][1][3] = "To mark a trade route";
        question[1][1][1][4] = "To create a city";
        question[1][1][1][5] = "To grow crops";
        question[1][1][1][6] = "It kept enemies out of China.";
        question[1][1][2][0] = "Why was the Declaration of Independence written?";
        question[1][1][2][1] = "To announce freedom from Britain";
        question[1][1][2][2] = "To announce freedom from Britain";
        question[1][1][2][3] = "To start a war";
        question[1][1][2][4] = "To elect a king";
        question[1][1][2][5] = "To build a city";
        question[1][1][2][6] = "It was signed in 1776.";
        question[1][1][3][0] = "What did ancient Egyptians use pyramids for?";
        question[1][1][3][1] = "As tombs for pharaohs";
        question[1][1][3][2] = "As tombs for pharaohs";
        question[1][1][3][3] = "As markets";
        question[1][1][3][4] = "As schools";
        question[1][1][3][5] = "As forts";
        question[1][1][3][6] = "Pyramids held royal burials.";
        question[1][1][4][0] = "Why did people build castles in the Middle Ages?";
        question[1][1][4][1] = "For protection and defense";
        question[1][1][4][2] = "For protection and defense";
        question[1][1][4][3] = "To grow food";
        question[1][1][4][4] = "To hold markets";
        question[1][1][4][5] = "To teach children";
        question[1][1][4][6] = "Castles were strongholds for safety.";
        question[1][1][5][0] = "What was the purpose of the Roman Colosseum?";
        question[1][1][5][1] = "To host gladiator fights";
        question[1][1][5][2] = "To host gladiator fights";
        question[1][1][5][3] = "To store food";
        question[1][1][5][4] = "To house people";
        question[1][1][5][5] = "To grow plants";
        question[1][1][5][6] = "It was a place for public entertainment.";

        // History - Taxonomy Level 3: Applying (Easy)
        question[1][2][0][0] = "If you were a Pilgrim, what would you bring to America?";
        question[1][2][0][1] = "Clothes and tools";
        question[1][2][0][2] = "Clothes and tools";
        question[1][2][0][3] = "Toys and games";
        question[1][2][0][4] = "Cars and phones";
        question[1][2][0][5] = "Books and TVs";
        question[1][2][0][6] = "Pilgrims needed basics to survive.";
        question[1][2][1][0] = "If you lived in ancient Egypt, where would you bury a pharaoh?";
        question[1][2][1][1] = "In a pyramid";
        question[1][2][1][2] = "In a pyramid";
        question[1][2][1][3] = "In a river";
        question[1][2][1][4] = "In a forest";
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
        question[1][2][3][2] = "A ship and a map";
        question[1][2][3][3] = "A car and a phone";
        question[1][2][3][4] = "A plane and a radio";
        question[1][2][3][5] = "A bike and a book";
        question[1][2][3][6] = "Explorers needed navigation tools.";
        question[1][2][4][0] = "If you were in the Colosseum, what would you see?";
        question[1][2][4][1] = "Gladiator fights";
        question[1][2][4][2] = "Gladiator fights";
        question[1][2][4][3] = "Farmers working";
        question[1][2][4][4] = "Teachers lecturing";
        question[1][2][4][5] = "Painters drawing";
        question[1][2][4][6] = "The Colosseum was for entertainment.";
        question[1][2][5][0] = "If you were a knight, what would you wear?";
        question[1][2][5][1] = "Armor and a helmet";
        question[1][2][5][2] = "Armor and a helmet";
        question[1][2][5][3] = "A suit and tie";
        question[1][2][5][4] = "A robe and sandals";
        question[1][2][5][5] = "A hat and gloves";
        question[1][2][5][6] = "Knights needed protection in battle.";

        // History - Taxonomy Level 4: Analyzing (Easy)
        question[1][3][0][0] = "What is the difference between a king and a president?";
        question[1][3][0][1] = "A king is born, a president is elected";
        question[1][3][0][2] = "A king is born, a president is elected";
        question[1][3][0][3] = "Both are elected";
        question[1][3][0][4] = "Both are born rulers";
        question[1][3][0][5] = "A president rules forever";
        question[1][3][0][6] = "Leadership roles have different origins.";
        question[1][3][1][0] = "How is a pyramid different from a castle?";
        question[1][3][1][1] = "Pyramids are tombs, castles are homes";
        question[1][3][1][2] = "Pyramids are tombs, castles are homes";
        question[1][3][1][3] = "Both are homes";
        question[1][3][1][4] = "Both are tombs";
        question[1][3][1][5] = "Pyramids are for defense";
        question[1][3][1][6] = "Each served a unique purpose.";
        question[1][3][2][0] = "What makes the Great Wall different from a city wall?";
        question[1][3][2][1] = "The Great Wall is longer";
        question[1][3][2][2] = "The Great Wall is longer";
        question[1][3][2][3] = "City walls are longer";
        question[1][3][2][4] = "Both are the same";
        question[1][3][2][5] = "City walls are taller";
        question[1][3][2][6] = "The Great Wall spans a country.";
        question[1][3][3][0] = "How is a knight different from a soldier?";
        question[1][3][3][1] = "Knights serve lords, soldiers serve countries";
        question[1][3][3][2] = "Knights serve lords, soldiers serve countries";
        question[1][3][3][3] = "Both are the same";
        question[1][3][3][4] = "Soldiers ride horses";
        question[1][3][3][5] = "Knights use guns";
        question[1][3][3][6] = "Knights lived in the Middle Ages.";
        question[1][3][4][0] = "What is the difference between a ship and a boat?";
        question[1][3][4][1] = "Ships are larger than boats";
        question[1][3][4][2] = "Ships are larger than boats";
        question[1][3][4][3] = "Boats are larger";
        question[1][3][4][4] = "Both are the same";
        question[1][3][4][5] = "Ships stay on land";
        question[1][3][4][6] = "Size defines their use.";
        question[1][3][5][0] = "How is ancient Egypt different from ancient Rome?";
        question[1][3][5][1] = "Egypt had pharaohs, Rome had emperors";
        question[1][3][5][2] = "Egypt had pharaohs, Rome had emperors";
        question[1][3][5][3] = "Both had kings";
        question[1][3][5][4] = "Rome had pyramids";
        question[1][3][5][5] = "Egypt had a Colosseum";
        question[1][3][5][6] = "Each had unique rulers and buildings.";

        // History - Taxonomy Level 5: Evaluating (Easy)
        question[1][4][0][0] = "Which was the best reason for building the Great Wall?";
        question[1][4][0][1] = "To protect China";
        question[1][4][0][2] = "To protect China";
        question[1][4][0][3] = "To make a road";
        question[1][4][0][4] = "To grow food";
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
        question[1][4][2][2] = "Near the Nile River";
        question[1][4][2][3] = "In the desert";
        question[1][4][2][4] = "On a mountain";
        question[1][4][2][5] = "In a forest";
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
        question[1][4][4][2] = "Aqueducts";
        question[1][4][4][3] = "Pyramids";
        question[1][4][4][4] = "Great Wall";
        question[1][4][4][5] = "Airplanes";
        question[1][4][4][6] = "Aqueducts brought water to cities.";
        question[1][4][5][0] = "Which was the best reason to explore new lands?";
        question[1][4][5][1] = "To find resources";
        question[1][4][5][2] = "To find resources";
        question[1][4][5][3] = "To stay home";
        question[1][4][5][4] = "To avoid trade";
        question[1][4][5][5] = "To build walls";
        question[1][4][5][6] = "Explorers sought wealth.";

        // History - Taxonomy Level 6: Creating (Easy)
        question[1][5][0][0] = "Design a flag for ancient Egypt.";
        question[1][5][0][1] = "Use symbols like the ankh or pyramid";
        question[1][5][0][2] = "Use symbols like the ankh or pyramid";
        question[1][5][0][3] = "Draw a car";
        question[1][5][0][4] = "Use only dots";
        question[1][5][0][5] = "Write numbers";
        question[1][5][0][6] = "Symbols represent culture.";
        question[1][5][1][0] = "Create a model of a castle.";
        question[1][5][1][1] = "Include walls and towers";
        question[1][5][1][2] = "Include walls and towers";
        question[1][5][1][3] = "Make a flat square";
        question[1][5][1][4] = "Use only paper";
        question[1][5][1][5] = "Draw a circle";
        question[1][5][1][6] = "Castles had defensive features.";
        question[1][5][2][0] = "Plan a festival for ancient Rome.";
        question[1][5][2][1] = "Include games and food";
        question[1][5][2][2] = "Include games and food";
        question[1][5][2][3] = "Build a wall";
        question[1][5][2][4] = "Grow crops";
        question[1][5][2][5] = "Make tools";
        question[1][5][2][6] = "Festivals were for fun.";
        question[1][5][3][0] = "Design a map of a new colony.";
        question[1][5][3][1] = "Show houses and a river";
        question[1][5][3][2] = "Show houses and a river";
        question[1][5][3][3] = "Draw only trees";
        question[1][5][3][4] = "Write a story";
        question[1][5][3][5] = "Use one color";
        question[1][5][3][6] = "Maps help plan settlements.";
        question[1][5][4][0] = "Create a story about a knight.";
        question[1][5][4][1] = "Describe his adventures";
        question[1][5][4][2] = "Describe his adventures";
        question[1][5][4][3] = "List numbers";
        question[1][5][4][4] = "Draw shapes";
        question[1][5][4][5] = "Write a poem";
        question[1][5][4][6] = "Stories bring history to life.";
        question[1][5][5][0] = "Plan a museum exhibit on explorers.";
        question[1][5][5][1] = "Show maps and ships";
        question[1][5][5][2] = "Show maps and ships";
        question[1][5][5][3] = "Display only rocks";
        question[1][5][5][4] = "Grow plants";
        question[1][5][5][5] = "Build a wall";
        question[1][5][5][6] = "Exhibits teach about exploration.";

        // Geography - Taxonomy Level 1: Remembering (Easy)
        question[2][0][0][0] = "What is the capital of France?";
        question[2][0][0][1] = "Paris";
        question[2][0][0][2] = "Paris";
        question[2][0][0][3] = "London";
        question[2][0][0][4] = "Berlin";
        question[2][0][0][5] = "Madrid";
        question[2][0][0][6] = "Capital city of France due to its famous landmarks like the Eiffel Tower.";
        question[2][0][1][0] = "What is the largest continent?";
        question[2][0][1][1] = "Asia";
        question[2][0][1][2] = "Asia";
        question[2][0][1][3] = "Africa";
        question[2][0][1][4] = "Australia";
        question[2][0][1][5] = "Europe";
        question[2][0][1][6] = "It is home to many countries.";
        question[2][0][2][0] = "What is the tallest mountain in the world?";
        question[2][0][2][1] = "Mount Everest";
        question[2][0][2][2] = "Mount Everest";
        question[2][0][2][3] = "Mount Kilimanjaro";
        question[2][0][2][4] = "K2";
        question[2][0][2][5] = "Mount Fuji";
        question[2][0][2][6] = "It is located in the Himalayas.";
        question[2][0][3][0] = "What is the largest ocean?";
        question[2][0][3][1] = "Pacific Ocean";
        question[2][0][3][2] = "Pacific Ocean";
        question[2][0][3][3] = "Atlantic Ocean";
        question[2][0][3][4] = "Indian Ocean";
        question[2][0][3][5] = "Arctic Ocean";
        question[2][0][3][6] = "It is the biggest body of water.";
        question[2][0][4][0] = "What is the longest river in the world?";
        question[2][0][4][1] = "Nile River";
        question[2][0][4][2] = "Nile River";
        question[2][0][4][3] = "Amazon River";
        question[2][0][4][4] = "Mississippi River";
        question[2][0][4][5] = "Yangtze River";
        question[2][0][4][6] = "It flows through Africa.";
        question[2][0][5][0] = "What is the name of the hottest desert?";
        question[2][0][5][1] = "Sahara Desert";
        question[2][0][5][2] = "Sahara Desert";
        question[2][0][5][3] = "Gobi Desert";
        question[2][0][5][4] = "Kalahari Desert";
        question[2][0][5][5] = "Mojave Desert";
        question[2][0][5][6] = "It is in northern Africa.";

        // Geography - Taxonomy Level 2: Understanding (Easy)
        question[2][1][0][0] = "Why is the equator hot?";
        question[2][1][0][1] = "It gets direct sunlight";
        question[2][1][0][2] = "It gets direct sunlight";
        question[2][1][0][3] = "It is near the ocean";
        question[2][1][0][4] = "It has no mountains";
        question[2][1][0][5] = "It is always cloudy";
        question[2][1][0][6] = "Sunlight hits the equator straight on.";
        question[2][1][1][0] = "What causes rain in a rainforest?";
        question[2][1][1][1] = "Warm air holds moisture";
        question[2][1][1][2] = "Warm air holds moisture";
        question[2][1][1][3] = "Cold air stops rain";
        question[2][1][1][4] = "Dry air creates clouds";
        question[2][1][1][5] = "No air movement";
        question[2][1][1][6] = "Heat makes water evaporate.";
        question[2][1][2][0] = "Why do mountains have snow on top?";
        question[2][1][2][1] = "Higher areas are colder";
        question[2][1][2][2] = "Higher areas are colder";
        question[2][1][2][3] = "They get more rain";
        question[2][1][2][4] = "They are near the Sun";
        question[2][1][2][5] = "They have less wind";
        question[2][1][2][6] = "Cold air at high altitudes freezes water.";
        question[2][1][3][0] = "What makes a desert dry?";
        question[2][1][3][1] = "Little rainfall";
        question[2][1][3][2] = "Little rainfall";
        question[2][1][3][3] = "Too much water";
        question[2][1][3][4] = "Cold temperatures";
        question[2][1][3][5] = "Many trees";
        question[2][1][3][6] = "Deserts get very little water.";
        question[2][1][4][0] = "Why do rivers flow to the sea?";
        question[2][1][4][1] = "Gravity pulls water downhill";
        question[2][1][4][2] = "Gravity pulls water downhill";
        question[2][1][4][3] = "The sea pushes water";
        question[2][1][4][4] = "Rivers are flat";
        question[2][1][4][5] = "Wind moves water";
        question[2][1][4][6] = "Water flows to lower areas.";
        question[2][1][5][0] = "What causes waves in the ocean?";
        question[2][1][5][1] = "Wind blows over water";
        question[2][1][5][2] = "Wind blows over water";
        question[2][1][5][3] = "The Moon pulls water";
        question[2][1][5][4] = "Fish swim fast";
        question[2][1][5][5] = "Rocks fall in";
        question[2][1][5][6] = "Wind creates ripples on water.";

        // Geography - Taxonomy Level 3: Applying (Easy)
        question[2][2][0][0] = "If you are in Paris, what country are you in?";
        question[2][2][0][1] = "France";
        question[2][2][0][2] = "France";
        question[2][2][0][3] = "Italy";
        question[2][2][0][4] = "Spain";
        question[2][2][0][5] = "Germany";
        question[2][2][0][6] = "Paris is the capital of France.";
        question[2][2][1][0] = "If you see Mount Everest, what continent are you on?";
        question[2][2][1][1] = "Asia";
        question[2][2][1][2] = "Asia";
        question[2][2][1][3] = "Africa";
        question[2][2][1][4] = "South America";
        question[2][2][1][5] = "Australia";
        question[2][2][1][6] = "Mount Everest is in the Himalayas.";
        question[2][2][2][0] = "If you are sailing in the Pacific, what are you crossing?";
        question[2][2][2][1] = "An ocean";
        question[2][2][2][2] = "An ocean";
        question[2][2][2][3] = "A river";
        question[2][2][2][4] = "A desert";
        question[2][2][2][5] = "A mountain";
        question[2][2][2][6] = "The Pacific is the largest ocean.";
        question[2][2][3][0] = "If you are in the Sahara, what are you crossing?";
        question[2][2][3][1] = "A desert";
        question[2][2][3][2] = "A desert";
        question[2][2][3][3] = "A forest";
        question[2][2][3][4] = "A river";
        question[2][2][3][5] = "A city";
        question[2][2][3][6] = "The Sahara is very dry.";
        question[2][2][4][0] = "If you follow the Nile, where will you end up?";
        question[2][2][4][1] = "Mediterranean Sea";
        question[2][2][4][2] = "Mediterranean Sea";
        question[2][2][4][3] = "Pacific Ocean";
        question[2][2][4][4] = "Red Sea";
        question[2][2][4][5] = "Atlantic Ocean";
        question[2][2][4][6] = "The Nile flows north.";
        question[2][2][5][0] = "If you are on a rainforest trail, what continent might you be on?";
        question[2][2][5][1] = "South America";
        question[2][2][5][2] = "South America";
        question[2][2][5][3] = "Antarctica";
        question[2][2][5][4] = "Europe";
        question[2][2][5][5] = "Australia";
        question[2][2][5][6] = "The Amazon is in South America.";

        // Geography - Taxonomy Level 4: Analyzing (Easy)
        question[2][3][0][0] = "What is the difference between a river and a lake?";
        question[2][3][0][1] = "Rivers flow, lakes are still";
        question[2][3][0][2] = "Rivers flow, lakes are still";
        question[2][3][0][3] = "Lakes flow, rivers are still";
        question[2][3][0][4] = "Both are the same";
        question[2][3][0][5] = "Rivers are deeper";
        question[2][3][0][6] = "Rivers move water, lakes hold it.";
        question[2][3][1][0] = "How is a desert different from a forest?";
        question[2][3][1][1] = "Deserts are dry, forests are green";
        question[2][3][1][2] = "Deserts are dry, forests are green";
        question[2][3][1][3] = "Forests are dry";
        question[2][3][1][4] = "Both are the same";
        question[2][3][1][5] = "Deserts have more trees";
        question[2][3][1][6] = "Water makes forests lush.";
        question[2][3][2][0] = "What makes a mountain different from a hill?";
        question[2][3][2][1] = "Mountains are taller";
        question[2][3][2][2] = "Mountains are taller";
        question[2][3][2][3] = "Hills are taller";
        question[2][3][2][4] = "Both are the same";
        question[2][3][2][5] = "Hills are steeper";
        question[2][3][2][6] = "Height defines mountains.";
        question[2][3][3][0] = "How is an ocean different from a sea?";
        question[2][3][3][1] = "Oceans are larger";
        question[2][3][3][2] = "Oceans are larger";
        question[2][3][3][3] = "Seas are larger";
        question[2][3][3][4] = "Both are the same";
        question[2][3][3][5] = "Seas are deeper";
        question[2][3][3][6] = "Oceans cover more area.";
        question[2][3][4][0] = "What is the difference between the equator and the poles?";
        question[2][3][4][1] = "Equator is hot, poles are cold";
        question[2][3][4][2] = "Equator is hot, poles are cold";
        question[2][3][4][3] = "Poles are hot";
        question[2][3][4][4] = "Both are the same";
        question[2][3][4][5] = "Equator is cold";
        question[2][3][4][6] = "Temperature varies by location.";
        question[2][3][5][0] = "How is a city different from a village?";
        question[2][3][5][1] = "Cities are larger";
        question[2][3][5][2] = "Cities are larger";
        question[2][3][5][3] = "Villages are larger";
        question[2][3][5][4] = "Both are the same";
        question[2][3][5][5] = "Villages have more buildings";
        question[2][3][5][6] = "Size and population differ.";

        // Geography - Taxonomy Level 5: Evaluating (Easy)
        question[2][4][0][0] = "Which is the best place to grow crops?";
        question[2][4][0][1] = "Near a river";
        question[2][4][0][2] = "Near a river";
        question[2][4][0][3] = "In a desert";
        question[2][4][0][4] = "On a mountain";
        question[2][4][0][5] = "In the ocean";
        question[2][4][0][6] = "Rivers provide water for crops.";
        question[2][4][1][0] = "Which is the best way to travel across an ocean?";
        question[2][4][1][1] = "By ship";
        question[2][4][1][2] = "By ship";
        question[2][4][1][3] = "By car";
        question[2][4][1][4] = "By bike";
        question[2][4][1][5] = "By walking";
        question[2][4][1][6] = "Ships are built for ocean travel.";
        question[2][4][2][0] = "Which is the best place to build a city?";
        question[2][4][2][1] = "Near a water source";
        question[2][4][2][2] = "Near a water source";
        question[2][4][2][3] = "In a desert";
        question[2][4][2][4] = "On a cliff";
        question[2][4][2][5] = "In a forest";
        question[2][4][2][6] = "Water supports city life.";
        question[2][4][3][0] = "Which is the best way to stay cool in a desert?";
        question[2][4][3][1] = "Wear light clothing";
        question[2][4][3][2] = "Wear light clothing";
        question[2][4][3][3] = "Wear heavy coats";
        question[2][4][3][4] = "Stay in the Sun";
        question[2][4][3][5] = "Avoid water";
        question[2][4][3][6] = "Light clothes reflect heat.";
        question[2][4][4][0] = "Which is the best way to find north?";
        question[2][4][4][1] = "Use a compass";
        question[2][4][4][2] = "Use a compass";
        question[2][4][4][3] = "Look at the ground";
        question[2][4][4][4] = "Follow the wind";
        question[2][4][4][5] = "Guess randomly";
        question[2][4][4][6] = "A compass points to north.";
        question[2][4][5][0] = "Which is the best place to see animals?";
        question[2][4][5][1] = "In a rainforest";
        question[2][4][5][2] = "In a rainforest";
        question[2][4][5][3] = "In a city";
        question[2][4][5][4] = "In the ocean";
        question[2][4][5][5] = "On a mountain";
        question[2][4][5][6] = "Rainforests have many species.";

        // Geography - Taxonomy Level 6: Creating (Easy)
        question[2][5][0][0] = "Design a map of a small island.";
        question[2][5][0][1] = "Show a beach and trees";
        question[2][5][0][2] = "Show a beach and trees";
        question[2][5][0][3] = "Draw only rocks";
        question[2][5][0][4] = "Write a story";
        question[2][5][0][5] = "Use one color";
        question[2][5][0][6] = "Maps show land features.";
        question[2][5][1][0] = "Create a poster about the Nile River.";
        question[2][5][1][1] = "Show its path and animals";
        question[2][5][1][2] = "Show its path and animals";
        question[2][5][1][3] = "Draw a city";
        question[2][5][1][4] = "List numbers";
        question[2][5][1][5] = "Write a song";
        question[2][5][1][6] = "Posters teach about geography.";
        question[2][5][2][0] = "Plan a park for a city.";
        question[2][5][2][1] = "Include trees and a pond";
        question[2][5][2][2] = "Include trees and a pond";
        question[2][5][2][3] = "Build a factory";
        question[2][5][2][4] = "Pave the area";
        question[2][5][2][5] = "Add a desert";
        question[2][5][2][6] = "Parks provide green spaces.";
        question[2][5][3][0] = "Design a flag for a new country.";
        question[2][5][3][1] = "Use colors and symbols";
        question[2][5][3][2] = "Use colors and symbols";
        question[2][5][3][3] = "Draw a square";
        question[2][5][3][4] = "Write numbers";
        question[2][5][3][5] = "Use only lines";
        question[2][5][3][6] = "Flags represent a country.";
        question[2][5][4][0] = "Create a model of a mountain.";
        question[2][5][4][1] = "Use clay or paper";
        question[2][5][4][2] = "Use clay or paper";
        question[2][5][4][3] = "Draw a flat line";
        question[2][5][4][4] = "Write a story";
        question[2][5][4][5] = "Use water";
        question[2][5][4][6] = "Models show land shapes.";
        question[2][5][5][0] = "Plan a trip across a continent.";
        question[2][5][5][1] = "Choose cities and routes";
        question[2][5][5][2] = "Choose cities and routes";
        question[2][5][5][3] = "Stay in one place";
        question[2][5][5][4] = "Draw a circle";
        question[2][5][5][5] = "Write a poem";
        question[2][5][5][6] = "Trips explore new places.";

        // Mathematics - Taxonomy Level 1: Remembering (Easy)
        question[3][0][0][0] = "What is 2 + 2?";
        question[3][0][0][1] = "4";
        question[3][0][0][2] = "4";
        question[3][0][0][3] = "3";
        question[3][0][0][4] = "5";
        question[3][0][0][5] = "6";
        question[3][0][0][6] = "Addition combines numbers.";
        question[3][0][1][0] = "What is 5 - 3?";
        question[3][0][1][1] = "2";
        question[3][0][1][2] = "2";
        question[3][0][1][3] = "1";
        question[3][0][1][4] = "4";
        question[3][0][1][5] = "8";
        question[3][0][1][6] = "Subtraction takes one number away.";
        question[3][0][2][0] = "What is 3 × 2?";
        question[3][0][2][1] = "6";
        question[3][0][2][2] = "6";
        question[3][0][2][3] = "5";
        question[3][0][2][4] = "8";
        question[3][0][2][5] = "9";
        question[3][0][2][6] = "Multiplication repeats addition.";
        question[3][0][3][0] = "What is 8 ÷ 2?";
        question[3][0][3][1] = "4";
        question[3][0][3][2] = "4";
        question[3][0][3][3] = "3";
        question[3][0][3][4] = "6";
        question[3][0][3][5] = "2";
        question[3][0][3][6] = "Division splits numbers.";
        question[3][0][4][0] = "What is the shape with 4 equal sides?";
        question[3][0][4][1] = "Square";
        question[3][0][4][2] = "Square";
        question[3][0][4][3] = "Circle";
        question[3][0][4][4] = "Triangle";
        question[3][0][4][5] = "Rectangle";
        question[3][0][4][6] = "A square has equal sides.";
        question[3][0][5][0] = "What is the number after 9?";
        question[3][0][5][1] = "10";
        question[3][0][5][2] = "10";
        question[3][0][5][3] = "8";
        question[3][0][5][4] = "11";
        question[3][0][5][5] = "7";
        question[3][0][5][6] = "Counting goes up by one.";

        // Mathematics - Taxonomy Level 2: Understanding (Easy)
        question[3][1][0][0] = "Why is 4 + 3 the same as 3 + 4?";
        question[3][1][0][1] = "Addition is commutative";
        question[3][1][0][2] = "Addition is commutative";
        question[3][1][0][3] = "Numbers are different";
        question[3][1][0][4] = "It is subtraction";
        question[3][1][0][5] = "Order changes the answer";
        question[3][1][0][6] = "Order does not affect addition.";
        question[3][1][1][0] = "What does a circle look like?";
        question[3][1][1][1] = "A round shape";
        question[3][1][1][2] = "A round shape";
        question[3][1][1][3] = "A square shape";
        question[3][1][1][4] = "A straight line";
        question[3][1][1][5] = "A triangle";
        question[3][1][1][6] = "Circles have no corners.";
        question[3][1][2][0] = "Why is 10 - 5 different from 5 - 10?";
        question[3][1][2][1] = "Subtraction is not commutative";
        question[3][1][2][2] = "Subtraction is not commutative";
        question[3][1][2][3] = "Both are the same";
        question[3][1][2][4] = "It is addition";
        question[3][1][2][5] = "Order does not matter";
        question[3][1][2][6] = "Order matters in subtraction.";
        question[3][1][3][0] = "What does 2 × 3 mean?";
        question[3][1][3][1] = "Two groups of three";
        question[3][1][3][2] = "Two groups of three";
        question[3][1][3][3] = "Three groups of one";
        question[3][1][3][4] = "Two plus three";
        question[3][1][3][5] = "Three minus two";
        question[3][1][3][6] = "Multiplication shows groups.";
        question[3][1][4][0] = "Why is a square a level of rectangle?";
        question[3][1][4][1] = "It has four right angles";
        question[3][1][4][2] = "It has four right angles";
        question[3][1][4][3] = "It has no angles";
        question[3][1][4][4] = "It is round";
        question[3][1][4][5] = "It has three sides";
        question[3][1][4][6] = "Rectangles include squares.";
        question[3][1][5][0] = "What does a number line show?";
        question[3][1][5][1] = "Order of numbers";
        question[3][1][5][2] = "Order of numbers";
        question[3][1][5][3] = "Shapes";
        question[3][1][5][4] = "Colors";
        question[3][1][5][5] = "Letters";
        question[3][1][5][6] = "Numbers are placed in sequence.";

        // Mathematics - Taxonomy Level 3: Applying (Easy)
        question[3][2][0][0] = "If you have 3 apples and add 2 more, how many do you have?";
        question[3][2][0][1] = "5";
        question[3][2][0][2] = "5";
        question[3][2][0][3] = "4";
        question[3][2][0][4] = "6";
        question[3][2][0][5] = "3";
        question[3][2][0][6] = "Add the numbers together.";
        question[3][2][1][0] = "If you have 6 cookies and eat 2, how many are left?";
        question[3][2][1][1] = "4";
        question[3][2][1][2] = "4";
        question[3][2][1][3] = "5";
        question[3][2][1][4] = "8";
        question[3][2][1][5] = "2";
        question[3][2][1][6] = "Subtract what you ate.";
        question[3][2][2][0] = "If you buy 2 packs of 3 pens, how many pens do you have?";
        question[3][2][2][1] = "6";
        question[3][2][2][2] = "6";
        question[3][2][2][3] = "5";
        question[3][2][2][4] = "8";
        question[3][2][2][5] = "4";
        question[3][2][2][6] = "Multiply packs by pens.";
        question[3][2][3][0] = "If you share 10 candies among 2 friends, how many does each get?";
        question[3][2][3][1] = "5";
        question[3][2][3][2] = "5";
        question[3][2][3][3] = "4";
        question[3][2][3][4] = "6";
        question[3][2][3][5] = "2";
        question[3][2][3][6] = "Divide equally.";
        question[3][2][4][0] = "If a square has a side of 3, what is its perimeter?";
        question[3][2][4][1] = "12";
        question[3][2][4][2] = "12";
        question[3][2][4][3] = "9";
        question[3][2][4][4] = "6";
        question[3][2][4][5] = "15";
        question[3][2][4][6] = "Add all four sides.";
        question[3][2][5][0] = "If you count by 2s, what is the 3rd number?";
        question[3][2][5][1] = "6";
        question[3][2][5][2] = "6";
        question[3][2][5][3] = "4";
        question[3][2][5][4] = "8";
        question[3][2][5][5] = "2";
        question[3][2][5][6] = "Skip count by twos.";

        // Mathematics - Taxonomy Level 4: Analyzing (Easy)
        question[3][3][1][0] = "How is a square different from a triangle?";
        question[3][3][1][1] = "Square has 4 sides, triangle has 3";
        question[3][3][1][2] = "Square has 4 sides, triangle has 3";
        question[3][3][1][3] = "Both have 3 sides";
        question[3][3][1][4] = "Both have 4 sides";
        question[3][3][1][5] = "Square has 3 sides";
        question[3][3][1][6] = "Side count defines them.";
        question[3][3][2][0] = "What is the difference between even and odd numbers?";
        question[3][3][2][1] = "Even is divisible by 2, odd is not";
        question[3][3][2][2] = "Even is divisible by 2, odd is not";
        question[3][3][2][3] = "Odd is divisible by 2";
        question[3][3][2][4] = "Both are the same";
        question[3][3][2][5] = "Even is not divisible by 2";
        question[3][3][2][6] = "Divisibility determines level.";
        question[3][3][3][0] = "How does counting differ from measuring?";
        question[3][3][3][1] = "Counting uses whole numbers, measuring uses units";
        question[3][3][3][2] = "Counting uses whole numbers, measuring uses units";
        question[3][3][3][3] = "Measuring uses whole numbers";
        question[3][3][3][4] = "Both are the same";
        question[3][3][3][5] = "Counting uses units";
        question[3][3][3][6] = "Purpose differs.";
        question[3][3][4][0] = "What distinguishes a circle from a square?";
        question[3][3][4][1] = "Circle is round, square has straight sides";
        question[3][3][4][2] = "Circle is round, square has straight sides";
        question[3][3][4][3] = "Square is round";
        question[3][3][4][4] = "Both are the same";
        question[3][3][4][5] = "Circle has straight sides";
        question[3][3][4][6] = "Shape defines them.";
        question[3][3][5][0] = "How does a whole number differ from a fraction?";
        question[3][3][5][1] = "Whole number is complete, fraction is part";
        question[3][3][5][2] = "Whole number is complete, fraction is part";
        question[3][3][5][3] = "Fraction is complete";
        question[3][3][5][4] = "Both are the same";
        question[3][3][5][5] = "Whole number is part";
        question[3][3][5][6] = "Fractions show parts.";

        // Mathematics - Taxonomy Level 5: Evaluating (Easy)
        question[3][4][0][0] = "Which is the best way to count objects quickly?";
        question[3][4][0][1] = "Group by tens";
        question[3][4][0][2] = "Group by tens";
        question[3][4][0][3] = "Count one by one";
        question[3][4][0][4] = "Guess the number";
        question[3][4][0][5] = "Use a ruler";
        question[3][4][0][6] = "Grouping saves time.";
        question[3][4][1][0] = "Which is the most accurate way to measure length?";
        question[3][4][1][1] = "Use a ruler";
        question[3][4][1][2] = "Use a ruler";
        question[3][4][1][3] = "Count steps";
        question[3][4][1][4] = "Guess the length";
        question[3][4][1][5] = "Use fingers";
        question[3][4][1][6] = "Tools give precision.";
        question[3][4][2][0] = "Which is the best way to learn addition?";
        question[3][4][2][1] = "Use objects like blocks";
        question[3][4][2][2] = "Use objects like blocks";
        question[3][4][2][3] = "Memorize only";
        question[3][4][2][4] = "Avoid practice";
        question[3][4][2][5] = "Use subtraction";
        question[3][4][2][6] = "Visuals aid learning.";
        question[3][4][3][0] = "Which is the most effective way to identify shapes?";
        question[3][4][3][1] = "Count sides and corners";
        question[3][4][3][2] = "Count sides and corners";
        question[3][4][3][3] = "Guess the shape";
        question[3][4][3][4] = "Measure area";
        question[3][4][3][5] = "Use colors";
        question[3][4][3][6] = "Properties define shapes.";
        question[3][4][4][0] = "Which is the best way to check if a number is even?";
        question[3][4][4][1] = "Divide by 2";
        question[3][4][4][2] = "Divide by 2";
        question[3][4][4][3] = "Add 1";
        question[3][4][4][4] = "Subtract 2";
        question[3][4][4][5] = "Guess";
        question[3][4][4][6] = "No remainder means even.";
        question[3][4][5][0] = "Which is the most reliable way to compare sizes?";
        question[3][4][5][1] = "Measure with a tool";
        question[3][4][5][2] = "Measure with a tool";
        question[3][4][5][3] = "Look only";
        question[3][4][5][4] = "Count objects";
        question[3][4][5][5] = "Use hands";
        question[3][4][5][6] = "Tools ensure accuracy.";

        // Mathematics - Taxonomy Level 6: Creating (Easy)
        question[3][5][0][0] = "Design a game to practice counting.";
        question[3][5][0][1] = "Use cards with numbers";
        question[3][5][0][2] = "Use cards with numbers";
        question[3][5][0][3] = "Draw shapes";
        question[3][5][0][4] = "List colors";
        question[3][5][0][5] = "Use letters";
        question[3][5][0][6] = "Games make learning fun.";
        question[3][5][1][0] = "Create a chart to show shapes.";
        question[3][5][1][1] = "Draw shapes and name them";
        question[3][5][1][2] = "Draw shapes and name them";
        question[3][5][1][3] = "List numbers";
        question[3][5][1][4] = "Show colors";
        question[3][5][1][5] = "Write words";
        question[3][5][1][6] = "Charts organize information.";
        question[3][5][2][0] = "Plan a lesson to teach addition.";
        question[3][5][2][1] = "Use objects and pictures";
        question[3][5][2][2] = "Use objects and pictures";
        question[3][5][2][3] = "List numbers only";
        question[3][5][2][4] = "Use subtraction";
        question[3][5][2][5] = "Avoid visuals";
        question[3][5][2][6] = "Visuals help understanding.";
        question[3][5][3][0] = "Design a model to show even numbers.";
        question[3][5][3][1] = "Use pairs of objects";
        question[3][5][3][2] = "Use pairs of objects";
        question[3][5][3][3] = "Show odd numbers";
        question[3][5][3][4] = "List all numbers";
        question[3][5][3][5] = "Use shapes";
        question[3][5][3][6] = "Pairs show divisibility.";
        question[3][5][4][0] = "Create a tool to measure length.";
        question[3][5][4][1] = "Make a paper ruler";
        question[3][5][4][2] = "Make a paper ruler";
        question[3][5][4][3] = "Use hands only";
        question[3][5][4][4] = "Guess length";
        question[3][5][4][5] = "Draw lines";
        question[3][5][4][6] = "Rulers give precision.";
        question[3][5][5][0] = "Propose a way to teach shapes.";
        question[3][5][5][1] = "Use real objects and drawings";
        question[3][5][5][2] = "Use real objects and drawings";
        question[3][5][5][3] = "List names only";
        question[3][5][5][4] = "Show colors";
        question[3][5][5][5] = "Use numbers";
        question[3][5][5][6] = "Objects make shapes clear.";
    }

    void medium_questions()
    {
        // Same as easy qeustion pattern.
    }

    void hard_questions()
    {
        // Same as easy_question type pattern.
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

    // Rest question number.
    void reset_question()
    {
        question_no = 1;
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
    int current_question, current_topic, marks, is_correct_answer = 0;
    int correct_answers[SIZE][MAX_TYPE][MAX_TOPICS] = {0};
    int total_attempts[SIZE][MAX_TYPE][MAX_TOPICS] = {0};

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
            is_correct_answer = 1;
        }

        else
        {
            cout << "Oh. That's Wrong answer! \nThe correct answer is: "
                 << question[current_topic][current_type][current_question][1] << endl;
            is_correct_answer = 0;
        }
        cout << "Explaination: "
             << question[current_topic][current_type][current_question][6] << endl;
    }

    void reset_marks_number()
    {
        // for (int i = 0; i < SIZE; i++)
        // {
        //     for (int j = 0; j < MAX_TOPICS; j++)
        //     {
        //         for (int k = 0; k < MAX_TYPE; k++) {
        //             correct_answers[i][j][k] = 0;
        //             total_attempts[i][j][k] = 0;
        //         }
        //     }
        // }
    }

    void calculate_marks()
    {
        //  Calculate marks.
        correct_answers[current_Level][current_topic][current_type] += is_correct_answer;
        total_attempts[current_Level][current_topic][current_type] += 1;

    }

    void display_result()
    {
        for (int level = 0; level < SIZE; level++)
        {
            for (int topic = 0; topic < MAX_TOPICS; topic++)
            {
                bool has_data = false;

                // First check if there is any attempt in this topic
                for (int type = 0; type < MAX_TYPE; type++)
                {
                    if (total_attempts[level][topic][type] > 0)
                    {
                        has_data = true;
                        break;
                    }
                }

                if (!has_data)
                    continue; // skip this combo

                cout << "--------------------------------------\n";
                cout << "Difficulty: " << level_names[level] << endl;
                cout << "Topic: " << topic_names[topic] << endl;
                cout << "--------------------------------------\n";

                for (int type = 0; type < MAX_TYPE; ++type)
                {
                    if (total_attempts[level][topic][type] > 0)
                    {
                        cout << "Taxonomy type: " << type_names[type] << endl;
                        cout << "Correct answers: " << correct_answers[level][topic][type]
                            << " out of " << total_attempts[level][topic][type] << endl;
                        cout << "--------------------------------------\n";
                    }
                }
            }
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
                continue;
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
            cout << " 1. Easy\n 2. Medium\n 3. Hard\n 4. Back to the Main Menu\n5.Exit\n";
            cout << "Enter your choice (1-5): ";
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
            cout << "Enter your choice (1-6): ";
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

            // Reset the marks for each time of quiz.
            miscellaneous.reset_marks_number();

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
                miscellaneous.calculate_marks();

                //  Condition to stop quiz at question 9.
                if (question_no == 10)
                {
                    // Display the result.
                    miscellaneous.display_result();

                    // Ask if the user wants to play again.
                    cout << "--------------------------------------\n";
                    cout << "           END OF QUIZ\n";
                    cout << "--------------------------------------\n\n";
                    cout << "So tell me what's your next plan??\n";
                    cout << "=> Enter 1 to Play agian\n=> Enter anything to exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    if (choice == "1")
                    {
                        // Reset question number.
                        display_Questions.reset_question();
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