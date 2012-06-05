// 乖乖终于过了~！！！
// 注意精度问题！！！ 

#include <iostream>
#include <cmath> 
using namespace std;

// 精度容差 
const double EPS = 1e-5; 

// 允许容差的浮点数相等 
inline bool equals( double x, double y ) {
	return	fabs( x - y ) < EPS;
}

// 点结构 
struct Point {
	Point() {}
	Point( double x, double y ) : posX( x ), posY( y ) {}
	void getPoint() { cin >> posX >> posY; }
	double	posX,	posY;
};

// 判断两点是否重合 
bool cover( Point pointA, Point pointB ) {
	return	fabs( pointA.posX - pointB.posX ) +
		fabs( pointA.posY - pointB.posY ) < EPS; 
}

// 线段类 
class LineSegment {
    public:
	LineSegment() {}
	// 构造函数，两点一线 
	LineSegment( Point pA, Point pB ) : pointA( pA ), pointB( pB ) {}
	// 判别点在线的哪一侧，返回值为叉积 
	double pointOnItsSide( Point );
	// 判别点是否在线上 
	bool pointOnLine( Point );
	// 判别两线是否相交 
	friend	bool cross( LineSegment, LineSegment );
    private:
	Point	pointA,	pointB;
};

double LineSegment :: pointOnItsSide( Point point ) {
	return	( point.posX - pointA.posX ) * ( pointB.posY - pointA.posY ) -
		( point.posY - pointA.posY ) * ( pointB.posX - pointA.posX );
} 

bool LineSegment :: pointOnLine( Point point ) {
	// 若端点重合，必定相交 
	if( cover( point, pointA ) || cover( point, pointB ) ) return	true;
	// 若点在线段坐标顶点方框外，必定不相交 
	if( point.posX > pointA.posX && point.posX > pointB.posX ||
	    point.posX < pointA.posX && point.posX < pointB.posX ||
	    point.posY > pointA.posY && point.posY > pointB.posY ||
	    point.posY < pointA.posY && point.posY < pointB.posY ) return false;
	// 否则，点必定不在延长线或端点上，只要点与直线叉积非零即不在线上
	return	equals( pointOnItsSide( point ), 0.0 );
}

bool cross( LineSegment lineA, LineSegment lineB ) {
	// 若一条直线端点在另一直线上，必然相交 
	if( lineA.pointOnLine( lineB.pointA ) || lineA.pointOnLine( lineB.pointB ) ||
	    lineB.pointOnLine( lineA.pointA ) || lineB.pointOnLine( lineA.pointB ) ) return true;
	double	prod11 = lineA.pointOnItsSide( lineB.pointA ),
		prod12 = lineA.pointOnItsSide( lineB.pointB ),
		prod21 = lineB.pointOnItsSide( lineA.pointA ),
		prod22 = lineB.pointOnItsSide( lineA.pointB );
	return	prod11 * prod12 < -EPS && prod21 * prod22 < -EPS;
}

// 多边形类
class Polygon {
    public:
	Polygon() {}
	int getPolygon();
	bool isValid();
	double area(); 
    private:
	int	size; 
	Point	vertex[1000];
	LineSegment	edge[1000]; 
};

int Polygon :: getPolygon() {
	cin >> size;
	for( int i = 0; i < size; i++ )
		vertex[i].getPoint();
	for( int i = 1; i < size; i++ )
		edge[i] = LineSegment( vertex[i - 1], vertex[i] );
	edge[0] = LineSegment( vertex[size - 1], vertex[0] );
	return	size;
}

bool Polygon :: isValid() {
	if( size < 3 )
		return false;
	if( size == 3 )
		return !fabs( LineSegment( vertex[0], vertex[1] ).pointOnItsSide( vertex[2] ) ) < EPS;
	for( int j = 2; j < size - 1; j++ )
		if( cross( edge[0], edge[j] ) ) return false;
	for( int i = 1; i < size - 2; i++ )
		for( int j = i + 2; j < size; j++ )
			if( cross( edge[i], edge[j] ) )
				return false;
	return	true;
} 

double Polygon :: area() {
	double	ans = 0.0;
	if( size < 3 )	return ans;
	for( int i = 2; i < size; i++ )
		ans += edge[i].pointOnItsSide( vertex[0] );
	return	fabs( ans / 2.0 );
}

int main() {
	Polygon	Pattern;
	int	T = 1;
	cout.setf( ios :: fixed );
	cout.precision( 2 );
	while( Pattern.getPolygon() ) {
		if( T != 1 ) cout << endl;
		cout << "Figure " << T++ << ": ";
		if( !Pattern.isValid() )
			cout << "Impossible" << endl;
		else	cout << Pattern.area() << endl;
	}
}
