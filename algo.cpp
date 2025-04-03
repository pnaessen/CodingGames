#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

const int TAILLE = 3;
struct EtatPlateau
{
	int grille[TAILLE][TAILLE];
	int tour;

	EtatPlateau()
	{
		for (int i = 0; i < TAILLE; i++) 
		{
			for (int j = 0; j < TAILLE; j++) 
				grille[i][j] = 0;
		}
		
		tour = 0; 
	}
	uint32_t calculerHash() const 
	{
		uint32_t hash = 0;
		for(int i = 0; i < TAILLE; i++)
		{
			for(int j = 0; j < TAILLE; j++)
				hash = hash * 10 + grille[i][j];
		}
		return(hash);
	}
	bool check_full() const
	{
		for(int i = 0; i < TAILLE; i++)
		{
			for(int j = 0; j < TAILLE; j++)
			{
				if(grille[i][j] == 0)
					return(false);
			}

		}
		return(true);
	}
	void debug()
	{
		cout << "(tour " << tour << "):" << endl;
		for(int i = 0; i < TAILLE; i++)
		{
			for(int j = 0; j < TAILLE; j++)
				 cout << grille[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
};

int main()
{
	int depth;
	cin >> depth; cin.ignore();
	
	EtatPlateau etat;
		
	for (int i = 0; i < TAILLE; i++) 
	{
		for (int j = 0; j < TAILLE; j++) 
		{
			int value;
			cin >> value; cin.ignore();
			etat.grille[i][j] = value;
		}
	}
	cerr << "État initial:" << endl;
	etat.debug();
	uint32_t hash = etat.calculerHash();
	cerr << "Hash du plateau initial: " << hash << endl;
	cerr << "Le plateau est plein: " << (etat.check_full() ? "Oui" : "Non") << endl;
	cerr << "Nombre de tours à simuler: " << depth << endl;
	cout << hash << endl;
	
	//g++ -o cephalopods algo.cpp 
	return 0;
}