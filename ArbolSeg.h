#ifndef ARBOLSEG_H
#define ARBOLSEG_H
#include <iostream>
#include "Cola.h"
#include "NodoS.h"
using namespace std;

	template<class T>
	class ArbolSeg
	{
		private:
			NodoS<T>* raiz;			
			//Metodos Privados
			void conectarhi(T *p,NodoS<T>* p_raiz,int& inf,int& tamVec);
			void conectarhd(T *p,NodoS<T>* p_raiz,int& inf,int& tamVec);
			void recpreorden(NodoS<T> *p_raiz,int &valid);
			void recpostorden(NodoS<T> *p_raiz);
			void recnivel(NodoS<T> *p_raiz);
			void rec_vaciar(NodoS<T> *p_raiz);
		public:
			//Constructores
			ArbolSeg<T>();
			ArbolSeg<T>(T vecVals[],int tamVec);//O(N)
			//Metodos
			bool esvacio();
			void vaciar();
			void niveles();
			void conectar(T *p,NodoS<T>* p_raiz,int& inf,int& tamVec);
			int consultarMenorRango(int i,int j); // O(log(n))
			~ArbolSeg<T>();
			void preorden();
			void postorden();// Los recorridos no funcionan muy bien solo son una guia para ver si el arbol esta bueno, tampoco me esforce mucho en ke funcionaran
	};
/////////////////////////
template<class T>
ArbolSeg<T>::ArbolSeg()
{
	raiz=NULL;
}
/////////////////////////
template<class T>
ArbolSeg<T>::ArbolSeg(T vecVals[],int tamVec)
{
	T *p;
	int ii=1,jj=1,aux,aux2,vec=tamVec;
	p=&vecVals[0];
	raiz=new NodoS<T>(jj,tamVec);
	
	conectarhi(p,raiz,ii,tamVec);
	conectarhd(p,raiz,jj,vec);
	

	if(vecVals[raiz->getHijoI()->getmenor()-1] < vecVals[raiz->getHijoD()->getmenor()-1])
	{
		aux=raiz->getHijoI()->getmenor();
		raiz->setmenor(aux);
	}
	else
	{
		aux2=raiz->getHijoD()->getmenor();
		raiz->setmenor(aux2);
	}
	
}
/////////////////////////////////////////
template<class T>
void ArbolSeg<T>::conectarhi(T *p,NodoS<T>* p_raiz,int& inf,int& tamVec)
{
	char xx;
	NodoS<T> *p_aux,*p_aux2,*p_aux3;
	T *p2=p;
	int ii,jj,kk,ll,mm,nn,sup,sup2,flag=2;
	////////////////
	sup=((inf+tamVec)/2);
	p_aux=new NodoS<T>(inf,sup);
	p_aux->getindices(ii,jj);
	p_raiz->setHijoI(p_aux);
	while(ii!=jj)
	{	
		conectarhi(p,p_aux,ii,jj);
		p_aux->getindices(ii,jj);
		sup2=(((ii+jj)/2)+1);
		p_aux2=new NodoS<T>(sup2,jj);
		p_aux2->getindices(kk,ll);
		p_aux->setHijoD(p_aux2);
		ii=kk;
		jj=ll;
		p_aux3=p_aux;
		p_aux=p_aux2;
		flag=1;
	}
	if(ii==jj)
	{
		p_aux->setmenor(ii);
		if(flag==1)
		{
			if(p[p_aux3->getHijoI()->getmenor()-1] < p[p_aux3->getHijoD()->getmenor()-1])// Caso base segmento de un solo elemento
			{
				sup2=p_aux3->getHijoI()->getmenor();
				p_aux3->setmenor(sup2);
			}
			else
			{
				sup2=p_aux3->getHijoD()->getmenor();
				p_aux3->setmenor(sup2);
			}
			p=p2;
		}
	//	cout << endl << " menor: "<< ii << endl;
		flag=0;
	}
	/*else
	{
		if(p[p_raiz->getHijoI()->getmenor()] < p[p_raiz->getHijoD()->getmenor()])// Caso base segmento de un solo elemento
		{
			sup2=p_raiz->getHijoI()->getmenor()+1;
			p_raiz->setmenor(sup2);
		}
		else
		{
			sup2=p_raiz->getHijoD()->getmenor()+1;
			p_raiz->setmenor(sup2);
		}
		p=p2;
	}*/
}
////////////////////////////
template<class T>
void ArbolSeg<T>::conectarhd(T *p,NodoS<T>* p_raiz,int& inf,int& tamVec)
{
	char xx;
	NodoS<T> *p_aux,*p_aux2,*p_aux3;
	T *p2=p;
	int ii,jj,kk,ll,mm,nn,sup,sup2,flag=2;
	////////////////
	sup=(((inf+tamVec)/2)+1);
	p_aux=new NodoS<T>(sup,tamVec);
	p_aux->getindices(ii,jj);
	p_raiz->setHijoD(p_aux);
	cout << ""<<ii<<" "<<jj;
	cin >>xx;
	while(ii!=jj)
	{	
		conectarhd(p,p_aux,ii,jj);
		p_aux->getindices(ii,jj);
		sup2=((ii+jj)/2);
		p_aux2=new NodoS<T>(ii,sup2);		
		p_aux2->getindices(kk,ll);
		p_aux->setHijoI(p_aux2);
		ii=kk;
		jj=ll;
		p_aux3=p_aux;
		p_aux=p_aux2;
		flag=1;
	}
	if(ii==jj)
	{
		p_aux->setmenor(ii);
		if(flag==1)
		{
			if(p[p_aux3->getHijoI()->getmenor()-1] < p[p_aux3->getHijoD()->getmenor()-1])// Caso base segmento de un solo elemento
			{
				sup2=p_aux3->getHijoI()->getmenor();
				p_aux3->setmenor(sup2);
			}
			else
			{
				sup2=p_aux3->getHijoD()->getmenor();
				p_aux3->setmenor(sup2);
			}
			p=p2;
		}
	//	cout << endl << " menor: "<< ii << endl;
		flag=0;
	}
	/*else
	{
		if(p[p_raiz->getHijoI()->getmenor()] < p[p_raiz->getHijoD()->getmenor()])// Caso base segmento de un solo elemento
		{
			sup2=p_raiz->getHijoI()->getmenor()+1;
			p_raiz->setmenor(sup2);
		}
		else
		{
			sup2=p_raiz->getHijoD()->getmenor()+1;
			p_raiz->setmenor(sup2);
		}
		p=p2;
	}*/
}
/////////////////////////
template<class T>
bool ArbolSeg<T>::esvacio()
{
	return(raiz==NULL);
}
/////////////////////////
template<class T>
int ArbolSeg<T>::consultarMenorRango(int i,int j)
{
	
}
/////////////////////
template<class T>
void ArbolSeg<T>::postorden()
{
	NodoS<T> *aux;
	aux=new NodoS<T>();
	aux->setHijoI(raiz);
	cout << "Recorrido Post-orden:<";
	if(!esvacio())
	recpostorden(aux);
	else
	{
		cout << " -";
	}
	cout << " >" << endl;
	delete aux;
}
///////////////////////////////////////////
template<class T>
void ArbolSeg<T>::recpostorden(NodoS<T> *p_raiz)
{
	NodoS<T> *p_aux,*p_aux2;	
	p_aux=p_raiz->getHijoI();
	p_aux2=p_raiz;
	while(p_aux!=NULL)
	{
		recpostorden(p_aux);
		cout << " " << p_aux->getelemento();
		p_aux2=p_aux2->getHijoD();
		p_aux=p_aux2;
	}
}
////////////////////////////////
template<class T>
void ArbolSeg<T>::preorden()
{
	NodoS<T> *aux;
	int valid=0;
	aux=new NodoS<T>();
	aux->setHijoI(raiz);
	cout << "Recorrido Pre-orden:<";
	if(!esvacio())
	recpreorden(aux,valid);
	else
	{
		cout << " -";
	}
	cout << " >" << endl;
	delete aux;
}
/////////////////////
template<class T>
void ArbolSeg<T>::recpreorden(NodoS<T> *p_raiz,int &valid)
{
	char xx;
	NodoS<T> *p_aux;
	if(valid!=0)
	cout << " " << p_raiz->getelemento();
	cin>>xx;
	valid++;
	p_aux=p_raiz->getHijoI();
	while(p_aux!=NULL)
	{
		recpreorden(p_aux,valid);
		p_aux=p_aux->getHijoD();
	}
}
/////////////////////
template<class T>
void ArbolSeg<T>::niveles()
{
	cout << "Recorrido por Niveles:<";
	if(!esvacio())
	recnivel(raiz);
	else
	{
		cout << "-";
	}
	cout << " >" << endl;
}
/////////////////////
template<class T>
void ArbolSeg<T>:: recnivel(NodoS<T> *p_raiz)
{
	Cola< NodoS<T>* > cc;
	cc.encolar(p_raiz);
	while(!cc.esvacia())
	{	
		cout << " " <<cc.getfrente()->getmenor();
		if(cc.getfrente()->getHijoI()!=NULL)
		{
			cc.encolar(cc.getfrente()->getHijoI());
		}
		if(cc.getfrente()->getHijoD()!=NULL)
		{
			cc.encolar(cc.getfrente()->getHijoD());
		}
		cc.desencolar();
	}
}
////////////////////////
template<class T>
void ArbolSeg<T>::rec_vaciar(NodoS<T> *p_raiz)
{
	NodoS<T> *p_aux,*p_aux2;
	p_aux=p_raiz->getHijoI();
	p_aux2=p_raiz;
	while(p_aux!=NULL)
	{
		rec_vaciar(p_aux);
		p_aux2=p_aux2->getHijoD();
		p_aux=p_aux2;
	}
	delete p_raiz;	
}
//////////////////////////
template<class T>
void ArbolSeg<T>::vaciar()
{
	if(!esvacio())
	{
		rec_vaciar(raiz);
	}
	raiz=NULL;
}
/////////////////////////
template<class T>
ArbolSeg<T>::~ArbolSeg()
{
	vaciar();
}
#endif
