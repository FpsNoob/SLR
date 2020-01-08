#include "include/ReadGrammar.h"
#include "include/First.h"
#include "include/Follow.h"
#include "include/Lex.h"
#include "include/SLRparsing.h"
#include "include/Parsing.h"

int main() {
	readGrammar();
	setFirst();
	setFollow();
	setDFA();
	cout << endl << endl;
	cout << "����������ַ�������$��β����";//text��i_2a23_+34*ab$
	cin >> input_str;
	lex();
	Parsing_SLR();
}
