#include "Map.h"
#include <iostream>
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

    return 0;
}