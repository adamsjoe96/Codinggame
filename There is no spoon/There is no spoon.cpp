#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <utility> // std::pair std::make_pair
#include<memory>

using namespace std;

/**
* Don't let the machines win. You are humanity's last hope...
**/


std::unique_ptr<std::pair<int, int>> checkLeft(int i, int j, auto &arr)
{
	cerr << "in checkLeft, i: " << i << " j: " << j << "\n";
	while (i >= 0 && arr[i][j] == "")
	{
		i--;
	}
	cerr << "in checkLeft2, i: " << i << " j: " << j << "\n";
	if (i >= 0 && arr[i][j] != "")
		return make_unique<pair<int, int> >(make_pair(i, j));
	else
		return nullptr;
}

std::unique_ptr<std::pair<int, int>> checkTop(int i, int j, auto &arr)
{
	cerr << "in checktop, i: " << i << " j: " << j << "\n";
	while (j >= 0 && arr[i][j] == "")
	{
		j--;
	}
	cerr << "in checktop2, i: " << i << " j: " << j << "\n";
	if (arr[i][j] != "")
		return make_unique<pair<int, int> >(make_pair(i, j));
	else
		return nullptr;
}

std::unique_ptr<std::pair<int, int>> checkBottom(int i, int j, auto &arr)
{
	cerr << "in checkBottom, i: " << i << " j: " << j << "\n";
	while (j <arr.size() && arr[i][j] == "")
	{
		j++;
	}
	cerr << "in checkBottom2, i: " << i << " j: " << j << "\n";
	if (arr[i][j] != "")
		return make_unique<pair<int, int> >(make_pair(i, j));
	else
		return nullptr;
}
void print(int iv, int jv, int hv, int vv, int ev, int pv, auto& arrv)
{
	arrv[iv][jv] = to_string(iv) + " " + to_string(jv) + " " + to_string(hv) + " " + to_string(vv) + " " + to_string(ev) + " " + std::to_string(pv);
	cerr << iv << " " << jv << " " << hv << " " << vv << " " << ev << " " << pv << endl;
}

void printarray(auto& arro)
{
	cerr << "Array: ";
	for (unsigned int io = 0; io<arro.size(); io++)
	{
		for (unsigned int jo = 0; jo<arro[0].size(); jo++)
		{
			std::cerr << "i: " << io << " j: " << jo << "\n" << arro[io][jo] << "\n";
			std::cout << arro[io][jo] << "\n";
		}
		std::cerr << std::endl;
	}
}
void changelinks(int iu, int ju, int x, int y, int w, int h, auto& arru)
{
	cerr << "i: " << iu << " j: " << ju << " x: " << x << " y: " << y << endl;
	if (iu >= 0 && iu <w && ju >= 0 && ju <h)
	{
		string s = arru[iu][ju];
		if (s.compare("") != 0)
		{
			s.replace(s.begin() + 4, s.begin() + 7, to_string(x) + " " + to_string(y));
			arru[iu][ju] = s;
			cerr << "arr[" << iu << "]" << "[" << ju << "]: " << arru[iu][ju] << endl;
		}
	}

}

void changeleft(int iu, int ju, int x, int y, int w, int h, auto& arru)
{
	cerr << "i: " << iu << " j: " << ju << " x: " << x << " y: " << y << endl;
	if (iu >= 0 && iu <w && ju >= 0 && ju <h)
	{
		string s = arru[iu][ju];
		if (s.compare("") != 0)
		{
			s.replace(s.begin() + 4, s.begin() + 9, to_string(x) + " " + to_string(y));
			arru[iu][ju] = s;
			cerr << "arr[" << iu << "]" << "[" << ju << "]: " << arru[iu][ju] << endl;
		}
	}

}


void changetop(int il, int jl, int x, int y, int w, int h, auto& arrl)
{
	if (il >= 0 && il <w && jl >= 0 && jl <h)
	{
		string s = arrl[il][jl];
		if (s.compare("") != 0)
		{
			s.replace(s.begin() + (s.size() - 3), s.end(), to_string(x) + " " + to_string(y));
			arrl[il][jl] = s;
			cerr << "arr[" << il << "]" << "[" << jl << "]: " << arrl[il][jl] << endl;
		}
	}
}

void changeob(int il, int jl, int x, int y, int w, int h, auto& arrl)
{
	if (il >= 0 && il <w && jl >= 0 && jl <h)
	{
		string s = arrl[il][jl];
		if (s.compare("") != 0)
		{
			s.replace(s.begin() + (s.size() - 5), s.end(), to_string(x) + " " + to_string(y));
			arrl[il][jl] = s;
			cerr << "arr[" << il << "]" << "[" << jl << "]: " << arrl[il][jl] << endl;
		}
	}


}

void adjust(int i, int j, int w, int h, auto &arr)
{
	if (i - 1 >= 0 && arr[i - 1][j] == "")
	{
		auto link = checkLeft(i - 1, j, arr);
		if (link != nullptr)
		{
			changeleft(link->first, link->second, i, j, w, h, arr);
		}
	}
	if (j - 1 >= 0 && arr[i][j - 1] == "")
	{
		auto top = checkTop(i, j - 1, arr);
		if (top != nullptr)
		{
			changeob(top->first, top->second, i, j, w, h, arr);
		}
	}
}
int main()
{
	int width; // the number of cells on the X axis
	cin >> width; cin.ignore();
	int height; // the number of cells on the Y axis
	cin >> height; cin.ignore();
	cerr << "width: " << width << " height: " << height << endl;
	std::vector<std::vector<string> > arr{ width, vector<string>{height} };
	for (int j = 0; j < height; j++) {
		string line; // width characters, each either 0 or .
		getline(cin, line);
		cerr << "line is: " << line << endl;
		int opa = 0;
		for (string::iterator it = line.begin(); it != line.end(); it++)
		{

			cerr << " it: " << *it << " opa: " << opa << endl;
			for (int i = opa; i <= opa; i++)
			{
				//cerr << "i: " << i << "\n";
				if (*it != '.')
				{
					if (j < height - 1 && i == width - 1)
					{
						print(i, j, -1, -1, i, j + 1, arr);
						adjust(i, j, width, height, arr);

						//printarray(arr);
					}
					else if (j == height - 1 && i < width - 1)
					{
						print(i, j, i + 1, j, -1, -1, arr);
						adjust(i, j, width, height, arr);
						//printarray(arr);
					}
					else if (j == height - 1 && i == width - 1)
					{
						std::cerr << "i: " << i << " j: " << j << endl;
						cerr << "do nothing " << endl;
						//print(i, j, -1, -1, -1, -1, arr);
						//adjust(i, j, width, height, arr);
					}
					else
					{

						print(i, j, i + 1, j, i, j + 1, arr);
						adjust(i, j, width, height, arr);
						//printarray(arr);
					}
				}
				else
				{
					cerr << "i: " << i << " j: " << j << endl;
					cerr << "error" << endl;
					auto iter = it + 1;
					/*int tmp = opa+1;
					while (iter != line.end() && *iter == '.')
					{
					iter++;
					tmp++;
					}
					if(*iter != '.')
					{
					changelinks(i-1, j, tmp, j, width, height, arr);
					}
					else
					{
					changelinks(i-1, j, -1, -1, width, height, arr);
					opa =tmp;
					}*/
					if (i - 1 >= 0 && arr[i - 1][j] != "")
					{
						changelinks(i - 1, j, -1, -1, width, height, arr);
					}
					if (j - 1 >= 0 && arr[i][j - 1] != "")
					{
						changetop(i, j - 1, -1, -1, width, height, arr);
					}
				}

			}
			opa++;
		}
	}
	cerr << "Ultimate array: " << endl;
	for (unsigned int i = 0; i< arr.size(); i++)
	{
		for (unsigned int j = 0; j <arr[0].size(); j++)
		{
			if (arr[i][j] == "")
			{
				//arr[i][j] = to_string(i) + " " + to_string(j) + " -1 -1 -1 -1";
				// arr[i][j] = "x1 y1 x2 y2 x3 y3";
			}
		}
	}
	printarray(arr);
}