#ifndef VOLATILITY_HPP
#define VOLATILITY_HPP
#include <vector>
#include <string>

namespace dauphine
{	
    class volatility
    {
		
    public:
	
		explicit volatility(const std::string& udlname=""); //prevents implicit conversion like converting a string to volatility
        const std::string& underlying_name() const;
		virtual double get_volatility(size_t index) const;
		virtual ~volatility();
		
		
	private:
		std::string m_udlname;
			
	protected:	//can be access by all children classes
	//usually include only methods in protected, not data members
		int id;
	};	
	
    class implied_volatility : public volatility
    {
		public:

			explicit implied_volatility(const std::string& name, const std::vector<double>& vol);
			void printid() const;
			virtual double get_volatility(size_t index) const;
			virtual~implied_volatility();
			
		private:
			std::vector<double> m_volatility;
    };
	
	class bumped_volatility : public volatility
	{
		public:
			explicit bumped_volatility(volatility* v, const double& bump);
			virtual~bumped_volatility();
			virtual double get_volatility(size_t index) const;
			
		private:
			volatility* p_volatility;
			double m_bump;
		
		
	};
	
	volatility* make_volatility(const std::string& ud, const std::vector<double>& vol);
    volatility* make_volatility(volatility* vol, double bump);
	
}

#endif
