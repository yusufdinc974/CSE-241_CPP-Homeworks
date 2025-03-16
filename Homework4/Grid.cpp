#include "Grid.h"
#include <iostream>

// Constructor
Grid::Grid() : cells(GRID_HEIGHT, std::vector<Robot*>(GRID_WIDTH, nullptr)) {}

// Destructor
Grid::~Grid() {
    if(counter == 1){
        for (auto& row : cells) {
            for (auto& robot : row) {
                delete robot;
                robot = nullptr;
            }
        }
    }
}

// Fight between two robots
void Grid::fight(Robot* attacker, Robot* victim) {
    if (!attacker->isAlive() || !victim->isAlive()) {
        if (!attacker->isAlive()) {
            removeRobot(attacker->getX(), attacker->getY());
        }
        if (!victim->isAlive()) {
            removeRobot(victim->getX(), victim->getY());
        }
        return; // Exit if either is not alive at the start of the fight
    }

    while (attacker->isAlive() && victim->isAlive()) {
        // Attacker attacks victim
        int damageAttacker = attacker->getDamage();
        victim->setHitpoints(victim->getHitpoints() - damageAttacker);
        std::cout << attacker->getName() << "(" << attacker->getHitpoints() << ") hits "
                  << victim->getName() << "(" << victim->getHitpoints() + damageAttacker << ") with "
                  << damageAttacker << std::endl;
        std::cout << "The new hitpoints of " << victim->getName() << " is " << victim->getHitpoints() << std::endl;

        // Check if victim is still alive after the attack
        if (!victim->isAlive()) {
            std::cout << victim->getName() << " is dead." << std::endl;
            removeRobot(victim->getX(), victim->getY()); // Remove dead robot from the grid
            return;
        }

        // Victim retaliates
        int damageVictim = victim->getDamage();
        attacker->setHitpoints(attacker->getHitpoints() - damageVictim);
        std::cout << victim->getName() << "(" << victim->getHitpoints() << ") hits "
                  << attacker->getName() << "(" << attacker->getHitpoints() + damageVictim << ") with "
                  << damageVictim << std::endl;
        std::cout << "The new hitpoints of " << attacker->getName() << " is " << attacker->getHitpoints() << std::endl;  

        // Check if attacker is still alive after the retaliation
        if (!attacker->isAlive()) {
            std::cout << attacker->getName() << " is dead." << std::endl;
            removeRobot(attacker->getX(), attacker->getY()); // Remove dead robot from the grid
            return;
        }
    }
}

void Grid::removeRobot(int x, int y) {
    if (isPositionValid(x, y) && cells[y][x] != nullptr) {
        cells[y][x] = nullptr; 
        counter--;
    } else {
        //sstd::cerr << "Attempt to delete a non-existing robot or invalid position." << std::endl;
    }
}


// Add a robot to a specific location
void Grid::addRobot(Robot* robot, int x, int y) {
    if (isPositionValid(x, y) && !cells[y][x]) {
        cells[y][x] = robot;
    } else {
       // std::cerr << "Failed to add robot: Invalid position or cell already occupied." << std::endl;
    }
}

// Move a robot within the grid
void Grid::moveRobot(int fromX, int fromY, int toX, int toY) {
    if (isPositionValid(fromX, fromY) && isPositionValid(toX, toY) && cells[fromY][fromX]) {
        if (cells[toY][toX] == nullptr) {
            cells[toY][toX] = cells[fromY][fromX];
            cells[fromY][fromX] = nullptr;
        } else {
            fight(cells[fromY][fromX], cells[toY][toX]);
        }
    } else {
       // std::cerr << "Failed to move robot: Invalid start or destination position." << std::endl;
    }
}


// Get a pointer to the robot at a specific location
Robot* Grid::getRobotAt(int x, int y) const {
    if (isPositionValid(x, y)) {
        return cells[y][x];
    }
    return nullptr;
}

// Display the grid status
void Grid::display() const {
    std::cout << "Grid status:" << std::endl;
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (cells[y][x]) {
                std::cout << cells[y][x]->getType()[0] << " ";  // Display first letter of the robot type
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

// Check if a position is within grid bounds
bool Grid::isPositionValid(int x, int y) const {
    return x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT;
}
