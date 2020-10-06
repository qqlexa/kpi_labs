#define _CRT_SECURE_NO_WARNINGS
#include <iostream>   
#include <iomanip>
#include <vector>

using namespace std;


struct Parameters {
	vector<float> fx;

	float a;
	float b;

	float dx;

	float x1;
	float x2;

};


Parameters readParameters();
void countFunction(Parameters& parameters);
void printFunction(Parameters parameters);
float getMaxValue(vector<float> fx);
float getMinValue(vector<float> fx);
float getAverageFromPositive(vector<float> fx);
vector<float> generateRandomArray(vector<float> fx, float S1, float S2, float beta);
void printRandomArray(vector<float> rnd);
vector<int> generateLinearArray(vector<float> fx, int lower_bound, int upper_bound);
void printSymbols(vector<int> linear_array, char symbol);

int main() {
	Parameters parameters = readParameters();
	int A = 70;
	float beta = 0.045;
	char symbol = 0xB0;
	float S1, S2;
	
	countFunction(parameters);
	printFunction(parameters);
	S1 = getAverageFromPositive(parameters.fx);
	S2 = getMaxValue(parameters.fx);

	vector<float> rnd = generateRandomArray(parameters.fx, S1, S2, beta);
	printf("S1: %-8f\nS2: %-8f\n", S1, S2);
	printRandomArray(rnd);
	
	vector<int> linear_array = generateLinearArray(parameters.fx, 0, A);
	printSymbols(linear_array, symbol);
	return 0;
}

Parameters readParameters() {
	Parameters parameters;

	printf("Enter a: ");
	scanf("%f", &parameters.a);

	printf("Enter b: ");
	scanf("%f", &parameters.b);

	printf("Enter x1: ");
	scanf("%f", &parameters.x1);

	printf("Enter x2: ");
	scanf("%f", &parameters.x2);

	printf("Enter dx: ");
	scanf("%f", &parameters.dx);
	return parameters;
}

void countFunction(Parameters& parameters) {
	float x = parameters.x1;
	float value;

	while (x <= parameters.x2) {
		if (x > -0.5) {
			value = parameters.a * x - parameters.b;
		}
		else {
			value = (parameters.b) ? -(x + parameters.a) / parameters.b : 0;
		}
		parameters.fx.push_back(value);
		x += parameters.dx;
	}
}

void printFunction(Parameters parameters) {
	char symbol = '#';
	float x = parameters.x1;
	printf("%-7cf(x)%8c       x%8c\n", symbol, symbol, symbol);
	for (int i = 0; i < 35; i++) {
		printf("%c", symbol);
	}
	printf("\n");
	for (int i = 0; i < parameters.fx.size(); i++) {
		printf("%-8c%-10.5f%-8c%-8.1f%-8c\n", symbol, parameters.fx[i], symbol, x, symbol);
		x += parameters.dx;
	}

	for (int i = 0; i < 35; i++) {
		printf("%c", symbol);
	}
	printf("\n");
}

float getMaxValue(vector<float> fx) {
	float result = fx[0];
	for (int i = 1; i < fx.size(); i++) {
		if (result < fx[i]) {
			result = fx[i];
		}
	}
	return result;
}

float getMinValue(vector<float> fx) {
	float result = fx[0];
	for (int i = 1; i < fx.size(); i++) {
		if (result > fx[i]) {
			result = fx[i];
		}
	}
	return result;
}

float getAverageFromPositive(vector<float> fx) {
	float result = 0;
	int countPositiveNumbers = 0;

	for (int i = 0; i < fx.size(); i++) {
		if (fx[i] > 0) {
			result += fx[i];
			countPositiveNumbers++;
		}
	}
	if (countPositiveNumbers) {
		result /= countPositiveNumbers;
	}
	return result;
}

vector<float> generateRandomArray(vector<float> fx, float S1, float S2, float beta) {
	vector<float> random_array(fx.size());

	float S_min = S1;
	float S_max = S2;
	if (S_min > S_max) {
		S_min = S_max + S_min;
		S_max = S_min - S_max;
		S_min = S_min - S_max;
	}

	float S_avg = (S_min + S_max) / 2;
	float step = beta * S_avg;

	random_array[0] = ((S_max - S_min) * ((float)rand() / RAND_MAX)) + S_min;
	for (int i = 1; i < fx.size(); i++) {
		float min_rand = random_array[i - 1] - step;
		float max_rand = random_array[i - 1] + step;

		float random_value = (rand() % 2 == 0) ? min_rand : max_rand;

		if (random_value > S_max || random_value < S_min) {
			random_array[i] = (random_value == min_rand) ? max_rand : min_rand;
		}
		else {
			random_array[i] = random_value;
		}
	}


	return random_array;
}

void printRandomArray(vector<float> rnd) {
	char symbol = '#';
	for (int i = 0; i < 35; i++) {
		printf("%c", symbol);
	}
	printf("\n");
	for (int i = 0; i < rnd.size(); i++) {
		printf("%-8c%-10.5f%-8c%-8d%-8c\n", symbol, rnd[i], symbol, i, symbol);
	
	}
	for (int i = 0; i < 35; i++) {
		printf("%c", symbol);
	}
	printf("\n");
}

vector<int> generateLinearArray(vector<float> fx, int lower_bound, int upper_bound) {
	vector<int> linear_array;

	
	float min_value = getMinValue(fx);
	float max_value = getMaxValue(fx);

	for (int i = 0; i < fx.size(); i++) {
		linear_array.push_back(lower_bound + (fx[i] - min_value) * (upper_bound - lower_bound) / (max_value - min_value));
	}
	return linear_array;
}

void printSymbols(vector<int> linear_array, char symbol) {
	for (int i = 0; i < linear_array.size(); i++) {
		for (int j = 0; j < linear_array[i]; j++) {
			printf("%c", symbol);
		}
		printf("\n");
	}
}
