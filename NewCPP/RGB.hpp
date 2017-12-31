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
	void afficher(std::ostream &flux) const;
    RGB add(RGB const& b) const;
    RGB mult1(float const& a) const;
    RGB mult2(RGB const& b) const;
    void calculerRGB(const int e, const float angle, RGB ci, RGB cs);

	RGB(){};
	RGB(int R1, int G1, int B1) : R(R1), G(G1), B(B1){};
};

void RGB::afficher(std::ostream &flux) const
{
    flux << R << " " << G << " " << B  ;
}

std::ostream &operator<<(std::ostream &flux, RGB const& rgb)
{
    rgb.afficher(flux) ;
    return flux;
}

RGB RGB::add(RGB const& b) const{
    RGB rst(this->R+b.R,this->G+b.G, this->B+b.B);
    return rst;
}

//Esperons que ce soit transitif
RGB operator+(RGB const& a, RGB const& b)
{
    RGB rst;
    rst = a.add(b);
    return rst;

    // Calcul des valeurs des attributs de resultat

}

/*void RGB::calculerRGBReflexion(const int e, const float angle,const RGB cr,const RGB cs, const float reflx)
{
    r = (1 - reflx)*r + reflx*e*cos(angle)*(cr.R*cs.R)/255;
    g = (1 - reflx)*g + reflx*e*cos(angle)*(cr.G*cs.G)/255;
    b = (1 - reflx)*b + reflx*e*cos(angle)*(cr.B*cs.B)/255;
}

void RGB::reflexiondansleneant(RGB c, float reflx)
{
    r = (1 - reflx)*r + reflx*c.R;
    g = (1 - reflx)*g + reflx*c.G;
    b = (1 - reflx)*b + reflx*c.B;
}*/


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
    // Calcul des valeurs des attributs de resultat

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
    // Calcul des valeurs des attributs de resultat

    return rst;
}


#endif