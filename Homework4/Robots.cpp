#include "Robots.h"
#include <cstdlib>  // For random functionality
#include <ctime>    // For seeding random number generator



// Primary constructor
Robot::Robot(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y)
: name(name), strength(strength), hitpoints(hitpoints), grid(grid), x(x), y(y) {
    hasMoved = false;
    if (grid) grid->addRobot(this, x, y);
}
// Destructor
Robot::~Robot() {

    grid->removeRobot(x, y);
    
}

void Robot::move() {
    if (hasMoved || !grid) return; // If already moved or grid is not set, return.

    int direction = rand() % 4; // 0: up, 1: right, 2: down, 3: left
    int newX = x, newY = y;

    switch (direction) {
        case 0: newY--; break;
        case 1: newX++; break;
        case 2: newY++; break;
        case 3: newX--; break;
    }

    if (grid->isPositionValid(newX, newY)) {
        if (grid->getRobotAt(newX, newY) == nullptr) {
            grid->moveRobot(x, y, newX, newY);
            x = newX;
            y = newY;
        } else {
            grid->fight(this, grid->getRobotAt(newX, newY));
        }
    }

    hasMoved = true;
}


const std::string& Robot::getName() const {
    return name;
}

int Robot::getStrength() const {
    return strength;
}

int Robot::getHitpoints() const {
    return hitpoints;
}

void Robot::setHitpoints(int hp) {
    hitpoints = hp;
}

bool Robot::isAlive() const {
    return hitpoints > 0;
}

// Constructor for Humanic
Humanic::Humanic(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y)
: Robot(name, strength, hitpoints, grid, x, y) {}

// getDamage implementation for Humanic
int Humanic::getDamage() {
    int baseDamage = (rand() % strength) + 1; // All robots inflict damage based on strength
    int nukeChance = rand() % 10; // 10% chance for tactical nuke attack
    if (nukeChance == 0) {
        baseDamage += 50; // Adds tactical nuke damage
        std::cout << name << " launches a tactical nuke attack, dealing an additional 50 damage!" << std::endl;
    }
    std::cout << name << " attacks for " << baseDamage << " damage points!" << std::endl;
    return baseDamage;
}

// Constructor for OptimusPrime
OptimusPrime::OptimusPrime(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y)
: Humanic(name, strength, hitpoints, grid, x, y) {}

// getDamage implementation for OptimusPrime
int OptimusPrime::getDamage() {
    int baseDamage = Humanic::getDamage(); // Get base damage from Humanic
    int strongAttackChance = rand() % 100;
    if (strongAttackChance < 15) { // 15% chance to double the damage
        baseDamage *= 2;
        std::cout << name << " executes a strong attack, doubling the damage to " << baseDamage << " points!" << std::endl;
    }
    return baseDamage;
}

// getType implementation for OptimusPrime
std::string OptimusPrime::getType() {
    return "OptimusPrime";
}

// Constructor for RoboCop
RoboCop::RoboCop(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y)
: Humanic(name, strength, hitpoints, grid, x, y) {}

// getDamage implementation for RoboCop
int RoboCop::getDamage() {
    // Since RoboCop's combat capabilities are inherited directly from Humanic
    // and there's no additional unique combat behavior specified,
    // we simply call the Humanic version of getDamage.
    return Humanic::getDamage();
}

// getType implementation for RoboCop
std::string RoboCop::getType() {
    return "RoboCop";
}

// Constructor for Roomba
Roomba::Roomba(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y)
: Robot(name, strength, hitpoints, grid, x, y) {}

// getDamage implementation for Roomba
int Roomba::getDamage() {
    // Roomba attacks twice each turn. The damage for each attack is calculated and summed.
    int totalDamage = 0;
    for (int i = 0; i < 2; ++i) { // Roomba attacks twice
        int attackDamage = (rand() % strength) + 1;
        totalDamage += attackDamage;
    }
    std::cout << name << " attacks twice for a total of " << totalDamage << " damage points!" << std::endl;
    return totalDamage;
}

// getType implementation for Roomba
std::string Roomba::getType() {
    return "Roomba";
}

// Constructor for Bulldozer
Bulldozer::Bulldozer(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y)
: Robot(name, strength, hitpoints, grid, x, y) {}

// getDamage implementation for Bulldozer
int Bulldozer::getDamage() {
    // Simplicity assumed here, with damage based purely on strength
    int damage = (rand() % strength) + 1;
    std::cout << name << " bulldozes through, dealing " << damage << " damage points!" << std::endl;
    return damage;
}

// getType implementation for Bulldozer
std::string Bulldozer::getType() {
    return "Bulldozer";
}

// Constructor for Kamikaze
Kamikaze::Kamikaze(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y)
: Robot(name, strength, hitpoints, grid, x, y) {}

// getDamage implementation for Kamikaze
int Kamikaze::getDamage() {
    std::cout << name << " explodes, dealing its total hitpoints (" << hitpoints << ") in damage!" << std::endl;
    int damage = hitpoints; // Kamikaze inflicts damage equal to its hitpoints
    hitpoints = 0; // Kamikaze explodes, thus it dies immediately

    // Optionally, if the grid management allows, remove from grid directly here
    if (grid) {
        grid->removeRobot(x, y); // Ensure this method properly handles the deletion or nullification
    }

    return damage;
}


// Destructor for Kamikaze
Kamikaze::~Kamikaze() {
    // The Kamikaze robot "self-destructs" after attacking, no additional action needed here since we're not managing dynamic memory
    std::cout << name << " has self-destructed!" << std::endl;
}

// getType implementation for Kamikaze
std::string Kamikaze::getType() {
    return "Kamikaze";
}