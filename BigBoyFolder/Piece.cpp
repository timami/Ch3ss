//GAMEBOARD
class Piece {
	protected:
		int type;				//Queen, King, etc.
		int move[2];			//Location
		int position[2];		//Position in 2D Array Gameboard
		int sprite;				//Image file link
		bool white;				//black or white
		bool dead;				//on board or not

	public:
		void move();			//inteact with 2D array, check legal move
		void parseMove();		//Changes from A1 to 00 and H8 to 77, put into move()
		bool taken();			//determines if piece is taken, mutates bool dead

	void parseMove(string position){		//desired move format = A1 <= desiredMove <= H8
		
		bool invalidString = true;
		if(position.size() == 2){
			if((position.at(0) >= 65 && position.at(0) <= 72) || 
				(position.at(0) >= 97 && position.at(0) <= 104)){
				if(position.at(1) >= 49 && position.at(1) <= 56){
					invalidString = false;
					char x = toupper(position.at(0));
					move[0] = static_cast<int>(x) - 65;
					move[1] = position.at(1) - '0' - 1;
					move();
				}
			}
		}
		if(!invalidString){
			cout << "You suck. Think about it";
		}

		
	}

	int[] getPosition(){
		return position;
	}

	void died(){
		dead = true;
	}

};

class Pawn : public Piece{
	private:
		bool firstMoved;

	public:
		void transformer();

	Pawn(bool firstMove) : Piece (int color, bool white, int positionX, int positionY){
		this->type = 0 //Pawn
		this->move[0] = 0;
		this->move[1] = 0;
		this->position[0] = positionX;	//X Location
		this->position[1] = positionY;	//Y location
		this->sprite = "PawnPics";	//Ask Darien
		this->white = white;
		this->dead = false;

		this->firstMoved = true;
	}

	void move(){

		int val1 = -1;
		int val2 = -2;
		
		if(white){
			val1 = abs(val1);
			val2 = abs(val2);
		}
		if(firstMoved && move[1] - position[1] == val2 && position[0] == move[0]){
			firstMoved = false;
			//check collision() to check if it can move there
			//if(collision()){
			position[0] = moved[0];
			position[1] = moved[1];
			//}
		}
		else if(move[1] - position[1] == val1 && position[0] == move[0]){
			firstMoved = false;
			//we can move dat
			//if(collision()){
			position[0] = moved[0];
			position[1] = moved[1];
			//}
		}
		else if(move[1] - position[1] == val1 && abs(move[1] - position[1]) == 1){
			if(collision()){
				firstMoved = false;
				kill(move);
				position[0] = moved[0];
				position[1] = moved[1];
			}
		}

		int end = 0;			//set end location for black
		if(white) end = 7;		//set end location for white
		if(position[1] == end) transformMethod();

		//put en passat VW in here
		else cout<<"Brahhhhhhhhhhh you can't move dat";

		collisionDetect();
	} 

	int getType(){
		return type;
	}

	void transformMethod(){
		bool chosen = false;
		while (!chosen){
			string option;
			cout << "Who do you want to be: \n Queen, Weenie, Rook, Bishop, Knight, King Weenie!";
			cin >> option;

			string lowerOption = "";
			for(unsigned i = 0; i < option.size(); i++){
				lowerOption += tolower(option.at(i));
			}
			
			if(lowerOption.compare("queen") == 0){
				chosen = true;
				//create a new queen with location = position
			}
			else if(lowerOption.compare("rook") == 0){
				chosen = true;
				//create a new rook with location = position
			}
			else if(lowerOption.compare("bishop") == 0){
				chosen = true;
				//create a new bishop with location = position
			}
			else if(lowerOption.compare("knight") == 0){
				chosen = true;
				//create a new knight with location = position
			}
			else if(lowerOption.compare("king weenie") == 0){
				cout << "ALL HAIL KING WEENIE!!!!!!! but seriously..." << endl;
			}
			else if(lowerOption.compare("weenie") == 0){
				cout << "Oh. Choose another... weenie" << endl;
			}
			else cout << "Sorry. That is not an option. Please choose again" << endl;
		}
	}

};


pawn1.parseMove("A1");