#include <iostream>
#include <vector>
#include <string>
using namespace std;

// int permutationsInfiniteCoins(vector<int> &coins, int target, int idx, string ans){

// if(target == 0){
//   cout << ans <<endl;
//   return 1;
// }

// int count = 0;

// for(int i = idx; i < coins.size();i++){
//   if(target - coins[i] >= 0){
//     count += permutationsInfiniteCoins(coins, target-coins[i], 0, ans + to_string(coins[i]));
//   }
// }
// return count;
// }

// vector<bool> column(false);
// vector<bool> row(false);
// vector<bool> diag(false);
// vector<bool> antiDiag(false);
// vector<vector<int>> q_dir = {{0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {0, 1}, {1, 0}, {1, 1}, {1, -1}};

// bool isColSafe(int idx){
//   return column[idx] == false? true: false;
// }
// bool isRowSafe(int idx){
//   return column[idx] == false? true: false;
// }
// bool isDiagSafe(int idx){
//   return column[idx] == false? true: false;
// }
// bool isAntiDiagSafe(int idx){
//   return column[idx] == false? true: false;
// }

// bool isQueenSafeBits(int r, int c){

//   return isColSafe(r) && isRowSafe(c) && isDiagSafe(r+c) && isAntiDiagSafe(r-c+);
// }

int bitRow = 0;
int bitCol = 0;
int bitDiag = 0;
int bitAntiDiag = 0;
int r_ = 4;
int c_ = 4;
int bs = r_;

bool isQueenBitSafe(int r, int c)
{
	return ((bitRow & (r << 1)) == 0 && (bitCol & (c << 1)) == 0 && (bitDiag & (r + c << 1)) == 0 && (bitAntiDiag & (r - c + bs << 1)) == 0);
}

void markUnmarkBit(int r, int c)
{
	bitRow ^= r << 1;
	bitCol ^= c << 1;
	bitDiag ^= (r + c << 1);
	bitAntiDiag ^= (r - c + bs << 1);
}

int nQueenBit(int r, int tnq)
{
	if (tnq == 0)
	{
		return 1;
	}
	int count = 0;
	for (int col = 0; col < c_; col++)
	{
		if (isQueenBitSafe(r, col))
			;
		markUnmarkBit(r, col);
		count += nQueenBit(r + 1, tnq - 1);
		markUnmarkBit(r, col);
	}
	return count;
}

vector<int> row(0);
vector<int> col(0);
vector<vector<int>> mat(0, vector<int>(9, 0));
int sudoku(int boxNo)
{
	if (boxNo == 81)
	{
		return 1;
	}

	int count = 0;
	int i = boxNo / 9;
	int j = boxNo % 9;
	for (int num = 1; num <= 9; num++)
	{
		int mask = 1 << num;
		if ((row[i] & mask) == 0 && (col[j] & mask) == 0 && (mat[i][j] & mask) == 0)
		{
			row[i] ^= mask;
			col[j] ^= mask;
			mat[i][j] ^= mask;
			count += sudoku(boxNo + 1);
			row[i] ^= mask;
			col[j] ^= mask;
			mat[i][j] ^= mask;
		}
		else
		{
			count += sudoku(boxNo + 1);
		}
	}
	return count;
}

int main()
{
	vector<int> coins{2, 3, 5, 7};
	// cout << permutationsInfiniteCoins(coins, 10,0,"") << endl;
	nQueenBit(r_, 4);
	return 0;
}
