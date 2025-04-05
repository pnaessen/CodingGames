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
	
	EtatPlateau initial;
	for (int i = 0; i < TAILLE; i++)
		for (int j = 0; j < TAILLE; j++)
			cin >> initial.grille[i][j];

	initial.tour = 0;

	vector<EtatPlateau> stack;
	stack.push_back(initial);
	uint32_t result_hash = 0;

	while (!stack.empty()) 
	{
		EtatPlateau etat = stack.back();
		stack.pop_back();

		if (etat.tour == depth || etat.check_full())
		 {
			uint32_t hash = etat.calculerHash();
			result_hash = (result_hash + hash) % 230;
			continue;
		}
		for (int i = 0; i < TAILLE; i++) 
		{
			for (int j = 0; j < TAILLE; j++) 
			{
				if (etat.grille[i][j] == 0) 
				{
					EtatPlateau nouveau = etat;
					nouveau.grille[i][j] = 1;
					nouveau.tour = etat.tour + 1;
					stack.push_back(nouveau);
				}
			}
		}
	}

	cout << result_hash << endl;
	return 0;
}
