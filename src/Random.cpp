#include "Random.hpp"

std::random_device Random::s_rd;
std::mt19937 Random::s_rng(s_rd());

template<>
int Random::get<int>() {
	return s_rng();
}

template<>
double Random::get<double>() {
	return static_cast<double>(s_rng()) / std::numeric_limits<unsigned int>::max();
}