

namespace dauphine
{
	class polynomial {
	
		private:
			double X;
	
		public:
			// Default constructor: initialize polynomial
			polynomial(double x = 2){
				
				// Set degree
				X = x;
				std::cout << "Created an instance of class polynomial" << std::endl;
				std::cout << "Degree: " << X << std::endl;
				
				// Initializer list
				std::vector<double> P;
				P(std::initializer_list<double> X){
					std::cout << "Constructed with a " << X.size() << "-element list" << std::endl;
				}
				
				void append(std::initializer_list<double> X){
					X.insert(X.end(), X.begin(), X.end());
				}
				
			}
	
};
}

