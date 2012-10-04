#pragma once

enum ProtocolList
{
	//ACK,REQ가 있는것은 서버에 인증을 받는 형식이고 안달린것들은 노 인증...

	//게임 외적인것...
	//이건 접속에 관한것...
	CONNECT_ACK,	CONNECT_REQ,
	DISCONNECT_ACK, DISCONNECT_REQ,

	
	//게임내적인것...
	//CLIENT TO SERVER
	MOVE,
	SHOT_ACK,SHOT_REQ,
	LIVE_ACK,LIVE_REQ,

	//SERVER TO CLIENT
	INFORMATION,EVENT
};


