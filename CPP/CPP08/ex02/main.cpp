/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== Tests de base (comme dans le sujet) ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Size after first pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(43);
	mstack.push(142);
	mstack.push(142);
	mstack.push(1);
	mstack.push(2);
	mstack.push(12);
	mstack.push(10);

	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "Size before second pop: " << mstack.size() << std::endl;

	mstack.pop();
	mstack.pop();

	std::cout << "Size after second pop: " << mstack.size() << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.push(0);
	mstack.push(0);

	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "Size before third pop: " << mstack.size() << std::endl;

	mstack.pop();
	mstack.pop();

	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "Size after third pop: " << mstack.size() << std::endl;


	std::cout << "Elements in stack (iterator):" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\n=== Comparaison avec std::list ===" << std::endl;
	std::list<int> lst(mstack.begin(), mstack.end());
	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
		std::cout << *lit << std::endl;

	std::cout << "\n=== Test pile vide ===" << std::endl;
	MutantStack<int> emptyStack;
	std::cout << "Empty size: " << emptyStack.size() << std::endl;
	if (emptyStack.begin() == emptyStack.end())
		std::cout << "OK: iterators handle empty stack" << std::endl;

	std::cout << "\n=== Test const MutantStack ===" << std::endl;
	const MutantStack<int> constStack(mstack);

	std::cout << "Elements in const stack (const_iterator):" << std::endl;
	for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
		std::cout << *cit << std::endl;

	return 0;
}
