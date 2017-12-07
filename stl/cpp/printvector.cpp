#include <vector>
#include <iostream>

void printvector(const std::vector<double>& myvector)
{
	for(int i=0;i<myvector.size();i++)
	{
	    if(i<myvector.size()-1)
	    {
		    std::cout << myvector[i] << ",";
	    }
	    else
	    {
	        std::cout << myvector[i];    
	    }
	}
	std::cout << std::endl;
}