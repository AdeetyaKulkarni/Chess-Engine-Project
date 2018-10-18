//Name= Elham Hojati
//Lab501 or Lab503 

#include "project1.h"

string string_parser(string s) {


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

		temp = par_str.substr(start, 4);
		pssep.push_back(temp);
		start += 4;


	}

	return pssep;
}



position readPosition(string s)
{

	row r(8, "e");
	position pos(8, r);
	//-------------------------------------------------------------

		//string s = "BK8a Bb8b    WK8cBp7a Bp7b Wp6b Wr1a";

		//String parser function to remove spaces.
	string par_str;
	par_str = string_parser(s); \
		//cout << "Parsed string = " << par_str <<"\n";

//-------------------------------------------------------------

	//Seperator function to seperate piece strings into vector

		int num_piecestr = (par_str.length()) / 4;
	vector<string>pssep;
	pssep = create_piecevec(num_piecestr, par_str);

	for (int i = 0; i < num_piecestr; i++) {

		//cout << "pieces=" << pssep[i] << "\n";
	}



	//-------------------------------------------------------------

		//store piece, rank, file from each vector index and place them in pos[rank][file]

	string piece, temp, temp1;
	int rank;
	int file; //convert alphabet to integer before insert

	cout << "\n";

	for (int i = 0; i < num_piecestr; i++) {

		piece = pssep[i].substr(0, 2);

		rank = (int)pssep[i][2];
		rank = rank - 48 - 1; //Convert to int //-1 to place in vec-index.

		file = (int)pssep[i][3];
		file = file - 97;

		//testing:
	//	cout << "piece=" << piece << "\n";
	//	cout << "rank=" << rank << "\n";
	//	cout << "file=" << file << "\n\n";

		//place into position vector

		pos[rank][file] = piece;


	}

	return pos;

	//system("pause");

}
