#include "utility.h"  //inserire il percorso relativo corretto

//disegna un carattere car nella posizione (x,y)
void punto(int x, int y, char car);

//disegna un carattere car nella posizione (x,y) del colore color
void puntoColore(int x, int y, char car, int color);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
void riga(int x, int y, int lung, char car);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void rigaColore(int x, int y, int lung, char car, int color);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando per ciauscun carattere un colore casuale tra i 16 possibili a partire dal colore base
void rigaColoriCasuali(int x, int y, int lung, char car, int coloreBase);

//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
void colonna(int x, int y, int lung, char car);

//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void colonnaColore(int x, int y, int lung, char car, int color);

//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoPieno(int x, int y, int l, char car);

//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoPienoColore(int x, int y, int l, char car, int color);

//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoVuoto(int x, int y, int l, char car);

//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoVuotoColore(int x, int y, int l, char car, int color);

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloPieno(int x, int y, int b, int h, char car);

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloPienoColore(int x, int y, int b, int h, char car, int color);

//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloVuoto(int x, int y, int b, int h, char car);

//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloVuotoColore(int x, int y, int b, int h, char car, int color);


//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car
void triangolo(int x, int y, int h, char car);

//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void triangoloColore(int x, int y, int h, char car, int color);










//disegna un carattere car nella posizione (x,y)
void punto(int x, int y, char car){
    gotoxy(x,y);                                                        //Va al punto in cui si vuole scrivere
    printf("%c", car);                                                  //Stampa il carattere
}



//disegna un carattere car nella posizione (x,y) del colore color
void puntoColore(int x, int y, char car, int color){
    int coloreAttuale = getTextColor();                                 //salvo il colore corrente
    setTextColor(color);                                                //imposto il nuovo colore
    punto(x, y, car);
    setTextColor(coloreAttuale);                                        //ripristino il colore precedente
}



//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
void riga(int x, int y, int lung, char car){
    gotoxy(x, y);
    for(int k = 0; k < lung; k++){
        printf("%c", car);
    }
}



//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void rigaColore(int x, int y, int lung, char car, int color){
    int coloreAttuale = getTextColor();
    setTextColor(color);
    riga(x, y, lung, car);
    setTextColor(coloreAttuale);
}



//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando per ciauscun carattere un colore casuale tra i 16 possibili a partire dal colore base
void rigaColoriCasuali(int x, int y, int lung, char car, int coloreBase){
    int coloreAttuale = getTextColor();
    int color;

    gotoxy(x, y);
    for(int k = 0; k < lung; k++){
        color = rand() % 16 + coloreBase;
        setTextColor(color);
        printf("%c", car);
    }
    setTextColor(coloreAttuale);
}



//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
void colonna(int x, int y, int lung, char car){
    for(int k = 0; k < lung; k++){
        gotoxy(x, y + k);
        printf("%c", car);
    }
}



//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void colonnaColore(int x, int y, int lung, char car, int color){
    int coloreAttuale = getTextColor();
    setTextColor(color);
    colonna(x, y, lung, car);
    setTextColor(coloreAttuale);
}



//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoPieno(int x, int y, int l, char car){
     for(int k = 0; k < l; k++){
        riga(x, y + k, l, '*');
     }
}



//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoPienoColore(int x, int y, int l, char car, int color){
    int coloreAttuale = getTextColor();
    setTextColor(color);
    quadratoPieno(x, y, l, car);
    setTextColor(coloreAttuale);
}



//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoVuoto(int x, int y, int l, char car){
    riga(x, y, l, car);
    colonna(x, y + 1, l - 2, car);
    colonna(x + l - 1, y + 1, l - 2, car);
    riga(x, y + l - 1, l, car);
}




//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoVuotoColore(int x, int y, int l, char car, int color){
    int coloreAttuale = getTextColor();
    setTextColor(color);
    quadratoVuoto(x, y, l, car);
    setTextColor(coloreAttuale);

}


//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloPieno(int x, int y, int b, int h, char car){
    for(int k = 0; k < h; k++){
        riga(x, y + k, b, car);
    }
}



//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloPienoColore(int x, int y, int b, int h, char car, int color){
    int coloreAttuale = getTextColor();
    setTextColor(color);
    rettangoloPieno(x, y, b, h, car);
    setTextColor(coloreAttuale);
}



//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloVuoto(int x, int y, int b, int h, char car){
    riga(x, y, b, car);
    colonna(x, y + 1, h - 2, car);
    colonna(x + b - 1, y + 1, h - 2, car);
    riga(x, y + h - 1, b, car);
}



//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloVuotoColore(int x, int y, int b, int h, char car, int color){
    int coloreAttuale = getTextColor();
    setTextColor(color);
    rettangoloVuoto(x, y, b, h, car);
    setTextColor(coloreAttuale);
}



//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car
void triangolo(int x, int y, int h, char car){
    for(int k = 0; k < h; k++){
        riga(x - k, y + k, 2 * k + 1, car);
    }
}



//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void triangoloColore(int x, int y, int h, char car, int color){
    int coloreAttuale = getTextColor();
    setTextColor(color);
    triangolo(x, y, h, car);
    setTextColor(coloreAttuale);
}










