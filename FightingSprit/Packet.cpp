#include "Packet.h"
#include <windows.h>

Packet::Packet()
: m_pDataField( 0 ), m_pReadPosition( 0 ), m_pWritePosition( 0 ), m_iReceivedSize( 0 ) 
{
	clear();
	ID(-1);
}

Packet::Packet( unsigned short ProtocolID, unsigned int id)
: m_pDataField( 0 ), m_pReadPosition( 0 ), m_pWritePosition( 0 ), m_iReceivedSize( 0 )
{
	clear();
	Protocolid( ProtocolID );
	ID(id);
}

Packet::Packet( const Packet& source )
: m_pDataField( 0 ), m_pReadPosition( 0 ), m_pWritePosition( 0 ),
m_iReceivedSize( 0 )
{
	clear();

	CopyMemory( m_PacketBuffer, source.m_PacketBuffer, PACKETBUFFERSIZE );

	m_iReceivedSize = source.m_iReceivedSize;


	DWORD offset;

	offset = ( DWORD )source.m_pReadPosition - ( DWORD )source.m_pDataField;
	m_pReadPosition += offset;

	offset = ( DWORD )source.m_pWritePosition - ( DWORD )source.m_pDataField;
	m_pWritePosition += offset;
}

Packet::~Packet()
{
}

bool Packet::isValidHeader()
{
	return ( getPacketSize() >= PACKETHEADERSIZE );
}

bool Packet::isValidPacket()
{
	if( isValidHeader() == false )
		return false;

	return ( getPacketSize() <= m_iReceivedSize );
}

void Packet::clear()
{
	ZeroMemory( m_PacketBuffer, PACKETBUFFERSIZE );

	packetHeader.dataSize	= ( unsigned short* )m_PacketBuffer + 0;					//  packetSize size = 2
	packetHeader.protocolID = ( unsigned short* )( ( char* )m_PacketBuffer + 4 );		//  protocolID size	= 2
	packetHeader.ID			= ( unsigned int* )( ( char* )m_PacketBuffer + 8 );

	m_pDataField      = &m_PacketBuffer[12];
	m_pReadPosition   = m_pWritePosition = m_pDataField;
	m_pEndOfDataField = &m_pDataField[PACKETBUFFERSIZE - 1];

	Protocolid( 0 );
	ID(-1);

	m_iReceivedSize = 0;
}

Packet& Packet::Protocolid( unsigned short ID )
{
	*packetHeader.protocolID = ID;

	return *this;
}

unsigned short Packet::Protocolid()
{
	return *packetHeader.protocolID;
}

unsigned short Packet::getDataFieldSize()
{
	return *packetHeader.dataSize;
}

void Packet::copyToBuffer( char* buff, int size )
{
	clear();
	CopyMemory( m_PacketBuffer, buff, size );
	m_iReceivedSize += size;
}

void Packet::readData( void* buffer, int size )
{
	if( m_pReadPosition + size > m_pDataField + getDataFieldSize() || m_pReadPosition + size > m_pEndOfDataField )
		return;

	CopyMemory( buffer, m_pReadPosition, size );
	m_pReadPosition += size;
}

void Packet::writeData( void* buffer, int size )
{
	if( m_pWritePosition + size > m_pEndOfDataField )
		return;

	CopyMemory( m_pWritePosition, buffer, size );
	m_pWritePosition += size;
	m_iReceivedSize += size;

	*packetHeader.dataSize += size;
}
void Packet::ID(unsigned int id)
{
	*packetHeader.ID = id;
}
unsigned int Packet::ID()
{
	return *packetHeader.ID;
}

////////////////////////////////////////////////////////////////////////////
//  Operators

Packet& Packet::operator = ( Packet& packet )
{
	CopyMemory( m_pDataField, packet.m_pDataField, packet.getDataFieldSize() );

	*packetHeader.protocolID = packet.Protocolid();
	*packetHeader.dataSize   = packet.getDataFieldSize();
	*packetHeader.ID		 = packet.ID();


	return *this;
}

Packet&	Packet::operator << ( char* arg )
{
	writeData( arg, strlen( arg ) * sizeof( char ) + sizeof( char) );

	return *this;
}


Packet&	Packet::operator >> ( char*	 arg )
{
	readData( arg, strlen( ( char* )m_pReadPosition ) * sizeof( char ) + sizeof( char ) );

	return *this;
}
//////////////ø‰¡Í////////////////
// Packet& Packet::operator << ( Packet& arg )
// {
// //	unsigned int idValue = arg.id();
// 	unsigned int size = arg.getDataFieldSize();
// 
// 	writeData( &idValue, sizeof( unsigned int ) );
// 	writeData( &size, sizeof( unsigned int ) );
// 	writeData( arg.m_pDataField, size );
// 
// 	return *this;
// }
// 
// Packet& Packet::operator >> ( Packet& arg )
// {
// 	int idValue, size;
// 	char buffer[PACKETBUFFERSIZE];
// 
// 	readData( &idValue, sizeof( int ) );
// 	readData( &size, sizeof( int ) );
// 
// 	readData( buffer, size );
// 
// 	//arg.id( idValue );
// 	arg.writeData( buffer, size );
// 
// 	return *this;
// }
//////////////ø‰¡Í////////////////
Packet& Packet::operator << ( bool arg )
{
	writeData( &arg, sizeof( bool ) );

	return *this;
}

Packet& Packet::operator >> ( bool& arg )
{
	readData( &arg, sizeof( bool ) );

	return *this;
}


Packet& Packet::operator << ( int arg )
{
	writeData( &arg, sizeof( int ) );

	return *this;
}

Packet& Packet::operator >> ( int& arg )
{
	readData( &arg, sizeof( int ) );

	return *this;
}
Packet& Packet::operator << ( float arg)
{
	writeData( &arg, sizeof(float));

	return *this;
}
Packet&	Packet::operator >> ( float& arg )
{
	readData(&arg,sizeof(float));

	return *this;
}
Packet& Packet::operator << ( long arg )
{
	writeData( &arg, sizeof( long ) );

	return *this;
}

Packet& Packet::operator >> ( long& arg )
{
	readData( &arg, sizeof( long ) );

	return *this;
}

Packet& Packet::operator << ( DWORD arg )
{
	writeData( &arg, sizeof( DWORD ) );

	return *this;
}

Packet& Packet::operator >> ( DWORD& arg )
{
	readData( &arg, sizeof( DWORD ) );

	return *this;
}

Packet& Packet::operator << ( __int64 arg )
{
	writeData( &arg, sizeof( __int64 ) );

	return *this;
}

Packet& Packet::operator >> ( __int64& arg )
{
	readData( &arg, sizeof( __int64 ) );

	return* this;
}

