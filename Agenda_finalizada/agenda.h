#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;


template <typename TIPO, int MAX>
struct Agenda {
 TIPO itens[MAX];
 int quantidade;
};

template <typename TIPO, int MAX>
bool inicializa_agenda(Agenda <TIPO,MAX> &ag) {
 ag.quantidade = 0;
 for(int i=0;i<MAX;i++){
        ag.itens[i].id=0;
 }
 return true;
};

template <typename TIPO, int MAX>
bool verifica_agenda(Agenda <TIPO,MAX> &ag) {///verifica se a agenda já está lotada
    if(ag.quantidade<MAX){
        return true;
    }
    else{
        return false;
    }
}

void gotoxy(int x, int y){ ///Função go to (X,Y)
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

template <typename TIPO, int MAX>
void insere(Agenda<TIPO,MAX> &ag,TIPO aux){ ///Copia o item inserido para a agenda desejada
    ag.itens[ag.quantidade] = aux;
    ag.quantidade++;
}
template <typename TIPO, int MAX>
int pesquisa_id(Agenda<TIPO,MAX> ag,int aux,int x){ ///faz a busca de contatos com base no ID
        for(int i=0;i<ag.quantidade;i++){
            if(ag.itens[i].id==x){
               return i;
            }
        }
}

template <typename TIPO, int MAX>
int pesquisa_nome(Agenda<TIPO,MAX> ag,int aux,string x){ ///Faz a buscade contatos com base no nome ou nome da empresa e mostra todos os respectivos dados
    for(int i=0;i<ag.quantidade;i++){
        if(ag.itens[i].nome==x){
           return i;
        }
    }
}

template <typename TIPO, int MAX>
void Remover(Agenda<TIPO,MAX> &ag,int id){ ///Faz a remoção do contato desejado com base no ID e reordena os ID's dos contatos, diminuindo tambem a contagem de contatos na agenda
    TIPO Aux;
    for (id;id<=ag.quantidade;id++){///Apaga o contado desejado e reordena o vetor
        Aux=ag.itens[id];
        ag.itens[id-1]=Aux;
    }
    ag.quantidade--;
    for(int i=0;i<ag.quantidade;i++){///reordena os ID's
        ag.itens[i].id=i+1;
    }
}
