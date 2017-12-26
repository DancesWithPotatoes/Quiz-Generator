//////////////////////////////////////////////////
// Author/s:			Chris Murphy
// Date created:		21/12/17
// Date last edited:	26/12/17
//////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The namespace used to contain the code of the quiz generator program.
namespace quiz_generator
{
	// A class used to integrate a multiple-choice quiz question with its associated answers.
	class quiz_question
	{
	public:
		// The constructor for the quiz_question class.
		quiz_question(string pQuestion, string pCorrectAnswer, vector<string> pIncorrectAnswers) : mQuestion(pQuestion), mCorrectAnswer(pCorrectAnswer), mIncorrectAnswers(pIncorrectAnswers) {	}

	private:
		// An individual question combined with others to generate a quiz.
		string mQuestion;
		// The correct answer to the question.
		string mCorrectAnswer;
		// The incorrect answers to be displayed alongside the correct one.
		vector<string> mIncorrectAnswers;
	};
}