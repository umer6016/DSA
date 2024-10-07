#include<iostream>
#include<string>

using namespace std;


struct Packet {

 int msg_number;
 int packet_number;
 char data;
 Packet* next;
};

class PacketList{
   private:
   Packet *head,*tail;
   int msg_counter;

   public:
   PacketList(){
      head=NULL;
      msg_counter = 0;
   }

   void decomposeMessage(string message){
      msg_counter++;
      int packet_counter = 0;

      for(char ch:message){
         packet_counter++;

         Packet *new_pack = new Packet;
         new_pack -> msg_number = msg_counter;
         new_pack -> packet_number = packet_counter;
         new_pack -> data = ch;
         new_pack -> next = NULL;

         if(head==NULL){
            head=new_pack;
         }
         else{
            Packet *temp = head; 
           while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new_pack;
         }
      }
   }

   void display_list(){
      Packet *temp = head;
      while(temp!=NULL){
         cout<<"The value of packet "<<temp->packet_number<<" in message "<<temp->msg_number<<" is "<<temp->data<<endl;
         temp = temp->next;
      }
   }

};   

int main() 
{
 PacketList p;
 string message1 = "Hello";
 string message2 = "This";
 string message3 = "is";
 string message4 = "CS221";
 string message5 = "Assignment";
 p.decomposeMessage(message1);
 p.decomposeMessage(message2);
 p.decomposeMessage(message3);
 p.decomposeMessage(message4);
 p.decomposeMessage(message5);
 // Display all packets
 cout << "Displaying all packets" <<endl;
 p.display_list();
 return 0;
}
