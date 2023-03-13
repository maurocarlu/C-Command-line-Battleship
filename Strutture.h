
#ifndef STRUTTURE_H_
#define STRUTTURE_H_

#define NumNavi 15 //numero di navi in gioco

typedef struct{	//Tabella usata dal giocatore per attaccare il campo avversario – record
   int celle[16][16];	//griglia della tabella al cui interno vi sono i numeri che indicano le condizioni del campo avversario – matrice di interi
   int ContNavi; //contatore che indica il numero di navi ancora in gioco dell’avversario – intero - >0 e 15<=
   int righe;	//numero di righe della tabella – intero - 16
   int colonne; //numero di righe della tabella – intero - 16
}BattleFieldAtt;

typedef struct{  //numero di abilita' a disposizione di ogni giocatore-Record
	int ColpoALargoRaggio;	//indica il numero di utilizzi disponibili di colpi a largo raggio, partendo da 3 per ogni giocatore-intero- >=0 e <=3
	int BombardamentoAereo; //indica il numero di utilizzi disponibili di bombardamento aereo, ne si ha solo 1 a disposizione per ciascuno-intero- >=0 e <=1
	int Radar;	//indica il numero di utilizzi disponibili di radar, partendo da 3 per ogni giocatore-intero- >=0 e <=3
}Abilita;

typedef struct{    //Tabella usata dal giocatore per il proprio campo di gioco – record
   int celle[16][16];  //griglia della tabella al cui interno vi sono i numeri che indicano le posizioni delle proprie navi – matrice di interi
   int righe; // numero di righe della tabella – intero - 16
   int colonne; // numero di colonne della tabella – intero - 16
}BattleFieldPos;


//DEFINIZIONE FUNZIONI

BattleFieldPos InizializzaTabPos(BattleFieldPos TabellaPos);//funzione usata per inizializzare un oggetto di tipo BattlefieldPos

BattleFieldAtt InizializzaTabAtt(BattleFieldAtt TabellaAtt);//funzione usata per inizializzare un oggetto di tipo BattlefieldAtt

BattleFieldAtt DecrementaNavi(BattleFieldAtt TabellaAtt);//funzione usata per decrementare il valore del campo contnavi di un oggetto di tipo BattlefieldAtt

int LeggereCellaAtt(BattleFieldAtt TabellaAtt, int riga, int colonna); //funzione usata per leggere una cella del campo celle di un oggetto di tipo BattlefieldAtt

int LeggereRigheAtt(BattleFieldAtt TabellaAtt); //funzione usata per leggere il numero di righe di un oggetto di tipo BattlefieldAtt

int LeggereColonneAtt(BattleFieldAtt TabellaAtt); //funzione usata per leggere il numero di colonne di un oggetto di tipo BattlefieldAtt

BattleFieldAtt ScrivereRigheAtt(BattleFieldAtt TabellaAtt, int righe); //funzione usata per modificare il numero di righe di un oggetto di tipo BattlefieldAtt

BattleFieldAtt ScrivereColonneAtt(BattleFieldAtt TabellaAtt, int colonne); //funzione usata per modificare il campo colonne di un oggetto di tibo BattlefieldAtt

BattleFieldAtt ScrivereCellaAtt(BattleFieldAtt TabellaAtt, int riga, int colonna, int valore); //funzione usata per scrivere una cella del campo celle di un oggetto di tipo BattlefieldAtt

int LeggereContNavi(BattleFieldAtt TabellaAtt); //funzione usata per leggere il campo contnavi di un oggetto di tipo BattlefieldAtt

BattleFieldAtt ScriviContNavi(BattleFieldAtt TabellaAtt, int ContNavi); //funzione usata per modificare il campo contnavi di un oggetto di tipo BattlefieldAtt

int LeggereCellaPos(BattleFieldPos TabellaPos, int riga, int colonna); //funzione usata per leggere una cella del campo celle di un oggetto di tipo BattlefieldPos

int LeggereRighePos(BattleFieldPos TabellaPos); //funzione usata per leggere il numero di righe di un oggetto di tipo BattlefieldPos

int LeggereColonnePos(BattleFieldPos TabellaPos); //funzione usata per leggere il numero di colonne di un oggetto di tipo BattlefieldPos

BattleFieldPos ScrivereRighePos(BattleFieldPos TabellaPos, int righe); //funzione usata per modificare il numero di righe di un oggetto di tipo BattlefieldPos

BattleFieldPos ScrivereColonnePos(BattleFieldPos TabellaPos, int colonne); //funzione usata per modificare il numero di colonne di un oggetto di tipo BattlefieldPos

BattleFieldPos ScrivereCellaPos(BattleFieldPos TabellaPos, int riga, int colonna, int valore); //funzione usata per modificare il campo celle di un oggetto di tipo battlefieldAtt

int LeggereColpoALargoRaggio(Abilita Colpo); //funzione usata per leggere il numero rimanente di colpi a largo raggio

Abilita ScrivereColpoALargoRaggio(Abilita ab, int ColpoALargoRaggio); //funzione usata per modificare il numero di colpi a largo raggio

int LeggereBombardamentoAereo(Abilita ab); //funzione usata per leggere il numero di bombardamenti aerei rimanenenti

Abilita ScrivereBombardamentoAereo(Abilita ab, int BombardamentoAereo); //funzione usata per modificare il numero di bombardamenti aerei rimanenti

int LeggereRadar(Abilita ab); //funzione usata per leggere il numero di radar rimanenti

Abilita ScrivereRadar(Abilita ab, int Radar); //funzione usata per modificare il numero di radar rimanenti

Abilita DecrementaColpoALargoRaggio(Abilita ab); //funzione usata per decrementare di 1 il numero di colpi a largo raggio

Abilita DecrementaBombardamentoAereo(Abilita ab); //funzione usata per decrementare di 1 il numero di bombardamento aereo

Abilita DecrementaRadar(Abilita ab); //funzione usata per decrementare di 1 il numero di radar

#endif /* STRUTTURE_H_ */
