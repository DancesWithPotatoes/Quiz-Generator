//////////////////////////////////////////////////
// Author/s:			Chris Murphy
// Date created:		21/12/17
// Date last edited:	31/12/17
//////////////////////////////////////////////////
#include <ctime>
#include <fstream>
#include <iostream>
#include "multiple_choice_question.h"
using namespace quiz_generator;
using namespace std;

//vector<multiple_choice_question> read_questions_from_file(string pFilePath)
//{
//
//
//}

// Writes quiz questions to a text file in a format which can be read by the read_questions_from_file() function.
bool write_questions_to_file(string pFileName, vector<multiple_choice_question> pQuestions)
{
	// The filestream used to open and write to the file of the provided name after removing any existing content within it.
	ofstream fileStream(pFileName.c_str(), ios::trunc);
	if (fileStream.is_open())
	{
		for (unsigned int i = 0; i < pQuestions.size(); ++i)
		{
			pQuestions[i].write_to_open_text_file(fileStream);
		}

		fileStream.close();
		return true;
	}
	else
		return false;
}

// The entry point of the program.
int main()
{
	// Sets the seed for all random number generation utilised by the program to be the current time.
	srand((unsigned int)time(NULL));

	vector<multiple_choice_question> questions;

	// TEMP
	string question = "What is the capital of Spain?";
	string correctAnswer = "Madrid";
	vector<string> incorrectAnswers;
	incorrectAnswers.push_back("Paris");
	incorrectAnswers.push_back("London");
	incorrectAnswers.push_back("Berlin");
	questions.push_back(multiple_choice_question(question, correctAnswer, incorrectAnswers));

	question = "How many months are in the Gregorian Calendar?";
	correctAnswer = "12";
	incorrectAnswers.clear();
	incorrectAnswers.push_back("10");
	incorrectAnswers.push_back("8");
	incorrectAnswers.push_back("14");
	questions.push_back(multiple_choice_question(question, correctAnswer, incorrectAnswers));

	question = "What was the first name of Archduke Ferdinand?";
	correctAnswer = "Franz";
	incorrectAnswers.clear();
	incorrectAnswers.push_back("Heinrich");
	incorrectAnswers.push_back("Karl");
	incorrectAnswers.push_back("Hans");
	questions.push_back(multiple_choice_question(question, correctAnswer, incorrectAnswers));

	
	write_questions_to_file("Questions.txt", questions);


	while (true)
	{
		questions[rand() % questions.size()].ask();
	}

	return 0;
}