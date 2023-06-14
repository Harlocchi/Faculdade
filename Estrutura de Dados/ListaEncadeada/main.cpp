#include <iostream>
#include <array>
#include <stdio.h>
#include <string>

using namespace std;


typedef struct prato {
    string nome;
    int id;
    double Price;
} aluno;

typedef struct no {
    prato pr;
    struct no *proximo;
};

typedef struct lista {
    no *inicio;
    int tam;
};

void add_list(lista *l, prato al) {

    no *novo = new no;
    novo->pr = al;

    if (l->inicio == nullptr) {

        l->inicio = novo;
        l->tam++;

    } else {
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    }


}


prato construct_aluno(string nome, int id, double price) {
    prato aux;
    aux.id = id;
    aux.nome = nome;
    aux.Price = price;
    return aux;
}


void imprime_list(lista *l) {
    no *aux = l->inicio;

    if (l->tam == 0) {
        cout << "lista esta vazia";
    } else {
        for (int i = 0; i < l->tam; i++) {
            cout << "\t\t\t |" << "--> Nome: " << aux->pr.nome << endl;
            cout << "\t\t\t |" << "ID: " << aux->pr.id << endl;
            cout << "\t\t\t |" << "Price: R$" << aux->pr.Price << endl;
            cout << "\t\t\t |" << "========================================" << endl;
            aux = aux->proximo;
        }
    }
}

prato encontraPrato(lista *l, string nome) {

    no *aux = l->inicio;

    for (int i = 0; i < l->tam; i++) {
        if (aux->pr.nome == nome) {
            return aux->pr;
        } else {
            aux = aux->proximo;
        }
    }


};

bool valida_id(lista *l, int id) {

    no *aux = l->inicio;

    for (int i = 0; i < l->tam; i++) {
        if (aux->pr.id == id) {
            return true;
        }
        return false;

    }
}


int main() {

    setlocale(LC_ALL, "");
    lista *list = new struct lista;
    list->inicio = NULL;
    list->tam = 0;
    int choose, vetcrsTam = 0;
    double price;
    prato al1;
    string name;
    double carteira = 100;
    bool validation, passagem = false;


    while (true) {

        system("cls");
        cout << "qual q dado vc quer mexer?      " << "carteira: R$" << carteira << endl;
        cout << "[1] - manter Cardapio" << endl;
        cout << "[2] - Comprar" << endl;
        cout << "[0] - sair" << endl;
        cin >> choose;

        if (choose == 1) {                                  //modificar aluno
            system("cls");
            cout << "oque voce quer fazer?" << endl;
            cout << "[1] - Adicionar" << endl;
            cout << "[2] - alterar" << endl;
            cout << "[3] - excluir" << endl;
            cout << "[4] - listar" << endl;
            int escolha;
            cin >> escolha;

            switch (escolha) {                          //adicionar aluno
                case 1:
                    system("cls");
                    cout << "OK, voce escolheu adicionar" << endl;
                    cout << "mas vamos precisar de alguns dados" << endl;
                    cout << endl;
                    cout << "nome: " << endl;
                    cin >> name;
                    cout << "id: " << endl;
                    passagem = false;
                    do {

                        passagem = true;
                        int id;
                        cin >> id;
                        validation = valida_id(list, id);

                    } while (validation);
                    cout << "valor";
                    cin >> price;
                    cout << endl;
                    int id;
                    al1 = construct_aluno(name, id, price);
                    add_list(list, al1);
                    cout << "prato adicionado com sucesso";
                    break;

                case 2:
                    cout << "Modificar";
                    break;
                case 3:
                    cout << "Excluir";
                    break;
                case 4:
                    imprime_list(list);
                    system("pause");
                    break;
                default:
                    cout << "escolha inválida";
                    break;
            }
        } else if (choose == 2) {
            system("cls");
            cout << "Legal, Voce quer comprar uma refeicao, oque vc quer?";
            cout << endl;

            if (list->tam != 0) {
                imprime_list(list);
                cout << endl;
                cout << "escreva o nome da qual vc quer comprar: ";
                string cmp;
                cin >> cmp;
                prato prat = encontraPrato(list, cmp);
                if (carteira < prat.Price) {
                    cout << "voce nao tem dinheiro o suficiente" << endl;
                } else {
                    carteira -= prat.Price;
                    cout << "compra realizada com sucesso";
                }
                system("pause");
            } else {
                cout << "não temos pratos no memento" << endl;
            }

        } else {
            cout << "comando invalido";
        }
    }
}
