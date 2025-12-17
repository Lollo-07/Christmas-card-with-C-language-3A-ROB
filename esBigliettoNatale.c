/*
Lorenzo Bruno;
22/12/2023
esBigliettoNatale
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "utility.h"
#include "baseGraficaBruno.h"
#define RED 68
#define WHITE 255
#define BLACK 0
#define GREY 136
#define PINK 238
#define YELLOW 102
#define GREEN 34
#define BLUE 17
#define WIDTH 120
#define HEIGHT 40
#define PURPLE 221
#define ALTEZZANEVE 4
#define CASETTAX 93
#define CASETTAY 34
#define ALBEROX 63
#define ALBEROY 32
#define ALTEZZAALBERO 10
#define PUAPAZZOX 15
#define PUPAZZOY 35



void Casetta(int x, int y){
    int puntoInizioColonne, altezzaColonne, colonna2x;                                    //Dichiarazione variabili per le colonne nere della casetta
    int verticeTriangoloNerox, verticeTriangoloNeroy, altezzaTriangoloNero;    //Dichiarazione variabili per il vertice dei triangoli del tetto della casetta
    int facciataCasettax, facciataCasettay, baseFacciataCasetta, altezzaFacciataCasetta;  //Dichiarazione Variabili facciata rettangolare casetta
    int facciataLateralex, baseLateraleCasetta;                                           //Dichiarazione variabili facciata casetta
    int rigaTettoBassax, lunghezzaRigaTettoBassa, rigaTettoAltax, lunghezzaRigaTettoAlta; //Dichiarazione variabili per linee tetto nere
    int rigaNeveTettox, rigaNeveTettoy, lunghezzarigaNeveTetto;                           //Dichiarazione variabili per linee che fanno la neve sul tetto
    int portax, portay, latoPorta, manigliax, manigliay;                                  //Dichiarazione variabili per porta e maniglia
    int finestra1x, finestra2x, finestrey, baseFinestre, altezzaFinestre;
    puntoInizioColonne = y - 5;
    altezzaColonne = 7;
    colonna2x = x + 14;
    verticeTriangoloNerox = x + 7;
    verticeTriangoloNeroy = y - 11;
    altezzaTriangoloNero = 7;
    facciataCasettax = x + 1;
    facciataCasettay = y - 4;
    baseFacciataCasetta = 13;
    altezzaFacciataCasetta = 6;
    baseLateraleCasetta = 12;
    facciataLateralex = x + 15;
    rigaTettoBassax = x + 15;
    lunghezzaRigaTettoBassa = 12;
    rigaTettoAltax = x + 8;
    lunghezzaRigaTettoAlta = 19;
    rigaNeveTettox = x + 9;
    rigaNeveTettoy = y - 10;
    lunghezzarigaNeveTetto = 17;
    portax = x + 5;
    portay = y - 3;
    latoPorta = 5;
    manigliax = x + 6;
    manigliay = y - 1;
    finestra1x = x + 17;
    finestra2x = x + 23;
    finestrey = y - 2;
    baseFinestre = 3;
    altezzaFinestre = 2;
    colonnaColore(x, puntoInizioColonne, altezzaColonne, '*', BLACK);                          //Colonna di sinistra
    colonnaColore(colonna2x, puntoInizioColonne, altezzaColonne, '*', BLACK);                     //Colonna di destra
    triangoloColore(verticeTriangoloNerox, verticeTriangoloNeroy, altezzaTriangoloNero, '*', BLACK);                    //Triangolo nero che viene
    triangoloColore(verticeTriangoloNerox, verticeTriangoloNeroy + 1, altezzaTriangoloNero - 1, '*', RED);              //Sovrapposto da quello rosso
    rettangoloPienoColore(facciataCasettax, facciataCasettay, baseFacciataCasetta, altezzaFacciataCasetta, '*', RED);   //Facciata rettangolare casetta
    rettangoloPienoColore(facciataLateralex, facciataCasettay, baseLateraleCasetta, altezzaFacciataCasetta, '*', RED);  //Facciata laterale casetta
    rigaColore(rigaTettoBassax, puntoInizioColonne, lunghezzaRigaTettoBassa, '*', BLACK);                               //Righe nere che delimitano il tetto
    rigaColore(rigaTettoAltax, verticeTriangoloNeroy, lunghezzaRigaTettoAlta, '*', BLACK);
    rigaColore(rigaNeveTettox, rigaNeveTettoy, 18, '*', WHITE);                                                         //5 righe per la neve
    rigaColore(rigaNeveTettox + 1, rigaNeveTettoy + 1, lunghezzarigaNeveTetto, '*', WHITE);
    rigaColore(rigaNeveTettox + 2, rigaNeveTettoy + 2, lunghezzarigaNeveTetto - 1, '*', WHITE);
    rigaColore(rigaNeveTettox + 3, rigaNeveTettoy + 3, lunghezzarigaNeveTetto - 2, '*', WHITE);
    rigaColore(rigaNeveTettox + 4, rigaNeveTettoy + 4, lunghezzarigaNeveTetto - 3, '*', WHITE);
    quadratoPienoColore(portax, portay, latoPorta, '*', GREY);                                                          //Porta
    puntoColore(manigliax, manigliay, '*', PINK);                                                                       //Maniglia
    rettangoloPienoColore(finestra1x, finestrey, baseFinestre, altezzaFinestre, '*', YELLOW);                           //Finestra 1                                                       //Finestra 1
    rettangoloPienoColore(finestra2x, finestrey, baseFinestre, altezzaFinestre, '*', YELLOW);                           //Finestra 2                                                           //Finestra 2
    }


    void Albero(int x, int y, int alt){

        int troncox, troncoy, lunghezzaRighe;                                   //Dichiarazione variabili per albero

        int cont = 0;
        for(int k = alt; k > 0; k--){                                           //Il for che crea la parte verde dell'albero, la formula
            lunghezzaRighe = 2 * k - 1;                                         //2 * k + 1 permette di costruirlo con due quadratini in
            rigaColore(x + cont, y - cont, lunghezzaRighe, '*', GREEN);         //più ogni riga.
            cont++;
        }

        troncox = x + alt - (2 * alt - 1) % 2 - 2;                               //Formula per far si che ovunque si posizioni l'albero
        troncoy = y + 1;
        int stellaAlberox = 71;
        int stellaAlberoy = 21;                                                        //il tronco sia sempre in mezzo.
        rettangoloPienoColore(troncox, troncoy, 5, 3, '*', GREY);
        rigaColore(stellaAlberox, stellaAlberoy, 3, '*', YELLOW);
        puntoColore(stellaAlberox + 1, stellaAlberoy + 1, '*', YELLOW);
        puntoColore(stellaAlberox + 1, stellaAlberoy - 1, '*', YELLOW);

         for(int contPalline = 0; contPalline < 40; contPalline ++){             //For per creare 40 palline
        int numerorigaAlbero = rand() % (100 - 1 + 1) + 1;                       //Per far si che la probabilità che ci sia una pallina
        int rigaAlbero;                                                          //in una riga sia equa chiedo un numero randomico da 1 a 100.
        int colorePalline = rand() % (47 - 32 + 1) + 32;                         //In base al numero che esce sarà su una determinata riga
                                                                                 //Questo serve perchè nella riga 10 è probabile che ci sono
        if(numerorigaAlbero == 1)                                                //più palline rispetto alla riga 1.
            rigaAlbero = 1;                                                      //Randomizzo il colore delle palline.
            else if(numerorigaAlbero < 5)
                rigaAlbero = 2;
                else if(numerorigaAlbero < 10)
                    rigaAlbero = 3;
                    else if(numerorigaAlbero < 17)
                        rigaAlbero = 4;
                        else if(numerorigaAlbero < 26)
                            rigaAlbero = 5;
                            else if(numerorigaAlbero < 37)
                                rigaAlbero = 6;
                                else if(numerorigaAlbero < 50)
                                    rigaAlbero = 7;
                                    else if(numerorigaAlbero < 65)
                                        rigaAlbero = 8;
                                        else if(numerorigaAlbero < 82)
                                            rigaAlbero = 9;
                                            else if(numerorigaAlbero < 101)
                                                rigaAlbero = 10;

        int xRigaPalline, yRigaAlbero, lunghezzaRigaAlbero;

        yRigaAlbero = 23;
        lunghezzaRigaAlbero = 3;

        switch(rigaAlbero){                                                                         //Quando sappiamo la riga dobbiamo solo
            case 1: puntoColore(72, yRigaAlbero, '*', colorePalline);                               //Chiedere un random per saperne la
                    break;                                                                          //Posizione esatta e associargli il colore
            case 2: xRigaPalline = rand() % lunghezzaRigaAlbero + 1;                                //Casuale.
                    puntoColore(xRigaPalline + 70, yRigaAlbero + 1, '*', colorePalline);
                    break;
            case 3: xRigaPalline = rand() % (lunghezzaRigaAlbero + 2) + 1;
                    puntoColore(xRigaPalline + 69, yRigaAlbero + 2, '*', colorePalline);
                    break;
            case 4: xRigaPalline = rand() % (lunghezzaRigaAlbero + 4) + 1;
                    puntoColore(xRigaPalline + 68, yRigaAlbero + 3, '*', colorePalline);
                    break;
            case 5: xRigaPalline = rand() % (lunghezzaRigaAlbero + 6) + 1;
                    puntoColore(xRigaPalline + 67, yRigaAlbero + 4, '*', colorePalline);
                    break;
            case 6: xRigaPalline = rand() % (lunghezzaRigaAlbero + 8) + 1;
                    puntoColore(xRigaPalline + 66, yRigaAlbero + 5, '*', colorePalline);
                    break;
            case 7: xRigaPalline = rand() % (lunghezzaRigaAlbero + 10) + 1;
                    puntoColore(xRigaPalline + 65, yRigaAlbero + 6, '*', colorePalline);
                    break;
            case 8: xRigaPalline = rand() % (lunghezzaRigaAlbero + 12) + 1;
                    puntoColore(xRigaPalline + 64, yRigaAlbero + 7, '*', colorePalline);
                    break;
            case 9: xRigaPalline = rand() % (lunghezzaRigaAlbero + 14) + 1;
                    puntoColore(xRigaPalline + 63, yRigaAlbero + 8, '*', colorePalline);
                    break;
            case 10: xRigaPalline = rand() % (lunghezzaRigaAlbero + 16) + 1;
                    puntoColore(xRigaPalline + 62, yRigaAlbero + 9, '*', colorePalline);
            }
        }
    }


    void PupazzoDiNeve(int x, int y){
        int parteBassaPupazzox, parteBassaPupazzoy, baseParteBassa, altezzaParteBassa;                          //Dichiaro le variabili
        int altezzaColonne, parteCentroPupazzox, parteCentroPupazzoy, baseCentroEFaccia, altezzaCentro;
        int facciaPupazzox, facciaPupazzoy, altezzaFaccia;
        int cappelloPupazzox, cappelloPupazzoy, lunghezzaCappello, occhiPupazzox, occhiPupazzoy;
        int sciarpax, sciarpay, lunghezzaSciarpa;

        parteBassaPupazzox = x;
        parteBassaPupazzoy = y - 2;
        baseParteBassa = 8;
        altezzaParteBassa = 3;
        altezzaColonne = 2;
        parteCentroPupazzox = x + 1;
        parteCentroPupazzoy = y - 5;
        baseCentroEFaccia = 6;
        altezzaCentro = 3;
        facciaPupazzox = x + 1;
        facciaPupazzoy = y - 7;
        altezzaFaccia = 2;
        cappelloPupazzox = x;
        cappelloPupazzoy = y - 8;
        lunghezzaCappello = 8;
        occhiPupazzox = x + 2;
        occhiPupazzoy = y - 6;
        sciarpax = x;
        sciarpay = y - 4;
        lunghezzaSciarpa = 8;
        rettangoloPienoColore(parteBassaPupazzox, parteBassaPupazzoy, baseParteBassa, altezzaParteBassa, '*', WHITE);         //Rettangolo basso pupazzo
        colonnaColore(parteBassaPupazzox - 1, parteBassaPupazzoy, altezzaColonne, '*', WHITE);
        colonnaColore(parteBassaPupazzox + 8, parteBassaPupazzoy, altezzaColonne, '*', WHITE);
        rettangoloPienoColore(parteCentroPupazzox, parteCentroPupazzoy, baseCentroEFaccia, altezzaCentro, '*', WHITE);        //Rettangolo centrale pupazzo
        colonnaColore(parteCentroPupazzox - 1, parteCentroPupazzoy + 1, altezzaColonne, '*', WHITE);
        colonnaColore(parteCentroPupazzox + 6, parteCentroPupazzoy + 1, altezzaColonne, '*', WHITE);
        rettangoloPienoColore(facciaPupazzox, facciaPupazzoy, baseCentroEFaccia, altezzaFaccia, '*', WHITE);                //Rettangolo alto pupazzo
        rigaColore(cappelloPupazzox, cappelloPupazzoy, lunghezzaCappello, '*', BLACK);                                      //Cappello nero
        rigaColore(cappelloPupazzox + 1, cappelloPupazzoy - 1, lunghezzaCappello - 2, '*', BLACK);
        puntoColore(occhiPupazzox, occhiPupazzoy, '*', BLACK);                                                              //Occhi
        puntoColore(occhiPupazzox + 3, occhiPupazzoy, '*', BLACK);
        rigaColore(sciarpax, sciarpay, lunghezzaSciarpa, '*', PURPLE);
        puntoColore(sciarpax - 1, sciarpay - 1, '*', PURPLE);
    }


    void Renna(int x, int y){

        int collareRennax, collareRennay, lunghezzaCollare, baseCorpoRenna, altezzaCorpoRenna;
        int gambeRennax, gambeRennay, facciaRennax, facciaRennay, baseFacciaRenna, altezzaFacciaRenna;
        int cornaRennax, cornaRennay;

        collareRennax = x - 2;
        collareRennay = y - 1;
        lunghezzaCollare = 2;
        baseCorpoRenna = 5;
        altezzaCorpoRenna = 2;
        gambeRennax = x;
        gambeRennay = y + 2;
        facciaRennax = x + 5;
        facciaRennay = y - 1;
        baseFacciaRenna = 3;
        altezzaFacciaRenna = 2;
        cornaRennax = x + 4;
        cornaRennay = y - 2;
        rigaColore(collareRennax, collareRennay, lunghezzaCollare, '*', BLACK);
        rettangoloPienoColore(x, y, baseCorpoRenna, altezzaCorpoRenna, '*', YELLOW);
        puntoColore(gambeRennax, gambeRennay, '*', YELLOW);
        puntoColore(gambeRennax + 4, gambeRennay, '*', YELLOW);
        rettangoloPienoColore(facciaRennax, facciaRennay, baseFacciaRenna, altezzaFacciaRenna, '*', YELLOW);
        puntoColore(cornaRennax, cornaRennay, '*', PINK);
        puntoColore(cornaRennax + 4, cornaRennay, '*', PINK);

        }



    void Slitta(int x, int y){
        int parteRossaSlittax, parteRossaSlittay, rigaGiallax, rigaGiallay, lunghezzaRigheRosse, lunghezzaRigaGialla;
        int parteNeraSlittax, parteNeraSlittay, lunghezzaParteNera;
        int parteRossaBabbox, parteRossaBabboy, parteBiancaBabbox, parteBiancaBabboy, lunghezzaRigheBianche;
        int parteRosax, parteRosay, lunghezzaRigheRosa, parteViolax, parteViolay, lunghezzaRigheViola;
        parteRossaSlittax = x;
        parteRossaSlittay = y;
        rigaGiallax = x + 2;
        rigaGiallay = y + 2;
        lunghezzaRigheRosse = 2;
        lunghezzaRigaGialla = 12;
        parteNeraSlittax = x + 4;
        parteNeraSlittay = y + 4;
        lunghezzaParteNera = 13;
        parteRossaBabbox = x + 8;
        parteRossaBabboy = y;
        parteBiancaBabbox = x + 9;
        parteBiancaBabboy = y - 1;
        lunghezzaRigheBianche = 2;
        parteRosax = x + 9;
        parteRosay = y - 2;
        lunghezzaRigheRosa = 2;
        parteViolax = x + 2;
        parteViolay = y;
        lunghezzaRigheViola = 6;
        rigaColore(parteRossaSlittax, parteRossaSlittay, lunghezzaRigheRosse, '*', RED);                       //Parte rossa della slitta
        rigaColore(parteRossaSlittax + 1, parteRossaSlittay + 1, lunghezzaRigheRosse + 13, '*', RED);
        rigaColore(rigaGiallax, rigaGiallay, lunghezzaRigaGialla, '*', YELLOW);                                //Riga gialla a metà slitta
        rigaColore(parteRossaSlittax + 3, parteRossaSlittay + 3, lunghezzaRigheRosse + 7, '*', RED);
        puntoColore(parteRossaSlittax + 16, parteRossaSlittay, '*', RED);
        puntoColore(parteNeraSlittax, parteNeraSlittay, '*', BLACK);                                           //Parte in basso nera
        puntoColore(parteNeraSlittax + 6, parteNeraSlittay, '*', BLACK);
        rigaColore(parteNeraSlittax - 3, parteNeraSlittay + 1, lunghezzaParteNera, '*', BLACK);
        puntoColore(parteNeraSlittax - 4, parteNeraSlittay, '*', BLACK);
        puntoColore(parteNeraSlittax + 10, parteNeraSlittay, '*', BLACK);
        rigaColore(parteRossaBabbox, parteRossaBabboy, lunghezzaRigheRosse + 2, '*', RED);                      //Parte rossa babbo
        puntoColore(parteRossaBabbox, parteRossaBabboy - 1, '*', RED);
        puntoColore(parteRossaBabbox + 3, parteRossaBabboy - 1, '*', RED);
        rigaColore(parteBiancaBabbox, parteBiancaBabboy, lunghezzaRigheBianche, '*', WHITE);                    //Barba babbo
        puntoColore(parteBiancaBabbox - 1, parteBiancaBabboy - 1, '*', WHITE);
        puntoColore(parteBiancaBabbox + 2, parteBiancaBabboy - 1, '*', WHITE);
        rigaColore(parteRosax, parteRosay, lunghezzaRigheRosa, '*', PINK);                                      //Faccia babbo
        rigaColore(parteRosax - 1, parteRosay - 1, lunghezzaRigheRosa + 2, '*', PINK);
        rigaColore(parteRossaBabbox, parteRossaBabboy - 4, lunghezzaRigheRosse + 2, '*', RED);                  //Cappello babbo
        rigaColore(parteRossaBabbox, parteRossaBabboy - 5, lunghezzaRigheRosse + 1, '*', RED);
        puntoColore(parteRossaBabbox - 1, parteRossaBabboy - 6, '*', RED);
        puntoColore(parteBiancaBabbox - 3, parteBiancaBabboy - 4, '*', WHITE);
        rigaColore(parteViolax, parteViolay, lunghezzaRigheViola, '*', PURPLE);                                 //Sacco dei regali
        rigaColore(parteViolax - 2, parteViolay - 1, lunghezzaRigheViola + 2, '*', PURPLE);
        rigaColore(parteViolax - 1, parteViolay - 2, lunghezzaRigheViola, '*', PURPLE);

            }



        void CancellaSlitta(int x, int y){                      //Questa funzione serve per cancellare la slitta. E fondamentale perchè la
            rettangoloPienoColore(x, y, 18, 12, '*', BLUE);     //slitta appare poi un quadratino dopo facendola sembrare in movimento.
            }


        void CancellaRenna(int x, int y, int z){
            rettangoloPienoColore(x, y, z * 11, 6, '*', BLUE);
            }

 int main() {
     cursor_hide();

     int nRenne;

     do{
     printf("Inserisci il numero di renne che aiuteranno Babbo Natale a portare i regali (1...5)");
     scanf("%d", &nRenne);
     }while(nRenne < 1 || nRenne > 5);

     srand(time(NULL));
     setTextColor(17);
     clrscr();



     rettangoloPienoColore(0, 36, 120, ALTEZZANEVE, '*', WHITE);

     Casetta(CASETTAX, CASETTAY);
     Albero(ALBEROX, ALBEROY, ALTEZZAALBERO);
     PupazzoDiNeve(PUAPAZZOX, PUPAZZOY);









     for(int contSlitta = 0; contSlitta < 100; contSlitta ++){
                                                                            //Questo for serve per far muovere la slitta.
        Slitta(contSlitta + 2, 8);
            if(contSlitta < 90)
                Renna(contSlitta + 21, 8);
            if(nRenne == 2 && contSlitta < 79){
                Renna(contSlitta + 21, 8);
                Renna(contSlitta + 32, 8);
            }
            else if(nRenne == 2 && contSlitta >= 79)
                nRenne = 1;
            if(nRenne == 3 && contSlitta < 68){
                Renna(contSlitta + 21, 8);
                Renna(contSlitta + 32, 8);
                Renna(contSlitta + 43, 8);
            }
            else if(nRenne == 3 && contSlitta >= 68)
                nRenne = 2;
            if(nRenne == 4 && contSlitta < 57){
                Renna(contSlitta + 21, 8);
                Renna(contSlitta + 32, 8);
                Renna(contSlitta + 43, 8);
                Renna(contSlitta + 54, 8);
            }
            else if(nRenne == 4 && contSlitta >= 57)
                nRenne = 3;
            if(nRenne == 5 && contSlitta < 46){
                Renna(contSlitta + 21, 8);
                Renna(contSlitta + 32, 8);
                Renna(contSlitta + 43, 8);
                Renna(contSlitta + 54, 8);
                Renna(contSlitta + 65, 8);
            }
            else if(nRenne == 5 && contSlitta >= 46)
                nRenne = 4;


                                                                                //A determinate posizioni della slitta si creano le lettere
        delay(100);                                                            // del BUON NATALE, è a questo che serve lo switch.
        CancellaSlitta(contSlitta + 2, 2);
        CancellaRenna(contSlitta + 20, 6, nRenne);
        switch(contSlitta){
        case 16: rettangoloPienoColore(11, 5, 2, 5, '*', GREEN);               //Lettera B
                 rigaColore(12, 4, 5, '*', GREEN);
                 rettangoloPienoColore(17, 5, 2, 2, '*', GREEN);
                 rigaColore(13, 7, 4, '*', GREEN);
                 rettangoloPienoColore(17, 8, 2, 2, '*', GREEN);
                 rigaColore(12, 10, 5, '*', GREEN);
                 break;


        case 25: rettangoloPienoColore(20, 4, 2, 6, '*', GREEN);              //Lettera U
                 rigaColore(21, 10, 4, '*', GREEN);
                 rettangoloPienoColore(24, 4, 2, 6, '*', GREEN);
                 break;


        case 34: rettangoloPienoColore(27, 5, 2, 5, '*', GREEN);              //Lettera O
                 rigaColore(28, 4, 5, '*', GREEN);
                 rettangoloPienoColore(32, 5, 2, 5, '*', GREEN);
                 rigaColore(28, 10, 5, '*', GREEN);
                 break;


        case 43: rettangoloPienoColore(35, 4, 2, 7, '*', GREEN);              //Lettera N
                 puntoColore(37, 5, '*', GREEN);
                 puntoColore(38, 6, '*', GREEN);
                 puntoColore(39, 7, '*', GREEN);
                 puntoColore(40, 8, '*', GREEN);
                 rettangoloPienoColore(41, 4, 2, 7, '*', GREEN);
                 break;


        case 60: rettangoloPienoColore(52, 4, 2, 7, '*', GREEN);                //Lettera N
                 puntoColore(54, 5, '*', GREEN);
                 puntoColore(55, 6, '*', GREEN);
                 puntoColore(56, 7, '*', GREEN);
                 puntoColore(57, 8, '*', GREEN);
                 rettangoloPienoColore(58, 4, 2, 7, '*', GREEN);
                 break;


        case 69: rettangoloPienoColore(61, 6, 2, 5, '*', GREEN);                //Lettera A
                 rettangoloPienoColore(62, 5, 2, 1, '*', GREEN);
                 rettangoloPienoColore(64, 4, 2, 1, '*', GREEN);
                 rettangoloPienoColore(66, 5, 2, 1, '*', GREEN);
                 rettangoloPienoColore(63, 7, 4, 1, '*', GREEN);
                 rettangoloPienoColore(67, 6, 2, 5, '*', GREEN);
                 break;


        case 78: rigaColore(70, 4, 8, '*', GREEN);                              //Lettera T
                 rettangoloPienoColore(73, 5, 2, 6, '*', GREEN);
                 break;


        case 87: rettangoloPienoColore(79, 6, 2, 5, '*', GREEN);                //Lettera A
                 rettangoloPienoColore(80, 5, 2, 1, '*', GREEN);
                 rettangoloPienoColore(82, 4, 2, 1, '*', GREEN);
                 rettangoloPienoColore(84, 5, 2, 1, '*', GREEN);
                 rettangoloPienoColore(81, 7, 4, 1, '*', GREEN);
                 rettangoloPienoColore(85, 6, 2, 5, '*', GREEN);
                 break;


        case 96: rettangoloPienoColore(88, 4, 2, 7, '*', GREEN);                //Lettera L
                 rigaColore(90, 10, 5, '*', GREEN);
                 break;

            }
     }
    rettangoloPienoColore(96, 4, 2, 7, '*', GREEN);                             //Lettera E
    rigaColore(98, 4, 5, '*', GREEN);
    rigaColore(98, 7, 3, '*', GREEN);
    rigaColore(98, 10, 5, '*', GREEN);

    rettangoloPienoColore(105, 4, 2, 5, '*', GREEN);
    rettangoloPienoColore(105, 10, 2, 1, '*', GREEN);



     while(1){                                                    //Nel while infinito ho messo l'albero e il braccio ddel pupazzo.
                                                                  //Queste animazioni si attiveranno dopo il passaggio della slitta.
        Albero(63, 32, 10);

        int cont;
        int x = 15;
        int y = 35;
        if(cont % 2 == 0){
            rigaColore(x + 8, y - 4, 2, '*', BLACK);
            rigaColore(x + 9, y - 5, 2, '*', BLACK);
            puntoColore(x + 10, y - 6, '*', BLACK);
            delay(1000);
            puntoColore(x + 9, y - 5, '*', BLUE);
            puntoColore(x + 10, y - 6, '*', BLUE);
        }
        else{
            rigaColore(x + 8, y - 4, 2, '*', BLACK);
            rigaColore(x + 10, y - 5, 2, '*', BLACK);
            puntoColore(x + 12, y - 6, '*', BLACK);
            delay(1000);
            puntoColore(x + 11, y - 5, '*', BLUE);
            puntoColore(x + 12, y - 6, '*', BLUE);
        }
        cont ++;

     }

 }


