#include <iostream>

#include "bitwa/Gracz.h"
#include "bitwa/Gra.h"

bool sprawdzDlugoscLinii(unsigned int dlugoscLinii)
{
    if(dlugoscLinii>0 && dlugoscLinii%2==0)
    {
        return true;
    }
    return false;
}
bool sprawdzMaksymalnaLiczbeTur(int liczbaTur)
{
    if(liczbaTur>0)
    {
        return true;
    }
    return false;
}
int main() {
    int dlugoscLinii=2;
    int liczbaTur=2;

//    std::cout << "Wprowadz dlugosc linii" << std::endl;
//    std::cin >> dlugoscLinii;
//
//    while (!sprawdzDlugoscLinii(dlugoscLinii))
//    {
//        std::cout << "Wprowadz dodatnia liczbe parzysta oznaczajaca dlugosc linii" << std::endl;
//        std::cin >> dlugoscLinii;
//    }
//    std::cout << "Wprowadz maksymalna liczbe tur" << std::endl;
//    std::cin >> liczbaTur;
//    while (!sprawdzMaksymalnaLiczbeTur(liczbaTur))
//    {
//        std::cout << "Wprowadz dodatnia liczbe oznaczajaca maksymalna liczbe tur" << std::endl;
//        std::cin >> liczbaTur;
//    }

    /*Wczytanie wojsk*/
    std::vector<std::vector<std::vector<char>>> tabPole /*(6)*/ = {{{'X', 'X'},{'X', 'X'},{'X', 'X'}},{{'X', 'X'},{'X', 'X'},{'X', 'X'}}};
//    char znak;
//    std::cout<<"Wprowadz wojska";
//  for(int nrWiersza=2;nrWiersza>=0;nrWiersza--)
//  {
//      for(unsigned int i=0;i<dlugoscLinii;i++)
//      {
//          tabPole.at(0).at(nrWiersza).at(i)=znak;
//      }
//  }
//    for(int nrWiersza=0;nrWiersza<=2;nrWiersza++)
//    {
//        for(unsigned int i=0;i<dlugoscLinii;i++)
//        {
//            tabPole.at(1).at(nrWiersza).at(i)=znak;
//        }
//    }
    Gra gra(liczbaTur,dlugoscLinii,tabPole);

}