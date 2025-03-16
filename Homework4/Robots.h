#ifndef ROBOTS_H
#define ROBOTS_H

#include "Grid.h"  // Ensure Grid is included for the Robot class to use it
#include <iostream>
#include <string>

class Grid;

class Robot {
protected:
    std::string name;
    int strength;
    int hitpoints;
    Grid* grid;  // Pointer to the grid where the robot is located
    int x, y;    // Position of the robot on the grid
    bool hasMoved; // Flag to check if the robot has moved in the current round
    
public:
    Robot(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y);
    virtual ~Robot();

    virtual int getDamage() = 0;
    virtual std::string getType() = 0;
    void move(); // Movement method for all robots

    void resetMovement() {
        hasMoved = false;
    }

    bool getHasMoved() const {
        return hasMoved;
    }

    void setHasMoved(bool moved) {
        hasMoved = moved;
    }

    const std::string& getName() const;
    int getStrength() const;
    int getHitpoints() const;
    void setHitpoints(int hp);
    bool isAlive() const;

    int getX() {return x;};
    int getY() {return y;};
};

class Humanic : public Robot {
public:
    Humanic(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y);
    int getDamage() override;
    virtual std::string getType() override = 0;
};

class OptimusPrime : public Humanic {
public:
    OptimusPrime(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y);
    int getDamage() override;
    std::string getType() override;
};

class RoboCop : public Humanic {
public:
    RoboCop(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y);
    int getDamage() override;
    std::string getType() override;
};

class Roomba : public Robot {
public:
    Roomba(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y);
    int getDamage() override;
    std::string getType() override;
};

class Bulldozer : public Robot {
public:
    Bulldozer(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y);
    int getDamage() override;
    std::string getType() override;
};

class Kamikaze : public Robot {
public:
    Kamikaze(const std::string &name, int strength, int hitpoints, Grid* grid, int x, int y);
    int getDamage() override;
    std::string getType() override;
    ~Kamikaze(); // Special destructor to handle self-destruct
};

#endif // ROBOTS_H
