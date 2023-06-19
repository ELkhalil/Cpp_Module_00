/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:48:34 by aelkhali          #+#    #+#             */
/*   Updated: 2023/06/19 14:47:39 by aelkhali         ###   ########.fr       */
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

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const
{
    return _amount;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t now = std::time(nullptr);
    std::tm* timestamp = std::localtime(&now);

    std::cout << "[" << std::setfill('0') << std::setw(4) << timestamp->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_sec;
    std::cout << "] ";
}

/*
Sure! Let's break down the _displayTimestamp function step by step:

std::time_t now = std::time(nullptr);

This line retrieves the current system time and stores it in the variable now. std::time is a function from the <ctime> header that returns the current system time as the number of seconds since January 1, 1970 (also known as Unix timestamp).
std::tm* timestamp = std::localtime(&now);

The std::localtime function takes the system time (now) and converts it into a structure of type std::tm representing the local time. This structure holds information about the year, month, day, hour, minute, and second.
The following lines use std::cout to print the timestamp in a specific format:

std::cout << "[" << std::setfill('0') << std::setw(4) << timestamp->tm_year + 1900;
This line prints the year. std::setfill('0') ensures that if the year is less than four digits, leading zeros are added. std::setw(4) specifies that the output should occupy four characters.
std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mon + 1;
This line prints the month. Similar to the previous line, it adds leading zeros if necessary.
std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_mday << "_";
This line prints the day of the month followed by an underscore.
std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_hour;
This line prints the hour.
std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_min;
This line prints the minute.
std::cout << std::setfill('0') << std::setw(2) << timestamp->tm_sec;
This line prints the second.
std::cout << "] ";
Finally, this line prints a closing bracket followed by a space.
By combining the different elements of the timestamp (year, month, day, hour, minute, second) in a specific format, the _displayTimestamp function generates a string representing the current timestamp. This string is then printed to the console using std::cout.

*/