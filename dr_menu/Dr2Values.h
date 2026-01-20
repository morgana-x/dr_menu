namespace DrLib
{
	namespace Dr2
	{
		namespace Values
		{
			namespace Audio
			{
				unsigned short* CurrentSong = (unsigned short*)(baseAddr + 0x3b5542);
			}
			namespace Map
			{
				int* CurrentMap = (int*)(baseAddr + 0x3a6580);
			}
			namespace Player
			{
				int* Level = (int*)(baseAddr + 0x3862b8);
			}
		}
	}
}