/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:12:49 by vgodart           #+#    #+#             */
/*   Updated: 2025/09/17 09:12:51 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include <cstdlib>
# include <climits>
# include <utility>
# include <stdexcept>
# include <cerrno>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        void run(int argc, char **argv);

    private:
        std::vector<int>    _vectorData;
        std::deque<int>     _dequeData;

        void                _parseInput(int argc, char **argv);
        std::vector<int>    _generateJacobsthal(size_t n);
        
        void                _sortVector(std::vector<int> &arr);
        void                _sortDeque(std::deque<int> &arr);

        template <typename T>
        void                _printContainer(const T &container);

        template <typename Iterator>
        Iterator            _binarySearch(Iterator begin, Iterator end, int value);
};

#endif