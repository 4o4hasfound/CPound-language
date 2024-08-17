#pragma once
#include <vector>
#include <exception>
#include <unordered_map>
#include <initializer_list>

template<typename A, typename B, typename CompA = std::equal_to<A>, typename CompB = std::equal_to<B>, typename = std::enable_if_t<!std::is_same_v<A, B>>>
class BiUnorderedMap {
public:
	BiUnorderedMap() {

	}
	BiUnorderedMap(std::initializer_list<std::pair<A, B>> list) {
		m_listA.reserve(list.size());
		m_listB.reserve(list.size());
		for (auto ptr = list.begin(), end = list.end(); ptr != end; ++ptr) {
			insertWithoutRealloc(*ptr);
		}
	}
	BiUnorderedMap(const BiUnorderedMap<A, B>& other) {
		m_listA = other.m_listA;
		m_listB = other.m_listB;

		for (const auto& a : m_listA) {
			auto ptr = other.m_AtoB[a];
			m_AtoB[a] = &m_listB[std::distance(other.m_listB.data(), ptr)];
		}
		for (const auto& b : m_listB) {
			auto ptr = other.m_BtoA[b];
			m_BtoA[b] = &m_listA[std::distance(other.m_listA.data(), ptr)];
		}
	}
	BiUnorderedMap(BiUnorderedMap<A, B>&& other) {
		m_listA = other.m_listA;
		m_listB = other.m_listB;
		m_AtoB = other.m_AtoB;
		m_BtoA = other.m_BtoA;
	}
	BiUnorderedMap<A, B>& operator=(const BiUnorderedMap<A, B>& other) {
		m_listA = other.m_listA;
		m_listB = other.m_listB;
		m_AtoB = std::unordered_map<A, B*>();
		m_BtoA = std::unordered_map<B, A*>();

		for (const auto& a : m_listA) {
			B* ptr = other.m_AtoB.at(a);
			m_AtoB[a] = &m_listB[ptr - other.m_listB.data()];
		}
		for (const auto& b : m_listB) {
			A* ptr = other.m_BtoA.at(b);
			m_BtoA[b] = &m_listA[ptr - other.m_listA.data()];
		}
		return *this;
	}
	~BiUnorderedMap() {

	}

	A& operator[](const B& b) {
		return *(m_BtoA.at(b));
	}
	B& operator[](const A& a) {
		return *(m_AtoB.at(a));
	}
	const A& operator[](const B& b) const {
		return *(m_BtoA.at(b));
	}
	const B& operator[](const A& a) const {
		return *(m_AtoB.at(a));
	}

	int count(const A& a) const {
		return m_AtoB.count(a);
	}
	int count(const B& b) const {
		return m_BtoA.count(b);
	}

	template<typename T>
	const std::vector<T>& list() const;

	template<>
	const std::vector<A>& list<A>() const {
		return m_listA;
	}

	template<>
	const std::vector<B>& list<B>() const {
		return m_listB;
	}
private:
	std::vector<A> m_listA;
	std::vector<B> m_listB;
	std::unordered_map<A, B*, std::hash<A>, CompA> m_AtoB;
	std::unordered_map<B, A*, std::hash<B>, CompB> m_BtoA;

	void insertWithoutRealloc(const std::pair<A, B>& value) {
		m_listA.push_back(value.first);
		m_listB.push_back(value.second);
		m_AtoB[m_listA.back()] = &m_listB.back();
		m_BtoA[m_listB.back()] = &m_listA.back();
	}
};