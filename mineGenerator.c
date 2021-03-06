#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int fila;
	int col;
} Mines;

void fflushnou () {
    char buffer[20];   
    fgets (buffer,20,stdin);
}

int dentroLimites(int r, int c, int filas, int columnas) {
	return r >= 0 && c >= 0 && r < filas && c < columnas;
}

void addNumberMines (char **taulell, int r, int c, int mine, int fil, int col) {
	int i = 0;
	if (dentroLimites (r-1, c-1, fil, col) && taulell[r-1][c-1] != 'M')
		taulell[r-1][c-1] = (int)taulell[r-1][c-1] + 1;
	
	if (dentroLimites (r+1, c+1, fil, col) && taulell[r+1][c+1] != 'M')
		taulell[r+1][c+1] = (int)taulell[r+1][c+1] + 1;
	
	if (dentroLimites (r+1, c-1, fil, col) && taulell[r+1][c-1] != 'M')
		taulell[r+1][c-1] = (int)taulell[r+1][c-1] + 1;

	if (dentroLimites (r-1, c+1, fil, col) && taulell[r-1][c+1] != 'M') 
		taulell[r-1][c+1] = (int)taulell[r-1][c+1] + 1;
	
	if (dentroLimites (r, c-1, fil, col) && taulell[r][c-1] != 'M') 
		taulell[r][c-1] = (int)taulell[r][c-1] + 1;
	
	if (dentroLimites (r, c+1, fil, col) && taulell[r][c+1] != 'M')
		taulell[r][c+1] = (int)taulell[r][c+1] + 1;
	
	if (dentroLimites (r+1, c, fil, col) && taulell[r+1][c] != 'M')
		taulell[r+1][c] = (int)taulell[r+1][c] + 1;

	if (dentroLimites (r-1, c, fil, col) && taulell[r-1][c] != 'M')
		taulell[r-1][c] = (int)taulell[r-1][c] + 1;
}

int existeMine (Mines *m, int r, int c, int num_mines) {
	int i;
	for (i = 0; i < num_mines; i++) {
		if (m[i].fila == r && m[i].col == c)
			return 1;
	}
	return 0;
}

int main () {
	FILE *f;
	int rows, col, mines;
	int i, j, r ,c ;
	char filename[50];
	char **taulell;
	char opcion;
	int mine;
	Mines *m;

	srand(time(NULL));

	do {
		mine = 0;
		printf ("Rows? ");
		scanf ("%d", &rows);
		printf ("Columns? ");
		scanf ("%d", &col);
		do {
			printf ("Number of mines? ");
			scanf ("%d", &mines);
			if (mines >= rows * col)
				printf ("Too many mines.\n");
		} while (mines >= rows * col);
		m = (Mines*)malloc(sizeof(Mines) * mines);
		for (i = 0; i < mines; i++) {
			m[i].fila = 0;
			m[i].col = 0;
		}
		printf ("Filename? ");
		fflushnou ();
		gets(filename);

		// Guardem memoria per al taulell
		taulell = (char**)malloc(sizeof(char*) * rows);
		for (i = 0; i < rows; i++) {
			taulell[i] = (char*)malloc(sizeof(char) * col+1);
			for (j = 0; j < col; j++)
				taulell[i][j] = '0';
		}

		// generamos random casillas para poner minas
		for (i = 0; i < mines; i++) {
			do {
				r = (i + rand()) % rows;
				c = (i + rand()) % col;
			} while (existeMine(m, r, c, mines));

			taulell[r][c] = 'M';
			addNumberMines(taulell, r, c, mine++, rows, col);
			m[i].fila = r;
			m[i].col = c;
		}

		for (i = 0; i < rows; i++) 
			taulell[i][col] = '\0';

		f = fopen (filename, "w");
		if (!f)
			printf ("Cannot create file.\n");
		else {
			fprintf (f, "C:%d\n", col);
			fprintf (f, "F:%d\n", rows);
			fprintf (f, "M:%d\n", mines);
			for (i = 0; i < rows; i++)
				fprintf (f, "%s\n", taulell[i]);
			fclose (f);
		}

		printf ("Do you want to continue generating? (Y/N)\n");
		scanf ("%c", &opcion);
	} while (opcion != 'N' && opcion != 'n');
	return 0;
}