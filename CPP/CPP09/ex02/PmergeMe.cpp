/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:12:49 by vgodart           #+#    #+#             */
/*   Updated: 2025/09/17 09:12:51 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_vectorData = src._vectorData;
        this->_dequeData = src._dequeData;
    }
    return *this;
}

template <typename Iterator>
Iterator PmergeMe::_binarySearch(Iterator begin, Iterator end, int value)
{
    Iterator low = begin;
    Iterator high = end;

    while (low < high)
    {
        Iterator mid = low + (high - low) / 2;
        
        if (*mid < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

void PmergeMe::_parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        char *endptr;
        errno = 0;
        long val = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0' || endptr == argv[i] || errno == ERANGE || val > INT_MAX || val < 0)
            throw std::invalid_argument("Error");
        
        _vectorData.push_back(static_cast<int>(val));
        _dequeData.push_back(static_cast<int>(val));
    }
}

std::vector<int> PmergeMe::_generateJacobsthal(size_t n)
{
    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);
    
    int last = 1;
    int prev = 0;
    
    while (seq.back() < (int)n)
    {
        int next = last + 2 * prev;
        seq.push_back(next);
        prev = last;
        last = next;
    }
    return seq;
}

void PmergeMe::_sortVector(std::vector<int> &arr)
{
    if (arr.size() <= 1) return;

    int straggler = 0;
    bool hasStraggler = false;
    if (arr.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);

    _sortVector(winners);

    std::vector<int> mainChain = winners;
    std::vector<int> pend;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].first == mainChain[i])
            {
                pend.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pend[0]);

    std::vector<int> jacob = _generateJacobsthal(pend.size());
    size_t insertedCount = 1;
    size_t k = 3;

    while (insertedCount < pend.size())
    {
        size_t limitIdx;
        if (k < jacob.size()) 
            limitIdx = jacob[k] - 1; 
        else 
            limitIdx = pend.size() - 1;

        if (limitIdx >= pend.size()) 
            limitIdx = pend.size() - 1;

        size_t current = limitIdx;
        while (true)
        {
            if (current < insertedCount) break;

            int val = pend[current];
            int bossVal = -1;
            for (size_t j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].second == val)
                {
                    bossVal = pairs[j].first;
                    break;
                }
            }
            
            std::vector<int>::iterator itBoss = std::find(mainChain.begin(), mainChain.end(), bossVal);
            std::vector<int>::iterator pos = _binarySearch(mainChain.begin(), itBoss, val);
            mainChain.insert(pos, val);

            if (current == insertedCount) break;
            current--;
        }
        insertedCount = limitIdx + 1;
        k++;
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator pos = _binarySearch(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    arr = mainChain;
}

void PmergeMe::_sortDeque(std::deque<int> &arr)
{
    if (arr.size() <= 1) return;

    int straggler = 0;
    bool hasStraggler = false;
    if (arr.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);

    _sortDeque(winners);

    std::deque<int> mainChain = winners;
    std::deque<int> pend;
    std::deque<bool> used(pairs.size(), false);

    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].first == mainChain[i])
            {
                pend.push_back(pairs[j].second);
                used[j] = true;
                break;
            }
        }
    }

    mainChain.push_front(pend[0]);

    std::vector<int> jacob = _generateJacobsthal(pend.size());
    size_t insertedCount = 1;
    size_t k = 3;

    while (insertedCount < pend.size())
    {
        size_t limitIdx;
        if (k < jacob.size()) 
            limitIdx = jacob[k] - 1;
        else 
            limitIdx = pend.size() - 1;

        if (limitIdx >= pend.size()) 
            limitIdx = pend.size() - 1;

        size_t current = limitIdx;
        while (true)
        {
            if (current < insertedCount) break;

            int val = pend[current];
            int bossVal = -1;
            for (size_t j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].second == val)
                {
                    bossVal = pairs[j].first;
                    break;
                }
            }
            
            std::deque<int>::iterator itBoss = std::find(mainChain.begin(), mainChain.end(), bossVal);
            std::deque<int>::iterator pos = _binarySearch(mainChain.begin(), itBoss, val);
            mainChain.insert(pos, val);

            if (current == insertedCount) break;
            current--;
        }
        insertedCount = limitIdx + 1;
        k++;
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator pos = _binarySearch(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    arr = mainChain;
}

template <typename T>
void PmergeMe::_printContainer(const T &container)
{
    size_t limit;
    limit = container.size();

    typename T::const_iterator it = container.begin();
    for (size_t i = 0; i < limit; ++i)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void PmergeMe::run(int argc, char **argv)
{
    _parseInput(argc, argv);

    std::cout << "Before: ";
    _printContainer(_vectorData);

    clock_t start = clock();
    _sortVector(_vectorData);
    clock_t end = clock();
    double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    _sortDeque(_dequeData);
    end = clock();
    double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:  ";
    _printContainer(_vectorData);

    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque  : " << deqTime << " us" << std::endl;
}