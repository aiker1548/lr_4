#include"lib.h"


OrGraph::OrGraph()
{
	size = 0;
}


void OrGraph::AddVertex(vertex ver)
{
	size++;
	ver.EnterId(size);
	vers.push_back(ver);
}

void OrGraph::AddEdge(int id1, int id2)
{
	vertex& ver1 = GetVertex(id1);
	vertex& ver2 = GetVertex(id2);
	ver1.EnterInEdge(id2);
	ver2.EnterOutEdge(id1);
}
void OrGraph::DelVertex(int id)
{
	vector <vertex> tmp;
	for (int i = 0; i < size; i++)
	{
		if (id != vers[i].Getid())
		{
			DelEdge(id, i + 1);
			DelEdge(i + 1, id);
			tmp.push_back(vers[i]);
		}
	}
	size--;
	vers = tmp;

}
void OrGraph::DelEdge(int id1, int id2)
{
	vertex& ver1 = GetVertex(id1), & ver2 = GetVertex(id2);
	ver1.DelInEdge(id2);
	ver2.DelOutEdge(id1);

}
void OrGraph::LoadGraph()
{
	vers.clear();
	string line, StrDigit = "";
	int digit, id = 0;
	vector<int> inEdge, outEdge;
	vertex tmp;

	ifstream in("LoadGraph.txt"); // окрываем файл для чтения
	getline(in, line);

	size = atoi(line.c_str());

	if (in.is_open())
	{
		while (getline(in, line))
		{
			for (int i = 2; i < line.size(); i++)
			{
				if (line[i] == ';')
				{
					digit = atoi(StrDigit.c_str());
					if (line[0] == '1')
					{
						inEdge.push_back(digit);
					}
					else
					{
						outEdge.push_back(digit);
					}
					StrDigit = "";
				}
				else if (line[i] != ' ')
				{
					StrDigit = StrDigit + line[i];
				}
				else
				{
					digit = atoi(StrDigit.c_str());
					if (line[0] == '1')
					{
						inEdge.push_back(digit);
					}
					else
					{
						outEdge.push_back(digit);
					}
					StrDigit = "";
				}
			}
			id++;
			if (id % 2 == 0)
			{
				tmp.inEdge = inEdge;
				tmp.outEdge = outEdge;
				tmp.EnterId((id / 2));
				vers.push_back(tmp);
				inEdge.clear();
				outEdge.clear();
			}
		}
	}
	in.close();
}
void OrGraph::SaveGraph()
{
	std::ofstream out;          // поток для записи
	out.open("SaveGraph.txt"); // окрываем файл для записи
	int id;
	vertex ver;
	vector<int> edges;
	if (out.is_open())
	{
		out << size << endl;
		for (int i = 0; i < size * 2; i++)
		{
			id = i / 2 + 1;
			ver = GetVertex(id);
			if (i % 2 == 0)
			{
				out << '1';
				edges = ver.GetInEdge();
				for (int j = 0; j < edges.size(); j++)
				{
					out << ' ' << edges[j];
				}
				out << ';' << endl;
			}
			else
			{
				out << '2';
				edges = ver.GetOutEdge();
				for (int j = 0; j < edges.size(); j++)
				{
					out << ' ' << edges[j];
				}
				out << ';' << endl;
			}
		}
	}
}

void OrGraph::Display()
{
	for (int i = 0; i < vers.size(); i++)
	{
		vers[i].Display();
		cout << endl;
	}
}

int OrGraph::GetSize()
{
	return size;
}

vertex& OrGraph::GetVertex(int id)
{
	return vers[id - 1];
}