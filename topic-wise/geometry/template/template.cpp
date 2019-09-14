structures:
class Point {
public:
    double x, y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
};

/**
Here, line is represented in linear standard form, ax + by = c
given two points (x1, y1) and (x2, y2)
slope, m = (y2 - y1) / (x2 - x1)
point-slope form: (y - y1) = m(x - x1)
=> (y - y1) = ((y2 - y1) / (x2 - x1)) * (x - x1)
after solving this,
x(y2 - y1) + y(x1 - x2) = x1y2 - x2y1
where,
a = y2 - y1
b = x1 - x2
c = x1y2 - x2y1
*/
class Line {
public:
    double a,b,c;
    line() {}
    line(point p1,point p2)
    {
//        a = p1.y - p2.y;
//        b = p2.x - p1.x;
//        c = p1.x * p2.y - p2.x * p1.y;

        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
    line(double _a,double _b,double _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
    double online(point p)
    {
        double ret = a * p.x + b * p.y + c;
        return ret;
    }
    void extend(point p,double s,point &p1,point &p2)
    {
        if( b == 0 )
        {

            p1 = point(p.x,p.y+s);
            p2 = point(p.x,p.y-s);
        }
        else
        {
            double dx = fabs(s*b) / sqrt( a*a + b*b );
            double dy = dx * (-a/b);
            p1 = point(p.x+dx,p.y+dy);
            p2 = point(p.x-dx,p.y-dy);
        }
    }
};

class Segment {
public:
    Point a, b;
    Segment() {}
    Segment(Point _a, Point _b)
    {
        a = _a;
        b= _b;
    }
};

class circle {
public:
    Point center;
    double r;
    circle() {}
    circle(point _c,double _r)
    {
        center = _c;
        r = _r;
    }
};

//class Polygon {
//public:
//    int n;
//    Point ara[120];
//};

Cross Product:
double cross_product(Point a, Point b, Point c)   {
    return (a.x * (b.y - c.y)) - ((a.y) * (b.x - c.x)) + ((b.x * c.y) - (c.x * b.y));
}

Orientation:
///1 ccw -1 cw 0 cc
int orientation(Point a, Point b, Point c) {
    double val = cross_product(a, b, c);
    int ret = 0;
    if(val > 0.0)ret = 1;
    else if(val < 0.0)ret = -1;
    return ret;
}
int orientation(Segment seg, Point c) {
    Point a = seg.a;
    Point b = seg.b;
    double val = cross_product(a, b, c);
    int ret = 0;
    if(val > 0.0)ret = 1;
    else if(val < 0.0)ret = -1;
    return ret;
}

Onsegment:
bool on_segment(Segment seg, Point pnt) {///works only if collinear
    if(orientation(seg, pnt) != 0)  {///means not collinear
        return false;
    }
    double mnx = min(seg.a.x, seg.b.x);
    double mxx = max(seg.a.x, seg.b.x);
    double mny = min(seg.a.y, seg.b.y);
    double mxy = max(seg.a.y, seg.b.y);
    if(((mnx <= pnt.x) && (pnt.x <= mxx)) && ((mny <= pnt.y) && (pnt.y <= mxy))){
        return true;
    }
    return false;
}

Segment Segment Intersection:
bool seg_seg_intr(Segment seg1, Segment seg2) {
    if(on_segment(seg1, seg2.a) || on_segment(seg1, seg2.b) || on_segment(seg2, seg1.a) || on_segment(seg2, seg1.b))return true;
    int o1 = orientation(seg1, seg2.a);
    int o2 = orientation(seg1, seg2.b);
    int o3 = orientation(seg2, seg1.a);
    int o4 = orientation(seg2, seg1.b);
    if (o1 != o2 && o3 != o4)return true;
    return false;
}

Point Inside Polygon:
bool point_inside_polygon(vector<Point> poly, Point pnt1)  {
    Point pnt2 = Point(pnt1.x + 30000, pnt1.y + 30000);
    int cnt = 0;///intersection count

    FOR(i, 1, (int)poly.size() - 1)   {
        if(on_segment(Segment(poly[i], poly[i - 1]), pnt1))    {
            return true;
        }
        cnt += (int)seg_seg_intr(Segment(poly[i], poly[i - 1]), Segment(pnt1, pnt2));
    }
    if(cnt % 2) return true;
    return false;
}

Point Inside Circle:
bool point_inside_circle(Circle circle, Point pnt)  {
    if(point_point_dis(circle.center, pnt) <= circle.center)    {
        return true;
    }
    return false;
}

Distance Between Two Points:
double point_point_dis(Point pnt1, Point pnt2)   {
    double x = pnt1.x - pnt2.x;
    double y = pnt1.y - pnt2.y;
    return sqrt((x * x) + (y * y));
}

Area:
double circle_area(double r)   {
    return pi * r * r;
}

Volume
double cylinder_volume(double r, double h)   {
    return pi * r * r * h;
}

int polygon_sum_of_interior_angles(int n) {
    return (n - 2) * 180;
}
int polygon_sum_of_exterior_angles() {
    return 360;
}

/**
triangle inequality: The longest side must be shorter than the sum of the rest.
polygon inequality: The longest side must be shorter than the sum of the rest.
*/
