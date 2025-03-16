#include <cstdlib>  // For rand and srand
#include <ctime>    // For time
#include <iostream>
#include <vector>
#include "Grid.h"   // Assuming Grid and Robot definitions are in these headers
#include "Robots.h"

int main() {
    Grid grid;

    // Seed the random number generator
    srand(time(NULL));

    // Create robots and add them to the grid
    // Since we need unique names for robots, let's append an index to their type as a simple identifier
    std::vector<Robot*> robots;
    int initialCount = 5;  // Initial count of each type of robot
    int typesOfRobots = 5; // Total types of robots
    int gridWidth = 10;    // Assuming grid width is 10
    int gridHeight = 10;   // Assuming grid height is 10

    // Store types in a struct or simple class (if not already defined)
    struct RobotInfo {
        std::string type;
        int strength;
        int hitpoints;
    };

    std::vector<RobotInfo> robotTypes = {
        {"OptimusPrime", 100, 100},
        {"RoboCop", 30, 40},
        {"Roomba", 3, 10},
        {"Bulldozer", 50, 200},
        {"Kamikaze", 10, 10}
    };

    // Create and place robots of each type
    for (int typeIndex = 0; typeIndex < typesOfRobots; ++typeIndex) {
        for (int i = 0; i < initialCount; ++i) {
            int x, y;
            // Find an unoccupied position
            do {
                x = rand() % gridWidth;
                y = rand() % gridHeight;
            } while (grid.getRobotAt(x, y) != nullptr);

            Robot* robot = nullptr;
            std::string robotName = robotTypes[typeIndex].type + "_" + std::to_string(i);
            int strength = robotTypes[typeIndex].strength;
            int hitpoints = robotTypes[typeIndex].hitpoints;

            if (robotTypes[typeIndex].type == "OptimusPrime") {
                robot = new OptimusPrime(robotName, strength, hitpoints, &grid, x, y);
            } else if (robotTypes[typeIndex].type == "RoboCop") {
                robot = new RoboCop(robotName, strength, hitpoints, &grid, x, y);
            } else if (robotTypes[typeIndex].type == "Roomba") {
                robot = new Roomba(robotName, strength, hitpoints, &grid, x, y);
            } else if (robotTypes[typeIndex].type == "Bulldozer") {
                robot = new Bulldozer(robotName, strength, hitpoints, &grid, x, y);
            } else if (robotTypes[typeIndex].type == "Kamikaze") {
                robot = new Kamikaze(robotName, strength, hitpoints, &grid, x, y);
            }

            // Add the robot to the vector for management and cleanup purposes
            robots.push_back(robot);
        }
    }

    // Display the initial grid setup
    std::cout << "Initial grid setup:" << std::endl;
    grid.display();

    while (grid.counter > 1) {
        // Reset movement flags at the start of each round
        for (Robot* robot : robots) {
            robot->resetMovement();
        }

        // Each robot moves once per round
        for (Robot* robot : robots) {
            if (!robot->getHasMoved() && robot->isAlive()) {
                robot->move();
            }
        }

        // Display the grid after one round of moves
        std::cout << "Grid after one round of moves:" << std::endl;
        grid.display();
    }
    std::cout << "out" << std::endl;

    return 0;
}
