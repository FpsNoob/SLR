#include "include/ReadGrammar.h"
#include "include/First.h"
#include "include/Follow.h"
#include "include/Lex.h"

int main() {
	readGrammar();
	setFirst();
	setFollow();

	cout << "����������ַ�������#��β����";//text��i_2a23_+34*ab
	cin >> input_str;
	lex();

}
