#ifndef BREAK_EVEN_VOLATILITY_HPP
#define BREAK_EVEN_VOLATILITY_CPP
#include <ostream>
#include <string>

namespace project
{
/*	class vol
	{
		public:
			explicit vol(const size_t mat, const double strike, const std::string underlying);
			virtual ~vol();

		private:
		protected:

	}
*/
	class pricer : public vol
	{
		public:
			pricer(const std::vector<double>& underlying, const double& strike, const double& vol, const std::vector<double>& rate ,const size_t& mat);
			~pricer();

		private:
			double& spot; 
			double& vol;
			size_t& mat;
			double& strike;
		protected:
	}

	class PnL : public vol
	{
		public:

			PnL(const std::vector<double>& underlying, const double& strike, const double& vol, const std::vector<double>& rate ,const size_t& mat);
			~PnL();
		
		private:
		protected:
	}
	
}


#endif
