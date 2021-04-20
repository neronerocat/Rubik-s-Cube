//主程序，包含解魔方算法

#include "arm.h"
#include "colour.h"
#include "photo.h"
#include "rotation.h"
#include "thistlethwaite.h"

string F[9];
string R[9];
string L[9];
string B[9];
string U[9];
string D[9];

string rotation[40];
string start[20];

int stage;
int f = 0;
int applicableMoves[] = { 0, 262143/*18_1*/, 259263/*111111010010111111*/, 74943/*10010010010111111*/, 74898/*10010010010010010*/ };
int affectedCubies[][8] = {
    { 0,  1,  2,  3,  0,  1,  2,  3 },   // U
    { 4,  7,  6,  5,  4,  5,  6,  7 },   // D
    { 0,  9,  4,  8,  0,  3,  5,  4 },   // F
    { 2, 10,  6, 11,  2,  1,  7,  6 },   // B
    { 3, 11,  7,  9,  3,  2,  6,  5 },   // L
    { 1,  8,  5, 10,  1,  0,  4,  7 },   // R
};

rush movement(int move, rush state) {
    int turns = move % 3 + 1;
    int face = move / 3;
    while (turns--) {
        rush oldState = state;
        for (int i = 0; i<8; i++) {
            int isCorner = i > 3;
            int target = affectedCubies[face][i] + isCorner * 12;
            int killer = affectedCubies[face][(i & 3) == 3 ? i - 3 : i + 1] + isCorner * 12;
            int orientationDelta = (i<4) ? (face>1 && face<4) : (face<2) ? 0 : 2 - (i & 1);
            state[target] = oldState[killer];
            state[target + 20] = oldState[killer + 20] + orientationDelta;
            if (!turns)
                state[target + 20] %= 2 + isCorner;
        }
    }
    return state;
}

int inverse(int move) {
    return move + 2 - 2 * (move % 3);
}

rush pass(rush state) {

    //stage 1
    if (stage < 2)
        return rush(state.begin() + 20, state.begin() + 32);

    //stage 2
    if (stage < 3) {
        rush result(state.begin() + 31, state.begin() + 40);
        for (int e = 0; e<12; e++)
            result[0] |= (state[e] / 8) << e;
        return result;
    }

    //stage 3
    if (stage < 4) {
        rush result(3);
        for (int e = 0; e<12; e++)
            result[0] |= ((state[e] > 7) ? 2 : (state[e] & 1)) << (2 * e);
        for (int c = 0; c<8; c++)
            result[1] |= ((state[c + 12] - 12) & 5) << (3 * c);
        for (int i = 12; i<20; i++)
            for (int j = i + 1; j<20; j++)
                result[2] ^= state[i] > state[j];
        return result;
    }

    //stage 4
    return state;
}

int main()
{
    wiringPiSetup();
    pinMode(22,OUTPUT); pinMode(23,OUTPUT);
    pinMode(21,OUTPUT); pinMode(25,OUTPUT);
    pinMode(26,OUTPUT); pinMode(27,OUTPUT);
    pinMode(28,OUTPUT); pinMode(29,OUTPUT);

    initial_position();
    photoF();
    take_photo();
    image_process();
    imshow("F",imgOriginal_quarter);
    for( int i=0;i<9;i++ )
    {
        if(a[i] == ""){a[i] = "F";}
        F[i] = a[i];
        cout << F[i] <<" ";
        a[i] = "";
        if(i == 8) cout<<endl;
    }
    waitKey(1000);

    photoR();
    take_photo();
    image_process();
    imshow("R",imgOriginal_quarter);
    for( int i=0;i<9;i++ )
    {
        if(a[i] == ""){a[i] = "F";}
        R[i] = a[i];
        cout << R[i] <<" ";
        a[i] = "";
        if(i == 8) cout<<endl;
    }
    waitKey(1000);

    photoL();
    take_photo();
    image_process();
    imshow("L",imgOriginal_quarter);
    for( int i=0;i<9;i++ )
    {
        if(a[i] == ""){a[i] = "F";}
        L[i] = a[i];
        cout << L[i] <<" ";
        a[i] = "";
        if(i == 8) cout<<endl;
    }
    waitKey(1000);

    photoB();
    take_photo();
    image_process();
    imshow("B",imgOriginal_quarter);
    for( int i=0;i<9;i++ )
    {
        if(a[i] == ""){a[i] = "F";}
        B[i] = a[i];
        cout << B[i] <<" ";
        a[i] = "";
        if(i == 8) cout<<endl;
    }
    waitKey(1000);

    photoU();
    take_photo();
    image_process();
    imshow("U",imgOriginal_quarter);
    for( int i=0;i<9;i++ )
    {
        if(a[i] == ""){a[i] = "F";}
        U[i] = a[i];
        cout << U[i] <<" ";
        a[i] = "";
        if(i == 8) cout<<endl;
    }
    waitKey(1000);

    photoD();
    take_photo();
    image_process();
    imshow("D",imgOriginal_quarter);
    for( int i=0;i<9;i++ )
    {
        if(a[i] == ""){a[i] = "F";}
        D[i] = a[i];
        cout << D[i] <<" ";
        a[i] = "";
        if(i == 8) cout<<endl;
    }
    waitKey(1000);

    prepare();

    start[0]=U[7]+F[1]; start[1]=U[5]+R[1]; start[2]=U[1]+B[1]; start[3]=U[3]+L[1];
    start[4]=D[1]+F[7]; start[5]=D[5]+R[7]; start[6]=D[7]+B[7]; start[7]=D[3]+L[7];
    start[8]=F[5]+R[3]; start[9]=F[3]+L[5]; start[10]=B[3]+R[5]; start[11]=B[5]+L[3];
    start[12]=U[8]+F[2]+R[0]; start[13]=U[2]+R[2]+B[0]; start[14]=U[0]+B[2]+L[0];
    start[15]=U[6]+L[2]+F[0]; start[16]=D[2]+R[6]+F[8]; start[17]=D[0]+F[6]+L[8];
    start[18]=D[6]+L[6]+B[8]; start[19]=D[8]+B[6]+R[8];

    for(int n = 0; n < 20; n++)
    {
        cout<<start[n]<<endl;
    }

    string solved[] = { "UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "FL", "BR", "BL",
           "UFR", "URB", "UBL", "ULF", "DRF", "DFL", "DLB", "DBR" };

    rush currentState(40), solvedState(40);
    for (int i = 0; i<20; i++)
    {
    solvedState[i] = i;
    string cubie = start[i];
    while ((currentState[i] = find(solved, solved + 20, cubie) - solved) == 20)
        {
            cubie = cubie.substr(1) + cubie[0];
            currentState[i + 20]++;
        }
    }

    while (++stage < 5)
    {
        rush currentPass = pass(currentState), solvedPass = pass(solvedState);
        if (currentPass == solvedPass)
        continue;
        queue<rush> q;
        q.push(currentState);
        q.push(solvedState);
        map<rush, rush> processor;
        map<rush, int> direction, lastMove;
        direction[currentPass] = 1;
        direction[solvedPass] = 2;

        //BFS
        while (1)
        {
            rush oldState = q.front();
            q.pop();
            rush oldPass = pass(oldState);
            int& oldDir = direction[oldPass];
            for (int move = 0; move<18; move++)
            {
                if (applicableMoves[stage] & (1 << move))
                {
                    rush newState = movement(move, oldState);
                    rush newPass = pass(newState);
                    int& newDir = direction[newPass];
                    if (newDir  &&  newDir != oldDir)
                    {
                        if (oldDir > 1)
                        {
                            swap(newPass, oldPass);
                            move = inverse(move);
                        }
                        rush algorithm(1, move);
                        while (oldPass != currentPass)
                        {
                            algorithm.insert(algorithm.begin(), lastMove[oldPass]);
                            oldPass = processor[oldPass];
                        }
                        while (newPass != solvedPass)
                        {
                            algorithm.push_back(inverse(lastMove[newPass]));
                            newPass = processor[newPass];
                        }


                        for (int i = 0; i<(int)algorithm.size(); i++)
                        {
                            char a = "UDFBLR"[algorithm[i] / 3];
                            int b = algorithm[i] % 3 + 1;
                            string c[1];
                            string d[1];
                            string e[1];
                            c[0] = a;
                            d[0] = '0' + b;
                            e[0] = c[0] + d[0];
                            if(stage == 1)rotation[i] = e[0];
                            if(stage == 2)rotation[i + f] = e[0];
                            if(stage == 3)rotation[i + f] = e[0];
                            if(stage == 4)rotation[i + f] = e[0];
                            //cout<<e[0];
                            printf("%s", e[0].c_str());
                            solution.push_back(algorithm[i]);
                            currentState = movement(algorithm[i], currentState);
                        }
                        f = f + algorithm.size();
                        //cout<<"/";
                        printf("/");
                        goto nextStage;
                    }

                    if (!newDir)
                    {
                        q.push(newState);
                        newDir = oldDir;
                        lastMove[newPass] = move;
                        processor[newPass] = oldPass;
                    }
                }
            }
        }

       nextStage:
           ;
    }

    waitKey(2000);
    for(int m = 0; m < 40; m++)
    {
        if(rotation[m] == "U1"){rotateU();}
        if(rotation[m] == "U2"){rotateU(); rotateU();}
        if(rotation[m] == "U3"){rotateU1();}

        if(rotation[m] == "D1"){rotateD();}
        if(rotation[m] == "D2"){rotateD(); rotateD();}
        if(rotation[m] == "D3"){rotateD1();}

        if(rotation[m] == "R1"){rotateR();}
        if(rotation[m] == "R2"){rotateR(); rotateR();}
        if(rotation[m] == "R3"){rotateR1();}

        if(rotation[m] == "L1"){rotateL();}
        if(rotation[m] == "L2"){rotateL(); rotateL();}
        if(rotation[m] == "L3"){rotateL1();}

        if(rotation[m] == "F1"){turnFB(); rotateR(); backFB();}
        if(rotation[m] == "F2"){turnFB(); rotateR(); rotateR(); backFB();}
        if(rotation[m] == "F3"){turnFB(); rotateR1(); backFB();}

        if(rotation[m] == "B1"){turnFB(); rotateL(); backFB();}
        if(rotation[m] == "B2"){turnFB(); rotateL(); rotateL(); backFB();}
        if(rotation[m] == "B3"){turnFB(); rotateL1(); backFB();}

        if(rotation[m] == ""){
            slider1back();
            slider2back();
            slider3back();
            slider4back();
        }
    }
    waitKey(0);
    return 0;
}
