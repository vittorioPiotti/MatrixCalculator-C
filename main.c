//
//  main.c
//  MC
//
//  Created by Vittorio Piotti on 22/08/2022.
//
/*
 * Matrix Calculator C v1.0.0 (https://github.com/vittorioPiotti/Matrix-Calculator-C/releases/tag/1.0.0)
 * Copyright 2024 Vittorio Piotti
 * Licensed under GPL-3.0 (https://github.com/vittorioPiotti/Matrix-Calculator-C/blob/main/LICENSE.md)
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//stato programma
#define SPEGNIMENTO 310
#define ACCENSIONE 311
#define ESECUZIONE 312
#define INCERTEZZA 313
//occorrenze primarie acquisizione
#define ANNULLA 88888880 //termina con zero perche associata a variabile float altrimenti darebbe errore di approssimazione e quindi il valore sorgente e quello destinatario non corrisponderebbero
#define ERRORE 88888881
#define CONTINUA 88888882
#define DISUSO 88888883
#define MAX_ERRORI 5
//occorrenze main
#define GESTIONE_MATRICI 300
#define OPERAZIONI_MATRICI 302
//occorrenze secondarie acquisizione
#define PUNTO 46
#define PIU 43
#define MENO 45
#define UNO 48
#define NOVE 57
#define MAXCIFRE 6
#define MINCIFRE 1
//occorrenze terziarie acquisizione : poszione punto
#define PRIMA 1
#define DOPO - 1
//schermate tipo selezione
#define EXT 408
#define RIX 409
#define PLUS 530
//occorrenze operazioni
#define INXMIN_OPERA_EXT 0
#define INXMAX_OPERA_EXT 3
#define INXMIN_OPERA_RIX 4
#define INXMAX_OPERA_RIX 10
//occorrenze operazioni algebriche
#define INXMINOPERALG 5
#define INXMAXOPERALG 8
//schermate selezione operazione estesa
#define VISUALIZZA 0
#define ELIMINA 1
#define IDENTIFICA 2
#define DETERMINANTE 3
//schermate selezione operazione ristretta
#define MODIFICA 4
#define SUMMAT 5
#define SUBMAT 6
#define PRODMAT 7
#define PRODSCAL 8
#define TRASPOSTA 9
#define CALC_INVERSA 10
#define OPERAZIONI 11
//schermate modifica
#define MODDIM 666
#define PICKMOD 685
#define PICKRG 676
#define PICKCL 677
#define NUMMOD 678
#define MODVAL 679
#define MODRG 683
#define MODCL 684
//schermate selezione indice
//schermate gestione main
#define LAUNCHER 501
#define PANNELLO 502
#define PRINCIPALE_0_MAT 503
#define PRINCIPALE 504
//schermate gestione matrici
#define GESTIONE_MAT 505
#define GESTIONE_MAT_ALL_IN 506
//schermate operazioni tra matrici

#define PICK_PROD 800
#define PICK_QUAD 801
#define PICK_SUM 802
//schermate carica matrici
#define CARICA 513
#define CARICA_MAN_UP 514
#define CARICA_MAN_DOWN 515
#define CARICA_MAN_RG 516
#define CARICA_MAN_CL 517
#define CARICA_MAN_VAL 518
#define CARICA_AUTO_UP 519
#define CARICA_AUTO_DOWN 520
//occorrenze carica
#define MAN 1
#define AUTO 2
//stato caricamento dimensione
#define UP 1
#define DAWN 0
//altre occorrenze schermate
#define DELULTIMA 700
//occorrenze tipo valore
#define MAT 0
#define SCAL 1
//occorrenze slezione matrice
#define ATTUALE 0
#define SCELTA 1
//occorrenze specie
#define SPECIE 3
#define IN 0
#define OUT 1
#define MIN 0
#define MAX 1
#define ALL 2
//numero tipo matrici
#define TIPO 2
//occorrenze genere
#define GENERE 8
#define NEUTRO 0
#define QUAD 1
#define MOLTPLNDO 2
#define MOLTPLTOR 3
#define ADDENDO2 4
#define APP 5
#define FREQ 6
#define INVERSA 7
//occorrenze classi
#define CLASSE 3
#define NUM 0
#define STATO 1
#define INX 2
//occorrenze matrici
#define MAXMAT 10
#define MAXMAT_TIPO 5
#define MINMAT 0
#define MAXRG 4
#define MAXCL 4
#define MINRG 1
#define MINCL 1
//occorrenze dimensioni
#define INXRG 0
#define INXCL 1
#define MAXDIM 2
//indici tipo matrice neutro
#define INXMININ 0
#define INXMAXIN 4
#define INXMINOUT 5
#define INXMAXOUT 9
//stato tipo matrice
#define NESSUNA 0
#define SOLO_UNA 1
#define UNA_PER 2
#define CON_UNA 3
#define ALCUNE 4
#define TUTTE 5
#define UN_TIPO 6
//occorrenze stringa
#define MAXCHAR 200
//stato caratteri termini operazioni
#define OPERALG 4
#define PROD 0
#define SUM 1
#define SUB 2
#define NO_OPERALG 3
#define TERMINI 2
#define TERMINE1 0
#define TERMINE2 1
//occorrenze identifica
#define SCALARE 1
#define MATNULL 2
#define MATID 3
#define MATDIAG 4
#define MATTRGINF 5
#define MATTRGSUP 6
#define MATQUAD 7
#define VETRG 8
#define VETCL 9
#define MATGEN 10
//occorrenze caratteristiche operazione
#define NOTEXE_ALLOUT 0
#define EXE_ALLOUT 1
//occorrenze pick
#define MAXPICK 7
#define LANCIO 0
#define HOME 1
#define OPTION 2
#define GESTIONE 3
#define OPERAMAC 4
#define OPERAMIC 5
#define PICKOPERA 6
//schermate operazioni tra matrici
#define OPERAMAT_ALL 901
#define OPERAMAT_ALLOUT_RIX 902
#define OPERAMAT_ALLOUT_EXT 903
#define OPERAMAT_OPERALG_RIX 904
#define OPERAMAT_OPERALG 905
#define OPERAMAT_ALL_OPERALG 906//tutte
#define OPERAMAT_NOQUAD_OPERALG 907//solo moltpl
#define OPERAMAT_NOMOLTPL_OPERALG 908//operazioni con det
#define OPERAMAT_ONLYQUAD_OPERALG 909//calcola det
#define OPERAMAT_NOINV_OPERALG 910//tutte tranne inversa

//gestione acquisizioni
double acquisizioneNumericaGenerale(char []);
int eliminaCarattere(int , char []);
int rilevaCorrisondenzaDiUnSingoloCarattere(int , int , char []);
int conversioneCararreteDiUnUnitaNumericaInNumero(char );
//gestione inserimento e schermate
int richiestaAnnullaInserimento(void);
double gestioneInserimentoSchermateClean(int, char[]);
double gestioneInserimentoSchermateExt(int[][SPECIE][CLASSE][MAXMAT], int [][MAXDIM], int,int, int, int, int,int, char[]);
double gestioneInserimentoSchermateRix(int, int, int, char[]);
double modificaValore(int, int, int, int, double, char[]);
double gestioneInserimentoSchermataIndice(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL],int [][MAXDIM], int ,int , int ,int ,int ,int ,char []);
//gestione schermate
void gestioneSmartSchermate(int[][SPECIE][CLASSE][MAXMAT], int [][MAXDIM],int,int, int, int);
void schermateExt(int[][SPECIE][CLASSE][MAXMAT],int [][MAXDIM],  int,int,int,int);
void schermataMod(int, int, int, double, int);
void schermateRix(int, int, int);
void schermateClean(int);
void schermataIndici(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL],int [][MAXDIM], int,int ,int ,int ,int, int);
//gestione inserimento
double inserimentoNumeroSuIntervallo(double, int, int);
int inserimentoNumeroSuVettore(int, int[], int);
double inserimentoExt(int[][SPECIE][CLASSE][MAXMAT], int [][MAXDIM],int, int,int, double, int, int,int);
double inserimentoRix(int, double, int, int);
double inserimentoClean(int, double);
//altre schermate
void schermataCaricaDimensioneMatrice(char[], char[], int);
void schermataSelezionaDimensione(int, char[], char[]);
void schermataModificaDimensioneMatrice(char[], char[], int, int);
//schermate di notifica
void notificaDimensioniModificate(int, int[][MAXDIM], int, int);
void notificaSingolaModificaGenerica(int, int, int, char[]);
void notificaSingoloValoreModificato(int, int, int, float, float);
//azzera variabili principali
void azzeraMat(float [][MAXRG][MAXCL]);
void azzeraDim(int [][MAXDIM]);
void azzeraOccMat(int [][SPECIE][CLASSE][MAXMAT]);
//indici matrici
int assegnaInx(int [][SPECIE][CLASSE][MAXMAT], int );
int assegnaInxAll(int [][SPECIE][CLASSE][MAXMAT], int );
int rilevaInxMat(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL], int [][MAXDIM],int , int ,int, int );
//aggiorna occMat
void aggiornaMatSmart(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL], int [][MAXDIM], int ,int,int );
int aggiornaStatoSmart(int [][SPECIE][CLASSE][MAXMAT], int );
int aggiornaStatoRix(int);
int aggiornaStatoExt(int);
void associaMatFreq(int [][SPECIE][CLASSE][MAXMAT], int );
void associaMatNeutro(int [][SPECIE][CLASSE][MAXMAT], int ,int );
int aggiornaStatoPlus(int , int );
//operazioni base
int matriceTrasposta(float [][MAXCL],float [][MAXCL], int,int,int*,int*);
void visualizzaSingolaMatrice(float mat[][MAXRG][MAXCL], int[][MAXDIM], int);
int eliminaSingolaMatrice(float mat[][MAXRG][MAXCL], int[][MAXDIM], int, int);
//operazioni algebriche
int moltiplicazione(float [][MAXRG][MAXCL], int [][MAXDIM], int ,float  ,int , int );
int prodottoScalareMatrice(float [][MAXCL], float [][MAXCL],float , int ,int , int *,int *);
int addizzione(float [][MAXRG][MAXCL], int [][MAXDIM], int ,float  , int , int );
//modifica
void modificaValoriMatrice(float[][MAXRG][MAXCL], int[][MAXDIM], int, char[]);
int modificaSmartSingoloValoreMatrice(float[][MAXRG][MAXCL], int[][MAXDIM], int, int, int, int);
void modificaSmartValoriMatrice(float[][MAXRG][MAXCL], int[][MAXDIM], int, int, int, int, int, char[]);
int eseguiOperazioneModificaSmartMatrice(float[][MAXRG][MAXCL], int[][MAXDIM], int, int, int, int, int);
int modificaSmartMatriceBidimensionale(float[][MAXRG][MAXCL], int[][MAXDIM], int, int, int, int);
int modificaSmartValoriMatriceVettoreColonna(float[][MAXRG][MAXCL], int[][MAXDIM], int, int, int);
int modificaSmartValoriMatriceVettoreRiga(float[][MAXRG][MAXCL], int[][MAXDIM], int, int, int);
//carica matrici
int caricaMatriciPlus(int[][SPECIE][CLASSE][MAXMAT], float[][MAXRG][MAXCL], int[][MAXDIM], int);
int cosaCaricaAuto(int[][SPECIE][CLASSE][MAXMAT], float[][MAXRG][MAXCL], int[][MAXDIM], int, int);
int caricaMatrici(int[][SPECIE][CLASSE][MAXMAT], float[][MAXRG][MAXCL], int[][MAXDIM], int, int);
int cosaCaricaMan(int[][SPECIE][CLASSE][MAXMAT], float[][MAXRG][MAXCL], int[][MAXDIM], int, int);
int caricaManualeDimensioni(int[][SPECIE][CLASSE][MAXMAT], int[][MAXDIM]);
int modificaManualeSingolaDimensione(int[][SPECIE][CLASSE][MAXMAT], int[][MAXDIM], int, int);
void modificaManualeDimensioni(int[][SPECIE][CLASSE][MAXMAT], int[][MAXDIM]);
int caricaManualeValori(int[][SPECIE][CLASSE][MAXMAT], float[][MAXRG][MAXCL], int[][MAXDIM]);
int caricaAutomaticoValori(float[][MAXRG][MAXCL], int[][MAXDIM], int);
//identifica
void risultatoIdentificaMatrice(float[][MAXRG][MAXCL], int[][MAXDIM], int);
int identificaMatrice(float[][MAXRG][MAXCL], int[][MAXDIM], int);
int identificaMatriceNulla(float[][MAXRG][MAXCL], int[][MAXDIM], int);
int identificaMatriceDiagonale(float[][MAXRG][MAXCL], int[][MAXDIM], int);
int identificaMatriceIdentita(float[][MAXRG][MAXCL], int[][MAXDIM], int);
int identificaMatriceTriangolareSuperiore(float[][MAXRG][MAXCL], int[][MAXDIM], int);
int identificaMatriceTriangolareInferiore(float[][MAXRG][MAXCL], int[][MAXDIM], int);
//inversa
int calcolaMatriceInversa(float [][MAXRG][MAXCL], int [][MAXDIM], int , int );
//determinante
float calcolaLaplaceDeterminanteMatriceNxN(float[][MAXRG], int);
float gestioneCalcoloDeterminante(float[][MAXRG][MAXCL], int[][MAXDIM], int);
//esegui operazione
int eseguiOperazioneIntervalloMatrici(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat[], int numMat, int selezioneOperazione);
int eseguiOperazioneSingolaMatriceRix(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL], int [][MAXDIM], int , int , int );
int eseguiOperazioneSingolaMatriceExt(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL], int [][MAXDIM], int , int , int ,int  );
void eseguiOperazioneSingolaMatrice(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL], int [][MAXDIM], int , int , int ,int ,int );
int eseguiOperaSingolaMatricePlus(int [][SPECIE][CLASSE][MAXMAT], float [][MAXRG][MAXCL], int [][MAXDIM],int , int ,char[]);

//gestione operazioni
int gestioneOperazioni(int [][SPECIE][CLASSE][MAXMAT], float [][MAXRG][MAXCL], int [][MAXDIM], int , int ,int, char []);
int operazioneMatriceDiUnTipo(int [][SPECIE][CLASSE][MAXMAT], float [][MAXRG][MAXCL], int [][MAXDIM], int ,int , int ,int, char []);
void gestioneOperazioniPlus(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL], int [][MAXDIM],int [MAXPICK], int ,int ,int , int ,int);
int gestioneOperazioneAll(int [][SPECIE][CLASSE][MAXMAT],float [][MAXRG][MAXCL],int [][MAXDIM],int , int , int , int ,int , int );
void associaFreqDaApp(int [][SPECIE][CLASSE][MAXMAT],int ,int , int  );
//gestione caratteri
void associaCharMaiuscTermini(char [OPERALG][TERMINI][MAXCHAR]);
void associaCharMaiuscOperazioni(char [OPERAZIONI][MAXCHAR]);
void aggiornaCharMaiuscFreq(int [][SPECIE][CLASSE][MAXMAT], char [][MAXCHAR]);
//altri algoritmi
void swapInt(int * , int * );
int associaOperaRix(int );
void bblCre(int[], int);
void copiaVettori(int[], int[]);
void scambiaVettori(int[], int[]);
void swapStr(char[],char[]);
int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int occMat[GENERE][SPECIE][CLASSE][MAXMAT];
    float mat[MAXMAT][MAXRG][MAXCL];
    int dim[MAXMAT][MAXDIM];
    int statoDim = DAWN;
    int statoExe = ACCENSIONE;
    int selezione[MAXPICK];
    azzeraDim(dim);
    azzeraMat(mat);
    azzeraOccMat(occMat);
    assegnaInx(occMat,NEUTRO);
    do {
      switch (statoExe) {
      case ACCENSIONE:
        selezione[LANCIO] = gestioneInserimentoSchermateClean(LAUNCHER, "scelta");
        switch (selezione[LANCIO]) {
        case ANNULLA:
          printf("\n\tripristino schermata\n\n");
          break;
        case ESECUZIONE:
          printf("\n\tprogramma avviato\n\n");
          statoExe = ESECUZIONE;
          break;
        case SPEGNIMENTO:
          printf("\n\tprogramma arrestato\n\n");
          statoExe = SPEGNIMENTO;
        }
        break;
      case ESECUZIONE:
        do {
            aggiornaMatSmart(occMat,mat, dim, NEUTRO, NEUTRO, DISUSO);
            if(occMat[NEUTRO][ALL][STATO][MINMAT] == NESSUNA)selezione[HOME] = PRINCIPALE_0_MAT;
            else selezione[HOME] = PRINCIPALE;
            selezione[HOME] = gestioneInserimentoSchermateClean(selezione[HOME], "scelta");
            switch(selezione[HOME]){
                case CARICA:
                    statoDim = caricaMatriciPlus(occMat, mat, dim, statoDim);
                    break;
                case INCERTEZZA:
                    statoExe = INCERTEZZA;
                    break;
                case GESTIONE_MATRICI:
                    do {
                      aggiornaMatSmart(occMat,mat, dim, NEUTRO, NEUTRO, DISUSO);
                        if(occMat[NEUTRO][ALL][STATO][MINMAT] == NESSUNA)selezione[GESTIONE] = 0;
                        else if(occMat[NEUTRO][IN][STATO][MINMAT] == TUTTE) selezione[GESTIONE] = GESTIONE_MAT_ALL_IN;
                        else selezione[GESTIONE] = GESTIONE_MAT;
                        selezione[GESTIONE] = gestioneInserimentoSchermateClean(selezione[GESTIONE], "scelta");
                        switch (selezione[GESTIONE]) {
                        case CARICA://carica
                          statoDim = caricaMatriciPlus(occMat, mat, dim, statoDim);
                          break;
                        case ANNULLA:
                          printf("\n\tritorno alla schermata principale\n\t");
                          selezione[GESTIONE] = 0;
                          break;
                        default:
                          gestioneOperazioni(occMat, mat, dim, NEUTRO, selezione[GESTIONE],DISUSO, "principale");
                          selezione[GESTIONE] = CONTINUA;
                        }
                    } while (selezione[GESTIONE] != 0);
                    break;
                case OPERAZIONI_MATRICI:
                    do {
                        
                      occMat[NEUTRO][OUT][STATO][MINMAT] = aggiornaStatoRix(occMat[NEUTRO][OUT][NUM][MINMAT]);
                        aggiornaMatSmart(occMat,mat, dim, QUAD, QUAD, DISUSO);
                        aggiornaMatSmart(occMat,mat, dim, MOLTPLNDO, MOLTPLNDO, DISUSO);
                        aggiornaMatSmart(occMat,mat, dim, INVERSA, INVERSA, DISUSO);
                        if(occMat[NEUTRO][OUT][STATO][MINMAT] == TUTTE){
                            if(occMat[QUAD][ALL][STATO][MINMAT])selezione[OPERAMAC] = OPERAMAT_ALLOUT_RIX;
                            else selezione[OPERAMAC] = OPERAMAT_ALLOUT_EXT;
                        }
                        else selezione[OPERAMAC] = OPERAMAT_ALL;
                        selezione[OPERAMAC] = gestioneInserimentoSchermateClean(selezione[OPERAMAC], "scelta");
                        switch(selezione[OPERAMAC]){
                            case ANNULLA:
                              printf("\n\tritorno alla schermata principale\n\t");
                              selezione[OPERAMAC] = 0;
                                break;
                            case IDENTIFICA:
                                gestioneOperazioni(occMat, mat, dim, NEUTRO, IDENTIFICA,DISUSO, "principale");
                                break;
                            case TRASPOSTA:
                                gestioneOperazioni(occMat, mat, dim, NEUTRO, TRASPOSTA,DISUSO, "principale");
                                break;
                            case OPERAMAT_OPERALG:
                                do{
                                occMat[APP][ALL][STATO][MINMAT] = 0;
                                if(occMat[QUAD][ALL][STATO][MINMAT] != NESSUNA) occMat[APP][ALL][STATO][MINMAT]  += QUAD;
                                if(occMat[MOLTPLNDO][ALL][STATO][MINMAT] != NESSUNA) occMat[APP][ALL][STATO][MINMAT]  += MOLTPLNDO;
                                if(occMat[INVERSA][ALL][STATO][MINMAT] != NESSUNA) occMat[APP][ALL][STATO][MINMAT]  += INVERSA;
                                switch( occMat[APP][ALL][STATO][MINMAT] ){
                                    case QUAD + MOLTPLNDO + INVERSA:
                                        selezione[OPERAMIC] = OPERAMAT_ALL_OPERALG;
                                        break;
                                    case QUAD + MOLTPLNDO:
                                        selezione[OPERAMIC] = OPERAMAT_NOINV_OPERALG;
                                       break;
                                    case QUAD + INVERSA:
                                        selezione[OPERAMIC] = OPERAMAT_NOMOLTPL_OPERALG;
                                        break;
                                    case QUAD:
                                        selezione[OPERAMIC] = OPERAMAT_ONLYQUAD_OPERALG;
                                        break;
                                    case MOLTPLNDO:
                                        selezione[OPERAMIC] = OPERAMAT_NOQUAD_OPERALG;
                                        break;
                                        
                                    default:
                                        selezione[OPERAMIC] =OPERAMAT_OPERALG_RIX;
                                }
                                    selezione[OPERAMIC] = gestioneInserimentoSchermateClean(selezione[OPERAMIC], "scelta");
                                    switch(selezione[OPERAMIC]){
                                                case ANNULLA:
                                                  printf("\n\tritorno alla schermata principale\n\t");
                                                    selezione[OPERAMIC] = 0;
                                                    break;
                                        case PICK_PROD:
                                            gestioneOperazioniPlus(occMat, mat, dim, selezione, PICK_PROD, NEUTRO,MOLTPLNDO, PRODSCAL, PRODMAT);
                                            break;
                                        case PICK_QUAD:
                                            gestioneOperazioniPlus(occMat, mat, dim, selezione, PICK_QUAD, QUAD,INVERSA, DETERMINANTE, CALC_INVERSA);
                                            break;
                                        case PICK_SUM:
                                            gestioneOperazioniPlus(occMat, mat, dim, selezione, PICK_SUM, NEUTRO,NEUTRO, SUMMAT, SUBMAT);
                                            break;
                                        case PRODSCAL:
                                            gestioneOperazioni(occMat, mat, dim, NEUTRO, PRODSCAL,DISUSO, "principale");
                                            break;
                                        case DETERMINANTE:
                                            gestioneOperazioni(occMat, mat, dim, QUAD, DETERMINANTE,DISUSO, "principale");
                                    }
                                    if(occMat[NEUTRO][OUT][NUM][MINMAT] == MAXMAT_TIPO)selezione[OPERAMIC] = 0;
                                }while(selezione[OPERAMIC] != 0);
                        }
            } while (selezione[OPERAMAC] != 0);
            }
        } while (statoExe == ESECUZIONE);
        break;
      case INCERTEZZA:
        selezione[OPTION] = gestioneInserimentoSchermateClean(PANNELLO, "scelta");
        switch (selezione[OPTION]) {
        case ANNULLA:
          printf("\n\tripristino schermata\n\n");
          break;
        case ESECUZIONE:
          printf("\n\toperazione annullata\n\n");
          statoExe = ESECUZIONE;
          break;
        case ACCENSIONE:
          printf("\n\tprogramma riavviato\n\n");
          azzeraDim(dim);
          azzeraMat(mat);
          azzeraOccMat(occMat);
          assegnaInx(occMat,NEUTRO);
          statoDim = NESSUNA;
          statoExe = ACCENSIONE;
          break;
        case SPEGNIMENTO:
          printf("\n\tprogramma arrestato\n\n");
          statoExe = SPEGNIMENTO;
        }
      }
    } while (statoExe != SPEGNIMENTO);
    return 0;
  }
//gestione acquisizioni
double acquisizioneNumericaGenerale(char inserimentoNumerico[]) {
  double conversione = 0.0;
  int segno = 0;
  int punto = 0;
  int posPunto;
  int inxCifra;
  int unita;
  int numCifre;
  numCifre = strlen(inserimentoNumerico);
  if (numCifre > MAXCIFRE) return ERRORE;
  switch (inserimentoNumerico[0]) {
  case MENO:
    segno = MENO;
    numCifre -= eliminaCarattere(numCifre, inserimentoNumerico);
    break;
  case PIU:
    segno = PIU;
    numCifre -= eliminaCarattere(numCifre, inserimentoNumerico);
    break;
  default:
    segno = 0;
  }
  switch (numCifre) {
  case NESSUNA:
    return ERRORE;
  case MINCIFRE:
    punto = rilevaCorrisondenzaDiUnSingoloCarattere(numCifre, PUNTO, inserimentoNumerico);
    if (punto != ERRORE) return ERRORE;

    conversione = conversioneCararreteDiUnUnitaNumericaInNumero(inserimentoNumerico[0]);
    switch (segno) {
    case MENO:
      return -1 * conversione;
    default:
      return conversione;
    }
    default:
      punto = rilevaCorrisondenzaDiUnSingoloCarattere(numCifre, PUNTO, inserimentoNumerico);
      if (punto == 0 || punto == numCifre - 1) return ERRORE;
      if (punto == ERRORE) punto = numCifre;
      inxCifra = numCifre - 1;
      do {
        if (inxCifra < punto) posPunto = PRIMA;
        else if (inxCifra > punto) posPunto = DOPO;
        else posPunto = 0;
        switch (posPunto) {
        case PRIMA:
          unita = conversioneCararreteDiUnUnitaNumericaInNumero(inserimentoNumerico[inxCifra]);
          if (unita == ERRORE) return ERRORE;
          conversione += unita * pow(10, punto - 1 - inxCifra);

          break;
        case DOPO:
          unita = conversioneCararreteDiUnUnitaNumericaInNumero(inserimentoNumerico[inxCifra]);
          if (unita == ERRORE) return ERRORE;
          conversione += unita / pow(10, inxCifra - punto);
          break;
        }
        inxCifra--;
      } while (inxCifra != -1);
      switch (segno) {
      case MENO:
        return -1 * conversione;
      default:
        return conversione;
      }
  }
}
int eliminaCarattere(int numeroCifre, char inserimentoNumerico[]) {
  int indiceCifra;
  for (indiceCifra = 0; indiceCifra < numeroCifre - 1; indiceCifra++) {
    inserimentoNumerico[indiceCifra] = inserimentoNumerico[indiceCifra + 1];
  }
  return 1;
}
int rilevaCorrisondenzaDiUnSingoloCarattere(int numeroCaratteriInserimento, int carattereDaCorrispondere, char inserimento[]) {
  int indiceCorrispondenza;
  for (indiceCorrispondenza = 0; indiceCorrispondenza < numeroCaratteriInserimento; indiceCorrispondenza++) {
    if (inserimento[indiceCorrispondenza] == carattereDaCorrispondere) return indiceCorrispondenza;
  }
  return ERRORE;
}
int conversioneCararreteDiUnUnitaNumericaInNumero(char carattere) {
  int risultatoConversione;
  for (risultatoConversione = UNO; risultatoConversione < NOVE + 1; risultatoConversione++) {
    if (risultatoConversione == carattere) return risultatoConversione - UNO;
  }
  return ERRORE;
}
//gestione inserimento e schermate
double gestioneInserimentoSchermateClean(int selezioneSchermata, char charMaiuscOggettoInserimento[]) {
  char inserimento[MAXCHAR];
  double selezioneOpzione = ERRORE;
  int acquisizioni = 0;
  do {
    switch (acquisizioni) {
    case 0:
            schermateClean(selezioneSchermata);
      break;
    case MAX_ERRORI:
      selezioneOpzione = richiestaAnnullaInserimento();
      acquisizioni = -1;
      break;
    default:

      if (acquisizioni != 1) printf("\treinserire %s : ", charMaiuscOggettoInserimento);
      scanf("%s", inserimento);
      selezioneOpzione = inserimentoClean(selezioneSchermata, acquisizioneNumericaGenerale(inserimento));
    }
    acquisizioni++;
  } while ((selezioneOpzione == ERRORE || selezioneOpzione == CONTINUA) && selezioneOpzione != ANNULLA);
  return selezioneOpzione;
}
double gestioneInserimentoSchermateExt(int occMat[][SPECIE][CLASSE][MAXMAT],int dim[][MAXDIM], int genereRef,int genereSrg, int selezioneSchermata, int righe, int colonne, int inxMat,char charMaiuscOggettoInserimento[]) {
  char inserimento[MAXCHAR];
  double selezioneOpzione = ERRORE;
  int acquisizioni = 0;
  do {
    switch (acquisizioni) {
    case 0:
            schermateExt(occMat,dim, genereRef,genereSrg, selezioneSchermata,inxMat);
      break;
    case MAX_ERRORI:
      selezioneOpzione = richiestaAnnullaInserimento();
      acquisizioni = -1;
      break;
    default:
      if (acquisizioni != 1) printf("\treinserire %s : ", charMaiuscOggettoInserimento);
      scanf("%s", inserimento);
      selezioneOpzione = inserimentoExt(occMat,dim, genereRef,genereSrg, selezioneSchermata, acquisizioneNumericaGenerale(inserimento), righe, colonne,inxMat);
    }
    acquisizioni++;
  } while ((selezioneOpzione == ERRORE || selezioneOpzione == CONTINUA) && selezioneOpzione != ANNULLA);
  return selezioneOpzione;
}
double gestioneInserimentoSchermateRix(int selezioneSchermata, int righe, int colonne, char charMaiuscOggettoInserimento[]) {
  char inserimento[MAXCHAR];
  double selezioneOpzione = ERRORE;
  int acquisizioni = 0;
  do {
    switch (acquisizioni) {
    case 0:
            schermateRix(selezioneSchermata, righe, colonne);
      break;
    case MAX_ERRORI:
      selezioneOpzione = richiestaAnnullaInserimento();
      acquisizioni = -1;
      break;
    default:
      if (acquisizioni != 1) printf("\treinserire %s : ", charMaiuscOggettoInserimento);
      scanf("%s", inserimento);
      selezioneOpzione = inserimentoRix(selezioneSchermata, acquisizioneNumericaGenerale(inserimento), righe, colonne);
    }
    acquisizioni++;
  } while ((selezioneOpzione == ERRORE || selezioneOpzione == CONTINUA) && selezioneOpzione != ANNULLA);
  return selezioneOpzione;
}
double gestioneInserimentoSchermataIndice(int occMat[][SPECIE][CLASSE][MAXMAT],float mat[][MAXRG][MAXCL],int dim[][MAXDIM], int genereRef,int genereRcv, int opera,int termine,int inxMat,int specie,char charMaiuscOggettoInserimento[]) {
    char inserimento[MAXCHAR];
    double selezioneOpzione = ERRORE;
    int acquisizioni = 0;
    do {
      switch (acquisizioni) {
      case 0:
              schermataIndici(occMat,mat, dim,genereRef,genereRcv,opera,termine,inxMat,specie);
        break;
      case MAX_ERRORI:
        selezioneOpzione = richiestaAnnullaInserimento();
        acquisizioni = - 1;
        break;
      default:
        if (acquisizioni != 1) printf("\treinserire %s : ", charMaiuscOggettoInserimento);
        scanf("%s", inserimento);
              selezioneOpzione = acquisizioneNumericaGenerale(inserimento);
              selezioneOpzione = inserimentoNumeroSuVettore(selezioneOpzione, occMat[genereRcv][specie][INX], occMat[genereRcv][specie][NUM][MINMAT]);
      }
      acquisizioni++;
    } while ((selezioneOpzione == ERRORE || selezioneOpzione == CONTINUA) && selezioneOpzione != ANNULLA);
    return selezioneOpzione;
  }
double modificaValore(int selezioneSchermata, int indiceMatrice, int righe, int colonne, double valorePrima, char caratteriMinuscoliOggettoInserimento[]) {
  //non prevista modifica indice matrice
  if (valorePrima == DISUSO) {
    if (colonne == DISUSO) valorePrima = righe;
    if (righe == DISUSO) valorePrima = colonne;
  }
  int acquisizioni = 0;
  char inserimento[MAXCHAR];
  double valoreDopo = ERRORE;
  do {
    switch (acquisizioni) {
    case 0:
            schermataMod(selezioneSchermata, righe, colonne, valorePrima, indiceMatrice);
      break;
    case MAX_ERRORI:
      valoreDopo = richiestaAnnullaInserimento();
      acquisizioni = -1;
      break;
    default:
      if (acquisizioni != 1) printf("\treinserire %s : ", caratteriMinuscoliOggettoInserimento);
      scanf("%s", inserimento);
      valoreDopo = inserimentoRix(selezioneSchermata, acquisizioneNumericaGenerale(inserimento), righe, colonne);
      if (valoreDopo == valorePrima) valoreDopo = ERRORE;
    }
    acquisizioni++;
  } while ((valoreDopo == ERRORE || valoreDopo == CONTINUA) && valoreDopo != ANNULLA);

  return valoreDopo;
}
int richiestaAnnullaInserimento() {
  int acquisizioni = 0;
  int annullamento = ERRORE;
  char inserimento[MAXCHAR];
  do {
    switch (acquisizioni) {
    case 0:
      printf("\n\n\tannullare inserimento ?");
      printf("\n\t\t1.annulla");
      printf("\n\t\t2.continua");
      printf("\n\t scelta = ");
      break;
    case MAX_ERRORI:
      acquisizioni = - 1;
      break;
    default:
      if (acquisizioni != 1) printf("\treinserire valore : ");
      scanf("%s", inserimento);
            switch ((int)acquisizioneNumericaGenerale(inserimento)) {
            case 1:
              printf("\n\tinserimento interrotto\n");
              annullamento = ANNULLA;
              break;
            case 2:
              printf("\n\tinserimento continuato\n");
              annullamento = CONTINUA;
              break;
            default:
              annullamento = ERRORE;
            }
    }
    acquisizioni++;
  } while (annullamento == ERRORE);

  return annullamento;
}
//gestione schermate
void schermateClean(int operazione) {
  switch (operazione) {
  case LAUNCHER:
    printf("\n----SCHERMATA DI LANCIO\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.avvia");
    printf("\n\t\t2.spegni");
    printf("\n\tscelta = ");
    break;
  case PANNELLO:
    printf("\n----PANNELLO DI CONTROLLO\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.continua");
    printf("\n\t\t2.riavvia");
    printf("\n\t\t3.spegni");
    printf("\n\tscelta = ");
    break;
  case PRINCIPALE_0_MAT:
    printf("\n----SCHERMATA PRINCIPALE\n");
    printf("\n\timpossibile effettuare alcuna operazione");
    printf("\n\t\t-\tnessuna matrice caricata");
    printf("\n\t\t-\tcaricare almeno una matrice\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.carica matrici");
    printf("\n\t\t2.pannello di controllo");
    printf("\n\tscelta = ");
    break;
  case PRINCIPALE:
    printf("\n----SCHERMATA PRINCIPALE\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.gestione matrici");
    printf("\n\t\t2.operazioni tra matrici");
    printf("\n\t\t3.pannello di controllo");
    printf("\n\tscelta = ");
    break;
  case GESTIONE_MAT:
    printf("\n----GESTIONE MATRICI\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.carica matrici");
    printf("\n\t\t2.visualizza matrici");
    printf("\n\t\t3.modfifica matrici");
    printf("\n\t\t4.elimina matrici");
    printf("\n\t\t0.schermata principale");
    printf("\n\tscelta = ");
    break;
  case GESTIONE_MAT_ALL_IN:
    printf("\n----GESTIONE MATRICI\n");
    printf("\n\timpossibile caricare altre matrici");
    printf("\n\t\t-\tnumero massimo matrici INPUT raggiunto");
    printf("\n\t\t-\teliminarne almeno una matrice INPUT\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.visualizza matrici");
    printf("\n\t\t2.modfifica matrici");
    printf("\n\t\t3.elimina matrici");
    printf("\n\t\t0.schermata principale");
    printf("\n\tscelta = ");
    break;


      case PICK_PROD:
          printf("\n----OPERAZIONE DI MOLTIPLICAZIONE\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.prodotto con scalare");
          printf("\n\t\t2.prodotto tra matrici");
          printf("\n\t\t0.indietro");
          printf("\n\tscelta = ");
          break;
      case PICK_QUAD:
          printf("\n----OPERAZIONI CON DETERMINANTE\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.calcola determinante");
          printf("\n\t\t2.calcola matrice inversa");
          printf("\n\t\t0.indietro");
          printf("\n\tscelta = ");
          break;

  case CARICA_MAN_UP:
    printf("\n----CARICA MATRICI MANUALE\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.carica valori");
    printf("\n\t\t2.modifica dimensioni");
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
    break;
  case CARICA_MAN_DOWN:
    printf("\n----CARICA MATRICI MANUALE\n");
    printf("\n\timpossibile caricare valori matrice");
    printf("\n\t\t- caricare prima le dimensioni\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.carica dimensioni");
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
    break;
  case CARICA_AUTO_UP:
    printf("\n----CARICA MATRICI AUTOMATICO\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.carica valori");
    printf("\n\t\t2.modifica dimensioni");
    printf("\n\t\t3.carica tutte le matrici");
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
    break;
  case CARICA_AUTO_DOWN:
    printf("\n----CARICA MATRICI AUTOMATICO\n");
    printf("\n\tselezionare : ");
    printf("\n\t\t1.carica singola matrice");
    printf("\n\t\t2.carica dimensioni");
    printf("\n\t\t3.carica tutte le matrici");
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
    break;
  case CARICA:
    printf("\n----CARICA MATRICI\n");
    printf("\n\tselezionare caricamento : ");
    printf("\n\t\t1.manuale");
    printf("\n\t\t2.automatico");
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
    break;
  case MODDIM:
    printf("\n----MODIFICA DIMENSIONI\n");
    printf("\n\tselezionare modifica : ");
    printf("\n\t\t1.righe");
    printf("\n\t\t2.colonne");
    printf("\n\t\t3.righe e colonne");
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
    break;

  case PICK_SUM:
    printf("\n----SOMMA TRA MATRICI\n");
    printf("\n\tspecificare operazione : ");
    printf("\n\t\t1.addizzione");
    printf("\n\t\t2.sottrazzione");
   printf("\n\t\t0.annulla");
    printf("\n\tscelta = ");
          break;
      case  OPERAMAT_ALL:
          printf("\n----OPERAZIONI TRA MATRICI\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.identifica");
          printf("\n\t\t2.operazioni algebriche");
          printf("\n\t\t3.matrice trasposta");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;
      case  OPERAMAT_ALLOUT_RIX:
          printf("\n----OPERAZIONI TRA MATRICI\n");
          printf("\n\timpossibile salvare i risultati dei calcoli");
          printf("\n\t\t-\tnumero massimo matrici OUTPUT raggiunto");
          printf("\n\t\t-\teliminarne almeno una matrice OUTPUT\n");
          printf("\n\tmatrici quadrate non presenti\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.identifica");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;
      case  OPERAMAT_ALLOUT_EXT:
          printf("\n----OPERAZIONI TRA MATRICI\n");
          printf("\n\timpossibile salvare i risultati dei calcoli");
          printf("\n\t\t-\tnumero massimo matrici OUTPUT raggiunto");
          printf("\n\t\t-\teliminarne almeno una matrice OUTPUT\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.identifica");
          printf("\n\t\t2.calcola determinante");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;
      case OPERAMAT_OPERALG_RIX:
          printf("\n----OPERAZIONI ALGEBRICHE\n");
          printf("\n\timpossibile effettuare operazioni con :");
          printf("\n\t\t-\tmatrici quadrate ");
          printf("\n\t\t-\tmatrici moltibilcabili");
          printf("\n\tqueste matrici non sono presenti\n");
          printf("\n\t\t1.somma tra matrici");
          printf("\n\t\t2.prodotto con scalare");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;
      case OPERAMAT_ALL_OPERALG:
          printf("\n----OPERAZIONI ALGEBRICHE\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.somma tra matrici");
          printf("\n\t\t2.operazione di moltiplicazione");
          printf("\n\t\t3.operazioni con determinante");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;
      case OPERAMAT_NOQUAD_OPERALG:
          printf("\n----OPERAZIONI ALGEBRICHE\n");
          printf("\n\tmatrici quadrate non presenti\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.somma tra matrici");
          printf("\n\t\t2.operazione di moltiplicazione");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;
      case OPERAMAT_NOMOLTPL_OPERALG:
          printf("\n----OPERAZIONI ALGEBRICHE\n");
          printf("\n\tmatrici moltiplicabili non presenti\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.somma tra matrici");
          printf("\n\t\t2.prodotto con scalare");
          printf("\n\t\t3.operazioni con determinante");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;
      case OPERAMAT_ONLYQUAD_OPERALG:
          printf("\n----OPERAZIONI ALGEBRICHE\n");
          printf("\n\timpossibile effettuare operazioni con :");
          printf("\n\t\t-\tmatrici inverse ");
          printf("\n\t\t-\tmatrici moltibilcabili");
          printf("\n\tqueste matrici non sono presenti\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.somma tra matrici");
          printf("\n\t\t2.prodotto con scalare");
          printf("\n\t\t3.calcola determinante");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;
      case OPERAMAT_NOINV_OPERALG:
          printf("\n----OPERAZIONI ALGEBRICHE\n");
          printf("\n\tselezionare : ");
          printf("\n\t\t1.somma tra matrici");
          printf("\n\t\t2.operazione di moltiplicazione");
          printf("\n\t\t3.calcola determinante");
         printf("\n\t\t0.annulla");
          printf("\n\tscelta = ");
          break;

  }

}
void schermateExt(int occMat[][SPECIE][CLASSE][MAXMAT],int dim[][MAXDIM],int genereRef, int genereSrg, int selezioneOpera,int inxMat) {
  int selezioneModalita = RIX;
  char charMaiucMat[MAXCHAR] = "OUTPUT";
  if (occMat[FREQ][MAX][INX][MINMAT] < INXMINOUT) strcpy(charMaiucMat, "INPUT");
  switch (selezioneOpera) {
  case CARICA_MAN_RG:
    schermataCaricaDimensioneMatrice("RIGHE", "righe", occMat[NEUTRO][IN][NUM][MINMAT]);
    break;
  case CARICA_MAN_CL:
    schermataCaricaDimensioneMatrice("COLONNE", "colonne", occMat[NEUTRO][IN][NUM][MINMAT]);
    break;
  case DELULTIMA:
    printf("\n----ELIMINA ULTIMA MATRICE.%d %s\n", occMat[FREQ][MAX][INX][MINMAT] + 1, charMaiucMat);
    printf("\n\teliminare ultima matrice ?");
    printf("\n\t\t1.elimina");
    printf("\n\t\t2.annulla");
    printf("\n\tscelta = ");
    break;
  default:
    if (selezioneOpera < INXMIN_OPERA_RIX || (selezioneOpera <= INXMAXOPERALG &&  selezioneOpera >= INXMINOPERALG )) selezioneModalita = EXT;
    gestioneSmartSchermate(occMat, dim,genereRef,genereSrg, selezioneModalita, selezioneOpera);
  }
}
void schermataMod(int operazione, int righe, int colonne, double valore, int indiceMatrice) {
  switch (operazione) {
  case MODRG:
    schermataModificaDimensioneMatrice("RIGHE", "righe", righe, indiceMatrice + 1);
    break;
  case MODCL:
    schermataModificaDimensioneMatrice("COLONNE", "colonne", colonne, indiceMatrice + 1);
    break;
  case MODVAL:
    printf("\n\tCELLA.%d.%d     VALORE", righe + 1, colonne + 1);
    printf("\n\tMATRICE.%d     %3.2f\n", indiceMatrice + 1, valore);
    printf("\n\tvalore = ");
  }
}
void schermateRix(int operazione, int righe, int colonne) {
    char charMaiuscTermini[OPERALG][TERMINI][MAXCHAR];
    int opera;
    opera = associaOperaRix(righe);
    associaCharMaiuscTermini(charMaiuscTermini);
  switch (operazione) {
      case TERMINE2:
          printf("\n\t%s SCALARE",charMaiuscTermini[opera][TERMINE2]);
          printf("\n\tvalore = ");
          break;
  case CARICA_MAN_VAL:
    printf("\n\tvalore[%d][%d] = ", righe + 1, colonne + 1);
    break;
  case PICKRG:
    schermataSelezionaDimensione(righe, "RIGA   ", "riga");
    break;
  case PICKCL:
    schermataSelezionaDimensione(colonne, "COLONNA", "colonna");
    break;
  case NUMMOD:
    printf("\n\tNUMERO     - max.%d", righe * colonne);
    printf("\n\tMODIFICHE  - min.1\n");
    printf("\n\tmodifiche = ");
    break;
  case PICKMOD:
    printf("\n\tSELEZIONE VALORI\n");
    printf("\n\tmodificare valori: ");
    printf("\n\t\t1.solo un valore");
    printf("\n\t\t2.intervallo di valori");
    printf("\n\t\t3.tutti i valori (%d)", righe * colonne);
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
    break;
  }
}
void gestioneSmartSchermate(int occMat[][SPECIE][CLASSE][MAXMAT],int dim[][MAXDIM],int genereRef,int genere, int selezione, int selezioneOpera) {
  char charMaiuscFreq[TIPO][MAXCHAR];
  char charMaiuscOperazione[OPERAZIONI][MAXCHAR];
    char charMaiuscTermini[OPERALG][TERMINI][MAXCHAR];
    int termine = TERMINE1;
    int operalg = associaOperaRix(selezioneOpera);
  associaCharMaiuscOperazioni(charMaiuscOperazione);
    associaCharMaiuscTermini(charMaiuscTermini);
  associaMatFreq(occMat, genere);
  aggiornaCharMaiuscFreq(occMat, charMaiuscFreq);
    if(genereRef == MOLTPLTOR || genereRef == ADDENDO2)termine = TERMINE2;
  switch (aggiornaStatoPlus(occMat[FREQ][MAX][STATO][MINMAT],occMat[FREQ][MIN][STATO][MINMAT])) {
  case UNA_PER:
    printf("\n----%s MATRICI %s\n", charMaiuscOperazione[selezioneOpera],charMaiuscTermini[operalg][termine] );
    printf("\n\tselezionare matrice : ");
    printf("\n\t\t1.unica di %s", charMaiuscFreq[MIN]);
    printf("\n\t\t2.unica di %s", charMaiuscFreq[MAX]);
    break;
  case CON_UNA:
    printf("\n----%s MATRICI  %s\n", charMaiuscOperazione[selezioneOpera],charMaiuscTermini[operalg][termine]);
    printf("\n\tselezionare matrice : ");
    printf("\n\t\t1.unica di %s", charMaiuscFreq[MIN]);
    printf("\n\t\t2.matrici di %s", charMaiuscFreq[MAX]);
    break;
  default:
    switch (occMat[FREQ][MIN][STATO][MINMAT]) {
    case NESSUNA:
      printf("\n----%s MATRICI %s %s\n", charMaiuscOperazione[selezioneOpera], charMaiuscFreq[MAX], charMaiuscTermini[operalg][termine]);
      printf("\n\tselezionare matrice : ");
      printf("\n\t\t1.matrice scelta");
      printf("\n\t\t2.matrice corrente");
      break;
    default:
      printf("\n----%s MATRICI  %s\n", charMaiuscOperazione[selezioneOpera],charMaiuscTermini[operalg][termine]);
      printf("\n\tselezionare matrice : ");
      printf("\n\t\t1.matrici di %s", charMaiuscFreq[MIN]);
      printf("\n\t\t2.matrici di %s", charMaiuscFreq[MAX]);
    }
  }
  switch (selezione) {
  case RIX:
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
    break;
  case EXT:
    printf("\n\t\t3.tutte le matrici");
    printf("\n\t\t0.indietro");
    printf("\n\tscelta = ");
  }
}
//altre schermate
void schermataSelezionaDimensione(int dimensione, char caratteriMaiuscoliDimensione[], char caratteriMinuscoliDimensione[]) {
  printf("\n\tSELEZIONE   - max.%d", dimensione);
  printf("\n\t%s     - min.1\n", caratteriMaiuscoliDimensione);
  printf("\n\t%s = ", caratteriMinuscoliDimensione);
}
void schermataModificaDimensioneMatrice(char caratteriMaiuscoliDimensione[], char caratteriMinuscoliDimensione[], int dimensione, int numeroMatriciInput) {
  printf("\n\tMODIFICA\t\tVALORE\n\t%s (%d)\t\t- min : 1\n\tMATRICE.%d\t\t- max : 4\n\n\t%s = ", caratteriMaiuscoliDimensione, dimensione, numeroMatriciInput, caratteriMinuscoliDimensione);
}
void schermataCaricaDimensioneMatrice(char caratteriMaiuscoliDimensione[], char caratteriMinuscoliDimensione[], int numeroMatriciInput) {
  printf("\n\tCARICA\t\t\tVALORE\n\t%s\t\t\t- min : 1\n\tMATRICE.%d\t\t- max : 4\n\n\t%s = ", caratteriMaiuscoliDimensione, numeroMatriciInput + 1, caratteriMinuscoliDimensione);
}
//schermate di notifica
void notificaSingoloValoreModificato(int indiceMatrice, int riga, int colonna, float valorePrima, float valoreDopo) {
  printf("\n\tCELLA.%d.%d     MODIFICATA", riga + 1, colonna + 1);
  printf("\n\tMATRICE.%d     %3.2f -> %3.2f\n", indiceMatrice, valorePrima, valoreDopo);
}
void notificaSingolaModificaGenerica(int valorePrima, int valoreDopo, int indiceMatrice, char caratteriMaiuscoliOggettoModifica[]) {
  printf("\n\tMODIFICA    %s", caratteriMaiuscoliOggettoModifica);
  printf("\n\tMATRICE.%d   %d -> %d\n", indiceMatrice, valorePrima, valoreDopo);
}
void notificaDimensioniModificate(int inxMat, int dim[][MAXDIM], int righeDopo, int colonneDopo) {
  printf("\n\tMODIFICA    RIGHE   %d -> %d", dim[inxMat][INXRG], righeDopo);
  printf("\n\tMATRICE.%d   COLONNE %d -> %d\n", inxMat + 1, dim[inxMat][INXCL], colonneDopo);
}

//gestione inserimento
double inserimentoNumeroSuIntervallo(double numero, int limiteMinimo, int limiteMassimo) {
  if (limiteMinimo > limiteMassimo) swapInt( & limiteMinimo, & limiteMassimo);
  if (numero < limiteMinimo || numero > limiteMassimo) return ERRORE;
  return numero;
}
int inserimentoNumeroSuVettore(int numero, int inxMat[], int numMat) {
  int i = 0;
  int stato = ERRORE;
  for (i = 0; i < numMat; i++) {
    if (numero - 1 == inxMat[i]) {

      stato = ANNULLA;
      break;
    }
  }
  switch (stato) {
  case ERRORE:
    return ERRORE;
  default:
    return inxMat[i] + 1;
  }
}
double inserimentoClean(int schermata, double selezioneOpzione) {
  switch (schermata) {
  case LAUNCHER:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 1, 2)) {
              default:
                return ERRORE;
              case 1: return ESECUZIONE; case 2: return SPEGNIMENTO;
          }
  case PANNELLO:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 1, 3)) {
              case 1: return ESECUZIONE; case 2: return ACCENSIONE;case 3: return SPEGNIMENTO;
              default:
                return ERRORE;
          }
    return inserimentoNumeroSuIntervallo(selezioneOpzione, 1, 3);
  case PRINCIPALE_0_MAT:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 1, 2)) {
              case 1: return CARICA; case 2: return INCERTEZZA;
              default:
                return ERRORE;
          }
  case PRINCIPALE:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 1, 3)) {
              case 1: return GESTIONE_MATRICI; case 2: return OPERAZIONI_MATRICI; case 3: return INCERTEZZA;
              default:
                return ERRORE;
          }
  case GESTIONE_MAT:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 4)) {
              case 1: return CARICA; case 2: return VISUALIZZA; case 3:return MODIFICA; case 4: return ELIMINA; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
  case GESTIONE_MAT_ALL_IN:
    switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3)) {
        case 1: return VISUALIZZA; case 2: return MODIFICA; case 3: return ELIMINA; case 0: return ANNULLA;
    default:
      return ERRORE;
    }
      case PICK_SUM:
          return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 2);
    

      return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 5);
      case PICK_PROD:
        return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 2);
    case CARICA:
      return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 2);
    case CARICA_MAN_UP:
      switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 2)) {
      case 1: return 2; case 2: return 1; case 0: return 0;
      default:
        return ERRORE;
      }
      case CARICA_MAN_DOWN:
        return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 1);
      case CARICA_AUTO_UP:
        return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3);
      case CARICA_AUTO_DOWN:
        return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3);
      case MODDIM:
        return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3);
   
      case  OPERAMAT_ALL:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3)) {
              case 1: return IDENTIFICA; case 2: return OPERAMAT_OPERALG; case 3: return TRASPOSTA; case 0: return 0;
          default:
            return ERRORE;
          }
      case  OPERAMAT_ALLOUT_RIX:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 1)) {
              case 1: return IDENTIFICA; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
      case  OPERAMAT_ALLOUT_EXT:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 2)) {
              case 1: return IDENTIFICA; case 2: return DETERMINANTE; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
      case OPERAMAT_OPERALG_RIX:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 2)) {
              case 1: return PICK_SUM; case 2: return PRODSCAL; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
      case OPERAMAT_ALL_OPERALG:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3)) {
              case 1: return PICK_SUM; case 2: return PICK_PROD; case 3: return PICK_QUAD; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
      case OPERAMAT_NOQUAD_OPERALG:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 2)) {
              case 1: return PICK_SUM; case 2: return PICK_PROD; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
      case OPERAMAT_NOMOLTPL_OPERALG:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3)) {
              case 1: return PICK_SUM; case 2: return PRODSCAL; case 3: return PICK_QUAD; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
      case OPERAMAT_ONLYQUAD_OPERALG:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3)) {
              case 1: return PICK_SUM; case 2: return PRODSCAL; case 3: return DETERMINANTE; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
      case OPERAMAT_NOINV_OPERALG:
          switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3)) {
              case 1: return PICK_SUM; case 2: return PICK_PROD; case 3: return DETERMINANTE; case 0: return ANNULLA;
          default:
            return ERRORE;
          }
      default:
        return selezioneOpzione;
  }
}
double inserimentoExt(int occMat[][SPECIE][CLASSE][MAXMAT],int dim[][MAXDIM], int genereRef,int genereSrg, int selezioneSchermata, double selezioneOpzione, int righe, int colonne,int inxMat) {
  associaMatFreq(occMat, NEUTRO);
  switch (selezioneSchermata) {
  case CARICA_MAN_RG:
    return inserimentoNumeroSuIntervallo(selezioneOpzione, MINRG, MAXRG);
  case CARICA_MAN_CL:
    return inserimentoNumeroSuIntervallo(selezioneOpzione, MINCL, MAXCL);
    case DELULTIMA:
      switch ((int) inserimentoNumeroSuIntervallo(selezioneOpzione, 1, 2)) {
      case 2: return 0; case 1: return 1;
      default:
        return ERRORE;
      }
      default:
        //schermate di selezione estesa
        if (( (selezioneSchermata >= INXMIN_OPERA_EXT && selezioneSchermata <= INXMAX_OPERA_EXT )|| selezioneSchermata) ) return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3);
        //schermate di selezione ristretta
        else if (selezioneSchermata >= INXMIN_OPERA_RIX && selezioneSchermata <= INXMAX_OPERA_RIX) return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 2);
        //schermate di selezione generale
        else return selezioneOpzione;
  }
}
double inserimentoRix(int selezioneSchermata, double selezioneOpzione, int righe, int colonne) {
  switch (selezioneSchermata) {
  case MODRG:
    return inserimentoNumeroSuIntervallo(selezioneOpzione, MINRG, 4);
  case MODCL:
    return inserimentoNumeroSuIntervallo(selezioneOpzione, MINCL, 4);
  case PICKMOD:
    return inserimentoNumeroSuIntervallo(selezioneOpzione, 0, 3);
  case PICKRG:
    return inserimentoNumeroSuIntervallo(selezioneOpzione, MINRG, righe);
  case PICKCL:
    return inserimentoNumeroSuIntervallo(selezioneOpzione, MINCL, colonne);
  case NUMMOD:
    return inserimentoNumeroSuIntervallo(selezioneOpzione, 1, righe * colonne);
  default:
    return selezioneOpzione;
  }
}
//azzera variabili principali
void azzeraMat(float mat[][MAXRG][MAXCL]) {
  int inxMat, rg, cl;
  for (inxMat = MINMAT; inxMat < MAXMAT; inxMat++) {
    for (rg = 0; rg < MAXRG; rg++) {
      for (cl = 0; cl < MAXRG; cl++) {
        mat[inxMat][rg][cl] = 0;
      }
    }
  }
}
void azzeraDim(int dim[][MAXDIM]) {
  int inxMat;
  for (inxMat = MINMAT; inxMat < MAXMAT; inxMat++) {
    dim[inxMat][INXCL] = MINCL;
    dim[inxMat][INXRG] = MINRG;
  }
}
void azzeraOccMat(int occMat[][SPECIE][CLASSE][MAXMAT]) {
  int i, j, k, h;
  for (i = 0; i < GENERE; i++) {
    for (j = 0; j < SPECIE; j++) {
      for (k = 0; k < CLASSE; k++) {
        for (h = 0; h < MAXMAT; h++) {
          occMat[i][j][k][h] = 0;
        }
      }
    }
  }
}
//indici matrici
int assegnaInx(int occMat[][SPECIE][CLASSE][MAXMAT], int genere) {
  int i;
  for (i = MINMAT; i < MAXMAT_TIPO; i++) {
    occMat[genere][IN][INX][i] = i + INXMININ;
  }
  for (i = MINMAT; i < MAXMAT; i++) {
    occMat[genere][OUT][INX][i] = i + INXMINOUT;
  }
  return occMat[NEUTRO][IN][NUM][MINMAT] + occMat[NEUTRO][OUT][NUM][MINMAT];
}
int assegnaInxAll(int occMat[][SPECIE][CLASSE][MAXMAT], int genere) {
  int i, j;

  for (i = MINMAT; i < occMat[genere][IN][NUM][MINMAT]; i++) {
    occMat[genere][ALL][INX][i] = occMat[genere][IN][INX][i];
  }
  for (j = MINMAT; j < occMat[genere][OUT][NUM][MINMAT]; j++) {
    occMat[genere][ALL][INX][i] = occMat[genere][OUT][INX][j];
    i++;
  }
  return occMat[genere][IN][NUM][MINMAT] + occMat[genere][OUT][NUM][MINMAT];
}
int rilevaInxMat(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL],int dim[][MAXDIM],int genereRef,int genereRcv, int specie, int inxMat){
    int i;
    int j;
    float det;
    int numMat = MINMAT;
    switch(genereRef){
            case ADDENDO2:
            for (i = MINMAT; i < occMat[NEUTRO][specie][NUM][MINMAT]; i++) {
                for (j = MINMAT; j < occMat[NEUTRO][specie][NUM][MINMAT]; j++) {
              if (dim[occMat[NEUTRO][specie][INX][i]][INXRG] == dim[inxMat][INXRG] && dim[occMat[NEUTRO][specie][INX][i]][INXCL] == dim[inxMat][INXCL] ) {
                occMat[genereRcv][specie][INX][numMat] = occMat[NEUTRO][specie][INX][i];
                numMat++;
                  break;
              }
                }
            }
            break;
        case QUAD:
            for (i = MINMAT; i < occMat[NEUTRO][specie][NUM][MINMAT]; i++) {
              if (dim[occMat[NEUTRO][specie][INX][i]][INXRG] == dim[occMat[NEUTRO][specie][INX][i]][INXCL]) {
                occMat[genereRcv][specie][INX][numMat] = occMat[NEUTRO][specie][INX][i];
                numMat++;
              }
            }
            break;
        case MOLTPLNDO:
            for (i = MINMAT; i < occMat[NEUTRO][specie][NUM][MINMAT]; i++) {
              for (j = MINMAT; j < occMat[NEUTRO][specie][NUM][MINMAT]; j++) {
                if (dim[occMat[NEUTRO][specie][INX][i]][INXCL] == dim[occMat[NEUTRO][specie][INX][j]][INXRG]) {
                  occMat[genereRcv][specie][INX][numMat] = occMat[NEUTRO][specie][INX][i];
                  numMat++;
                  break;
                }
              }
            }
            break;
        case MOLTPLTOR:
            for (i = MINMAT; i < occMat[NEUTRO][specie][NUM][MINMAT]; i++) {
              if (dim[inxMat][INXCL] == dim[occMat[NEUTRO][specie][INX][i]][INXRG]) {
                occMat[genereRcv][specie][INX][numMat] = occMat[NEUTRO][specie][INX][i];
                numMat++;
      
              }
            }
            break;
        case INVERSA:
            for (i = MINMAT; i < occMat[NEUTRO][specie][NUM][MINMAT]; i++) {
              if (dim[i][INXRG] == dim[i][INXCL]) {
                  det = calcolaLaplaceDeterminanteMatriceNxN(mat[occMat[NEUTRO][specie][INX][i]],dim[i][INXCL]);
                  if(det != 0){
                occMat[genereRcv][specie][INX][i] = occMat[NEUTRO][specie][INX][i];
                numMat++;
                  }
              }
              }
        
    }
    return numMat;
}
void schermataIndici(int occMat[][SPECIE][CLASSE][MAXMAT],float mat[][MAXRG][MAXCL],int dim[][MAXDIM],int genereRef,int genereRcv,int opera,int termine,int inxMat, int specie) {
    char charMaiuscMat[MAXCHAR] = "OUTPUT";
    int controllo1 = 0; //controllo intervallo
    int controllo2 = 0; //controllo possibilita
    int controllo3 = 0;
    int i = -1;
    int inxMin = 0;
    int app = OUT;
    int app2 = OUT;
    char charMaiuscTermini[OPERALG][TERMINI][MAXCHAR];
    int operaDecompressa;
    if(opera == SUMMAT)operaDecompressa = SUM;
    else if(opera == SUBMAT )operaDecompressa = SUB;
    else if(opera == PRODMAT || opera == PRODSCAL)operaDecompressa = PROD;
    else operaDecompressa = NO_OPERALG;
    switch(genereRcv){
        case FREQ:
            aggiornaMatSmart(occMat,mat, dim, genereRef, genereRcv, inxMat);
            associaMatFreq(occMat, genereRef);
            break;
        default:
            aggiornaMatSmart(occMat,mat, dim, genereRef, genereRcv, inxMat);
    }
    associaCharMaiuscTermini(charMaiuscTermini);
    printf("\n\tSCELTA MATRICE %s",charMaiuscTermini[operaDecompressa][termine]);
      if (occMat[genereRcv][specie][INX][MINMAT] < INXMINOUT){ strcpy(charMaiuscMat, "INPUT");
          app = IN;
      }
      printf("\n\t\t- %s : ", charMaiuscMat);
    do {
      i++;
      if (i < occMat[genereRcv][specie][NUM][MINMAT]) controllo1 = CONTINUA;
      else controllo1 = ANNULLA;
      switch (controllo1) {
      case CONTINUA:
        if (occMat[genereRcv][specie][INX][i] + 1 == occMat[genereRcv][specie][INX][i + 1] && i < occMat[genereRcv][specie][NUM][MINMAT] - 1) controllo2 = CONTINUA;
        else controllo2 = ANNULLA;
        switch (controllo2) {
        case CONTINUA:
          break;
        default:
          if (i != inxMin) printf("%d - %d", occMat[genereRcv][specie][INX][inxMin] + 1, occMat[genereRcv][specie][INX][i] + 1);
          else printf("%d", occMat[genereRcv][specie][INX][inxMin] + 1);
                app2 = app;
                if (occMat[genereRcv][specie][INX][i + 1] < INXMINOUT){ strcpy(charMaiuscMat, "INPUT");
                    app = IN;
                }else{
                    strcpy(charMaiuscMat, "OUTPUT");
                    app = OUT;
                }
                if(app != app2 && i < occMat[genereRcv][specie][NUM][MINMAT] - 1)printf(" ; \n\t\t- %s : ", charMaiuscMat);
                else if (i < occMat[genereRcv][specie][NUM][MINMAT] - 1) printf(" , ");
                
          inxMin = i + 1;
        }
        controllo3 = CONTINUA;
        break;
      default:
        printf(" ; ");
        controllo3 = ANNULLA;
      }
    } while (controllo3 != ANNULLA);
    printf("\n\tindice = ");
}
//aggiorna occMat
int aggiornaStatoPlus(int stato1, int stato2) {
  switch ( stato1) {
  case NESSUNA:
    switch (stato2) {
    case NESSUNA:
      return NESSUNA;
    case SOLO_UNA:
      return SOLO_UNA;
    default:
      return UN_TIPO;
    }
    case SOLO_UNA:
      switch (stato2) {
      case NESSUNA:
        return SOLO_UNA;
      case SOLO_UNA:
        return UNA_PER;
      default:
        return CON_UNA;
      }
      case TUTTE:
        switch (stato2) {
        case NESSUNA:
          return UN_TIPO;
        case SOLO_UNA:
          return CON_UNA;
        case TUTTE:
          return TUTTE;
        default:
          return ALCUNE;
        }
        default:
          switch (stato2) {
          case SOLO_UNA:
            return CON_UNA;
          case NESSUNA:
            return UN_TIPO;
          default:
            return ALCUNE;
          }
  }
}
void associaMatFreq(int occMat[][SPECIE][CLASSE][MAXMAT], int genere) {
    int i,j;
    for(j = MIN; j <= ALL; j ++){
        for(i = NUM; i <= STATO; i ++){
            occMat[FREQ][j][i][MINMAT] =  occMat[genere][j][i][MINMAT];
        }
    }
  copiaVettori(occMat[genere][ALL][INX], occMat[FREQ][ALL][INX]);
  copiaVettori(occMat[genere][IN][INX], occMat[FREQ][MIN][INX]);
  copiaVettori(occMat[genere][OUT][INX], occMat[FREQ][MAX][INX]);
  if (occMat[FREQ][MIN][NUM][MINMAT] > occMat[FREQ][MAX][NUM][MINMAT]) {
    scambiaVettori(occMat[FREQ][MIN][INX], occMat[FREQ][MAX][INX]);
    swapInt( & occMat[FREQ][MAX][NUM][MINMAT], & occMat[FREQ][MIN][NUM][MINMAT]);
      swapInt( & occMat[FREQ][MAX][STATO][MINMAT], & occMat[FREQ][MIN][STATO][MINMAT]);
  }
    else if(occMat[FREQ][MIN][NUM][MINMAT] == occMat[FREQ][MAX][NUM][MINMAT] &&
            occMat[FREQ][MAX][INX][MINMAT] < INXMINOUT ){
        scambiaVettori(occMat[FREQ][MIN][INX], occMat[FREQ][MAX][INX]);
        swapInt( & occMat[FREQ][MAX][NUM][MINMAT], & occMat[FREQ][MIN][NUM][MINMAT]);
        swapInt( & occMat[FREQ][MAX][STATO][MINMAT], & occMat[FREQ][MIN][STATO][MINMAT]);
      }
}
void associaMatNeutro(int occMat[][SPECIE][CLASSE][MAXMAT], int genereSrg,int genereRcv) {
  occMat[genereRcv][OUT][NUM][MINMAT] = occMat[genereSrg][MAX][NUM][MINMAT];
  occMat[genereRcv][IN][NUM][MINMAT] = occMat[genereSrg][MIN][NUM][MINMAT];
  if (occMat[genereSrg][MAX][INX][MINMAT] < INXMINOUT) swapInt( & occMat[genereRcv][IN][NUM][MINMAT], & occMat[genereRcv][OUT][NUM][MINMAT]);
}
int aggiornaStatoSmart(int occMat[][SPECIE][CLASSE][MAXMAT], int genere) {
  occMat[genere][IN][STATO][MINMAT] = aggiornaStatoRix(occMat[genere][IN][NUM][MINMAT]);
  occMat[genere][OUT][STATO][MINMAT] = aggiornaStatoRix(occMat[genere][OUT][NUM][MINMAT]);
  return aggiornaStatoExt(occMat[genere][ALL][NUM][MINMAT]);
}
void aggiornaMatSmart(int occMat[][SPECIE][CLASSE][MAXMAT],float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int genereRef,int genereRcv,int inxMat){
    if(genereRcv != APP){
        occMat[NEUTRO][ALL][NUM][MINMAT] = assegnaInxAll(occMat, NEUTRO);
    if(genereRef != NEUTRO){
        occMat[genereRcv][IN][NUM][MINMAT] = rilevaInxMat(occMat,mat,dim,genereRef,genereRcv,IN,inxMat);
        occMat[genereRcv][OUT][NUM][MINMAT] = rilevaInxMat(occMat,mat,dim,genereRef,genereRcv,OUT,inxMat);
    }
    if(genereRef == NEUTRO || genereRef == FREQ)occMat[genereRcv][ALL][NUM][MINMAT] = assegnaInxAll(occMat, genereRef);
    else occMat[genereRcv][ALL][NUM][MINMAT] = rilevaInxMat(occMat,mat,dim,genereRef,genereRcv,ALL,inxMat);
    bblCre(occMat[genereRcv][ALL][INX], occMat[genereRcv][ALL][NUM][MINMAT]);
    occMat[genereRcv][ALL][STATO][MINMAT] = aggiornaStatoSmart(occMat, genereRcv);
    }
   
}
int aggiornaStatoRix(int numTipoMat) {
  switch (numTipoMat) {
  case NESSUNA:
    return NESSUNA;
  case SOLO_UNA:
    return SOLO_UNA;
  case MAXMAT_TIPO:
    return TUTTE;
  default:
    return ALCUNE;
  }
}
int aggiornaStatoExt(int numTipoMat) {
  switch (numTipoMat) {
  case NESSUNA:
    return NESSUNA;
  case SOLO_UNA:
    return SOLO_UNA;
  case MAXMAT:
    return TUTTE;
  default:
    return ALCUNE;
  }
}
//operazioni base
int matriceTrasposta(float mat1[][MAXCL],float mat2[][MAXCL], int rg1,int cl1,int *rg2, int *cl2){
    int riga, colonna;
    *rg2 = cl1;
    *cl2 = rg1;
    for (riga = 0; riga < rg1; riga++) {
        for (colonna = 0; colonna < cl1; colonna++) {
            mat2[colonna][riga] =  mat1[riga][colonna];
        }
    }
    return 1;
}
void visualizzaSingolaMatrice(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  int riga, colonna;
  for (riga = 0; riga < dim[inxMat][INXRG]; riga++) {
    printf("\n\t\t ");
    for (colonna = 0; colonna < dim[inxMat][INXCL]; colonna++) {
      printf("  %3.2f", mat[inxMat][riga][colonna]);
    }
    printf("\n\t\t ");
  }
}
int eliminaSingolaMatrice(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int numMat, int inxStart) {
  int riga, colonna, inxMat;
  for (inxMat = inxStart; inxMat < numMat - 1; inxMat++) {
    dim[inxMat][0] = dim[inxMat + 1][0];
    dim[inxMat][1] = dim[inxMat + 1][1];
    for (riga = 0; riga < dim[inxMat][0]; riga++) {
      for (colonna = 0; colonna < dim[inxMat][1]; colonna++) {
        mat[inxMat][riga][colonna] = mat[inxMat + 1][riga][colonna];
      }
    }
  }
  return 1;
}
//operazioni algebriche
int moltiplicazione(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat,float valore ,int numMat, int oggetto){
    int i, j, k;
    float sommatoria;
    switch(oggetto){
        case MAT:
            for (i = 0; i < dim[inxMat][INXRG]; i++) {
              for (j = 0; j < dim[(int)valore][INXCL]; j++) {
                sommatoria = 0;
                for (k = 0; k < dim[(int)valore][INXRG]; k++) {
                  sommatoria += mat[inxMat][i][k] * mat[(int)valore][k][j];
                }
                  mat[numMat][i][j] = sommatoria;
              }
            }
            dim[numMat][INXRG] = dim[inxMat][INXRG];
            dim[numMat][INXCL] = dim[(int)valore][INXCL];
            break;
        case SCAL:
            
            prodottoScalareMatrice( mat[inxMat],  mat[numMat], valore, dim[inxMat][INXRG], dim[inxMat][INXCL],&dim[numMat][INXRG], &dim[numMat][INXCL]);
    }
    return 1;
}
int prodottoScalareMatrice(float mat1[][MAXCL], float mat2[][MAXCL],float valore, int rg1,int cl1, int *rg2,int *cl2){
    int i,j;
    for (i = 0; i <rg1; i++) {
      for (j = 0; j < cl1; j++) {
          mat2[i][j] = valore * mat1[i][j];
      }
    }
    *rg2 = rg1;
    *cl2 = cl1;
    return 1;
}
int addizzione(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat,float valore ,int numMat, int selezione){
    int i, j;
            for (i = 0; i < dim[inxMat][INXRG]; i++) {
              for (j = 0; j < dim[inxMat][INXCL]; j++) {
                  switch(selezione){
                      case SUM:
                          mat[numMat][i][j] = mat[inxMat][i][j] + mat[(int)valore][i][j];
                          break;
                      default:
                          mat[numMat][i][j] = mat[inxMat][i][j] - mat[(int)valore][i][j];
                  }
              }
            }
    dim[numMat][INXRG] = dim[inxMat][INXRG];
    dim[numMat][INXCL] = dim[inxMat][INXCL];
    return 1;
}
//modifica
void modificaValoriMatrice(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, char charMaiuscAttualeOdScelta[]) {
  int rg = 0;
  int cl = 0;
  int modifica = 0;
  switch (dim[inxMat][INXRG]) {
  case MINRG:
    switch (dim[inxMat][INXCL]) {
    case MINCL:
      //scalare
      switch (modificaSmartSingoloValoreMatrice(mat, dim, inxMat, 1, rg, cl)) {
      case ANNULLA:
        break;
      default:
        printf("\n\tvalore MATRICE.%d modificato con successo\n", inxMat + 1);
      }
      break;
    default:
      //vettore colonna
      modificaSmartValoriMatrice(mat, dim, inxMat, cl, rg, modifica, VETCL, charMaiuscAttualeOdScelta);
    }
    break;
  default:
    switch (dim[inxMat][INXCL]) {
    case MINCL:
      //vettore riga
      modificaSmartValoriMatrice(mat, dim, inxMat, cl, rg, modifica, VETRG, charMaiuscAttualeOdScelta);
      break;
    default:
      //matrice
      modificaSmartValoriMatrice(mat, dim, inxMat, cl, rg, modifica, MATGEN, charMaiuscAttualeOdScelta);
    }
  }
}
int modificaSmartSingoloValoreMatrice(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int modificheRimaste, int rg, int cl) {
  float val;
  val = modificaValore(MODVAL, inxMat, rg, cl, mat[inxMat][rg][cl], "valore");
  switch ((int) val) {
  case ANNULLA:
    return ANNULLA;
  default:
    notificaSingoloValoreModificato(inxMat, rg, cl, mat[inxMat][rg][cl], val);
    mat[inxMat][rg][cl] = val;
    return modificheRimaste - 1;
  }
}
void modificaSmartValoriMatrice(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int cl, int rg, int modifica, int tipoMat, char charMaiuscAttualeOdScelta[]) {
  int numModifiche = 0;
  int modificheRimaste = 0;
  int controlloTermineCiclo = 0;
  char charMaiuscMat[MAXCHAR] = "OUTPUT";
  if (inxMat < INXMINOUT) strcpy(charMaiuscMat, "INPUT");
  int conteggioCicli = 0; //per non visualizzare due volte al primo ciclo la schermata "MODIFICA UNICA/SCELTA/ATTUALE MATRICE INPUT/OUTPUT"
  do {
    if (conteggioCicli != 0) printf("\n\tMODIFICA MATRICE %s %s\n", charMaiuscMat, charMaiuscAttualeOdScelta);
    printf("\n\t\tMATRICE.%d\n", inxMat + 1);
    visualizzaSingolaMatrice(mat, dim, inxMat);
    modifica = gestioneInserimentoSchermateRix(PICKMOD, dim[inxMat][INXRG], dim[inxMat][INXCL], "scelta");
    switch (modifica) {
    case ANNULLA:
      if (numModifiche != 0 && modificheRimaste != numModifiche && controlloTermineCiclo != ANNULLA) printf("\n\tmodifiche MATRICE.%d effettuate (%d)\n", inxMat + 1, numModifiche - modificheRimaste);
      break;
    case 0:
      printf("\n\tritorno alla schermata precedente\n");
      break;
    case 1:
      //un solo valore
      printf("\n\tMODIFICA SINGOLO VALORE\n\tMATRICE %s %s\n", charMaiuscMat, charMaiuscAttualeOdScelta);
      switch (eseguiOperazioneModificaSmartMatrice(mat, dim, inxMat, modificheRimaste, rg, cl, tipoMat)) {
      case ANNULLA:
        printf("\n\tritorno alla schermata precedente\n");
        break;
      default:
        printf("\n\tmodifica MATRICE.%d effettuata\n", inxMat + 1);
      }
      break;
    case 2:
      //intervallo valori scelto
      printf("\n\tMODIFICA INTERVALLO VALORI\n\tMATRICE %s %s\n", charMaiuscMat, charMaiuscAttualeOdScelta);
      numModifiche = gestioneInserimentoSchermateRix(NUMMOD, dim[inxMat][INXRG], dim[inxMat][INXCL], "scelta");
      switch (numModifiche) {
      case ANNULLA:
        printf("\n\tritorno alla schermata precedente\n");
        break;
      default:
        modificheRimaste = numModifiche;
        do {
          if (modificheRimaste != 0 && modificheRimaste < numModifiche) printf("\n\t\t%d modifiche rimanenti\n", modificheRimaste);
          switch (eseguiOperazioneModificaSmartMatrice(mat, dim, inxMat, modificheRimaste, rg, cl, tipoMat)) {
          case ANNULLA:
            controlloTermineCiclo = ANNULLA;
            break;
          default:
            modificheRimaste--;
          }
        } while (modificheRimaste != 0 && controlloTermineCiclo != ANNULLA);
      }
      if (numModifiche != 0 && modificheRimaste != numModifiche && controlloTermineCiclo != ANNULLA) printf("\n\tmodifiche MATRICE.%d effettuate (%d)\n", inxMat + 1, numModifiche - modificheRimaste);
      break;
    case 3:
      printf("\n\tMODIFICA TUTTI I VALORI (%d)\n\tMATRICE %s %s\n", dim[inxMat][INXRG] * dim[inxMat][INXCL], charMaiuscMat, charMaiuscAttualeOdScelta);
      //tutti i valori
      numModifiche = dim[inxMat][INXRG] * dim[inxMat][INXCL];
      modificheRimaste = numModifiche;
      do {
        if (numModifiche != 0 && modificheRimaste < numModifiche) printf("\n\t\t%d modifiche rimanenti\n", modificheRimaste);
        switch (eseguiOperazioneModificaSmartMatrice(mat, dim, inxMat, modificheRimaste, rg, cl, tipoMat)) {
        case ANNULLA:
          controlloTermineCiclo = ANNULLA;
          break;
        default:
          modificheRimaste--;
        }
      } while (modificheRimaste != 0 && controlloTermineCiclo != ANNULLA);
      if (numModifiche != 0 && modificheRimaste != numModifiche && controlloTermineCiclo) printf("\n\tmodifiche MATRICE.%d effettuate (%d)\n", inxMat + 1, numModifiche - modificheRimaste);
      break;
    }
    conteggioCicli++;
  } while (modifica != 0 && modifica != ANNULLA);
}
int eseguiOperazioneModificaSmartMatrice(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int modificheRimaste, int rg, int cl, int tipoMat) {
  switch (tipoMat) {
  case VETCL:
    return modificaSmartValoriMatriceVettoreColonna(mat, dim, inxMat, modificheRimaste, rg);
  case VETRG:
    return modificaSmartValoriMatriceVettoreRiga(mat, dim, inxMat, modificheRimaste, cl);
  default:
    return modificaSmartMatriceBidimensionale(mat, dim, inxMat, modificheRimaste, cl, rg);
  }
}
int modificaSmartMatriceBidimensionale(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int modificheRimaste, int rg, int cl) {
  rg = gestioneInserimentoSchermateRix(PICKRG, dim[inxMat][INXRG], DISUSO, "riga");
  switch (rg) {
  case ANNULLA:
    return ANNULLA;
  default:
    return modificaSmartValoriMatriceVettoreColonna(mat, dim, inxMat, modificheRimaste, rg - 1);
  }
}
int modificaSmartValoriMatriceVettoreColonna(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int modificheRimaste, int rg) {
  int cl;
  cl = gestioneInserimentoSchermateRix(PICKCL, DISUSO, dim[inxMat][INXCL], "colonna");
  switch (cl) {
  case ANNULLA:
    return ANNULLA;
  default:
    return modificaSmartSingoloValoreMatrice(mat, dim, inxMat, modificheRimaste, rg, cl - 1);
  }
}
int modificaSmartValoriMatriceVettoreRiga(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int modificheRimaste, int cl) {
  int rg;
  rg = gestioneInserimentoSchermateRix(PICKRG, dim[inxMat][INXRG], DISUSO, "riga");
  switch (rg) {
  case ANNULLA:
    return ANNULLA;
  default:
    return modificaSmartSingoloValoreMatrice(mat, dim, inxMat, modificheRimaste, rg - 1, cl);
  }
}
//carica matrici
int caricaMatrici(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int statoDim, int tipoCarica) {
  int cosaCarica = 0;
  int down = CARICA_MAN_DOWN;
  int up = CARICA_MAN_UP;
  switch (tipoCarica) {
  case MAN:
    down = CARICA_MAN_DOWN;
    up = CARICA_MAN_UP;
    break;
  case AUTO:
    down = CARICA_AUTO_DOWN;
    up = CARICA_AUTO_UP;
  }
  do {
    switch (occMat[NEUTRO][IN][NUM][MINMAT]) {
    case MAXMAT_TIPO:
      cosaCarica = 0;
      break;
    default:
      switch (statoDim) {
      case 0:
        cosaCarica = gestioneInserimentoSchermateClean(down, "scelta");

        break;
      case 1:
        cosaCarica = gestioneInserimentoSchermateClean(up, "scelta");
      }
      switch (cosaCarica) {
      case ANNULLA:
        cosaCarica = 0;
      default:
        switch (tipoCarica) {
        case MAN:
          statoDim = cosaCaricaMan(occMat, mat, dim, cosaCarica, statoDim);
          break;
        case AUTO:
          statoDim = cosaCaricaAuto(occMat, mat, dim, cosaCarica, statoDim);
        }
      }
    }
  } while (cosaCarica != 0);
  return statoDim;
}
int caricaMatriciPlus(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int statoDim) {
  int tipoCarica;
  do {
    switch (occMat[NEUTRO][IN][NUM][MINMAT]) {
    case MAXMAT_TIPO:
      printf("\n\timpossibile caricare altre matrici INPUT");
      printf("\n\t\t-\tnumero massimo matrici INPUT raggiunto");
      printf("\n\t\t-\tper caricarne altre occorre eliminarne alcune\n");
      printf("\n\tritorno alla schermata principale\n");
      tipoCarica = 0;
      break;
    default:
      tipoCarica = gestioneInserimentoSchermateClean(CARICA, "scelta");
      switch (tipoCarica) {
      case 0:
        printf("\n\tritorno alla schermata principale\n");
        break;
      case ANNULLA:
        printf("\n\tritorno alla schermata principale\n");
        tipoCarica = 0;
        break;
      default:
        statoDim = caricaMatrici(occMat, mat, dim, statoDim, tipoCarica);
      }
    }
  } while (tipoCarica != 0);
  return statoDim;;
}
int cosaCaricaMan(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int cosaCarica, int statoDim) {
  int sceltaModicaDimensione;
  switch (cosaCarica) {
  case 1:
    switch (statoDim) {
    case 0:
      statoDim = caricaManualeDimensioni(occMat, dim);
      break;
    case 1:
      sceltaModicaDimensione = gestioneInserimentoSchermateClean(MODDIM, "scelta");
      switch (sceltaModicaDimensione) {
      case 1:
        dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] = modificaManualeSingolaDimensione(occMat, dim, INXRG, MODRG);
        break;
      case 2:
        dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL] = modificaManualeSingolaDimensione(occMat, dim, INXCL, MODCL);

        break;
      case 3:
        modificaManualeDimensioni(occMat, dim);
        break;
      case 0:
        printf("\n\tritorno alla schermata caricamento\n");
      }
      break;
    }
    break;
  case 2:
    printf("\n\tCARICA      VALORI (%d)", dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] * dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL]);
    printf("\n\tMANUALE     MATRICE.%d\n", occMat[NEUTRO][IN][NUM][MINMAT] + 1);
    if (caricaManualeValori(occMat, mat, dim) != ANNULLA) {
      printf("\n\tvalori MATRICE.%d caricati (%d)\n", occMat[NEUTRO][IN][NUM][MINMAT] + 1, dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] * dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL]);
      occMat[NEUTRO][IN][NUM][MINMAT]++;
      statoDim = 0;
    }
    break;
  case 0:
    printf("\n\tritorno alla selezione del caricamento\n");
    break;
  case ANNULLA:
    printf("\n\tritorno alla selezione del caricamento\n");
    cosaCarica = 0;
  }
  return statoDim;
}
int cosaCaricaAuto(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int cosaCarica, int statoDim) {
  int modicaDimensione;
  int rg, cl;
  int numMatInPrima = occMat[NEUTRO][IN][NUM][MINMAT];
  switch (cosaCarica) {
  case 2:
    switch (statoDim) {
    case 0:
      dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] = 1 + rand() % 4;
      dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL] = 1 + rand() % 4;
      printf("\n\tCARICA AUTOMATICO\n\tDIMENSIONI MATRICE.%d\n", occMat[NEUTRO][IN][NUM][MINMAT] + 1);
      printf("\n\t\t- dimensioni caricate \n");
      statoDim = 1;
      break;
    case 1:
      modicaDimensione = gestioneInserimentoSchermateClean(MODDIM, "scelta");
      switch (modicaDimensione) {
      case 1:
        do {
          rg = 1 + rand() % 4;
        } while (rg == dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG]);

        notificaSingolaModificaGenerica(dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG], rg, occMat[NEUTRO][IN][NUM][MINMAT] + 1, "RIGHE");
        dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] = rg;
        break;
      case 2:
        do {
          cl = 1 + rand() % 4;
        } while (cl == dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL]);
        notificaSingolaModificaGenerica(dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL], cl, occMat[NEUTRO][IN][NUM][MINMAT] + 1, "COLONNE");
        dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL] = cl;
        break;
      case 3:
        do {
          rg = 1 + rand() % 4;
        } while (rg == dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG]);
        do {
          cl = 1 + rand() % 4;
        } while (cl == dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL]);
        notificaDimensioniModificate(occMat[NEUTRO][IN][NUM][MINMAT], dim, rg, cl);
        dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] = rg;
        dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL] = cl;
        break;
      case 0:
        printf("\n\tritorno alla schermata caricamento\n");
      }
      break;
    }
    break;
  case 1:
    printf("\n\tCARICA AUTOMATICO\n\tSINGOLA MATRICE.%d\n", occMat[NEUTRO][IN][NUM][MINMAT] + 1);
    do {
      switch (statoDim) {
      case 0:
        dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] = 1 + rand() % 4;
        dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL] = 1 + rand() % 4;
        printf("\n\t\t- dimensioni caricate ");
        statoDim = CONTINUA;
        break;
      default:
        printf("\n\t\t- valori caricati ");
        occMat[NEUTRO][IN][NUM][MINMAT] += caricaAutomaticoValori(mat, dim, occMat[NEUTRO][IN][NUM][MINMAT]);
        statoDim = ANNULLA;
      }
    } while (statoDim != ANNULLA);
    printf("\n");
    statoDim = 0;
    break;
  case 3:
    printf("\n\tCARICA AUTOMATICO\n\tTUTTE LE MATRICI\n");
    do {
      do {
        switch (statoDim) {
        case 0:
          dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] = 1 + rand() % 4;
          dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL] = 1 + rand() % 4;
          statoDim = CONTINUA;
          break;
        default:
          occMat[NEUTRO][IN][NUM][MINMAT] += caricaAutomaticoValori(mat, dim, occMat[NEUTRO][IN][NUM][MINMAT]);
          statoDim = ANNULLA;
        }
      } while (statoDim != ANNULLA);
      statoDim = 0;
    } while (occMat[NEUTRO][IN][NUM][MINMAT] != MAXMAT_TIPO);
    printf("\n\ttutte le matrici di INPUT rimanenti caricate (%d)\n", MAXMAT_TIPO - numMatInPrima);
    break;
  case 0:
    printf("\n\tritorno alla selezione del caricamento\n");
  }
  return statoDim;
}

int caricaAutomaticoValori(float matrici[][MAXRG][MAXCL], int dimensioni[][MAXDIM], int numMat) {
  int i, j;
  for (i = 0; i < dimensioni[numMat][INXRG]; i++) {
    for (j = 0; j < dimensioni[numMat][INXCL]; j++) {
      matrici[numMat][i][j] = 100 - rand() % 200;
    }
  }
  return 1;
}
int caricaManualeDimensioni(int occMat[][SPECIE][CLASSE][MAXMAT], int dim[][MAXDIM]) {
  int rg, cl;
    rg = gestioneInserimentoSchermateExt(occMat, dim, NEUTRO, NEUTRO, CARICA_MAN_RG, DISUSO, DISUSO, DISUSO, "righe");
  switch (rg) {
  case ANNULLA:
    return 0;
  default:
          cl = gestioneInserimentoSchermateExt(occMat, dim, NEUTRO, NEUTRO, CARICA_MAN_CL, DISUSO, DISUSO, DISUSO,"colonne");
    switch (cl) {
    case ANNULLA:
      return 0;
    default:
      dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] = rg;
      dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL] = cl;
      printf("\n\tCARICA      RIGHE   %d", dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG]);
      printf("\n\tMATRICE.%d   COLONNE %d\n", occMat[NEUTRO][IN][NUM][MINMAT] + 1, dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL]);
      return 1;
    }
  }
}
int modificaManualeSingolaDimensione(int occMat[][SPECIE][CLASSE][MAXMAT], int dim[][MAXDIM], int selezioneDimensione, int selezioneSchermata) {
  int dimensione;
  char charMaiuscDim[MAXCHAR] = "RIGHE";
  switch (selezioneDimensione) {
  case INXRG:
    dimensione = modificaValore(MODRG, occMat[NEUTRO][IN][NUM][MINMAT], dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG], DISUSO, DISUSO, "righe");
    break;
  default:
    strcpy(charMaiuscDim, "COLONNE");
    dimensione = modificaValore(MODCL, occMat[NEUTRO][IN][NUM][MINMAT], DISUSO, dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL], DISUSO, "colonne");
  }
  switch (dimensione) {
  case ANNULLA:
    return dim[occMat[NEUTRO][IN][NUM][MINMAT]][selezioneDimensione];
  default:
    notificaSingolaModificaGenerica(dim[occMat[NEUTRO][IN][NUM][MINMAT]][selezioneDimensione], dimensione, occMat[NEUTRO][IN][NUM][MINMAT] + 1, charMaiuscDim);
    return dimensione;
  }
}
void modificaManualeDimensioni(int occMat[][SPECIE][CLASSE][MAXMAT], int dim[][MAXDIM]) {
  int rg;
  int cl;
  rg = modificaValore(MODRG, occMat[NEUTRO][IN][NUM][MINMAT], dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG], DISUSO, DISUSO, "righe");

  if (rg != ANNULLA) {
    cl = modificaValore(MODCL, occMat[NEUTRO][IN][NUM][MINMAT], DISUSO, dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL], DISUSO, "colonne");
    if (cl != ANNULLA) {
      notificaDimensioniModificate(occMat[NEUTRO][IN][NUM][MINMAT], dim, rg, cl);
      dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG] = rg;
      dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL] = cl;
    }
  }
}
int caricaManualeValori(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL], int dim[][MAXDIM]) {
  int rg, cl;
  for (rg = 0; rg < dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXRG]; rg++) {
    for (cl = 0; cl < dim[occMat[NEUTRO][IN][NUM][MINMAT]][INXCL]; cl++) {
      mat[occMat[NEUTRO][IN][NUM][MINMAT]][rg][cl] = gestioneInserimentoSchermateRix(CARICA_MAN_VAL, rg, cl, "valore");

      if (mat[occMat[NEUTRO][IN][NUM][MINMAT]][rg][cl] == ANNULLA) return ANNULLA;
    }
  }
  return 1;
}
//identifica
void risultatoIdentificaMatrice(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  switch (identificaMatrice(mat, dim, inxMat)) {
  case SCALARE:
    printf("scalare");
    break;
  case MATNULL:
    printf("matrice nulla");
    break;
  case MATID:
    printf("matrice identita");
    break;
  case MATDIAG:
    printf("matrice diagonale");
    break;
  case MATTRGSUP:
    printf("triangolare superiore");
    break;
  case MATTRGINF:
    printf("triangolare inferiore");
    break;
  case MATQUAD:
    printf("matrice quadrata");
    break;
  case VETRG:
    printf("vettore riga");
    break;
  case VETCL:
    printf("vettore colonna");
    break;
  case MATGEN:
    printf("matrice qualsiasi");
  }
  printf("\n");
}
int identificaMatriceNulla(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  int riga, colonna;
  for (riga = 0; riga < dim[inxMat][0]; riga++) {
    for (colonna = 0; colonna < dim[inxMat][1]; colonna++) {
      if (mat[inxMat][riga][colonna] != 0) return ERRORE; //non
    }
  }
  return SCALARE; //nulla
}
int identificaMatriceDiagonale(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  int riga, colonna;
  for (riga = 0; riga < dim[inxMat][0]; riga++) {
    for (colonna = 0; colonna < dim[inxMat][1]; colonna++) {
      if (riga != colonna && mat[inxMat][riga][colonna] != 0) return ERRORE; // non
    }
  }
  return MATDIAG; //diagonale
}
int identificaMatriceIdentita(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  int i;
  for (i = 0; i < dim[inxMat][0]; i++) {
    if (mat[inxMat][i][i] != 1) return ERRORE; //non
  }
  return MATID; //unita
}
int identificaMatriceTriangolareInferiore(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  int colonna, riga;
  for (colonna = 1; colonna < dim[inxMat][0]; colonna++) {
    for (riga = 0; riga < colonna; riga++) {
      if (mat[inxMat][riga][colonna] != 0) return ERRORE; //non
    }
  }
  return MATTRGINF; //triangolare inferiore
}
int identificaMatriceTriangolareSuperiore(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  int riga, colonna;
  for (riga = 0; riga < dim[inxMat][0]; riga++) {
    for (colonna = 1 + riga; colonna < dim[inxMat][1]; colonna++) {
      if (mat[inxMat][riga][colonna] != 0) return ERRORE; //non
    }
  }
  return MATTRGSUP; //triangolare superiore
}
int identificaMatrice(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  if (dim[inxMat][INXRG] == dim[inxMat][INXCL]) {
    if (dim[inxMat][INXRG] == SCALARE) return SCALARE; //scalare
    else if (identificaMatriceNulla(mat, dim, inxMat) == MATNULL) return MATNULL; // matrice nulla
    else if (identificaMatriceDiagonale(mat, dim, inxMat) == MATDIAG) {
      if (identificaMatriceIdentita(mat, dim, inxMat) == MATID) return MATID; //matrice  di identita
      else return MATDIAG; //matrice diagonale
    } else if (identificaMatriceTriangolareInferiore(mat, dim, inxMat) == MATTRGINF) return MATTRGINF; //matrice triangolare inferiore
    else if (identificaMatriceTriangolareSuperiore(mat, dim, inxMat) == MATTRGSUP) return MATTRGSUP; //matrice triangolare superiore
    else return MATQUAD; //matrice quadrata
  } else if (dim[inxMat][INXRG] == MINRG) return VETRG; //vettore righe
  else if (dim[inxMat][INXCL] == MINCL) return VETCL; //vettore colonne
  else return MATGEN; //matrice qualsiasi
}
//inversa
int calcolaMatriceInversa(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int numMat){
    int i ,j,k,h,g = 0,f = 0, s = 0;
    float mat2[MAXRG][MAXCL];
    float mat3[MAXRG][MAXCL];
    float mat4[MAXRG][MAXCL];
    int rg,cl;
    float det = 0.0; //dichiarazione obligatoria in quanto risulta immpossibile eseguire il codice 'printf("%f = " 1 / calcolaLaplaceDeterminanteMatriceNxN(mat[inxMat], dim[inxMat][INXCL]));'
    for(i = 0;i < dim[inxMat][INXRG]; i ++){
        for(j = 0;j < dim[inxMat][INXCL]; j ++){
            mat4[i][j] = mat[inxMat][i][j];
        }
    }
    
    dim[numMat][INXRG] = dim[inxMat][INXRG];
    dim[numMat][INXCL] = dim[numMat][INXRG];
    //matrice cofattori
    for(i = 0;i < dim[inxMat][INXRG]; i ++){
        for(j = 0;j < dim[inxMat][INXCL]; j ++){
            g = 0;
            f = 0;
            //calcolo minore complementare
            for(k = 0;k < dim[inxMat][INXRG] - 1;k  ++){
                for(h = 0;h < dim[inxMat][INXCL] - 1; h ++){
                    do{
                        if ( g == i && f == j)s = 1;
                        else if( g == i || f == j)s = 1;
                        else {
                            mat2[k][h] = mat[inxMat][g][f];
                            s = 0;
                        }
                        f++;
                        if (f == dim[inxMat][INXCL]){
                            f = 0;
                            g++;
                        }
                        if(g == dim[inxMat][INXCL]){
                            s = 0;
                        }
                    }while(s != 0);
                }
            }
            mat[numMat][i][j] = pow(-1, i + j) * calcolaLaplaceDeterminanteMatriceNxN(mat2, dim[inxMat][INXCL] - 1);
        }
    }
    //matrice trasposta
    matriceTrasposta(mat[numMat], mat3, dim[numMat][INXRG], dim[numMat][INXCL], &rg, &cl);
    //matrice inversa
    det = calcolaLaplaceDeterminanteMatriceNxN(mat[inxMat], dim[inxMat][INXCL]);
    //moltiplicazione(mat, dim, numMat  + 1,det,numMat, SCAL);
    prodottoScalareMatrice(mat3, mat[numMat], det, rg, cl, &dim[numMat][INXRG], &dim[numMat][INXCL]);
    //fix di un bug sui valori del parametro della matrice
    for(i = 0;i < dim[inxMat][INXRG]; i ++){
        for(j = 0;j < dim[inxMat][INXCL]; j ++){
            mat[inxMat][i][j] = mat4[i][j];
        }
    }
    return 1;
}
//determinante
float calcolaLaplaceDeterminanteMatriceNxN(float matElemAlg[][MAXCL], int dim) {
  float det = 0.0;
  float matCompl[MAXRG][MAXCL];
  int i;
  int j = 0;
  int k;
  int colonne = 0;
  if (dim == 2) return matElemAlg[0][0] * matElemAlg[1][1] - matElemAlg[0][1] * matElemAlg[1][0];
  else {
    for (k = 0; k < dim; k++) {
      for (i = 1; i < dim; i++) {
        for (j = 0; j < dim; j++) {
          if (j < colonne) matCompl[i - 1][j] = matElemAlg[i][j];
          else if (j > colonne) matCompl[i - 1][j - 1] = matElemAlg[i][j];
        }
      }
      if (k % 2 == 1) matElemAlg[0][k] = -matElemAlg[0][k];
      det += calcolaLaplaceDeterminanteMatriceNxN(matCompl, dim - 1) * matElemAlg[0][k];
      colonne++;
    }
  }
  return det;
}
float gestioneCalcoloDeterminante(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat) {
  switch (dim[inxMat][MINRG]) {
  case 1:
    return mat[inxMat][0][0];
  case 2:
          return (mat[inxMat][0][0] * mat[inxMat][1][1]) - (mat[inxMat][0][1] * mat[inxMat][1][0]);
  case 3:
          return ((mat[inxMat][0][0] * mat[inxMat][1][1] * mat[inxMat][2][2]) + (mat[inxMat][0][1] * mat[inxMat][1][2] * mat[inxMat][2][0]) + (mat[inxMat][0][2] * mat[inxMat][1][0] * mat[inxMat][2][1])) - ((mat[inxMat][0][2] * mat[inxMat][1][1] * mat[inxMat][2][0]) + (mat[inxMat][0][1] * mat[inxMat][1][0] * mat[inxMat][2][2]) + (mat[inxMat][0][0] * mat[inxMat][1][2] * mat[inxMat][2][1]));
  default:
    return calcolaLaplaceDeterminanteMatriceNxN(mat[inxMat], dim[inxMat][INXRG]);
  }
}
//esegui operazione
int eseguiOperaSingolaMatricePlus(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL], int dim[][MAXDIM],int genere1, int genere2,char charMaiuscSchermataPrecedente[]){
    int selezione = 0;
selezione = gestioneInserimentoSchermateExt(occMat, dim, genere1, genere2, DELULTIMA, DISUSO, DISUSO, DISUSO, "scelta");
switch (selezione) {
case 1:
eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[genere2][MAX][INX][occMat[genere2][MAX][NUM][MINMAT] - 1], ELIMINA,genere2,MAX,ATTUALE);
  break;
case 0:
printf("\n\tritorno alla schermata %s\n", charMaiuscSchermataPrecedente);
break;
case ANNULLA:
printf("\n\tritorno alla schermata %s\n", charMaiuscSchermataPrecedente);
selezione = 0;
}
    return selezione;
}
int eseguiOperazioneIntervalloMatrici(float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat[], int numMat, int selezioneOperazione) {
  int inxMax = inxMat[numMat - 1];
  int inxMin = inxMat[0];
  int inx;
  char charMaiuscMat[MAXCHAR] = "OUTPUT";
  if (inxMat[0] < INXMINOUT) strcpy(charMaiuscMat, "INPUT");
  switch (selezioneOperazione) {
  case VISUALIZZA:
    for (inx = 0; inx < numMat; inx++) {
      printf("\n\t\tMATRICE.%d\n", inxMat[inx] + 1);
      visualizzaSingolaMatrice(mat, dim, inxMat[inx]);
      printf("\n");
    }
    return 0;
  case ELIMINA:
    printf("\n\ttutte le matrici %s eliminate con successo (%d)\n", charMaiuscMat, inxMax - (inxMax - numMat));
    for (inx = 0; inx < numMat; inx++) {
      eliminaSingolaMatrice(mat, dim, inxMat[inx], inxMin);
    }
    return numMat;
  case IDENTIFICA:
    for (inx = 0; inx < numMat; inx++) {
      printf("\n\t\t%d\t", inxMat[inx] + 1);
      risultatoIdentificaMatrice(mat, dim, inxMat[inx]);
    }
    return 0;
  case DETERMINANTE:
    for (inx = 0; inx < numMat; inx++) {
      printf("\n\t\t%d\tdeterminante = %3.2f\n", inxMat[inx] + 1, gestioneCalcoloDeterminante(mat, dim, inxMat[inx]));
    }
    return 0;
  default:
    return 0;
  }
}
void eseguiOperazioneSingolaMatrice(int occMat[][SPECIE][CLASSE][MAXMAT],float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int operazione, int genereSrg,int specie,int tipoSelezione) {

    if(operazione >= INXMINOPERALG && operazione <= INXMAXOPERALG )occMat[NEUTRO][OUT][NUM][MINMAT] += eseguiOperazioneSingolaMatriceExt(occMat, mat, dim, inxMat, operazione, specie, tipoSelezione);
    else occMat[genereSrg][specie][NUM][MINMAT] -= eseguiOperazioneSingolaMatriceRix(occMat,mat, dim, inxMat, operazione, tipoSelezione);
}
int eseguiOperazioneSingolaMatriceRix(int occMat[][SPECIE][CLASSE][MAXMAT],float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int operazione, int attualeOdScelta){
    char  charMaiuscMat[MAXCHAR] = "OUTPUT";
    char charMaiuscAttualeOdScelta[MAXCHAR] = "ATTUALE";
    if(attualeOdScelta == SCELTA)strcpy(charMaiuscMat,"SCELTA");
    if (inxMat < INXMINOUT)strcpy(charMaiuscMat,"INPUT");
    switch (operazione) {
    case VISUALIZZA:
      printf("\n\t\tMATRICE.%d\n", inxMat + 1);
      visualizzaSingolaMatrice(mat, dim, inxMat);
            return 0;
    case ELIMINA:
      printf("\n\tmatrice %s.%d eliminata con successo\n", charMaiuscMat, inxMat + 1);
     return eliminaSingolaMatrice(mat, dim, MAXMAT_TIPO, inxMat);
            break;
    case MODIFICA:
      modificaValoriMatrice(mat, dim, inxMat, charMaiuscAttualeOdScelta);
            return 0;
    case IDENTIFICA:
      printf("\n\t\tMATRICE %s.%d\n\t\t", charMaiuscMat, inxMat + 1);
      risultatoIdentificaMatrice(mat, dim, inxMat);
            return 0;
        case TRASPOSTA:
            printf("\n\t\tMATRICE.%d", occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]] + 1);
            printf("\n\t\tTRASPOSTA\n");
            occMat[NEUTRO][OUT][NUM][MINMAT] +=  matriceTrasposta(mat[inxMat],mat[occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]]],dim[inxMat][INXRG],dim[inxMat][INXCL],&dim[ occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]]][INXRG],&dim[ occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]]][INXCL]);
            visualizzaSingolaMatrice(mat, dim, occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]] - 1);
            return 0;
        case CALC_INVERSA:
            printf("\n\t\tMATRICE.%d", occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]] + 1);
            printf("\n\t\tINVERSA\n");
            
            occMat[NEUTRO][OUT][NUM][MINMAT] += calcolaMatriceInversa(mat, dim, inxMat, occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]]);
            visualizzaSingolaMatrice(mat, dim,occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]] - 1);
            return 0;
    case DETERMINANTE:
      printf("\n\t\tMATRICE %s.%d", charMaiuscMat, inxMat + 1);
      printf("\n\t\tdeterminante = %3.2f\n", gestioneCalcoloDeterminante(mat, dim, inxMat));
            return 0;
        default:
            return 0;
    }
}
int eseguiOperazioneSingolaMatriceExt(int occMat[][SPECIE][CLASSE][MAXMAT],float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int inxMat, int operazione,int specie,int tipoSelezione) {
    float valore = 0.0;
    int opera1;
    int opera2;
    int operarix;
    int genereRef;
    char charMaiuscAttualeOdScelta[MAXCHAR] = "SCELTA";
    char charMaiuscTermini[OPERALG][TERMINI][MAXCHAR];
    associaCharMaiuscTermini(charMaiuscTermini);
    if(tipoSelezione == ATTUALE)strcpy(charMaiuscAttualeOdScelta,"ATTUALE");
  char charMaiuscMat[MAXCHAR] = "OUTPUT";
  if (inxMat < INXMINOUT) strcpy(charMaiuscMat, "INPUT");
        if(operazione == SUMMAT || operazione == SUBMAT || operazione == PRODMAT)opera1 = MAT;
        else opera1 = SCAL;
        opera2 = associaOperaRix(operazione);
        if(operazione == PRODMAT)genereRef = MOLTPLTOR;
        else   genereRef = ADDENDO2;
        if(operazione == PRODSCAL || (tipoSelezione == ATTUALE && occMat[FREQ][ALL][STATO][MINMAT] != SOLO_UNA))printf("\n\tMATRICE.%d\n\t%s\n",inxMat + 1,charMaiuscTermini[opera2][TERMINE1]);
        switch(opera1){
            case MAT:
                aggiornaMatSmart(occMat,mat, dim, genereRef, genereRef, inxMat);
                valore = gestioneOperazioni(occMat, mat, dim, genereRef, operazione,inxMat, "");
                break;
            case SCAL:
                valore = gestioneInserimentoSchermateRix(TERMINE2,operazione,DISUSO,"valore");
        }

    if(valore == PLUS) valore = gestioneInserimentoSchermataIndice(occMat,mat, dim, genereRef, genereRef, operazione, TERMINE2, inxMat, ALL, "indice") - 1;
        switch((int)valore){
            case ANNULLA:
                return 0;
            case ANNULLA - 1:
                return 0;
            default:
                operarix = associaOperaRix(operazione);
                if(opera1 != SCAL){
                printf("\n\tMATRICE.%d",inxMat + 1);
                printf("\n\t%s\n",charMaiuscTermini[operarix][TERMINE1]);
                printf("\n\tMATRICE.%d",(int)valore + 1);
                printf("\n\t%s\n",charMaiuscTermini[operarix][TERMINE2]);
                }
                switch(opera2){
                    case SUM:
                        printf("\n\tMATRICE.%d\n\tSOMMA\n",occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]] + 1);
                        addizzione(mat, dim, inxMat, valore, occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]], SUM);
                        break;
                    case SUB:
                        printf("\n\tMATRICE.%d\n\tDIFFERENZA\n",occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]] + 1);
                         addizzione(mat, dim, inxMat, valore, occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]], SUB);
                        break;
                    case PROD:
                        printf("\n\tMATRICE.%d\n\tPRODOTTO\n",occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]] + 1);
                         moltiplicazione(mat, dim, inxMat, valore, occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]], opera1);
                        break;
                }
                visualizzaSingolaMatrice(mat, dim, occMat[NEUTRO][OUT][INX][occMat[NEUTRO][OUT][NUM][MINMAT]]);
        }
    return 1;
}
//altri algoritmi
void copiaVettori(int vetStampa[], int vetCopia[]) {
  int i;
  for (i = MINMAT; i < MAXMAT_TIPO; i++)
    vetCopia[i] = vetStampa[i];
}
void swapInt(int * a, int * b) {
  int c;
  c = * a;
  * a = * b;
  * b = c;
}
void scambiaVettori(int vet1[], int vet2[]) {
  int vet3[MAXMAT_TIPO];
  copiaVettori(vet1, vet3);
  copiaVettori(vet2, vet1);
  copiaVettori(vet3, vet2);
}
void bblCre(int vet[], int dim) {
  int i, j;
  for (i = 0; i < dim - 1; i++) {
    for (j = 0; j < dim - 1; j++) {
      if (vet[j] > vet[j + 1]) swapInt( & vet[j], & vet[j + 1]);
    }
  }
}
void swapStr(char str1[], char str2[]) {
  char str3[MAXCHAR];
  strcpy(str3, str1);
  strcpy(str1, str2);
  strcpy(str2, str3);
}
int associaOperaRix(int operazione){
    if(operazione == SUMMAT)return SUM;
    else if(operazione == PRODMAT  || operazione == PRODSCAL )return PROD;
    else if( operazione == SUBMAT) return SUB;
    else return NO_OPERALG;
}
//gestione operazioni

void gestioneOperazioniPlus(int occMat[][SPECIE][CLASSE][MAXMAT],float mat[][MAXRG][MAXCL], int dim[][MAXDIM],int selezione[MAXPICK], int schermata,int genere1,int genere2,int opera1, int opera2){
    do{
        selezione[PICKOPERA] =  gestioneInserimentoSchermateClean(schermata, "scelta");
        switch(selezione[PICKOPERA] ){
            case 1:
              gestioneOperazioni(occMat, mat, dim, genere1, opera1,DISUSO, "principale");

                break;
            case 2:
              gestioneOperazioni(occMat, mat, dim, genere2, opera2,DISUSO, "principale");
                
                }
        if(occMat[NEUTRO][OUT][NUM][MINMAT] == MAXMAT_TIPO)selezione[PICKOPERA]  = 0;
        if(schermata == PICK_SUM)selezione[PICKOPERA]  = 0;
    }while(selezione[PICKOPERA] != 0);
}
int gestioneOperazioni(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int genere, int operazione,int inxMat, char charMaiuscSchermataPrecedente[]) {
  int selezione = 0;
    int specie;
    int specie2 = IN;
    int modalita = 0;
    int modalita2;
    int cicli = 0;
    if(genere == MOLTPLTOR || genere == ADDENDO2 )modalita = PLUS;
    else if(operazione == PRODSCAL || operazione == PRODMAT  || operazione == SUMMAT || operazione == SUBMAT)modalita = EXT;
    int caratteristicaOperazione = EXE_ALLOUT;
    if((operazione >= INXMINOPERALG && operazione <= INXMAXOPERALG )|| (operazione == TRASPOSTA || operazione == CALC_INVERSA))caratteristicaOperazione = NOTEXE_ALLOUT;
    char charMaiuscFreq[TIPO][MAXCHAR];
  char charMaiuscOperazioni[OPERAZIONI][MAXCHAR];
    associaCharMaiuscOperazioni( charMaiuscOperazioni);
    associaMatFreq(occMat, genere);
    aggiornaCharMaiuscFreq(occMat, charMaiuscFreq);
  do {
    
      if(occMat[FREQ][MAX][INX][MINMAT] >= INXMINOUT)specie = MAX;
      else specie = MIN;
      if (((occMat[FREQ][MAX][NUM][MINMAT] + occMat[FREQ][MIN][NUM][MINMAT] == MAXMAT) || (occMat[NEUTRO][OUT][NUM][MINMAT] == MAXMAT_TIPO)) && (caratteristicaOperazione == NOTEXE_ALLOUT))selezione = 0;
      else{
          
          if( genere == INVERSA){
              aggiornaMatSmart(occMat, mat, dim, INVERSA, INVERSA, inxMat);
              associaMatFreq(occMat, INVERSA);
          }
          if(operazione == TRASPOSTA)associaMatFreq(occMat, NEUTRO);
          else associaMatFreq(occMat, FREQ);
          aggiornaCharMaiuscFreq(occMat, charMaiuscFreq);
          occMat[FREQ][ALL][NUM][MINMAT] = aggiornaStatoSmart(occMat, FREQ);
          switch (aggiornaStatoPlus(occMat[FREQ][MIN][STATO][MINMAT], occMat[FREQ][MAX][STATO][MINMAT]) ) {
              case NESSUNA:
                selezione = 0;
                break;
              case SOLO_UNA:
                //visualizza o elimina o identifica o modifica sola matrice piu frequente
                  if(modalita != PLUS && modalita != EXT && operazione != ELIMINA)printf("\n\t%s UNICA MATRICE.%d %s\n", charMaiuscOperazioni[operazione], occMat[FREQ][MAX][INX][MINMAT] + 1, charMaiuscFreq[MAX]);
                  if(modalita == PLUS)return occMat[FREQ][MAX][INX][occMat[FREQ][MAX][NUM][MINMAT] - 1];
                switch (operazione) {
                case ELIMINA:
                        switch(cicli){
                            case 0:
                                printf("\n\t%s UNICA MATRICE.%d %s\n", charMaiuscOperazioni[operazione], occMat[FREQ][MAX][INX][MINMAT] + 1, charMaiuscFreq[MAX]);
                                eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[FREQ][MAX][INX][occMat[FREQ][MAX][NUM][MINMAT] - 1], operazione,FREQ,MAX, ATTUALE);
                                break;
                            default:
                                if(occMat[FREQ][MAX][NUM][MINMAT] == MINMAT){
                                    swapInt(&occMat[FREQ][MAX][NUM][MINMAT], &occMat[FREQ][MIN][NUM][MINMAT]);
                                    scambiaVettori(occMat[FREQ][MAX][INX], occMat[FREQ][MIN][INX]);
                                }
                                selezione = eseguiOperaSingolaMatricePlus( occMat,  mat,  dim, genere,  FREQ,charMaiuscSchermataPrecedente);
                        }
                      
                  break;
                default:
                eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[FREQ][MAX][INX][occMat[FREQ][MAX][NUM][MINMAT] - 1], operazione,FREQ,MAX, ATTUALE);
                }
                break;
              case CON_UNA:
                  selezione = gestioneInserimentoSchermateExt(occMat, dim, genere, FREQ, operazione, DISUSO, DISUSO, DISUSO, "scelta");
                  aggiornaMatSmart(occMat,mat, dim, genere, FREQ, inxMat);
                  associaMatFreq(occMat, FREQ);
                switch (selezione) {
                case 0:
                  printf("\n\tritorno alla schermata %s\n", charMaiuscSchermataPrecedente);
                  break;
                case ANNULLA:
                  printf("\n\tritorno alla schermata %s\n", charMaiuscSchermataPrecedente);
                  selezione = 0;
                  break;
                case 1:
              
                        if(modalita != PLUS && modalita != EXT)printf("\n\t%s UNICA MATRICE.%d %s\n", charMaiuscOperazioni[operazione], occMat[FREQ][MIN][INX][MINMAT] + 1, charMaiuscFreq[MIN]);
                        if(modalita == PLUS)return occMat[FREQ][MIN][INX][occMat[FREQ][MIN][NUM][MINMAT] - 1];
                  eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[FREQ][MIN][INX][occMat[FREQ][MIN][NUM][MINMAT] - 1], operazione,FREQ,MIN, ATTUALE);
                  break;
                case 2:
                  modalita2 =  operazioneMatriceDiUnTipo(occMat, mat, dim, genere,MAX, operazione,inxMat, charMaiuscSchermataPrecedente);
                        if(modalita == PLUS)return modalita2;
                  break;
                case 3:
                        if (gestioneOperazioneAll(occMat, mat, dim, modalita, CON_UNA, genere, operazione, inxMat, specie2)  == PLUS)return PLUS;
                  break;
                }
                break;
              case UNA_PER:
                  selezione = gestioneInserimentoSchermateExt(occMat, dim, genere, FREQ, operazione, DISUSO, DISUSO, DISUSO, "scelta");
                  aggiornaMatSmart(occMat,mat, dim, genere, FREQ, inxMat);
                  associaMatFreq(occMat, FREQ);
                  aggiornaCharMaiuscFreq(occMat, charMaiuscFreq);
                switch (selezione) {
                case 0:
                  printf("\n\tritorno alla schermata  %s\n", charMaiuscSchermataPrecedente);
                  break;
                case ANNULLA:
                  printf("\n\tritorno alla schermata  %s\n", charMaiuscSchermataPrecedente);
                  selezione = 0;
                  break;
                case 1:
               
                        if(modalita != PLUS && modalita != EXT)printf("\n\t%s UNICA MATRICE.%d %s\n", charMaiuscOperazioni[operazione],occMat[FREQ][MIN][INX][MINMAT] + 1, charMaiuscFreq[MIN]);
                        if(modalita == PLUS)return occMat[FREQ][MIN][INX][occMat[FREQ][MIN][NUM][MINMAT] - 1];
                  eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[FREQ][MIN][INX][occMat[FREQ][MIN][NUM][MINMAT] - 1], operazione,FREQ,MIN, ATTUALE);
                  break;
                case 2:
               
                        if(modalita != PLUS && modalita != EXT)printf("\n\t%s UNICA MATRICE.%d %s\n", charMaiuscOperazioni[operazione], occMat[FREQ][MAX][INX][MINMAT] + 1,charMaiuscFreq[MAX]);
                        if(modalita == PLUS)return occMat[FREQ][MAX][INX][occMat[FREQ][MAX][NUM][MINMAT] - 1];
                  eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[FREQ][MAX][INX][occMat[FREQ][MAX][NUM][MINMAT] - 1], operazione,FREQ,MAX, ATTUALE);
                  break;
                case 3:
                        if (gestioneOperazioneAll(occMat, mat, dim, modalita, UNA_PER, genere, operazione, inxMat, specie2)  == PLUS)return PLUS;
                  break;
                }
                break;
              case UN_TIPO:

               modalita2 =  operazioneMatriceDiUnTipo(occMat, mat, dim,genere, MAX, operazione,inxMat, charMaiuscSchermataPrecedente);
                  if(modalita == PLUS)return modalita2;
                  if(operazione == TRASPOSTA || genere == INVERSA ){
                  if (modalita2 == ANNULLA   && ( occMat[NEUTRO][OUT][NUM][MINMAT] == MINMAT || occMat[NEUTRO][IN][NUM][MINMAT] == MINMAT))selezione = 0;
                  else selezione = CONTINUA;
                  }else selezione = 0;
                  
                break;
              default:
                  selezione = gestioneInserimentoSchermateExt(occMat, dim, genere, FREQ, operazione, DISUSO, DISUSO, DISUSO, "scelta");
                switch (selezione) {
                case 0:
                  printf("\n\tritorno alla schermata  %s\n", charMaiuscSchermataPrecedente);
                  break;
                case ANNULLA:
                  printf("\n\tritorno alla schermata  %s\n", charMaiuscSchermataPrecedente);
                  selezione = 0;
                  break;
                case 1:
                  modalita2 = operazioneMatriceDiUnTipo(occMat, mat, dim, genere,MIN, operazione,inxMat, charMaiuscSchermataPrecedente);
                        if(modalita == PLUS)return modalita2;
                  break;
                case 2:
                  modalita2 = operazioneMatriceDiUnTipo(occMat, mat, dim,genere, MAX, operazione,inxMat, charMaiuscSchermataPrecedente);
                        if(modalita == PLUS)return modalita2;
                  break;
                case 3:
                        if (gestioneOperazioneAll(occMat, mat, dim, modalita, ALCUNE, genere, operazione, inxMat, specie2)  == PLUS)return PLUS;
                  break;
                }
              }
      }
      
      if(operazione == ELIMINA)associaMatNeutro(occMat,FREQ,NEUTRO);
    
      if(modalita == PLUS || modalita == EXT )selezione = 0;
      cicli++;
  } while (selezione != 0);
    return ANNULLA;
}
int gestioneOperazioneAll(int occMat[][SPECIE][CLASSE][MAXMAT],float mat[][MAXRG][MAXCL],int dim[][MAXDIM],int modalita, int modalita2, int genere, int operazione,int inxMat, int specie2){
    char charMaiuscFreq[TIPO][MAXCHAR];
   char charMaiuscOperazioni[OPERAZIONI][MAXCHAR];
    int inxMatScelta;
    associaCharMaiuscOperazioni( charMaiuscOperazioni);
    associaMatFreq(occMat, genere);
    aggiornaCharMaiuscFreq(occMat, charMaiuscFreq);
    switch(modalita){
        case PLUS:
            return PLUS;
        case EXT:
            inxMatScelta = gestioneInserimentoSchermataIndice(occMat,mat, dim, genere, genere, operazione, TERMINE1, DISUSO, ALL, "indice");
      switch (inxMatScelta) {
      case ANNULLA:
        break;
      default:
              if (inxMatScelta >= INXMINOUT){
                  inxMatScelta -= INXMINOUT;
                  specie2 = OUT;
              }
        eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[genere][specie2][INX][inxMatScelta - 1], operazione,genere,specie2, SCELTA);
    }
    break;
    default:
            switch(modalita2){
                case UNA_PER:
                    printf("\n\t%s TUTTE LE MATRICI\n", charMaiuscOperazioni[operazione]);
                    printf("\n\t----MATRICI %s\n", charMaiuscFreq[MIN]);
                    eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[FREQ][MIN][INX][occMat[FREQ][MIN][NUM][MINMAT] - 1], operazione,FREQ,MIN, ATTUALE);
                    printf("\n\t----MATRICI %s\n", charMaiuscFreq[MAX]);
                    eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[FREQ][MAX][INX][occMat[FREQ][MAX][NUM][MINMAT] - 1], operazione,FREQ,MAX, ATTUALE);
                    break;
                case CON_UNA:
                    printf("\n\t%s TUTTE LE MATRICI\n", charMaiuscOperazioni[operazione]);
                    printf("\n\t----MATRICI %s\n", charMaiuscFreq[MIN]);
                    eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[FREQ][MIN][INX][occMat[FREQ][MIN][NUM][MINMAT] - 1], operazione,FREQ,MIN, ATTUALE);
                    printf("\n\t----MATRICI %s\n", charMaiuscFreq[MAX]);
                    occMat[FREQ][MAX][NUM][MINMAT] -= eseguiOperazioneIntervalloMatrici(mat, dim, occMat[FREQ][MAX][INX], occMat[FREQ][MAX][NUM][MINMAT], operazione);
                    break;
                default:
                    printf("\n\t%s TUTTE LE MATRICI\n", charMaiuscOperazioni[operazione]);
                    printf("\n\t----MATRICI %s\n", charMaiuscFreq[MIN]);
                    occMat[FREQ][MIN][NUM][MINMAT] -= eseguiOperazioneIntervalloMatrici(mat, dim, occMat[FREQ][MIN][INX], occMat[FREQ][MIN][NUM][MINMAT], operazione);
                    printf("\n\t----MATRICI %s\n", charMaiuscFreq[MAX]);
                    occMat[FREQ][MAX][NUM][MINMAT] -= eseguiOperazioneIntervalloMatrici(mat, dim, occMat[FREQ][MAX][INX], occMat[FREQ][MAX][NUM][MINMAT], operazione);
            }
            }
    return ANNULLA;
}
int operazioneMatriceDiUnTipo(int occMat[][SPECIE][CLASSE][MAXMAT], float mat[][MAXRG][MAXCL], int dim[][MAXDIM], int genere,int specie, int selezioneOperazione,int inxMat, char charMaiuscSchermataPrecedente[]) {
  int selezione = 0;
  int inxMatScelta = 0;
  int app = occMat[FREQ][MAX][NUM][MINMAT];
  int tipo = OUT;
    int modalita = RIX;
    int termine = TERMINE1;
  int caratteristicaOperazione = EXE_ALLOUT;
  char charMaiuscOperazioni[OPERAZIONI][MAXCHAR];
  char charMaiuscMat[MAXCHAR] = "OUTPUT";
  associaCharMaiuscOperazioni( charMaiuscOperazioni);
  if (occMat[FREQ][specie][INX][MINMAT] < INXMINOUT) tipo = IN;
    if(genere == MOLTPLTOR || genere == ADDENDO2 ){
        modalita = PLUS;
        termine = TERMINE2;
    }
    else if(selezioneOperazione == PRODSCAL || selezioneOperazione == PRODMAT  || selezioneOperazione == SUMMAT || selezioneOperazione == SUBMAT)modalita = EXT;
  if( (selezioneOperazione >= INXMINOPERALG && selezioneOperazione <= INXMAXOPERALG) || (selezioneOperazione == TRASPOSTA|| selezioneOperazione == CALC_INVERSA) )caratteristicaOperazione = NOTEXE_ALLOUT;
  occMat[APP][MIN][NUM][MINMAT] = 0;
  occMat[APP][MAX][NUM][MINMAT] = occMat[FREQ][specie][NUM][MINMAT];
  copiaVettori(occMat[FREQ][specie][INX], occMat[APP][MAX][INX]);
  copiaVettori(occMat[FREQ][MAX][INX], occMat[APP][MIN][INX]);
  if (specie != MIN) {
    scambiaVettori(occMat[APP][MAX][INX], occMat[APP][MIN][INX]);
    app = occMat[FREQ][MIN][NUM][MINMAT];
  }
  if (occMat[APP][MAX][INX][MINMAT] < INXMINOUT) strcpy(charMaiuscMat, "INPUT");
  do {
     if(selezioneOperazione == TRASPOSTA && specie == IN){
         copiaVettori(occMat[NEUTRO][OUT][INX], occMat[APP][MAX][INX]);
         occMat[APP][MAX][NUM][MINMAT] = occMat[NEUTRO][OUT][NUM][MINMAT];
     }
      selezione = gestioneInserimentoSchermateExt(occMat, dim, genere, APP, selezioneOperazione, DISUSO, DISUSO, inxMat, "scelta");
     
    switch (selezione) {
    case 0:
      printf("\n\tritorno alla schermata %s\n", charMaiuscSchermataPrecedente);
      break;
    case ANNULLA:
      printf("\n\tritorno alla schermata %s\n", charMaiuscSchermataPrecedente);
      selezione = 0;
      break;
    case 1:
      if(modalita != PLUS && modalita != EXT)printf("\n\t%s MATRICE %s SCELTA\n", charMaiuscOperazioni[selezioneOperazione], charMaiuscMat);
            inxMatScelta = gestioneInserimentoSchermataIndice(occMat, mat,dim, genere, APP, selezioneOperazione, termine, inxMat, MAX, "indice");
            if(modalita == PLUS){
                associaFreqDaApp(occMat,specie, app,tipo );
                return inxMatScelta - 1;
            }
      switch (inxMatScelta) {
      case ANNULLA:
        break;
      default:
        if (inxMatScelta >= INXMINOUT) inxMatScelta -= INXMINOUT;
        eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[APP][MAX][INX][inxMatScelta - 1], selezioneOperazione,APP,MAX, SCELTA);
      }
      break;
    case 2:
            if(modalita != PLUS && modalita != EXT) printf("\n\t%s MATRICE.%d %s ATTUALE\n", charMaiuscOperazioni[selezioneOperazione],occMat[APP][MAX][INX][occMat[APP][MAX][NUM][MINMAT] - 1] + 1, charMaiuscMat);
            if(modalita == PLUS){
                associaFreqDaApp(occMat,specie, app,tipo );
                return occMat[APP][MAX][INX][occMat[APP][MAX][NUM][MINMAT] - 1];
            }
     eseguiOperazioneSingolaMatrice(occMat,mat, dim, occMat[APP][MAX][INX][occMat[APP][MAX][NUM][MINMAT] - 1], selezioneOperazione,APP,MAX, ATTUALE);
      break;
    case 3:
     if(modalita == PLUS){
         associaFreqDaApp(occMat,specie, app,tipo );
         return PLUS;
     }
            if(modalita != PLUS && modalita != EXT) printf("\n\t%s TUTTE MATRICI %s\n", charMaiuscOperazioni[selezioneOperazione], charMaiuscMat);
      occMat[APP][MAX][NUM][MINMAT] -= eseguiOperazioneIntervalloMatrici(mat, dim, occMat[APP][MAX][INX], occMat[APP][MAX][NUM][MINMAT], selezioneOperazione);
      break;
    }
      if(selezioneOperazione == ELIMINA && occMat[APP][MAX][NUM][MINMAT] == SOLO_UNA && app == 0 ){
          eseguiOperaSingolaMatricePlus( occMat,  mat,  dim, genere,  APP,charMaiuscSchermataPrecedente);
          selezione = 0;
      }
      if(occMat[NEUTRO][IN][NUM][MINMAT] +  occMat[NEUTRO][OUT][NUM][MINMAT] == MAXMAT)selezione = ANNULLA;
      if (occMat[APP][MAX][NUM][MINMAT] <= SOLO_UNA) selezione = ANNULLA;
      if(occMat[NEUTRO][OUT][NUM][MINMAT] == MAXMAT_TIPO && caratteristicaOperazione == NOTEXE_ALLOUT)
          selezione = ANNULLA;
      if(genere == MOLTPLTOR || genere == ADDENDO2 )modalita = PLUS;
      if(modalita == PLUS || modalita == EXT )selezione = 0;
  } while (selezione != 0 && selezione != ANNULLA);
    associaFreqDaApp(occMat,specie, app,tipo );
    return ANNULLA;
}
void associaFreqDaApp(int occMat[][SPECIE][CLASSE][MAXMAT],int specie,int app, int tipo ){
    copiaVettori(occMat[NEUTRO][IN][INX], occMat[FREQ][MIN][INX]);
    copiaVettori(occMat[NEUTRO][OUT][INX], occMat[FREQ][MAX][INX]);
    occMat[FREQ][specie][NUM][MINMAT] = occMat[APP][MAX][NUM][MINMAT];
    if (specie == MIN) {
      if (tipo == OUT) scambiaVettori(occMat[FREQ][MAX][INX], occMat[FREQ][MIN][INX]);
      occMat[FREQ][MAX][NUM][MINMAT] = app;
    } else {
      if (tipo == IN) scambiaVettori(occMat[FREQ][MAX][INX], occMat[FREQ][MIN][INX]);
      occMat[FREQ][MIN][NUM][MINMAT] = app;
    }
}
//gestione caratteri
void associaCharMaiuscTermini(char charMaiuscTermini[OPERALG][TERMINI][MAXCHAR]){
    strcpy(charMaiuscTermini[PROD][TERMINE1], "MOLTIPLICANDO");
    strcpy(charMaiuscTermini[PROD][TERMINE2], "MOLTIPLICATORE");
    strcpy(charMaiuscTermini[SUM][TERMINE1], "ADDENDO 1 ");
    strcpy(charMaiuscTermini[SUM][TERMINE2], "ADDENDO 2");
    strcpy(charMaiuscTermini[SUB][TERMINE1], "MINUENDO");
    strcpy(charMaiuscTermini[SUB][TERMINE2], "SOTTRAENDO");
    strcpy(charMaiuscTermini[NO_OPERALG][TERMINE1]," ");
    strcpy(charMaiuscTermini[NO_OPERALG][TERMINE2]," ");
}
void associaCharMaiuscOperazioni(char charMaiuscOperazione[OPERAZIONI][MAXCHAR]){
    strcpy(charMaiuscOperazione[CALC_INVERSA], "CALCOLA INVERSA");
    strcpy(charMaiuscOperazione[VISUALIZZA], "VISUALIZZA");
    strcpy(charMaiuscOperazione[TRASPOSTA], "TRASPOSIZZIONE");
    strcpy(charMaiuscOperazione[ELIMINA], "ELIMINA");
    strcpy(charMaiuscOperazione[DETERMINANTE], "DETERMINANTE");
    strcpy(charMaiuscOperazione[IDENTIFICA], "IDENTIFICA");
    strcpy(charMaiuscOperazione[MODIFICA], "MODIFICA");
    strcpy(charMaiuscOperazione[SUMMAT], "SOMMA MATRICE - ");
    strcpy(charMaiuscOperazione[SUBMAT], "SOTTRAI MATRICE - ");
    strcpy(charMaiuscOperazione[PRODSCAL], "MOLTIPLICA SCALARE - ");
    strcpy(charMaiuscOperazione[PRODMAT], "MOLTIPLICA MATRICE - ");
}
void aggiornaCharMaiuscFreq(int occMat[][SPECIE][CLASSE][MAXMAT], char charMaiuscFreq[][MAXCHAR]) {
  strcpy(charMaiuscFreq[MAX], "OUTPUT");
  strcpy(charMaiuscFreq[MIN], "INPUT");
  if (occMat[FREQ][MAX][INX][MINMAT] < INXMINOUT) swapStr(charMaiuscFreq[MAX], charMaiuscFreq[MIN]);
}


