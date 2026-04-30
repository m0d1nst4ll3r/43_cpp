#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {

	public:

	Brain( void );
	~Brain( void );
	Brain( const Brain& toCopy );
	Brain&	operator=( const Brain& op );
	
	private:

	std::string	ideas[100];
};

#endif /* BRAIN_H */
