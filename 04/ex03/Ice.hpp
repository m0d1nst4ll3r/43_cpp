#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
	public:
    	Ice();
		virtual	~Ice();
		Ice(const Ice& toCopy);
		Ice&	operator=(const Ice& op);
    	virtual Ice*	clone() const;
    	virtual void	use(ICharacter& target);
};

#endif /* ICE_H */