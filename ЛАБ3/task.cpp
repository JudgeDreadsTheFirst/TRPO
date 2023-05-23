#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>

#define PI 3.14159235

class Figure
{
    protected:
        double _d1, _d2, _d3;

    public:
        Figure(double d1 = 0, double d2 = 0, double d3 = 0): _d1(d1), _d2(d2), _d3(d3) {}

        void set_dim(double d1, double d2, double d3 = 0)
        {
            this->_d1 = d1;
            this->_d2 = d2;
            this->_d3 = d3;
        }

        void get_dim(double &d1, double &d2, double &d3)
        {
            d1 = this->_d1;
            d2 = this->_d2;
            d3 = this->_d3;
        }

        virtual void name() = 0;
        virtual double volume() = 0;
};

class rectParallelepiped: public Figure
{
    // _d1 - сторона 1, _d2 - сторона 2, _d3 = сторона 3
    double volume() override 
    {
        return _d1*_d2*_d3;
    }
    
    void name()
    {
        std::cout << "I am rectangulaR parallelpiped" << std::endl;
    }
};

class rPyramid: public Figure
{
    // _d1 - сторона основания, _d2 - высота, _d3 = 0
    double volume() override
    {
        return (1.00/3.00)*((sqrt(3)/4)*(_d1*_d1))*_d2;
    }

    void name()
    {
        std::cout << "I am the right pyramid" << std::endl;
    }
};

class hollowCylinder: public Figure
{
    // _d1 - внешний радиус, _d2 - внутренний радиус, _d3 - высота
    double volume() override
    {
        return PI*(pow(_d1,2)-pow(_d2,2))*_d3;
    }

    void name()
    {
        std::cout << "I am hollow cylinder" << std::endl;
    }
};

Figure* random_object()
{
    switch(std::rand() % 3)
    {
        case 0: return new rectParallelepiped;
        case 1: return new rPyramid;
        default: return new hollowCylinder;
    }
}

int main()
{
    std::srand(std::time(0));

    Figure *fig = random_object();
    fig->name();

    if(dynamic_cast<rPyramid*>(fig) != nullptr)
    {
        double d1, d2;
        std::cout << "Input height and triangle side:" << std::endl;
        std::cin >> d1 >> d2;
        fig->set_dim(d1, d2);
    }
    else
    {
        double d1,d2,d3;
        std::cout << "Input three sides:" << std::endl;
        std::cin >> d1 >> d2 >> d3;
        fig->set_dim(d1, d2,d3); 
    }

    std::cout << "Volume of figure: " << fig->volume() << std::endl;

    return 0;
}