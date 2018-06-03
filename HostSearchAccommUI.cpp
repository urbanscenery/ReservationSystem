
#include "HostSearchAccommUI.h"


HostSearchAccommUI::HostSearchAccommUI()
{
}


HostSearchAccommUI::~HostSearchAccommUI()
{
}

void HostSearchAccommUI::searchAccomms(Member** currentUser, FILE* in_fp, FILE* out_fp, AccommManager* accommManager, AccommList *allAccommList)
{
	AccommList* hostAccommList;
	char userID[MAX_STRING];
	strcpy(userID, (*currentUser)->getUserID());
	hostAccommList = accommManager->getAccommLists(userID, 0, 1, allAccommList);

	fprintf(out_fp, "3.2. 등록 숙소 조회\n");
	Accomm* accomm = hostAccommList -> getHead();
	for (int i = 0, max = hostAccommList->getCount(); i < max; i++) {
		fprintf(out_fp, "> %s %s %d %d\n", accomm -> getID(), accomm -> getCity(), accomm -> getPrice(), accomm -> getDate() );
		accomm = accomm -> getNext();
	}
	fprintf(out_fp, "\n");
}
