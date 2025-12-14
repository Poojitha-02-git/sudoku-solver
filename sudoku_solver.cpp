#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int matrix[][9], int i, int j, int n, int number){
	//i have to check if the number exist within the same row or same column
	for (int k = 0; k < n; k++)
	{
		if(matrix[k][j] == number || matrix[i][k] == number){
			return false;
		}
	}
	n = sqrt(n);
	int si = (i/n)*n;
	int sj = (j/n)*n;
	for (i = si; i < si+n; i++){
		for(j = sj; j < sj+n; j++){
			if(matrix[i][j] == number || matrix[i][j] == number){
				return false;
			}
		}
	}
	return true;
}
bool Sudoko(int matrix[][9], int i, int j, int n){
	//base case
	if(i == n){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	if(j == n){
		//we will move to the next row
		return Sudoko(matrix, i+1, 0, n);
	}
	if(matrix[i][j] != 0){
		//what if we come across a already filled cell?
		//we will simply ask the recursion to solve the sudoko
		//move to the next cell
		return Sudoko(matrix, i, j+1, n);
	}
	//recursive case
	for(int number = 1; number <= 9; number++){
		if(isSafe(matrix, i, j, n, number)){
			//place the number if its safe
			matrix[i][j] = number;
			//ask recursion to solve the remaining sudoko
			bool remaining_sudoko = Sudoko(matrix, i, j+1, n);
			if(remaining_sudoko == true){
				return true;
			}
			//back tracking
			matrix[i][j] = 0;
		}

	}
	//return false if we dont find the answer...
			return false;
}
int main(){
	int matrix[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9},
	};
	Sudoko(matrix, 0, 0, 9);
	return 0;
}