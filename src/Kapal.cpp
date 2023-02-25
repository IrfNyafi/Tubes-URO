#include "Kapal.h"
#include "Map.h"
#include <cstdlib>
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

// std::vector<int> Kapal::translationAbsToRel(std::string targetPos) // Accepted format move e.g. "A13"
std::vector<int> Kapal::translationToCoordinat(std::string& targetPos)
{
    const char *hurufScale = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char letter = targetPos[0];
    std::string number = targetPos.substr(1);

    std::vector<int> tempResult(2, 0);
    tempResult[1] = stoi(number) - 1; // for xRel

    int indexHurufScale = -1;
    for (int i = 0; i < 26; ++i)
    {
        if (letter == hurufScale[i])
        {
            indexHurufScale = i;
        }
    }

    if (indexHurufScale != -1)
    {
        tempResult[0] = indexHurufScale;
    }

    return tempResult;
}

int Kapal::move(std::string targetPos, Map *ptrMap) // return 1 jika berhasil move, otherwise 0
{
    std::vector<std::vector<std::string>> map = ptrMap->getMap();
    std::vector<int> coordinatTarget = translationToCoordinat(targetPos); // Index 0 for Y coordinate and 1 for X coordinat
    int yTarget = coordinatTarget[0];
    int xTarget = coordinatTarget[1];

    if (map[yTarget][xTarget] == ptrMap->getRockChar())
    {
        std::cerr << "\nYou hit a rock!\n";
        return 0;
    }

    if (std::abs(yTarget - yPos) + std::abs(xTarget - xPos) > maxStepMove)
    {
        std::cerr << "\nToo many move. The number of maximum move step is " << maxStepMove << '\n';
        return 0;
    }

    map[yPos][xPos] = ptrMap->getEmptyCellStr();
    yPos = yTarget;
    xPos = xTarget;

    ptrMap->setMap(map);
    return 1;
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

std::vector<std::string> KapalMusuh::koleksiMove(KapalMusuh *musuh, Map *ptrMap)
{
    std::vector<std::string> tempResult;
}