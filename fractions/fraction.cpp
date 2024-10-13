#include <iostream>
#include <numeric>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

	int greateastCommonDivisor(int denom1, int denom2) {	
		while (denom2 != 0) {
			int temp = denom2;			
			denom2 = denom1 % denom2;	
			denom1 = temp;				
		}
		return denom1;
	}

	int leastCommonMultiple(int denom1, int denom2) {		
		return (denom1 / greateastCommonDivisor(denom1, denom2)) * denom2;	
	}

	void lowestTerm() {
		int gcd = greateastCommonDivisor(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
	}
public:
	Fraction(int _numerator, int _denominator) {
		if (_denominator == 0) {
			while (_denominator < 1) {
				cout << "You'd been warned to avoid entering a ZERO value for the denominator.\nNow you'll be asked to correct your mistake for every denominator if you entered more than 1 as ZERO.\nOtherwise fix your only mistake and enter a NON-ZERO Value\n";
				cin >> _denominator;
			}
		}
		this->numerator = _numerator;
		this->denominator = _denominator;
	}
	~Fraction() {
		//cout << "Destroying " << numerator << "/" << denominator << "\n";
	}

	int getNumerator() {
		return numerator;
	}

	int getDenominator() {
		return denominator;
	}

	void ShowFraction() {
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}

		if (numerator > denominator || (numerator * -1) > denominator) {
			if (numerator - denominator * (numerator / denominator) == 0 && denominator == 1) {
				cout << numerator / denominator;
			}
			else if (numerator - denominator * (numerator / denominator) == 0) {
				cout << numerator / denominator << char(248) << 1 << "/" << denominator;
			}
			else {
				if (numerator < 0) {
					cout << numerator / denominator << char(248) << -1 * (numerator - denominator * (numerator / denominator)) << "/" << denominator;
				}
				else {
					cout << numerator / denominator << char(248) << (numerator - denominator * (numerator / denominator)) << "/" << denominator;
				}
			}
		}
		else if (numerator / denominator == 1) {
			cout << 1;
		}
		else if ((numerator / denominator) < 0 && (numerator % denominator == 0)) {
			cout << numerator / denominator;
		}
		else {
			cout << numerator << "/" << denominator;
		}
	}

	Fraction plus(Fraction& frac2) {
		Fraction frac1 = Fraction(numerator, denominator);

		int lcmDenom = leastCommonMultiple(frac1.denominator, frac2.getDenominator());
		int num1 = frac1.getNumerator() * (lcmDenom / frac1.getDenominator());
		int num2 = frac2.getNumerator() * (lcmDenom / frac2.getDenominator());

		Fraction sum(num1 + num2, lcmDenom);
		sum.lowestTerm();

		return sum;
	}
	Fraction subtract(Fraction& frac2) {
		int lcmDenom = leastCommonMultiple(denominator, frac2.getDenominator());
		int num1 = numerator * (lcmDenom / denominator);
		int num2 = frac2.getNumerator() * (lcmDenom / frac2.getDenominator());

		Fraction difference(num1 - num2, lcmDenom);
		difference.lowestTerm();

		return difference;
	}
	Fraction multiply(Fraction& frac2) {
		int num1 = numerator * frac2.getNumerator();
		int num2 = denominator * frac2.getDenominator();

		Fraction product(num1, num2);
		product.lowestTerm();

		return product;
	}
	Fraction divide(Fraction& frac2) {
		int num1 = numerator * frac2.getDenominator();
		int num2 = denominator * frac2.getNumerator();

		Fraction quotient(num1, num2);
		quotient.lowestTerm();

		return quotient;
	}
};


void main() {
	Fraction frac1(-2, 1);
	Fraction frac2(1, 4);

	Fraction sum = frac1.plus(frac2);
	cout << "The sum of ";
	frac1.ShowFraction();
	cout << " + ";
	frac2.ShowFraction();
	cout << " = ";
	sum.ShowFraction();
	cout << "\n";
	
	Fraction diff = frac1.subtract(frac2);
	cout << "The difference of ";
	frac1.ShowFraction();
	cout << " - ";
	frac2.ShowFraction();
	cout << " = ";
	diff.ShowFraction();
	cout << "\n";

	Fraction product = frac1.multiply(frac2);
	cout << "The product of ";
	frac1.ShowFraction();
	cout << " x ";
	frac2.ShowFraction();
	cout << " = ";
	product.ShowFraction();
	cout << "\n";

	Fraction quotient = frac1.divide(frac2);
	cout << "The quotient of ";
	frac1.ShowFraction();
	cout << " " << char(246) << " ";  //" / ";
	frac2.ShowFraction();
	cout << " = ";
	quotient.ShowFraction();
	cout << "\n";
	
	cout << "\nWelcome to my Fraction Calculator.\n";
	int num1, num2, denum1, denum2, opChoice;
	while (true) {
		cout << "\nPlease enter your numerator for the 1st fraction : \n";
		cin >> num1;
		cout << "\nWonderful! Now enter the denominator for your 1st fraction:\nCareful now, DO NOT ENTER 0!!!\n";
		cin >> denum1;
		cout << "\nNice! We have the 1st fraction complete.\nNow enter the numerator for your 2nd fraction:\n";
		cin >> num2;
		cout << "\nSo far so good. Now enter the denominator for your 2nd fraction:\nRemember DO NOT ENTER a 0!!!\n";
		cin >> denum2;
		cout << "\nMarvelous. Now choose your operation method:\n1. for addition\n2. for subtraction\n3. for multiplication\n4. for division\nWhat will it be?\n";
		cin >> opChoice;

		frac1 = Fraction(num1, denum1);
		frac2 = Fraction(num2, denum2);

		switch (opChoice) {
		case 1:
			sum = frac1.plus(frac2);
			cout << "The sum of ";
			frac1.ShowFraction();
			cout << " + ";
			frac2.ShowFraction();
			cout << " = ";
			sum.ShowFraction();
			cout << "\n";
			break;
		case 2:
			diff = frac1.subtract(frac2);
			cout << "The difference of ";
			frac1.ShowFraction();
			cout << " - ";
			frac2.ShowFraction();
			cout << " = ";
			diff.ShowFraction();
			cout << "\n";
			break;
		case 3:
			product = frac1.multiply(frac2);
			cout << "The product of ";
			frac1.ShowFraction();
			cout << " x ";
			frac2.ShowFraction();
			cout << " = ";
			product.ShowFraction();
			cout << "\n";
			break;
		case 4:
			quotient = frac1.divide(frac2);
			cout << "The quotient of ";
			frac1.ShowFraction();
			cout << " " << char(246) << " ";  //" / ";
			frac2.ShowFraction();
			cout << " = ";
			quotient.ShowFraction();
			cout << "\n";
			break;
		default:
			break;
		}
	}
}