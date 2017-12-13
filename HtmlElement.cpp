#include "HtmlElement.h"

using namespace std;

HtmlElement::HtmlElement() {}
HtmlElement::HtmlElement(const string &name, const string &text) : name(name), text(text) {}

string HtmlElement::str(int indent) const {
	ostringstream oss;
	string i(indent_size*indent, ' ');
	oss << i << "<" << name << ">" << endl;
	if(text.size() > 0) {
		oss << string(indent_size*(indent + 1), ' ') << text << endl;
	}
	for(const auto &e : elements) {
		oss << e.str(indent + 1);
	}
	oss << i << "</" << name << ">" << endl;
	return oss.str();
}

HtmlBuilder HtmlElement::build(string root_name) {
	return HtmlBuilder{root_name};
}


HtmlBuilder::HtmlBuilder(string root_name) {
	HtmlBuilder::root.name = root_name;
}
HtmlBuilder& HtmlBuilder::add_child(string child_name, string child_text) {
	HtmlElement e{child_name, child_text};
	root.elements.emplace_back(e);
	return *this;
}

string HtmlBuilder::str() const {
	return root.str();
}
