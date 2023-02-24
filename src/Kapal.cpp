#include "Kapal.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <vector>

Kapal::Kapal(Map *ptrMap)
{
    xPos = (colMap - 1) / 2;
    yPos = (rowMap - 1) / 2;
    healthStatus = 10;
    copyMap = ptrMap;
}

void Kapal::showHealthStats()
{
    for (int i = 0; i < healthStatus; ++i)
    {
        std::cout << '$';
    }
    std::cout << '\n';
}

bool KapalMusuh::nameExist(std::string val, std::vector<KapalMusuh> vect)
{
    for (int i = 0; i < (int)vect.size(); ++i)
    {
        if (vect[i].Nama == val)
        {
            return true;
        }
    }
    return false;
}

KapalMusuh::KapalMusuh(Map *ptrMap) : Kapal()
{
    std::vector<std::vector<std::string>> map = ptrMap->getMap();
    std::vector<KapalMusuh> enemyShipVect = ptrMap->getVectMusuh();

    if (enemyShipVect.size() == 0)
    {
        Nama = "M1";
    }
    else
    {
        Nama = "M0";
        for (int i = 1; i <= ptrMap->getMaxJumlahMusuh(); ++i)
        {
            if (!nameExist("M" + std::to_string(i), enemyShipVect))
            {
                Nama = "M" + std::to_string(i);
                break;
            }
        }
    }

    healthStatus = 3;

    int row, col;
    do
    {
        row = ptrMap->generateRand(0, rowMap - 1);
        col = ptrMap->generateRand(0, colMap - 1);

    } while (map[row][col] != "  ");

    map[row][col] = Nama;
    ptrMap->setMap(map);
}

KapalMusuh::KapalMusuh(std::string name, Map *ptrMap) : Kapal()
{
    std::vector<std::vector<std::string>> map = ptrMap->getMap();
    Nama = name;

    healthStatus = 3;

    int row, col;
    do
    {
        row = ptrMap->generateRand(0, rowMap - 1);
        col = ptrMap->generateRand(0, colMap - 1);

    } while (map[row][col] != "  ");

    map[row][col] = Nama;
    ptrMap->setMap(map);
}