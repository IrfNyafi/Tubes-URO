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
    std::vector<KapalMusuh> tempInitialize = {m1, m2, m3};
    peta.setVectMusuh(tempInitialize);

    peta.showMap(&myShip);

    std::cout << "\n\nCheck Move\n\n";

    std::string move;
    std::cout << "Perintah Move: ";
    std::cin >> move;

    myShip.move(move, &peta);
    peta.showMap(&myShip);

    return 0;
}