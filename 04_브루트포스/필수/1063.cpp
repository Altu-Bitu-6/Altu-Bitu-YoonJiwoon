#include <iostream>
#include <string>

using namespace std;

bool rockMove(pair<char, int>& k, pair<char, int>& r) {
	if (k.first == r.first) {
		if (k.second == r.second) {
			return true;
		}
	}
	return false;
}

void kingMove(string command, pair<char,int>& k, pair<char, int>& r) {
	pair<char, int> tmp = { 'I',9 };
	if (command == "R") {
		if (k.first == 'H') {
			return;
		}
		if (k.first == 'G' && r.first == 'H' && k.second == r.second) {
			return;
		}
		else {
			k.first++;
			if (rockMove(k, r)) {
				kingMove("R", r, tmp);
			}
		}
		return;
	}
	if (command == "L") {
		if (k.first == 'A') {
			return;
		}
		if (k.first == 'B' && r.first == 'A' && k.second == r.second) {
			return;
		}
		else {
			k.first--;
			if (rockMove(k, r)) {
				kingMove("L", r, tmp);
			}
		}
		return;
	}
	if (command == "B") {
		if (k.second == 1) {
			return;
		}
		if (k.second == 2 && r.second == 1 && k.first == r.first) {
			return;
		}
		else {
			k.second--;
			if (rockMove(k, r)) {
				kingMove("B", r, tmp);
			}
		}
		return;
	}
	if (command == "T") {
		if (k.second == 8) {
			return;
		}
		if (k.second == 7 && r.second == 8 && k.first == r.first) {
			return;
		}
		else {
			k.second++;
			if (rockMove(k, r)) {
				kingMove("T", r, tmp);
			}
		}
		return;
	}
	if (command == "RT") {
		if (k.first == 'H' || k.second == 8) {
			return;
		}
		if (k.first == 'G' && r.first == 'H' && (k.second + 1) == r.second) {
			return;
		}
		if (k.second == 7 && r.second == 8 && (k.first + 1) == r.first) {
			return;
		}
		else {
			k.first++;
			k.second++;
			if (rockMove(k, r)) {
				kingMove("RT", r, tmp);
			}
		}
		return;
	}
	if (command == "LT") {
		if (k.first == 'A' || k.second == 8) {
			return;
		}
		if (k.first == 'B' && r.first == 'A' && (k.second + 1) == r.second) {
			return;
		}
		if (k.second == 7 && r.second == 8 && (k.first - 1) == r.first) {
			return;
		}
		else {
			k.first--;
			k.second++;
			if (rockMove(k, r)) {
				kingMove("LT", r, tmp);
			}
		}
		return;
	}
	if (command == "RB") {
		if (k.first == 'H' || k.second == 1) {
			return;
		}
		if (k.first == 'G' && r.first == 'H' && (k.second - 1) == r.second) {
			return;
		}
		if (k.second == 2 && r.second == 1 && (k.first + 1) == r.first) {
			return;
		}
		else {
			k.first++;
			k.second--;
			if (rockMove(k, r)) {
				kingMove("RB", r, tmp);
			}
		}
		return;
	}
	else {
		if (k.first == 'A' || k.second == 1) {
			return;
		}
		if (k.first == 'B' && r.first == 'A' && (k.second - 1) == r.second) {
			return;
		}
		if (k.second == 2 && r.second == 1 && (k.first - 1) == r.first) {
			return;
		}
		else {
			k.first--;
			k.second--;
			if (rockMove(k, r)) {
				kingMove("LB", r, tmp);
			}
		}
		return;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	pair<char, int>king;
	pair<char, int>rock;
	int n, column;
	char row;
	string command;

	cin >> row >> column;
	king.first = row;
	king.second = column;
	cin >> row >> column;
	rock.first = row;
	rock.second = column;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> command;
		kingMove(command,king,rock);
	}

	cout << king.first << king.second << "\n" << rock.first << rock.second;

	return 0;
}