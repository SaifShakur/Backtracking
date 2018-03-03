//Saif Shakur

#include<iostream>
#include<string>
#include<vector>

bool checkmatch(std::string, const std::string&, const std::vector<std::string>&, std::vector<int>&);	//Checks whether a "key" can be encrypted using a vector of "elements" 
bool checkpartial(std::string&, const std::string&);	//Checks if the "res" is equal to the "key" relative to the length of "res"

int main(){

	std::vector<std::string> elements; 	//---[elements]--- 	: a vector used to store the concatenating values
	std::vector<int> stack4output;		//---[stack4output]--- : a vector that we use to store the values that concatenate to form the key
	int size;				//---[size]---	: size of vector "elements"
	std::string res = "";			//---[res]---   	: a string used in our functions (checkmatch, checkpartial) to determine if 
						//		the result of the current "elements" being concatenated together form our key 
	std::string key, input;			//---[key]--- 	: the target we are searching for through the backtracking algorithm.
						//---[input]---	: string used for input from the user

	std::cout << std::endl;
	std::cout << "Enter the target string (a non-zero/non-negative/non-decimal integer): ";	//Accquring the target string (key) 
																							//	that we are searching for 
	std::cin >> key;
	std::cout << std::endl;

	std::cout << "Enter the size of \"elements\" set: ";	//Accquring size of the set of "elements" 
	std::cin >> size;

	while((std::cin.fail()) || (size <= 0)){

		std::cin.clear();
		std::cin.ignore();
		std::cout << "ERROR! Please enter a valid value (a non-zero/non-negative/non-decimal integer): ";
		std::cin >> size;
	}
	
	std::cout << std::endl;
	std::cout << "Enter the elements: " << std::endl;	//Accquring the set of "elements" we are using to concatenating to form the target string

	for(int i = 0; i < size; i++){				//Forming the list of "elements"

		std::cout << "Element [" << i << "]: ";
		std::cin >> input;
		elements.push_back(input);			
	}

	if( checkmatch(res, key, elements, stack4output) ){
			
		std::cout << "Target string (" << key << ") sequence: ";

		for(int i = 0; i < stack4output.size(); i++)	//Outputing the sequence of indices which make up the target string
			std::cout << stack4output[i] << " ";
	}
	else
		std::cout << "ERROR! TARGET STRING CAN'T BE ENCRYPTED!" << std::endl;	//Output if we cannot encrypt the key

	std::cout << std::endl;

	return 0;
}

//---[res]--- : the result from our search that we want to equal the "key"
//---[key]--- : the target string we want to encrypt using the sequence of indices from "elements"
//---[elements]---: vector of user defined elements that could be used to encrypt the "key" (based on index in the vector)
//---[stack4output]---: vector we use to store the current "valid" index's of "elements" that form the "key"
//Pre-Condition: Takes two strings ("res" and "key") and two vectors ("elements" and "stack4output")
//Post-Condition: Returns true if the "key" can be encrypted. Returns false otherwise.
bool checkmatch(std::string res, const std::string& key, const std::vector<std::string>& elements, std::vector<int>& stack4output){

	for (int i = 0; i < elements.size(); i++){

		if(res == key)				//The key is matched with the current "res", so we exit function
			return true;

		res = res + elements[i];		//Testing the "i"th element in the vector of elements
	
		if(checkpartial(res,key)){		//If we have a match, we continue down that particular version of "res"
			
			stack4output.push_back(i);	//Storing index "i" since it yielded a partial match

			if( checkmatch(res, key, elements, stack4output) ) 	//RECURSION: So far we have a partial match, so we will recursively call the function
				return true;					//	(checkmatch) to determine if it is part of the final sequence of indices which
										//	compose the key.  					

			stack4output.pop_back();	//BACKTRACKING: If "checkmatch" results in a FALSE, then we have to backtrack by removing the index we added, as it 
							//	does not lead to a successful path
		
		}
		res = res.erase((res.size() - elements[i].size()), elements[i].size());		//BACKTRACKING: Removing the last added element from the "elements" vector
												//	from "res." We do this to revert "res" back to it's state prior to
												//	checking whether adding the next element in the "elements" vector 
												//	yields a partial match to the key (using the "checkpartial" function)

	}
	return false;		//We've exhausted all elements of the vector and have not found a match
		
}

//---[res]--- : the result from our search that we want to equal the "key"
//---[key]--- : the target string we want to encrypt using the sequence of indices
//Pre-Condition: takes two strings ("res" and "key")
//Post-Condition: returns whether or not the two strings are equal relative to "res"'s length
bool checkpartial(std::string& res, const std::string& key){

	std::string tempkey = key.substr(0, res.length());	//We take the length size of "res" from "key" to check if what is in "res" 
								//	matches the same length of "key"	
	if(tempkey == res) 
		return true;		//The two strings match
	else 
		return false;		//The two strings do not match
}
