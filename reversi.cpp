#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;//0 empty 1 mine 2 enemy 3 playable
class play
{
	char h;
	int z;
public:
	char geth() { return h; }
	int getz() { return z; }
	void calplay(int * board, int* value);
	int algo(int* board, int* value, vector<int> &final, int s, int p, vector<int> &pos1);
};
int flip(int* board, int z, char h,int s)
{
	int i, u, check = 0;
	for (i = 1; i < z; i++)//up
	{
		if (board[(z - 1 - i) * 8 + h - '0' - 49] == 0)
			break;
		else if (board[(z - 1 - i) * 8 + h - '0' - 49] == s)
		{
			check = 1;
			for (u = 1; u < i; u++)
				board[(z - 1 - u) * 8 + h - '0' - 49] = s;
			break;
		}
	}
	for (i = 1; i < 9 - z; i++)//down
	{
		if (board[(z - 1 + i) * 8 + h - '0' - 49] == 0)
			break;
		else if (board[(z - 1 + i) * 8 + h - '0' - 49] == s)
		{
			check = 1;
			for (u = 1; u < i; u++)
				board[(z - 1 + u) * 8 + h - '0' - 49] = s;
			break;
		}
	}
	for (i = 1; i < h - '0' - 48; i++)//left
	{
		if (board[(z - 1) * 8 + h - '0' - 49 - i] == 0)
			break;
		else if (board[(z - 1) * 8 + h - '0' - 49 - i] == s)
		{
			check = 1;
			for (u = 1; u < i; u++)
				board[(z - 1) * 8 + h - '0' - 49 - u] = s;
			break;
		}
	}
	for (i = 1; i < 57 - (h - '0'); i++)//right
	{
		if (board[(z - 1) * 8 + h - '0' - 49 + i] == 0)
			break;
		else if (board[(z - 1) * 8 + h - '0' - 49 + i] ==s)
		{
			check = 1;
			for (u = 1; u < i; u++)
				board[(z - 1) * 8 + h - '0' - 49 + u] = s;
			break;
		}
	}
	for (i = 1; i < min(9-(h - '0' - 48),9-z); i++)//right down
	{
		if (board[(z - 1+i) * 8 + h - '0' - 49 + i] == 0)
			break;
		else if (board[(z - 1+i) * 8 + h - '0' - 49 + i] == s)
		{
			check = 1;
			for (u = 1; u < i; u++)
				board[(z - 1+u) * 8 + h - '0' - 49 + u] = s;
			break;
		}
	}
	for (i = 1; i < min(9 - (h - '0' - 48), z); i++)//right up
	{
		if (board[(z - 1 - i) * 8 + h - '0' - 49 + i] == 0)
			break;
		else if (board[(z - 1 - i) * 8 + h - '0' - 49 + i] == s)
		{
			check = 1;
			for (u = 1; u < i; u++)
				board[(z - 1 - u) * 8 + h - '0' - 49 + u] = s;
			break;
		}
	}
	for (i = 1; i < min(h - '0' - 48, z); i++)//left up
	{
		if (board[(z - 1 - i) * 8 + h - '0' - 49 - i] == 0)
			break;
		else if (board[(z - 1 - i) * 8 + h - '0' - 49 - i] == s)
		{
			check = 1;
			for (u = 1; u < i; u++)
				board[(z - 1 - u) * 8 + h - '0' - 49 - u] = s;
			break;
		}
	}
	for (i = 1; i < min(h - '0' - 48, 9-z); i++)//left down
	{
		if (board[(z - 1 + i) * 8 + h - '0' - 49 - i] == 0)
			break;
		else if (board[(z - 1 + i) * 8 + h - '0' - 49 - i] == s)
		{
			check = 1;
			for (u = 1; u < i; u++)
				board[(z - 1 + u) * 8 + h - '0' - 49 - u] = s;
			break;
		}
	}
	return check;
}
void cerrboard(int* board)
{
	int i, j;
	for (i = 1; i < 9; i++)
	{
		for (j = 1; j < 9; j++)
			cerr << board[(i - 1) * 8 + j - 1];
		cerr << endl;
	}
}
int playable(int* board)
{
	int i,z, check = 0;
	char h;
	for (z = 1; z < 9; z++)
	{
		for (h = 'a'; h < 'i'; h++)
		{
			if (board[(z - 1) * 8 + h - '0' - 49] == 0)
			{
				if (check == 0)
					for (i = 1; i < z; i++)//up
					{

						if (board[(z - 1 - i) * 8 + h - '0' - 49] == 0)
							break;
						else if (board[(z - 1 - i) * 8 + h - '0' - 49] == 1)
						{
							if (i != 1)
								check = 1;
							break;
						}
					}
				if (check == 0)
				for (i = 1; i < 9 - z; i++)//down
				{
					if (board[(z - 1 + i) * 8 + h - '0' - 49] == 0)
						break;
					else if (board[(z - 1 + i) * 8 + h - '0' - 49] == 1)
					{
						if (i != 1)
						check = 1;
						break;
					}
				}
				if (check == 0)
				for (i = 1; i < h - '0' - 48; i++)//left
				{
					if (board[(z - 1) * 8 + h - '0' - 49 - i] == 0)
						break;
					else if (board[(z - 1) * 8 + h - '0' - 49 - i] == 1)
					{
						if (i != 1)
						check = 1;
						break;
					}
				}
				if (check == 0)
				for (i = 1; i < 57 - (h - '0'); i++)//right
				{
					if (board[(z - 1) * 8 + h - '0' - 49 + i] == 0)
						break;
					else if (board[(z - 1) * 8 + h - '0' - 49 + i] == 1)
					{
						if (i != 1)
						check = 1;
						break;
					}
				}
				if (check == 0)
				for (i = 1; i < min(9 - (h - '0' - 48), 9 - z); i++)//right down
				{
					if (board[(z - 1 + i) * 8 + h - '0' - 49 + i] == 0)
						break;
					else if (board[(z - 1 + i) * 8 + h - '0' - 49 + i] == 1)
					{
						if (i != 1)
						check = 1;
						break;
					}
				}
				if (check == 0)
				for (i = 1; i < min(9 - (h - '0' - 48), z); i++)//right up
				{
					if (board[(z - 1 - i) * 8 + h - '0' - 49 + i] == 0)
						break;
					else if (board[(z - 1 - i) * 8 + h - '0' - 49 + i] == 1)
					{
						if (i != 1)
						check = 1;
						break;
					}
				}
				if (check == 0)
				for (i = 1; i < min(h - '0' - 48, z); i++)//left up
				{
					if (board[(z - 1 - i) * 8 + h - '0' - 49 - i] == 0)
						break;
					else if (board[(z - 1 - i) * 8 + h - '0' - 49 - i] == 1)
					{
						if (i != 1)
						check = 1;
						break;
					}
				}
				if (check == 0)
				for (i = 1; i < min(h - '0' - 48, 9 - z); i++)//left down
				{
					if (board[(z - 1 + i) * 8 + h - '0' - 49 - i] == 0)
						break;
					else if (board[(z - 1 + i) * 8 + h - '0' - 49 - i] == 1)
					{
						if (i != 1)
						check = 1;
						break;
					}
				}
			}
		}
	}
	return check;
}
void playablewrite(int* board, vector<int> &pos, int s)
{
	int i, z, check = 0;
	char h;
	for (z = 1; z < 9; z++)
	{
		for (h = 'a'; h < 'i'; h++)
		{
			check = 0;
			if (board[(z - 1) * 8 + h - '0' - 49] == 0)
			{
				if (check == 0)
					for (i = 1; i < z; i++)//up
					{

						if (board[(z - 1 - i) * 8 + h - '0' - 49] == 0)
							break;
						else if (board[(z - 1 - i) * 8 + h - '0' - 49] == s)
						{
							if (i != 1)
							{
								pos.push_back((z - 1) * 8 + h - '0' - 49);
								check = 1;
							}
							break;
						}
					}
				if (check == 0)
					for (i = 1; i < 9 - z; i++)//down
					{
						if (board[(z - 1 + i) * 8 + h - '0' - 49] == 0)
							break;
						else if (board[(z - 1 + i) * 8 + h - '0' - 49] == s)
						{
							if (i != 1)
							{
								pos.push_back((z - 1 ) * 8 + h - '0' - 49);
								check = 1;
							}
							break;
						}
					}
				if (check == 0)
					for (i = 1; i < h - '0' - 48; i++)//left
					{
						if (board[(z - 1) * 8 + h - '0' - 49 - i] == 0)
							break;
						else if (board[(z - 1) * 8 + h - '0' - 49 - i] == s)
						{
							if (i != 1)
							{
								pos.push_back((z - 1) * 8 + h - '0' - 49);
								check = 1;
							}
							break;
						}
					}
				if (check == 0)
					for (i = 1; i < 57 - (h - '0'); i++)//right
					{
						if (board[(z - 1) * 8 + h - '0' - 49 + i] == 0)
							break;
						else if (board[(z - 1) * 8 + h - '0' - 49 + i] == s)
						{
							if (i != 1)
							{
								pos.push_back((z - 1) * 8 + h - '0' - 49);
								check = 1;
							}
							break;
						}
					}
				if (check == 0)
					for (i = 1; i < min(9 - (h - '0' - 48), 9 - z); i++)//right down
					{
						if (board[(z - 1 + i) * 8 + h - '0' - 49 + i] == 0)
							break;
						else if (board[(z - 1 + i) * 8 + h - '0' - 49 + i] == s)
						{
							if (i != 1)
							{
								pos.push_back((z - 1 ) * 8 + h - '0' - 49);
								check = 1;
							}
							break;
						}
					}
				if (check == 0)
					for (i = 1; i < min(9 - (h - '0' - 48), z); i++)//right up
					{
						if (board[(z - 1 - i) * 8 + h - '0' - 49 + i] == 0)
							break;
						else if (board[(z - 1 - i) * 8 + h - '0' - 49 + i] == s)
						{
							if (i != 1)
							{
								pos.push_back((z - 1 ) * 8 + h - '0' - 49);
								check = 1;
							}
							break;
						}
					}
				if (check == 0)
					for (i = 1; i < min(h - '0' - 48, z); i++)//left up
					{
						if (board[(z - 1 - i) * 8 + h - '0' - 49 - i] == 0)
							break;
						else if (board[(z - 1 - i) * 8 + h - '0' - 49 - i] == s)
						{
							if (i != 1)
							{
								pos.push_back((z - 1 ) * 8 + h - '0' - 49);
								check = 1;
							}
							break;
						}
					}
				if (check == 0)
					for (i = 1; i < min(h - '0' -48, 9 - z); i++)//left down
					{
						if (board[(z - 1 + i) * 8 + h - '0' - 49 - i] == 0)
							break;
						else if (board[(z - 1 + i) * 8 + h - '0' - 49 - i] == s)
						{
							if (i != 1)
							{
								pos.push_back((z - 1 ) * 8 + h - '0' - 49);
								check = 1;
							}
							break;
						}
					}
			}
		}
	}
}
int play::algo(int* board,int* value, vector<int> &final,int s,int p,vector<int> &pos1)
{
	int i,u;
	vector<int> pos2;
	vector<int> values;
	vector<int> values2;
	vector<int> mob2;
	vector<int> bigv2s;
	vector<int> PASS;
	playablewrite(board, pos1,s);//s=1
	for (i = 0; i < pos1.size(); i++)
	{
		values.push_back(value[pos1[i]]);
		int *board1=new int[64];
		for (u = 0; u < 64; u++)
			board1[u] = board[u];
		board1[pos1[i]] = 1;
		playablewrite(board1, pos2, p);//p=2
		if (pos2.size() != 0)
		{
			for (u = 0; u < pos2.size(); u++)
				values2.push_back(value[pos2[u]]);
			std::vector<int>::iterator bigv2 = std::max_element(std::begin(values2), std::end(values2));
			bigv2s.push_back(*bigv2);
		}
		else
		{
			PASS.push_back(pos1[i]);
			bigv2s.push_back(0);
		}
		mob2.push_back(pos2.size());
		delete[]board1;
		values2.clear();
	}
	if (PASS.size() == 0)
	{
		std::vector<int>::iterator biggestv = std::max_element(std::begin(values), std::end(values));
		std::vector<int>::iterator smallestm = std::min_element(std::begin(mob2), std::end(mob2));
		std::vector<int>::iterator bigbigv2s = std::max_element(std::begin(bigv2s), std::end(bigv2s));
		std::vector<int>::iterator smbigv2s = std::min_element(std::begin(bigv2s), std::end(bigv2s));
		if (*biggestv == 90) return pos1[distance(std::begin(values), biggestv)];
		for (i = 0; i < pos1.size(); i++)
			final.push_back((double)values[i] / (double)*biggestv + 10 * (double)*smallestm / (double)mob2[i] - 0.5*(double)bigv2s[i] / (double)*bigbigv2s);
		std::vector<int>::iterator bigf = std::max_element(std::begin(final), std::end(final));
		return pos1[distance(std::begin(final), bigf)];
	}
	else
	{
		vector<int> PASSval;
		for (i = 0; i < PASS.size(); i++)
			PASSval.push_back(value[PASS[i]]);
		std::vector<int>::iterator bigPASSval = std::max_element(std::begin(PASSval), std::end(PASSval));
		return PASS[distance(std::begin(PASSval), bigPASSval)];
	}
}
void play::calplay(int* board, int* value)
{
	int u,i,o,out,f2;
	vector<int> pos1;
	vector<int> size;
	vector<int> all;
	if (playable(board))
	{
		vector<int> final1;
		out = play::algo(board, value, final1,1,2,pos1);
		if (final1.size() != 0)
		{
			for (i = 0; i < final1.size(); i++)
			{
				int *board1 = new int[64];
				for (u = 0; u < 64; u++)
					board1[u] = board[u];
				board1[pos1[i]] = 1;
				vector<int> final2;
				vector<int> pos2;
				int out = play::algo(board1, value, final2, 2, 1, pos2);
				int judge=1;
				if (final2.size() != 0)
				{
					for (o = 0; o < final2.size(); o++)
						if (pos2[o] == out)
						{
							judge = 0;
							break;
						}
					f2 = final2[o - judge];
				}
				else f2 = 65;
				board1[out] = 2;
				vector<int> final3;
				vector<int> pos3;
				if (playable(board1))
				{
					play::algo(board1, value, final3, 1, 2, pos3);
					if (final3.size() != 0)
					{
						for (int o = 0; o < final3.size(); o++)
							all.push_back(final3[o] + final1[i] - f2);
						size.push_back(final3.size());
					}
					else
					{
						all.push_back(50);
						size.push_back(1);
					}
				}
				else 
			}
			std::vector<int>::iterator bigbig = std::max_element(std::begin(all), std::end(all));
			int p=distance(std::begin(all), bigbig);
			for (i=0;p>0;i++)
				p -= size[i];
			out=pos1[i--];
		}
		z = 1 + out / 8;
		h = 'a' + out % 8;
		board[(z - 1) * 8 + h - '0' - 49] = 1;
		flip(board, z, h, 1);
		cout << h << ' ' << z << endl;
	}
	else
		cout << "PASS" << endl;
}
int main()
{
	int value[64];
	string cmd;
	play step;
	int i, j,z,s;
	char h; 
	int board[64] = {0};
	while (cmd!="DONE")
	{
		cin >> cmd;
		if (cmd == "START")
		{
			for (i = 0; i < 64; i++)
				board[i] = 0;
		}
		else if (cmd == "PLACE")
		{
			cin >> h >> z >> s;
			if (s == 1)
				board[(z - 1) * 8 + h - '0' - 49] = 1;
			else board[(z - 1) * 8 + h - '0' - 49] = 2;
		}
		else if (cmd == "DONE")
		{
			cerrboard( board);
			cout << "OK" << endl;
		}
	}
	cin >> cmd;
	value[0] = value[7] = value[63] = value[56] = 90;
	value[1] = value[6] = value[8] = value[15] = value[48] = value[55] = value[57] = value[62] = -60;
	value[9] = value[14] = value[49] = value[54] = -80;
	for (j = 1;j < 5; j++)
		for (i = 1; i < 5;i++)
			value[8 *j + 9 + i] = 1;
	for (i = 10; i < 14; i++)
		for (j = 0; j < 2; j++)
			value[40 * j + i] = 5;
	for (i = 17; i < 42; i = i + 8)
		value[i] = 5;
	for (i = 22; i < 47; i = i + 8)
		value[i] = 5;

	for (i = 2; i < 6; i++)
		for (j = 0; j < 2; j++)
			value[56 * j + i] = 10;
	for (i = 16; i < 41; i = i + 8)
		value[i] = 10;
	for (i = 23; i < 48; i = i + 8)
		value[i] = 10;

	if (cmd == "BEGIN")
	{
		cout<<'d'<<' '<<3<<endl;
		board[19] = 1;
		board[27] = 1;
		cerrboard( board);
	}
	else//TURN
	{
		cin >> h >> z;
		board[(z - 1) * 8 + h - '0' - 49] = 2;
		flip(board, z, h, 2);
		step.calplay(board, value);
		cerrboard(board);
	}
	while (1)
	{
		cin >> cmd;
		if (cmd == "END")
			break;
		if (cmd=="TURN")
		{
			cin >> h >> z;
			board[(z - 1) * 8 + h - '0' - 49] = 2;
			flip(board, z, h, 2);
			cerrboard(board);
		}
		step.calplay(board, value);
		cerrboard(board);
	}
	return 0;
}
