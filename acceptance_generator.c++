#include <iostream> 
#include <algorithm>  // std::random_shuffle
#include <list>
#define MAX_NBR_OF_VERT 10

int main () {
	using namespace std;

	srand( unsigned (time(0)));

	int vertex_number [MAX_NBR_OF_VERT] = {0};		// list of vertices

	int vertices = rand() % MAX_NBR_OF_VERT + 1;   /// from 1 to 10

	int number_of_lines = rand() % vertices;

	int adj_list_array [MAX_NBR_OF_VERT][MAX_NBR_OF_VERT] = {};

	//ouptut_number= 

	cout << vertices << " " << number_of_lines << endl;


	for (int i =0; i < vertices ; i++) {		//	[1,2,3,4,5]
		vertex_number [i]= i+1;
	}

	random_shuffle(vertex_number, vertex_number + vertices);

	std::list<int> vertex_number_list (vertex_number, vertex_number + vertices);


/*	 for (int i =0; i < vertices ; i++) {		//	[2 5 7 4 3 1 9 6 8]
	 	cout << vertex_number [i ] << " ";
	 }

	 cout << endl;*/


	/*for (list<int>::iterator it = vertex_number_list.begin(); it != vertex_number_list.end(); ++it)
		cout << *it << ' ';

	cout << endl;*/


	while ( number_of_lines >= 0) {

		int current_vertex = vertex_number_list.front();

		int number_dependencies =  rand() % (vertex_number_list.size()- 1) + 1;
		int loop_count = 0;
		int actual_dependencies = 0;
		for(int i = 0; i < number_dependencies; ++i){
			int number = rand() % vertices + 1;
			while(adj_list_array[number][current_vertex] == 1 && 
				loop_count < vertex_number_list.size()){
				cout << "in while loop";
				++loop_count;
				number = rand() % vertices + 1;
			}
			cout << "out of while loop";
			adj_list_array[current_vertex][number] = 1;
			++actual_dependencies;
		}

		if(actual_dependencies > 0){	
			cout << current_vertex << " "; //vertex on a new line 
			vertex_number_list.pop_front();

			cout << actual_dependencies << " " ;
			for(int j = 0; j < vertex_number_list.size(); ++j){
				if(adj_list_array[current_vertex][j] == 1)
					cout << adj_list_array[current_vertex][j] << " ";
			}
		}




		// int number_dependencies = rand() % (vertices -1) + 1;	
		// //cout << number_dependencies	<< " ";
		// int actual_dependencies;
		// for (int i=0, i < number_dependencies; i++) {
		// 	int number = rand() % vertices +1 ;

		// 	while (adj_list_array[number] [vertex_number[number_of_lines]] == 1) {
		// 		number = rand() % vertices +1 ;
		// 	}
		// 	adj_list_array [vertex_number[number_of_lines]][number] = 1;	

		// 	}
		}




	// 	number_of_lines --;
	// 	cout << endl;
	// }

}