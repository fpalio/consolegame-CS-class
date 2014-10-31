// Trabajo 
#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

//indice:**************
//*=pared             *
//@= personaje        *
//O = cajas           *
//X = meta            *
//*********************

//nivel 1*****************************************************************
int map[16][40] = 
{{6,0,6,0,6,0,0,6,0,0,6,0,0,6,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,6,0,0,6,0,0,0,0,0,0,0,0,0,0,0,6,0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,6,0,0,0,0,0,6,0,6,0,0,6,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0},
{0,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,6,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,4,0,0,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{6,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,6,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,6,0,0,0,0,0,0},
{0,0,0,6,0,0,0,4,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0},
{6,0,0,0,0,6,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0},
{0,0,0,0,0,0,0,6,0,6,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,6,0,0,0,0,0,0,0,6,0,0,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};




//**********variables***************************
int x;
int y ;
char cTecla = 0;
int nivelGM=1;

//****funciones de mecanismo***************************
void dibujar (int map[][40])
{
	for (int fil = 0; fil < 16; fil++)
	{

		for (int col = 0; col < 40; col++)
		{
			if (map[fil][col] == 0)
			{
				Console::BackgroundColor = ConsoleColor::White;
				Console::SetCursorPosition(15+col,5+fil);
				cout <<" ";
				

			}
			else if (map[fil][col] == 2)
			{
				Console::BackgroundColor = ConsoleColor::White;
				Console::ForegroundColor =ConsoleColor::Red;
				Console::SetCursorPosition(15+col,5+fil);
				cout <<"*";
				x =col;
				y= fil;
				

			}else if (map[fil][col] == 3)
			{
				Console::BackgroundColor = ConsoleColor::Green;
				Console::SetCursorPosition(15+col,5+fil);
				cout <<" ";
				

			}else if (map[fil][col] == 4)
			{
				Console::BackgroundColor = ConsoleColor::Yellow;
				Console::SetCursorPosition(15+col,5+fil);
				cout <<" ";
				

			}
			else if (map[fil][col] == 6)
			{
				Console::BackgroundColor = ConsoleColor::Black;
				Console::SetCursorPosition(15+col,5+fil);
				cout <<" ";

			}
			
		
		}


	}

}
void movimientoPersonaje (int map[][40])
{
	cTecla = _getch(); // sin eco
	
	// Las compuestas//esto lagea y requiere mucha memoria lo cual hace el juego lento
	//if( cTecla == 0 ) cTecla = getch(); 
	
	//movimiento izquierda
	if( cTecla == char(97) ){
		int x2 = x-1;
		int x3 = x-2;
		if(map[y][x2] == 0){
			map[y][x] = 0;
			x--;
			map[y][x] = 2;
		}else if(map[y][x2] == 4 && map[y][x3] == 0){
			map[y][x] = 0;
			x--;
			map[y][x] = 2;
			map[y][x-1] =4;
		}else if(map[y][x2] == 4 && map[y][x3] == 6){
			map[y][x] = 0;
			x--;
			map[y][x] = 2;
			map[y][x-1] =0;
		}
	}
	// movimiento derecha
	if( cTecla == char(100) ){
		int x2 = x+1;
		int x3 = x+2;
		if(map[y][x2] == 0){
			map[y][x] = 0;
			x++;
			map[y][x] = 2;
		}else if(map[y][x2] == 4 && map[y][x3] == 0){
			map[y][x] = 0;
			x++;
			map[y][x] = 2;
			map[y][x+1] =4;
		}else if(map[y][x2] == 4 && map[y][x3] == 6){
			map[y][x] = 0;
			x++;
			map[y][x] = 2;
			map[y][x+1] =0;
		}
	}
	//movimiento arriba
	if( cTecla == char(119) ){
		int y2 = y-1;
		int y3 = y-2;
		if(map[y2][x] == 0){
			map[y][x] = 0;
			y--;
			map[y][x] = 2;
		}else if(map[y2][x] == 4 && map[y3][x] == 0){
			map[y][x] = 0;
			y--;
			map[y][x] = 2;
			map[y-1][x] = 4;
		}else if(map[y2][x] == 4 && map[y3][x] == 6){
			map[y][x] = 0;
			y--;
			map[y][x] = 2;
			map[y-1][x] =0;
		}
	}
	//movimiento abajo
	if( cTecla == char(115) )
	{
		int y2 = y+1;
		int y3 = y+2;
		if(map[y2][x] == 0){
			map[y][x] = 0;
			y++;
			map[y][x] = 2;
		}else if(map[y2][x] == 4 && map[y3][x] == 0){
			map[y][x] = 0;
			y++;
			map[y][x] = 2;
			map[y+1][x] =4;
		}else if(map[y2][x] == 4 && map[y3][x] == 6){
			map[y][x] = 0;
			y++;
			map[y][x] = 2;
			map[y+1][x] =0;
		}

	}
}


//*******************************************************
int main(array<System::String ^> ^args)
{
	
	cout<<"Silver Sphere";

	getch();
	system("cls");
//loop de juego****************************************
	while (cTecla != char(27))
	{
		switch (nivelGM)
		{
		case 1:
			movimientoPersonaje(map);
			dibujar (map);
			
			break;


		}
	}
	
	getch();
	return 0;
}