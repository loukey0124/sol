#include <iostream>

using namespace std;

void Sort(int* arr, char* label, int size) {
	int temp = 0;
	char tempc = ' ';

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				tempc = label[j];
				label[j] = label[j + 1];
				label[j + 1] = tempc;
			}
		}
	}
	return;
}

void PrintLeftBall(int* ball, char* label, int size) {
	cout << "잔여 공 개수 : ";

	for (int i = 0; i < size; i++) {
		cout << label[i] << ':' << ball[i]<<' ';
	}
	cout << endl;
}

void PrintNozzle(char* label, int* nozzle, int size) {
	cout << "현재 노즐 조합 : " << label[nozzle[0]] << ' ' << label[nozzle[1]] << ' '
		<< label[nozzle[2]] << ' ' << label[nozzle[3]] << endl;
}

int main()
{
	int balls[6] = { 0 };
	char labels[6] = { 'A','B','C','D','E','F' };

	cout << "공의 갯수 입력: ";
	cin >> balls[0] >> balls[1] >> balls[2] >> balls[3] >> balls[4] >> balls[5];

	Sort(balls, labels, (sizeof balls) / 4);

	for (int i = 0; i < 6; i++)
		cout << balls[i] << " ";
	cout << endl;
	for (int i = 0; i < 6; i++)
		cout << labels[i] << " ";
	cout << endl;



	int curr[4] = { 0,1,2,3 };
	PrintNozzle(labels, curr, (sizeof curr) / 4);

	int time = 5;

	while (1) {
		if (balls[curr[0]] == 0 && balls[curr[1]] > 2) {
			cout << "노즐 조합 수정!" << endl;

			int last = 0;

			if (curr[3] == 5 && curr[2] == 5)
				if (balls[curr[0]] == 0 && balls[curr[3]] / balls[curr[1]] == 3)
					last = curr[3];
				else
					last = curr[1];
			else if (balls[curr[2]] > 6 && balls[curr[3]] == 0) {
				curr[1] = 5, curr[2] = 5, curr[3] = 5;
				last = 5;
			}
			else if (curr[3] == 5)
				last = curr[3];
			else
				last = curr[3] + 1;

			for (int i = 0; i < sizeof curr / 4 - 1; i++)
				curr[i] = curr[i + 1];
			curr[3] = last;
			PrintNozzle(labels, curr, (sizeof curr) / 4);

			time += 5;
		}
		else if (balls[curr[0]] == 0 && balls[curr[1]] == 0 &&
			balls[curr[2]] == 0 && balls[curr[3]] == 0) {
			cout << "노즐 조합 수정!" << endl;

			if (balls[5] / balls[4] >= 3) {
				curr[0] = 4;
				curr[1] = 5, curr[2] = 5, curr[3] = 5;
			}
			else {
				curr[0] = 4, curr[2] = 4;
				curr[1] = 5, curr[3] = 5;
			}
			PrintNozzle(labels, curr, (sizeof curr) / 4);
			time += 5;
		}
		else if (balls[curr[0]] == 0 && balls[curr[1]] < 4) {
			for (int i = 0; i < sizeof curr / 4; i++) {
				if (balls[curr[i]] != 0) {
					balls[curr[i]]--;
				}
			}

			PrintLeftBall(balls, labels, (sizeof balls) / 4);
			time += 2;
		}
		else {
			for (int i = 0; i < sizeof curr / 4; i++)
				if (balls[curr[i]] != 0) {
					balls[curr[i]]--;
				}

			PrintLeftBall(balls, labels, (sizeof balls) / 4);
			time += 2;
		}

		cout << "현재 소요시간 : " << time << endl;
		if (balls[5] == 0 && balls[4] == 0)
			break;
	}

	return 0;
}
