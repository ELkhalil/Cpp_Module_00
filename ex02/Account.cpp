/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:54:18 by aelkhali          #+#    #+#             */
/*   Updated: 2023/07/12 20:23:25 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


int Account::getNbAccounts( void ){ return _nbAccounts;}
int Account::getTotalAmount( void ){ return _totalAmount;}
int Account::getNbDeposits( void ){ return _totalNbDeposits;}
int Account::getNbWithdrawals( void ){ return _totalNbWithdrawals;}

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = _nbAccounts;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" <<
    _amount << ";created" << std::endl;
    _totalAmount += _amount;
    _nbAccounts++;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" 
              << _amount << ";closed" << std::endl;
}

void    Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" 
              << _nbAccounts << ";total:" << _totalAmount << ";deposits:" 
              << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount << ";deposit:" << deposit
              << ";amount:" << _amount + deposit << ";nb_deposits:"
              << 1 << std::endl;
    _nbDeposits++;
    _totalNbDeposits += this->_nbDeposits;
    _amount += deposit;
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount << ";withdrawal:";
    if (_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    else
    {
        std::cout << withdrawal << ";amount:" << _amount - withdrawal
                  << ";nb_withdrawals:" << 1 << std::endl;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals += this->_nbWithdrawals;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    return true;
}

int		Account::checkAmount( void ) const { 
    return _amount;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount << ";deposits:"
              << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
    std::time_t now = std::time(nullptr);
    std::tm* timestamp = std::localtime(&now);

    std::cout << "[";
    std::cout << std::setfill('0') << std::setw(4) << timestamp->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_sec;
    std::cout << "] ";
}

Account::Account( void ) {}