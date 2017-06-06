#ifndef ED_HPP_
#define ED_HPP_
#include <vector>
#include <string>


class ED{
public:
	ED(std::string a, std::string b);
	~ED();

	void perimeterCases();
	int penalty(char a, char b);
	int min(int& x, int& y, int& z);
	int optimalDistance();
	std::string Alignment();

	friend std::ostream& operator <<(std::ostream& left, const ED& ed);//displays grid
private:
	unsigned int m, n;
	std::string x, y;
	int **grid;
};

#endif
