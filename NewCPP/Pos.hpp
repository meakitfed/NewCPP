#ifndef POS_H
#define POS_H

#include <iostream>
#include <math.h>

class Pos 
{
	private :
	float x;
	float y;
	float z;

	public :


	Pos(){};
	Pos(float x1, float y1, float z1) : x(x1), y(y1), z(z1){};
	Pos segment(Pos p2);
	float getX(){return x;}
	float getY(){return y;}
	float getZ(){return z;}
	void setX(float x){this->x = x;}
	void setY(float y){this->y = y;}
	void setZ(float z){this->z = z;}
	float distanceAvecPoint(Pos p);
	static float scal(Pos p1, Pos p2);
	static float norm(Pos p);

	void afficher(std::ostream &flux) const;
	float calculeCos(Pos vecteur2) const;


Pos& operator+=(const Pos& rhs) 
{                           
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;	
	return *this;
}
	 
friend Pos operator+(Pos lhs,const Pos& rhs) 
{
	lhs += rhs; 
	return lhs; 
}

Pos& operator-=(const Pos& rhs) 
{                           
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;	
	return *this;
}
	 
friend Pos operator-(Pos lhs,const Pos& rhs) 
{
	lhs -= rhs; 
	return lhs; 
}

Pos& operator*=(const float f) 
{                           
	x *= f;
	y *= f;
	z *= f;	
	return *this;
}
	 
	
friend Pos operator*(Pos lhs, const float f)
{
	lhs *= f; 
	return lhs;
}

friend Pos operator*(const float f, Pos lhs)
{
	lhs *= f; 
	return lhs;
}


Pos& operator/=(const float f) 
{                           
	x /= f;
	y /= f;
	z /= f;	
	return *this;
}
	 
friend Pos operator/(Pos lhs,const float f) 
{
	lhs /= f; 
	return lhs; 
}
};

void Pos::afficher(std::ostream &flux) const
{
    flux << "[x : " << x << " - y : " << y << " - z : " << z << "]";
}

Pos Pos::segment(Pos p2)
{	
	Pos p(p2.getX()-x, p2.getY()-y, p2.getZ()-z);
	return p;
} 

float Pos::distanceAvecPoint(Pos p)
{
	return sqrt(pow((x-p.getX()),2) + pow((y-p.getY()),2) + pow((z-p.getZ()),2));
}


std::ostream &operator<<(std::ostream &flux, Pos const& pos)
{
    pos.afficher(flux);
    return flux;
}

float Pos::scal(Pos p1, Pos p2)
{
 	return p1.x*p2.x+ p1.y*p2.y+ p1.z*p2.z;
}

float Pos::norm(Pos p)
{
	return sqrt(pow(p.x,2)+ pow(p.y,2)+ pow(p.z,2));
}

float Pos::calculeCos(Pos vect2) const
{
	return (scal(*this, vect2)/(norm(*this)*norm(vect2)));
}


#endif