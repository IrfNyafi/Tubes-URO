#include "Map.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    Map peta;
    Kapal myShip(&peta);
    KapalMusuh m1("M1", &peta);
    KapalMusuh m2("M2", &peta);
    KapalMusuh m3("M3", &peta);
    // KapalMusuh foo(" ", &peta);
    std::vector<KapalMusuh> tempInitialize = {m1, m2, m3};
    peta.setVectMusuh(tempInitialize);

    while (myShip.getHealth() < 0)
    {
        system("clear");

        std::cout << "Your Health Status: ";
        myShip.showHealthStats();
        std::cout << "Enemy Health:\n";
        for (KapalMusuh musuh : peta.getVectMusuh())
        {
            std::cout << musuh.getNama() << ": ";
            musuh.showHealthStats();
        }
        std::cout << '\n';

        peta.showMap(&myShip);

        std::cout << "[1] Bergerak!\n"
                  << "[2] Menembak!\n";
        std::cout << "Tentukan Pilihan Anda: ";

        int pilihan;
        std::cin >> pilihan;

        std::cout << '\n';
        if (pilihan == 1)
        {
            std::string move;
            std::cout << "Perintah Move: ";
            std::cin >> move;
            myShip.move(move, &peta);
        }
        else if (pilihan == 2)
        {
            std::cout << "Masukkan koordinat tembak: ";
            std::string coordinatTembak;
            std::cin >> coordinatTembak;
            myShip.shoot(coordinatTembak, &peta);
            system("clear");

            std::cout << "Your Health Status: ";
            myShip.showHealthStats();
            std::cout << "Enemy Health:\n";
            for (KapalMusuh musuh : peta.getVectMusuh())
            {
                std::cout << musuh.getNama() << ": ";
                musuh.showHealthStats();
            }
        }

        for (KapalMusuh musuh : peta.getVectMusuh())
        {
            musuh.moveCloser(&myShip, &peta);
        }

        std::cout << "Kapal yang berhasil Anda tenggelamkan adalah " << myShip.getBanyakMusuhMati() << " kapal\n";
    }
    return 0;
}