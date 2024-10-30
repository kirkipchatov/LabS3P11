#include <iostream>
#include <fstream>


struct Items {
	int id;
	char name[50];
	char providor[50];
	char description[50];
	double weight;
	int count;

	void print()
	{
		std::cout << "[" << id << "]\n\t";
		std::cout << name << " (" << description << ")\n\t";
		std::cout << weight << " kg; " << count << " items\n\t";
		std::cout << "from " << providor << "\n\n";
	}
};

int totalWeight(Items* items, int n)
{
	int sumTot = 0;
	for (int i = 0; i < n; i++)
	{
		int sumGroup = items[i].weight * items[i].count;
		sumTot += sumGroup;
	}
	return sumTot;
}

int main(int argc, char* argv[])
{
	bool cont = true;
	do {
		std::cout << "0 - exit" << std::endl;
		std::cout << "1 - read from file" << std::endl;
		std::cout << "2 - write to file" << std::endl;
		std::cout << "3 - change" << std::endl;
		int choice = 0;
		std::cin >> choice;

		switch (choice)
		{
		case 0:
		{
			cont = false;
			break;
		}
		case 1:
		{
			std::string filename;
			std::cout << "input file name : ";
			std::cin >> filename;
			std::ifstream fin(filename);
			int n = 0;
			fin >> n;
			Items* items = new Items[n];
			for (int i = 0; i < n; i++)
			{
				fin >> items[i].id;
				char tmp[2];
				fin.getline(tmp, 2);
				fin.getline(items[i].name, 50);
				fin.getline(items[i].providor, 50);
				fin.getline(items[i].description, 50);
				fin >> items[i].weight;
				fin >> items[i].count;
			}
			fin.close();
		}
		case 2:
		{

		}
		}
	} while (cont);

	for (int i = 0; i < n; i++)
	{
		items[i].print();
	}
	std::cout << "Total weight: " << totalWeight(items, n);

	return EXIT_SUCCESS;
}