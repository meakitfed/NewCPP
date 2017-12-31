#ifndef RGB_H
#define RGB_H 

#include <iostream>

class RGB 
{
	private :
	int R;
	int G;
	int B;

	public :
    RGB(){};
    RGB(int R1, int G1, int B1) : R(R1), G(G1), B(B1){};
	void afficher(std::ostream &flux) const;
    RGB add(RGB const& b) const;
    RGB mult1(float const& a) const;
    RGB mult2(RGB const& b) const;
    void calculerRGB(const int e, const float angle, RGB ci, RGB cs);
};

void RGB::afficher(std::ostream &flux) const
{
    flux << R << " " << G << " " << B << " " ;
}

std::ostream &operator<<(std::ostream &flux, RGB const& rgb)
{
    rgb.afficher(flux) ;
    return flux;
}

//redéfinition des opérateurs pour RGB
RGB RGB::add(RGB const& b) const{
    RGB rst(this->R+b.R,this->G+b.G, this->B+b.B);
    return rst;
}

RGB operator+(RGB const& a, RGB const& b)
{
    RGB rst;
    rst = a.add(b);
    return rst;
}

RGB RGB::mult1(float const& a) const{
    RGB rst(int(a*this->R), int(a*this->G), int(a*this->B));
    if (rst.R >255)
        rst.R = 255;
    if (rst.G >255)
        rst.G = 255;
    if (rst.B >255)
        rst.B = 255;
    if (rst.R <0)
        rst.R = 0;
    if (rst.G <0)
        rst.G = 0;
    if (rst.B <0)
        rst.B = 0;
    return rst;
}

RGB operator*(float const& a, RGB const& b)
{
    RGB rst;
    rst = b.mult1(a);
    return rst;
}

RGB RGB::mult2(RGB const& b) const{
    RGB rst(int(this->R*b.R/255), int(this->G*b.G/255), int(this->B*b.B/255));
    if (rst.R >255)
        rst.R = 255;
    if (rst.G >255)
        rst.G = 255;
    if (rst.B >255)
        rst.B = 255;
    if (rst.R <0)
        rst.R = 0;
    if (rst.G <0)
        rst.G = 0;
    if (rst.B <0)
        rst.B = 0;
    return rst;
}

RGB operator*(RGB const& a, RGB const& b)
{
    RGB rst;
    rst = a.mult2(b);
    return rst;
}
#endif