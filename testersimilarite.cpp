#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<math.h>
 
#define pi   3.14159265358979323846264338327950288419716939937510
 
using namespace std;
 
typedef std::map<std::string,int> strintmap;

void occurence(std::istream &fich, strintmap &words){
    std::string s;
    while (fich >> s){
        ++words[s];
    }
}
 
 int modit(strintmap d){
 	
 	
    int mod=0;
    for (strintmap::iterator p = d.begin(); p != d.end(); p++){
        mod += p->second * p->second;
    }
    return mod;
}

int compterdistance(strintmap f1, strintmap f2){
    int produitscalaire = 0;
    for (strintmap::iterator p1 = f1.begin(); p1 != f1.end(); p1++){
        for (strintmap::iterator p2 = f2.begin(); p2 != f2.end(); p2++){
            if (p1->first == p2->first)
                produitscalaire += (p1->second*p2->second);
        }
    }
    return produitscalaire;
}
 
int main(void)
{
 ifstream fichier1("C:/Users/elitebook/Desktop/M1 SSI/FICH1.TXT");  // Flux de lecture
 ifstream fichier2("C:/Users/elitebook/Desktop/M1 SSI/FICH2.TXT");  // Flux de lecture
 
  int ps; //produit scalire 
    int mod1, mod2;
    double mod;
    float distance;
     if (!fichier1)
        cout << "ERREUR: Impossible d'ouvrir le fichier 1 en lecture. ";
    if (!fichier2)
        cout << "ERREUR: Impossible d'ouvrir le fichier 2 en lecture.";
        
        strintmap f1,f2;
    occurence(fichier1, f1);
    occurence(fichier2, f2);
    
     cout << "\n table1= [ ";
   for (strintmap::iterator p = f1.begin(); p != f1.end() ; p++){
        std::cout << p->first << "  = " << p->second << "  "  << std::endl;}
        cout << " ] ";
      cout << endl;
      cout << "\n table2= [ ";
   for (strintmap::iterator p = f2.begin(); p != f2.end() ; p++){
        std::cout << p->first << "  = " << p->second << "  "  << std::endl;}
        cout << " ] ";
      cout << endl;
    ps = compterdistance(f1, f2);
    mod1 = modit(f1);
    mod2 = modit(f2);
    mod = sqrt(mod1*mod2);
    
    distance = 180*acos(ps / mod)/pi;
    cout << "la similarite entre les deux fichiers est "  << distance;cout << endl;
    if (distance == 0) {
    	cout << "les deux fichiers sont similaire  ";
}
     else 
	 {
	if (distance == 90) {
    	cout << "les deux fichiers ne sont pas similaire  ";
	}
	else {	cout << "les deux fichiers sont peu similaire  ";
	}}
    getchar();
 fichier1.close();
fichier2.close();

}
 
    
