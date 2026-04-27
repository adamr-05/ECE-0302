#include "State.hpp"

template <typename T>
State<T>::State(const T &val, std::size_t path_cost, std::size_t heur)
    : value(val), g(path_cost), h(heur) {
  f = g + h;
}

template <typename T> T State<T>::getValue() const { return value; }

template <typename T> void State<T>::updatePathCost(std::size_t cost) {
  g = cost;
  f = g + h;
}

template <typename T> std::size_t State<T>::getPathCost() const { return g; }

template <typename T> std::size_t State<T>::getFCost() const { return f; }
