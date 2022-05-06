#include <iostream>
#include <string>

class BankAccount {
private:
  int accountNumber_;
  int funds_;
  std::string holderName_;

public:
  BankAccount(int accountNumber, int funds, std::string holderName);

  int GetAccountNumber() const { return accountNumber_; }
  int GetFunds() const { return funds_; }
  std::string GetHolderName() const { return holderName_; }

  void SetAccountNumber(int newAccountNumber);
  void SetFunds(int newFunds);
  void SetHolderName(std::string newHolderName);
};

BankAccount::BankAccount(int accountNumber, int funds, std::string holderName)
    : accountNumber_(accountNumber), funds_(funds), holderName_(holderName) {}

void BankAccount::SetAccountNumber(int newAccountNumber) {
  accountNumber_ = newAccountNumber;
}

void BankAccount::SetFunds(int newFunds) { funds_ = newFunds; }

void BankAccount::SetHolderName(std::string newHolderName) {
  holderName_ = newHolderName;
}

int main() {
  BankAccount exampleAccount(1, 0, "Jonathan");
  std::cout << exampleAccount.GetAccountNumber() << "\n"
            << exampleAccount.GetFunds() << "\n"
            << exampleAccount.GetHolderName() << "\n";
}