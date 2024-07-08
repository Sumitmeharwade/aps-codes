#include <iostream>
#include <fstream>
#include <vector>
#include "Hungarian.h"

using namespace std;

// Function to solve the assignment problem
void minCost(vector<vector<double>> arr) {
	int n = arr.size();

	// Convert the 2D vector to a double array
	double **costMatrix = new double*[n];
	for (int i = 0; i < n; i++) {
		costMatrix[i] = new double[n];
		for (int j = 0; j < n; j++) {
			costMatrix[i][j] = arr[i][j];
		}
	}

	// Apply the Hungarian algorithm to find the optimal assignment
	HungarianAlgorithm algorithm;
	vector<int> assignment;
	double cost = algorithm.Solve(costMatrix, n, n, assignment);

	// Print the optimal cost
	cout << "Optimal cost: " << cost << endl;

	// Free memory allocated for the cost matrix
	for (int i = 0; i < n; i++) {
		delete[] costMatrix[i];
	}
	delete[] costMatrix;
}

// Main function
int main() {
	// Load the input array from a .csv file
	ifstream inputFile("input.csv");
	vector<vector<double>> arr;
	string line;
	while (getline(inputFile, line)) {
		vector<double> row;
		size_t pos = 0;
		string token;
		while ((pos = line.find(",")) != string::npos) {
			token = line.substr(0, pos);
			row.push_back(stod(token));
			line.erase(0, pos + 1);
		}
		row.push_back(stod(line));
		arr.push_back(row);
	}

	// Solve the assignment problem
	minCost(arr);

	return 0;
}
