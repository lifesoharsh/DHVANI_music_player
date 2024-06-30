#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <unordered_map>
#include <queue>


using namespace std;
struct Node1 {
    string key;
    Node1* left;
    Node1* right;

    Node1(const string& k) : key(k), left(nullptr), right(nullptr) {}
};


class BST {
public:

    BST() {
        root=nullptr;
    }

    void insert(const string& key) {
        root = insertRecursive(root, key);
    }

    void displayInOrder() const {
        displayInOrderRecursive(root);
        cout << endl;
    }

    ~BST() {
        destroyTree(root);
        root = nullptr;
    }


private:

    Node1* root;

    Node1* insertRecursive(Node1* current, const string& key) {
        if (current == nullptr) {
            return new Node1(key);
        }

        if (key < current->key) {
            current->left = insertRecursive(current->left, key);
        } else if (key > current->key) {
            current->right = insertRecursive(current->right, key);
        }

        return current;
    }


    void displayInOrderRecursive(const Node1* current) const {
        if (current != nullptr) {
            displayInOrderRecursive(current->left);
            cout << current->key << " ";
            displayInOrderRecursive(current->right);
        }
    }


    void destroyTree(Node1* current) {
        if (current != nullptr) {
            destroyTree(current->left);
            destroyTree(current->right);
            delete current;
        }
    }
};



struct User {
    string username;
    string password;
};



class UserAuthentication {
private:

    BST keysBST;
    unordered_map<string, User> users;
    string currentuser;

public:

    void saveUsersToFile() const {
        ofstream file("user_credentials.txt", ios::app);

        if (file.is_open()) {
            for (const auto& entry : users) {
                file << entry.second.username << " " << entry.second.password << endl;
            }

            file.close();
        } else {
            cerr << "Error opening the file for saving user credentials." << endl;
        }
    }


    void registerUser() {
        string username, password;

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;
        readUsersFromFile();

        if (users.find(username) == users.end()) {
            users[username] = {username, password};

            keysBST.insert(username);
            cout << "User " << username << " registered successfully." << endl;
            return;
        } else {
            cout << "Username " << username << " is already taken. Please choose another." << endl;
            registerUser();
        }
    }



  bool authenticateUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;
    readUsersFromFile();

    auto it = users.find(username);

    if (it != users.end() && it->second.password == password) {
        cout << "User " << username << " authenticated successfully." << endl;
        currentuser=username;
        return true;
    } else {
        cout << "Authentication failed. Please check your username and password." << endl;
        // Terminate the program if authentication fails
        cerr << "Authentication failed. Exiting the program." << endl;
        exit(EXIT_FAILURE);
    }
}



string getusername(){
        return currentuser;
    }



    void readUsersFromFile() {
        ifstream file("user_credentials.txt");
        string username, password;

        while (file >> username >> password) {
            users[username] = {username, password};
            keysBST.insert(username);
        }

        file.close();
        return;
    }

    // Function to match user details during authentication

    bool authenticateUser(const string& username, const string& password) {
        auto it = users.find(username);

        if (it != users.end() && it->second.password == password) {
            cout << "User " << username << " authenticated successfully." << endl;
            return true;
        } else {
            cout << "Authentication failed. Please check your username and password." << endl;
            return false;
        }
    }


    void displayKeys() const {
        keysBST.displayInOrder();
    }
};



struct node
{
    char song[100];
    struct node *next;
    struct node *prev;
};




void add_node_file(struct node *first,string a)
    {
    while(first->next!=NULL)
    {
        first=first->next;
    }
    first->next=(struct node*)malloc(sizeof(struct node));
    first->prev=first;
    first=first->next;
    strcpy(first->song,a.c_str());
    first->next=NULL;
}




void del_node(struct node *first)
{
    while((first->next)->next!=NULL)
    {
        first=first->next;
    }
    struct node *temp;
    temp=(first->next)->next;
    first->next=NULL;
    delete(temp);
   cout<<"Deleted"<<endl;
}




void printlist(struct node *first)
{
    cout<<"\nPlaylist Name- ";
    while(first->next!=NULL)
    {
        cout<<first->song<<endl;
        first=first->next;
    }
    cout<<first->song<<endl;
}



void count_nodes(struct node *first)
{
    int i=0;
    while (first->next!=NULL)
    {
        first=first->next;
        i++;
    }
    i++;
    cout<<"\nTotal songs-  "<<i-1<<endl;
}



void search1(struct node *first)
{
    char song[100];
    cout<<"\n\a\a\a\aEnter song To be Searched- ";
    cin>>song;
    int flag=0;

    while(first!=NULL)
    {
        if(strcmp(first->song,song)==0)
        {
            cout<<"\n\a\a\a\a#Song Found"<<endl;
            flag++;
            break;
        }
        else
        {
            first=first->next;
        }
    }


    if(flag==0)
    {
        cout<<"\n\a\a\a\a#Song Not found"<<endl;
    }
}




class LinkedList {

public:
    LinkedList() {}


void savePlaylistToFile(const string& username,string name) {
    fstream file;
    file.open(username + "_playlist.txt", ios::in | ios::app);


    if (file.is_open()) {
            file << name << endl;
        file.close();
    } else {
        cerr << "Error opening the file for saving the playlist." << endl;
    }
}


    void displayPlaylist(string username) const {

    fstream file;
    file.open(username + "_playlist.txt", ios::in);

    if (file.is_open()) {
        string song;
        while (getline(file, song)) {
            cout<<song<<endl;
        }

        file.close();

        cout << "Playlist for user " << username << ":\n";
    } else {
        cerr << "Error opening the file for displaying playlist." << endl;
    }
}

};



void add_node(struct node *first, LinkedList& playlist, UserAuthentication& as)
    {
    char a[100];
    while(first->next!=NULL)
    {
        first=first->next;
    }
    first->next=(struct node*)malloc(sizeof(struct node));
    first->prev=first;
    first=first->next;
    cout<<"\n\a\a\a\aEnter Song name-  ";
    cin>>a;
    playlist.savePlaylistToFile(as.getusername(),a);
    strcpy(first->song,a);
    first->next=NULL;
}


string latest;


class SongQueue {

public:


    void enqueue(string song) {
        songs.push(song);
    }

    void playQueue() {
        while (!songs.empty()) {
            cout<<"Playing queue: "<<endl;
            string song = songs.front();
            latest=song;
            cout<<"Now playing: "<<song<<endl;
            string path=song + ".wav";
            PlaySound(TEXT(path.c_str()),NULL, SND_FILENAME | SND_ASYNC);
            songs.pop();
        }
    }


    string recent(){
        cout<<"Last Played:"<<endl;
        cout<<latest<<endl;
    }
    queue<string> songs;
};



void addplaylist(struct node *start){


    fstream f1;
    string line;
    f1.open("_playlist.txt",ios::in);
    while(!f1.eof())
    {
        getline(f1,line);
        add_node_file(start,line);
    }
    cout<<"Playlist Added"<<endl;
    f1.close();
    printlist(start);
}



void del_search(struct node *start)
{
    char song[100];
    printlist(start);

    cout<<"\n\a\a\a\aChoose song you wish to delete- ";
    cin>>song;
    int flag=0;

    struct node* current=start;

    while(current!=NULL)
    {
        if(strcmp(current->next->song,song)==0)
        {
            cout<<"\n\a\a\a\a#Song Found"<<endl;
            struct node *temp;
            temp= (struct node *)malloc(sizeof(node));

            temp=current->next;
            current->next=current->next->next;

            delete(temp);
            flag++;
            break;
        }

        else
        {
            current=current->next;
        }
    }

    if(flag==0)
    {
        cout<<"\n\a\a\a\a#Song Not found"<<endl;
    }
}


void deletemenu(struct node *start){
    del_search(start);
    }


void deletePlaylistFile(const string& username) {

        string filename = username + "_playlist.txt";
        if (remove(filename.c_str()) == 0) {
            cout << "Playlist file for user " << username << " deleted successfully." << endl;
        } else {
            cerr << "Error deleting the playlist file for user " << username << "." << endl;
        }
    }


void merge(struct node *a, struct node *b, struct node *&sorted) {
    struct node *result = NULL;
    struct node *last = NULL;

    while (a != NULL && b != NULL) {
        if (strcmp(a->song, b->song) < 0) {
            if (result == NULL) {
                result = a;
                result->prev = NULL;
                last = result;
            } else {
                last->next = a;
                a->prev = last;
                last = a;
            }
            a = a->next;
        } else {
            if (result == NULL) {
                result = b;
                result->prev = NULL;
                last = result;
            } else {
                last->next = b;
                b->prev = last;
                last = b;
            }
            b = b->next;
        }
    }

    if (a != NULL) {
        last->next = a;
        a->prev = last;
    } else {
        last->next = b;
        b->prev = last;
    }

    sorted = result;
}



void splitList(struct node *source, struct node *&front, struct node *&back) {
    struct node *fast;
    struct node *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    front = source;
    back = slow->next;
    slow->next = NULL;
}




void mergeSort(struct node *&start) {
    struct node *head = start;
    struct node *a;
    struct node *b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    splitList(head, a, b);

    mergeSort(a);
    mergeSort(b);

    merge(a, b, start);
}




int main()
{
    int choice;
    UserAuthentication authenticationSystem;
    struct node *start;
    start=(struct node *) malloc(sizeof(struct node));


    cout<<"\t\t\t\t\t\t\a\a\a\a*WELCOME TO DHVANI*"<<endl;

    LinkedList playlist;
    SongQueue songQueue;
   int ch;


   cout<<"\n1.Register User\n2.Authenticate User"<<endl;
   cin>>ch;


   if(ch==1){
    authenticationSystem.registerUser();
   }
   else if(ch==2){
    authenticationSystem.authenticateUser();
   }
   cin.ignore();

   cout<<"\n**please use '_' for space."<<endl;
    cout<<"\n\n\a\a\a\aEnter your playlist name-  ";
    cin.getline(start->song,100);
    start->next=NULL;


    do{
        cout<<"\n1.Create Playlist\n2.Delete Song\n3.Display Entered Playlist\n4.Total Songs\n5.Search Song\n";
        cout<<"6.Play Song\n7.Last Played\n8. Sorted playlist\n9.Add From File\n";
        cout<<"10.Delete Playlist\n11. Display Registered Users"<<endl;
        cout<<"12.Add to queue"<<endl;
        cout<<"13. Exit"<<endl;
        cout<<("\n\a\a\a\aEnter your choice- ");
        cin>>choice;



        switch(choice)
        {
            case 1:
                add_node(start,playlist, authenticationSystem);
            break;

            case 2:
                deletemenu(start);
            break;

            case 3:
                if(ch==1){
                printlist(start);
            }
            else if(ch==2){
                playlist.displayPlaylist(authenticationSystem.getusername());
            }
            break;

            case 4:count_nodes(start);
            break;

            case 5:search1(start);
            break;
            case 6:
                songQueue.playQueue();
                break;

            case 7:
                songQueue.recent();
                break;

            case 8:mergeSort(start);
            printlist(start);
            break;

            case 9:addplaylist(start);
            break;
            case 10:
                deletePlaylistFile(authenticationSystem.getusername());
                break;


                case 13:
                authenticationSystem.saveUsersToFile();
                exit(0);
                break;

            case 11:
                cout << "Registered Users: ";
                authenticationSystem.displayKeys();
                break;

            case 12:
                string name;
                cout << "Enter name of the song: ";
                cin >> name;
                songQueue.enqueue(name);
                cout << "Song added to the playlist." << endl;
                break;

        }
    }while(choice!=13);
    return 0;
}
