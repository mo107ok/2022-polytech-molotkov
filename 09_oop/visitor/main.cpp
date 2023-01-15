#include <iostream>
#include <vector>
#include <cmath>

class Rectangle;
class Circle;
class Triangle;

class Visitor {
public:
    virtual void accept(Rectangle& r) = 0;
    virtual void accept(Circle& c) = 0;
    virtual void accept(Triangle& t) = 0;

    virtual ~Visitor() = default;
};

class IElement {
public:
    virtual void visit(Visitor& v) = 0;

    virtual ~IElement() = default;
};

class Rectangle: public IElement {
public:
    Rectangle(double width, double height): width(width), height(height) {}
    void visit(Visitor& v) final {
        v.accept(*this);
    }
    int width{};
    int height{};
};

class Circle: public IElement {
public:
    explicit Circle(int radius): radius(radius) {}
    void visit(Visitor& v) final {
        v.accept(*this);
    }
    int radius;
};

class Triangle: public IElement {
public:
    Triangle(int a, int b, int c): sideA(a), sideB(b), sideC(c) {}
    void visit(Visitor& v) final {
        v.accept(*this);
    }
    int sideA{};
    int sideB{};
    int sideC{};
};


class Printer: public Visitor {
    void accept(Rectangle& r) final {
        std::cout << "Rectangle" << std::endl;
        std::cout << "Width: " << r.width << std::endl;
        std::cout << "Height: " << r.height << std::endl;
    }
    void accept(Circle& c) final {
        std::cout << "Circle" << std::endl;
        std::cout << "Radius: " << c.radius << std::endl;
    }
    void accept(Triangle& t) final {
        std::cout << "Triangle" << std::endl;
        std::cout << "Side A: " << t.sideA << std::endl;
        std::cout << "Side B: " << t.sideB << std::endl;
        std::cout << "Side C: " << t.sideC << std::endl;
    }
};

class PerimeterCalculator: public Visitor {
    void accept(Rectangle& r) final {
        std::cout << "Rectangle" << std::endl;
        std::cout << "Perimeter: " << 2 * (r.width + r.height) << std::endl;
    }
    void accept(Circle& c) final {
        std::cout << "Circle" << std::endl;
        std::cout << "Perimeter: " << 2 * 3.14 * c.radius << std::endl;
    }
    void accept(Triangle& t) final {
        std::cout << "Triangle" << std::endl;
        std::cout << "Perimeter: " << t.sideA + t.sideB + t.sideC << std::endl;
    }
};

class AreaCalculator: public Visitor {
    void accept(Rectangle& r) final {
        std::cout << "Rectangle" << std::endl;
        std::cout << "Area: " << r.width * r.height << std::endl;
    }
    void accept(Circle& c) final {
        std::cout << "Circle" << std::endl;
        std::cout << "Area: " << 3.14 * c.radius * c.radius << std::endl;
    }
    void accept(Triangle& t) final {
        std::cout << "Triangle" << std::endl;
        double p = (t.sideA + t.sideB + t.sideC) / 2.0;
        std::cout << "Area: " << sqrt(p * (p - t.sideA) * (p - t.sideB) * (p - t.sideC)) << std::endl;
    }
};


int main() {
    std::vector<IElement*> elements;

    elements.push_back(new Circle(10));
    elements.push_back(new Rectangle(5, 10));
    elements.push_back(new Triangle(3, 4, 5));

    Printer p;
    PerimeterCalculator pc;
    AreaCalculator ac;
    for(auto& el: elements) {
        el->visit(p);
        el->visit(pc);
        el->visit(ac);
    }
}