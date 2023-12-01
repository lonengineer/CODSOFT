#include<iostream>
#include<vector>

// using std::cout, std::vector, std::string, std::endl;
using namespace std;

double sum(vector<float> grades);
string spaced_string(string input);

int main() {
	string name; float grade; unsigned counter = 0;
	vector<string> studentsName;
	vector<float> studentsGrade;
	cout << "==================== Student Grading System ====================" << std::endl << "Type \'end\' to terminate";
	try {
		for (int i = 0; true; i++) {
			cout << std::endl;
			cout << "Enter name of student " << i + 1 << " and percentage grade: ";
			std::cin >> name;
			if (name == "end") break;
			std::cin >> grade;
			if (grade > 100 || grade < 0)
				throw("Grade out of bound");
			studentsName.push_back(name);
			studentsGrade.push_back(grade);
		}
	}
	catch (const char* exception) {
		cout << "Exception:\t" << exception << endl;
	}
	catch (...) {
		cout << "Exception caugth" << endl;
		// return 0;
	}
	double avg = (float)sum(studentsGrade) / studentsGrade.size();
	cout << std::endl << "======================== Result =======================" << std::endl << std::endl;
	for (int i = 0; i < studentsName.size(); i++) {
		cout << "|| " << spaced_string(studentsName[i]) << "|\t" << studentsGrade[i] << " ||" << std::endl;
	}
	cout << "--------------------------------------------------------------------" << std::endl;
	cout << "Avg. grade:\t" << avg << "\tHighest grade:\t" << *max_element(studentsGrade.begin(), studentsGrade.end()) << "\tLowest grade:\t" << *min_element(studentsGrade.begin(), studentsGrade.end())<<endl;

}
double sum(vector<float> grades) {
	double sumGrades = 0;
	for (auto i : grades)
		sumGrades += i;
	return sumGrades;

}
string spaced_string(string input) {
	if (input.length() > 15)
		return input;

	string s = "";
	for (int i = 0; i < 15 - input.length(); i++)
		s = s + " ";
	return s + input;
}

