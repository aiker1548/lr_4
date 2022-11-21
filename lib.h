#pragma once

#include<iostream>
#include<string>
#include<vector>
#include <fstream>

using namespace std;

class vertex
{
public:
	int id;
	void EnterId(int id);
	vector <int> inEdge;
	vector <int> outEdge;
	int Getid();
	vector<int> GetInEdge();
	vector<int> GetOutEdge();

	void EnterInEdge(int id);
	void EnterOutEdge(int id);

	void DelInEdge(int id);
	void DelOutEdge(int id);

	int GetSizeIn();
	int GetSizeOut();

	void Display();
};


class OrGraph
{
public:
	OrGraph();
	vector <vertex> vers;
	int size;
	void AddVertex(vertex vertex);
	void AddEdge(int id1, int id2);
	void DelVertex(int id);
	void DelEdge(int id1, int id2);
	void LoadGraph();
	void SaveGraph();
	void Display();
	int GetSize();
	vertex& GetVertex(int id);
};


vector<int> GraphTraversal(OrGraph graph, int id_start, int id_end);

OrGraph Addition(OrGraph graph);

