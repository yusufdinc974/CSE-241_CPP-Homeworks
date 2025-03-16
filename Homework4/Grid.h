#ifndef GRID_H
#define GRID_H

#include "Robots.h"  // Include the Robots header to use the Robot classes
#include <vector>
#include <memory>    // For smart pointers, if necessary

// Define the grid size as constants
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 10;

class Robot;

class Grid {
private:
    // 2D vector to hold pointers to Robots
    std::vector<std::vector<Robot*>> cells;

public:
    int counter = 25;

    // Constructor and destructor
    Grid();
    ~Grid();

    // Member functions to manage robots on the grid
    void addRobot(Robot* robot, int x, int y);  // Add a robot to a specific location
    void moveRobot(int fromX, int fromY, int toX, int toY);  // Move a robot within the grid
    void removeRobot(int x, int y);  // Remove a robot from the grid

    // Get a pointer to the robot at a specific location
    Robot* getRobotAt(int x, int y) const;

    // Display the grid status
    void display() const;

    // Utility functions
    bool isPositionValid(int x, int y) const;  // Check if a position is within grid bounds

    void fight(Robot* attacker, Robot* victim);
};

#endif // GRID_H
