//////////////////////////////////////////////////
// Author/s:			Chris Murphy
// Date created:		27/12/17
// Date last edited:	27/12/17
//////////////////////////////////////////////////
#include "multiple_choice_question.h"
using namespace std;

namespace quiz_generator
{
	multiple_choice_question::multiple_choice_question(string pQuestion, string pCorrectAnswer, vector<string> pIncorrectAnswers) : mQuestion(pQuestion), mCorrectAnswer(pCorrectAnswer), mIncorrectAnswers(pIncorrectAnswers) { }

	bool multiple_choice_question::ask()
	{
		cout << mQuestion << endl;

		// A vector containing the correct and incorrect answers.
		vector<string> answers = mIncorrectAnswers;
		answers.push_back(mCorrectAnswer);
		// Randomises the order of the answers and displays them on the console.
		random_shuffle(answers.begin(), answers.end());
		for (unsigned int i = 0; i < answers.size(); ++i)
			cout << i + 1 << ") " << answers[i] << endl;

		// The input of the user.
		string input;
		// The answer index inputted by the user.
		int inputtedAnswerIndex = -1;
		// Ensures that the user enters a valid number within the answer range.
		while (true)
		{
			cout << "Enter the number of the correct answer: ";
			getline(cin, input);

			stringstream sStream(input);
			if (sStream >> inputtedAnswerIndex && inputtedAnswerIndex > 0 && inputtedAnswerIndex <= answers.size())
				break;
			else
				cout << "Invalid input." << endl;
		}

		// If the corresponding answer of the inputted index is the correct answer, returns true.
		if (answers[--inputtedAnswerIndex] == mCorrectAnswer)
		{
			cout << "Correct answer!" << endl << endl;
			return true;
		}
		// Else outputs the correct answer and returns false.
		else
		{
			cout << "Incorrect - the correct answer is " + mCorrectAnswer << '.' << endl << endl; 
			return false;
		}
	}
}