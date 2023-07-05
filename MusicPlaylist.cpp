// DO NOT MODIFY THIS STRUCT
#include<iostream>
using namespace std;

struct Node
{
    string song_title;
    int id;
    Node *next;

    Node(string s, int i, Node* n){
        song_title = s;
        id = i;
        next = n;
    }
};

class playlist{
private:
    Node* head;
public:
    playlist()
    {
        head=NULL;

    }
    Node* getHead()
    {
        return head;
    }

    void insert_song(Node* &head, string s, int i)
    { //recursive
    // your implementation here
        if(head == NULL)
        {                             //adding new node if list is empty
            head = new Node(s, i, NULL);
            return;
        }

        else if(head->next==NULL)
        {
            head->next = new Node(s, i, NULL);
            return;
        }

        insert_song(head->next, s, i); //recursive calling t/f acting as loop to move to next

    }
    void insert_song_after(Node* &head, string s, int i, string song2)
    { //iterative (song2 is the song after which new song should be inserted)
    // your implementation her

    Node* here = head;

    if (here == NULL)
    {
        return;
    }

    else
    {
        while (here->song_title != song2 &&
                here->next != NULL)
            here = here->next;

        if (here->song_title == song2)
            {
            Node* temp = here->next;
            here->next = new Node(s, i, temp);
            }
    }
    }

    void delete_song(Node* &head, Node* prev)
    { //recursive
    // your implementation here
        Node* current = head; 

        if(head == NULL)
        {
            return;
        }
        else if(head->next=NULL)
        {
            delete current;
            prev->next = NULL;
        
            return;
        }
        delete_song(head->next, head);

    }
    void display_playlist(Node* head)
    { //recursive
    // your implementation here
    if(head==NULL)
    {    
    return;
    }
    cout<<"Song title : "<< head->song_title <<" & Id : "<<head->id << endl; 
    display_playlist(head->next);

    }
    int find_min(Node* head, int length)
    { //recursive
    // your implementation here
        if(length != 0)
        {
            return head->id;
        }
        else if(head->id>find_min(head->next, length-1))
        {
            return head->id;
        }

    }
    int playlist_size(Node* head)
    { //recursive
    // your implementation here
    if(head==NULL)  
    return 0;

    return playlist_size(head->next) + 1;   
 
    }
    void search_song(Node* head,string song)
    { //recursive
    // your implementation here
    Node* here = head;
    if (here == NULL)
    {
        cout<<"The list is Empty. "<<endl;
        return;
    }
    if(here->song_title == song)
    {
        cout<<"Details : "<<endl;
        cout<<"Song title = "<<here->song_title<<" & ID = "<<here->id<<endl;
        return;
    }
    search_song(head->next,song);

    }
    void search_song(Node* head, int id)
    { //recursive
    // your implementation here

    Node* here = head;
    if (here == NULL)
    {
        cout<<"The list is Empty. "<<endl;
        return;
    }
    if(here->id == id)
    {
        cout<<"Details : "<<endl;
        cout<<"Song title = "<<here->song_title<<" & ID = "<<here->id<<endl;
        return;
    }
    search_song(head->next,id);
    }
    void delete_playlist(Node* &head, Node* prev)
    { //recursive
    // your implementation here
         if (head == NULL) 
           return; 
         delete_playlist(head->next,head);  
         delete head;

         return;
    }

};



int main()
{
    //create your object and any other variables here
     playlist P;
     int len=0;

     string songtitle, second_song,s_song;
     int id,ch,song_id;
     Node* linklist;
     Node* last;
     last=NULL;
     linklist = NULL;
    int choice;

    do
    {
        cout<<endl;
        cout << "Welcome to your Playlist!" << endl
        << "0. Exit" << endl  //selecting this should terminate the program
        << "1. Insert a song at the end" << endl
        << "2. Insert a song after a specified song" << endl
        << "3. Delete a song from the playlist" << endl
        << "4. Display Playlist" << endl
        << "5. Find minimum id song of playlist" << endl
        << "6. Find length of Playlist" << endl
        << "7. Search for a song" << endl
        << "8. Delete Playlist" << endl
        << "Choice: ";
        cin >> choice;
        cout<<endl;

        if(choice == 1)
        {

            cout<<" Kindly enter song title "<<endl;
            
            cin>>songtitle;
            cout<<" Enter its id "<<endl;
            cin>>id;
            cout<<endl;
            P.insert_song(linklist, songtitle, id);
        }
        else if(choice==2)
        {
            cout<<"kindly enter song title "<<endl; 
            cin>>songtitle;
            cout<<"Enter its id "<<endl;
            cin>>id;
            cout<<"Enter song sfter which you want it : "<<endl;
            cin>>second_song;
            cout<<endl;
            P.insert_song_after(linklist, songtitle, id, second_song);
        }
        else if(choice==3)
        {
            cout<<endl;
             P.delete_song(linklist,last);
        }
        else if(choice==4)
        {
            cout<<endl;
            P.display_playlist(linklist);
            cout<<"\n\n";
        }
        else if(choice==5)
        {
            cout<<endl;
            cout<<"Enter length of play list: "<<endl;
            cin>>len;

            cout<<endl;
           cout<<"The minimum id is "<< P.find_min(linklist,len)<<endl;
        }
        else if(choice==6)
        {
            cout<<endl;
            cout<<"Size of the Playlist : "<<P.playlist_size(linklist)<<endl;

        }
        else if(choice==7)
        {
            cout<<endl;
            cout<<"To use song title press 1 & to use id press 2 "<<endl;
            cin>>ch;
            if(ch==1)
            {
            cout<<endl;
            cout<<"Enter a song that you want to search using song title "<<endl;
            cin>>s_song;
            cout<<endl;
            P.search_song(linklist,s_song);
            }
            else if(ch==2)
            {
                cout<<endl;
                cout<<"Enter a song that you want to search using id "<<endl;
                cin>>song_id;
                cout<<endl;
                P.search_song(linklist,song_id);
            }

        }
        else if(choice==8)
        {
            cout<<endl;
            P.delete_playlist(linklist, last);
            linklist=NULL;
            cout<<"Emptied Playlist "<<endl;
        }       

    }while(choice!=0);


        //do the rest here
        

    return 0;
}
