#pragma once

enum ProtocolList
{
	//ACK,REQ�� �ִ°��� ������ ������ �޴� �����̰� �ȴ޸��͵��� �� ����...

	//���� �����ΰ�...
	//�̰� ���ӿ� ���Ѱ�...
	CONNECT_ACK,	CONNECT_REQ,
	DISCONNECT_ACK, DISCONNECT_REQ,

	
	//���ӳ����ΰ�...
	//CLIENT TO SERVER
	MOVE,
	SHOT_ACK,SHOT_REQ,
	LIVE_ACK,LIVE_REQ,

	//SERVER TO CLIENT
	INFORMATION,EVENT
};


