// combinatorics.cpp

#include <iostream>         // for std::cout
#include <cassert>          // for assert
#include <unordered_map>    // for std::unordered_map

/*
This example contains a Combinatorics class with static methods for:
- a recursive implementation of a factorial function with memoization.
- a permutation function that calculates the permutation of n and r.
- a combination function that calculates the combination of n and r.
Adheres to SOLID principles by encapsulating related functionality and using static methods.
*/

/**
 * @class Combinatorics
 * @brief Provides static methods for common combinatorial calculations.
 *
 * This class includes methods for calculating factorials (with memoization),
 * permutations, and combinations. All methods are static and thread-safe for
 * read-only usage, but memoization uses a static cache.
 */
class Combinatorics {
public:
    /**
     * @brief Computes the factorial of a non-negative integer n using memoization.
     * @param n The non-negative integer whose factorial is to be computed.
     * @return The factorial of n (n!).
     *
     * Uses a static unordered_map to cache previously computed results for efficiency.
     * Throws no exceptions.
     */
    static unsigned long long fact(unsigned int n) {
        static std::unordered_map<unsigned int, unsigned long long> memo;
        auto it = memo.find(n);
        if (it != memo.end()) {
            return it->second;
        }
        if (n == 0 || n == 1) {
            memo[n] = 1;
            return 1;
        }
        unsigned long long result = n * fact(n - 1);
        memo[n] = result;
        return result;
    }

    /**
     * @brief Computes the number of permutations (P(n, r)) of n items taken r at a time.
     * @param n The total number of items.
     * @param r The number of items to arrange.
     * @return The number of permutations: n! / (n - r)!
     *
     * Asserts that n >= r.
     */
    static unsigned int perm(unsigned int n, unsigned int r) {
        assert(n >= r); // Defensive: n must be >= r
        return static_cast<unsigned int>(fact(n) / fact(n - r));
    }

    /**
     * @brief Computes the number of combinations (C(n, r)) of n items taken r at a time.
     * @param n The total number of items.
     * @param r The number of items to choose.
     * @return The number of combinations: n! / (r! * (n - r)!)
     *
     * Asserts that n >= r.
     */
    static unsigned int comb(unsigned int n, unsigned int r) {
        assert(n >= r); // Defensive: n must be >= r
        return static_cast<unsigned int>(fact(n) / (fact(r) * fact(n - r)));
    }
};

// Example usage (optional, can be removed if not needed)

int main() {
    std::cout << "5! = " << Combinatorics::fact(5) << std::endl;
    std::cout << "P(5, 3) = " << Combinatorics::perm(5, 3) << std::endl;
    std::cout << "C(5, 3) = " << Combinatorics::comb(5, 3) << std::endl;
    return 0;
}

