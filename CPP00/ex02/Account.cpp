#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
  _totalAmount += initial_deposit;
  _nbAccounts++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::Account()
    : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
}

void Account::_displayTimestamp() {
  std::time_t curTime = time(NULL);
  struct std::tm *local = localtime(&curTime);
  int curr_year = local->tm_year + 1900;
  int curr_month = local->tm_mon + 1;
  int curr_day = local->tm_mday;
  int curr_hour = local->tm_hour;
  int curr_minute = local->tm_min;
  int curr_second = local->tm_sec;
  printf("[%d%d%d_%d%d%d] ", curr_year, curr_month, curr_day, curr_hour,
         curr_minute, curr_second);
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
  int p_amount = checkAmount();
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
            << ";deposit:" << deposit << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  int p_amount = checkAmount();
  if (_amount >= withdrawal) {
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
              << ";withdrawal:" << withdrawal << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return 0;
  } else {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
              << ";withdrawal:refused" << std::endl;
    return 1;
  }
}

int Account::checkAmount() const { return _amount; }

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}