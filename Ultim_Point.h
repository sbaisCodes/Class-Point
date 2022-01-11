#include<iostream>
#include<cstdlib>
#include<cstring>


#ifndef TPOINT_H
#define TPOINT_H

using namespace std;
// PARTIE 1
class Tpoint{
	private: 
	   double x; 
	   double y;
	   
	public: 
	// forme canonique 
	   Tpoint(){
	   	x = 0;
	   	y = 0;
	   };
	   Tpoint(const Tpoint&p){
	   	x = p.x;
	   	y = p.y;
	   };
	   virtual ~Tpoint(){};
	   Tpoint& operator=(const Tpoint&TP){
	   	x = TP.x;
	   	y = TP.y;
	   };
	// constructeur generique 
	   Tpoint(double xx, double yy){
	   	x = xx; y = yy;
	   }
	//setters 
	
	void setX(double xx){
 		x = xx ;
	}
	
	void setY(double yy){
 		y = yy ;
	}
	
	// surcharge de l'operateur de sortie 
	
	friend ostream& operator<<(ostream& out, Tpoint& Tpo){
	
	out<< ">absisse : "<< Tpo.x <<"\n>ordonne : "<< Tpo.y<<endl;
	return out;
}
	
	
	
	
	
};




// PARTIE 2
class TObjetGraphique{
	private: 
	   Tpoint origine;
	   int StyleLine;
	   char* couleur;
	
	public: 
	// forme de coplien : canonique
	     TObjetGraphique():origine(){
	     	
	     	//origine.setX(0);
	     	//origine.setY(0);
	     	char* col = " ";
	     	StyleLine = 0;
	     	couleur = (char*)malloc(sizeof(col));
	     	strcpy(couleur, col);
		 };
	     virtual ~TObjetGraphique(){ // no need for virtual 
	     	free(couleur);
		 };
	     TObjetGraphique(const TObjetGraphique& objGraf){
	     	// const in the middle means the object is constant: will not change
	     	origine = objGraf.origine;
	     	StyleLine = objGraf.StyleLine;
	     	couleur = (char*)malloc(sizeof(objGraf.couleur));
	     	strcpy(couleur, objGraf.couleur);
		 };
		 // = operator is pretty similar to copy constructor
	     TObjetGraphique& operator=(const TObjetGraphique&objGraf){
	     	
	     	origine = objGraf.origine;
	     	StyleLine = objGraf.StyleLine;
	     	couleur = (char*)malloc(sizeof(objGraf.couleur));
	     	strcpy(couleur, objGraf.couleur);
		 };
	  
	// getters 
	// easy to do
	
	// setters
	// easy
	
	// question a 
	// constructeur generique
	TObjetGraphique(Tpoint P, int style, char* color){
		origine = P;
		StyleLine = style;
		couleur = (char*)malloc(sizeof(color));
	    strcpy(couleur, color);
	};
	
	// question a
	// fonction aire virtuelle 
	
	double virtual aire()=0;
	
	// question b
	/* cette fonction etant virtual dans cette class de base 
	 il faut qu'elle soit definie dans cette class, pour le
	 surcharger apres dans une class derive sinon il faut le mettre
	 virtuelle pure on ajoutons = 0 dans la declaration ci-dessus.
	 
	                  double virtual aire() = 0;
	 il faut prendre quelques precautions aussi :) ... 
	*/
	
	// question c : surcharge de + >> calcule de somme de surface
	// ??
	 double virtual operator+(TObjetGraphique& Tobj){
	 	return (this->aire() + Tobj.aire());
	 };
	

};


// PARTIE 3

class TRectangle: public TObjetGraphique{
	private: 
	    double longeur;
	    double largeur;
	public:
		// forme de Coplien
		TRectangle(){
			longeur = 0.0;
			largeur = 0.0;
		};
		~TRectangle(){
		};
		TRectangle(const TRectangle&rec){
			longeur = rec.longeur;
			largeur = rec.largeur;
		};
		TRectangle& operator=(TRectangle& rec){
			longeur = rec.longeur;
			largeur = rec.largeur;
		};
		// question a
		TRectangle(double l, double L){
			longeur = l;
			largeur = L;
		};
		// redefinition de la fonction aire()
		
		double aire(){
			return longeur*largeur;
		}
		
		double operator+(TRectangle& Trec){
			return (this->aire() + Trec.aire());
		}
		// question b
		friend ostream& operator<<(ostream& out, TRectangle& Trec);
		
};

ostream& operator<<(ostream& out, TRectangle& Trec){
	
	out<< ">longeur : "<< Trec.longeur <<"\n>largeur : "<< Trec.largeur<<endl;
	return out;
}




class TTriangle: public TObjetGraphique{
	private: 
	    double base;
	    double hauteur;
	public:
		// forme de Coplien
			TTriangle(){
				cout<<"triangle default cons";
			base = 0.0;
			hauteur = 0.0;
		};
		~TTriangle(){
		};
		TTriangle(const TTriangle&tr){
			base = tr.base;
			hauteur = tr.hauteur;
		};
		TTriangle& operator=(TTriangle& tr){
			base = tr.base;
			hauteur = tr.hauteur;
		};
		// question a
		TTriangle(double b, double H){
			base = b ;
			hauteur = H;
		};
		// redefinition de la fonction aire()
		
		double aire(){
			return (base*hauteur)/2;
		}
		// question b
		friend ostream& operator<<(ostream& out, TTriangle& Ttri);
};

ostream& operator<<(ostream& out, TTriangle& Ttri){
	
	out<< ">base : "<< Ttri.base <<"\n>largeur : "<< Ttri.hauteur<<endl;
	return out;
}

///////// class generique 

template<class T>
class Collection{
	
	private: 
		T* *elements; // tableau de pointeurs
		int taille;
		int taille_courante;
	
	public: 
	
		Collection(int ta){
			taille = ta;
			elements = new T*[taille]; // for taille = 3> elements = [..., ..., ... ]

		};
		~Collection(){
			cout<<"\n-----destructor of collection-----\n"<<endl;
			delete [] elements;
		};
		
		void insere(T *elt){
			int i;
			cout<<"i am in insere function : taille = "<< taille <<endl;
			cout<<" taille courant : " << taille_courante <<endl;
			elements[taille_courante] = elt; // first pass> elements = [ptr_rec1, ..., ... ]
			cout<<*elements[taille_courante]<<endl;
			
			++taille_courante;
		};
		
		
		
		double somme(){
			double sum = 0.0; 
			for(int i =0; i<taille; i++){
				sum += (*elements[i]).aire();
			}
			return sum;
		};
		
		T* operator[](int i){
			return elements[i];
		};
	
};




#endif
