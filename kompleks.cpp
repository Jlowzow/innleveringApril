//-------------------------------------------------------------------
//
// komp.cpp - implementasjon av klassen Kompleks
//        
#include <cmath>
#include "kompleks.h"   

using namespace std;

const double eps = 0.0001; // tall mindre enn dette defineres som 0. 
 
void Kompleks::sett(double nyRealdel, double nyImagdel)
{
  realdel = nyRealdel;
  imagdel = nyImagdel;
} // sett 

//-------------------------------------------------------------------
void Kompleks::settRealdel(double nyRealdel)
{
  realdel = nyRealdel;
} // settRealdel

//-------------------------------------------------------------------
void Kompleks::settImagdel(double nyImagdel)   
{
  imagdel = nyImagdel;
} // settImagdel  

//-------------------------------------------------------------------
void Kompleks::finn(double &realdelen, double &imagdelen) const   
{
  realdelen = realdel;
  imagdelen = imagdel;
} // finn 

//-------------------------------------------------------------------
double Kompleks::finnRealdel() const
{
  return realdel;
} // finnRealdel

//-------------------------------------------------------------------
double Kompleks::finnImagdel() const
{
  return imagdel;
} // finnImagdel

//-------------------------------------------------------------------
Kompleks Kompleks::finnKonjugert() const
{
  Kompleks hjelp = *this;
  hjelp.imagdel = -hjelp.imagdel;
  return hjelp;
} // finnKonjugert

//-------------------------------------------------------------------
double Kompleks::finnModul() const
{            
	return sqrt(realdel * realdel + imagdel * imagdel);
} // finnModul

//-------------------------------------------------------------------
double Kompleks::finnArg() const
{           
  double arg; 
  double pi = 4.0 * atan(1.0);
  if (fabs(realdel) >= eps) {
    arg = atan(imagdel / realdel);
    if (realdel < 0.0) {
      if (imagdel >= 0.0) arg += pi;
      else arg -= pi;
      }
    }
  else {
    if (imagdel >= 0.0) arg = pi / 2.0;
    else arg = - pi / 2.0;    
    }
  return arg;
} // finnArg

//-------------------------------------------------------------------
Kompleks Kompleks::operator+(const Kompleks &detAndre) const
//c=a+b
{
  Kompleks hjelp = *this;
  hjelp += detAndre;
  return hjelp;
} // operator+

//-------------------------------------------------------------------
Kompleks &Kompleks::operator+=(const Kompleks &detAndre)
	//a+=b     a=a+b
{ 
  realdel += detAndre.realdel;   //ar=ar+br          
  imagdel += detAndre.imagdel;	 //ai=ai+bi
  return *this;
} // operator+=

//-------------------------------------------------------------------
Kompleks Kompleks::operator-(const Kompleks &detAndre) const
{
  Kompleks hjelp = *this;
  hjelp -= detAndre;
  return hjelp;
} // operator-

//-------------------------------------------------------------------
Kompleks &Kompleks::operator-=(const Kompleks &detAndre)
{
  realdel -= detAndre.realdel;             
  imagdel -= detAndre.imagdel;
  return *this;
} // operator-=

//-------------------------------------------------------------------
Kompleks Kompleks::operator*(const Kompleks &detAndre) const
{
  Kompleks hjelp = *this;
  hjelp *= detAndre;
  return hjelp;
} // operator*

//-------------------------------------------------------------------
Kompleks &Kompleks::operator*=(const Kompleks &detAndre)
{
  double Modul = finnModul() * detAndre.finnModul();
  double Arg   = finnArg() + detAndre.finnArg();
  settTrigForm(Modul, Arg);
  return *this;                 
} // operator*=

//-------------------------------------------------------------------
Kompleks Kompleks::operator*(double detAndre) const
{                     
  Kompleks hjelp = *this;
  hjelp.realdel *= detAndre;
  hjelp.imagdel *= detAndre;    
  return hjelp;
} // operator*
  
//-------------------------------------------------------------------     
Kompleks Kompleks::operator/(const Kompleks &detAndre) const
{ 
  Kompleks hjelp = *this; 
  hjelp /= detAndre;
  return hjelp;
} // operator/

//-------------------------------------------------------------------
Kompleks &Kompleks::operator/=(const Kompleks &detAndre)
{
  double Modul = finnModul() / detAndre.finnModul();
  double Arg   = finnArg() - detAndre.finnArg();
  settTrigForm(Modul, Arg);
  return *this;
} // operator/=   
            
//-------------------------------------------------------------------
Kompleks Kompleks::operator-(void) const
{
  Kompleks hjelp;
  hjelp.realdel = -realdel;
  hjelp.imagdel = -imagdel;
  return hjelp;
} // operator-
              
//-------------------------------------------------------------------
bool Kompleks::operator==(const Kompleks &detAndre) const
{
  if (realdel == detAndre.realdel && imagdel == detAndre.imagdel) {
    return true;
    }
  else return false;
} // operator==

//-------------------------------------------------------------------
bool Kompleks::operator!=(const Kompleks &detAndre) const
{
  return (bool)(!(*this == detAndre));
} // operator!=                    

//-------------------------------------------------------------------
//bestemmer at < betyr mindre absoluttverdi
bool Kompleks::operator<(
                  const Kompleks &detAndre) const
{
	return (finnModul()<detAndre.finnModul());
}
//-------------------------------------------------------------------   
Kompleks Kompleks::kvRot()
{
  double modul = sqrt(finnModul());
  double arg = finnArg() / 2;
  Kompleks hjelp;
  hjelp.settTrigForm(modul, arg);
  return hjelp;
} // sqrt

//-------------------------------------------------------------------
void Kompleks::settTrigForm(double modul, double arg)
{
  realdel = modul * cos(arg);
  imagdel = modul * sin(arg);
} // settTrigForm  

//-------------------------------------------------------------------
//
// Ikke-medlemsfunksjoner
  
//-------------------------------------------------------------------
ostream &operator<<(ostream &ut, const Kompleks &tall)
{
  double re = tall.finnRealdel();
  double im = tall.finnImagdel();
  if (fabs(re) >= eps) {
    ut << re;
    if (im >= eps) ut << " + " << im << "i ";
    else if (im <= -eps) ut << " - " << -im << "i ";
    }
  else if (fabs(im) >= eps) ut << im << "i ";
  else ut << 0;  
  return ut;
} // operator<<
    
//-------------------------------------------------------------------   
istream &operator>>(istream &inn, Kompleks &tall)
{
  double realdel;
  double imagdel;
  inn >> realdel;
  inn >> imagdel;
  tall.sett(realdel, imagdel);
  return inn; 
} // operator>>          

//-------------------------------------------------------------------
Kompleks operator*(double detEne, const Kompleks &detAndre)
{
  return detAndre * detEne;
} // operator*  



