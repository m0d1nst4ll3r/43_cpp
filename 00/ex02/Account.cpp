#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors

Account::Account( void )
	: _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
}

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created\n";
}

// Destructors

Account::~Account( void )
{
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed\n";
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
}

// Private

void	Account::_displayTimestamp( void )
{
	const time_t	timestamp = time(NULL);
	const struct tm	*datetime = localtime(&timestamp);
	char			buffer[18]; // [YYYYMMDD-HHMMSS] + '\0'
	strftime(buffer, sizeof(buffer), "[%Y%m%d-%H%M%S]", datetime);
	std::cout << buffer;
}

// Public

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	if (_nbAccounts == 0)
		return ;
	_displayTimestamp();
	std::cout
		<< " accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< '\n';
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits + 1
		<< '\n';
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused\n";
		return (false);
	}
	std::cout << withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << _nbWithdrawals + 1
		<< '\n';
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

/* Don't know what this is used for
int		Account::checkAmount( void ) const
{
}*/

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< '\n';
}
