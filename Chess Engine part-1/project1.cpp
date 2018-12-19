//Name= Adeetya Kulkarni
//Lab503 

#include "project1.h"

string string_parser(string s) {

	//Loop through full input string check if space then remove from string.

	for (int i = 0; i < (signed)s.length() - 1; i++) {

		//cout << "s[i]" << s[i] << "\n"; //testing

		if (s[i] == ' ') {

			//cout << s[i] << "is erased" << "\n"; //testing
			s.erase(i, 1);
			i--; //get back erased index.


		}
		else {

			//cout << s[i] << "is not erased" << "\n"; //testing
			continue;

		}

	}

	return s;

}


vector<string> create_piecevec(int num_piecestr, string par_str) {


	int start = 0; // starting index

	string temp;

	vector<string> pssep; //seperated piece strings

	//loop n times remove from start to end to temp string then push to vector and then double start and end. 

	for (int i = 0; i < num_piecestr; i++) {

		temp = par_str.substr(start, 4); //getting every four elements and storing them in temp
		pssep.push_back(temp); //pushing temp to vector of string (piece-string)
		start += 4; //every 4 elements.


	}

	return pssep;
}



position readPosition(string s)
{

	row r(8, "e");
	position pos(8, r);
//-------------------------------------------------------------

	//String parser function to remove spaces.

	string par_str;
	par_str = string_parser(s); 
		//cout << "Parsed string = " << par_str <<"\n"; //testing

//-------------------------------------------------------------

	//Seperator function to seperate piece strings into vector

	int num_piecestr = (par_str.length()) / 4; //get number of pieces in the vector.
	vector<string>pssep; // pssep - piece string separated.

	pssep = create_piecevec(num_piecestr, par_str);

	//testing.
	//for (int i = 0; i < num_piecestr; i++) {

		//cout << "pieces=" << pssep[i] << "\n";
	//}



//-------------------------------------------------------------

	//store piece, rank, file from each vector index and place them in pos[rank][file]

	string piece, temp, temp1;
	int rank;
	int file; //convert alphabet to integer before insert

	for(int i = 0; i < num_piecestr; i++) {

		piece = pssep[i].substr(0, 2);

		rank = (int)pssep[i][2];
		rank = rank - 48 - 1; //Convert to int //-1 to place in vec-index.

		file = (int)pssep[i][3];
		file = file - 97;//convert alphabets to 'file'

		//testing:
	//	cout << "piece=" << piece << "\n";
	//	cout << "rank=" << rank << "\n";
	//	cout << "file=" << file << "\n\n";

		//place into position vector

		pos[rank][file] = piece;


	}

	return pos;

	system("pause");

}
