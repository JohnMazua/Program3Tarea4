#include "Evaluador.h"
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream archivo(nombre_archivo.c_str(), ios::in); // abre el el archivo en la variable nombre_archivo para escribir en el
    archivo<<num; // escribe el valor de la variable num al archivo
    archivo.close(); // cierra el archivo
}
int leerNumeroTexto(string nombre_archivo)
{
    int num; // crea la variable num
    ifstream archivo(nombre_archivo.c_str(), ios::out); // abre el el archivo en la variable nombre_archivo para lectura
    archivo>>num; // escribe lo que encuentra en el archivo a la variable num
    return num; // retorna el valor de num
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream archivo(nombre_archivo.c_str()); // abre el el archivo en la variable nombre_archivo para escribir en el
    archivo<<str; // escribe el valor de la variable str al archivo
    archivo.close(); // cierra el archivo
}
string leerStringTexto(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str()); // abre el el archivo en la variable nombre_archivo para lectura
    string str; // crea la variable str
    archivo>>str; // escribe lo que encuentra en el archivo a la variable str
    return str; // retorna el valor de str
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
    ofstream archivo(nombre_archivo.c_str()); // abre el el archivo en la variable nombre_archivo para escribir en el
    archivo.write((char*)&num,10); // escribe la variable num al archivo binario
    archivo.close(); // cierra el archivo
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str()); // abre el el archivo en la variable nombre_archivo para lectura
    int num; // declara la variable num
    archivo.read((char*)&num,10); // lee el archivo binario y escribe el valor a la variable num
    return num; // retorna num
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream archivo(nombre_archivo.c_str()); // abre el el archivo en la variable nombre_archivo para escribir en el
    archivo.write(str.c_str(),10); // escribe la variable num al archivo binario
    archivo.close(); // cierra el archivo
}
string leerStringBinario(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str()); // abre el el archivo en la variable nombre_archivo para lectura
    char* texto; // declara el apuntador tipo char a la variable texto
    texto = new char[10]; // asigna un array de 10 espacios a la variable texto
    archivo.read(texto,10); // asigna los primeros 10 caracteres del archivo binario a la variable texto
    return texto; // retorna el valor de texto
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    int tamano,cont=0; // declara las variables númericas tamano y cont, donde cont es igual a 0
    string texto; // declara la variable texto que es una variable textual
    ifstream archivo(nombre_archivo.c_str()); // abre el el archivo en la variable nombre_archivo para lectura
    while(archivo>>texto) // declara que mientras el archivo tenga texto que pueda enviar a la variable texto que trabaje
    {
    if(str.compare(texto)==0) cont=cont+1; // utiliza la función compare para comparar ambos textos, y si son iguales, incrementa el contador
    }
    if(cont>0) return true; // si hay algo en el contador retorna el valor de verdadero
    else if(cont==0) return false; // si no hay algo en el contador (0) retorna el valor de falso
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream archivo(nombre.c_str()); // abre el el archivo en la variable nombre para lectura
    int num,tamano,mayor=0; // declara las variables númericas num, tamano y mayor, donde mayor es igual a 0
    archivo.seekg(0,ios::end); // busca el final del archivo para ver el tamaño del archivo entero
    tamano = archivo.tellg()/4; // divide dicha cantidad entre 4, para definir el tamaño de la variable tamano
    archivo.seekg(0,ios::beg); // retorna al principio del archivo
    for(int i=0;i<tamano;i++) // contador de 0 a tamano
    {
    archivo.read((char*)&num,4); // lee el archivo binario y asigna la variable a num
    if(num>mayor)mayor=num; // si num es el numero mayor, entonces mayor es igual a num. Donde se guarde el valor major de todos
    }
    return mayor; //retorna el valor de la variable mayor.
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
