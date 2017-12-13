#include "HtmlElement.h"
using namespace std;

int main() {

  HtmlBuilder builder{"ul"};
	builder.add_child("li", "Hello").add_child("li", "World");
	cout << builder.str() << endl;

	auto builder2 = HtmlElement::build("ul").add_child("li","stuff").add_child("li", "stuff2");

	cout << builder2.str() << endl;

	return 0;
}
