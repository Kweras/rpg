#include <iostream>
 
 
using namespace std;
 
class postac
{
const int ILETOZSAMOSCI=20;   //maksymalna ilość tożsamości w grze
  
private: //modyfikator dostępu private
     double sila; // zmienna składowa klasy
      bool plec;
    int wiek;
     int tozsamosc; //kim jest
    string opisPostaci[2]; //Biografia, Wygląd
 
public: //modyfikator dostępu public
      string imie, nazwisko, nick;
    int ekwipunek[20];
     int umiejetnosci[30]; // wartosci od 0-9, 1. Bieganie 2. Walka wręcz, 3. Dowodzenie ...., 4. Umiejętność myślenia abstrakcyjnego
      int CzynnikGenetyczny[3]; // Mięśnie, Neurony i Hormony (M, N, H) // na starcie 9pkt tzw. punkty urodzenia
    int CzynnikiRozwoju[3]; //Kontrola Mięśni, Kontrola Neuronów i Kontrola Hormonów (KM, KN, KH)
     int Cechy[12];
       
     postac(int M, int N, int H, int KM, int KN, int KH, int psila, bool pplec, int pwiek, int ptozsamosc){  // funkcja skladowa klasy z argumentami
       
     if((psila>9) || (pplec!=0 && pplec!=1) || (tozsamosc>=0 && tozsamosc<ILETOZSAMOSCI)){
         cout<<"\nŹle zinicjalizowane dane: nie zgadza się zakres";
       if(psila>9) cout <<" siły";
        else if (pplec!=0 && pplec!=1) cout <<" płci";
        else if (tozsamosc>=0 && tozsamosc<ILETOZSAMOSCI) cout <<" tożsamosci";
       else cout << "";
       cout<<endl;
      }
    Cechy[0]=H+KH*5; //Charyzma
     Cechy[1]=H*10; //Czujność
    Cechy[2]=N+KH*5; //Inteligencja  
     Cechy[3]=N*10; //Pamięć 
     sila=psila; plec=pplec; wiek=pwiek; tozsamosc=ptozsamosc;
     }
    void modToz(int Toz){ // modyfikuj tożsamość. Lista zawarta w pokazTozsamosc()
     tozsamosc=Toz;
      }
    void pokazTozsamosc(); // pokazuje tożsamość w oparciu o przypisaną wartość: tozsamosc
       
     int pokaz(bool psila, bool pplec, bool pwiek, bool ptozsamosc){
        if (psila) return sila;
         else if (pplec) return plec;
       else if (pwiek) return wiek;
       else if (ptozsamosc) return tozsamosc;
         else return -1;
        }
 
protected: //modyfikator dostępu protected   
 
  
};
/*
class walka{
     
  int walcz(postac przeciwnik1, postac przeciwnik2){
      TUTAJ COŚ BĘDZIE
    }
  
  return tab;
   };
*/
int main(int argc, char **argv)
{
 
 postac Rycerz=postac(3,3,3,2,2,2,5,0,25,13); //tworzenie konstruktora M,N,H,KM,KN,KH,sila,plec,wiek,tozsamosc
 postac*RycerzWsk; // wskaźnik do rycerza
 RycerzWsk=&Rycerz;
 RycerzWsk->imie="Gerard";
 RycerzWsk->modToz(4);
  cout<<"Siła osoby: "<<RycerzWsk->imie<<" wynosi "<<RycerzWsk->pokaz(1,0,0,0)<<endl;
   cout<<RycerzWsk->imie<<" to ";
  RycerzWsk->pokazTozsamosc();
  
  postac Krasnolud(3,3,3,2,2,2,10,0,25,3); //drugi sposób na tworzenie konstruktora
                                 // źle zinicjalizowane dane konstruktora
                                  // wartość 10 nie jest tutaj możliwa (<10)
 postac*KrasnoludWsk; // wskaźnik do krasnoluda
 KrasnoludWsk=&Krasnolud;
 KrasnoludWsk->imie="Yarpen Zigrin";
   KrasnoludWsk->modToz(5);
  cout<<"\n\nSiła osoby: "<<KrasnoludWsk->imie<<" wynosi "<<KrasnoludWsk->pokaz(1,0,0,0)<<endl;
  cout<<KrasnoludWsk->imie<<" to ";
  KrasnoludWsk->pokazTozsamosc();
 return 0;
}
 
  void postac::pokazTozsamosc(){
        string tozsamoscTab[20]={"król", "królowa", "książe", "księżniczka", "rycerz", "krasnolud"}; 
 
       if (tozsamosc>=0 && tozsamosc<ILETOZSAMOSCI) cout <<tozsamoscTab[this->tozsamosc];//cout<< tozsamoscTab[Toz];
        else cout<< "niezdefiniowana";
        }
