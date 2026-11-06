/*
Lab_2
Zach Beauchamp
LAB – Fundamental Data Structure
Dr. Fei Zuo

*/

#include <iostream>
#include <string>

using namespace std;

/***
 * Create the Character Class (The Foundation)
 * Define a base class Character that represents a generic character in the game.
 * The class should have the following protected attributes:
 * name (string): The character's name.
 * health (int): The character's health points.
 * level (int): The character's level.
 * Implement a constructor to initialize these attributes and a public method displayInfo() to print the character's information.
 */
class Character
{
    string name;
    int health;
    int level;

public:
    //default constructor
    Character();

    //arg-constucter
    Character(string, int, int);
    
    //getters
    string getName() const;
    int getHealth() const;
    int getLevel() const;

    //setters
    void setName(string);
    void setHealth(int);
    void setLevel(int);

    //aux functions
    virtual void displayInfo() = 0;
    virtual ~Character();
};

//Character Initialization
Character::Character(){
    name = "Serf";
    health = 1;
    level = 0;
}

//overloaded constructor
Character::Character(string name, int health, int level){
    this->name = name;
    this->health = health;
    this->level = level;    
}
//destructer
Character::~Character() {
    cout << "CHAR_LOG: Character address: " << this << " has been destructed!" << endl;
}

//getters
string Character::getName() const{
    return name;
}
int Character::getHealth() const{
    return health;
}
int Character::getLevel() const {
    return level;
}

//setters
void Character::setName(string name) {
    this->name = name;
}
void Character::setHealth(int health) {
    this->health = health;
}
void Character::setLevel(int level) {
    this->level = level;
}

//void displayInfo();
void Character::displayInfo() {
   
}

/**
 * Create the Hero Class (The Champion)
 * Derive a class Hero from the base class Character.
 * Add an additional private attribute specialPower (string) that represents the hero’s unique ability.
 * Implement a constructor to initialize all attributes, including those inherited from Character.
 * Implement a method useSpecialPower() that prints a message indicating that the hero is using their special power.
 */ 
class Hero : public Character {
    string specialPower; 
public:
    Hero();
    Hero(string, int, int, string);
    ~Hero();
    string getSpecialPower() const;
    void setSpecialPower(string); 
    void useSpecialPower();
    void displayInfo() override; 
};

//default constructor
Hero::Hero() : Character() {
    Character::setName("Lord of the Serfs");
    Character::setHealth(2);
    Character::setLevel(1);
    specialPower = "Lord of the Serfs has no special power";
}


//overloaded constructor
Hero::Hero(string name, int health, int level, string specialPower) : Character(name, health, level) {
    Character::setName(name);
    Character::setHealth(health);
    Character::setLevel(level);
    this->specialPower = specialPower; 
}

//destructer
Hero::~Hero() {
    cout << "H_LOG: Hero MEM address: " << this << " has been destructed!" << endl;
}

//getters
string Hero::getSpecialPower() const {
    return specialPower;
}

//setters
void Hero::setSpecialPower(string specialPower) {
    this->specialPower = specialPower; 
}

//useSpecialPower() function
void Hero::useSpecialPower() {
    cout << Character::getName() << " uses " << specialPower << "!\n";
}
void Hero::displayInfo() {
    cout << endl << Character::getName() << endl;
    cout << "Health: " << Character::getHealth() << endl;
    cout << "Level: " << Character::getLevel() << endl;
    cout << "Special Power: " << specialPower << endl; 
    cout << "MEM Address: " << this << endl; 
}


/**
 * Create the Villain Class (The Nemesis)
 * Derive a class Villain from the base class Character.
 * Add an additional private attribute evilPlan (string) that represents the villain’s master plan.
 * Implement a constructor to initialize all attributes.
 * Implement a method executePlan() that prints a message indicating that the villain is executing their evil plan.
 */
class Villain : public Character{
    string evilPlan;
public:
    Villain();
    Villain(string, int, int, string);
    ~Villain();
    string getEvilPlan() const; 
    void setEvilPlan(string); 
    void executeEvilPlan(); 
    void displayInfo() override; 
};

//default constructor
Villain::Villain() : Character() {
    Character::setName("Shai'tan");
    Character::setHealth(999);
    Character::setLevel(999);
    evilPlan = "Destroy the Wheel of Time";
}

//overloaded contructor
Villain::Villain(string name, int health, int level, string evilPlan) : Character(name, health, level) {
    Character::setName(name);
    Character::setHealth(health);
    Character::setLevel(level);
    this->evilPlan = evilPlan; 
}

//destructor
Villain::~Villain() {
    cout << "V_LOG: Villain MEM address: " << this << " has been destructed" << endl;
}

//getters
string Villain::getEvilPlan() const {
    return evilPlan; 
}

//setters
void Villain::setEvilPlan(string evilPlan) {
    this->evilPlan = evilPlan;
}

//aux functions
void Villain::executeEvilPlan() {
    cout << Character::getName() << " began execution of their evil plan to " << evilPlan << "! \n";
}

void Villain::displayInfo() {
    cout << endl << Character::getName() << endl;
    cout << "Health: " << Character::getHealth() << endl;
    cout << "Level: " << Character::getLevel() << endl;
    cout << "Evil Plan: " << evilPlan << endl;
    cout << "MEM Address: " << this << endl; 
}
/**
 * Create the Warrior Class (The Brave Fighter)
 * Derive a class Warrior from the Hero class.
 * Add an additional private attribute weapon (string) that represents the warrior’s weapon.
 * Implement a constructor to initialize all attributes.
 * Implement a method attack() that prints a message indicating that the warrior is attacking with their weapon.
 */
class Warrior : public Hero {
    string weapon; 
public: 
    Warrior();
    Warrior(string, int, int, string);
    ~Warrior();
    string getWeapon();
    void setWeapon(string);
    void attack();
    void displayInfo() override; 
};
//default constructor
Warrior::Warrior() : Hero() {
    setName("The Dude");
    setHealth(25);
    setLevel(10);
    setSpecialPower("None");
    weapon = "Short sword";
} 
//overloaded constructor 
Warrior::Warrior(string name, int health, int level, string weapon) : Hero(name, health, level, " ") {
    this->weapon = weapon; 
    Hero::setSpecialPower("None");
}
Warrior::~Warrior() {
    cout << "W_LOG: Warrior MEM address: " << this << " has been destructed" << endl; 
}
//getters
string Warrior::getWeapon() {
    return weapon;
}
//setters
void Warrior::setWeapon(string weapon) {
    this->weapon = weapon; 
}

//aux functions
void Warrior::attack() {
    cout << Character::getName() << " attacks with " << weapon << "!\n";
}
void Warrior::displayInfo() {
    cout << endl << Character::getName() << endl;
    cout << "Health: " << Character::getHealth() << endl;
    cout << "Level: " << Character::getLevel() << endl;
    cout << "Weapon: " << weapon << endl; 
    cout << "MEM Address: " << this << endl; 
}

/**
 * Create the Mage Class (The Wise Spellcaster)
 * Derive a class Mage from the Hero class.
 * Add an additional private attribute spell (string) that represents the mage’s powerful spell.
 * Implement a constructor to initialize all attributes.
 * Implement a method castSpell() that prints a message indicating that the mage is casting their spell.
 */

class Mage : public Hero {
    string spell; 
public:
    Mage();
    Mage(string, int, int, string);
    ~Mage();
    string getSpell() const;
    void setSpell(string);
    void castSpell(); 
    void displayInfo() override; 
};
//default Constructor
Mage::Mage() : Hero(){
    Character::setName("Harry Potter");
    Character::setHealth(100);
    Character::setLevel(10); 
    spell = "Expecto Patranum!"; 
}
//overloaded constructor
Mage::Mage(string name, int health, int level, string spell) : Hero(name, health, level, " "){
    this->spell = spell; 
}
//destructor
Mage::~Mage() {
    cout << "M_LOG: Mage MEM address: " << this << " has been destructed" << endl;
}

//getter
string Mage::getSpell() const {
    return spell;
}

//setter
void Mage::setSpell(string spell) {
    this->spell = spell;
}

//aux function
void Mage::castSpell() {
    cout << Character::getName() << " weaves " << spell << "!\n";
}
void Mage::displayInfo() {
    cout << endl << Character::getName() << endl;
    cout << "Health: " << Character::getHealth() << endl;
    cout << "Level: " << Character::getLevel() << endl;
    cout << "Spell: " << spell << endl;
    cout << "MEM Address: " << this << endl; 
}

/**
 * Create the DarkLord Class (The Ultimate Villain)
 * Derive a class DarkLord from the Villain class.
 * Add an additional private attribute darkMagic (string) that represents the Dark Lord’s dark powers.
 * Implement a constructor to initialize all attributes.
 * Implement a method unleashDarkMagic() that prints a message indicating that the Dark Lord is unleashing their dark magic.
 */
class DarkLord : public Villain {
    string darkMagic;
public:
    DarkLord();
    DarkLord(string, int, int, string);
    ~DarkLord();
    string getDarkMagic() const;
    void setDarkMagic(string);
    void unleashDarkMagic();
    void displayInfo() override;
};

//default constructor
DarkLord::DarkLord() : Villain(){
    Character::setName("Pinky the Brain");
    Character::setHealth(25);
    Character::setLevel(5);
    darkMagic = "World Domination";
}

//overloaded constructor
DarkLord::DarkLord(string name, int health, int level, string darkMagic) : Villain(name, health, level, " ") {
    Character::setName(name);
    Character::setHealth(health);
    Character::setLevel(level);
    this->darkMagic = darkMagic;
}

//destructor
DarkLord::~DarkLord() {
    cout << "D_LOG: DarkLord MEM address: " << this << " has been destructed" << endl;
}

//getters
string DarkLord::getDarkMagic() const {
    return darkMagic;
}
//setters
void DarkLord::setDarkMagic(string darkMagic) {
    this->darkMagic = darkMagic;
}

//aux functions
void DarkLord::unleashDarkMagic() {
    cout << Character::getName() << " has unleashed dark magic: " << darkMagic << "!\n";
}

void DarkLord::displayInfo() {
    cout << endl << Character::getName() << endl;
    cout << "Health: " << Character::getHealth() << endl;
    cout << "Level: " << Character::getLevel() << endl;
    cout << "Dark Magic: " << darkMagic << endl; 
    cout << "MEM Address: " << this << endl; 
}

int main()
{

    /**
     * Create Instances (Forming the Party and Enemies)
     * Create instances of Warrior, Mage, and DarkLord. Initialize them with names, health, level, and their respective special attributes.
     * Print the character information for each instance using displayInfo().
     */

    Hero h("Rand al'Thor", 85, 10, "Saidin");
    Warrior w("al'Lan Mandragoran", 100, 15, "The sword of the Malkier Kings");
    Mage m("Moraine Damodred, Aes Sedai of the Blue Ajah", 75, 20, "Saidar");

    DarkLord d("Lanfear, Forsaken of the Light", 150, 25, "Saidar used with true malice");

    h.displayInfo();
    w.displayInfo();
    m.displayInfo();
    d.displayInfo(); 
    /**
     * Simulate a Battle (Action Time!)
     * Call the methods attack(), castSpell(), and unleashDarkMagic() to simulate a battle between the heroes and the Dark Lord.
     */
    cout << "\nThe battle begins!" << endl << endl;

    d.unleashDarkMagic();
    h.useSpecialPower();
    w.attack();
    m.castSpell();

    /**
     * Using Pointers to Base Class (Dynamic Binding)
     * Create an array of pointers to the base class Character, and store objects of hero1, hero2, and villain in the array.
     * Iterate over the array and call the displayInfo() method on each object using dynamic binding.
     */
     
    Character* arr[4];
    
    arr[0] = &d;
    arr[1] = &h;
    arr[2] = &w;
    arr[3] = &m;
    
    for (int i = 0; i < 4; ++i)
    {
        arr[i]->displayInfo(); 
    }     
    
    cout << endl << endl; 
    return 0;
}