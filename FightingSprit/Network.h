#pragma once

//#include <Windows.h>

#include <WinSock2.h>
#include <process.h>
#pragma comment(lib,"ws2_32.lib")




#define		FIGHTING_SPRIT_PORT		8599



/*
네트워크...
인터페이스...

서버가 가진 정보 = 클라가 가진정보 둘다있는 정보들

다른 사람의 ID 이름 및 IP주소...
킬, 데스?
포지션 및 보는 방향..
쐈다-> 쏜흔적? 및 쳐맞으면(이건 서버에서 ㅊㅓ리)대미지 감쇠..



클라이언트
메시지 받기		- 메시지큐에 패킷을 쳐넣어둠 하나의 명령단위...
메시지 보내기	- 그냥 패킷 생성해서 하나의 명령을 넣어서 보냄...

서버
메시지 받기		- 일단 받은 메시지를 처리한후.. 모두에게 다시 뿌려줌..
메시지 보내기	- 위와같음.. 모두에게 뿌림.. 필요한것을(유닛이동, 충돌체크등)


프로토콜
(얘는 결국 모든 명령 통제 클래스)
접속했냐 안했냐 등...이건 나중에 생각하자..


위에 모든것을 위한 설계가 필요해...

1. 서버 및 클라에서 패킷을 주고 받아야 한다..
   - 같은 인터페이스에 다른 구현을 붙여서 사용한다...

2. 서버 및 클라는 여러가지 정보를 가지고 있어야 한다.
	- 정보를 가지고 있는 USER클래스를 토대로 모든 서버 및 클라이언트는 정보를 가진다.

3. 서버에서 클라의 정보를 토대로 계산해낸다... 클라는-> 자기자신한테 패킷을 보냄..
   (어떤 클라이언트던 같은방식 대신 방장이냐 아니냐라는 STATUS를 가짐..(ME, YOU, bangjang)
   (쓰레드에서 클라이언트 메모리에 접근해야함...(크리티컬 섹션......;;;필요한가?)
   - USER에 STATUS표시를 두고.. 사용 , IOCP 관리 클래스에서 IRRLICHT 기본을 가져간다.

4. 패킷은 하나는 기본패킷(케릭포지션 뭐뭐뭐뭐뭐 명령도 포함... 포함한 기본 패킷)
   접속에 관한 패킷을 가진다.
	- 명령에 관한 패킷생산(커맨드패턴?), 서로간에 주고 받는 기본패킷에 대한 클래스 제작..

5. 쓰레드 관리 및 IOCP관리 클래스 필요...(세션에 관한 클래스 필요 없음 어짜피 한개니까..TCP도 아니고..)
	- 옆에꺼와 비슷하게 하면댐..

6. 기타 네트워크 오류에 관한 문제는 재낀다...(난 몰라)
	- 그나마 EXCEPTION클래스 사용 THROW나 LOG를 남겨서 정리한다.(서버만..)

7. 네트워크가 클라이언트데이터에 접근하기 위한 자료구조 모음...
*/