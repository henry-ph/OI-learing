#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
struct node {
	float x, y, z;
	node() {};
	node(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}
}; 
int main() {
	node a, b, c, d;
	float x, y, z;
	while (true) {
		printf("please input the first point of the first line: ");
		cin >> x >> y >> z;
		a = node(x, y, z);
		printf("please input the second point of the first line: ");
		cin >> x >> y >> z;
		b = node(x, y, z);
		printf("please input the first point of the second line: ");
		cin >> x >> y >> z;
		c = node(x, y, z);
		printf("please input the second point of the first line: ");
		cin >> x >> y >> z;
		d = node(x, y, z);
		node linea, lineb;
		linea = node(b.x - a.x, b.y - a.y, b.z - a.z);
		lineb = node(d.x - c.x, d.y - c.y, d.z - c.z);
		float cos, fenmu;
		fenmu = sqrt(linea.x * linea.x + linea.y * linea.y + linea.z * linea.z) * sqrt(lineb.x * lineb.x + lineb.y * lineb.y + lineb.z * lineb.z);
		cos = (linea.x * lineb.x + linea.y * lineb.y + linea.z * lineb.z) / fenmu;
		float ans = acos(cos);
		cout << ans << endl;
	}
	return 0;
}
