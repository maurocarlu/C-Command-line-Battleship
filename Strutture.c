#include "Strutture.h"


BattleFieldAtt DecrementaNavi(BattleFieldAtt TabellaAtt)
{
	TabellaAtt.ContNavi=(TabellaAtt.ContNavi)-1;
	return TabellaAtt;
}

BattleFieldPos InizializzaTabPos(BattleFieldPos TabellaPos){
	int i=0; //utilizzata per scorrere le righe di TabellaPos >=0 e 15<=
	int j; //utilizzata per scorrere le colonne di TabellaPos >=0 e 15<=
	while(i<LeggereRighePos(TabellaPos)){
		j=0;
		while(j<LeggereColonnePos(TabellaPos)){
			TabellaPos=ScrivereCellaPos(TabellaPos, i, j, 0);
			j++;
		}
		i++;
	}
	return TabellaPos;
}

int LeggereCellaAtt(BattleFieldAtt TabellaAtt, int riga, int colonna)
{
	int valore; //valore della cella richiesta – intero - Può valere 0 - 1 - 2 - 3
	valore=TabellaAtt.celle[riga][colonna];
	return valore;
}

int LeggereRigheAtt(BattleFieldAtt TabellaAtt)
{
	int righe=TabellaAtt.righe;
	return righe;
}

int LeggereColonneAtt(BattleFieldAtt TabellaAtt)
{
	int colonne=TabellaAtt.colonne;
	return colonne;
}

BattleFieldAtt ScrivereRigheAtt(BattleFieldAtt TabellaAtt, int righe)
{
	TabellaAtt.righe=righe;
	return TabellaAtt;
}

BattleFieldAtt ScrivereColonneAtt(BattleFieldAtt TabellaAtt, int colonne)
{
	TabellaAtt.colonne=colonne;
	return TabellaAtt;
}

BattleFieldAtt ScrivereCellaAtt(BattleFieldAtt TabellaAtt, int riga, int colonna, int valore)
{
	TabellaAtt.celle[riga][colonna]=valore;
	return TabellaAtt;
}

int LeggereContNavi(BattleFieldAtt TabellaAtt)
{
	int ContNavi; //numero di navi rimaste all'avversario - intero - >=0 e <=15
	ContNavi=TabellaAtt.ContNavi;
	return ContNavi;
}

BattleFieldAtt ScriviContNavi(BattleFieldAtt TabellaAtt, int ContNavi)
{
	TabellaAtt.ContNavi=ContNavi;
	return TabellaAtt;
}


int LeggereCellaPos(BattleFieldPos TabellaPos, int riga, int colonna)
{
	int valore; //valore della cella richiesta – intero - Può valere 0 - 1
	valore=TabellaPos.celle[riga][colonna];
	return valore;

}

int LeggereRighePos(BattleFieldPos TabellaPos)
{
	int righe; //numero di righe della tabella pos - intero -
	righe=TabellaPos.righe;
	return righe;
}

int LeggereColonnePos(BattleFieldPos TabellaPos)
{
	int colonne; //numero di colonne della tabela pos - intero
	colonne=TabellaPos.colonne;
	return colonne;
}

BattleFieldPos ScrivereRighePos(BattleFieldPos TabellaPos, int righe)
{
	TabellaPos.righe=righe;
	return TabellaPos;
}

BattleFieldPos ScrivereColonnePos(BattleFieldPos TabellaPos, int colonne)
{
	TabellaPos.colonne=colonne;
	return TabellaPos;
}

BattleFieldPos ScrivereCellaPos(BattleFieldPos TabellaPos, int riga, int colonna, int valore)
{
	TabellaPos.celle[riga][colonna]=valore;
	return TabellaPos;
}

int LeggereColpoALargoRaggio(Abilita Colpo)
{
	int valore; //numero di colpi a largo raggio rimasti - intero - >=0 e 3<=
	valore=Colpo.ColpoALargoRaggio;
	return valore;
}

Abilita ScrivereColpoALargoRaggio(Abilita ab, int ColpoALargoRaggio)

{
	ab.ColpoALargoRaggio=ColpoALargoRaggio;
	return ab;
}

int LeggereBombardamentoAereo(Abilita ab)
{
	int valore; //numero di bombardamenti aerei rimasti - intero - >=0 e 1<=
	valore=ab.BombardamentoAereo;
	return valore;
}

Abilita ScrivereBombardamentoAereo(Abilita ab, int BombardamentoAereo)

{
	ab.BombardamentoAereo=BombardamentoAereo;
	return ab;
}

int LeggereRadar(Abilita ab)
{
	int valore; //numero di radar rimasti - intero - >=0 e 3<=
	valore=ab.Radar;
	return valore;
}

Abilita ScrivereRadar(Abilita ab, int Radar)

{
	ab.Radar=Radar;
	return ab;
}

Abilita DecrementaColpoALargoRaggio(Abilita ab)

{
	ab.ColpoALargoRaggio=(ab.ColpoALargoRaggio)-1;
	return ab;
}

Abilita DecrementaBombardamentoAereo(Abilita ab)

{
	ab.BombardamentoAereo=(ab.BombardamentoAereo)-1;
	return ab;
}

Abilita DecrementaRadar(Abilita ab)

{
	ab.Radar=(ab.Radar)-1;
	return ab;
}
BattleFieldAtt InizializzaTabAtt(BattleFieldAtt TabellaAtt){
	int i=0; //intero usato per scorrere le righe - intero - >=0 e 16<
	int j; //intero usato per scorrere le colonne - intero - >=0 e 16<
	while(i<LeggereRigheAtt(TabellaAtt)){
		j=0;
		while(j<LeggereColonneAtt(TabellaAtt)){
			TabellaAtt=ScrivereCellaAtt(TabellaAtt, i, j, 0);
			j++;
		}
		i++;
	}

	return TabellaAtt;
}
