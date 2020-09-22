#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    float x = 0;
    float y = 0;
public:
    Point (float x, float y) : x(x), y(y) { }
    Point () = default;

    /// <Summary>
    /// X component of the vector.
    /// </Summary>
    float getX() const {
        return x;
    }

    /// <Summary>
    /// Y component of the vector.
    /// </Summary>
    float getY() const {
        return y;
    }

    /// <Summary>
    /// Returns the length of this vector.
    /// </Summary>
    float distance() const {
        return sqrt(x * x + y * y);
    }

    friend istream& operator >> (istream& in, Point& data) {
        float newX = data.x;
        float newY = data.y;
        string xChars;
        string yChars;
        bool isCorrectFormat = true;
        in >> xChars;
        in >> yChars;
        if (xChars.front() == '(' && xChars.back() == ',') {
            xChars = xChars.substr(1, xChars.length() - 2);
            newX = stof(xChars);
        }
        else {
            isCorrectFormat = false;
        }
        if (yChars.back() == ')') {
            yChars.pop_back();
            newY = stof(yChars);
        }
        else {
            isCorrectFormat = false;
        }

        if (isCorrectFormat) {
            data.x = newX;
            data.y = newY;
        }
        return in;
    }

    friend ostream& operator << (ostream& out, Point& data) {
        out << '(' << data.x << ", " << data.y << ')';
        return out;
    }
};

int main() {
    Point p1 = Point(1, 2), p2;
    cout << p1 << endl;	// вывод на экран (1, 2)
    cout << p2 << endl; 	// вывод на экран (0, 0)
    cin >> p2; 	// вводим (10.5, 7.9)
    cout << p2 << endl; 	// выводим (10.5, 7.9)
    cin >> p1;  	// вводим 5 9
    cout << p1 << endl;
    // выводим (1, 2) -- формат точки неверный, поэтому p1 не меняется

}
