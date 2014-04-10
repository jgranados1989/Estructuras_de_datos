/**************************************************
*	Implementacion de colas basicas en C++		  *
*	Codigo Original: Jimmy Granados				  *
*	Algoritmos y estructuras de datos			  *
***************************************************/
#include <iostream>

using namespace std;

//Prototipo Clase nodoCola
class nodoCola
{
	public:	
		//Constructores de la clase NodoCola
		nodoCola();
		nodoCola(int valor);
		nodoCola(int valor,nodoCola *sig);
		//Funciones miembro de nodoCola		
		int retornaValor();
	private:
		//Datos pertenecientes a cada nodoCola
		int datos;
		nodoCola *siguiente;
	friend class Cola;
};//Fin prototipo clase nodoCola

//Constructor nodoCola
nodoCola::nodoCola()
{
}
//Constructor nodoCola
nodoCola::nodoCola(int numero)
{
	datos=numero;
	siguiente=NULL;
}
//Constructor nodoCola
nodoCola::nodoCola(int numero,nodoCola *sig)
{
	datos=numero;
	siguiente=sig;
}

//Funcion que retorna (e imprime) el valor de un nodoCola
int nodoCola::retornaValor()
{
	cout<<"Valor de nodo: "<<datos<<"\n"; //Comentar esta linea si solo se quiere retornar el valor
	return datos;
}

//Prototipo de la clase Cola
class Cola
{
	public:	
		//Constructor de la clase Cola
		Cola();
		//Funciones miembro de Cola		
		int estaVacia();
		void push(int valor);
		int pop();
		void imprimeCola();
	private:
		//Datos pertenecientes a la Cola
		nodoCola *primero;
};

//Constructor de la cola de aridad 0
Cola::Cola()
{
	primero=NULL;
}

//Funcion que retorna 1 si la cola esta vacia, 0 en otro caso
int Cola::estaVacia()
{
	if(!primero)
		return 1;
	else return 0;
}

//Funcion que obtiene el primer nodo de la colas
int Cola::pop()
{
	int retorno;
	//Si la cola esta vacia informa al usuario
	if(!primero)
		cout<<"La cola esta vacia\n";
	else
	{
		nodoCola *aux=primero;
		retorno=aux->datos;
		primero=primero->siguiente;		
		aux=NULL;
		cout<<retorno<<" sacado de la cola con exito\n"; //Informa que se saco de la cola (opcional)
	}
	return retorno;
}
//Funcion que inserta un nodo en la cola
void Cola::push(int valor)
{
	//Si la cola esta vacia lo asigna al primero
	if(!primero)
	{
		primero=new nodoCola(valor);
		cout<<valor<<" insertado con exito\n";//Informa que se inserto a la cola (opcional)
	}
	else
	{
		nodoCola *aux;
		aux=primero;
		while(aux->siguiente!=NULL)
		{
			aux=aux->siguiente;			
		}
		aux->siguiente=new nodoCola(valor);
		cout<<valor<<" insertado con exito\n"; //Informa que se inserto a la cola(opcional)
	}
}
//Funcion que imprime todos los datos de los nodos de la cola
void Cola::imprimeCola()
{
	if(!primero)
		cout<<"Cola vacia";
	else
	{
		nodoCola *aux;
		aux=primero;
		while(aux!=NULL)
		{
			cout<<aux->datos<<" - ";
			aux=aux->siguiente;			
		}
		cout<<"\n=====Fin de cola=====\n";
	}
}

main()
{
	Cola prueba1; //Creacion de cola llamada prueba1
	{	//Pruebas de push
		prueba1.push(35);
		prueba1.push(45);
		prueba1.push(67);
		prueba1.push(95);
		prueba1.push(23);
	}
	prueba1.imprimeCola();
	{	//Pruebas de pop
		prueba1.pop();
		prueba1.pop();
		prueba1.pop();
		prueba1.pop();
		prueba1.pop();
		prueba1.pop();
	}
	prueba1.imprimeCola();
	{
		prueba1.push(1);
		prueba1.push(2);
		prueba1.push(3);
		prueba1.push(4);
		prueba1.push(5);
	}
	prueba1.imprimeCola();
}
