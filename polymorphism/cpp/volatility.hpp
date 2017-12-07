#ifndef VOLATILITY_HPP
#define VOLATILITY_HPP

#include <string>
#include <iostream>
#include <vector>

namespace mathphi
{
    // VOLATILITY CLASS
	class volatility
    {
	
	/*
	- PUBLIC:		Access granted to everyone
	- PRIVATE:		Access granted to class only
	- PROTECTED:	Access granted to class and inheriting classes
	*/
	
	private:
		std::string m_name;
	
	protected:
	/*Only accessibled in the class hiearchy (in the class itself)*/
		int m_id;
	
	public:
		// Default constructor
		/*
		==============================================================
		We use explicit
		
		It avoids implicit conversion (bug)
		
			int compute(const implied_volatility& v);
			compute("bnp");
		
		instead of:
		
			int compute(const v("bnp"));
		==============================================================
		*/
		
		explicit volatility(const std::string& name = "");
		
        const std::string& underlying_name() const;
	
    };

		
		
	// IMPLIED VOLATILITY SUB-CLASS
    class implied_volatility : public volatility
    {
	public:
		// Default constructor
		explicit implied_volatility(const std::string& name = "");
		void print() const;
		
	
    };
}

#endif
