
class Coding{

public:
	/* For any character c, encode(c) is a character different from c */
	static unsigned char encode(unsigned char c){
		return c + 'a';
	};

	/* For any character c, decode(encode(c)) == c */
	static unsigned char decode(unsigned char c){
		return c + 'a';
	}

}


int main(int argc, char* argv[]){
	String inFile = "";
}