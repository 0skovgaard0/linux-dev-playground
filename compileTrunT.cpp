// Experimenting with simple funcs, params, and vars to focus on compile time
// when possible!


#include <iostream>
#include <string>


class CompTime {
public:
	CompTime(const std::string& s) : s(s);

	void welcomePrint() const {
		std::cout << "Welcome to the castle of opportuss! Number of seats: " << numSeats << std:endl;
	}

	constexpr int SeatsLeft(int guests) const {
		return numSeats - guests;
	}

	void checkGuests(int guests) const {
		if (guests < 0) || (guests > numSeats)) {
			std::cout << "Go home, there is a bug!\n";
		} else {
			std::cout <<"Seats left: " << numSeats - guests << "\n";
		}



private:
	std::string str;
	int x = 0;

	const int numSeats = 10;

}


int main() {	
	CompTime s("This is fun");

	s.welcomePrint();

	SeatsLeft("8");

	
	return 0;
}
