#include "ED.hpp"
#include <vector>
#include <iostream>
#include <string>

const int MATCH = 0;
const int GAP = 2;
const int SWITCH = 1;

ED::ED(std::string a, std::string b) : x(a), y(b)
{
	x.append("-");
	y.append("-");

	m = x.length();
	n = y.length();

	grid = new int*[m];
	for (unsigned int i = 0; i < m; i++)
	{
		grid[i] = new int[n];
	}
}

ED::~ED()
{
	for (unsigned int i = 0; i < m; i++)
	{
		delete [] grid[i];
	}

	delete grid;
}

void ED::perimeterCases()
{
	for (unsigned int i = m; i > 0; i--)
	{
	
		for (unsigned int j = n; j > 0; j--)
		{

			if(i == m)
				grid[i-1][j-1] = (n - j) * GAP;//makes bottom row

			if(j == n)
				grid[i-1][j-1] = (m - i) * GAP;//makes rightmost column
		}
	}
}

int ED::penalty(char a, char b)
{
	return ((a == b)) ? MATCH : SWITCH;
	
}

int ED::min(int& a, int& b, int& c)
{
	if(a < b)
		return (a < c) ? a : c;//if a is less than c return a, else return c
	return (b < c) ? b : c;//if b is less than c return b, else return c
}

int ED::optimalDistance()
{
	int optDistance;
	perimeterCases();

	for(unsigned int i = m -1; i > 0; i--)
	{
		for(unsigned int j = n-1; j > 0; j--)
		{
			int bottom = grid[i][j-1] + GAP;
			int right = grid[i-1][j] + GAP;
			int diagonal = grid[i][j] + (penalty(x.at(i-1), y.at(j-1)));

			optDistance = min (right, bottom, diagonal);//find the smallest cost
			grid[i-1][j-1] = optDistance;
		}
	}

	return optDistance;
}

std::string ED::Alignment()
{
	std::string result;

	unsigned int i = 0, j = 0;

	int *current = &grid[i][j];
	int *right = &grid[i][j+1];
	int *bottom = &grid[i+1][j];
	int *diagonal = &grid[i+1][j+1];

	int *correctptr;//current;

	while(i < m-1 || j < n-1)
	{
		//check to see if the current number and right number = 2
		if(j < n-1 && (*current - *right) == GAP)
		{
			result.append("-");//x is a gap
			result.append(" ");
			result.push_back(y.at(j));//y is a letter
			result.append(" ");
			result.append("2");//save the cost
			result.append("\n");
			correctptr = right;
			j++;
		}
		else if(i < m-1 && (*current - *bottom) == GAP)
		{
			result.push_back(x.at(i));//x is a letter
			result.append(" ");
			result.append("-");//y is a gap
			result.append(" ");
			result.append("2");//save the cost
			result.append("\n");
			correctptr = bottom;
			i++;
		}
		else if(penalty(x.at(i), y.at(j)) == (*current - *diagonal))
		{
			result.push_back(x.at(i));//x is a letter
			result.append(" ");
			result.push_back(y.at(j));//y is a letter
			result.append(" ");
			if(*current - *diagonal == SWITCH)
				result.append("1");//save the cost
			if(*current - *diagonal == MATCH)
				result.append("0");//save the cost
			result.append("\n");
			correctptr = diagonal;
			i++;
			j++;
		}
		//update pointers based on new current pointer
		current = correctptr;
		right = &grid[i][j+1];
		bottom = &grid[i+1][j];
		diagonal = &grid[i+1][j+1];
	}
	return result;
}

std::ostream& operator <<(std::ostream& left, const ED& ed)
{
	std::cout << std::endl;
	std::cout << "   ";
	for(unsigned int i = 0; i < ed.n; i++)
	{
		std::cout << "   " << std::left << ed.y.at(i);
	}
	std::cout << std::endl;

	for(unsigned int i = 0; i < ed.m; i++)
	{
		std:: cout << std:: endl << ed.x.at(i) << "   ";
		for(unsigned int j = 0; j < ed.n; j++)
		{
			if(ed.grid[i][j] > 9)
				std::cout << "  " << std::left << ed.grid[i][j];//make two spaces if the grid number is 2 digits
			else
				std::cout << "   " << std::left << ed.grid[i][j];//make 3 spaces if the grid is a single digit
		}
	}
	std::cout << std::endl << std::endl;
	return left;
}
