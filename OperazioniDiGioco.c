#include "OperazioniDiGioco.h"
#include "Strutture.h"
#include "OutputASchermo.h"
#include "Attacchi.h"
#include <stdio.h>
#include <stdlib.h>
#include "SalvaECarica.h"


void IniziaPartita (char NomePartita[], char NomePlayer1[], char NomePlayer2[], BattleFieldPos TabellaPos1, BattleFieldPos TabellaPos2, BattleFieldAtt TabellaAtt1, BattleFieldAtt TabellaAtt2, Abilita ab1, Abilita ab2, int Turno){
	//Inizializzazione delle strutture di gioco
	TabellaAtt1=ScriviContNavi(TabellaAtt1,NumNavi);
	TabellaAtt2=ScriviContNavi(TabellaAtt2,NumNavi);
	ab1=ScrivereRadar(ab1, 3);
	ab1=ScrivereColpoALargoRaggio(ab1, 3);
	ab1=ScrivereBombardamentoAereo(ab1, 1);
	ab2=ScrivereRadar(ab2, 3);
	ab2=ScrivereColpoALargoRaggio(ab2, 3);
	ab2=ScrivereBombardamentoAereo(ab2, 1);
	TabellaPos1=InizializzaTabPos(TabellaPos1);
	TabellaPos2=InizializzaTabPos(TabellaPos2);
	TabellaAtt1=InizializzaTabAtt(TabellaAtt1);
	TabellaAtt2=InizializzaTabAtt(TabellaAtt2);

	//Inserimento nome della partita e dei giocatori
	printf("Inserire nome della partita \n");
	scanf("%s", NomePartita);
	printf("\n");
	printf("Giocatore 1 inserisci il tuo nome \n");
	scanf("%s", NomePlayer1);
	printf("\n");
	printf("Giocatore 2 inserisci il tuo nome \n");
	scanf("%s", NomePlayer2);
	printf("\n");
	TabellaPos1=InserisciNavi(TabellaPos1, NomePlayer1);
	TabellaPos2=InserisciNavi(TabellaPos2, NomePlayer2);
	//Avvio gioco
	Gioca(NomePlayer1,NomePlayer2,NomePartita,TabellaPos1,TabellaPos2,TabellaAtt1,TabellaAtt2, ab1, ab2,Turno);

}

void Gioca(char NomePlayer1[],char NomePlayer2[], char NomePartita[], BattleFieldPos TabellaPos1,BattleFieldPos TabellaPos2, BattleFieldAtt TabellaAtt1,BattleFieldAtt TabellaAtt2, Abilita ab1, Abilita ab2,int Turno){
	int SceltaAttacco=0; //intero usato dall'utente per scegliere quale opzione scegliere - intero - Può valere 1-2-3-4-5-6
	int esito; //intero che indica se il salvataggio è avvenuto con successo oppure no - intero - 0 o 1
	do
	{
		do
		{

			printf("TURNO: %d\n\n", (Turno+1)/2); //(Turno+1)/2 per avere il numero del turno corretto
			//Se il turno è dispari tocca al giocatore 1
			if(Turno%2!=0)
			{
				printf("E' IL TUO TURNO, %s\n\n", NomePlayer1);
				StampaGrigliaAttacco(TabellaAtt1);
			}
			//Se il turno è pari tocca al giocatore 2
			else
			{
				printf("E' IL TUO TURNO, %s\n",NomePlayer2);
				StampaGrigliaAttacco(TabellaAtt2);
			}
			MostraMenu(2);
			printf("Inserisci un numero tra 1 e 6 per scegliere quale operazione eseguire\n");
			//scelta dell'operazione da eseguire
			SceltaAttacco=LeggereIntero();
			//se la scelta è 5 (salvataggio) salva e non uscire dal while in modo da poter scegliere un attacco
			if(SceltaAttacco == 5)
			{
				esito=SalvaPartita(NomePlayer1, NomePlayer2, TabellaPos1, TabellaPos2, TabellaAtt1, TabellaAtt2,ab1,ab2, NomePartita, Turno);
				if(esito==1){
					printf("Partita salvata\n");
				}
			}
		}while(SceltaAttacco!=1 && SceltaAttacco!=2 && SceltaAttacco!=3 && SceltaAttacco!=4 && SceltaAttacco!=6); //fino a quando la scelta non è un attacco oppure l'uscita dal programma

		//Se scelta è Attacco
		if(SceltaAttacco == 1){
			//Se il turno è dispari tocca al giocatore 1 e attacca normalmente
			if(Turno%2 != 0){
				TabellaAtt1=Attacco(TabellaAtt1, TabellaPos2);
				Turno++;
			//Se il turno è pari tocca al giocatore 2 e attacca normalmente
			}else if (Turno%2 == 0){
				TabellaAtt2=Attacco(TabellaAtt2, TabellaPos1);
				Turno++;
			}
		}
		//Se scelta è Colpo a Largo Raggio
		if(SceltaAttacco == 2){
			//Se il turno è dispari tocca al giocatore 1
			if(Turno%2 != 0){
				//se il giocatore 1 non ha finito i colpi a largo raggio, lo usa e decrementa la quantità
				if(LeggereColpoALargoRaggio(ab1)>0){
					TabellaAtt1=ColpoALargoRaggio(TabellaAtt1, TabellaPos2);
					ab1=DecrementaColpoALargoRaggio(ab1);
					Turno++;
				}
				//Se non ha colpi a largo raggio seleziona un altro attacco
				else{
					printf("Hai terminato i colpi a largo raggio, seleziona un altro attacco\n");
				}

			//Se il turno è pari tocca al giocatore 2
			}else if(Turno%2 == 0){
				//se il giocatore 2 non ha finito i colpi a largo raggio, lo usa e decrementa la quantità
				if(LeggereColpoALargoRaggio(ab2)>0)
				  {
					TabellaAtt2=ColpoALargoRaggio(TabellaAtt2, TabellaPos1);
					ab2=DecrementaColpoALargoRaggio(ab2);
					Turno++;
				  }
				//Se non ha colpi a largo raggio seleziona un altro attacco
				else{
					printf("Hai terminato i colpi a largo raggio, seleziona un altro attacco\n");
				}
			}
		}
		//Se scelta è bombardamento aereo
		if(SceltaAttacco == 3){
			//Se si è superato il turno 10 ((20+1)/2=10) puoi usare il bombardamento aereo
			if(Turno>=19){
				//Se il turno è dispari tocca al giocatore 1
				if(Turno%2 != 0){
					//se il giocatore 1 non ha finito i bombardamenti aerei, lo usa e decrementa la quantità
					if(LeggereBombardamentoAereo(ab1) > 0){
						TabellaAtt1 = BombardamentoAereo(TabellaAtt1, TabellaPos2);
						ab1=DecrementaBombardamentoAereo(ab1);
						Turno++;
					//Se non ha bombardamenti aerei seleziona un altro attacco
					}else{
						printf("Hai terminato gli utilizzi per il bombardamento aereo\n");
					}
				//Se il turno è pari tocca al giocatore 2
				}else if (Turno%2 == 0){
					//se il giocatore 2 non ha finito i bombardamenti aerei, lo usa e decrementa la quantità
					 if(LeggereBombardamentoAereo(ab2) > 0){
						TabellaAtt2=BombardamentoAereo(TabellaAtt2, TabellaPos1);
						ab2=DecrementaBombardamentoAereo(ab2);
						Turno++;
						//Se non ha bombardamenti aerei seleziona un altro attacco
					 }else{
						 printf("Hai terminato gli utilizzi per il bombardamento aereo\n");
					 }
				}
			//Se non è stato superato il turno 10
			}else{
				printf("Potrai usare questo attacco solo dopo il decimo turno\n");
			}
		}

		//Se scelta è radar
		if(SceltaAttacco == 4){
			//Se il turno è dispari tocca al giocatore 1
			if(Turno%2 != 0){
				//se il giocatore 1 non ha finito i radar, lo usa e decrementa la quantità
				if(LeggereRadar(ab1) > 0){
					TabellaAtt1=Radar(TabellaAtt1, TabellaPos2);
					ab1=DecrementaRadar(ab1);
					Turno++;
					//Se non ha radar seleziona un altro attacco
				}else{
					printf("Hai terminato gli utilizzi per il radar\n");
				}
			//Se il turno è pari tocca al giocatore 2
			}else if(Turno%2 == 0 ){
				//se il giocatore 2 non ha finito i radar, lo usa e decrementa la quantità
				if(LeggereRadar(ab2) > 0){
					TabellaAtt2=Radar(TabellaAtt2, TabellaPos1);
					ab2=DecrementaRadar(ab2);
					Turno++;
				//Se non ha radar seleziona un altro attacco
				}else{
					printf("Hai terminato gli utilizzi per il radar\n");
				}
			}
		 }

	}while(LeggereContNavi(TabellaAtt1) != 0 && LeggereContNavi(TabellaAtt2) != 0 && SceltaAttacco != 6); //finchè uno dei giocatori ha affondato tutte le navi o scelgono di uscire dal gioco
	//Se il giocatore 1 ha affondato tutte le navi nemiche
	if(LeggereContNavi(TabellaAtt1) == 0){
		printf("Hai vinto! %s\n", NomePlayer1);
	//Se il giocatore 1 ha affondato tutte le navi nemiche
	}else if (LeggereContNavi(TabellaAtt2) == 0){
		printf("Hai vinto! %s\n", NomePlayer2);
	}
}

int TraduzioneColonna(char Lettera){
	int numero; //numero ottenuto dalla traduzione dal carattere della colonna all'intero corrispondente - intero - >=0 e 15<=

	if(Lettera == 'A'){
		numero=0;
	}
	else if (Lettera == 'B'){
		numero=1;
	}
	else if (Lettera == 'C'){
		numero=2;
		}
	else if (Lettera == 'D'){
		numero=3;
		}
	else if (Lettera == 'E'){
		numero=4;
		}
	else if (Lettera == 'F'){
		numero=5;
		}
	else if (Lettera == 'G'){
		numero=6;
		}
	else if (Lettera == 'H'){
		numero=7;
		}
	else if (Lettera == 'I'){
		numero=8;
		}
	else if (Lettera == 'J'){
		numero=9;
		}
	else if (Lettera == 'K'){
		numero=10;
		}
	else if (Lettera == 'L'){
		numero=11;
		}
	else if (Lettera == 'M'){
		numero=12;
		}
	else if (Lettera == 'N'){
		numero=13;
		}
	else if (Lettera == 'O'){
		numero=14;
		}
	else if (Lettera == 'P'){
		numero=15;
		}
	else {
		numero = -1;
	}

	return numero;
}



char TraduzioneColonnaInversa(int numero){
	char carattere; //carattere ottenuto dalla traduzione dal numero della colonna al carattere corrispondente - carattere

	if (numero == 0){
		carattere = 'A';
	}
	else if (numero == 1){
		carattere = 'B';
	}
	else if (numero == 2){
			carattere = 'C';
		}
	else if (numero == 3){
			carattere = 'D';
		}
	else if (numero == 4){
			carattere = 'E';
		}
	else if (numero == 5){
			carattere = 'F';
		}
	else if (numero == 6){
			carattere = 'G';
		}
	else if (numero == 7){
			carattere = 'H';
		}
	else if (numero == 8){
			carattere = 'I';
		}
	else if (numero == 9){
			carattere = 'J';
		}
	else if (numero == 10){
			carattere = 'K';
		}
	else if (numero == 11){
			carattere = 'L';
		}
	else if (numero == 12){
			carattere = 'M';
		}
	else if (numero == 13){
			carattere = 'N';
		}
	else if (numero == 14){
			carattere = 'O';
		}
	else if (numero == 15){
			carattere = 'P';
		}
	return carattere;
}

int LeggereIntero(){
	int valore; //valore letto da tastiera - intero
	scanf("%d", &valore);
	printf("\n");
	fflush(stdin);	//fa parte della libreria stdio.h e serve a svuotare il buffer di input/output

	return valore;
}


BattleFieldPos InserisciNavi (BattleFieldPos TabellaPos, char NomePlayer[]){
	int z=1; //intero usato per spostarsi lungo le celle durante l'inserimento - intero - >=0
	int flag=1; //flag usato per indicare se l'inserimento è possibile oppure no - intero - 0 o 1
	int navi1= 5; //numero di navi di dimensione 1 - intero
	int navi2= 4; //numero di navi di dimensione 2 - intero
	int navi3= 3; //numero di navi di dimensione 3 - intero
	int navi4= 2; //numero di navi di dimensione 4 - intero
	int navi5= 1; //numero di navi di dimensione 5 - intero
	int scelta;	//intero usato per scegliere quale nave inserire - intero - Può valere 1-2-3-4-5
	char carattere; //carattere usato per indicare in quale colonna si vuole inserire la nave - carattere
	int riga; //intero che indica in quale riga si vuole inserire la nave - intero - >=0 e 15<=
	int colonna; //intero che indica in quale colonna si vuole inserire la nave - intero - >=0 e 15<=
	int SceltaVerso; //intero usato per indicare in quale verso inserire le navi di dimensione maggiore di 1 - intero - Può valere 1-2-3-4
	int i=0; //intero usato per il ciclo di spazi per dividere le due tabelle al termine dell'inserimento - intero

	//Ciclo di inserimento di tutte le navi
	printf("Inserisci le navi %s\n", NomePlayer);
	do{
		//Scelta di quale tipo di nave inserire
		do{
			MenuInserimento(navi1, navi2, navi3, navi4, navi5);
			StampaGrigliaPosizione(TabellaPos);
			printf("Inserisci un numero per decidere \n");
			scelta=LeggereIntero();
			//Se si sceglie dimensione 1 e le navi di quel tipo sono finite
			if(scelta == 1 && navi1 == 0){
				printf("Hai inserito il numero massimo di navi di questo tipo, scegli un altro tipo \n");
				scelta=0;
			}
			//Se si sceglie dimensione 2 e le navi di quel tipo sono finite
			else if(scelta == 2 && navi2 == 0){
				printf("Hai inserito il numero massimo di navi di questo tipo, scegli un altro tipo \n");
				scelta=0;
			}
			//Se si sceglie dimensione 3 e le navi di quel tipo sono finite
			else if (scelta == 3 && navi3 == 0){
				printf("Hai inserito il numero massimo di navi di questo tipo, scegli un altro tipo \n");
				scelta=0;
			}
			//Se si sceglie dimensione 4 e le navi di quel tipo sono finite
			else if (scelta == 4 && navi4 == 0){
				printf("Hai inserito il numero massimo di navi di questo tipo, scegli un altro tipo \n");
				scelta=0;
			}
			//Se si sceglie dimensione 5 e le navi di quel tipo sono finite
			else if (scelta == 5 && navi5 == 0){
				printf("Hai inserito il numero massimo di navi di questo tipo, scegli un altro tipo \n");
				scelta=0;
			}

		}while(scelta <=0 || scelta > 5); //fino a quando non si inserisce una scelta corretta

		//Scelta della cella di partenza in cui inserire la nave
		do{
			//inserimento della riga di partenza in cui inserire la nave
			do{
				printf("Inserisci un numero (tra 1 e 16) per indicare in quale riga inserire la nave: ");
				riga = LeggereIntero();
			}while(riga<1 || riga>16);	//fino a quando non si inserisce una riga corretta
			riga=riga-1;
			//inserimento della colonna di partenza in cui inserire la nave
			do{
				printf("Inserisci una lettera in maiuscolo (tra A e P) per indicare in quale colonna inserire la nave: ");
				scanf("%c", &carattere);
				printf("\n");
				fflush(stdin);
				colonna=TraduzioneColonna(carattere);

			}while(colonna == -1); //fino a quando non si inserisce una colonna corretta

			//Se nella cella scelta vi è già una nave
			if(LeggereCellaPos(TabellaPos, riga, colonna) == 1){
				printf("Cella gia' occupata \n");
			}
			//Se vi è una nave adiacente alla cella scelta
			if(ControlloAdiacente(TabellaPos, riga, colonna) == 0){
				printf("Ci sono navi adiacenti\n");
			}

		}while(LeggereCellaPos(TabellaPos, riga, colonna) == 1 || ControlloAdiacente(TabellaPos, riga, colonna) == 0); //fino a quando non si sceglie una cella in cui è possibile inserire la nave

		//Se scelta è 1 allora inserisci la nave
		if(scelta == 1){
			navi1=navi1 - 1;
			printf("Nave inserita correttamente \n");
			TabellaPos= ScrivereCellaPos(TabellaPos, riga, colonna, 1);

		//Se non si è scelta una nave di dimensione 1 allora si sceglie il verso in cui inserire la nave e si effettuano
		//i controlli di adiacenza per le celle che si vogliono occupare
		}else{
			//scelta del verso in cui inserire la nave
			do{
				MostraMenu(3);
				SceltaVerso= LeggereIntero();
			}while (SceltaVerso<1 || SceltaVerso>4);	//fino a quando non si inserisce un verso corretto
			//Se si vuole inserire verso l'alto
			if(SceltaVerso == 1){

				//Se verso l'alto c'è un numero di celle minore alla dimensione della nave non si può inserire
				if(riga-(scelta-1) < 0){ //scelta -1 perchè il punto iniziale è già stato controllato
					flag=0;
				}
				//controlla un numero di celle pari alla dimensione della nave -1 nel verso indicato, per verificare se vi navi adiacenti o le celle sono occupate

				while(z<scelta && flag == 1){//fino a quando sono state controllate un numero di celle pari alla dimensione della nave -1(punto di partenza) e non sono state trovate celle occupate o navi adiacenti

					//Controlla se nella cella controllata vi è già una nave oppure vi sono navi adiacenti
					if(LeggereCellaPos(TabellaPos, riga-(z), colonna) !=0 || ControlloAdiacente(TabellaPos, riga-(z), colonna) == 0){
						flag=0;
					}
					z++;
				};
				//Se l'inserimento è possibile
				if(flag == 1){
					z=0;
					//inserisco una parte di nave in tutte le celle controllate precedentemente
					do{

						TabellaPos=ScrivereCellaPos(TabellaPos, riga, colonna, 1);
						riga--;
						z++;

					}while(z<scelta); //fino a quando non sono state inserite tutti i pezzi
				}
			}
			//se si vuole inserire verso il basso
			if(SceltaVerso == 2){
				//Se verso il basso c'è un numero di celle minore alla dimensione della nave non si può inserire
				if(riga+(scelta-1) >= 16){
					flag=0;
				}
				//controlla un numero di celle pari alla dimensione della nave -1 nel verso indicato, per verificare se vi navi adiacenti o le celle sono occupate
				while(z<scelta && flag == 1){ //fino a quando sono state controllate un numero di celle pari alla dimensione della nave -1(punto di partenza) e non sono state trovate celle occupate o navi adiacenti

					//Controlla se nella cella controllata vi è già una nave oppure vi sono navi adiacenti
					if(LeggereCellaPos(TabellaPos, riga+(z), colonna) != 0 || ControlloAdiacente(TabellaPos, riga+(z), colonna) == 0){
						flag=0;
					}
					z++;
				};
				//Se è possibile posizionare la nave
				if(flag == 1){
					z=0;
					//inserisco una parte di nave in tutte le celle controllate precedentemente
					do{

						TabellaPos=ScrivereCellaPos(TabellaPos, riga, colonna, 1);
						riga++;
						z++;

					}while(z<scelta);	//fino a quando non sono state inserite tutte le parti
				};
			}

			//Se si vuole inserire verso destra
			if(SceltaVerso == 3){

				//Se verso destra c'è un numero di celle minore alla dimensione della nave non si può inserire
				if(colonna+(scelta-1) >= 16){
					flag=0;
				}

				//controlla un numero di celle pari alla dimensione della nave -1 nel verso indicato, per verificare se vi navi adiacenti o le celle sono occupate
				while(z<scelta && flag == 1){ //fino a quando sono state controllate un numero di celle pari alla dimensione della nave -1(punto di partenza) e non sono state trovate celle occupate o navi adiacenti

					//Controlla se nella cella controllata vi è già una nave oppure vi sono navi adiacenti
					if(LeggereCellaPos(TabellaPos, riga, colonna+(z)) !=0 || ControlloAdiacente(TabellaPos, riga, colonna+(z)) == 0){
						flag=0;
					}
					z++;
				};
				//Se è possibile inserire la nave
				if(flag == 1){
					z=0;
					//Posiziono una parte di nave in tutte le celle controllate precedentemente
					do{

						TabellaPos=ScrivereCellaPos(TabellaPos, riga, colonna, 1);
						colonna++;
						z++;

					}while(z<scelta); //fino a quando non sono state inserite tutte le parti di nave
				}
			}

			//Se si sceglie di inserire verso sinistra
			if(SceltaVerso == 4){

				//Se verso sinistra c'è un numero di celle minore alla dimensione della nave non si può inserire
				if(colonna-(scelta-1)<0){
					flag=0;
				}

				//controlla un numero di celle pari alla dimensione della nave -1 nel verso indicato, per verificare se vi navi adiacenti o le celle sono occupate
				while(z<scelta && flag == 1){ //fino a quando sono state controllate un numero di celle pari alla dimensione della nave -1(punto di partenza) e non sono state trovate celle occupate o navi adiacenti

					//Controlla se nella cella controllata vi è già una nave oppure vi sono navi adiacenti
					if(LeggereCellaPos(TabellaPos, riga, colonna-(z)) != 0 || ControlloAdiacente(TabellaPos, riga, colonna-(z)) == 0){
						flag=0;
					}
					z++;
				};
				//Se l'inserimento è possibile
				if(flag == 1){
					z=0;
					//Posiziono una parte di nave in tutte le celle controllate precedentemente
					do{

						TabellaPos=ScrivereCellaPos(TabellaPos, riga, colonna, 1);
						colonna--;
						z++;

					}while(z<scelta); //fino a quando non sono state inserite tutte le parti
				}

			}
			//Se la nave è stata inserita correttamente modifico il contatore relativo alle navi della dimensione scelta inizialmente
			if(flag==1){

				printf("Nave inserita correttamente \n");
				//se dimensione 2
				if(scelta==2){
					navi2--;
				//se dimensione 3
				}else if(scelta==3){
					navi3--;
				//se dimensione 4
				}else if(scelta==4){
					navi4--;
				//se dimensione 5
				}else if(scelta==5){
					navi5--;
				}
			//Se non è possibile posizionare la nave
			}else{
				printf("Non puoi posizionare la nave in questo modo \n");
			}
			//reimposto le variabili utilizzate nel ciclo al valore iniziale
			z=1;
			flag=1;
			scelta=0;
		}

	}while(navi1 != 0 || navi2 != 0 || navi3 != 0 || navi4 != 0 || navi5 != 0); //fino a quando non sono state inserite tutte le navi

	//Vengono creati degli spazi tra le tabelle dei due giocatori
	do{
	printf("\n");
	i++;
	}while(i<100);
	return TabellaPos;
}



