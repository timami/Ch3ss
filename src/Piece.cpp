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

};

class Pawn : public Piece{
	private:
		bool firstMoved;

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


};


pawn1.parseMove("A1");