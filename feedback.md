**5/29/2025**
*  **feedback.md is for instructor use only. DO NOT change the feedback.md**; make a copy if needed
* class definition style & standards:  first, member vars  none per line and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
* inadequate and/ insufficient test data/ not all possible scenarios and edge cases have been tested; e.g., each record has 4 pieces of data; pow(2,4)->16  possible combinations of valid/invalid and only one of them is a valid record; all menu options should be tested;  no zeros, negative numbers, etc; must test all created functions -5
* same mistakes as before  - 30
* operator – cause the program to crash  -20
```test
terminate called after throwing an instance of 'FractionException'
  what():  std::exception
```
* class Fraction does not provide a strong exception guarantee; all exception to be caught and handled by setFractions() with 3 args; discussed in the class and previous lab(s) -5
* 112 when is this going to happen -2 
*  #15 common name is what()


