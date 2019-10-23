#include <iostream>
#include "agenda.h"
using namespace std;
#define T 50 ///Tamanho das agendas

///----------------------AGENDA--------------------------------///

struct Fisica{
  int id;
  string nome,cpf,telefone;
};
struct Juridica{
 int id;
 string nome,cnpj,telefone;
};

ostream &operator << (ostream &os,Fisica &x){
        os<<" ID: " <<x.id<<endl;
        os<<" CPF: "<<x.cpf<< endl;
        os<<" Telefone: "<<x.telefone<< endl;
        os<<" Nome: "<<x.nome<<endl;
        os<<"-------------------------------";
        os<< endl;
    return os;
}
istream &operator >> (istream &is,Fisica &x){
        cout << "CPF: ";
        is>>x.cpf;
        cout << "Telefone: ";
        is>>x.telefone;
        cout << "Nome: ";
        fflush(stdin);
        getline(is,x.nome);
    return is;
}
istream &operator >> (istream &is,Juridica &x){
        cout << "CNPJ: ";
        is>>x.cnpj;
        cout << "Telefone Comercial: ";
        is>>x.telefone;
        cout << "Nome da Empresa: ";
        fflush(stdin);
        getline(is,x.nome);
    return is;
}
ostream &operator << (ostream &os,Juridica &x){
        os<<" ID: " <<x.id<<endl;
        os<<" CNPJ: "<<x.cnpj<< endl;
        os<<" Telefone Comercial: "<<x.telefone<< endl;
        os<<" Nome da Empresa: "<<x.nome<<endl;
        os<<"-------------------------------";
        os<< endl;
    return os;
}

void seta(int gx,int &gy,int op){///Seta do menu do jogo
    int moveseta,i=0;
    gx=47,gy=2;
    bool sair=false;
    while(!sair){
/// mostra tecla
        gotoxy(gx,gy);
/// implementação para nao ter delay na troca da seta quando for para baixo ou para cima
        if(i<1000){
            cout << "->";
        }
        if(i>2000){
            i = 0;
        }
        if(_kbhit()){
            moveseta=getch();
        switch(moveseta){
        case 13:
            sair = true;
        break;
        case 72:
            if (gy == 2){
                break;
            }
            if(op==1 || op==2 || op==3 || op==4 || op==5 || op==6){
                if(gy==2){
                    break;
                }
            }
            gotoxy(gx,gy);
            cout << "  ";
            gy = gy - 2;
        break;
        case 80:
            if (gy == 10){
                        break;
            }
            if(op==1 || op==2 || op==3 || op==4 || op==5 || op==6){
                if(gy==4){
                    break;
                }
            }
            gotoxy(gx,gy);
            cout << "  ";
            gy = gy + 2;
        break;

        }
        }
        i++;
    }
    sair=false;
}
void apagacursor(){///Remove o curso da tela
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}
void Menu(){ ///Impressão dos opções do menu
    gotoxy(53,0);
    cout<<"    AGENDA";
    gotoxy(50,2);
    cout<<"Cadastro de Contatos";
    gotoxy(50,4);
    cout<<"Remover Contatos";
    gotoxy(50,6);
    cout<<"Ver Contatos";
    gotoxy(50,8);
    cout<<"Pesquisar Contatos";
    gotoxy(50,10);
    cout<<"Sair";
    gotoxy(7,2);
    gotoxy(3,3);
    cout<<"-Use as setas para cima e para baixo";
    gotoxy(3,4);
    cout<<" para mover o cursor";
    gotoxy(3,5);
    cout<<"-Digite enter para confirmar sua acao";
}
void Escolha(int op){ ///Impressão das opções dentro das opções do menu principal
    switch(op){
        case 1:
            gotoxy(50,0);
            cout<<"Deseja criar um contato: ";
            gotoxy(53,2);
            cout<<"FISICO";
            gotoxy(53,4);
            cout<<"JURIDICO";
        break;
        case 2:
            gotoxy(53,0);
            cout<<"Deseja Remover de qual agenda? ";
            gotoxy(50,2);
            cout<<"FISICO";
            gotoxy(50,4);
            cout<<"JURIDICO";
        break;
        case 3:
            gotoxy(53,0);
            cout<<"Deseja ver quais contatos? ";
            gotoxy(50,2);
            cout<<"FISICO";
            gotoxy(50,4);
            cout<<"JURIDICO";
        break;
        case 4:
            cout<<"Deseja pesquisar em qual agenda? ";
            gotoxy(50,2);
            cout<<"FISICO";
            gotoxy(50,4);
            cout<<"JURIDICO";
        break;
    }
}

template <typename TIPO, int MAX>
TIPO Enche_Agenda (Agenda <TIPO,MAX> ag){/// Faz o cin de forma generica para uma agenda, e ja aumenta a sua contagem de contatos
    TIPO x;
    cin >> x;
    x.id=ag.quantidade+1;
    return x;
}

int main()
{
    srand(time(NULL));
    apagacursor();
    int entrada=0,gx=47,gy=2;
    Agenda<Fisica,T> fisica;
    Agenda<Juridica,T> juridica;
    inicializa_agenda(fisica);
    inicializa_agenda(juridica);

    bool controle=true;
    while(controle){///-----------------MENU
        Menu();
        seta(gx,gy,0);
        entrada=gy;
        system("cls");
        switch (entrada){
            case 2:///--------------------Escolhe qual agenda inserir o contato
                int op1;
                Escolha(1);///------------Escolhe a agenda
                seta(gx,gy,1);
                op1=gy;
                system("cls");
                switch(op1){
                case 2:
                    {
                    if(verifica_agenda(fisica)){///---------------Verifica se a agenda esta cheia
                        insere(fisica,Enche_Agenda(fisica));///-----------Insere na agenda
                    }
                    else{
                        gotoxy(53,2);
                        cout<<"Agenda esta cheia!!";
                        getch();
                    }
                    system("cls");
                    }
                    break;
                case 4:
                    {
                    if(verifica_agenda(juridica)){
                        insere(juridica,Enche_Agenda(juridica));
                    }
                    else{
                        gotoxy(53,2);
                        cout<<"Agenda esta cheia!!";
                        getch();
                    }
                    system("cls");
                    }
                break;
                }
            break;
            case 4:///------------------------Remove os contatos
                int op2;
                Escolha(2);///----------------Escolhe a agenda que deseja remover
                seta(gx,gy,2);
                op2=gy;
                system("cls");
                switch (op2){
                case 2:
                    int idf;
                    cout<<"Digite o id que deseja remover: ";
                    cin>>idf;
                    Remover(fisica,idf);///-----------Remove o contato desejado
                    system("cls");
                break;
                case 4:
                    int idj;
                    cout<<"Digite o id que deseja remover: ";
                    cin>>idj;
                    Remover(juridica,idj);
                    system("cls");
                break;
                }
            break;
            case 6:///-----------------Imprime toda a agenda
                int op3;
                Escolha(3);///----------Escolhe a agenda
                seta(gx,gy,3);
                op3=gy;
                system("cls");
                switch (op3){
                case 2:
                    for(int i=0;i<fisica.quantidade;i++){ ///--------Imprime
                        cout<<fisica.itens[i];
                    }
                    getch();
                    system("cls");
                break;
                case 4:
                    for(int i=0;i<juridica.quantidade;i++){ ///--------Imprime
                        cout<<juridica.itens[i];
                    }
                    getch();
                    system("cls");
                }
            break;
            case 8:///----------------------------------Pesquisa os contatos
                int pesquisa;
                system("cls");
                int op4;
                gotoxy(53,0);
                Escolha(4);///--------------------------Escolhe a agenda
                seta(gx,gy,4);
                op4=gy;
                system("cls");
                switch (op4){
                case 2:///------------------------------Agenda Fisica
                    int op5;
                    gotoxy(53,0);
                    cout << "Pesquisar por ID ou Nome? ";
                    gotoxy(50,2);
                    cout<<"ID";
                    gotoxy(50,4);
                    cout<<"NOME";
                    seta(gx,gy,5);
                    op5=gy;
                    system("cls");
                    switch(op5){
                        case 2:///----------ID
                            int x;
                            cout << "Digite o id: ";
                            cin >> x;
                            cout<<fisica.itens[pesquisa_id(fisica,op5,x)];///-----------Faz a pesquisa na agenda
                        break;
                        case 4:///----------Nome
                            string y;
                            cout << "Digite o nome: ";
                            getline(cin,y);
                            cout<<fisica.itens[pesquisa_nome(fisica,op5,y)];
                        break;
                        }
                    getch();
                    system("cls");
                break;
                case 4:///---------------------------Agenda Juridica
                    int op6;
                    system("cls");
                    gotoxy(53,0);
                    cout << "Pesquisar por ID ou Nome? ";
                    gotoxy(50,2);
                    cout<<"ID";
                    gotoxy(50,4);
                    cout<<"NOME";
                    seta(gx,gy,6);
                    op6=gy;
                    system("cls");
                    switch(op6){
                        case 2:///------------ID
                            int x;
                            cout << "Digite o id: ";
                            cin >> x;
                            cout<<"\n\n";
                            cout<<juridica.itens[pesquisa_id(juridica,op6,x)];///----------Faz a pesquisa na agenda
                        break;
                        case 4:///------------Nome
                            string y;
                            cout << "Digite o nome: ";
                            getline(cin,y);
                            cout<<"\n\n";
                            cout<<juridica.itens[pesquisa_nome(juridica,op6,y)];
                        break;
                        }
                    getch();
                    system("cls");
                break;
                }
            break;
            case 10:///---------------Sai da agenda
                controle=false;
        }
   }
}
