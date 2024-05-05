#include <iostream>

using namespace std;

struct nodo{
	int nro;
	int tipo;
	struct nodo *sgte;

};

typedef struct nodo *TpLista;// crear tipo de dato struct nodo
// Funcion para crear Nodo
TpLista  crearNodo(int n,int t){
	TpLista q=new(struct nodo );
	system("CLS");
	q->nro=n;
	q->tipo=t;
	q->sgte = NULL;
	return q;
}

void mostrarLista(TpLista lista){
	TpLista t=lista;
	while(t != NULL ){
		cout<<"nr = "<<t->nro<<" tipo= "<<t->tipo<<" --> ";
		t=t->sgte;
	}
	cout<<" NULL"<<endl;
}

void insertarInicio(TpLista &lista){
    int num,tp;
    cout<<"\nIngresar numero--> ";cin>>num;
    cout<<"\nIngresar Tipo--> ";cin>>tp;
	TpLista w= crearNodo(num,tp);
	w->sgte=lista;
	lista=w;
}
void insertarFinal(TpLista &lista,TpLista nodo){
	if (lista == NULL) {
        lista = nodo;
        return;
    }

	TpLista w=nodo,t=lista;

	while(t->sgte != NULL)
		t=t->sgte;
	t->sgte=w;
}

void insertarPosicion(TpLista &lista,TpLista nodo, int pos){
	TpLista w=nodo,t=lista, s=NULL;
	int x=1;
	bool flag=false;
	if(pos ==1)
		insertarInicio(lista);
	else{
		while( x != pos &&  t->sgte != NULL){
			s=t;
			t=t->sgte;
			x++;
			if(x==pos)
				flag=true;
		}

	if(flag ==false){
		cout<<" Error, posicion ingresada no existe..."<<endl;

	}else{
		s->sgte=w;
		w->sgte=t;
	}
	}

}

void eliminarInicio(TpLista &lista){
	TpLista w=lista;
	lista=lista->sgte;
	delete(w);

}
 void eliminarFinal(TpLista &lista){
 	TpLista t=lista, s=NULL;
 	while(t->sgte != NULL){
 		s=t;
 		t=t->sgte;
	 }
 	s->sgte=NULL;
 	delete(t);
 }

void eliminarPosicion(TpLista &lista, int pos){
	TpLista t=lista, s=NULL;
	int x=1;
	bool flag=false;
	if(pos==1){

		eliminarInicio(lista);
		return;
	}
	while(	x!= pos && t->sgte != NULL ){
		s=t;
		t=t->sgte;
		x++;
		if(x==pos)
			flag=true;
	}
	if(flag == false){
		cout<<"Error, Posicion ingresada NO EXISTE.."<<endl;

	}else{
		s->sgte=t->sgte;
		delete(t);

	}
}
int promedioLista(TpLista lista){
    TpLista t=lista;
    int suma=0, n=0, promediov;
	while(t != NULL ){
		suma= suma+t->nro;
		t=t->sgte;
		n++;
	}
	
	
	if(n==0){
		return(-1);
	}
	
	promediov=suma/n;
	return(promediov);
}

void opcion1(TpLista &lista){
    int num, tp;
    do{
        cout<<"\nIngresar numero--> ";cin>>num;
        if(promedioLista(lista)==-1){
        	break;
		}

		cout<<"El promedio es:"<<promedioLista(lista);
    }while(num>promedioLista(lista));

	cout<<"\nIngresar Tipo--> ";cin>>tp;
	insertarFinal(lista,crearNodo(num,tp));
	
}

void opcion2(TpLista &lista){
	int num,tp,x=0,pos;
	do{
        cout<<"\nIngresar numero impar: ";cin>>num;
    }while(num%2==0);
    cout<<"\nIngresar Tipo--> ";cin>>tp;
    TpLista t=lista;
    while(t!= NULL){
	
			t=t->sgte;
			x++;
	}
	if(x%2==0){
		pos=x/2;
		pos= pos+1;
	}
	else{
		pos=(x+1)/2;
	}
	
	cout<<pos<<endl;
	insertarPosicion(lista,crearNodo(num,tp),pos);
}
void opcion3(TpLista &lista){
	
	TpLista t=lista;
	int x=0, menor=t->nro;
    while(t!= NULL){
			if(t->nro<menor){
				menor=t->nro;
			}
			t=t->sgte;
			x++;
			
	}
	eliminarPosicion(lista,x);
}

void menu(){
system("CLS");
 cout<<"\n\t LISTA ENLAZADA SIMPLE\n\n";
 cout<<"1.- Insertar numero menor a promedio al final "<<endl;
 cout<<"2.- Crear nodo impar en el medio "<<endl;
 cout<<"3.- Eliminar minimo valor"<<endl;
 cout<<"4.- Mostrar lista "<<endl;
 cout<<"0.- Salir "<<endl<<endl;

 cout<<"Ingresar Opcion--->  "<<endl;
}

//***************************************
int main() {

	int posicion,opc, busca, reemp;
	TpLista lista=NULL;// variable gusrada el inicio de la lista

	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
				opcion1(lista);
				mostrarLista(lista);
				system("pause");
				break;
				}

			case 2:{
				opcion2(lista);
				mostrarLista(lista);
				system("pause");
				break;
				}

			case 3:
			{
				opcion3(lista);
				mostrarLista(lista);
				system("pause");
				break;
				}
			case 4:{

				mostrarLista( lista);
				system("pause");
				break;
				}
		}

	}while(opc !=0);
	system("pause");
	return 0;
}

