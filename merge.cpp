#include <iostream>
#include <vector>

using namespace std;

// prompts user to give a word and returns the answer
string get_input() {
	string input = {""};
	cout << "input a word to merge...\n";
	cin >> input;

	return input;
}

// merges word1 (from beginning to index i1 not included) with
// word2 (from index i2 to the end)
string merge_on(string word1, string word2, int i1, int i2) {
	string merged;
	merged.append(word1, 0, i1);
	merged.append(word2, i2, string::npos);
	return merged;
}

// returns a list of possible merging of the two words
vector<string> merge(string word1, string word2) {

	vector<string> possible_merge;

	for (int i = word1.length()-2; i > 0; i--) {
		const char a = word1[i];
		for (int j = 0; j <= word2.length()-2; j++) {
			if (a == word2[j]){
				possible_merge.push_back(merge_on(word1, word2, i, j));
			}
		}
	}

	// reverse order
	for (int i = word2.length()-2; i > 0; i--) {
		const char a = word2[i];
		for (int j = 0; j <= word1.length()-2; j++) {
			if (a == word1[j]){
				possible_merge.push_back(merge_on(word2, word1, i, j));
			}
		}
	}

	return possible_merge;
}

// returns vector of the longest strings from a vector of strings
vector<string> longest_strings(vector<string>& vect) {
	vector<string> output;
	string longest = vect[0];
	for (const string& str : vect) {
		if (str.length() > longest.length())
			longest = str;
	}
	for (const string& str : vect) {
		if (str.length() == longest.length())
			output.push_back(str);
	}
	return output;
}

// prints the content of a vector of strings
void print_vect(vector<string> vect) {
	for (const string& str : vect)
		cout << str << "\n";
}

int main() {
	string word1 = get_input();
	string word2 = get_input();
	vector<string> merges = merge(word1, word2);

	cout << "best merge(s) of " << word1 << " with " << word2 << " :\n";
	print_vect(longest_strings(merges));
	cout << "other possible merges are :\n";
	print_vect(merges);
}
