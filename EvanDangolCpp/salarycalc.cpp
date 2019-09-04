#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>
#include <stdio.h>
#pragma _CRT_SECURE_NO_WARNINGS
using namespace std;
const int hrindicator = 588;
const float mintaxsalary = 6250;
int idstart = -1;
int laststart = -1;
int firststart = -1;
int *hremployeecount = 0x0;
int salarystart = -1;
float *taxcredit = 0x0;
float totalsalary = 0;

struct Record {
    int id;
    char lastName[15];
    char firstName[10];
    float salary;
};

void displayResults(int, Record*);

int nmain (int argc, char** argv) {











    ifstream salaryfile(argv[1]);
	
	
	/*char x[100];
	while (!salaryfile.eof())
	{
		salaryfile.getline(x, sizeof(x));
		cout << x;
	}
	getchar();*/
	//return 0;
    int lcount = 0;
    const int recsinfile=5;
    string line;
    char buf;
	
	
	
    char recordsfromfile[2];
    salaryfile.get(recordsfromfile[0]);
	
    salaryfile.get(recordsfromfile[1]);
    salaryfile.get(buf);
	
    //sscanf(recordsfromfile, "%d", &recsinfile);

    //recsinfile -= 2;

    Record recs[recsinfile];

    int ccount = 0;
    char *hbuf = (char*)malloc(8);
    while (salaryfile.get(buf)) {
		
        if (buf == 10) {
            break;
        }
        hbuf[ccount] = buf;
        ccount++;
        hbuf = (char*)realloc(hbuf, ccount);
        if (ccount == 2) {
            if (idstart == -1)
                idstart = atoi(hbuf);
            else if (laststart == -1)
                laststart = atoi(hbuf);
            else if (firststart == -1)
                firststart = atoi(hbuf);
            else
                salarystart = atoi(hbuf);

            ccount = 0;
        }
    }

    char recbuf;
    char *sbuf = (char*)malloc(15 * sizeof(char));
    while (lcount < recsinfile) {
        int l = 0;
        int c = 0;
        int v = 0;
        while (salaryfile.get(recbuf)) {
            l++;
            v += recbuf;
            if (recbuf == 10) {
				
                recs[lcount].salary = atoi(sbuf);
                lcount++;
                break;
            }

            if (v == hrindicator) {
                hremployeecount++;
            }
            sbuf[c] = recbuf;
			cout << (char)recbuf;
			cout << "   " << endl;
            c++;
            sbuf = (char*)realloc(sbuf, c);

            if (l == laststart) {
                recs[lcount].id = atoi(sbuf);
                c = 0;
                v = c;
            } else if (l == firststart) {
				
                memcpy(recs[lcount].lastName, sbuf, 15);
                c = 0;
                v = c;
            } else if (l == salarystart) {
                memcpy(recs[lcount].firstName, sbuf, 10);
                c = 0;
                v = c;
            }
        }
    }
	taxcredit = new float;
    for (int i = 0; i < recsinfile; i++) {
        float s;
        s = recs[i].salary;
		cout << recs[i].firstName << endl;
        if (s < mintaxsalary) {
            *taxcredit += s * 0.33f;
        }
        totalsalary += s;
    }

    displayResults(lcount, recs);
	getchar();
    return 0;
}

// Class note! Do not change this method - points will be deducted for invalid submissions.
void displayResults(int records, Record* recordList) {
    char output[255];
    if (records != 0)
        sprintf_s(output,"Records:%d",records);
    if (recordList[0].id != 0)
        sprintf(output + strlen(output),";FirstId:%d",recordList[0].id);
    if (totalsalary != 0)
        sprintf(output + strlen(output),";Total:%g",totalsalary);
    if (hremployeecount != NULL)
        sprintf(output + strlen(output),";HR:%d",*hremployeecount);
    if (taxcredit != NULL)
        sprintf(output + strlen(output), ";TaxCredits:%g",*taxcredit);

    cout << output << endl;
}