#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <exception>
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137){
	std::cout << GREY << "ShrubberyCreationForm constructor" << NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target): AForm("Shrubbery", 145, 137){
	this->setTarget(target);
	std::cout << GREY << "ShrubberyCreationForm constructor" << NC << std::endl;
}

ShrubberyCreationForm::	ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()){
	std::cout << GREY << "ShrubberyCreationForm copy constructor" << NC << std::endl;
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src){
	this->setSignature(src.getSignature());
	this->setTarget(src.getTarget());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << GREY << "ShrubberyCreationForm destructor" << NC << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::fstream file;
	try{
		if (!this->getSignature())
			throw AForm::NeedToBeSign();
		if (executor.getGrade() > this->getGradeToExec())
			throw Bureaucrat::GradeTooLowException();
		file.open ( (this->getTarget() + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
		if (!file.is_open())
			throw ShrubberyCreationForm::openProb();
		file << "                                                                                     " << std::endl;
		file << "	           _{/ _{/{|/}/}/}__           	             _{/ _{/{|/}/}/}__            " << std::endl;
		file << "             {/{//}{/{//}(/}{//} _                     {/{//}{/{//}(/}{//} _         " << std::endl;
		file << "            {/{//}{/{//}(_)/}{/{//}  _                {/{//}{/{//}(_)/}{/{//}  _     " << std::endl;  
		file << "         {/{/(/}/}{/{//}/}{/){//}/} //}            {/{/(/}/}{/{//}/}{/){//}/} //}    " << std::endl; 
		file << "        {/{/(_)/}{/{/)/}{/(_){/}/}/}/}            {/{/(_)/}{/{/)/}{/(_){/}/}/}/}     " << std::endl;   
		file << "       _{/{/{/{/{/{/(_)/}/}/}{/(/}/}/}           _{/{/{/{/{/{/(_)/}/}/}{/(/}/}/}     " << std::endl;  
		file << "      {/{/{/{/{/(/}{/{//}/}{/}(_){//}/}         {/{/{/{/{/(/}{/{//}/}{/}(_){//}/}    " << std::endl;       
		file << "      _{/{/{/{/(_)/}/}{/{/{//}/})/}{//}         _{/{/{/{/(_)/}/}{/{/{//}/})/}{//}    " << std::endl;         
		file << "     {/{/{/{/(/}{/{/{/{//})/}{/(_)/}/}/}       {/{/{/{/(/}{/{/{/{//})/}{/(_)/}/}/}   " << std::endl;       
		file << "      {/{//}(_){/{/{//}/}(_){//}{//}/})/}       {/{//}(_){/{/{//}/}(_){//}{//}/})/}  " << std::endl;  
		file << "       {/{/{//}{/{/{/{//}/}{/{//}/}/}(_)         {/{/{//}{/{/{/{//}/}{/{//}/}/}(_)   " << std::endl;    
		file << "      {/{/{//}{/){/{/{//}/}{/{/(/}/}/}/}        {/{/{//}{/){/{/{//}/}{/{/(/}/}/}/}   " << std::endl; 
		file << "       {/{/{//}(_){/{/{/(/}/}{/(_)/}/}/}         {/{/{//}(_){/{/{/(/}/}{/(_)/}/}/}   " << std::endl;         
		file << "         {/({/{/{/{/{//}(_){//}/}/}/}(/}           {/({/{/{/{/{//}(_){//}/}/}/}(/}   " << std::endl;      
		file << "          (_){/{//}{/{//}/}{/{/)/}/}(_)             (_){/{//}{/{//}/}{/{/)/}/}(_)    " << std::endl;       
		file << "            {/{/{/{//}{/{/{/{/(_)/}                   {/{/{/{//}{/{/{/{/(_)/}        " << std::endl;    
		file << "             {/{/{/{//}/}{/{//}/}                      {/{/{/{//}/}{/{//}/}          " << std::endl;   
		file << "              {){/ {//}{//} /}/}                        {){/ {//}{//} /}/}           " << std::endl;          
		file << "              (_)  /.-'.-/                              (_)  /.-'.-/                 " << std::endl;          
		file << "          __...--- |'-.-'| --...__                  __...--- |'-.-'| --...__         " << std::endl;      
		file << "   _...--   .-'    |'-.-'|  ' -.  --..._______...--   .-'    |'-.-'|  ' -.  --..__   " << std::endl;        
		file << " -    ' .  . '     |.'-._| '  . .  '    .  -    ' .  . '     |.'-._| '  . .  '       " << std::endl; 
		file << " .  '-  '    .--'  | '-.'|    .  '  . '    .  '-  '    .--'  | '-.'|    .  '  . '    " << std::endl;         
		file << "          ' ..     |'-_.-|                          ' ..     |'-_.-|                 " << std::endl;     
		file << "  .  '  .       _.-|-._ -|-._  .  '  .   .   .  '  .       _.-|-._ -|-._  .  '  .     " << std::endl;
		file << "              .'   |'- .-|   '.                         .'   |'- .-|   '.            " << std::endl;      
		file << "  ..-'   ' .  '.   `-._.-   .'  '  - .   -  ..-'   ' .  '.   `-._.-   .'  '  - .     " << std::endl;       
		file << "   .-' '        '-._______.-'     '  . . _ . .-' '        '-._______.-'     '  .     " << std::endl;      
		file.close();
		std::cout << executor.getName() << " create the document " << this->getTarget() << "_Shrubbery" << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << RED << "Creation Error : " << e.what() << NC << std::endl;
	}
}
