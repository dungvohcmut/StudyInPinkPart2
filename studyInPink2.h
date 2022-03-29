/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

string notebook1(string ntb1) {
    // Complete this function to gain point
    //Read first line of ntb1
    ifstream inp1(ntb1);
    string nb1;
    getline(inp1, nb1);
    
    //Check if the string <n1> is valid or not
    string strN1 = nb1.substr(11, 13);
    if (strN1.length() != 3) {
        return "0000000000";
    }
    for (char check : strN1) {
        if (isdigit(check) == 0)
            return "0000000000";
    }

    //Convert string <n1> into integer
    stringstream convert1(strN1);
    int n1;
    convert1 >> n1;

    //Check if n1 is valid or not
    if (n1 >= 0 && n1 <= 999) {
        //Read string from line 2
        for (int i = 0; i <= n1; i++){
            getline(inp1,nb1);
        }

        //Delete spaces between string on line 2
        int count = 0;
        string n2 = nb1.substr(0,nb1.length());
        for (int i = 0; n2[i]; i++) {
            if (n2[i] != ' ') {
                n2[count++] = n2[i];
            }
        }
        n2[count] = '\0';

        //List the frequency of numbers in string
        int n2Num[10] = { 0 };
        for (int i = 0; i < n1; i++) {
            n2Num[n2[i] - '0']++;
        }
        stringstream str2;
        string strN2;
        for (int i = 0; i < 10; i++) {
            str2 << n2Num[i] % 10;
        }
        str2 >> strN2;
        return strN2;
    }
    else {
        return "0000000000";
    }
}

string notebook2(string ntb2) {
    // Complete this function to gain point
    //Read <n2> from ntb2
    ifstream inp2(ntb2);
    string strN2;
    getline(inp2, strN2);

    //Check if the string is valid or not
    if (strN2.length() != 5) {
        return "1111111111";
    }
    for (char check : strN2) {
        if (isdigit(check) == 0)
            return "1111111111";
    }

    //Convert string into integer
    stringstream convert2(strN2);
    int n2;
    convert2 >> n2;

    //Check if n2 is valid or not
    if (n2 >= 5 && n2 <= 100) {
        //Read string from line 0 to line n2
        int cntP = 0;
        for (int i = 1; i <= n2; i++) {
            getline(inp2, ntb2);
            //Count the occurrences of "pink"
            int pos = ntb2.find("pink");
            while (pos != string::npos) {
                pos = ntb2.find("pink", pos + 1);
                cntP++;
            }
            //Count the occurrences of "Pink"
            pos = ntb2.find("Pink");
            while (pos != string::npos) {
                pos = ntb2.find("Pink", pos + 1);
                cntP++;
            }
        }
        if (cntP < 10000) {
            cntP *= cntP;
        }
        //If cnt_P is less than 10 digits, add number '9' to the end until enough
        string cnt_P;
        cnt_P = to_string(cntP);
        if (cnt_P.length() <= 10) {
            while (cnt_P.length() < 10){
                cnt_P.push_back('9');
            }
        }
        return cnt_P;
    }
    else {
        return "1111111111";
    }
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    //Read n1 from ntb1
    ifstream inp3(ntb3);
    string nb3;
    string Max;

    int array_2D[10][10];
    int i = 0, j = 0, max = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 9; j++) {
            getline(inp3, nb3, '|');
            //Convert string to integer
            stringstream convert3(nb3);
            int n3;
            convert3 >> n3;
            array_2D[i][j] = n3;
        }
        getline(inp3, nb3);
        //Convert string to integer
        stringstream convert3(nb3);
        int nf3;
        convert3 >> nf3;
        array_2D[i][9] = nf3;
        for (j = 0; j < 10; j++) {
            if (array_2D[i][j] < 0) {
                array_2D[i][j] *= -1;
            }
        }
        for (j = 0; j < 10; j++) {
            //Change all elements above the main diagonal
            if (i < j) {
                int n = 2;
                if (array_2D[i][j] == 0) {
                    array_2D[i][j] += 2;
                }
                if (array_2D[i][j] == 1) {
                    array_2D[i][j] += 1;
                }
                while (n < array_2D[i][j]) {
                    if (array_2D[i][j] % n == 0) {
                        array_2D[i][j]++;
                        n = 2;
                    }
                    else {
                        n++;
                    }
                }
            }
            //Change all elements below the main diagonal
            if (i > j) {
                int first = 0, second = 1, third = first + second;
                while (third < array_2D[i][j]) {
                    first = second;
                    second = third;
                    third = first + second;
                }
                array_2D[i][j] = third;
            }
            else {
                array_2D[i][j] = array_2D[i][j];
            }
        }
        
        //Sort the last 3 integers of the row
        int k = 0;
        if (array_2D[i][7] > array_2D[i][9]) {
            k = array_2D[i][7];
            array_2D[i][7] = array_2D[i][9];
            array_2D[i][9] = k;
        }
        if (array_2D[i][8] > array_2D[i][9]) {
            k = array_2D[i][8];
            array_2D[i][8] = array_2D[i][9];
            array_2D[i][9] = k;
        }
        if (array_2D[i][7] > array_2D[i][8]) {
            k = array_2D[i][7];
            array_2D[i][7] = array_2D[i][8];
            array_2D[i][8] = k;
        }
        for (j = 0; j < 10; j++) {
            if (array_2D[i][j] >= array_2D[i][max]) {
                max = j;
            }
        }
        to_string(max);
        Max += to_string(max);
    }
    return Max;
    
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    //<g(pwd1,pwd2)>
    string pwd1_pwd2 = "";
    int carry_12 = 0;
    int i_12 = 0, j_12 = 0;
    while (i_12 < 10 || j_12 < 10) {
        int x = 0, y = 0;
        if (i_12 >= 0) { x = pwd1[i_12] - '0'; }
        if (j_12 >= 0) { y = pwd2[j_12] - '0'; }
        int sum_12 = x + y + carry_12;
        if (sum_12 > 9) {
            carry_12 = 1;
            sum_12 = sum_12 - 10;
        }
        else { carry_12 = 0; }
        pwd1_pwd2 += to_string(sum_12);
        i_12++;
        j_12++;
    }
    if (carry_12 == 1) { pwd1_pwd2 = pwd1_pwd2; }

    //<g(pwd1,pwd3)>
    string pwd1_pwd3 = "";
    int carry_13 = 0;
    int i_13 = 0, j_13 = 0;
    while (i_13 < 10 || j_13 < 10) {
        int x = 0, y = 0;
        if (i_13 >= 0) { x = pwd1[i_13] - '0'; }
        if (j_13 >= 0) { y = pwd3[j_13] - '0'; }
        int sum_13 = x + y + carry_13;
        if (sum_13 > 9) {
            carry_13 = 1;
            sum_13 = sum_13 - 10;
        }
        else { carry_13 = 0; }
        pwd1_pwd3 += to_string(sum_13);
        i_13++;
        j_13++;
    }
    if (carry_13 == 1) { pwd1_pwd3 = pwd1_pwd3; }

    //<g(pwd2,pwd3)>
    string pwd2_pwd3 = "";
    int carry_23 = 0;
    int i_23 = 0, j_23 = 0;
    while (i_23 < 10 || j_23 < 10) {
        int x = 0, y = 0;
        if (i_23 >= 0) { x = pwd2[i_23] - '0'; }
        if (j_23 >= 0) { y = pwd3[j_23] - '0'; }
        int sum_23 = x + y + carry_23;
        if (sum_23 > 9) {
            carry_23 = 1;
            sum_23 = sum_23 - 10;
        }
        else { carry_23 = 0; }
        pwd2_pwd3 += to_string(sum_23);
        i_23++;
        j_23++;
    }
    if (carry_23 == 1) { pwd2_pwd3 = pwd2_pwd3; }

    //<g(<g(pwd1,pwd2)>,pwd3)>
    string pwd1pwd2_pwd3 = "";
    int carry_12_3 = 0;
    int i_12_3 = 0, j_12_3 = 0;
    while (i_12_3 < 10 || j_12_3 < 10) {
        int x = 0, y = 0;
        if (i_12_3 >= 0) { x = pwd1_pwd2[i_12_3] - '0'; }
        if (j_12_3 >= 0) { y = pwd3[j_12_3] - '0'; }
        int sum_12_3 = x + y + carry_12_3;
        if (sum_12_3 > 9) {
            carry_12_3 = 1;
            sum_12_3 = sum_12_3 - 10;
        }
        else { carry_12_3 = 0; }
        pwd1pwd2_pwd3 += to_string(sum_12_3);
        i_12_3++;
        j_12_3++;
    }
    if (carry_12_3 == 1) { pwd1pwd2_pwd3 = pwd1pwd2_pwd3; }

    //<g(pwd1,<g(pwd2,pwd3)>)>
    string pwd1_pwd2pwd3 = "";
    int carry_1_23 = 0;
    int i_1_23 = 0, j_1_23 = 0;
    while (i_1_23 < 10 || j_1_23 < 10) {
        int x = 0, y = 0;
        if (i_1_23 >= 0) { x = pwd1[i_1_23] - '0'; }
        if (j_1_23 >= 0) { y = pwd2_pwd3[j_1_23] - '0'; }
        int sum_1_23 = x + y + carry_1_23;
        if (sum_1_23 > 9) {
            carry_1_23 = 1;
            sum_1_23 = sum_1_23 - 10;
        }
        else { carry_1_23 = 0; }
        pwd1_pwd2pwd3 += to_string(sum_1_23);
        i_1_23++;
        j_1_23++;
    }
    if (carry_1_23 == 1) { pwd1_pwd2pwd3 = pwd1_pwd2pwd3; }

    //<g(<g(pwd1,pwd2)>,<g(pwd1,pwd3)>)>
    string pwd1pwd2_pwd1pwd3 = "";
    int carry_12_13 = 0;
    int i_12_13 = 0, j_12_13 = 0;
    while (i_12_13 < 10 || j_12_13 < 10) {
        int x = 0, y = 0;
        if (i_12_13 >= 0) { x = pwd1_pwd2[i_12_13] - '0'; }
        if (j_12_13 >= 0) { y = pwd1_pwd3[j_12_13] - '0'; }
        int sum_12_13 = x + y + carry_12_13;
        if (sum_12_13 > 9) {
            carry_12_13 = 1;
            sum_12_13 = sum_12_13 - 10;
        }
        else { carry_12_13 = 0; }
        pwd1pwd2_pwd1pwd3 += to_string(sum_12_13);
        i_12_13++;
        j_12_13++;
    }
    if (carry_12_13 == 1) { pwd1pwd2_pwd1pwd3 = pwd1pwd2_pwd1pwd3; }
    
    return pwd1 + ";" + pwd2 + ";" + pwd3 + ";" + pwd1_pwd2 + ";" + pwd1_pwd3 + ";" + pwd2_pwd3 + ";" + pwd1pwd2_pwd3 + ";" + pwd1_pwd2pwd3 + ";" + pwd1pwd2_pwd1pwd3;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    int i = 0, j = 0;
    bool catchUp = 0;

    //Initialize elements of 2-D arrays -9  
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            arr[i][j] = -9;
        }
    }
    //The first position of taxi
    arr[0][0] = 0;

    //Movements of taxi
    i = 0; j = 0;
    for (int k = 0; k < moves.length(); k++) {
        if (moves[k] == 'U' && i > 0) {
            i--;
            arr[i][j] = arr[i + 1][j] + 9;
        }
        else if (moves[k] == 'D' && i < 99) {
            i++;
            arr[i][j] = arr[i - 1][j] + 9;
        }
        else if (moves[k] == 'R' && j < 99) {
            j++;
            arr[i][j] = arr[i][j - 1] + 9;
        }
        else if (moves[k] == 'L' && j > 0) {
            j--;
            arr[i][j] = arr[i][j + 1] + 9;
        }
    }

    int a = 0, b = 0, timeToPoint = 0, Pj, Pi, pointOfCatchUp = 0, numberOfPoints = 0;
    size_t position = 0, pos_1 = 0;
    string point, p_i, p_j;

    //Count the number of points in string
    for (int i = 0; i < points.length(); i++) {
        if (points[i] == '-') {
            numberOfPoints++;
        }
    }

    //Manipulate data of points exclude the last
    while ((position = points.find('-')) != string::npos) {
        //Variable to determine the point Sherlock catches up taxi
        pointOfCatchUp++;
        point = points.substr(1, position - 2);
        points.erase(0, position + 1);
        p_i = point.substr(0, 2);

        //Convert string p_i into integer Pi
        stringstream convertp_i(p_i);
        convertp_i >> Pi; 

        if (Pi < 10) {
            p_j = point.substr(2, 2);
            //Convert string p_j into integer Pj
            stringstream convertp_j(p_j);
            convertp_j >> Pj;
        }
        else {
            p_j = point.substr(3, 2);
            //Convert string p_j into integer Pj
            stringstream convertp_j(p_j);
            convertp_j >> Pj;
        }
        timeToPoint += 14 * (abs(Pi - a) + abs(Pj - b));
        a = Pi;
        b = Pj;
        outTimes += to_string(timeToPoint) + ';';

        //Check whether Sherlock can catch the taxi
        if (arr[Pi][Pj] >= timeToPoint) {
            outCatchUps += "Y;";
            catchUp = 1;
            for (int i = pointOfCatchUp; i < numberOfPoints; i++) {
                outCatchUps += "-;";
                outTimes += "-;";
            }
            outCatchUps += "-";
            outTimes += "-";
            return catchUp;
            break;
        }
        else {
            outCatchUps += "N;";
        }
    }

    //Manipulate data of the last point
    int Pfi, Pfj;
    p_i = points.substr(1, 2);
    stringstream convertp_i(p_i);
    convertp_i >> Pfi;

    if (Pfi < 10) {
        p_j = points.substr(3, 2);
        stringstream convertp_j(p_j);
        convertp_j >> Pfj;
    }
    else {
        p_j = points.substr(4, 2);
        stringstream convertp_j(p_j);
        convertp_j >> Pfj;
    }
    timeToPoint += 14 * (abs(Pfi - a) + abs(Pfj - b));
    
    //Check whether Sherlock can catch the taxi
    if (arr[Pfi][Pfj] >= timeToPoint) {
        outTimes += '-';
        outCatchUps += "-";
        return catchUp;
    }
    else if (arr[Pfi][Pfj] < timeToPoint && arr[a][b] < timeToPoint) {
        outCatchUps += "N";
        outTimes += to_string(timeToPoint);
    }
    return catchUp;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    //Get string email
    ifstream inp4(tag);
    string Tag;
    getline(inp4, Tag);
    string email = Tag.substr(7, Tag.length());

    //Get <n3> and convert it into interger
    getline(inp4, Tag);
    string strN3 = Tag.substr(9, Tag.length());
    stringstream convert6(strN3);
    int n3;
    convert6 >> n3;

    //Return password
    string passWord;
    for (int i = 0; i < n3; i++) {
        passWord += message;
    }
    return email + ";" + passWord;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
