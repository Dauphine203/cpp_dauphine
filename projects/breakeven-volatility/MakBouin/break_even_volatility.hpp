#ifndef BREAK_EVEN_VOLATILITY_HPP
#define BREAK_EVEN_VOLATILITY_CPP
#include <ostream>
#include <string>

namespace project
{
	class vol // maybe to delete
	{
		public:
			explicit vol(const size_t mat, const double strike, const std::string underlying);
			virtual ~vol();

		private:
		protected:

	}

	class pricer : public vol // maybe to change
	{
		public:
			//constructor and destructor
			pricer(const std::vector<double>& underlying, const double& strike, const double& vol, const std::vector<double>& rate ,const size_t& mat);
			~pricer();

			//pricer and delta of the option
			const BS_pricer(const std::vector<double>& underlying, const double& strike, const double&vol, const std::vector<double>& rate, const size_t& mat) const;
			const BS_delta(const std::vector<double>& underlying, const double& strike, const double&vol, const std::vector<double>& rate, const size_t& mat) const;



		private:

			// don't know just put it here but maybe to be removed
			double& spot; 
			double& vol;
			size_t& mat;
			double& strike;
		protected:
	}

	class PnL : public vol //maybe to change
	{
		public:

			//constructor and destructor
			PnL(const std::vector<double>& underlying, const double& strike, const double& vol, const std::vector<double>& rate ,const size_t& mat);
			~PnL();

			//computation of the PnL, use of the pricers formulas
			const Hedged_PnL(const std::vector<double>& underlying, const double& strike, const double& vol, const std::vector<double>& rate, const size_t& mat) const;
			//maybe have a get_vol method here, since we will find the fair vol here

		
		private:
		protected:
	}
	
}


#endif
