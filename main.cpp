#include"lib.h"



int main()
{
	OrGraph graph,inversG;
	vertex ver;
	vector<int> way;

	bool f = true;
	int method, pos;
	int id1, id2;
	while (f)
	{
		cout << "choose orgraph method: " << endl;
		cout << "1: AddVertex" << endl;
		cout << "2: AddEdge" << endl;
		cout << "3: DelVertex" << endl;
		cout << "4: DelEdge" << endl;
		cout << "5: LoadGraph" << endl;
		cout << "6: SaveGraph" << endl;
		cout << "7: Display" << endl;
		cout << "8: GraphTraversal" << endl;
		cout << "9: Addition" << endl;
		cout << "10: Exit" << endl;

		cin >> method;

		switch (method)
		{
		case 1:
			system("cls");

			graph.AddVertex(ver);
			cout << "Complite!" << endl;
			cout << endl;
			break;
		case 2:
			system("cls");

			cout << "enter vertex id from, vertex id to , to add edges: ";
			cin >> id1 >> id2;
			graph.AddEdge(id1, id2);
			cout << "Complite!" << endl;
			cout << endl;
			break;
		case 3:
			system("cls");

			cout << "enter id vertex to delete vertex: ";
			cin >> id1;
			graph.DelVertex(id1);
			cout << "Complite!" << endl;
			cout << endl;
			break;
		case 4:
			system("cls");

			cout << "enter vertex id from, vertex id to , to delete edges: ";
			cin >> id1 >> id2;
			graph.DelEdge(id1, id2);
			cout << "Complite!" << endl;
			cout << endl;
			break;
		case 5:
			system("cls");

			graph.LoadGraph();
			cout << "Complite!" << endl;
			break;
		case 6:
			system("cls");

			graph.SaveGraph();
			cout << "Complite!" << endl;
			cout << endl;
			break;
		case 7:
			system("cls");

			graph.Display();
			break;
		case 8:
			system("cls");

			cout << "enter vertex id start, vertex id end , to get way: ";
			cin >> id1 >> id2;
			way = GraphTraversal(graph, id1, id2);
			cout << "way :";
			for (int i = 0; i < way.size(); i++)
			{
				cout << way[i] << '-';
			}
			cout << endl << "Complite!" << endl;
			cout << endl;
			break;
		case 9:
			system("cls");

			cout << "Inverse orgraph: ";
			inversG = Addition(graph);
			inversG.Display();
			break;
		case 10:
			f = false;
			break;
		}
	}
	return 0;
}