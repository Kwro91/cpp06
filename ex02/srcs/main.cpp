#include "../includes/Functions.hpp" //contain all

int main (){
	std::cout << GREEN << "/////////////////RANDOM_GENERATION///////////////////" << WHITE << std::endl;
	try{ //generate A B or C with generate()
		Base *p = generate();
		Base &t = *p;
		identify(p);
		identify(t);
		delete p;
		std::cout << GREEN << "///////////////////TRY_A_B_C_NULL////////////////////////" << WHITE << std::endl;
	}
	catch (std::exception &e){
		(void)e;
	}
//////////////////////////////////////////////////////////////
	try{ //generate A and test identify
		Base *p = new A();
		Base &t = *p;
		identify(p);
		identify(t);
		delete p;
		std::cout << std::endl;
	}
	catch (std::exception &e){
		(void)e;
	}
//////////////////////////////////////////////////////////////
	try{ //generate B and test identify
		Base *p = new B();
		Base &t = *p;
		identify(p);
		identify(t);
		delete p;
		std::cout << std::endl;
	}
	catch (std::exception &e){
		(void)e;
	}
//////////////////////////////////////////////////////////////
	try{ //generate C and test identify
		Base *p = new C();
		Base &t = *p;
		identify(p);
		identify(t);
		delete p;
		std::cout << std::endl;
	}
	catch (std::exception &e){
		(void)e;
	}
//////////////////////////////////////////////////////////////
try{ //generate NULL and test identify
	Base *p = NULL;
	Base &t = *p;
	identify(p);
	identify(t);
	delete p;
}
catch (std::exception &e){
	(void)e;
}
	return (0);
}