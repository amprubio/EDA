#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

class Set {
	// Conjuntos de enteros representados como vectores ordenados sin repeticiones
public:
	class Hora {
	private:
		int h_;
		int min_;
		int secs_;
	public:
		Hora() : h_(0), min_(0), secs_(0) {};
		Hora(int h, int m, int s) : h_(h), min_(m), secs_(s) {}

		void print() const {
			std::cout << std::setfill('0') << std::setw(2) << h_ << ":" << std::setfill('0') << std::setw(2) << min_ << ":" << std::setfill('0') << std::setw(2) << secs_ << "\n";
		}

		bool isIncorrect() {
			return (h_ > 23 || min_ > 59 || secs_ > 59);
		}

		bool operator< (const Hora& h) const {
			if (h_ == h.h_) {
				if (min_ == h.min_) {
					return secs_ < h.secs_;
				}
				else return min_ < h.min_;
			}
			else return h_ < h.h_;
		}

		bool operator<= (Hora h) const {
			if (h_ == h.h_) {
				if (min_ == h.min_) {
					if (secs_ == h.secs_) return true;
					else return secs_ < h.secs_;
				}
				else return min_ < h.min_;
			}
			else return h_ < h.h_;
		}

		bool operator>= (Hora h) const {
			if (h_ == h.h_) {
				if (min_ == h.min_) {
					if (secs_ == h.secs_) return true;
					else return secs_ > h.secs_;
				}
				else return min_ > h.min_;
			}
			else return h_ > h.h_;
		}

		bool operator== (const Hora& h) const {
			return (h.h_ == h_ && h.min_ == min_ && h.secs_ == secs_);
		}
	};

	Set(int size) { size_ = size; }

	bool isEmpty() const { return (size_ == 0); }

	int size() { return size_; }

	void add(Hora h) {
		if (h.isIncorrect()) throw "Hora inválida";
		else elems.push_back(h);
	}

	void findClosestHour(const Hora& x) const {
		if (elems.size() == 1) {
			if (elems[0] >= x) elems[0].print();
			else std::cout << "NO\n";
		}

		else findClosestHourAux(x, 0, elems.size() - 1);
	}

	void findClosestHourAux(const Hora& x, int a, int b) const {
		int m;

		if (a == elems.size() - 1) std::cout << "NO\n";

		else if (a <= b) {
			m = (a + b) / 2;
			if (elems[m] < x && elems[m + 1] >= x) elems[m + 1].print();
			else if (elems[m] < x)
				findClosestHourAux(x, m + 1, b);
			else
				findClosestHourAux(x, a, m - 1);
		}
		else elems[a].print();
	}

private:
	std::vector<Hora> elems;
	int size_;
};


std::istream& operator>>(std::istream& sIn, Set& set)
{
    int h, m, s;
    char aux;
    for (int k = 0; k < set.size(); k++) {
        std::cin >> h >> aux >> m >> aux >> s;
        set.add(Set::Hora(h, m, s));
    }
    return sIn;
}