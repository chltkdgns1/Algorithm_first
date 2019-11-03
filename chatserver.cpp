#define _WINDOCK_DEPRECATED_NO_WARINGS
#include <iostream>
#include <process.h>
#include "room.h"
#include "SOCKET.h"
#include "Notice.h"
#include "stringAlladd.h"
#include "Omok.h"
#include "OmokRank.h"
#include "BoomRoom.h"
#include <conio.h>
#include "MessageFriend.h"
using namespace std;
#define BUF_SIZE 1024
#define NUMBER 50

unsigned WINAPI sendrecvthread(void *arg);
unsigned WINAPI sortthread(void *arg);

unsigned WINAPI message_friend_thread(void *arg); // 친구 요청받음

void ErrorHandling(char *massage);
void sendmessage(char *name, char *message, int time, SOCKET sock);

string Null;
Socket *Clnt = new Socket;
HANDLE mutex;
Room *room = new Room;
Client *client = new Client;
Link *notice = new Link;
Omok *omok = new Omok;
Omok_Rank *omokrank = new Omok_Rank;
BoomRoom *boomroom = new BoomRoom;
BoomMan *boomman = new BoomMan;
BoomReturn Return_number;
MessageFriend *friend_data = new MessageFriend;

int main(int argc, char *argv[]){
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;

	HANDLE thread, sort_thread;
	int szClntAddr;

	if (argc != 2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		ErrorHandling("WSAStartup() eooror!");
	}

	mutex = CreateMutex(NULL, FALSE, NULL);
	hServSock = socket(PF_INET, SOCK_STREAM, 0);

	if (hServSock == INVALID_SOCKET){
		ErrorHandling("socket() error!");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR){
		ErrorHandling("bind() error");
	}

	if (listen(hServSock, 5) == SOCKET_ERROR){
		ErrorHandling("listen() error");
	}

	szClntAddr = sizeof(clntAddr);

	client->Read();
	notice->Read_Notice();
	omokrank->Sort_data_read();
	friend_data->ReadDirectory();
	friend_data->PrintDirectory();

	sort_thread = (HANDLE)_beginthreadex(NULL, 0, sortthread, (void*)&hClntSock, 0, NULL);
	
	while (1){
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
		if (hClntSock == INVALID_SOCKET)
			ErrorHandling("accpet() error");
		cout << "connect : " << inet_ntoa(clntAddr.sin_addr) << endl;
		Clnt->ClntSockLink(hClntSock, mutex);
		thread = (HANDLE)_beginthreadex(NULL, 0, sendrecvthread, (void*)&hClntSock, 0, NULL);
	}
	closesocket(hClntSock);
	closesocket(hServSock);
	WSACleanup();
	return 0;
}

unsigned WINAPI message_friend_thread(void *Sock){
	SOCKET sock = *((SOCKET*)Sock);
	while (1){
		friend_data->RequestFriend(sock, mutex);
	}
	return 0;
}

unsigned WINAPI sortthread(void* sock){
	int get_time = 0;
	while (1){
		if (GetTickCount() - get_time > 10000){
			omokrank->QuickSortList(omokrank->head->next, omokrank->current);
			omokrank->PrintSortSystem();
			get_time = GetTickCount();
		}
	}
	return 0;
}

void ErrorHandling(char *message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

unsigned WINAPI sendrecvthread(void *Sock){
	//string name;
	HANDLE friend_thread;
	SOCKET sock = *((SOCKET*)Sock);
	LoginUser *In_user = new LoginUser;
	HANDLE friend_message_thread;
	int delnumber = 0;
	while (1){
		string temp;
		char ch;
		if (sizeof(ch) != recv(sock, &ch, sizeof(char), 0)){
			continue;
		}
		switch (ch){
		case '1':
			while ((temp = client->Member_Create_first(sock)) == Null);
			client->Member_Create_second(sock, temp, mutex, omokrank);
			while(friend_data->WriteDirectory(temp)==false);
			break;
		case '2':
			if (client->Logins(sock, In_user, Clnt) == true){
				friend_thread = (HANDLE)_beginthreadex(NULL, 0, message_friend_thread, (void*)&sock, 0, NULL);
				while (1){
					char ch;
					if (sizeof(ch) != recv(sock, &ch, sizeof(char), 0)){
						continue;
					}
					switch (ch){
					case '1':
						while (1){
							notice->PrintNoticeList(sock);
							char ch;
							if (sizeof(ch) != recv(sock, &ch, sizeof(char), 0)){
								continue;
							}
							switch (ch){
							case '1':
								notice->Write(sock, mutex);
								break;
							case '2':
								notice->CheckTheNumber(sock);
								break;
							case '3':
								notice->DeleteWrite(sock, In_user, mutex);
								break;
							case '4': //아이디 검색
								notice->Read_ALL(sock);
								break;
							case '5'://내용 검색
								notice->Read_story(sock);
								break;
							case '6':
								break;
							case '7':
								delete(In_user);
								notice->Infor_Notice();
								client->Infor_write();
								omokrank->Sort_data_write();
								Clnt->DelSocket(sock, mutex);
								return 0;
							default:
								break;
							}
							if (ch == '6')
								break;
						}
						break;
					case '2':
						while (1){
							char ch;
							room->SendRoomList(sock);
							if (sizeof(ch) != recv(sock, &ch, sizeof(char), 0)){
								continue;
							}
							cout << "ch : " << ch << endl;
							switch (ch){
							case '1':
								int creat_room_call;
								room->RoomCreate(sock, mutex, In_user->id);
								creat_room_call = room->RoomIn(sock, mutex,In_user->id);
								while (1){
									Messagedata create_message_data;
									recv(sock, (char*)&create_message_data, sizeof(create_message_data), 0);
									Str(create_message_data.name, In_user->id.c_str());
									room->SendMessages(sock, creat_room_call, &create_message_data, mutex);

									string temp = create_message_data.message; // exit 판별
									if (temp.compare("/exit") == 0){
										break;
									}
								}
								cout << "exit" << endl;
								break;
							case '2':
								int in_room_call;
								in_room_call = room->RoomIn(sock, mutex,In_user->id);
								if (in_room_call == 0)
									break;
								while (1){
									Messagedata message_data;
									recv(sock, (char*)&message_data, sizeof(message_data), 0);
									Str(message_data.name, In_user->id.c_str());
									room->SendMessages(sock, in_room_call, &message_data, mutex);

									string temp = message_data.message; // exit 판별
									if (temp.compare("/exit") == 0){
										break;
									}
								}
								break;
							case '3':
								break;
							case '4':  //뒤로가기
								break;
							case '5':
								delete(In_user);
								notice->Infor_Notice();
								client->Infor_write();
								omokrank->Sort_data_write();
								Clnt->DelSocket(sock, mutex);
								return 0;
							default:
								break;
							}
							if (ch == '4')
								break;
						}
						break;
					case '3': //오목
						while (1){
							char ch;
							//cout << "a" << endl;
							if (sizeof(ch) != recv(sock, &ch, sizeof(char), 0)){
								continue;
							}
							switch (ch){
							case '1':  //매칭 시작
								int approve;
								if((approve = omok->MatchingPlayer(Clnt, sock, mutex)) != 0){
									while (1){
										if (omok->Sendxypos(sock, client, Clnt, omokrank) == -1){
											break;
										}
									}
								}
								break;
							case '2':
								omokrank->OmokRankSend(sock);
								break;
							case '3':
								if (omok->MatchingRoomCreate(sock, mutex) == 1){
									while (1){
										if (omok->Sendxypos(sock, client, Clnt, omokrank) == -1){
											break;
										}
									}
								}
								break;
							case '4':
								if (omok->InMatchingRoom(sock, Clnt, mutex) == 1){
									while (1){
										if (omok->Sendxypos(sock, client, Clnt, omokrank) == -1){
											break;
										}
									}
								}
								break;
							case '5':
								delete(In_user);
								notice->Infor_Notice();
								client->Infor_write();
								omokrank->Sort_data_write();
								Clnt->DelSocket(sock, mutex);
								return 0;
							case '6':
								break;
							default:
								break;
							}
							if (ch == '6')
								break;
						}
						break;
					case '4':
						while (1){
							char ch;
							int room_number = 0;
							int return_number = 0;
							boomroom->BoomRoomList(sock);
							if (sizeof(ch) != recv(sock, &ch, sizeof(char), 0)){
								continue;
							}
							switch (ch){
							case '1':
								room_number = boomroom->BoomRoomCreate(sock, mutex, In_user);
								Node_Boomroom *first;
								for (first = boomroom->head->next; first; first = first->next){
									if (first->room_number == room_number){
										break;
									}
								}
								while (1){
									if ((return_number = boomroom->BoomRoomSendMessage(sock, room_number, In_user->id, mutex, boomman)) == Return_number.Out){
										break;
									}
									else if (return_number == Return_number.GameStart){
										while (1){							
											if (boomman->SendUserData(sock, first,mutex) == false){
												return_number = 0;
												boomroom->DeleteNode(first);
												boomroom->room_number--;
												break;
											}
										}
										break;
									}
								}
								break;
							case '2':
								if (boomroom->BoomRoonIn(sock, mutex, room_number, In_user, boomman) == true){
									Node_Boomroom *first;
									for (first = boomroom->head->next; first; first = first->next){
										if (first->room_number == room_number){
											break;
										}
									}
									while (1){
										if ((return_number = boomroom->BoomRoomSendMessage(sock, room_number, In_user->id, mutex,boomman)) == Return_number.Out){
											break;
										}
										else if (return_number == Return_number.GameStart){
											while (1){
												if (boomman->SendUserData(sock, first,mutex) == false){
													return_number = 0;
													break;
												}
											}
											break;
										}
									}
								}
								break;
							case '3':
								break;
							case '4':
								break;
							case '5':
								delete(In_user);
								notice->Infor_Notice();
								client->Infor_write();
								omokrank->Sort_data_write();
								Clnt->DelSocket(sock, mutex);
								return 0;
							}
							if (ch == '4'){
								break;
							}
						}
						break;
					case '5':  //회원탈퇴
						delnumber = client->member_delete(sock, mutex);
						break;
					case '6':  //개인정보
						client->member_print(sock, In_user);
						break;
					case '7':
						client->pass_chage1(sock, In_user, Clnt);
						break;
					case '8':
						friend_data->RecvRequest(sock,mutex);
						break;
					case '9':
						delete(In_user);
						notice->Infor_Notice();
						client->Infor_write();
						omokrank->Sort_data_write();
						Clnt->DelSocket(sock, mutex);
						return 0;
					default:
						break;
					}
					if (ch == '7' || delnumber == 1 ){
						Clnt->Logout(sock);
						delnumber = 0;
						In_user->id = Null;
						In_user->password = Null;
						break;
					}
				}
			}
			break;
		case '3':
			client->id_search(sock);
			break;
		case '4':
			client->pass_search(sock);
			break;
		case '5':
			delete(In_user);
			notice->Infor_Notice();
			client->Infor_write();
			omokrank->Sort_data_write();
			Clnt->DelSocket(sock, mutex);
			return 0;
		default:
			break;
		}
	}
}
/*notice->Infor_Notice(); // 수정필요
	client->Infor_write();  // 수정필요*/


