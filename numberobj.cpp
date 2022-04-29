#include "numberobj.h"
void numberobj::output(){
}
ostream& operator<<(ostream& os, numberobj* ptr){
	ptr->output();
	return os;
}