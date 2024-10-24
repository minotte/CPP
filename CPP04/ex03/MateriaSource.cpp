#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++){
			this->_spell[i] = NULL;
	} 
}

MateriaSource::MateriaSource(MateriaSource const & src){
	for (int i = 0; i < 4; i++){
			this->_spell[i] = 0;
	}
	*this = src;
}

MateriaSource const & MateriaSource::operator=(const MateriaSource &src){
	for (int i = 0; i < 4; i++){
		delete this->_spell[i];
			this->_spell[i] = src._spell[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		if (this->_spell[i]) {
			delete this->_spell[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* src){
	for (int i = 0; i < 4; i++){
		if (this->_spell[i] == 0) {
			this->_spell[i] = src;
			break;
		}
	} 
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (this->_spell[i] && !(this->_spell[i]->getType().compare(type))){
			return (this->_spell[i]->clone());
		}
	}
	std::cout << type <<  " doesn't exist" << std::endl;
	return 0;
}
