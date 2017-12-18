#ifndef VOLATILITY_HPP
#define VOLATILITY_HPP

#include <string>
#include <iostream>
#include <vector>

/*If you don't use*/

namespace dauphine
{
	// VOLATILITY (class)
	class volatility{
		
	public:
		// Basic commands
		explicit volatility(const std::string& name = "");
		virtual ~volatility();
		const std::string& underlying_name() const;
		
		// Something here
		virtual double get_volatility(size_t index) const = 0;
		virtual void print() const;
		
		// Emaluating a copy constructor (to call it outside of the class)
		//virtual volatility* clone() const = 0;
		
	
	private:
		std::string m_name;
	
	};
	
	// IMPLIED VOLATILLITY (subclass)
	class implied_volatility : public volatility
	{
		
		public:
			implied_volatility(const std::string& name, const std::vector<double>& vol);
			virtual ~implied_volatility();
			virtual double get_volatility(size_t index) const;
			virtual void print() const;
			
		private:
			std::vector<double> m_volatility;
	};
	
	// BUMBED VOLATILITY (subclass)
	class bumped_volatility : public volatility
	{
		public:
			bumped_volatility(volatility* vol, double bump);
			virtual ~bumped_volatility();
			virtual double get_volatility(size_t index) const;
			virtual void print() const;
			
		private:
			volatility* p_volatility;
			double m_bump;
	};
	
	volatility* make_volatility(const std::string& ud, const std::vector<double>& vol);
	volatility* make_volatility(volatility* vol, double bump);
	
}

#endif
