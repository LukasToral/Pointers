#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Deklarace funkcí
void vypisPole(int pole[], int velikostPole);
void pocetKladnychZapornych(int pole[], int velikostPole, int *pocKladnych, int *pocZapornych);

int main() {
	//Vytvoøení promìnné file
	FILE *file;
	//Zadání cesty txt souboru, se kterym budu praovat + "w", protoze do nej budu psat
	file = fopen("C:\\Users\\student\\Documents\\Toral\\text.txt", "w");
	//Vytvoreni dvou poli pro zapsani kladnych a zapornych hodnot
	int *kladnePole, *zapornePole;
	//Vytvoreni promennych pro registraci kladnych a zapornych cisel ve funkci pocetKladnychZapornych
	int pocKladnych, pocZapornych;
	srand(time(NULL));
	//Vytvoreni pole cisel
	int *poleCisel;
	//Pocet cisel v poliCisel
	int pocetCisel;
	//Nacteni poctu cisel
	scanf("%d", &pocetCisel);
	//Urceni velikosti pole
	poleCisel = (int*)malloc(sizeof(int) * pocetCisel);
	//Pomocna promenna pro praci s cykly
	int i;
	
	//Naplneni pole
	for (i = 0; i < pocetCisel; i++) {
		//Nacitani pseudonahodnych cisel v intervalu <-50;50>
		poleCisel[i] = rand()%101-50;
		//Pri vygenerovani cisla, automaticky probehne zapis cisla do souboru s jeho prislusnym poradim
		fprintf (file, "%d. cislo: %d\n",i + 1, poleCisel[i]);
	}
	//Zavreni souboru - uz s nim nebudeme pracovat
	fclose (file);
	
	//Volani funkce k urceni kladnych a zapornych cisel
	//Zadavam adresu promennych, ktere jsem si vytvoril drive, protože na jejich adresu nyni budu ukladat hodnoty, ktere zjistim v funkci nize.
	pocetKladnychZapornych(poleCisel, pocetCisel, &pocKladnych, &pocZapornych);
	
	//Vypis poleCisel pomoci funkce
	vypisPole(poleCisel, pocetCisel);
	
	//Prideleni pameti a urceni velikosti poli pro kladne a zaporne cisla
	kladnePole = (int*)malloc(sizeof(int) * pocKladnych);
	zapornePole = (int*)malloc(sizeof(int) * pocZapornych);
	
	int pocetKladnych, pocetZapornych;
	//Dvì pomocné promìnné, aby se hodnoty do polí ukladaly na spravne misto
	pocetKladnych = 0; 
	pocetZapornych = 0;
	//Cyklus pro roztrizeni cisel
	for (i = 0; i < pocetCisel; i++) {
		if (poleCisel[i] < 0) {
			zapornePole[pocetZapornych] = poleCisel[i];
			//Po zapsani do pole se pocet zapornych siel zvedne, aby pri pristim zapsani byla cisla na spravnem miste v poli
			pocetZapornych++;
	 } else {
			kladnePole[pocetKladnych] = poleCisel[i];
			pocetKladnych++;
		}
	}
	
	//Vypsani kladneho a zaporneho pole
	printf("KLADNE POLE\n");
	for (i = 0; i < pocetKladnych; i++) {
		printf("%d\n", kladnePole[i]);
	}
	printf("ZAPORNE POLE\n");
	for (i = 0; i < pocetZapornych; i++) {
		printf("%d\n", zapornePole[i]);
	}	
	
	return 0;
}

//Funkce pro vypis pole
void vypisPole(int pole[], int velikostPole) {
	int i;
	for (i = 0; i < velikostPole; i++) {
		printf("%d\n", pole[i]);
	}
}

/**Funkce pro urceni postu kladnych a zapornych cisel v poli
   Funkce "vraci" dve hodnoty pomoci pointeru. V mainu jsem si vytvoril dve obycejne promenne a na jejich adresu nyni ukazuji pointery z teto funkce ->
   pozdeji muzu pomoci obycejnych promennych ziskat hodnoty z teto funkce.
**/
void pocetKladnychZapornych(int pole[], int velikostPole, int *pocKladnych, int *pocZapornych) {
	int i;
	//Pointery ukazujici na obycejne promenne v mainu
	*pocKladnych = 0;
	*pocZapornych = 0;
	//Zjisteni kladnych a zapornych hodnot a zvetsovani promennych pomoci pointeru.
	for (i = 0; i < velikostPole; i++) {
		(pole[i] < 0)? *pocZapornych++:*pocKladnych++;
	}
}
