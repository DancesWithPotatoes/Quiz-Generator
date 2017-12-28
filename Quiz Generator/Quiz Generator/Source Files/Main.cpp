//////////////////////////////////////////////////
// Author/s:			Chris Murphy
// Date created:		21/12/17
// Date last edited:	27/12/17
//////////////////////////////////////////////////
#include <ctime>
#include <iostream>
#include "multiple_choice_question.h"
using namespace quiz_generator;
using namespace std;

vector<multiple_choice_question> read_questions_from_file(string pFilePath)
{


}

bool write_questions_to_file(string pFilePath, vector<multiple_choice_question> pQuestions)
{

	return false;
}

// The entry point of the program.
int main()
{
	// Sets the seed for all random number generation utilised by the program to be the current time.
	srand(time(NULL));

	// TEMP
	string question = "What is the capital of Spain?";
	string correctAnswer = "Madrid";
	vector<string> incorrectAnwers;
	incorrectAnwers.push_back("Paris");
	incorrectAnwers.push_back("London");
	incorrectAnwers.push_back("Berlin");
	multiple_choice_question quizQuestion(question, correctAnswer, incorrectAnwers);

	while (true)
	{
		quizQuestion.ask();
	}

	return 0;
}