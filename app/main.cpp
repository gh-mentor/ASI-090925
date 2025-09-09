#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>

namespace Lambda {
	/**
	 * LambdaGen provides generators for square and cube lambda functions.
	 */
	class LambdaGen {
	public:
		/**
		 * Returns a lambda that squares a double.
		 * @return std::function<double(double)> that computes the square.
		 */
		static std::function<double(double)> SqrGen() {
			return [](double x) { return x * x; };
		}

		/**
		 * Returns a lambda that cubes a double.
		 * @return std::function<double(double)> that computes the cube.
		 */
		static std::function<double(double)> CubeGen() {
			return [](double x) { return x * x * x; };
		}
	};
}

int main() {
	using namespace Lambda;
	std::vector<std::function<double(double)>> funcList;
	std::vector<double> numbers;
	double input = 0.0;
	std::cout << "Enter up to 10 real numbers (-1 to stop):\n";
	while (numbers.size() < 10) {
		std::cout << "Number " << (numbers.size() + 1) << ": ";
		if (!(std::cin >> input)) {
			std::cerr << "Invalid input. Exiting.\n";
			return 1;
		}
		if (input == -1.0) break;
		numbers.push_back(input);
	}

	funcList.push_back(LambdaGen::SqrGen());
	funcList.push_back(LambdaGen::CubeGen());

		std::cout << std::fixed << std::setprecision(4);
	for (const auto& n : numbers) {
		try {
			double sq = funcList[0](n);
			double cb = funcList[1](n);
			std::cout << "n: " << n << "\tSquared: " << sq << "\tCubed: " << cb << "\n";
		} catch (const std::exception& e) {
			std::cerr << "Error computing values: " << e.what() << std::endl;
		}
	}
	return 0;
}
