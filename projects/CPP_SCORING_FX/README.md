**A C++ scoring algorithm for ranking global currencies based on financial market sentiment**

Master 203 C++ Project

Features:
- An object-oriented heritage architecture that allows developpers to input their own implementations
- Uses 25D risk reversal pairwise currency data (easily available on Bloomberg Volatility Surface) to gauge financial market sentiment
- For importing data, needs 2 text files (as dataframes are not provided in C++): a string vector of currency tickers (std::vector<string>) and an antisymmetric matrix of risk reversals (std::vector<double>)
- An implementation on randomized data and a real-world snapshot is featured in this folder
- One can use butterfly values instead of risk reversal

Guide for importing data:
- For the antisymmetric matrix data to be imported into the C++ algorithm, we recommend setting up the Risk Reversal cross-currency matrix in Excel, than saving as "Text (Tab Delimited)" and using this text file for importing risk reversal data.