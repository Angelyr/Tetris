
class Tetris
{

	public:
		//Constructor
		Tetris(int w);

		//Fuctions
		void add_piece(char shape, int rotation, int start);
		int remove_full_rows();
		void destroy();
		void add_left_column();
		void add_right_column();
		void remove_left_column();
		void remove_right_column();

		//Accessors
		int get_width() const {return width;};
		int get_max_height() const;
		int count_squares() const;
		void print() const;

	private:
		int width;
		int* heights;
		char** data;
		void add_o(int rotation , int start);
		void add_i(int rotation , int start);
		void add_t(int rotation , int start);
		void add_z(int rotation , int start);
		void add_s(int rotation , int start);
		void add_l(int rotation , int start);
		void add_j(int rotation , int start);
		int resize(int start, int length, int height);
};