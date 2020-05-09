#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

struct Point {
	int x;
	int y;
};

enum {
	FIRST = 0,
	SECOND,
	THIRD
};

void
set_points(std::vector<Point> &points) {
	for (Point &p: points)
		std::cin >> p.x >> p.y;
}

double
euclidean_dist(const Point& a, const Point& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool
is_triangle(std::vector<Point> &points) {
	std::vector<double> lengths = {
		euclidean_dist(points[FIRST], points[SECOND]),
		euclidean_dist(points[SECOND], points[THIRD]),
		euclidean_dist(points[THIRD], points[FIRST])
	};
	std::sort(lengths.begin(), lengths.end());
	
	return (lengths[FIRST] + lengths[SECOND]) > lengths[THIRD];
}

bool
is_special_triagle(std::vector<Point> &points) {
	std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
		return (a.x == b.x ? a.y < b.y : a.x < b.x);
	});
	
	return false
		|| (points[FIRST].x == points[SECOND].x)
		|| (points[SECOND].x == points[THIRD].x);
}

int
get_ans(std::vector<Point> &points) {
	if (is_triangle(points)) {
		if (is_special_triagle(points))
			return 1;
		return 0;
	}
	return -1;
}

int
main() {
	const int N = 3;
	
	std::vector<Point> points(N);
	set_points(points);	
	
	int ans = get_ans(points);
	std::cout << ans << std::endl;
	
	return 0;
}

