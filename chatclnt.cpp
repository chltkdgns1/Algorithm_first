int Stack_Place = 0;
#define _WINDOCK_DEPRECATED_NO_WARINGS
#include <iostream>
#include "Room.h"
#include <process.h>
#include <string>
#include <ctime>
#include <conio.h>
#include "cilent.h"
#include "Notice.h"
#include "other.h"
#include "Omok.h"
#include "OmokRank.h"
#include "BoomRoom.h"
#include "Boomman.h"
#include "MessageFriend.h"
using namespace std;
#define BUF_SIZE 1024
#define TEN 10


void ErrorHandling(char *massage);
void Erase(); // 지우개 함수
void NameSend(SOCKET sock);
bool EixtHandler(string command);
int LineCheck();

unsigned WINAPI MessageFriendthread(void *arg);

unsigned WINAPI Userlistthread(void *arg);

unsigned WINAPI Mainthread(void *arg);

unsigned WINAPI Sendthread(void *arg);
unsigned WINAPI Recvthread(void *arg);

unsigned WINAPI Matchingsend_thread(void *arg);
unsigned WINAPI Matchingrecv_thread(void *arg);
unsigned WINAPI Matchingprint_thread(void *arg);

unsigned WINAPI Time_thread_send(void *arg);
unsigned WINAPI Time_thread_recv(void *arg);

unsigned WINAPI Matching_time_count(void *arg);
unsigned WINAPI Make_friend_thread(void *arg);

unsigned WINAPI Map_data_recv_thread(void *arg);
unsigned WINAPI Map_data_send_thread(void *arg);
int xpos, ypos; //채팅 좌표

string Null;
HANDLE mutex;
Room *room = new Room;
Log *client = new Log;
Link *notice = new Link;
Screen *screen = new Screen;
Omok *omok = new Omok;
Omok_Rank *omokrank = new Omok_Rank;
BoomRoom *boomroom = new BoomRoom;
BoomMan *boomman = new BoomMan;
MessageFriend *friend_data = new MessageFriend;
SOCKET matchsock;      // 상대 소켓
int omokorder = 0;      // 오목 돌 순서
int omokonoff = 0;      // 오목 종료
int matching_print = 0; //로딩 프린트
int loading_time = 0;
int get_time; //오목 시간 //보내는 시간
int assigned_time;// 받는 시간
int lose_end_time = 0;
int win_end_time = 0;

int send_thread_out = 0; //send thread 탈출
int start_game = 0;

int boomgame_end;
TrueFalse truth;

int main(int argc, char *argv[]){
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	HANDLE main_thread;

	if (argc != 3){
		printf("Usage : %s <IP><port>\n", argv[0]);
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		ErrorHandling("WSAStartup() eooror!");
	}

	mutex = CreateMutex(NULL, FALSE, NULL);
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET){
		ErrorHandling("socket() error!");
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(atoi(argv[2]));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("connect() error!");

	system("cls");
	main_thread = (HANDLE)_beginthreadex(NULL, 0, Mainthread, (void*)&hSocket, 0, NULL);
	//recvThread = (HANDLE)_beginthreadex(NULL, 0, Recvthread, (void*)&hSocket, 0, NULL);
	WaitForSingleObject(main_thread, INFINITE);
	//WaitForSingleObject(recvThread, INFINITE);
	closesocket(hSocket);
	WSACleanup();
	return 0;
}

unsigned WINAPI MessageFriendthread(void *Sock){
	SOCKET sock = *((SOCKET*)Sock);
	friend_data->SendMessageFriend(sock,id);
	return 0;
}

unsigned WINAPI Mainthread(void *Sock){
	HANDLE send_thread, recv_thread, matchingrecv_thread, matchingsend_thread;
	HANDLE matching_print_thread, matching_time_count;
	HANDLE make_friend_thread;
	HANDLE User_list_thread;
	HANDLE map_data_recv_thread, map_data_send_thread;
	HANDLE message_friend_thread;
	SOCKET sock = *((SOCKET*)Sock);
	char accept;
	int delnumber = 0;
	TrueFalse truth;
	while (1){
		screen->FirstFace();
		char ch = _getch();
		send(sock, &ch, sizeof(char), 0);
		switch (ch){
		case '1':
			system("cls");
			while (client->Member_Create_first(sock) != true);
			client->Member_Create_second(sock);
			break;
		case '2':
			system("cls");
			if (client->Logins(sock) == true){
				message_friend_thread = (HANDLE)_beginthreadex(NULL, 0, MessageFriendthread, (void*)&sock, 0, NULL);
				while (1){
					friend_data->SetOnSendNumber();
					Stack_Place = 1;
					screen->PrintContents();
					char ch = _getch();
					friend_data->SetOffSendNumber();
					send(sock, &ch, sizeof(char), 0);
					switch (ch){
					case '1':
						while (1){
							friend_data->SetOnSendNumber();
							Stack_Place = 2;
							notice->PrintNoticeList(sock);
							screen->NoticePrint();
							char ch = _getch();
							friend_data->SetOffSendNumber();
							send(sock, &ch, sizeof(char), 0);
							switch (ch){
							case '1': //게시글 쓰기
								system("cls");
								notice->Write(sock);
								break;
							case '2': //게시글 읽기
								system("cls");
								notice->CheckTheNumber(sock);
								break;
							case '3':
								system("cls");
								notice->DeleteWrite(sock);
								break;
							case '4': //아이디 검색
								system("cls");
								notice->Read_ALL(sock);
								break;
							case '5'://내용 검색
								system("cls");
								notice->Read_story(sock);
								break;
							case '6':
								break;
							case '7':
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
							friend_data->SetOnSendNumber();
							Stack_Place = 3;
							system("cls");
							room->FirstPrint(sock);
							char ch = _getch();
							friend_data->SetOffSendNumber();
							send(sock, &ch, sizeof(char), 0);
							switch (ch){
							case '1':
								int create_room_number;
								int create_approve;
								room->RoomCreate(sock);//자동 번호입력
								recv(sock, (char*)&create_room_number, sizeof(int), 0);
								send(sock, (char*)&create_room_number, sizeof(int), 0);
								recv(sock, (char*)&create_approve, sizeof(int), 0);
								send_thread = (HANDLE)_beginthreadex(NULL, 0, Sendthread, (void*)&sock, 0, NULL);
								recv_thread = (HANDLE)_beginthreadex(NULL, 0, Recvthread, (void*)&sock, 0, NULL);
								WaitForSingleObject(send_thread, INFINITE);
								WaitForSingleObject(recv_thread, INFINITE);
								break;
							case '2':
								int in_room_number;
								int in_approve;
								room->RoomIn(sock);//수동 번호입력
								recv(sock, (char*)&in_approve, sizeof(int), 0);
								if (in_approve == 1){
									send_thread = (HANDLE)_beginthreadex(NULL, 0, Sendthread, (void*)&sock, 0, NULL);
									recv_thread = (HANDLE)_beginthreadex(NULL, 0, Recvthread, (void*)&sock, 0, NULL);
									WaitForSingleObject(send_thread, INFINITE);
									WaitForSingleObject(recv_thread, INFINITE);
								}
								else{
									cout << "non approve" << endl;
									Sleep(50);
								}
								break;
							case '3':
								break;
							case '4':
								break;
							case '5':
								return 0;
							default:
								break;
							}
							if (ch == '4')
								break;
						}
						break;
					case '3'://오목
						while (1){
							friend_data->SetOnSendNumber();
							Stack_Place = 4;
							omok->PrintOmok();
							char ch = _getch();
							friend_data->SetOffSendNumber();
							send(sock, &ch, sizeof(char), 0);
							system("cls");
							switch (ch){
							case '1': //매칭시작
								int approve;
								SOCKET matchsocket;
								//매칭 로딩 부분
								matching_print_thread = (HANDLE)_beginthreadex(NULL, 0, Matchingprint_thread, (void*)&sock, 0, NULL);
								recv(sock, (char*)&approve, sizeof(int), 0);
								matching_print = 1;
								system("cls");
								if (approve == 1){
									cout << "Matching player" << endl;
									omok->BordPrint();
									matchingsend_thread = (HANDLE)_beginthreadex(NULL, 0, Matchingsend_thread, (void*)&sock, 0, NULL);
									matchingrecv_thread = (HANDLE)_beginthreadex(NULL, 0, Matchingrecv_thread, (void*)&sock, 0, NULL);
									WaitForSingleObject(matchingsend_thread, INFINITE);
									WaitForSingleObject(matchingrecv_thread, INFINITE);
									break;
								}
								else{
									cout << "Not Search Matching players" << endl;
								}
								break;
							case '2':
								omokrank->PrintRanking(sock);
								break;
							case '3':
								if (omok->MatchingRoomCreate(sock) == 1){
									char matchedplayer;
									matching_print_thread = (HANDLE)_beginthreadex(NULL, 0, Matchingprint_thread, (void*)&sock, 0, NULL);
									matching_time_count = (HANDLE)_beginthreadex(NULL, 0, Matching_time_count, (void*)&sock, 0, NULL);
									recv(sock, &matchedplayer, sizeof(char), 0);
									matching_print = 1;
									loading_time = 1;
									if (matchedplayer == 1){
										cout << "Matching player" << endl;
										omok->BordPrint();
										matchingsend_thread = (HANDLE)_beginthreadex(NULL, 0, Matchingsend_thread, (void*)&sock, 0, NULL);
										matchingrecv_thread = (HANDLE)_beginthreadex(NULL, 0, Matchingrecv_thread, (void*)&sock, 0, NULL);
										WaitForSingleObject(matchingsend_thread, INFINITE);
										WaitForSingleObject(matchingrecv_thread, INFINITE);
									}
									else{
										cout << "Not MatchPlayer" << endl;
									}
									loading_time = 0;
								}
								break;
							case '4':
								if (omok->InMatchingRoom(sock) == 1){
									cout << "Matching player" << endl;
									omok->BordPrint();
									matchingsend_thread = (HANDLE)_beginthreadex(NULL, 0, Matchingsend_thread, (void*)&sock, 0, NULL);
									matchingrecv_thread = (HANDLE)_beginthreadex(NULL, 0, Matchingrecv_thread, (void*)&sock, 0, NULL);
									WaitForSingleObject(matchingsend_thread, INFINITE);
									WaitForSingleObject(matchingrecv_thread, INFINITE);
								}
								break;
							case '5':
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
							friend_data->SetOnSendNumber();
							Stack_Place = 5;
							system("cls");
							boomroom->BoomRoomList(sock);
							char ch = _getch();
							friend_data->SetOffSendNumber();
							send(sock, &ch, sizeof(char), 0);
							switch (ch){
							case '1':
								boomroom->BoomRoomCreate(sock);
								send_thread = (HANDLE)_beginthreadex(NULL, 0, Sendthread, (void*)&sock, 0, NULL);
								recv_thread = (HANDLE)_beginthreadex(NULL, 0, Recvthread, (void*)&sock, 0, NULL);
								WaitForSingleObject(send_thread, INFINITE);
								WaitForSingleObject(recv_thread, INFINITE);
								// recv send 쓰레드 생성
								if (start_game == truth.True){
									system("cls");
									start_game = truth.False;
									boomman->RecvMapdata(sock);
									map_data_send_thread = (HANDLE)_beginthreadex(NULL, 0, Map_data_send_thread, (void*)&sock, 0, NULL);
									map_data_recv_thread = (HANDLE)_beginthreadex(NULL, 0, Map_data_recv_thread, (void*)&sock, 0, NULL);
									WaitForSingleObject(map_data_send_thread, INFINITE);
									WaitForSingleObject(map_data_recv_thread, INFINITE);
									start_game = truth.False;
								}
								break;
							case '2':
								if (boomroom->BoomRoomIn(sock) == true){
									send_thread = (HANDLE)_beginthreadex(NULL, 0, Sendthread, (void*)&sock, 0, NULL);
									recv_thread = (HANDLE)_beginthreadex(NULL, 0, Recvthread, (void*)&sock, 0, NULL);
									WaitForSingleObject(send_thread, INFINITE);
									WaitForSingleObject(recv_thread, INFINITE);
									if (start_game == truth.True){
										system("cls");
										start_game = truth.False;
										boomman->RecvMapdata(sock);
										map_data_send_thread = (HANDLE)_beginthreadex(NULL, 0, Map_data_send_thread, (void*)&sock, 0, NULL);
										map_data_recv_thread = (HANDLE)_beginthreadex(NULL, 0, Map_data_recv_thread, (void*)&sock, 0, NULL);
										WaitForSingleObject(map_data_send_thread, INFINITE);
										WaitForSingleObject(map_data_recv_thread, INFINITE);
										start_game = truth.False;
									}
								}
								break;
							case '3':
								break;
							case '4':
								break;
							case '5':
								return 0;
							}
							if (ch == '4'){
								break;
							}
						}
						break;
					case '5'://회원탈퇴
						delnumber = client->member_delete(sock);
						break;
					case '6':  //개인정보
						client->member_print(sock);
						break;
					case '7': //비밀번호 변경
						client->pass_chage1(sock);
						break;
					case '8':
						friend_data->RequestFriend(sock,id);
						break;
					case '9':
						return 0;
					default:
						break;
					}
					if (ch == '7' || delnumber == 1 ){
						delnumber = 0;
						id = Null;
						pass = Null;
						break;
					}
				}
			}
			break;
		case '3':
			system("cls");
			client->id_search(sock);
			Sleep(2000);
			break;
		case '4':
			system("cls");
			client->pass_search(sock);
			Sleep(2000);
			break;
		case '5':
			return 0;
		default:
			break;
		}
		system("cls");
	}
}

unsigned WINAPI Make_friend_thread(void *Sock){
	return 0;
}

unsigned WINAPI Map_data_send_thread(void *arg){
	SOCKET sock = *((SOCKET*)arg);
	int get_time = 0;
	int hpup_time = 0;
	while (1){
		if (_kbhit()){
			boomman->PlayMove(sock);
		}
		else{
			if (boomman->charecter == 3){
				if (GetTickCount() - get_time > 1500){
					boomman->StopMove(sock);
					get_time = GetTickCount();
				}
			}
			else{
				if (GetTickCount() - get_time > 900){
					boomman->StopMove(sock);
					get_time = GetTickCount();
				}
			}
		}
		if (boomman->charecter == 2){
			if (GetTickCount() - hpup_time > 400){
				if (boomman->hp < boomman->maxhp){
					boomman->hp++;
					boomman->StopMove(sock);
				}
				hpup_time = GetTickCount();
			}
		}
		else{
			if (GetTickCount() - hpup_time > 2000){
				if (boomman->hp < boomman->maxhp){
					boomman->hp++;
					boomman->StopMove(sock);
				}
				hpup_time = GetTickCount();
			}
		}
		if (boomgame_end == -1){
			boomgame_end = 0;
			Sleep(5000);
			return 0;
		}
	}
	return 0;
}

unsigned WINAPI Map_data_recv_thread(void *arg){
	SOCKET sock = *((SOCKET*)arg);
	while (1){
		if (boomman->RecvUserData(sock) == false){
			boomgame_end = -1;
			return 0;
		}
	}
	return 0;
}

unsigned WINAPI Sendthread(void *Sock){
	fflush(stdin);
	cout << "input command /help" << endl;
	WaitForSingleObject(mutex, INFINITE);
	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	xpos = SBInfo.dwCursorPosition.X; ypos = SBInfo.dwCursorPosition.Y;
	ReleaseMutex(mutex);
	gotoxy(xpos, ypos + TEN);
	SOCKET sock = *(SOCKET*)Sock;
	cout << "----------------------------------------------" << endl;
	cout << "Text : ";
	while (1){
		Messagedata message_data;
		struct tm t;
		time_t times;
		int UpLine = 0;
		int DownLine = 0;
		if (_kbhit()){
			gotoxy(xpos, ypos + TEN);
			cout << "----------------------------------------------" << endl;
			char message[BUF_SIZE] = {};
			cout << "Text : ";
			cin.getline(message, BUF_SIZE);
			fflush(stdin);
			string command;

			command = message;
			if (command.compare("/help") == 0){
				UpLine = LineCheck() - 1;
				gotoxy(xpos, UpLine);
				cout << "                  " << endl;
				cout << "/set game map 'number'" << endl;
				cout << "/set start game" << endl;
				cout << "/set select charecter 'number'" << endl;
				cout << "charecter 1 is warrier" << endl;
				cout << "charecter 2 is magician" << endl;
				cout << "charecter 3 is assassin" << endl;
				cout << "when you dont select charecter auto warrier select" << endl;
				cout << "when you dont select map auto number 1 select" << endl;
	        continue;
			}

			times = time(NULL);
			localtime_s(&t, &times);

			gotoxy(xpos, ypos + TEN);
			Erase();
			gotoxy(xpos, ypos);
			UpLine = LineCheck();

			Str(message_data.message, message);
			message_data.time = times;
			send(sock, (char*)&message_data, sizeof(message_data), 0);

			string temp = message; // exit 판별
			if (temp.compare("/exit") == 0){
				return 0;
			}

			cout << t.tm_year + 1900 << "." << t.tm_mon + 1 << "." << t.tm_mday << "." << t.tm_hour << ":" << t.tm_min << " " << "[" << id << "] : " << message << endl;
			DownLine = LineCheck();
			Erase();
			WaitForSingleObject(mutex, INFINITE);
			ypos = ypos + DownLine - UpLine;
			ReleaseMutex(mutex);
			gotoxy(xpos, ypos + TEN);
			cout << "----------------------------------------------" << endl;
			cout << "Text : ";
		}
		if (send_thread_out == truth.True){
			send_thread_out = truth.False;
			message_data.time = 0;
			start_game = truth.True;
			send(sock, (char*)&message_data, sizeof(message_data), 0);
			return 0;
		}
	}
	return 0;
}

unsigned WINAPI Recvthread(void *Sock){
	SOCKET sock = *((SOCKET*)Sock);
	while (1){
		int UpLine = 0;
		int DownLine = 0;
		Messagedata message_data;
		if (sizeof(message_data) != recv(sock, (char*)&message_data, sizeof(message_data), 0)){
			continue;
		};
		string temp = message_data.message; // exit 판별
		if (EixtHandler(temp) == false){
			return 0;
		}
		struct tm t;
		time_t times = message_data.time;
		localtime_s(&t, &times);
		gotoxy(xpos, ypos);
		UpLine = LineCheck();
		cout << t.tm_year + 1900 << "." << t.tm_mon + 1 << "." << t.tm_mday << "." << t.tm_hour << ":" << t.tm_min << " " << "[" << message_data.name << "] : " << message_data.message << endl;
		DownLine = LineCheck();
		WaitForSingleObject(mutex, INFINITE);
		ypos = ypos + DownLine - UpLine;
		ReleaseMutex(mutex);
		gotoxy(xpos, ypos + TEN - (DownLine - UpLine));
		Erase();
		gotoxy(xpos, ypos + TEN);
		cout << "----------------------------------------------" << endl;
		cout << "Text : ";
		gotoxy(xpos + TEN - 3, ypos + TEN + 1);
	}
	return 0;
}
bool EixtHandler(string command){
	if (command.compare("/exit") == 0){
		return false;
	}
	else if (command.compare("start wait 0..") == 0){
		send_thread_out = truth.True;
		return false;
	}
}


unsigned WINAPI Matching_time_count(void *Sock){
	SOCKET sock = *((SOCKET*)Sock);
	int get_time = 0;
	int count = 0;
	char approve;
	while (1){
		if (GetTickCount() - get_time > 60000){
			approve = -1;
			get_time = GetTickCount();
			if (count == 1){
				send(sock, &approve, sizeof(char), 0);
				return 0;
			}
			count++;
		}
		if (loading_time == 1){
			approve = 1;
			send(sock, &approve, sizeof(char), 0);
			loading_time = 0;
			return 0;
		}
	}
	return 0;
}

unsigned WINAPI Matchingprint_thread(void *Sock){

	class Matchprint{
	public:
		int get_time;
		int xpos, ypos;
		int loding_time;
		int temp;
		Matchprint() :get_time(0), loding_time(0){}
	};
	//	int get_time=0;   //다이아몬드 출력
	//	int x = 30, y = 10;
	//	int xpos = 30, ypos = 24;
	//	int loding_time;  //로딩 출력
	int count = 0;
	int printcount = 0;
	int mode = 0;
	int i = 0;
	string loding = "Loding match..................";
	Matchprint dia_print;
	Matchprint loding_print;
	dia_print.xpos = 30, dia_print.ypos = 10;
	loding_print.xpos = 23, loding_print.ypos = 20;
	loding_print.temp = 23;
	while (1){
		if (mode == 0){
			if (count == 0){
				if (GetTickCount() - dia_print.get_time > 300){
					gotoxy(dia_print.xpos, dia_print.ypos);
					cout << "*";
					dia_print.xpos++, dia_print.ypos++;
					dia_print.get_time = GetTickCount();
					printcount++;
					if (printcount == 4){
						count++;
						printcount = 0;
					}
				}
			}
			else if (count == 1){
				if (GetTickCount() - dia_print.get_time > 300){
					gotoxy(dia_print.xpos, dia_print.ypos);
					cout << "*";
					dia_print.xpos--, dia_print.ypos++;
					dia_print.get_time = GetTickCount();
					printcount++;
					if (printcount == 4){
						count++;
						printcount = 0;
					}
				}
			}
			else if (count == 2){
				if (GetTickCount() - dia_print.get_time > 300){
					gotoxy(dia_print.xpos, dia_print.ypos);
					cout << "*";
					dia_print.xpos--, dia_print.ypos--;
					dia_print.get_time = GetTickCount();
					printcount++;
					if (printcount == 4){
						count++;
						printcount = 0;
					}
				}
			}
			else if (count == 3){
				if (GetTickCount() - dia_print.get_time > 300){
					gotoxy(dia_print.xpos, dia_print.ypos);
					cout << "*";
					dia_print.xpos++, dia_print.ypos--;
					dia_print.get_time = GetTickCount();
					printcount++;
					if (printcount == 4){
						count = 0;
						printcount = 0;
						mode = 1;
					}
				}
			}
			if (GetTickCount() - loding_print.get_time > 300){
				gotoxy(loding_print.xpos, loding_print.ypos);
				cout << loding.at(i);
				loding_print.xpos++;
				loding_print.get_time = GetTickCount();
				i++;
			}
			if (mode == 1){
				loding_print.xpos = loding_print.temp;
				i = 0;
			}
		}
		else{
			if (count == 0){
				if (GetTickCount() - dia_print.get_time > 300){
					gotoxy(dia_print.xpos, dia_print.ypos);
					cout << " ";
					dia_print.xpos++, dia_print.ypos++;
					dia_print.get_time = GetTickCount();
					printcount++;
					if (printcount == 4){
						count++;
						printcount = 0;
					}
				}
			}
			else if (count == 1){
				if (GetTickCount() - dia_print.get_time > 300){
					gotoxy(dia_print.xpos, dia_print.ypos);
					cout << " ";
					dia_print.xpos--, dia_print.ypos++;
					dia_print.get_time = GetTickCount();
					printcount++;
					if (printcount == 4){
						count++;
						printcount = 0;
					}
				}
			}
			else if (count == 2){
				if (GetTickCount() - dia_print.get_time > 300){
					gotoxy(dia_print.xpos, dia_print.ypos);
					cout << " ";
					dia_print.xpos--, dia_print.ypos--;
					dia_print.get_time = GetTickCount();
					printcount++;
					if (printcount == 4){
						count++;
						printcount = 0;
					}
				}
			}
			else if (count == 3){
				if (GetTickCount() - dia_print.get_time > 300){
					gotoxy(dia_print.xpos, dia_print.ypos);
					cout << " ";
					dia_print.xpos++, dia_print.ypos--;
					dia_print.get_time = GetTickCount();
					printcount++;
					if (printcount == 4){
						count = 0;
						printcount = 0;
						mode = 0;
					}
				}
			}
			if (GetTickCount() - loding_print.get_time > 300){
				gotoxy(loding_print.xpos, loding_print.ypos);
				cout << " ";
				loding_print.xpos++;
				loding_print.get_time = GetTickCount();
			}
			if (mode == 0){
				loding_print.xpos = loding_print.temp;
			}
		}
		if (matching_print == 1){
			matching_print = 0;
			break;
		}
	}
	return 0;
}

struct omokdatastruct{
	string omokid;
	string omokmatchid;
	int win;
	int lose;
	int tear;
	int matwin;
	int matlose;
	int mattear;
};

omokdatastruct omokdatastructnode; // 오목 유저 데이터

struct omokdata{
	int win; //자신의 승리
	int lose; //자신의 패배
	int tear; // 자신의 티어
	int matchwin; //상대의 승리
	int matchlose;//자신의 패배
	int matchtear;//자신의 티어
	int color;
	SOCKET sock;
	char matchid[GENERAL_SIZE];
	char id[GENERAL_SIZE];
};


struct xypos{
	int x;
	int y;
	int color;
	int win;
	//
	int withdraw;
	//
	char id[GENERAL_SIZE];
	SOCKET matchsock;
};

unsigned WINAPI Matchingsend_thread(void *Sock){ //오목 데이타 보냄
	SOCKET sock = *((SOCKET*)Sock);
	HANDLE time_thread;
	int return_number;
	int print_time = 0;
	int print_time_erase = 0;
	Time_struct time;
	get_time = ((GetTickCount() + 90000) / 1000) * 60;
	//time_thread = (HANDLE)_beginthreadex(NULL, 0, Time_thread_send, (void*)&sock, 0, NULL);
	Sleep(2000);
	gotoxyomok(omok->x, omok->y);
	if (omok->Eggnum == 0)
		omok->Print_whiteegg();
	else
		omok->Print_blackegg();
	while (1){
		if (omok->Eggnum != -1 && omokorder == 1){
			if ((return_number = omok->Move_Egg()) == 1){
				omok->PrintEggStone();
				xypos pos;
				pos.x = omok->x;
				pos.y = omok->y;
				pos.color = omok->Eggnum;
				pos.matchsock = matchsock;
				pos.win = 0;   // 승패 미결정
				omokorder = 0;
				assigned_time = ((GetTickCount() + 90000) / 1000) * 60;
				send(sock, (char*)&pos, sizeof(pos), 0);
			}
			else if (return_number == 2){
				//cout << "승리자 리턴" << endl;
				omok->PrintEggStone();
				//win_end_time = 1;
				lose_end_time = 1;
				xypos pos;
				pos.x = omok->x;
				pos.y = omok->y;
				pos.color = omok->Eggnum;
				pos.matchsock = matchsock;
				pos.win = 1; // 승리 
				Str(pos.id, omokdatastructnode.omokid.c_str());
				send(sock, (char*)&pos, sizeof(pos), 0);
				gotoxy(11, 10);
				RED;
				cout << "-------Win-------" << endl;
				WHITE;
				WaitForSingleObject(mutex, INFINITE);
				omok->ALLDataRemove();
				omokorder = 0;
				//win_end_time = 0;
				lose_end_time = 0;
				ReleaseMutex(mutex);
				Sleep(3000);
				system("cls");
				return 0;
			}
			//
			else if (return_number == 3){
				lose_end_time = 1;
				xypos pos;
				pos.matchsock = matchsock;
				pos.win = -2; // 기권
				pos.withdraw = 1;
				Str(pos.id, omokdatastructnode.omokid.c_str());
				send(sock, (char*)&pos, sizeof(pos), 0);
				gotoxy(11, 10);
				RED;
				cout << "-------lose-------" << endl;
				WHITE;
				WaitForSingleObject(mutex, INFINITE);
				omok->ALLDataRemove();
				omokorder = 0;
				lose_end_time = 0;
				ReleaseMutex(mutex);
				Sleep(3000);
				system("cls");
				return 0;
			}
			//
			else if (lose_end_time == 1){
				//cout << "패배자의 센더 리턴" << endl;
				lose_end_time = 0;
				xypos pos;
				pos.matchsock = matchsock;
				pos.win = -2; // 시간초 패배
				Str(pos.id, omokdatastructnode.omokid.c_str());
				send(sock, (char*)&pos, sizeof(pos), 0);
				gotoxy(11, 10);
				RED;
				cout << "-------lose-------" << endl;
				WHITE;
				WaitForSingleObject(mutex, INFINITE);
				omok->ALLDataRemove();
				omokorder = 0;
				ReleaseMutex(mutex);
				Sleep(3000);
				system("cls");
				return 0;
			}
			if (GetTickCount() - print_time > 1000){
				time.TimeCount(get_time);
				if (GetTickCount() - print_time_erase > 2000){
					gotoxy(60, 22);
					cout << " ";
					print_time_erase = GetTickCount();
				}
				gotoxy(55, 22);
				cout << time.minute << " : " << time.second;
				if (time.minute <= 0 && time.second <= 0){
					Sleep(2000);
					lose_end_time = 1;
				}
				print_time = GetTickCount();
			}
			/*else{
				omok->PrintEggStone();
				continue;
				}*/
		}
		else if (omokonoff == 1){
			omokonoff = 0;
			//cout << "승리자의 센더 리턴";
			//cout << "패배자의 센더 리턴" << endl;
			return 0;
		}
	}
	//오목 내용
}

unsigned WINAPI Matchingrecv_thread(void *Sock){ //오목 데이터 받음
	SOCKET sock = *((SOCKET*)Sock);
	omokdata data;
	HANDLE time_thread;
	recv(sock, (char*)&data, sizeof(data), 0);
	omok->Eggnum = data.color;
	omokorder = data.color;
	matchsock = data.sock;
	omokdatastructnode.omokid = data.id;
	omokdatastructnode.omokmatchid = data.matchid;
	// 추가 2015 11 06
	omokdatastructnode.win = data.win;
	omokdatastructnode.lose = data.lose;
	omokdatastructnode.tear = data.tear;
	omokdatastructnode.matwin = data.matchwin;
	omokdatastructnode.matlose = data.matchlose;
	omokdatastructnode.mattear = data.matchtear;
	gotoxy(3, 22);
	cout << "MatchPlayer : " << omokdatastructnode.omokid << "  " << omokdatastructnode.win << " Win " << omokdatastructnode.lose << " Lose " << omokdatastructnode.tear << " tear" << endl;
	gotoxy(3, 23);
	cout << "MatchPlayer : " << omokdatastructnode.omokmatchid << "  " << omokdatastructnode.matwin << " Win " << omokdatastructnode.matlose << " Lose " << omokdatastructnode.mattear << " tear" << endl;
	gotoxy(3, 21);
	cout << "1 key WITHDRAW";
	Sleep(1000);
	// 추가 2015 11 06
	time_thread = (HANDLE)_beginthreadex(NULL, 0, Time_thread_recv, (void*)&sock, 0, NULL);
	while (1){
		xypos pos;
		recv(sock, (char*)&pos, sizeof(pos), 0);
		get_time = ((GetTickCount() + 90000) / 1000) * 60;
		Node_Omok *New = new Node_Omok(pos.x, pos.y, pos.color);
		omok->Linklist(New);
		if (pos.matchsock == matchsock){
			//cout << "패배자의 리시버 리턴" << endl;
			//	cout << "승리자 리시버 리턴" << endl;
			return 0;
		}
		else if (pos.withdraw == 1){
			lose_end_time = 1;
			omokonoff = 1;
			gotoxy(11, 10);
			RED;
			cout << "-------Win-------" << endl;
			WHITE;
			pos.win = 2;
			Str(pos.id, omokdatastructnode.omokid.c_str());
			send(sock, (char*)&pos, sizeof(pos), 0);
			WaitForSingleObject(mutex, INFINITE);
			omokorder = 0;
			lose_end_time = 0;
			omok->ALLDataRemove();
			ReleaseMutex(mutex);
			Sleep(3000);
			system("cls");
			return 0;
		}

		else if (win_end_time == 1){
			win_end_time = 0;
			//	cout << "승리자의 리시버 리턴";
			omokonoff = 1;
			gotoxy(11, 10);
			RED;
			cout << "-------Win-------" << endl;
			WHITE;
			pos.win = 2;
			Str(pos.id, omokdatastructnode.omokid.c_str());
			send(sock, (char*)&pos, sizeof(pos), 0);
			WaitForSingleObject(mutex, INFINITE);
			omokorder = 0;
			omok->ALLDataRemove();
			ReleaseMutex(mutex);
			Sleep(3000);
			system("cls");
			return 0;
		}
		omok->PrintEggStone();
		if (omok->OmokWinRule(New) == 1){
			omokonoff = 1;
			//win_end_time = 1;
			lose_end_time = 1;
			//	cout << "패배자 리시버 리턴" << endl;
			gotoxy(11, 10);
			RED;
			cout << "-------lose-------" << endl;
			WHITE;
			pos.win = -1;
			Str(pos.id, omokdatastructnode.omokid.c_str());
			send(sock, (char*)&pos, sizeof(pos), 0);
			WaitForSingleObject(mutex, INFINITE);
			omokorder = 0;
			omok->ALLDataRemove();
			win_end_time = 0;
			lose_end_time = 0;
			ReleaseMutex(mutex);
			Sleep(3000);
			system("cls");
			return 0;
		}
		omokorder = 1;
	}
	//오목 내용
}

/*unsigned WINAPI Time_thread_send(void *Sock){  //센드 //0초가 됬을때 자기가 패배
	Time_struct time;
	get_time = ((GetTickCount() + 90000) / 1000) * 60;
	int print_time = 0;
	int print_time_erase = 0;
	while (1){
	if (omokorder == 1){
	if (_kbhit()){
	continue;
	}
	if (GetTickCount() - print_time > 1000){
	time.TimeCount(get_time);
	if (GetTickCount() - print_time_erase > 2000){
	gotoxy(60, 22);
	cout << " ";
	print_time_erase = GetTickCount();
	}
	gotoxy(55, 22);
	cout << time.minute << " : " << time.second;
	if (time.minute <= 0 && time.second <= 0){
	Sleep(2000);
	lose_end_time = 1;
	return 0;
	}
	print_time = GetTickCount();
	}
	}
	if (win_end_time == 1){
	//cout << "승리 센드 타임의 링턴";
	return 0;
	}
	}
	}*/


unsigned WINAPI Time_thread_recv(void *Sock){ //리시브  0초가되면 승리
	int print_time = 0;
	int print_time_erase = 0;
	Time_struct time;
	assigned_time = ((GetTickCount() + 90000) / 1000) * 60;
	while (1){
		if (omokorder == 0){
			if (GetTickCount() - print_time > 1000){
				time.TimeCount(assigned_time);
				if (GetTickCount() - print_time_erase > 2000){
					gotoxy(60, 23);
					cout << " ";
					print_time_erase = GetTickCount();
				}
				gotoxy(55, 23);
				cout << time.minute << " : " << time.second;
				if (time.minute <= 0 && time.second <= 0){
					win_end_time = 1;
					return 0;
				}
				print_time = GetTickCount();
			}
		}
		if (lose_end_time == 1){
			return 0;
		}
	}
}
void Erase(){
	for (int i = 0; i < 3; i++){
		cout << "                                                                                 " << endl;
	}
}

int LineCheck(){
	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	return SBInfo.dwCursorPosition.Y;
}

void ErrorHandling(char *message){
	fputs(message, stderr);
	    fputc('\n', stderr);
	exit(1);
}

