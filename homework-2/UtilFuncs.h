#pragma once

#include <string>

template <class Container>
void split(const std::string& str, Container& cont, // http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
	std::string delims, int index = 0);




template<class Container>
inline void split(const std::string & str, Container & cont, std::string delims, int index)
{
	if (index >= delims.size())
		return;

	std::size_t current, previous = 0;
	current = str.find(delims[index]);
	while (current != std::string::npos) {
		cont.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find(delims, previous);
	}
	cont.push_back(str.substr(previous, current - previous));

	split(str, cont, delims, ++index);
}
