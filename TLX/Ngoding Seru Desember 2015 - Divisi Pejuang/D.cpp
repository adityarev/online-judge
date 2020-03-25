#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

struct Point {
	int x;
	int y;
};

void
set_points(std::vector<struct Point> &points) {
	for (struct Point &p: points)
		std::cin >> p.x >> p.y;
}

int
get_ans(std::vector<struct Point> &points) {
	enum {
		FIRST = 0,
		SECOND,
		THIRD
	};
	
	// Not a triangle
	if (
		(points[FIRST].x == points[SECOND].x && points[SECOND].x == points[THIRD].x)
		|| (points[FIRST].y == points[SECOND].y && points[SECOND].y == points[THIRD].y)
	) {
		return -1;
	}
	
	// Special triangle
	if (
		(points[FIRST].x == points[SECOND].x && points[SECOND].x != points[THIRD].x)
		|| (points[FIRST].x != points[SECOND].x && points[SECOND].x == points[THIRD].x)
	) {
		return 1;
	}
	
	return 0;
}

int
main() {
	const int N = 3;
	
	std::vector<struct Point> points(N);
	set_points(points);	
	
	std::function<bool(const struct Point&, const struct Point&)>
	comp = [&](const struct Point &a, const struct Point &b) -> bool {
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	};
	std::sort(points.begin(), points.end(), comp);
	
	int ans = get_ans(points);
	std::cout << ans << std::endl;
	
	return 0;
}

