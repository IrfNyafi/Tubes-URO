#pragma once
#include "Kapal.h"
#include <string>
#include <vector>

class Map
{
private:
    std::string emptyCell = "  ";
    std::vector<std::vector<std::string>> arrMap = {rowMap, {colMap, std::string{emptyCell}}};
    // std::vector<std::vector<std::string>> arrMap = {rowMap, {colMap, std::string{"  "}}};
    std::vector<KapalMusuh> vectMusuh;
    std::vector<std::vector<int>> rocks;
    int jumlahMaxMusuh = 3;
    std::string rocksChar = " *";

public:
    Map();
    int generateRand(int a, int b);
    void showMap(Kapal *myShip);
    // void showMap(Kapal *myShip, std::vector<KapalMusuh>& enemyShip); // Also displaying our ship, enemy ship, and rocks

    int getMaxJumlahMusuh() { return jumlahMaxMusuh; }
    std::string getRockChar() { return rocksChar; }
    std::string getEmptyCellStr() { return emptyCell; }

    std::vector<std::vector<std::string>> const& getMap() const { return arrMap; }
    void setMap(std::vector<std::vector<std::string>> x) { arrMap = std::move(x); }

    std::vector<KapalMusuh> const& getVectMusuh() const { return vectMusuh; }
    void setVectMusuh(std::vector<KapalMusuh> y) { vectMusuh = std::move(y); }

    std::vector<std::vector<int>> const& getRocks() const { return rocks; };
    // source : https://stackoverflow.com/questions/21227060/setter-and-getter-for-vector-and-list-in-c
};