#pragma once
#include <string>
#include <vector>

static const int rowMap = 15; // Tidak boleh lebih dari 26
static const int colMap = 20;

class Map;

class Kapal
{
protected:
    std::string Nama = "##";
    int xPos, yPos, healthStatus; // Koordinat sudah mengikuti konvensi map yang sudah dibuat
    Map *copyMap;
    int maxStepMove = 2;

public:
    Kapal() = default;
    Kapal(Map *ptrMap);

    int const& getXPos() const { return xPos; }
    int const& getYPos() const { return yPos; }
    std::string const& getNama() const { return Nama; }

    int move(std::string targetPos, Map *ptrMap); // return 1 jika berhasil move, otherwise 0
    void shoot(Kapal& musuh, Map *ptrMap);
    void showHealthStats();
    std::vector<int> getValidPos(Map *ptrMap);
    std::vector<int> translationToCoordinat(std::string& targetPos);
    std::string translationToStr (int a, int b);
};

class KapalMusuh : public Kapal
{

public:
    KapalMusuh(Map *ptrMap);
    KapalMusuh(std::string name, Map *ptrMap);
    bool nameExist(std::string val, std::vector<KapalMusuh> vect);
    void die(Map *ptrMap);
    void distanceToShip(Kapal& myShip, Map *ptrMap);
    void moveCloser(Map *ptrMap);
    std::vector<std::string> koleksiMove(KapalMusuh *musuh, Map *ptrMap);
};