#include "tetris.h"
#include <iostream>

Tetris::Tetris(int w)
{
	width=w;
	heights = new int[width];
	data = new char*[width];
	//sets the heights to 0
	for(int i=0; i < width; i++)
	{
		heights[i]=0;
		data[i]=new char[1];

		for(int j=0; j < 1; j++)
		{
			data[i][j]=' ';
		}
	}

}
void Tetris::add_piece(char shape, int rotation, int start)
{
	//reads the shape and sends it to different helper fuctions.
	if(shape == 'O')
	{
		add_o(rotation, start);
	}
	if(shape == 'I')
	{
		add_i(rotation, start);
	}
	if(shape == 'T')
	{
		add_t(rotation, start);
	}
	if(shape == 'Z')
	{
		add_z(rotation, start);
	}
	if(shape == 'S')
	{
		add_s(rotation, start);
	}
	if(shape == 'L')
	{
		add_l(rotation, start);
	}
	if(shape == 'J')
	{
		add_j(rotation, start);
	}
}
void Tetris::add_o(int rotation, int start)
{
	//makes data larger and places old pieces into it
	int temp_height=resize(start, 2, 2);
	//places new piece into data and increases heights
	data[start][temp_height]='O';
	data[start][temp_height+1]='O';
	data[start+1][temp_height]='O';
	data[start+1][temp_height+1]='O';
	heights[start]=temp_height+2;
	heights[start+1]=temp_height+2;
}
void Tetris::add_i(int rotation , int start)
{
	if(rotation == 0 || rotation == 180)
	{
		//makes data larger and places old pieces into it
		resize(start, 1, 4);
		//places new piece into data and increases heights
		data[start][heights[start]]= 'I';
		data[start][heights[start]+1]= 'I';
		data[start][heights[start]+2]= 'I';
		data[start][heights[start]+3]= 'I';
		heights[start]+=4; 
	}
	if(rotation == 90 || rotation== 270)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 4, 1);
		//places new piece into data and increases heights
		data[start][temp_height]='I';
		data[start+1][temp_height]='I';
		data[start+2][temp_height]='I';
		data[start+3][temp_height]='I';
		heights[start]=temp_height+1;
		heights[start+1]=temp_height+1;
		heights[start+2]=temp_height+1;
		heights[start+3]=temp_height+1;
	}
}
void Tetris::add_t(int rotation , int start)
{
	if(rotation == 0)
	{
		//makes data larger and places old pieces into it
		int check=resize(start+1, 1,1);
		int temp_height=resize(start, 3, 2);
		//places new piece into data and increases heights
		//the if statement checks to see if its being put on
		//even ground
		if(temp_height<=check){
			data[start][temp_height+1]='T';
			data[start+1][temp_height]='T';
			data[start+1][temp_height+1]='T';
			data[start+2][temp_height+1]='T';
			heights[start]=temp_height+2;
			heights[start+1]=temp_height+2;
			heights[start+2]=temp_height+2;}
		else{
			data[start][temp_height]='T';
			data[start+1][temp_height-1]='T';
			data[start+1][temp_height]='T';
			data[start+2][temp_height]='T';
			heights[start]=temp_height+1;
			heights[start+1]=temp_height+2;
			heights[start+2]=temp_height+1;}
	}
	if(rotation == 90)
	{
		//makes data larger and places old pieces into it
		int check=resize(start+1, 1,1);
		int temp_height=resize(start, 2 , 3);
		//places new piece into data and increases heights
		//the if statement checks to see if its being put on
		//even ground
		if(temp_height<=check){
			data[start][temp_height+1]='T';
			data[start+1][temp_height]='T';
			data[start+1][temp_height+1]='T';
			data[start+1][temp_height+2]='T';
			heights[start]=temp_height+2;
			heights[start+1]=temp_height+3;}
		else{
			data[start][temp_height]='T';
			data[start+1][temp_height-1]='T';
			data[start+1][temp_height]='T';
			data[start+1][temp_height+1]='T';
			heights[start]=temp_height+1;
			heights[start+1]=temp_height+3;}
	}
	if(rotation == 180)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 3 , 2);
		//places new piece into data and increases heights
		data[start][temp_height]='T';
		data[start+1][temp_height]='T';
		data[start+1][temp_height+1]='T';
		data[start+2][temp_height]='T';
		heights[start]=temp_height+1;
		heights[start+1]=temp_height+2;
		heights[start+2]=temp_height+1;
	}
	if(rotation == 270)
	{
		//makes data larger and places old pieces into it
		int check=resize(start,1,1);
		int temp_height=resize(start, 2 , 3);
		//places new piece into data and increases heights
		if(temp_height >= check){
			data[start][temp_height]='T';
			data[start][temp_height+1]='T';
			data[start][temp_height+2]='T';
			data[start+1][temp_height+1]='T';
			heights[start]=temp_height+3;
			heights[start+1]=temp_height+2;}
		else{
			data[start][temp_height-1]='T';
			data[start][temp_height]='T';
			data[start][temp_height+1]='T';
			data[start+1][temp_height]='T';
			heights[start]=temp_height+3;
			heights[start+1]=temp_height+1;}
	}
}
void Tetris::add_z(int rotation , int start)
{
	if(rotation == 0 || rotation == 180)
	{
		//makes data larger and places old pieces into it
		int check=resize(start+1,2,1);
		int temp_height=resize(start, 3 , 2);
		//places new piece into data and increases heights
		if(temp_height <= check){
			data[start][temp_height+1]='Z';
			data[start+1][temp_height]='Z';
			data[start+1][temp_height+1]='Z';
			data[start+2][temp_height]='Z';
			heights[start]=temp_height+2;
			heights[start+1]=temp_height+2;
			heights[start+2]=temp_height+1;
		}
		else{
			data[start][temp_height]='Z';
			data[start+1][temp_height-1]='Z';
			data[start+1][temp_height]='Z';
			data[start+2][temp_height-1]='Z';
			heights[start]=temp_height+1;
			heights[start+1]=temp_height+2;
			heights[start+2]=temp_height+1;
		}
	}
	if(rotation == 90 || rotation == 270)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 2 , 3);
		//places new piece into data and increases heights
		data[start][heights[start]]='Z';
		data[start][heights[start]+1]='Z';
		data[start+1][heights[start]+1]='Z';
		data[start+1][heights[start]+2]='Z';
		heights[start]=heights[start]+2;
		heights[start+1]=heights[start]+1;
	}
}
void Tetris::add_s(int rotation , int start)
{
	if(rotation == 0 || rotation == 180)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 3 , 2);
		//places new piece into data and increases heights
		data[start][temp_height]='S';
		data[start+1][temp_height]='S';
		data[start+1][temp_height+1]='S';
		data[start+2][temp_height+1]='S';
		heights[start]=temp_height+1;
		heights[start+1]=temp_height+2;
		heights[start+2]=temp_height+2;
	}
	if(rotation == 90 || rotation == 270)
	{
		//makes data larger and places old pieces into it
		resize(start, 2 , 3);
		//places new piece into data and increases heights
		data[start][heights[start+1]+1]='S';
		data[start][heights[start+1]+2]='S';
		data[start+1][heights[start+1]]='S';
		data[start+1][heights[start+1]+1]='S';
		heights[start]=heights[start+1]+3;
		heights[start+1]=heights[start+1]+2;
	}
}
void Tetris::add_l(int rotation , int start)
{
	if(rotation == 0)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 2, 4);
		//places new piece into data and increases heights
		data[start][temp_height]='L';
		data[start][temp_height+1]='L';
		data[start][temp_height+2]='L';
		data[start+1][temp_height]='L';
		heights[start]=temp_height+3;
		heights[start+1]=temp_height+1;
	}
	if(rotation == 90)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 3 , 2);
		//places new piece into data and increases heights
		data[start][temp_height]='L';
		data[start][temp_height+1]='L';
		data[start+1][temp_height+1]='L';
		data[start+2][temp_height+1]='L';
		heights[start]=temp_height+2;
		heights[start+1]=temp_height+2;
		heights[start+2]=temp_height+2;
	}
	if(rotation == 180)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 2 , 3);
		//places new piece into data and increases heights
		data[start][temp_height+2]='L';
		data[start+1][temp_height]='L';
		data[start+1][temp_height+1]='L';
		data[start+1][temp_height+2]='L';
		heights[start]=temp_height+3;
		heights[start+1]=temp_height+3;
	}
	if(rotation == 270)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 3 , 2);
		//places new piece into data and increases heights
		data[start][temp_height]='L';
		data[start+1][temp_height]='L';
		data[start+2][temp_height]='L';
		data[start+2][temp_height+1]='L';
		heights[start]=temp_height+1;
		heights[start+1]=temp_height+1;
		heights[start+2]=temp_height+2;
	}
}
void Tetris::add_j(int rotation , int start)
{
	if(rotation == 0)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 2, 4);
		//places new piece into data and increases heights
		data[start][temp_height]='J';
		data[start+1][temp_height]='J';
		data[start+1][temp_height+1]='J';
		data[start+1][temp_height+2]='J';
		heights[start]=temp_height+1;
		heights[start+1]=temp_height+3;
	}
	if(rotation == 90)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 3 , 2);
		//places new piece into data and increases heights
		data[start][temp_height]='J';
		data[start][temp_height+1]='J';
		data[start+1][temp_height]='J';
		data[start+2][temp_height]='J';
		heights[start]=temp_height+2;
		heights[start+1]=temp_height+1;
		heights[start+2]=temp_height+1;
	}
	if(rotation == 180)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 2 , 3);
		//places new piece into data and increases heights
		data[start][temp_height]='J';
		data[start][temp_height+1]='J';
		data[start][temp_height+2]='J';
		data[start+1][temp_height+2]='J';
		heights[start]=temp_height+3;
		heights[start+1]=temp_height+3;
	}
	if(rotation == 270)
	{
		//makes data larger and places old pieces into it
		int temp_height=resize(start, 3 , 2);
		//places new piece into data and increases heights
		data[start][temp_height+1]='J';
		data[start+1][temp_height+1]='J';
		data[start+2][temp_height]='J';
		data[start+2][temp_height+1]='J';
		heights[start]=temp_height+2;
		heights[start+1]=temp_height+2;
		heights[start+2]=temp_height+2;
	}
}
//puts old data into a bigger temporary array, then deletes the old data, 
//and points data to new temp array.
int Tetris::resize(int start, int length, int height)
{
	int temp_height=heights[start];
	//gets height the piece is going to be at 
	for(int i=start; i < start+length; i++)
		if(heights[i] > temp_height)
			temp_height=heights[i];
	//makes data big enough to fit new piece
	for(int i=start; i < start+length; i++)
	{
		char *temp = new char[temp_height+height];
		for(int j=0; j < temp_height+height; j++)
		{
			if( j < heights[i])
				temp[j]=data[i][j];
			else
				temp[j]=' ';
		}
		delete[] data[i];
		data[i] = temp;
	}
	return temp_height;
}
void Tetris::add_left_column()
{
	width++;
	char** temp=data;
	int* temp_height=heights;
	data = new char*[width];
	heights = new int[width];
	data[0] = new char[1];
	heights[0] = 0;

	for(int i=1; i < width; i++)
	{
		heights[i]=temp_height[i-1];
		data[i]=temp[i-1];
	}
	delete[] temp;
	delete[] temp_height;
}
void Tetris::add_right_column()
{
	width++;
	char** temp=data;
	int* temp_height=heights;
	data = new char*[width];
	heights = new int[width];
	data[width-1] = new char[1];
	heights[width-1] = 0;

	for(int i=0; i < width-1; i++)
	{
		heights[i]=temp_height[i];
		data[i]=temp[i];
	}
	delete[] temp;
	delete[] temp_height;
}
void Tetris::remove_left_column()
{
	width--;
	char** temp=data;
	int* temp_height=heights;
	data = new char*[width];
	heights = new int[width];

	for(int i=0; i < width; i++)
	{
		heights[i]=temp_height[i+1];
		data[i]=temp[i+1];
	}
	delete[] temp[0];
	delete[] temp;
	delete[] temp_height;
}
void Tetris::remove_right_column()
{
	width--;
	char** temp=data;
	int* temp_height=heights;
	data = new char*[width];
	heights = new int[width];

	for(int i=0; i < width; i++)
	{
		heights[i]=temp_height[i];
		data[i]=temp[i];
	}
	delete[] temp[width];
	delete[] temp;
	delete[] temp_height;
}
int Tetris::get_max_height() const
{
	int max=0;
	for(int i=0; i < width; i++)
	{
		if(heights[i] > max)
			max = heights[i];
	}
	return max;
}
int Tetris::count_squares() const
{
	int squares=0;
	for(int i=0; i < width; i++)
	{
		for(int j=0; j < heights[i]; j++)
		{
			if(data[i][j] != ' ')
				squares++;
		}
	}
	return squares;
}
int Tetris::remove_full_rows()
{
	int removed=0;
	int check=0;
	bool go=true;

	while(go)
	{
		int lowest_height=heights[0];
		check=0;
		//finds lowest height 
		for(int i=0; i < width; i++)
			if(heights[i] < lowest_height)
				lowest_height=heights[i];
		//looks for full rows and sets lowest_height = to a possible full row
		for(int j=0; j < lowest_height; j++)
		{
			check=0;
			for(int i=0; i < width; i++)
			{
				if(data[i][j] != ' ')
					check++;
				else break;
				if(check == width)
					lowest_height=j;
			}
		}
		check =0;
		for(int i=0; i < width; i++)
		{
			//checks to see if there are full rows left
			if(lowest_height >= heights[i])
			{	go=false;
				break;	}
			//makes sure it is a full row
			if(data[i][lowest_height] != ' ')
				check++;
			if(check == width)
			{
				removed++;
				char** temp=data;
				data=new char*[width];
				//decreases the heights and assigns new values
				for(int i=0; i < width; i++)
				{
					heights[i]--;
					data[i]=new char[heights[i]];
					for(int j=0; j < heights[i]; j++)
					{
						if(j < lowest_height)
							data[i][j]=temp[i][j];
						else
							data[i][j]=temp[i][j+1];
					}
				}
				for(int i=0; i < width; i++)
					delete[] temp[i];
				delete[] temp;
				break;
			}
		}
	}
	//fixes height that become 0
	for(int i=0; i < width; i++)
	{
		check=0;
		for(int j=0; j < heights[i]; j++)
		{
			if(data[i][j] == ' ')
				check++;
			if(check == heights[i])
				heights[i]=0;
		}
	}
	return removed;
}
void Tetris::destroy()
{
	for(int i=0; i < width; i++)
	{
		delete[] data[i];
	}

	delete[] data;
	delete[] heights;
}
