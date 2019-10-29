#include "DataFrame.hpp"

void DataFrame::loadFileCSV(string fileName)
{

	ifstream fin;

	fin.open(fileName, ios::in);

	string temp;

	for(int i = 0; i < 6; i++){

		getline(fin,temp,',');

		label.push_back(temp);


	}

	getline(fin, temp, '\n');

	label.push_back(temp);

	while(fin.good()){
		vector<double> dataTemp;

		for(int j = 0; j < 6; j++){

			getline(fin, temp, ',');
			if(temp=="") break;

			dataTemp.push_back(toDouble(temp));
		}

		if(temp=="") break;

		getline(fin, temp, '\n');


		dataTemp.push_back(temp[0] == 'y'  ? 1 : 0);


		data.push_back(dataTemp);

	}

}


void DataFrame::concat(vector<DataFrame> df){
	label = df[0].label;
	for(int i = 0; i < df.size(); i++)
		for(int j = 0; j < df[i].data.size(); j++) data.push_back(df[i].data[j]);

}

void DataFrame::merge(vector<double> *L, vector<double> *R, vector<double> *arr)
{

	int i = 0, j = 0, k = 0;

	while (i < (*L).size() && j < (*R).size())
	{

		if ((*L)[i] < (*R)[j])
		{
			(*arr)[k] = (*L)[i];
			i++;
		}
		else
		{
			(*arr)[k] = (*R)[j];
			j++;
		}
		k++;
	}

	while (i < (*L).size())
	{
		(*arr)[k] = (*L)[i];
		i++;
		k++;
	}

	while (j < (*R).size())
	{
		(*arr)[k] = (*R)[j];
		j++;
		k++;
	}
}

void DataFrame::mergeSort(vector<double> *arr)
{

	if ((*arr).size() < 2)
		return;

	int mid = (*arr).size() / 2;

	vector<double> L;
	vector<double> R;

	for (int i = 0; i < mid; i++) L.push_back((*arr)[i]);


	for (int i = 0; i < (*arr).size() - mid; i++) R.push_back((*arr)[mid + i]);


	mergeSort(&L);
	mergeSort(&R);
	merge(&L, &R, arr);
}

double* DataFrame::quartile(vector<double> column)
{
	double* qtl = new double[3];
	mergeSort(&column);


	qtl[0] = column[(int)((column.size() + 1) * 0.25)-1];

	qtl[1] = column.size() % 2 == 0 ? (column[(int)(column.size() * 0.5)-1] + column[(int)(((column.size() + 1)) * 0.5) - 1]) / 2.0 : column[(int)((column.size() + 1) * 0.5)-1];
	qtl[2] = column[(int)((column.size() + 1) * 0.75)-1];

	return qtl;
}


double** DataFrame::discretize(){

	int columns = data[0].size()-1;

	double *q;
	double** Q = new double*[columns];

	for(int i = 0; i < columns; i++) Q[i] = new double[3];


	for (int i = 0; i < columns; i++){
		vector<double> c;

		for(int j = 0; j < data.size(); j++) c.push_back(data[j][i]);

		q = quartile(c);
		Q[i] = q;

		for (int j = 0; j < data.size(); j++){

			if (data[j][i] <= q[0])
				data[j][i] = 0;

			else if (data[j][i] <= q[1])
				data[j][i] = 1;

			else if (data[j][i] <= q[2])
				data[j][i] = 2;

			else data[j][i] = 3;
		}

	}

	return Q;
}

