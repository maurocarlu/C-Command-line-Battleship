#include "OutputASchermo.h"
#include "OperazioniDiGioco.h"
#include <stdio.h>
#include <stdlib.h>
#include "Strutture.h"

void MostraMenu(int sceltaMenu){
	if(sceltaMenu==1){				//se sceltaMenu è 1 stampa il menu principale
		printf("\n");
		printf("Premi 1 per iniziare una nuova partita\n"
				"Premi 2 per caricare una partita\n"
				"Premi 3 per mostrare le regole di gioco\n"
				"Premi 4 per uscire dal gioco\n");
	}
	if(sceltaMenu==2){	//se sceltaMenu è 2 stampa il menu degli attacchi
		printf("\n");
		printf( "1) Attacco\n"
				"2) Colpo a largo raggio\n"
				"3) Bombardamento aereo\n"
				"4) Radar\n"
				"5) Salva partita\n"
				"6) Esci dalla partita (Il salvataggio non e' automatico)\n"
		);
	}if(sceltaMenu==3){	//se sceltaMenu è 3 stampa il menu dei versi
		printf("Scegli il verso in cui posizionare la nave: \n"
				"1)verso l alto\n"
				"2)verso il basso\n"
				"3)verso destra\n"
				"4)verso sinistra \n"
								);
	}
	if(sceltaMenu==4){ //se sceltaMenu è 4 stampa il menu del caricamento
		printf("Nome della partita inesistente, vuoi riprovare?\n"
				"1 = Si\n"
				"2 = No\n");
	}
	if(sceltaMenu==5){ //se sceltaMenu è 5 stampa il menu del bombardamento aereo
		printf("Premi 1 per colpire una riga\n"
		"Premi 2 per colpire una colonna\n");
	}

}

void MostraRegole(){
    FILE *fp; //puntatore al file - puntatore
    char app[255]; //array di caratteri utilizzato per leggere dal file - array di caratteri

    //Tentativo di apertura del file
    if((fp=fopen("regole.txt", "r"))!=NULL){
    while(!feof(fp)){
            fgets (app, 254, fp);
            printf("%s",app);
    }
    }else{
        printf("Errore nell'apertura del file delle regole\n");
    }
    fclose(fp);
}

void MenuInserimento(int Navi1, int Navi2, int Navi3, int Navi4, int Navi5){
	printf("1)Inserisci nave di lunghezza 1,rimanenti: %d/5\n",Navi1);
	printf("2)Inserisci nave di lunghezza 2,rimanenti: %d/4\n",Navi2);
	printf("3)Inserisci nave di lunghezza 3,rimanenti: %d/3\n",Navi3);
	printf("4)Inserisci nave di lunghezza 4,rimanenti: %d/2\n",Navi4);
	printf("5)Inserisci nave di lunghezza 5,rimanenti: %d/1\n",Navi5);
}

void StampaGrigliaAttacco(BattleFieldAtt TabellaAtt){
	int colonna=0; //contatore usato per stampare il numero di colonna - intero - >=0 e 15<=
	int riga=1; //contatore usato per stampare il numero di riga - intero - >=1 e 16<=
	int i=0; //contatore che indica la colonna per la stampa - intero - >=0 e 15<=
	int valore=0; //valore letto nella cella indicata di tabellaAtt - intero - Può valere 0-1-2-3
	printf("   ");

	//stampa dei caratteri da A a P per indicare le colonne
	while(colonna<LeggereColonneAtt(TabellaAtt)){
		printf("%c",TraduzioneColonnaInversa(colonna));
		colonna++;
	}
	printf("\n");
	//stampa dei numeri da 1 a 10 per indicare le righe
	while(riga<=LeggereRigheAtt(TabellaAtt)){
		i=0;
		//se riga ha una cifra aggiunge uno spazio nella stampa
		if(riga<10){
			printf("%d  ",riga);
		}else{
			printf("%d ",riga);
		}
		//Legge tutti i valori di una riga
		while(i<LeggereColonneAtt(TabellaAtt)){
			valore=LeggereCellaAtt(TabellaAtt,riga-1,i);
			printf("%d",valore);
			i++;
		}
		printf("\n");
		riga++;
	}
}

void StampaGrigliaPosizione(BattleFieldPos TabellaPos){
	int colonna=0; //contatore usato per stampare il numero di colonna - intero - >=0 e 15<=
	int riga=1; //contatore usato per stampare il numero di riga - intero - >=1 e 16<=
	int i=0; //contatore che indica la colonna per la stampa - intero - >=0 e 15<=
	int valore=0; //valore letto nella cella indicata di tabellapos - intero - Può valere 0-1-2-3
	printf("   ");

	//stampa dei caratteri da A a P per indicare le colonne
	while(colonna<LeggereColonnePos(TabellaPos)){
		printf("%c",TraduzioneColonnaInversa(colonna));
		colonna++;
	}
	printf("\n");
	//stampa dei numeri da 1 a 10 per indicare le righe
	while(riga<=LeggereRighePos(TabellaPos)){
		i=0;
		//se riga ha una cifra aggiunge uno spazio nella stampa
		if(riga<10){
			printf("%d  ",riga);
		}else{
			printf("%d ",riga);
		}
		//Legge tutti i valori di una riga
		while(i<LeggereColonnePos(TabellaPos)){
			valore=LeggereCellaPos(TabellaPos,riga-1,i);
			printf("%d",valore);
			i++;
		}
		printf("\n");
		riga++;
	}
}




