#pragma once
#include "Glober.h"
//#include <Windows.h>


#define		PACKETBUFFERSIZE	8192
#define		PACKETHEADERSIZE	12



class Packet
{
private:
	BYTE		m_PacketBuffer[PACKETBUFFERSIZE];
	BYTE*		m_pDataField;
	BYTE*		m_pReadPosition;
	BYTE*		m_pWritePosition;
	BYTE*		m_pEndOfDataField;

	int			m_iReceivedSize;

public:
	Packet();
	Packet(unsigned short ProtocolID, unsigned int id);
	Packet( const Packet& source );
	virtual ~Packet();

	bool			isValidHeader();
	bool			isValidPacket();

	Packet&			Protocolid( unsigned short ID );
	unsigned short	Protocolid();

	void			ID(unsigned int id);
	unsigned int	ID();			

	void			clear();

	unsigned short	getDataFieldSize();
	int				getPacketSize(){ return ( getDataFieldSize() + PACKETHEADERSIZE ); }
	int				getReceivedSize(){ return m_iReceivedSize; }
	BYTE*			getPacketBuffer(){ return m_PacketBuffer; }

	void			copyToBuffer( char* buff, int size );

	void			readData( void* buffer, int size );
	void			writeData( void* buffer, int size );

	virtual void	Build() {}



	Packet&	operator = ( Packet& packet );

	Packet&	operator << ( bool arg );
	Packet&	operator << ( int arg );
	Packet&	operator << ( long arg );
	Packet&	operator << ( DWORD arg );
	Packet& operator << ( float arg);
	Packet&	operator << ( __int64 arg );
	Packet&	operator << ( char* arg );
	Packet&	operator << ( Packet& arg );

	Packet&	operator >> ( bool& arg );
	Packet&	operator >> ( int& arg );
	Packet&	operator >> ( float& arg );
	Packet&	operator >> ( long& arg );
	Packet&	operator >> ( DWORD& arg );
	Packet&	operator >> ( __int64& arg );
	Packet&	operator >> ( char*	 arg );
	Packet&	operator >> ( Packet& arg );

protected:
	typedef struct
	{
		unsigned short*		dataSize;
		unsigned short*		protocolID;
		unsigned int*		ID;
	} HEADER;

	HEADER		packetHeader;
};
