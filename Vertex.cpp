#include"lib.h"


void vertex::EnterId(int id)
{
	this->id = id;
}
int vertex::Getid()
{
	return id;
}

vector<int> vertex::GetInEdge()
{
	return inEdge;
}
vector<int> vertex::GetOutEdge()
{
	return outEdge;
}

void vertex::EnterInEdge(int id)
{
	inEdge.push_back(id);
}
void vertex::EnterOutEdge(int id)
{
	outEdge.push_back(id);
}
void vertex::DelInEdge(int id)
{
	vector<int> tmp;
	for (int i = 0; i < inEdge.size(); i++)
	{
		if (inEdge[i] != id)
			tmp.push_back(inEdge[i]);
	}
	inEdge = tmp;
}
void vertex::DelOutEdge(int id)
{
	vector<int> tmp;
	for (int i = 0; i < outEdge.size(); i++)
	{
		if (outEdge[i] != id)
			tmp.push_back(outEdge[i]);
	}
	outEdge = tmp;
}

void vertex::Display()
{
	cout << "id: " << id << endl;
	cout << "Edge to: ";
	for (int i = 0; i < inEdge.size(); i++)
	{
		cout << inEdge[i] << ' ';
	}
	cout << endl;
	cout << "Edge from: ";
	for (int i = 0; i < outEdge.size(); i++)
	{
		cout << outEdge[i] << ' ';
	}
	cout << endl;

}

int vertex::GetSizeIn()
{
	return inEdge.size();
}

int vertex::GetSizeOut()
{
	return outEdge.size();
}