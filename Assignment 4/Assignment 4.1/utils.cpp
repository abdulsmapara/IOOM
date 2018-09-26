#include "utils.hpp"

//CSE,ECE,MEC,ARC,CME,MET,EEE,MIN
std::string i_to_dept(Department dept)
{
	std::string retval="CSE";
	switch(dept)
	{
		case CSE:
				;
				break;
		case ECE:
				retval = "ECE";
				break;
		case MEC:
				retval = "MEC";
				break;
		case ARC:
				retval = "ARC";
				break;
		case CME:
				retval = "CME";
				break;
		case MET:
				retval = "MET";
				break;
		case EEE:
				retval = "EEE";
				break;
		case MIN:
				retval = "MIN";
				break;
		default:
				retval = "ILL";//illegal
				break;
	}
	return retval;
}
void display_dept()
{
	std::cout << "0] CSE \n1] ECE\n2] MEC\n3] ARC\n4] CME\n5] MET\n6] EEE\n7] MIN\n";
}
void assign_dept(Department& dept,int val)
{
	if(val < MIN_DEPARTMENT_ALLOWED or val > MAX_DEPARTMENT_ALLOWED){
		throw "Illegal Values Exception";
	}else{
		switch(val)
		{
			case 0:
					dept = CSE;
					break;
			case 1:
					dept = ECE;
					break;
			case 2:
					dept = MEC;
					break;
			case 3:
					dept = ARC;
					break;
			case 4:
					dept = CME;
					break;
			case 5:
					dept = MET;
					break;
			case 6:
					dept = EEE;
					break;
			case 7:
					dept = MIN;
					break;
			default:
				throw "Illegal Values Exception";
				break;
		}
	
	}
}
std::string i_to_type(Type type)
{
	std::string retval = "MINI_PROJECT";
	switch(type)
		{
			case MINI_PROJECT:
				;
				break;
			case INTERNSHIP_PROJECT:
				retval = "INTERNSHIP_PROJECT";
				break;
			case GOVT_PROJECT:
				retval = "GOVT_PROJECT";
				break;
			case FUNDED_PROJECT:
				retval ="FUNDED_PROJECT";
				break;
			default:
				throw "Illegal Values Exception";
				break;
		}
		return retval;
}
void display_types(){
	std::cout << "0] MINI_PROJECT\n1] INTERNSHIP_PROJECT\n2] GOVT_PROJECT\n3] FUNDED_PROJECT\n";
}
void assign_type(Type& type,int val)
{
	//enum Type{MINI_PROJECT,INTERNSHIP_PROJECT,GOVT_PROJECT,FUNDED_PROJECT,NONE};
	if(val < MIN_TYPE_ALLOWED or val > MAX_TYPE_ALLOWED){
		throw "Illegal Values Exception";
	}else{
		switch(val)
		{
			case 0:
				type = MINI_PROJECT;
				break;
			case 1:
				type = INTERNSHIP_PROJECT;
				break;
			case 2:
				type = GOVT_PROJECT;
				break;
			case 3:
				type =FUNDED_PROJECT;
				break;
			default:
				throw "Illegal Values Exception";
				break;
		}
	}
}