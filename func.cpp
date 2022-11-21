#include"lib.h"

vector<int> GraphTraversal(OrGraph graph, int id_start, int id_end)
{
	vector<int> way;
	vertex ver;

	int size = graph.GetSize();
	bool* visit = new bool[size + 1];

	for (int i = 1; i <= size; ++i)
	{
		visit[i] = false;
	}

	visit[id_start] = true;
	int curr = id_start;
	bool f = false;
	while (true)
	{
		f = false;
		way.push_back(curr);
		ver = graph.GetVertex(curr);

		if (curr == id_end)
		{
			delete[] visit;
			return way;
		}

		for (int i = 0; i < ver.GetSizeIn(); i++)
		{
			if (visit[ver.GetInEdge()[i]] == false)
			{
				curr = ver.GetInEdge()[i];
				visit[ver.GetInEdge()[i]] = true;
				f = true;
				break;
			}
		}

		if (ver.GetSizeIn() == 0 || f == false)
		{
			if (!way.empty())
			{
				way.pop_back();
				curr = way[way.size() - 1];
				way.pop_back();
			}
			else
			{
				delete[] visit;
				return way;
			}
		}
	}
}

void FalseArr(bool* ver,int size)
{
	for (int i = 0; i < size; i++)
	{
		ver[i] = false;
	}
}

OrGraph Addition(OrGraph graph)
{
	OrGraph graphOut;
	bool* ver=nullptr;
	int size = graph.GetSize();
	ver = new bool[size];
	vertex tmp;
	vector<int> in, out;
	vector <vertex> vers;

	for (int i = 0; i < size; i++)
	{
		FalseArr(ver, size);
		tmp = graph.GetVertex(i + 1);
		in = tmp.GetInEdge();
		out = tmp.GetOutEdge();
		for (int q = 0; q < in.size(); q++)
		{
			ver[in[q]-1] = true;
		}
		in.clear();
		for (int q = 0; q < size; q++)
		{
			if (ver[q] == false && q != i)
			{
				in.push_back(q + 1);
			}
		}
	
		for (int q = 0; q < out.size(); q++)
		{
			ver[out[q]] = true;
		}
		out.clear();
		for (int q = 0; q < size; q++)
		{
			if (ver[q] == false && q!=i)
			{
				out.push_back(q + 1);
			}
		}
		tmp.inEdge = in;
		tmp.outEdge = out;

		vers.push_back(tmp);
	}

	graphOut.size = size;
	graphOut.vers = vers;

	return graphOut;
}