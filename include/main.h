#define MAX_STRING 32
#include <cstring>

using namespace std;

class Session
{
private:
	char userID[32];
public:
	Session(char *uID){
		strcpy(userID, uID);
	};
	~Session(){};
	char* getUserID();
};