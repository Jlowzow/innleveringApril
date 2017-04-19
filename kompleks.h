//-------------------------------------------------------------------
//
// kompleks.h
//
// Klasse for Komplekse tall.
//
#ifndef KOMPLEKSETALL_DEFINERT
  #define KOMPLEKSETALL_DEFINERT
  #include <fstream>
  using namespace std;
  class Kompleks {
    public:
      void      sett(
                  double          nyRealdel,        // inn
                  double          nyImagdel);       // inn
      void      settRealdel(                        
                  double          nyRealdel);       // inn
      void      settImagdel(
                  double          nyImagdel);       // inn
      void      finn(
                  double         &realdelen,        // inn
                  double         &imagdelen) const; // inn
      double    finnRealdel() const;
      double    finnImagdel() const;
      Kompleks  finnKonjugert() const;
      double    finnModul() const;
      double    finnArg() const;
      Kompleks  operator+(
                  const Kompleks &detAndre) const;  // inn
      Kompleks &operator+=(
                  const Kompleks &detAndre);        // inn
      Kompleks  operator-(                                    
                  const Kompleks &detAndre) const;  // inn
      Kompleks &operator-=(
                  const Kompleks &detAndre);        // inn
      Kompleks  operator*(                                    
                  const Kompleks &detAndre) const;  // inn
      Kompleks &operator*=(
                  const Kompleks &detAndre);        // inn
      Kompleks  operator*(
                  double detAndre) const;           // inn            
      Kompleks  operator/(                                    
                  const Kompleks &detAndre) const;  // inn
      Kompleks  operator-() const;            
      Kompleks &operator/=(
                  const Kompleks &detAndre);        // inn  
      bool      operator==(
                  const Kompleks &detAndre) const;  // inn
      bool      operator!=(
                  const Kompleks &detAndre) const;  // inn  
	   bool      operator<(
                  const Kompleks &detAndre) const;  // inn  
      Kompleks  kvRot();                 
                                                          
    private:
      void settTrigForm(
                  double modul,  // inn
                  double arg);   // inn
      double imagdel;
      double realdel;
    }; // Kompleks
    
  //-----------------------------------------------------------------
  //
  // Ikke-medlemsfunksjoner 
  //
  ostream &operator<<(                            
    ostream        &ut,                     // inn/ut
    const Kompleks &tall);                  // inn
    
  //-----------------------------------------------------------------   
  istream &operator>>(
    istream        &inn,                    // inn/ut
    Kompleks       &tall);                  // inn
    
  //-----------------------------------------------------------------
  Kompleks operator*(
    double          detEne,                 // inn
    const Kompleks &detAndre);              // inn
#endif                             

