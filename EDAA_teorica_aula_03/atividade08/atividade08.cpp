// Atividade 8: Preço por Condição de Pagamento
// Calcula o valor final de um produto usando switch com base nas 4 condições de pagamento da tabela.

#include <iostream>
using namespace std;

int main() {
    float precoEtiqueta, valorFinal;
    int condicao;

    cout << "Digite o preco normal de etiqueta: R$ ";
    cin >> precoEtiqueta;

    cout << "--- Condicao de Pagamento ---" << endl;
    cout << "1 - A vista em dinheiro/cheque (10% desconto)" << endl;
    cout << "2 - A vista no cartao de credito (5% desconto)" << endl;
    cout << "3 - Em 2x (preco normal)" << endl;
    cout << "4 - Em 3x (preco normal + 10% juros)" << endl;
    cout << "Escolha a condicao (1-4): ";
    cin >> condicao;

    switch (condicao) {
        case 1:
            valorFinal = precoEtiqueta - (precoEtiqueta * 0.10);
            cout << "Valor a pagar: R$ " << valorFinal << endl;
            break;
        case 2:
            valorFinal = precoEtiqueta - (precoEtiqueta * 0.05);
            cout << "Valor a pagar: R$ " << valorFinal << endl;
            break;
        case 3:
            valorFinal = precoEtiqueta;
            cout << "Valor a pagar: 2 parcelas de R$ " << valorFinal / 2.0 << " (Total: R$ " << valorFinal << ")" << endl;
            break;
        case 4:
            valorFinal = precoEtiqueta + (precoEtiqueta * 0.10);
            cout << "Valor a pagar: 3 parcelas de R$ " << valorFinal / 3.0 << " (Total: R$ " << valorFinal << ")" << endl;
            break;
        default:
            cout << "Condicao de pagamento invalida!" << endl;
            break;
    }

    return 0;
}