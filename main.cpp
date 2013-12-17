#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
string answer = "";
void swap (char*,char*,char,char,int,int,char);
void transformation (char*,char*,char*,char*,char*,char*,string);
void twist (char*,char,int);
void rotate(char*,char);
void display (char*,char*,char*,char*,char*,char*);

void transformation (char* fr,char* to,char* bo,char* ri,char* le,char* ba,string T) {
    if (T == "U") {
        swap(fr,le,'R','R',0,0,'n');
        swap(fr,ri,'R','R',0,0,'n');
        swap(ri,ba,'R','R',0,0,'n');
        rotate(to,'c');
    }
    if (T == "F") {
        swap(to,ri,'R','C',2,0,'n');
        swap(le,to,'C','R',2,2,'r');
        swap(le,bo,'C','R',2,0,'n');
        rotate(fr,'c');
        twist(bo,'R',0);
    }
    if (T == "R") {
        swap(ba,bo,'C','C',0,2,'r');
        swap(ba,fr,'C','C',0,2,'n');
        swap(ba,to,'C','C',0,2,'n');
        rotate(ri,'c');
        twist(ba,'C',0);
    }
    if (T == "L") {
        swap(fr,bo,'C','C',0,0,'n');
        swap(fr,to,'C','C',0,0,'n');
        swap(to,ba,'C','C',0,2,'n');
        rotate(le,'c');
        twist(to,'C',0);
        twist(ba,'C',2);
    }
    if (T == "U'") {
        swap(ri,ba,'R','R',0,0,'n');
        swap(fr,ri,'R','R',0,0,'n');
        swap(fr,le,'R','R',0,0,'n');
        rotate(to,'a');
    }
    if (T == "F'") {
        swap(le,bo,'C','R',2,0,'n');
        swap(le,to,'C','R',2,2,'r');
        swap(to,ri,'R','C',2,0,'n');
        rotate(fr,'a');
        twist(le,'C',2);
    }
    if (T == "R'") {
        swap(fr,bo,'C','C',2,2,'n');
        swap(to,fr,'C','C',2,2,'r');
        swap(to,ba,'C','C',2,0,'n');
        rotate(ri,'a');
        twist(to,'C',2);
        twist(ba,'C',0);
        twist(fr,'C',2);
    }
    if (T == "L'") {
        twist(to,'C',0);
        twist(ba,'C',2);
        swap(to,ba,'C','C',0,2,'n');
        swap(fr,to,'C','C',0,0,'n');
        swap(fr,bo,'C','C',0,0,'n');
        rotate(le,'a');
    }
    if (T == "turnright") {
        swap(fr,ri,'R','R',0,0,'n');
        swap(fr,ri,'R','R',1,1,'n');
        swap(fr,ri,'R','R',2,2,'n');
        swap(ri,le,'R','R',0,0,'n');
        swap(ri,le,'R','R',1,1,'n');
        swap(ri,le,'R','R',2,2,'n');
        swap(ri,ba,'R','R',0,0,'n');
        swap(ri,ba,'R','R',1,1,'n');
        swap(ri,ba,'R','R',2,2,'n');
        rotate(to,'c');
        rotate(bo,'a');
    }
    if (T == "turnleft") {
        swap(fr,le,'R','R',0,0,'n');
        swap(fr,le,'R','R',1,1,'n');
        swap(fr,le,'R','R',2,2,'n');
        swap(ri,le,'R','R',0,0,'n');
        swap(ri,le,'R','R',1,1,'n');
        swap(ri,le,'R','R',2,2,'n');
        swap(le,ba,'R','R',0,0,'n');
        swap(le,ba,'R','R',1,1,'n');
        swap(le,ba,'R','R',2,2,'n');
        rotate(to,'a');
        rotate(bo,'c');
    }
    if (T == "D") {
        swap(fr,le,'R','R',2,2,'n');
        swap(le,ri,'R','R',2,2,'n');
        swap(le,ba,'R','R',2,2,'n');
        rotate(bo,'c');
    }
    if (T == "D'") {
        swap(le,ba,'R','R',2,2,'n');
        swap(le,ri,'R','R',2,2,'n');
        swap(fr,le,'R','R',2,2,'n');
        rotate(bo,'a');
    }
    if (T == "turnupsidedown") {
        rotate(fr,'c');
        rotate(fr,'c');
        rotate(ba,'a');
        rotate(ba,'a');
        rotate(le,'c');
        rotate(le,'c');
        rotate(ri,'a');
        rotate(ri,'a');
        swap(ri,le,'R','R',0,0,'n');
        swap(ri,le,'R','R',1,1,'n');
        swap(ri,le,'R','R',2,2,'n');
        rotate(to,'c');
        rotate(to,'c');
        rotate(bo,'a');
        rotate(bo,'a');
        swap(to,bo,'R','R',0,0,'n');
        swap(to,bo,'R','R',1,1,'n');
        swap(to,bo,'R','R',2,2,'n');
    }
    //answer = answer + " " + T;
}
void swap (char* one,char* two,char rcOne,char rcTwo,int rcOneNum,int rcTwoNum,char orient) {
    int k;
    char arrayOne[3];
    char arrayTwo[3];
    if ( rcOne == 'C' && rcTwo == 'C' ) {
        if (orient == 'n') {
            for (int i = 0; i < 3; i++) {
                arrayTwo[i] = *(two+3*i+rcTwoNum);
                arrayOne[i] = *(one+3*i+rcOneNum);
            }
        }
        else {
            k = 2;
            for (int i = 0; i < 3; i++) {
                arrayTwo[i] = *(two+3*i+rcTwoNum);
                arrayOne[i] = *(one+3*k+rcOneNum);
                k--;
            }
        }
        for (int i = 0; i < 3; i++) {
            *(two+3*i+rcTwoNum) = arrayOne[i];
            *(one+3*i+rcOneNum) = arrayTwo[i];
        }
    }
    if ( rcOne == 'C' && rcTwo == 'R' ) {
        if (orient == 'n') {
            for (int i = 0; i < 3; i++) {
                arrayTwo[i] = *(two+3*rcTwoNum+i);
                arrayOne[i] = *(one+3*i+rcOneNum);
            }
        }
        else {
            k = 2;
            for (int i = 0; i < 3; i++) {
                arrayTwo[i] = *(two+3*rcTwoNum+i);
                arrayOne[i] = *(one+3*k+rcOneNum);
                k--;
            }
        }
        for (int i = 0; i < 3; i++) {
            *(two+3*rcTwoNum+i) = arrayOne[i];
            *(one+3*i+rcOneNum) = arrayTwo[i];
        }
    }
    if ( rcOne == 'R' && rcTwo == 'C' ) {
        if (orient == 'n') {
            for (int i = 0; i < 3; i++) {
                arrayTwo[i] = *(two+3*i+rcTwoNum);
                arrayOne[i] = *(one+3*rcOneNum+i);
            }
        }
        else {
            k = 2;
            for (int i = 0; i < 3; i++) {
                arrayTwo[i] = *(two+3*i+rcTwoNum);
                arrayOne[i] = *(one+3*rcOneNum+k);
                k--;
            }
        }
        for (int i = 0; i < 3; i++) {
            *(two+3*i+rcTwoNum) = arrayOne[i];
            *(one+3*rcOneNum+i) = arrayTwo[i];
        }
    }
    if ( rcOne == 'R' && rcTwo == 'R' ) {
        if (orient == 'n') {
            for (int i = 0; i < 3; i++) {
                arrayTwo[i] = *(two+3*rcTwoNum+i);
                arrayOne[i] = *(one+3*rcOneNum+i);
            }
        }
        else {
            k = 2;
            for (int i = 0; i < 3; i++) {
                arrayTwo[i] = *(two+3*rcTwoNum+i);
                arrayOne[i] = *(one+3*rcOneNum+k);
                k--;
            }
        }
        for (int i = 0; i < 3; i++) {
            *(two+3*rcTwoNum+i) = arrayOne[i];
            *(one+3*rcOneNum+i) = arrayTwo[i];
        }
    }
}
void twist (char* face,char rc,int rcNum) {
    char temp;
    if ( rc == 'R') {
        temp = *(face+3*rcNum);
        *(face+3*rcNum) = *(face+3*rcNum+2);
        *(face+3*rcNum+2) = temp;
    }
    if ( rc == 'C' ) {
        temp = *(face+rcNum);
        *(face+rcNum) = *(face+6+rcNum);
        *(face+6+rcNum) = temp;
    }
}
void rotate (char* face,char direction) {
    char a1,a2,a3;
    a1 = *(face);
    a2 = *(face+1);
    a3 = *(face+2);
    if (direction == 'c') {
        *(face) = *(face+6);
        *(face+1) = *(face+3);
        *(face+2) = a1;
        *(face+3) = *(face+7);
        *(face+6) = *(face+8);
        *(face+7) = *(face+5);
        *(face+8) = a3;
        *(face+5) = a2;
    }
    else {
        *(face) = a3;
        *(face+1) = *(face+5);
        *(face+2) = *(face+8);
        *(face+5) = *(face+7);
        *(face+8) = *(face+6);
        *(face+7) = *(face+3);
        *(face+6) = a1;
        *(face+3) = a2;
    }
}
void fle(char* fr,char* to,char* bo,char* ri,char* le,char* ba,int num) {
    if (num == 1) {
        transformation(fr,to,bo,ri,le,ba,"F");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"D");
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"D'");
    }
    if (num == 2) {
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"L");
        transformation(fr,to,bo,ri,le,ba,"F");
        transformation(fr,to,bo,ri,le,ba,"F");
        transformation(fr,to,bo,ri,le,ba,"L'");
        transformation(fr,to,bo,ri,le,ba,"R");
    }
    if (num == 3) {
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"D'");
        transformation(fr,to,bo,ri,le,ba,"F'");
        transformation(fr,to,bo,ri,le,ba,"D");
    }
    if (num == 4) {
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"D");
        transformation(fr,to,bo,ri,le,ba,"D");
        transformation(fr,to,bo,ri,le,ba,"L");
        transformation(fr,to,bo,ri,le,ba,"D'");
        transformation(fr,to,bo,ri,le,ba,"D'");
    }
    if (num == 5) {
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"R'");
    }
    if (num == 6) {
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"F'");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"F");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"R'");
    }
    if (num == 7) {
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"F'");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"F");
    }
}

void firstlayer (char* fr,char* to,char* bo,char* ri,char* le,char* ba) {
    int count = 0;
    int pcount = 0;
    int check = 0;
    for (int k = 0; k < 4; k++) {
        if (!(*(bo)==*(bo+4)&&*(bo+2)==*(bo+4)&&*(bo+6)==*(bo+4)&&*(bo+8)==*(bo+4)&&*(fr+6)==*(fr+8)&&*(ri+6)==*(ri+8)&&*(le+6)==*(le+8)&&*(ba+6)==*(ba+8))) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (*(bo+2)==*(bo+4)&&*(ri+6)==*(ri+4)&&*(fr+8)==*(fr+4)) {
                        count++;
                        break;
                    }
                    if (*(fr)==*(ri+4)&&*(to+6)==*(fr+4)&&*(le+2)==*(bo+4)) {
                        fle(fr,to,bo,ri,le,ba,5);
                        count++;
                        break;
                    }
                    if (*(fr+2)==*(bo+4)&&*(to+8)==*(fr+4)&&*(ri)==*(ri+4)) {
                        transformation(fr,to,bo,ri,le,ba,"U");
                        fle(fr,to,bo,ri,le,ba,5);
                        count++;
                        break;
                    }
                    if (*(to+6)==*(bo+4)&&*(fr)==*(fr+4)&&*(le+2)==*(ri+4)) {
                        fle(fr,to,bo,ri,le,ba,6);
                        count++;
                        break;
                    }
                    if (*(to+8)==*(bo+4)&&*(ri)==*(fr+4)&&*(fr+2)==*(ri+4)) {
                        transformation(fr,to,bo,ri,le,ba,"U");
                        fle(fr,to,bo,ri,le,ba,6);
                        count++;
                        break;
                    }
                    if (*(ri)==*(bo+4)&&*(fr+2)==*(fr+4)&&*(to+8)==*(ri+4)) {
                        fle(fr,to,bo,ri,le,ba,7);
                        count++;
                        break;
                    }
                    if (*(fr)==*(bo+4)&&*(le+2)==*(fr+4)&&*(to+6)==*(ri+4)) {
                        transformation(fr,to,bo,ri,le,ba,"U'");
                        fle(fr,to,bo,ri,le,ba,7);
                        count++;
                        break;
                    }
                    transformation(fr,to,bo,ri,le,ba,"U");
                }
                transformation(fr,to,bo,ri,le,ba,"turnright");
            }
        }
        if (!(*(bo)==*(bo+4)&&*(bo+2)==*(bo+4)&&*(bo+6)==*(bo+4)&&*(bo+8)==*(bo+4)&&*(fr+6)==*(fr+8)&&*(ri+6)==*(ri+8)&&*(le+6)==*(le+8)&&*(ba+6)==*(ba+8))) {
            while (1) {
                if (!(*(bo+2)==*(bo+4)&&*(ri+6)==*(ri+4)&&*(fr+8)==*(fr+4))) {
                    fle(fr,to,bo,ri,le,ba,7);
                    break;
                }
                transformation(fr,to,bo,ri,le,ba,"turnright");
            }
        }
    }
    while (*(fr+8)!=*(fr+4)) {
        transformation(fr,to,bo,ri,le,ba,"D");
    }
    count = 0;
    pcount = 0;
    while (count != 4) {
        if (*(bo+1)==*(bo+4)&&*(bo+3)==*(bo+4)&&*(bo+5)==*(bo+4)&&*(bo+7)==*(bo+4)&&*(fr+7)==*(fr+8)&&*(ri+7)==*(ri+8)&&*(le+7)==*(le+8)&&*(ba+7)==*(ba+8)) {
            break;
        }
        for (int i = 0; i < 3; i++) {
            if (*(fr+1)==*(bo+4)) {
                while (1) {
                    transformation(fr,to,bo,ri,le,ba,"D");
                    if (*(to+7)==*(fr+8)) {
                        break;
                    }
                }
                fle(fr,to,bo,ri,le,ba,1);
                count++;
            }
            if (*(to+7)==*(bo+4)) {
                while (1) {
                    transformation(fr,to,bo,ri,le,ba,"D");
                    if (*(fr+1)==*(fr+8)) {
                        break;
                    }
                }
                fle(fr,to,bo,ri,le,ba,2);
                count++;
            }
            if (*(le+5)==*(bo+4)) {
                while (1) {
                    transformation(fr,to,bo,ri,le,ba,"D");
                    if (*(fr+3)==*(ri+8)) {
                        break;
                    }
                }
                fle(fr,to,bo,ri,le,ba,3);
                count++;
            }
            if (*(fr+3)==*(bo+4)) {
                while (1) {
                    transformation(fr,to,bo,ri,le,ba,"D");
                    if (*(le+5)==*(ri+8)) {
                        break;
                    }
                }
                fle(fr,to,bo,ri,le,ba,4);
                count++;
            }
            transformation(fr,to,bo,ri,le,ba,"turnright");
        }
        if (count == pcount) {
            while (1) {
                if (!(*(fr+7)==*(fr+8)&&*(bo+1)==*(bo+4))) {
                    fle(fr,to,bo,ri,le,ba,1);
                    break;
                }
                transformation(fr,to,bo,ri,le,ba,"turnright");
            }
        }
        pcount = count;
    }
    while (*(fr+7)!=*(fr+4)) {
        transformation(fr,to,bo,ri,le,ba,"D");
    }
}
void mle (char* fr,char* to,char* bo,char* ri,char* le,char* ba,char orient) {
    if ( orient == 'r' ) {
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"F'");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"F");
    }
    if ( orient == 'l' ) {
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"L'");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"L");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"F");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"F'");
    }
}
void middlelayer (char* fr,char* to,char* bo,char* ri,char* le,char* ba) {
    int count = 0;
    int pcount = 0;
    while ( *(fr+3)!=*(fr+4) || *(fr+5)!=*(fr+4) || *(ri+3)!=*(ri+4) || *(ri+5)!=*(ri+4) || *(le+3)!=*(le+4) || *(le+5)!=*(le+4) || *(ba+3)!=*(ba+4) || *(ba+5)!=*(ba+4)) {
        if (*(fr+3)==*(fr+4) && *(fr+5)==*(fr+4) && *(ri+3)==*(ri+4) && *(ri+5)==*(ri+4) && *(le+3)==*(le+4) && *(le+5)==*(le+4) && *(ba+3)==*(ba+4) && *(ba+5)==*(ba+4)) {
            break;
        }
        if ( (*(fr+1)==*(to+4) || *(to+7)==*(to+4)) && (*(ri+1)==*(to+4) || *(to+5)==*(to+4)) && (*(le+1)==*(to+4) || *(to+3)==*(to+4)) && (*(ba+1)==*(to+4) || *(to+1)==*(to+4)) ) {
            if (*(fr+5)!=*(fr+4)&&*(ri+3)!=*(ri+4)) {
                mle (fr,to,bo,ri,le,ba,'r');
            }
            else if (*(fr+3)!=*(fr+4)&&*(le+5)!=*(le+4)) {
                mle (fr,to,bo,ri,le,ba,'l');
            }
            else {
                transformation(fr,to,bo,ri,le,ba,"turnright");
                transformation(fr,to,bo,ri,le,ba,"turnright");
            }
        }
        if ( (*(fr+1)==*(to+4) || *(to+7)==*(to+4)) && (*(ri+1)==*(to+4) || *(to+5)==*(to+4)) && (*(le+1)==*(to+4) || *(to+3)==*(to+4)) && (*(ba+1)==*(to+4) || *(to+1)==*(to+4)) ) {
            if (*(fr+5)!=*(fr+4)&&*(ri+3)!=*(ri+4)) {
                mle (fr,to,bo,ri,le,ba,'r');
            }
            else if (*(fr+3)!=*(fr+4)&&*(le+5)!=*(le+4)) {
                mle (fr,to,bo,ri,le,ba,'l');
            }
        }
        if ( *(fr+1) == *(fr+4) && *(to+7) == *(ri+4) ) {
            mle (fr,to,bo,ri,le,ba,'r');
            count++;
        }
        if ( *(fr+1) == *(fr+4) && *(to+7) == *(le+4) ) {
            mle (fr,to,bo,ri,le,ba,'l');
            count++;
        }
        if ( (*(ri+1) == *(fr+4) && *(to+5) == *(ri+4)) || (*(ri+1) == *(fr+4) && *(to+5) == *(le+4)) ) {
            transformation(fr,to,bo,ri,le,ba,"U");
            if ( *(fr+1) == *(fr+4) && *(to+7) == *(ri+4) ) {
                mle (fr,to,bo,ri,le,ba,'r');
                count++;
            }
            if ( *(fr+1) == *(fr+4) && *(to+7) == *(le+4) ) {
                mle (fr,to,bo,ri,le,ba,'l');
                count++;
            }
        }
        if ( (*(le+1) == *(fr+4) && *(to+3) == *(ri+4)) || (*(le+1) == *(fr+4) && *(to+3) == *(le+4)) ) {
            transformation(fr,to,bo,ri,le,ba,"U'");
            if ( *(fr+1) == *(fr+4) && *(to+7) == *(ri+4) ) {
                mle (fr,to,bo,ri,le,ba,'r');
                count++;
            }
            if ( *(fr+1) == *(fr+4) && *(to+7) == *(le+4) ) {
                mle (fr,to,bo,ri,le,ba,'l');
                count++;
            }
        }
        if ( (*(ba+1) == *(fr+4) && *(to+1) == *(ri+4)) || (*(ba+1) == *(fr+4) && *(to+1) == *(le+4)) ) {
            transformation(fr,to,bo,ri,le,ba,"U");
            transformation(fr,to,bo,ri,le,ba,"U");
            if ( *(fr+1) == *(fr+4) && *(to+7) == *(ri+4) ) {
                mle (fr,to,bo,ri,le,ba,'r');
                count++;
            }
            if ( *(fr+1) == *(fr+4) && *(to+7) == *(le+4) ) {
                mle (fr,to,bo,ri,le,ba,'l');
                count++;
            }
        }
        if ( *(fr+3)!=*(fr+4) || *(fr+5)!=*(fr+4) || *(ri+3)!=*(ri+4) || *(ri+5)!=*(ri+4) || *(le+3)!=*(le+4) || *(le+5)!=*(le+4) || *(ba+3)!=*(ba+4) || *(ba+5)!=*(ba+4)) {
            transformation(fr,to,bo,ri,le,ba,"turnright");
        }
        if (pcount == count) {
            while (1) {
                transformation(fr,to,bo,ri,le,ba,"turnright");
                if (!(*(fr+5)==*(fr+4)&&*(ri+3)==*(ri+4))) {
                    mle (fr,to,bo,ri,le,ba,'r');
                    break;
                }
            }
        }
        pcount = count;
        transformation(fr,to,bo,ri,le,ba,"turnright");
    }
}
void lle (char* fr,char* to,char* bo,char* ri,char* le,char* ba,int num) {
    if ( num == 1 ) {
        transformation(fr,to,bo,ri,le,ba,"F");
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"F'");
    }
    if ( num == 2 ) {
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"U");
    }
    if ( num == 3 ) {
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"L'");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"L");
    }
    if ( num == 4 ) {
        transformation(fr,to,bo,ri,le,ba,"R");
        transformation(fr,to,bo,ri,le,ba,"U");
        transformation(fr,to,bo,ri,le,ba,"R'");
        transformation(fr,to,bo,ri,le,ba,"U'");
    }
}
void lastlayer(char* fr,char* to,char* bo,char* ri,char* le,char* ba) {
    while (!((*(to+1) == *(to+4) && *(to+3) == *(to+4))||(*(to+3) == *(to+4) && *(to+7) == *(to+4))||(*(to+1) == *(to+4) &&  *(to+5) == *(to+4))||(*(to+5) == *(to+4) && *(to+7) == *(to+4))||(*(to+3) == *(to+4) && *(to+5) == *(to+4))||(*(to+1) == *(to+4) && *(to+7)== *(to+4)))) {
        lle(fr,to,bo,ri,le,ba,1);
    }
    if (*(to+3) == *(to+4) && *(to+7) == *(to+4)) {
        transformation(fr,to,bo,ri,le,ba,"U");
    }
    if (*(to+1) == *(to+4) &&  *(to+5) == *(to+4)) {
        transformation(fr,to,bo,ri,le,ba,"U'");
    }
    if (*(to+5) == *(to+4) && *(to+7) == *(to+4)) {
        transformation(fr,to,bo,ri,le,ba,"U'");
        transformation(fr,to,bo,ri,le,ba,"U'");
    }
    if (*(to+1) == *(to+4) && *(to+7)== *(to+4)) {
        transformation(fr,to,bo,ri,le,ba,"U");
    }
    while (!(*(to+1) == *(to+4) && *(to+3) == *(to+4) && *(to+5) == *(to+4) && *(to+7) == *(to+4))) {
        lle(fr,to,bo,ri,le,ba,1);
    }
    int check = 0;
    int asdf;
    for (asdf = 0; asdf < 10; asdf++) {
        if ((*(fr+1)==*(fr+4)&&*(le+1)==*(le+4)&&*(ri+1)==*(ri+4)&&*(ba+1)==*(ba+4))) {
            break;
        }
    if (!(*(fr+1)==*(fr+4)&&*(le+1)==*(le+4)&&*(ri+1)==*(ri+4)&&*(ba+1)==*(ba+4))) {
        for (int i = 0; i < 4; i++) {
            if ( *(le+1) == *(le+4) && *(ba+1) == *(ba+4)) {
                transformation(fr,to,bo,ri,le,ba,"turnright");
                check = 1;
                break;
            }
            if (*(fr+1)==*(fr+4) && *(le+1)==*(le+4)) {
                transformation(fr,to,bo,ri,le,ba,"turnright");
                transformation(fr,to,bo,ri,le,ba,"turnright");
                check = 1;
                break;
            }
            if (*(fr+1)==*(fr+4) && *(ri+1)==*(ri+4)) {
                transformation(fr,to,bo,ri,le,ba,"turnleft");
                check = 1;
                break;
            }
            if (*(ri+1)==*(ri+4) && *(ba+1)==*(ba+4)) {
                check = 1;
                break;
            }
            transformation(fr,to,bo,ri,le,ba,"U");
        }
    }
    if (check == 1) {
        lle(fr,to,bo,ri,le,ba,2);
        check = 0;
    }
    else {
        if (*(fr+1)==*(fr+4)&&*(ba+1)==*(ba+4)) {
            transformation(fr,to,bo,ri,le,ba,"turnright");
            lle(fr,to,bo,ri,le,ba,2);
        }
        else if (*(ri+1)==*(ri+4)&&*(le+1)==*(le+4)) {
            lle(fr,to,bo,ri,le,ba,2);
        }
    }
    if (!(*(fr+1)==*(fr+4)&&*(le+1)==*(le+4)&&*(ri+1)==*(ri+4)&&*(ba+1)==*(ba+4))) {
        for (int i = 0; i < 4; i++) {
            if ( *(le+1) == *(le+4) && *(ba+1) == *(ba+4)) {
                transformation(fr,to,bo,ri,le,ba,"turnright");
                check = 1;
                break;
            }
            if (*(fr+1)==*(fr+4) && *(le+1)==*(le+4)) {
                transformation(fr,to,bo,ri,le,ba,"turnright");
                transformation(fr,to,bo,ri,le,ba,"turnright");
                check = 1;
                break;
            }
            if (*(fr+1)==*(fr+4) && *(ri+1)==*(ri+4)) {
                transformation(fr,to,bo,ri,le,ba,"turnleft");
                check = 1;
                break;
            }
            if (*(ri+1)==*(ri+4) && *(ba+1)==*(ba+4)) {
                check = 1;
                break;
            }
            transformation(fr,to,bo,ri,le,ba,"U");
        }
    }
    if (check == 1) {
        lle(fr,to,bo,ri,le,ba,2);
        check = 0;
    }
        if (!(*(fr+1)==*(fr+4)&&*(le+1)==*(le+4)&&*(ri+1)==*(ri+4)&&*(ba+1)==*(ba+4))) {
            while (1) {
                transformation(fr,to,bo,ri,le,ba,"U");
                if (*(fr+1)==*(fr+4)) {
                    break;
                }
            }
            transformation(fr,to,bo,ri,le,ba,"turnleft");
            lle(fr,to,bo,ri,le,ba,2);
            if (!(*(fr+1)==*(fr+4)&&*(le+1)==*(le+4)&&*(ri+1)==*(ri+4)&&*(ba+1)==*(ba+4))) {
                for (int i = 0; i < 4; i++) {
                    if ( *(le+1) == *(le+4) && *(ba+1) == *(ba+4)) {
                        transformation(fr,to,bo,ri,le,ba,"turnright");
                        check = 1;
                        break;
                    }
                    if (*(fr+1)==*(fr+4) && *(le+1)==*(le+4)) {
                        transformation(fr,to,bo,ri,le,ba,"turnright");
                        transformation(fr,to,bo,ri,le,ba,"turnright");
                        check = 1;
                        break;
                    }
                    if (*(fr+1)==*(fr+4) && *(ri+1)==*(ri+4)) {
                        transformation(fr,to,bo,ri,le,ba,"turnleft");
                        check = 1;
                        break;
                    }
                    if (*(ri+1)==*(ri+4) && *(ba+1)==*(ba+4)) {
                        check = 1;
                        break;
                    }
                    transformation(fr,to,bo,ri,le,ba,"U");
                }
            }
            if (check == 1) {
                lle(fr,to,bo,ri,le,ba,2);
                check = 0;
            }
            else {
                if (*(fr+1)==*(fr+4)&&*(ba+1)==*(ba+4)) {
                    transformation(fr,to,bo,ri,le,ba,"turnright");
                    lle(fr,to,bo,ri,le,ba,2);
                }
                else if (*(ri+1)==*(ri+4)&&*(le+1)==*(le+4)) {
                    lle(fr,to,bo,ri,le,ba,2);
                }
            }
        }

    }
        if ( asdf != 0 ) {
            while ((*(fr+2)**(to+8)**(ri)!=*(fr+4)**(to+4)**(ri+4))||(*(fr)**(to+6)**(le+2)!=*(fr+4)**(to+4)**(le+4))||(*(ba+2)**(to)**(le)!=*(ba+4)**(to+4)**(le+4))||(*(ba)**(to+2)**(ri+2)!=*(ba+4)**(to+4)**(ri+4))) {
                if ( *(fr+2)**(to+8)**(ri) == *(fr+4)**(to+4)**(ri+4) ) {
                    while (*(fr+2)**(to+8)**(ri)!=*(fr+4)**(to+4)**(ri+4)||*(fr)**(to+6)**(le+2)!=*(fr+4)**(to+4)**(le+4)||*(ba+2)**(to)**(le)!=*(ba+4)**(to+4)**(le+4)||*(ba)**(to+2)**(ri+2)!=*(ba+4)**(to+4)**(ri+4)) {
                        lle(fr,to,bo,ri,le,ba,3);
                    }
                }
                if (*(fr)**(to+6)**(le+2) == *(fr+4)**(to+4)**(le+4)) {
                    transformation(fr,to,bo,ri,le,ba,"turnleft");
                    while (*(fr+2)**(to+8)**(ri)!=*(fr+4)**(to+4)**(ri+4)||*(fr)**(to+6)**(le+2)!=*(fr+4)**(to+4)**(le+4)||*(ba+2)**(to)**(le)!=*(ba+4)**(to+4)**(le+4)||*(ba)**(to+2)**(ri+2)!=*(ba+4)**(to+4)**(ri+4)) {
                        lle(fr,to,bo,ri,le,ba,3);
                    }
                }
                if (*(ba+2)**(to)**(le) == *(ba+4)**(to+4)**(le+4)) {
                    transformation(fr,to,bo,ri,le,ba,"turnleft");
                    transformation(fr,to,bo,ri,le,ba,"turnleft");
                    while (*(fr+2)**(to+8)**(ri)!=*(fr+4)**(to+4)**(ri+4)||*(fr)**(to+6)**(le+2)!=*(fr+4)**(to+4)**(le+4)||*(ba+2)**(to)**(le)!=*(ba+4)**(to+4)**(le+4)||*(ba)**(to+2)**(ri+2)!=*(ba+4)**(to+4)**(ri+4)) {
                        lle(fr,to,bo,ri,le,ba,3);
                    }
                }
                if (*(ba)**(to+2)**(ri+2) == *(ba+4)**(to+4)**(ri+4)) {
                    transformation(fr,to,bo,ri,le,ba,"turnright");
                    while (*(fr+2)**(to+8)**(ri)!=*(fr+4)**(to+4)**(ri+4)||*(fr)**(to+6)**(le+2)!=*(fr+4)**(to+4)**(le+4)||*(ba+2)**(to)**(le)!=*(ba+4)**(to+4)**(le+4)||*(ba)**(to+2)**(ri+2)!=*(ba+4)**(to+4)**(ri+4)) {
                        lle(fr,to,bo,ri,le,ba,3);
                    }
                }
                if ((*(fr+2)**(to+8)**(ri)!=*(fr+4)**(to+4)**(ri+4))&&(*(fr)**(to+6)**(le+2)!=*(fr+4)**(to+4)**(le+4))&&(*(ba+2)**(to)**(le)!=*(ba+4)**(to+4)**(le+4))&&(*(ba)**(to+2)**(ri+2)!=*(ba+4)**(to+4)**(ri+4))) {
                    lle(fr,to,bo,ri,le,ba,3);
                }
            }
            transformation(fr,to,bo,ri,le,ba,"turnupsidedown");
            while ( *(bo)!=*(bo+4) || *(bo+2)!=*(bo+4) || *(bo+8)!=*(bo+4) || *(bo+6)!=*(bo+4) || *(fr+6)!=*(fr+7) || *(fr+8)!=*(fr+7) || *(ba+6)!=*(ba+7) || *(ba+8)!=*(ba+7)) {
                while ((*(fr+8)!=*(fr+7) || *(bo+2)!=*(bo+4))) {
                    lle(fr,to,bo,ri,le,ba,4);
                }
                transformation(fr,to,bo,ri,le,ba,"D");
            }
            while (*(fr+7)!=*(fr+4)) {
                transformation(fr,to,bo,ri,le,ba,"D");
            }
        }
}
void display (char* fr,char* to,char* bo,char* ri,char* le,char* ba) {
    
    cout << endl;
    cout << "Front" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << fr[3*i+j];
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Top" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << to[3*i+j];
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Bottom" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << bo[3*i+j];
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Right" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ri[3*i+j];
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Left" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << le[3*i+j];
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Back" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ba[3*i+j];
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    
    char front[3][3],top[3][3],bottom[3][3],right[3][3],left[3][3],back[3][3];
    char* fr;
    char* to;
    char* bo;
    char* ri;
    char* le;
    char* ba;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> front[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> top[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> bottom[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> right[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> left[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> back[i][j];
        }
    }
    
    fr = &front[0][0];
    to = &top[0][0];
    bo = &bottom[0][0];
    ri = &right[0][0];
    le = &left[0][0];
    ba = &back[0][0];
    
    firstlayer(fr,to,bo,ri,le,ba);
    display(fr,to,bo,ri,le,ba);
    cout << answer;
    answer = "";
    middlelayer(fr,to,bo,ri,le,ba);
    display(fr,to,bo,ri,le,ba);
    cout << answer;
    answer = "";
    lastlayer(fr,to,bo,ri,le,ba);
    display(fr,to,bo,ri,le,ba);
    cout << answer;
    answer = "";
    
    /*char ans[1000];
     ans = answer.c_str();
     int i = 1;
     char a1s[10];
     char a2s[10];
     char a3s[10];
     char a4s[10];
     int a11,a22,a33,a44;
     string output = "";
     int k = 0;
     while (ans[i]!='\0') {
     for (int a11 = i+1; ans[a11] != " " ; a11++) {
     a1s[k] = ans[a11];
     k++;
     }
     k = 0;
     for (int a22 = a11; ans[a22] != " " ; a22++) {
     a2s[k] = ans[a22];
     k++;
     }
     k = 0;
     for (int a33 = a22; ans[a33] != " " ; a33++) {
     a3s[k] = ans[a33];
     k++;
     }
     k = 0;
     for (int a44 = a33; ans[a44] != " " ; a44++) {
     a4s[k] = ans[a44];
     k++;
     }
     k = 0;
     if (a1s == a2s && a2s == a3s && a3s == a4s) {
     output = output + a1s;
     i = a4;
     }
     else {
     output = output + a1s;
     i++;
     }
     }
     cout << output;*/
    //cout << answer;
    return 0;
}


