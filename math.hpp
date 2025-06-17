#ifndef MATH_HPP
#define MATH_HPP

#include <cstdint>

template <typename T>
struct vec2_t {
	bool operator==(const vec2_t<T>& other) const {
		return x == other.x && y == other.y;
	}
	bool operator!=(const vec2_t<T>& other) const {
		return x != other.x || y != other.y;
	}

	vec2_t<T> operator+(const vec2_t<T>& other) const {
		return { x + other.x, y + other.y };
	}

	vec2_t<T> operator-(const vec2_t<T>& other) const {
		return { x - other.x, y - other.y };
	}

	vec2_t<T> operator/(const vec2_t<T>& other) const {
		return { x / other.x, y / other.y };
	}

	vec2_t<T> operator*(const vec2_t<T>& other) const {
		return { x * other.x, y * other.y };
	}

	void operator+=(const vec2_t<T>& other) {
		x += other.x;
		y += other.y;
	}

	void operator-=(const vec2_t<T>& other) {
		x -= other.x;
		y -= other.y;
	}

	void operator/=(const vec2_t<T>& other) {
		x /= other.x;
		y /= other.y;
	}

	void operator*=(const vec2_t<T>& other) {
		x *= other.x;
		y *= other.y;
	}

	T x, y;
};

using vec2i_t = vec2_t<std::int32_t>;

#endif  // MATH_HPP