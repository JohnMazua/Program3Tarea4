#include "Evaluador.h"
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo de texto
void escribirNumeroTexto(string nombre_archivo, int num)
{
    ofstream archivo(nombre_archivo.c_str(), ios::in);
    archivo<<num;
    archivo.close();
}
int leerNumeroTexto(string nombre_archivo)
{
    int num;
    ifstream archivo(nombre_archivo.c_str(), ios::out);
    archivo>>num;
    return num;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo de texto
void escribirStringTexto(string nombre_archivo, string str)
{
    ofstream archivo(nombre_archivo.c_str());
    archivo<<str;
    archivo.close();
}
string leerStringTexto(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str());
    string str;
    archivo>>str;
    return str;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente un numero ubicado al inicio de un archivo binario
void escribirNumeroBinario(string nombre_archivo, int num)
{
    ofstream archivo(nombre_archivo.c_str());
    archivo.write((char*)&num,10);
    archivo.close();
}
int leerNumeroBinario(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str());
    int num;
    archivo.read((char*)&num,10);
    return num;
}

//Las siguientes funciones escribir y leer ingresan y leen respectivamente una cadena ubicada al inicio de un archivo binario
void escribirStringBinario(string nombre_archivo, string str)
{
    ofstream archivo(nombre_archivo.c_str());
    archivo.write(str.c_str(),10);
    archivo.close();
}
string leerStringBinario(string nombre_archivo)
{
    ifstream archivo(nombre_archivo.c_str());
    char* texto;
    texto = new char[10];
    archivo.read(texto,10);
    return texto;
}

//Devuelve true si encuentra str (dada) en un archivo dado el nombre
bool existe(string nombre_archivo, string str)
{
    int tamano,cont=0;
    string texto;
    ifstream archivo(nombre_archivo.c_str());
    archivo.seekg(0,ios::end);
    tamano = archivo.tellg()/str.length();
    archivo.seekg(0,ios::beg);
    for(int i=0;i<tamano;i++)
    {
    archivo>>texto;
    cout<<str<<" es igual a: "<<texto<<" Valor de: ";
    if(str.compare(texto)==0) cont=cont+1;
    cout<<cont<<endl;
    }
    if(cont>0)
    {
    cout<<"True!"<<endl;
    return true;
    }
    else if(cont==0)
    {
    cout<<"False!"<<endl;
      return false;
    }
}

//Devuelve el numero mayor dado el nombre de un archivo binario
int obtenerMayor(string nombre)
{
    ifstream archivo(nombre.c_str());
    int num,tamano,mayor=0;
    archivo.seekg(0,ios::end);
    tamano = archivo.tellg()/4;
    archivo.seekg(0,ios::beg);
    for(int i=0;i<tamano;i++)
    {
    archivo.read((char*)&num,4);
    if(num>mayor)mayor=num;
    }
    return mayor;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
