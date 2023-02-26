#pragma once
#include <string>
#include <vector>

static const int rowMap = 10; // Tidak boleh lebih dari 26
static const int colMap = 20;

class Map;

class Kapal
{
protected:
    std::string Nama = "##";
    int xPos, yPos, healthStatus; // Koordinat sudah mengikuti konvensi map yang sudah dibuat
    Map *copyMap;
    int maxStepMove = 2;
    int banyakMusuhMati = 0;

public:
    Kapal() = default;
    Kapal(Map *ptrMap);

    int const& getXPos() const { return xPos; }
    void setXPos(int& x) { xPos = x; }

    int const& getYPos() const { return yPos; }
    void setYPos(int& y) { yPos = y; }

    void reduceHealt() { healthStatus = healthStatus - 1; }
    int getHealth() { return healthStatus; }
    void musuhMatiNambah() { banyakMusuhMati += 1; }
    int getBanyakMusuhMati() { return banyakMusuhMati; }

    std::string const& getNama() const { return Nama; }

    int move(std::string targetPos, Map *ptrMap); // return 1 jika berhasil move, otherwise 0
    void shoot(std::string coor, Map *ptrMap);
    void showHealthStats();
    std::vector<int> translationToCoordinat(std::string& targetPos);
    std::string translationToStrCoor(int row, int col);
};

class KapalMusuh : public Kapal
{

public:
    KapalMusuh(Map *ptrMap);
    KapalMusuh(std::string name, Map *ptrMap);
    bool nameExist(std::string val, std::vector<KapalMusuh> vect);
    void die(Map *ptrMap);
    int distanceToShip(int& xTar, int& yTar, int& xShip, int& yShip);
    void moveCloser(Kapal *myShip, Map *ptrMap);
    std::vector<std::string> koleksiMove(Map *ptrMap);
};