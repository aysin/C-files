#include "ServerGroup.h"

ServerGroup::ServerGroup (int num) //pass in an integer
{
  size = num;
  spServer = 0;
}

bool ServerGroup::spServerFree (ServerGroup a)
{ 
  if (spServer == 0)
    return true; return false;
}


bool ServerGroup::serverFree(int b)
{
  for(int i(0); i < size; ++i)
   {
    if(servers[i] == 0)
     {
      freeServer = i; //Now assign freeServer with the index
      return true;
     }
   }
   return false; 
}


int ServerGroup::decServers()
{
  int i(0);
  for(; i < size; ++i)
  {
    if(servers[i] != 0)
      --servers[i];
  }

  if(spServer!= 0)
    spServer -= 1;
 
  return servers[i];
}