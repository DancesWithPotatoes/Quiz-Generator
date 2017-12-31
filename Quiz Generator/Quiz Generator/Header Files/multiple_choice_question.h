//////////////////////////////////////////////////
// Author/s:			Chris Murphy
// Date created:		21/12/17
// Date last edited:	31/12/17
//////////////////////////////////////////////////
#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace quiz_generator
{
	// A class used to integrate a quiz question and its associated multiple-choice-style answers.
	class multiple_choice_question
	{
	public:
		// The standard constructor for the multiple_choice_question class.
		multiple_choice_question(string pQuestion, string pCorrectAnswer, vector<string> pIncorrectAnswers);
		// Initialises the multiple_choice_question class from an already 
		
		// TEMP - Writes the members of the question to an already-opened text file stream in a format which can be read using a multiple_choice_question constructor overload.
		bool write_to_open_text_file(ofstream& pOpenFileStream);

		// Uses the console to ask the user to answer the question and returns whether or not they get it correct.
		bool ask();

	private:
		// The question to be displayed to the user.
		string mQuestion;
		// The correct answer to the question.
		string mCorrectAnswer;
		// The incorrect answers to be displayed alongside the correct one.
		vector<string> mIncorrectAnswers;
	};
}