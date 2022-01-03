/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:35:17 by tefroiss          #+#    #+#             */
/*   Updated: 2021/10/27 16:12:50 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "Account.hpp"

int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_nbAccounts = 0;

Account::Account(int initial_deposit)
{
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount += initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

const std::string currentDateTime() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &tstruct);

    return buf;
}

void	Account::_displayTimestamp( void )
{
	std::cout << currentDateTime();
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	if (!deposit)
		return ;
	_totalNbDeposits++;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	this->_amount = _amount + deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return(false);
	}
	_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	this->_amount = _amount - withdrawal;
	return (true);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
