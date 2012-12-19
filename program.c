#include <stdio.h>

struct osoba {
    unsigned int ID;
    char nazwisko[20];
}osoby[61];

int sprawdzanie(){
        int z,i=0,id;

        do{
                printf("\nWprowadz ID:");
                scanf("%i",&id);

                for(z=0;z<61;z++)
                        if(osoby[z].ID == id){
                                i=z;
                                printf("ID zajete, podaj inne.");
                                //getchar();
                        }
        }while(osoby[i].ID == id);
        return id;
}

int hashowanie(int ID){
        int i=0,numerh;

        do{
                numerh = h(ID,i);
                if(osoby[numerh].ID == 0)
                        return numerh;
                i++;
                if(i == 61)
                        return i;
        }while(osoby[numerh].ID != 0);
}

int wyswietlanie() {
        int i=0,id;

        printf("\n\n\nPodaj ID:");
        scanf("%i",&id);
        while(i<61)
        {
            if (osoby[h(id,i)].ID == id) {
            //sprawdzanie hashowanegoid z naszym id podanym.
                printf("Do podanego ID: %i przypisane jest nazwisko: %s",id,osoby[(id%61+i*(1+id%59))%61].nazwisko);
                //getchar();
                return;
            }

            if (osoby[h(id,i)].ID == 0) {
                printf("Takiego ID nie ma na liscie...");
                //getchar();
                return;
            } else {
                i++; //jezeli nie znajdzie takido id i++
            }

            printf("Takiego ID nie ma na liscie...");
            //getchar();
            return;
        }
}

//Hashing function
int h(int id, int i)
{
    return (id%61+i*(1+id%59))%61;
}

int main() {
        int i,z,id,numerh;
        char nazwis[20];

        for(i=0;i<61;i++)// wprowadzenie zer do calej listy
            osoby[i].ID=0;

        while (i!=0) {
                printf ("\n\n\tMENU\n\n");
                printf("0 - Zakoncz\n");
                printf("1 - Dodaj rekord (nazwisko)\n");
                printf("2 - Wyswietlanie rekordu (nazwiska)\n");
                printf("3 - Wyswietl wszystko\n\n");
                printf("Podaj wybor: ");
                scanf("%i",&i);

                switch(i){
                        case 1:
                                id = sprawdzanie();
                                printf("Podaj nazwisko:");
                                scanf("%s",nazwis);
                                printf("id: %i \n", id);
                                numerh = hashowanie(id);
                                printf("numerh: %i\n", numerh);
                                if(numerh == 61)
                                {
                                    printf("\nLista jest juz zapelniona");
                                } else {
                                    osoby[numerh].ID = id;
                                    for(z=0;z<20;z++)
                                    {
                                        osoby[numerh].nazwisko[z] = nazwis[z];
                                    }
                                    printf("Nazwisko zostalo dodane na pozycji: %i...",numerh);
                                }
                                //getchar();
                        break;
                        case 2:
                                wyswietlanie();
                        break;
                        case 3:
                                for(z=0;z<61;z++)
                                {
                                    printf("\n\t#%2i|%5i|%10s",z,osoby[z].ID,osoby[z].nazwisko);
                                }
                                //getchar();
                        break;
                        case 0:
                                return 0;
                        break;
                        default:
                                printf("Wprowadz odpowienia wartosc...");
                                //getchar();
                        break;
                }
        }
        return 0;
}
