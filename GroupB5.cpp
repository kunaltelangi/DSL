#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct node {
    char name[20];
    node *next;
    node *down;
    int flag;
};

class Gll {
    char ch[20];
    int n, i;
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;

public:
    node *create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};

node *Gll::create() {
    node *p = new(struct node);
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    cout << "\nEnter the name: ";
    cin >> p->name;
    return p;
}

void Gll::insertb() {
    if (head == NULL) {
        t1 = create();
        head = t1;
    } else {
        cout << "\nBook already exists.";
    }
}

void Gll::insertc() {
    if (head == NULL) {
        cout << "\nThere is no book.";
    } else {
        cout << "\nHow many chapters do you want to insert? ";
        cin >> n;
        for (i = 0; i < n; i++) {
            t1 = create();
            if (head->flag == 0) {
                head->down = t1;
                head->flag = 1;
            } else {
                temp = head;
                temp = temp->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}

void Gll::inserts() {
    if (head == NULL) {
        cout << "\nThere is no book.";
    } else {
        cout << "\nEnter the name of the chapter where you want to enter the section: ";
        cin >> ch;
        temp = head;
        if (temp->flag == 0) {
            cout << "\nThere are no chapters in the book.";
        } else {
            temp = temp->down;
            while (temp != NULL) {
                if (!strcmp(ch, temp->name)) {
                    cout << "\nHow many sections do you want to enter? ";
                    cin >> n;
                    for (i = 0; i < n; i++) {
                        t1 = create();
                        if (temp->flag == 0) {
                            temp->down = t1;
                            temp->flag = 1;
                            t2 = temp->down;
                        } else {
                            while (t2->next != NULL)
                                t2 = t2->next;
                            t2->next = t1;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void Gll::insertss() {
    if (head == NULL) {
        cout << "\nThere is no book.";
    } else {
        cout << "\nEnter the name of the chapter where you want to enter the section: ";
        cin >> ch;
        temp = head;
        if (temp->flag == 0) {
            cout << "\nThere are no chapters in the book.";
        } else {
            temp = temp->down;
            while (temp != NULL) {
                if (!strcmp(ch, temp->name)) {
                    cout << "\nEnter the name of section in which you want to enter the subsection: ";
                    cin >> ch;
                    if (temp->flag == 0) {
                        cout << "\nThere are no sections.";
                    } else {
                        temp = temp->down;
                        while (temp != NULL) {
                            if (!strcmp(ch, temp->name)) {
                                cout << "\nHow many subsections do you want to enter? ";
                                cin >> n;
                                for (i = 0; i < n; i++) {
                                    t1 = create();
                                    if (temp->flag == 0) {
                                        temp->down = t1;
                                        temp->flag = 1;
                                        t2 = temp->down;
                                    } else {
                                        while (t2->next != NULL)
                                            t2 = t2->next;
                                        t2->next = t1;
                                    }
                                }
                                break;
                            }
                            temp = temp->next;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void Gll::displayb() {
    if (head == NULL) {
        cout << "\nBook does not exist.";
    } else {
        temp = head;
        cout << "\nName of Book: " << temp->name;
        if (temp->flag == 1) {
            temp = temp->down;
            while (temp != NULL) {
                cout << "\n\tName of Chapter: " << temp->name;
                t1 = temp;
                if (t1->flag == 1) {
                    t1 = t1->down;
                    while (t1 != NULL) {
                        cout << "\n\t\tName of Section: " << t1->name;
                        t2 = t1;
                        if (t2->flag == 1) {
                            t2 = t2->down;
                            while (t2 != NULL) {
                                cout << "\n\t\t\tName of Subsection: " << t2->name;
                                t2 = t2->next;
                            }
                        }
                        t1 = t1->next;
                    }
                }
                temp = temp->next;
            }
        }
    }
}

int main() {
    Gll g;
    int x;
    while (1) {
        cout << "\n\nEnter your choice";
        cout << "\n1. Insert book";
        cout << "\n2. Insert chapter";
        cout << "\n3. Insert section";
        cout << "\n4. Insert subsection";
        cout << "\n5. Display book";
        cout << "\n6. Exit";
        cin >> x;
        switch (x) {
            case 1:
                g.insertb();
                break;
            case 2:
                g.insertc();
                break;
            case 3:
                g.inserts();
                break;
            case 4:
                g.insertss();
                break;
            case 5:
                g.displayb();
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}
