#ifndef ServerGroup_H
#define ServerGroup_H

class ServerGroup
{
  private:
  int* servers = new int[size];  //pointer
  int spServer;   //Special purpose server
  int freeServer;
  int size; //for number of elements in dynamic array
  
  public:
  ServerGroup (int); //pass in an integer
  bool spServerFree (ServerGroup );
  bool serverFree (int );
  int useServer (int );
  int decServers();

};

#endif