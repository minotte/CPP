#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	std::cout << "index:" << this->_accountIndex;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += _amount;
	std::cout << ";amount:" << Account::checkAmount() << ";created" << std::endl;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";amount:" << this->_amount << ";closed" << std::endl;
	return;
}

/* ------------ Getter  ------------------ */

int	Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )	{
	return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const{
	return (_amount);
}
/* ------------ SETTER -------------------- */

void	Account::makeDeposit( int deposit )	{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex; 
	std::cout << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	_totalNbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex; 
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal < _amount)
	{
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (0);
	}
	else{
		std::cout << ";withdrawal:refused" << std::endl;
		return (1);
	}
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount; 
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;

}

void	Account::_displayTimestamp( void )
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];
	
	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,80,"[%Y%m%d_%H%M%S] ",timeinfo);
	std::cout << buffer;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
