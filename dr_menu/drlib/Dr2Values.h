namespace DrLib
{
	namespace Dr2
	{
		namespace Values
		{
			namespace Audio
			{
				inline extern unsigned short* CurrentSong = (unsigned short*)(baseAddr + 0x3b5542);
			}
			namespace Map
			{
				inline extern int* CurrentMap = (int*)(baseAddr + 0x3a6580);
			}
			namespace Player
			{
				inline extern int* Level = (int*)(baseAddr + 0x3862b8);
			}
			namespace Collectables
			{
				inline extern unsigned short* Monocoins = (unsigned short*)(baseAddr + 0x38a042);
			}
		}
	}
}