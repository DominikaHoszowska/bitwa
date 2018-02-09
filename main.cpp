#include <iostream>

#include "bitwa/Gracz.h"
#include "bitwa/Gra.h"
using std::vector;
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
    int dlugoscLinii;
    int liczbaTur;

    std::cout << "Wprowadz dlugosc linii" << std::endl;
    std::cin >> dlugoscLinii;

    while (!sprawdzDlugoscLinii(dlugoscLinii))
    {
        std::cout << "Wprowadz dodatnia liczbe parzysta oznaczajaca dlugosc linii" << std::endl;
        std::cin >> dlugoscLinii;
    }
    std::cout << "Wprowadz maksymalna liczbe tur" << std::endl;
    std::cin >> liczbaTur;
    while (!sprawdzMaksymalnaLiczbeTur(liczbaTur))
    {
        std::cout << "Wprowadz dodatnia liczbe oznaczajaca maksymalna liczbe tur" << std::endl;
        std::cin >> liczbaTur;
    }

    /*Wczytanie wojsk*/
    std::vector<std::vector<std::vector<char>>> tabPole(2,vector<vector<char>>(3));
    char znak;
    std::cout<<"Wprowadz wojska";
  for(int nrWiersza=2;nrWiersza>=0;nrWiersza--)
  {
      for( int i=0;i<dlugoscLinii;i++)
      {
          std::cin>>znak;
          tabPole.at(0).at(nrWiersza).push_back(znak

          );
      }
  }
    for(int nrWiersza=0;nrWiersza<=2;nrWiersza++)
    {
        for( int i=0;i<dlugoscLinii;i++)
        {

            std::cin>>znak;
            tabPole.at(1).at(nrWiersza).push_back(znak);
        }
    }
    Gra gra(liczbaTur,dlugoscLinii,tabPole);
    gra.wypisz();
    while(!gra.czyKoniec())
    {
        gra.rozegrajTure();
    }
    char a;
    std::cin>>a;
}