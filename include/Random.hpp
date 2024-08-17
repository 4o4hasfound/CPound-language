#pragma once
#include <random>
#include <cstdint>
#include <limits>

class Random {
public:
	template<typename T>
	static T get();

	template<>
	static int get<int>();
	template<>
	static double get<double>();
private:
	Random() = delete;

	static std::random_device s_rd;
	static std::mt19937 s_rng;
};