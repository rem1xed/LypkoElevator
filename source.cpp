#include <iostream>


using namespace std;

class elevator
{
	//way == true - up, way == false - down
	bool way;
	bool work = false;
	int curr = 5;

public:
	void OnOff(int s)
	{
		if (s == 0)
		{
			work = true;
		}
		if (s == 1)
		{
			work = false;
		}
	}
	void call(int urFloor);

	void curPos()
	{
		cout << "\n\nElevator is on | " << curr << " | Floor";
	}
	void moveTo(int urDest);
	int returnPos()
	{
		return curr;
	}
	bool returnWork()
	{
		return work;
	}
};

void elevator::call(int urFloor)
{
	int countFl = 0;
	if (urFloor != curr)
	{
		if (urFloor > curr)
		{
			way = true;
		}
		else if (urFloor < curr)
		{
			way = false;
		}
		switch (way)
		{
		case true:
			while (urFloor != curr)
			{
				countFl++;
				curr++;
			}
			break;
		case false:
			while (urFloor != curr)
			{
				countFl++;
				curr--;
			}
			break;
		default:
			break;
		}
		cout << "\nElevator came after passing | " << countFl << " | floors";
	}
	else
	{
		cout << "\n\nElevator came after passing 0 floors(it was on your floor)";
	}

}
void elevator::moveTo(int urDest)
{
	int countFl = 0;
	if (urDest != curr)
	{
		if (urDest > curr)
		{
			way = true;
		}
		else if (urDest < curr)
		{
			way = false;
		}
		switch (way)
		{
		case true:
			while (urDest != curr)
			{
				countFl++;
				curr++;
			}
			break;
		case false:
			while (urDest != curr)
			{
				countFl++;
				curr--;
			}
			break;
		default:
			break;
		}
		cout << "\nElevator moved to |" << urDest << "| floor after passing |" << countFl << "| floors";
	}
	else
	{
		cout << "\n\nElevator moved to |" << urDest << "| after passing 0 floors(it was on your floor)";
	}
}
void main()
{
	elevator el;
	bool work;
	work = el.returnWork();
	int opt;
	int urFloor = 0;
	int enter;
	while (true)
	{
		cout << "\nIf elevator is not working - enter the engineer mode";
		cout << "\n\n1 - enter as a resident\n2 - enter as engineer\n3 - Leave the house\n";
		cin >> enter;

		switch (enter)
		{
		case 1:
			if (work == true)
			{
				while (true)
				{
					bool go = true;
					el.curPos();
					cout << "\nYou are on <" << urFloor << "> floor";
					cout << "\n\n1 - call the elevator \n2 - leave elevator\n";
					cin >> opt;
					switch (opt)
					{
					case 1:
						el.call(urFloor);
						int dest;
						cout << "\n\nChoose floor destination: ";
						cin >> dest;
						if (dest >= 0)
						{
							el.moveTo(dest);
							urFloor = el.returnPos();
						}
						break;
					case 2:
						go = false;
						break;
					default:
						break;
					}
					if (go == false)
					{
						break;
					}
				}
			}
			else
			{
				cout << "The elevator is not working!";
				break;
			}
			break;
		case 2:
			while (true)
			{
				int engL;
				if (work == true)
				{
					cout << "\n\nElevator is working, enter 1 to turn it off ";
					int sel;
					cin >> sel;
					el.OnOff(sel);
					work = el.returnWork();
				}
				else if (work == false)
				{
					cout << "\n\nElevator is not working, enter 0 to turn it on ";
					int sel;
					cin >> sel;
					el.OnOff(sel);
					work = el.returnWork();
				}

				cout << "\n\nDo you want to leave engineer mode? (1 - leave)";
				cin >> engL;
				if (engL == 1)
				{
					break;
				}
				else
				{
					continue;
				}
			}
		default:
			break;
		}
		if (enter == 3)
		{
			break;
		}
	}

}