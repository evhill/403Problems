/* UVa problem: 11837 - Musical Plagiarism
 * Topic: Strings
 * Brief problem description:
 *   Given a two input strings X and Y, determine if Y is a copy of X based on 
 *   rules of musical theory. 
 *
 * Solution Summary:
 *   A song that has been copied and transposed from an original song
 *   into a new 'key' will retain the same distance (or intervals) between notes. 
 *   To find the intervals, all we need to do is get the difference between consecutive
 *   notes. 
 *   
 *   For example: A song of A-B-C-D will have note intervals of 2-1-2 since A=1, B=3, C=4, 
 *   and D=5. If we have a suspicious song of D-E-F-G, we can determine that it is a copy 
 *   because the intervals are also 2-1-2.
 *   
 *   As a check, if we just take the value of A-B-C-D and D-E-F-G we see that the numerical
 *   value of these two songs is 1-3-4-6 and 6-8-9-11. Each note of the second song is a difference
 *   of 5 from the original song. In other words, the copy song has taken the original song and 
 *   transposed all the notes up 5 whole tones. 
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;

map<string, int> music;
vector<int> song, copy_s;
string orig_intervals, copy_intervals;

//MinGW has a problem with to_string so I used this to compile
namespace fix {
	std::string to_string(int n) {
		std::ostringstream strm;
		strm << n;
		return strm.str();
	}
}

void EquivalentNotes() {
	music["A"] = 1;
	music["A#"] = 2;
	music["Bb"] = 2;
	music["B"] = 3;
	music["B#"] = 4;
	music["Cb"] = 3;
	music["C"] = 4;
	music["C#"] = 5;
	music["Db"] = 5;
	music["D"] = 6;
	music["D#"] = 7;
	music["Eb"] = 7;
	music["E"] = 8;
	music["E#"] = 9;
	music["Fb"] = 8;
	music["F"] = 9;
	music["F#"] = 10;
	music["Gb"] = 10;
	music["G"] = 11;
	music["G#"] = 12;
	music["Ab"] = 12;

}

int notesToInts(string a) {
	return music.find(a)->second;
}

void getIntervals(vector<int> &notes, string &intervals) {
	int last = 0, temp;
	vector<int>::iterator it = notes.begin();
	last = *it;
	it++;

	intervals.append(" "); //important or you'll get issues with find() (ex: 11 and 1)
	for (; it != notes.end(); it++) {
		if (last > *it)
			temp = (*it + 12) - last;
		else
			temp = (*it - last);

		intervals.append(fix::to_string(temp));
		intervals.append(" ");
		last = *it;
	}
}

int checkIntervals(string &real, string &fake) {
	int pos = 0;
	pos = real.find(fake);
	return pos;
}

int main() {
	EquivalentNotes();
	vector<int>::iterator it;
	string temp;
	int song_len, copy_len, note_value;

	while (cin >> song_len >> copy_len) {
		if (copy_len == 0 && copy_len == 0)
			break;

		int found_position = -1;

		song.clear();
		copy_s.clear();
		orig_intervals.clear();
		copy_intervals.clear();

		for (int i = 0; i < song_len; i++) {
			cin >> temp;
			note_value = notesToInts(temp);
			song.push_back(note_value);
		}

		for (int i = 0; i < copy_len; i++) {
			cin >> temp;
			note_value = notesToInts(temp);
			copy_s.push_back(note_value);

		}


		getIntervals(song, orig_intervals);
		getIntervals(copy_s, copy_intervals);

		if(copy_len == 1){
			cout << "S" << endl;
		} else {
			found_position = checkIntervals(orig_intervals, copy_intervals);
			if (found_position >= 0)
				cout << "S" << endl;
			else
				cout << "N" << endl;
		}
	}

	return 0;
}
