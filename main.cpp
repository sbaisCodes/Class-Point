#include <iostream>
#include"Tpoint.h"
using namespace std;
int main(int argc, char** argv) {
	
	TRectangle rec1(3.14,2), rec2(9.8, 6.012), rec3(1.1, 2.2);
	cout<<"\nObjets creer :  rec1(3.14,2), rec2(9.8, 6.012), rec3(1.1, 2.2) =============\n tri1(2.12,2) =============\n";

	TTriangle tri1(2.12,2);
	
// affichage de l'aire
	cout << "aire rectangle de longeur 3.14, largeur 2 : "<<rec1.aire()<<endl;
	cout << "aire triangle de base 2, hauteur 3 : "<< tri1.aire()<<endl;
	
cout<<"\n========= test surcharge de '=' =============\n";
double resultat_somme;

resultat_somme = rec1 + rec2 ;
cout<<"somme des surfaces du rec1 et rec2  : "<< resultat_somme;

	
// test <<
 cout<<"\n============= test : affichage << =============\n";

 cout << rec1;
 cout << tri1;
 cout<<"\n=============== class generique =====================\n";
 TRectangle* pr_rec1 = &rec1, *pr_rec2 = &rec2, *pr_rec3 = &rec3;
 
 Collection <TRectangle> col1(3);
 col1.insere(pr_rec1);
 cout<<"Element 1> aire = "<<pr_rec1->aire()<<endl;

 col1.insere(pr_rec2);
 cout<<"Element 2> aire = "<<pr_rec2->aire()<<endl;

 col1.insere(pr_rec3);
 cout<<"Element 3> aire = "<<pr_rec3->aire()<<endl;

 
 cout<<"\n Somme des surfaces des trois objets : "<<endl;
 cout<<"sum = " << col1.somme();


	
	
	return 0;
}
