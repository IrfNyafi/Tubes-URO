#include "Map.h"
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int Map::generateRand(int a, int b)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist((double)a, b + 1.0);
    return dist(mt);
}

Map::Map()
{
    std::string rocksChar = " *";
    for (int i = 0; i < 17; ++i)
    {
        int a, b;
        do
        {
            a = generateRand(0, rowMap - 1);
            b = generateRand(0, colMap - 1);
        } while (a == rowMap / 2 && b == colMap / 2);

        rocks.push_back({a, b});
        arrMap[a][b] = rocksChar;
    }
}

void Map::showMap(Kapal *myShip)
{

    const char *hurufScale = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // if (vectMusuh.size() > 0)
    // {
    //     for (int i = 0; i < (int)vectMusuh.size(); ++i)
    //     {
    //         arrMap[vectMusuh[i].getYPos()][vectMusuh[i].getXPos()] = vectMusuh[i].getNama();
    //     }
    // }

    std::cout << std::right;
    std::cout << " |";
    for (int i = 1; i < colMap + 1; ++i)
    {
        std::cout << std::setw(2) << i << '|';
    }
    std::cout << '\n';

    std::cout << " ----";
    for (int i_hor = 1; i_hor <= 1 * rowMap; ++i_hor)
    {
        std::cout << "----";
    }
    std::cout << '\n';

    for (int i = 1; i <= 2 * rowMap; ++i)
    {
        if (i % 2 == 0)
        {
            std::cout << " ----";
            for (int i_hor = 1; i_hor <= 1 * rowMap; ++i_hor)
            {
                std::cout << "----";
            }
            std::cout << '\n';
        }
        else
        {
            int temp_i = (i + 1) / 2;
            std::cout << hurufScale[temp_i - 1] << '|';
            for (int k = 1; k <= colMap; ++k)
            {
                if (myShip->getYPos() == temp_i && myShip->getXPos() == k)
                {
                    std::cout << std::setw(2) << myShip->getNama() << '|';
                }
                else
                {
                    std::cout << std::setw(2) << arrMap[temp_i - 1][k - 1] << '|';
                }
            }
            std::cout << '\n';
        }
    }

    // for (int i = 1; i <= rowMap; ++i)
    // {
    //     std::cout << hurufScale[i - 1] << '|';
    //     for (int k = 1; k <= colMap; ++k)
    //     {
    //         if (myShip->getYPos() == i && myShip->getXPos() == k)
    //         {
    //             std::cout << std::setw(2) << myShip->getNama() << '|';
    //         }
    //         else
    //         {
    //             std::cout << std::setw(2) << arrMap[i - 1][k - 1] << '|';
    //         }
    //     }
    //     std::cout << '\n';
    // }
    std::cout << '\n';
}