#include <iostream>
#include "HSmanagement.h"

using namespace HSmanagement;

long int scores[HSmanagement::size];
string names[HSmanagement::size];

void showTable(){
	for (int i = 0; i < HSmanagement::size; i++)
	{
		cout << "Name: " << names[i] << " score: " << scores[i] << endl;
	}
}

void addScore(){
	string nameInput;
	long int scoreInput;

	cout << "Ingrese el nombre del jugador: "; cin >> nameInput; cout << endl;
	cout << "Ingrese su score: "; cin >> scoreInput; cout << endl;

	HSmanagement::add_Score(scoreInput, nameInput, scores, names);

	cout << "El jugador a sido añadido con exito!" << endl;
}

void MaxToMin(){
	HSmanagement::higher_To_Lowest(scores, names);
}

void MinToMax() {
	HSmanagement::lowest_To_Highest(scores, names);
}

void SearchScore() {
	string nameAux;
	int scoreSearched = 0;
	cout << "El puntaje de quien desea buscar? " << endl;
	cout << "NAME: "; cin >> nameAux;
	scoreSearched = HSmanagement::find_Score(nameAux,scores,names);
	cout << endl;
	cout << "El score de " << nameAux << " es : " << scoreSearched << endl;
}

void CopyScoreTable() {
	long int scores2[HSmanagement::size];
	string names2[HSmanagement::size];
	copy_Table(scores, names, scores2, names2);
	cout << "Los puntajes se copiaron a otra tabla!" << endl;
}

void interfaz(){
	int eleccion = 0;
	bool onMenu = true;

	while (onMenu)
	{
		cout << "Ingrese que desea hacer con la tabla:" << endl;

		cout << "[0] MOSTRAR LA TABLA" << endl;
		cout << "[1] AGREGAR NUEVO PUNTAJE" << endl;
		cout << "[2] BUSCAR PUNTAJE" << endl;
		cout << "[3] ORDENAR DE MAYOR A MENOR" << endl;
		cout << "[4] ORDENAR DE MENOR A MAYOR" << endl;
		cout << "[5] COPIAR LA TABLA A OTRA TABLA" << endl;
		cout << "[6] LIMPIAR TABLA DE PUNTAJES" << endl;
		cout << "[7] SALIR DEL GESTOR DE PUNTAJES" << endl;

		cin >> eleccion;

		switch (eleccion)
		{
		case 0: system("cls");
			showTable();
			break;
		case 1: system("cls");
			addScore();
			break;
		case 2:	system("cls");
			SearchScore();
			break;
		case 3: system("cls");
			MaxToMin();
			showTable();
			break;
		case 4:	system("cls");
			MinToMax();
			showTable();
			break;
		case 5:system("cls");
			CopyScoreTable();
			break;
		case 6: system("cls");
			clean_Table(scores, names);
			cout << "Tabla limpiada con exito!" << endl;
			break;
		case 7:onMenu = false;
			break;
		}
	}
}

int main()
{
	clean_Table(scores,names);
	
	interfaz();

	system("pause");
	return 0;
}
