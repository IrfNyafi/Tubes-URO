#pragma once
#include <string>
#include <vector>

static const int rowMap = 15;
static const int colMap = 21;

class Map;

class Kapal
{
protected:
    std::string Nama = "##";
    int xPos, yPos, healthStatus;
    Map *copyMap;

public:
    Kapal() = default;
    Kapal(Map *ptrMap);

    int const& getXPos() const { return xPos; }
    int const& getYPos() const { return yPos; }
    std::string const& getNama() const { return Nama; }

    void move(int& xRel, int& yRel, Map& statusLoc);
    void shoot(Kapal& musuh, Map& statusLoc);
    void showHealthStats();
    std::vector<int> getValidPos(Map *ptrMap);
};

class KapalMusuh : public Kapal
{

public:
    KapalMusuh(Map *ptrMap);
    KapalMusuh(std::string name, Map *ptrMap);
    bool nameExist(std::string val, std::vector<KapalMusuh> vect);
    void die(Map& statusLoc);
    void distanceToShip(Kapal& myShip, Map& statusLoc);
    void moveCloser(Map& statusLoc);
};