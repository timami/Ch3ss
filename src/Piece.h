class Piece {
	protected:
		int type;				//Queen, King, etc.
		int move[2];			//Location
		int position[2];		//Position in 2D Array Gameboard
		int sprite;				//Image file link
		bool white;				//black or white
		bool dead;				//on board or not

	public:
		void parseMove(string position);		//Changes from A1 to 00 and H8 to 77, put into move()
		int[] getPosition();					//inteact with 2D array, check legal move
		void died();							//determines if piece is taken, mutates bool dead
}