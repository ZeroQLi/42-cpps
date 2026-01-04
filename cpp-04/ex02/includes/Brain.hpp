#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>
# include <algorithm>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain &operator=(const Brain &other);
		virtual ~Brain();

		std::string getIdea(unsigned int index) const;
		void setIdea(unsigned int index, const std::string& idea);
};

#endif

