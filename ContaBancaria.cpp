#include <iostream>
#include <string>

using namespace std;
class ContaBancaria {
private:
  // dados da conta bancária, privados por segurança
  string numeroConta;
  string nomeTitular;
  double saldo;

public:
  // construtor da classe
  ContaBancaria(string numeroConta, string nomeTitular, double saldoInicial) {
    this->numeroConta = numeroConta;
    this->nomeTitular = nomeTitular;
    if (saldoInicial >= 0) {
      this->saldo = saldoInicial;
    } else {
      this->saldo = 0;
      cout << "Saldo inicial não pode ser negativo, saldo inicial zerado."
           << endl;
    }
    cout << "Conta bancária criada para " << nomeTitular
         << " com número de conta " << numeroConta << " e saldo inicial de $"
         << saldo << endl;
  }

  void depositar(double valor) {
    if (valor > 0) {
      saldo += valor;
      cout << "Deposito de $" << valor << " realizado com sucesso!" << endl;
    } else {
      cout << "Deposito deve ser positivo, deposito ignorado." << endl;
    }
  }

  void sacar(double valor) {
    if (valor > 0) {
      if (saldo >= valor) {
        saldo -= valor;
        cout << "Saque de $" << valor << " realizado com sucesso!" << endl;
      } else {
        cout << "Saldo insuficiente para saque de $" << valor
             << "! Saldo atual: $" << saldo << endl;
      }
    } else {
      cout << "Saque deve ser positivo, saque ignorado." << endl;
    }
  }

  double getSaldo() const { return saldo; }

  void exibirInformacoes() const {
    cout << "Nome do titular: " << nomeTitular << endl;
    cout << "Número da conta: " << numeroConta << endl;
    cout << "Saldo atual: $" << saldo << endl;
  }
};
int main() {
  // criação de um objeto ContaBancaria
  ContaBancaria conta("123456", "Joaquim", 1000.0);

  // uso de métodos do objeto
  conta.exibirInformacoes();
  conta.depositar(500.0);
  conta.sacar(200.0);
  cout << "Saldo atual: $" << conta.getSaldo() << endl;

  // criação de outro objeto
  ContaBancaria conta2("789012", "Maria", -100.0);
  conta2.exibirInformacoes();

  conta2.depositar(-200.0);
  conta2.sacar(300.0);
  cout << "Saldo atual: $" << conta2.getSaldo() << endl;

  return 0;
}
