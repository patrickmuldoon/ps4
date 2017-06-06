#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include "ED.hpp"

int main(int argc, char* argv[])
{
	std::string _x, _y;//_x relates to x and _y relates to y, or column


	std::cin >> _x;//1st string
	std::cin >> _y;//2nd string

	int editDistance;
	std::string edit_distance_output;

	sf::Clock clock;
	sf::Time t;

	ED ed(_x,_y);//create ED with the two string from files;

	editDistance = ed.optimalDistance();//get optimal distance or cost;

	edit_distance_output = ed.Alignment();//set output as the alignment string;

	std::cout << "Edit distance = " << editDistance << std::endl;
	std::cout << edit_distance_output << std::endl;
	//output the two strings vertically using - for gaps 

	t = clock.getElapsedTime();
	std::cout << "Time elapsed is " << t.asSeconds() << " seconds.";
	std::cout << std::endl;

	std::cout << ed << std::endl;//you can turn this comment on to see the array 
	//as long as the array is not to big to fit on the terminal output screen.

	
	return 0;

}
