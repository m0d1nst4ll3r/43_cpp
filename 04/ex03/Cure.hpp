#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
    	Cure();
		virtual	~Cure();
		Cure(const Cure& toCopy);
		Cure&	operator=(const Cure& op);
    	virtual Cure*	clone() const;
    	virtual void	use(ICharacter& target);
};

#endif /* CURE_H */
