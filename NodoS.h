#ifndef NODOS_H
#define NODOS_H
#include <iostream>
#include <climits>
using namespace std;
	template <class T>
	class NodoS
	{
		private:
			int elem; // Elemento menor entre indices i y j
			int ind1;
			int ind2;/* Indices ind1 y ind2 identifican el fragmento de segmento que representa el NodoSSSSSS(ind1<=ind2)*/
			NodoS<T> *lson,*rson;
		public:
			NodoS<T>();// Constructor básico
			NodoS<T>(int& ii,int& jj); // Llena el NodoS y asume que será el NodoS raiz , llenando entre el inicio y N, fin del arreglo
			NodoS<T>* getHijoI();
			NodoS<T>* getHijoD();
			void setmenor(int& elemento);
			int getmenor();
			void setHijoD(NodoS<T>* hd);
			void setHijoI(NodoS<T>* hi);	
		//	void llenar(T arreglo[],int ii,int jj);//LLena el NodoS con el menor elemento entre los indices a partir del arreglo
			void getindices(int& inf,int& sup); // inf sera el valor del primer indice, igual sup pero con el otro indice		
	};
/////////////////////////////
template<class T>
NodoS<T>::NodoS()
{
	ind1=ind2=-1;// Identificador que indica que no hay arreglo que represente el NodoS	
	lson=rson=NULL;
}
/////////////////////////////
template<class T>
NodoS<T>::NodoS(int& ii,int& jj)
{
	
	ind1=ii;
	ind2=jj;
	lson=rson=NULL;
}
/////////////////////////////
/*template<class T>
void NodoS<T>::llenar(T arreglo[],int ii,int jj)
{
	
	int i,comp=-1;
	long int mayor=LONG_MAX;
	ii--;
	jj--;// Por motivos de diferencia de indices en pseudo y programacion
	if((ii>=0)&&(ii<=jj))
	{
		i=ii;
		while(i<=jj)
		{
			if(arreglo[i]<mayor)
			{
				mayor=arreglo[i];
				comp=i;
			}
			i++;
		}
	}
	if(comp!=-1)
	{
		ind1=ii+1;
		ind2=jj+1;
		elem=comp+1;
	}
}*/

///////////////////////////////////
template<class T>
void NodoS<T>::setmenor(int& elemento)
{
	elem=elemento;
}
//////////////////////////////////
template<class T>
int NodoS<T>::getmenor()
{
	return elem;
}
////////////////////////////////////
template <class T>
void NodoS<T>::getindices(int& inf,int& sup)
{
	if(ind1!=-1)
	{
		sup=ind2;
		inf=ind1;
	}
	else
	{
		inf=sup=-1; // NodoS no lleno
	}
}
/////////////////////////////////////////////
template<class T>
NodoS<T>* NodoS<T>::getHijoI()
{
	return(lson);
}
/////////////////////////
template<class T>
NodoS<T>* NodoS<T>:: getHijoD()
{
	return(rson);
}
///////////////////////////////////
template<class T>
void NodoS<T>::setHijoD(NodoS<T>* hd)
{
	rson=hd;
}
/////////////////////////////
template<class T>
void NodoS<T>::setHijoI(NodoS<T>* hi)
{
	lson=hi;
}	
#endif
