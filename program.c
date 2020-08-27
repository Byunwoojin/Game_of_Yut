#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define MAX_NODE 29
#define MAX_NUM 100
#define NONE 0
#define CATCH 10
#define DOUBLE 20
#define FINISH 4
#define SPECIAL 5
#define S_SPECIAL 6
#define P_NUM 3
#define ALL_FINISH 7
#define PLUS 8


typedef struct dll_node_type *dll_node_ptr;
struct dll_node_type{
	dll_node_ptr llink;//직선
	dll_node_ptr d_llink;//대각선
	dll_node_ptr rlink;
	dll_node_ptr d_rlink;
	char data[3];
};
struct s_order {
	int num[MAX_NUM];
	int stone[MAX_NUM];
};

struct player {
	dll_node_ptr stone1;
	dll_node_ptr stone2;
	dll_node_ptr stone3;
	dll_node_ptr team;
	struct s_order score;
	char t_member[P_NUM];
};

struct dll_node_type head, node1, node2, node3, node4, node5, node6, node7, node8, node9;
struct dll_node_type node10, node11, node12, node13, node14, node15, node16, node17, node18, node19;
struct dll_node_type node20, node21, node22, node23, node24, node25, node26, node27, node28, node29;
struct player player1, player2;
dll_node_ptr list;
int turn = 1; int prev_state = 0; int p1_score = 0; int p2_score = 0;
int play_game(struct player *ptr);
int check_node(struct player *player, dll_node_ptr *temp_stone, char new_stone);
int move_stone(struct player *ptr,int i);
void print_game(dll_node_ptr list);
void main() {
	int x = 0;
	int state = 0;

	
	list = &node1;
	node1.llink = &head; node1.rlink = &node2; node1.d_llink = NULL; node1.d_rlink = NULL;
	node2.llink = &node1; node2.rlink = &node3; node2.d_llink = NULL; node2.d_rlink = NULL;
	node3.llink = &node2; node3.rlink = &node4; node3.d_llink = NULL; node3.d_rlink = NULL;
	node4.llink = &node3; node4.rlink = &node5; node4.d_llink = NULL; node4.d_rlink = NULL;
	node5.llink = &node4; node5.rlink = &node6; node5.d_llink = NULL; node5.d_rlink = &node20;

	node6.llink = &node5; node6.rlink = &node7; node6.d_llink = NULL; node6.d_rlink = NULL;
	node7.llink = &node6; node7.rlink = &node8; node7.d_llink = NULL; node7.d_rlink = NULL;
	node8.llink = &node7; node8.rlink = &node9; node8.d_llink = NULL; node8.d_rlink = NULL;
	node9.llink = &node8; node9.rlink = &node10; node9.d_llink = NULL; node9.d_rlink = NULL;
	node10.llink = &node9; node10.rlink = &node11; node10.d_llink = NULL; node10.d_rlink = &node25; //!!^

	node11.llink = &node10; node11.rlink = &node12; node11.d_llink = NULL; node11.d_rlink = NULL;
	node12.llink = &node11; node12.rlink = &node13; node12.d_llink = NULL; node12.d_rlink = NULL;
	node13.llink = &node12; node13.rlink = &node14; node13.d_llink = NULL; node13.d_rlink = NULL;
	node14.llink = &node13; node14.rlink = &node15; node14.d_llink = NULL; node14.d_rlink = NULL;
	node15.llink = &node14; node15.rlink = &node16; node15.d_llink = &node24; node15.d_rlink = NULL; //!!^

	node16.llink = &node15; node16.rlink = &node17; node16.d_llink = NULL; node16.d_rlink = NULL;
	node17.llink = &node16; node17.rlink = &node18; node17.d_llink = NULL; node17.d_rlink = NULL;
	node18.llink = &node17; node18.rlink = &node19; node18.d_llink = NULL; node18.d_rlink = NULL;
	node19.llink = &node18; node19.rlink = &node29; node19.d_llink = NULL; node19.d_rlink = NULL;

	node20.llink = &node5; node20.rlink = &node21; node20.d_llink = NULL;    node20.d_rlink = NULL;
	node21.llink = &node20; node21.rlink = &node22; node21.d_llink = NULL;    node21.d_rlink = NULL;
	node22.llink = &node21; node22.rlink = &node23; node22.d_llink = &node26; node22.d_rlink = &node27; //!!^
	node23.llink = &node22; node23.rlink = &node24; node23.d_llink = NULL;    node23.d_rlink = NULL;
	node24.llink = &node23; node24.rlink = &node15; node24.d_llink = NULL;    node24.d_rlink = NULL;

	node25.llink = NULL;     node25.rlink = &node26;  node25.d_llink = &node10;  node25.d_rlink = NULL;
	node26.llink = &node25;  node26.rlink = &node22;  node26.d_llink = NULL;     node26.d_rlink = NULL;
	node27.llink = &node22;  node27.rlink = &node28;  node27.d_llink = NULL;     node27.d_rlink = NULL;
	node28.llink = &node27;  node28.rlink = &node29;  node28.d_llink = NULL;     node28.d_rlink = NULL;
	node29.llink = &node19;  node29.rlink = &head;    node29.d_llink = &node28;  node29.d_rlink = NULL; //!!^
	head.llink = &node29;    head.rlink =   &node1;   head.d_llink = NULL;       head.d_rlink = NULL;

	player1.stone1 = &head; player1.stone2 = &head; player1.stone3 = &head; player1.team = &head;
	player2.stone1 = &head; player2.stone2 = &head; player2.stone3 = &head; player2.team = &head;
	printf("			                     <윷놀이>\n\n");
	printf("도가 나오면 1, 개가 나오면 2, 걸이 나오면 3, 윷이 나오면 4,모가 나오면 5,백도면 -1을 입력하세요\n\n");

	printf("[ Player1의 말은 A,B,C이고, Player1의 말 중 두개이상의 말이 함께 움직이는 '업은말'을 T라고 지칭합니다.    ]\n");
	printf("[ Player2의 말은 X,Y,Z이고, Player2의 말 중 두개이상의 말이 함께 움직이는 '업은말'을 U라고 지칭합니다.    ]\n");
	printf("[   예시)Player1의 말 A,B가 업은 상태일때, 업은말 'AB'를 움직이고 싶다면, 말 번호에 T를 입력하면 됩니다.  ]\n\n");
	printf("==========================================================================================================\n");
	while (state != ALL_FINISH) {
		turn = 1;
		state=play_game(&player1);
		if (state == ALL_FINISH)break;
		turn = 2;
		printf("--------------------------------------------------------------------------------------------------------\n");
		state=play_game(&player2);
		if (state == ALL_FINISH)break;
		printf("--------------------------------------------------------------------------------------------------------\n");
	}
	
}
int play_game(struct player *ptr) {
	srand(time(NULL));
	struct player *temp = ptr;
	int i = 0; int count = 0; int score = 4; char stone; int j = 0;
	int f_state = 0; int n = 0; int k = 0;
	srand(time(NULL));
	for (count = 0; score == 4 || score == 5; count++) {
		score = rand() % 6;
		if (score == 0)score = -1;
		printf("Player%d이 윷을 던진 결과: %d\n", turn, score);

	}
	while (count == 1) {
		printf("움직일 말의 번호를 입력해주세요(player1: A,B,C,T중에서 /player2: X,Y,Z,U중에서) :"); scanf(" %c", &stone);
		printf("\n");
		temp->score.num[i] = score;
		
		if (stone == 'A' || stone == 'X')temp->score.stone[i] = 1;
		if (stone == 'B' || stone == 'Y')temp->score.stone[i] = 2;
		if (stone == 'C' || stone == 'Z')temp->score.stone[i] = 3;
		if (stone == 'T' || stone == 'U')temp->score.stone[i] = 4;
		 count--;
		f_state=move_stone(ptr, j);
		if (f_state == ALL_FINISH) { printf("\nPlayer%d가 이겼습니다!\n", turn); return ALL_FINISH; }
		if (f_state == CATCH) {
				for (score = 4; score == 4 || score == 5; count++,i++) {
					score = rand() % 6;
					if (score == 0)score = -1;
					printf("Player %d이 추가로 윷을 던진 결과 : %d\n", turn, score); j++; n = j;
				}k = i;
			}
		else i++;
		f_state = 0;
	}
	if (count > 1) {
		printf("<%d개 중 먼저, 실행할 눈과 말의 번호를 차례대로 알려주세요>.\n", count);
		for (j = 0; count > 0 && f_state != FINISH; j++,i++) {
			if (n != 0) { j = n, i = k; }
			printf("\n실행할 눈: "); scanf("%d", &score);
			printf("움직일 말의 번호를 입력해주세요(player1: A,B,C,T중에서 /player2: X,Y,Z,U 중에서):"); scanf(" %c", &stone);
			printf("\n");
			temp->score.num[i] = score;
			if (stone == 'A' || stone == 'X')temp->score.stone[i] = 1;
			if (stone == 'B' || stone == 'Y')temp->score.stone[i] = 2;
			if (stone == 'C' || stone == 'Z')temp->score.stone[i] = 3;
			if (stone == 'T' || stone == 'U')temp->score.stone[i] = 4;
			count--;
		
			f_state = move_stone(ptr, j);
			if (f_state == ALL_FINISH) {
				printf("\nPlayer%d가 이겼습니다!\n", turn); return ALL_FINISH;
			}
			if (f_state == CATCH) {
				score = 4;
				for (score = 4; score == 4 || score == 5; ) {
					score = rand() % 6;
					if (score == 0)score = -1;
					printf("Player %d이 추가로 윷을 던진 결과 : %d ", turn,score); printf("\n"); count++;
					f_state = 0;
				}
			}
			
	}
		
	}
	return 0;
}
	

int move_stone(struct player *ptr,int i) {
	struct player *temp = ptr; dll_node_ptr *temp_stone; int num = 0; int a; char stone_sym; 
	int stone_state = 0; int n = 0; int turn; 
	int x = 0;
	
	if (temp->score.stone[i]) {
		
		prev_state = 0;
		if (temp == &player1)turn = 1;
		if (temp == &player2)turn = 2;
		switch (temp->score.stone[i]) {
		case 1:
			temp_stone = &(temp->stone1);
			if (temp == &player1)stone_sym = 'A';
			if (temp == &player2)stone_sym = 'X';
			break;
		case 2:
			temp_stone = &(temp->stone2);
			if (temp == &player1)stone_sym = 'B';
			if (temp == &player2)stone_sym = 'Y';
			break;
		case 3:
			temp_stone = &(temp->stone3);
			if (temp == &player1)stone_sym = 'C';
			if (temp == &player2)stone_sym = 'Z';
			break;
		case 4:
			temp_stone = &(temp->team);
			if (temp == &player1)stone_sym = 'T';
			if (temp == &player2)stone_sym = 'U';
			break;
		}
		num = temp->score.num[i];
	
		
		if (num!=-1&&(*temp_stone == &node5 || *temp_stone == &node10 )) {
			printf("방향을 고르세요(직진이면 1, 방향을 꺾고 싶으면 2를 입력해주세요) :"); scanf("%d", &a);
			if (a == 2)
				prev_state = SPECIAL;
		}
		if (num!=-1&&(*temp_stone == &node22)) {
			printf("방향을 고르세요( ↘이면 3, ↙이면 4를 입력해주세요) :"); scanf("%d", &a);
			if (a == 3) {
				prev_state = SPECIAL;
			}
		}
		
		if (prev_state == SPECIAL) {
			
			if (num > 0) { *temp_stone = (*temp_stone)->d_rlink; num--; }
		}

		if (num > 0) {

			n = num;
			while (n > 0) {
				*temp_stone = (*temp_stone)->rlink;
				n--;
				if (n >= 2 && (*temp_stone == &node26)) {
					*temp_stone = &node22;
					*temp_stone = (*temp_stone)->d_rlink;
					n = n - 2;
				}
				if (*temp_stone == &node29) {
					if (stone_sym == 'T' || stone_sym == 'U') {
						if (temp == &player1) {
							if (temp->t_member[2]) { p1_score = 3, x = 0; }
							else { p1_score = p1_score + 2, x = 3 - p1_score; }
						}
						if (temp == &player2) {
							if (temp->t_member[2]) { p2_score = 3, x = 0; }
							else { p2_score = p2_score + 2, x = 3 - p2_score; }
						}
						printf("\n말 %c %c %c가 한바퀴를 돌았습니다. 이제 말 %c %c %c는 사용할 수 없습니다.\n", temp->t_member[0], temp->t_member[1], temp->t_member[2], temp->t_member[0], temp->t_member[1], temp->t_member[2]);
						printf("player%d은 현재 말 %d개가 남았습니다.\n\n", turn, x);
						*temp_stone = NULL;

						if (x == 0) { return ALL_FINISH; }
						else break;
					}
					else {
						if (temp == &player1) {
							p1_score++, x = 3 - p1_score;
						}
						if (temp == &player2) {
							p2_score++, x = 3 - p2_score;
						}
						printf("\n말 %c가 한바퀴를 돌았습니다.이제 말%c는 사용할 수 없습니다.\n", stone_sym, stone_sym);
						printf("player%d은 현재 말 %d개가 남았습니다.\n\n", turn, x);
						*temp_stone = NULL;
						if (x == 0)return ALL_FINISH;
						else break;
				
					}

				}
				
			}

		}
		else if (num == -1 && (prev_state == 0)) {
			if (*temp_stone == &head)printf("원점에서 백도이므로, 말을 움직이지 않습니다\n");
			if (*temp_stone == &node22) {
				printf("방향을 고르세요(↖이면 5, ↗이면 6을 입력해주세요) :"); scanf("%d", &a);
				if (a == 5) prev_state = SPECIAL;
			}
			if (*temp_stone == &node15) {
				printf("방향을 고르세요(↑이면 5, ↗이면 6을 입력해주세요) :"); scanf("%d", &a);
				if (a == 6) prev_state = SPECIAL;
			}

			if (prev_state == SPECIAL) {
				if (num == -1) { *temp_stone = (*temp_stone)->d_llink; }
			}
			else 
				if(*temp_stone!=&head)*temp_stone = (*temp_stone)->llink;
		}
		i++;
		stone_state=check_node(temp, temp_stone, stone_sym);
		print_game(list);
		if (stone_state == CATCH) { return CATCH; }
		
	}
	return 0;
}
int check_node(struct player *player, dll_node_ptr *temp_stone, char stone_sym) {
	int c_state = 0; int answer = 0; char a, b; char c = ' ';
	if (*temp_stone != NULL) {
		if ((player == &player1) && *temp_stone != &head) {
			if (temp_stone != &(player1.stone1) && *temp_stone == player1.stone1) {
				if (temp_stone == (&player1.team)) {
					printf("말 %c %c를 A에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", player1.t_member[0], player1.t_member[1]); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player1.team = player1.stone1;
						player1.stone1 = NULL; player1.t_member[2] = 'A';
					}
				}
				else {
					printf("말 %c를 A에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", stone_sym); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player1.team = player1.stone1; player1.stone1 = NULL; *temp_stone = NULL;
						player1.t_member[0] = 'A'; player1.t_member[1] = stone_sym;

					}
				}
			}
			if (temp_stone != &(player1.stone2) && *temp_stone == player1.stone2) {
				if (temp_stone == (&player1.team)) {
					printf("말 %c %c를 B에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", player1.t_member[0], player1.t_member[1]); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player1.team = player1.stone2;
						player1.stone2 = NULL; player1.t_member[2] = 'B';
					}
				}
				else {
					printf("말 %c를 B에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", stone_sym);  scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player1.team = player1.stone2; player1.stone2 = NULL; *temp_stone = NULL;
						player1.t_member[0] = 'B'; player1.t_member[1] = stone_sym;
					}
				}
			}
			if (temp_stone != &(player1.stone3) && *temp_stone == player1.stone3) {
				if (temp_stone == (&player1.team)) {
					printf("말 %c %c를 C에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", player1.t_member[0], player1.t_member[1]); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player1.team = player1.stone3;
						player1.stone3 = NULL; player1.t_member[2] = 'C';
					}
				}
				else {
					printf("말 %c를 C에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", stone_sym); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player1.team = player1.stone3; player1.stone3 = NULL; *temp_stone = NULL;
						player1.t_member[0] = 'C'; player1.t_member[1] = stone_sym;
					}
				}
			}
			if (temp_stone != &(player1.team) && *temp_stone == player1.team) {
				printf("말 %c를 다른 두 말과 업어서, 세말이 모두 함께 이동할거면 1,아니면 2를 입력해주세요 : ", stone_sym); scanf("%d", &answer); printf("\n");
				if (answer == 1) {
					c_state = DOUBLE;
					player1.team = *temp_stone;
					*temp_stone = NULL; player1.t_member[2] = stone_sym;
				}
			}

			if (*temp_stone != NULL) {
				if (*temp_stone == player2.stone1 && (player2.stone1 != &head)) {
					printf("Player2의 말X를 잡았습니다."); c_state = CATCH; player2.stone1 = &head; printf("\n");
				}
				if (*temp_stone == player2.stone2 && (player2.stone2 != &head)) {
					printf("Player2의 말Y를 잡았습니다."); c_state = CATCH; player2.stone2 = &head; printf("\n");
				}
				if (*temp_stone == player2.stone3&(player2.stone3 != &head)) {
					printf("Player2의 말Z를 잡았습니다."); c_state = CATCH; player2.stone3 = &head; printf("\n");
				}
				if (*temp_stone == player2.team) {
					a = player2.t_member[0];
					b = player2.t_member[1];
					if (player2.t_member[2])c = player2.t_member[2];
					printf("Player2의 말 %c %c %c를 잡았습니다.", a, b, c); c_state = CATCH; player2.team = &head; printf("\n");;
				}
				if (c_state == CATCH) {

					printf("player2의 말을 잡았으므로, 한번 더 던질 수 있습니다.\n");
					return CATCH;
					c_state = 0;
				}
			}
		}
		if ((player == &player2) && *temp_stone != &head) {
			if (temp_stone != &(player2.stone1) && *temp_stone == player2.stone1) {
				if (temp_stone == (&player2.team)) {
					printf("말 %c %c를 X에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", player2.t_member[0], player2.t_member[1]); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player2.team = player2.stone1;
						player2.stone1 = NULL; player2.t_member[2] = 'X';
					}
				}
				else {
					printf("말 %c를 X에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", stone_sym);  scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player2.team = player2.stone1; player2.stone1 = NULL; *temp_stone = NULL;
						player2.t_member[0] = 'X'; player2.t_member[1] = stone_sym;
					}
				}
			}
			if (temp_stone != &(player2.stone2) && *temp_stone == player2.stone2) {
				if (temp_stone == (&player2.team)) {
					printf("말 %c %c를 Y에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", player2.t_member[0], player2.t_member[1]); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player2.team = player2.stone2;
						player2.stone2 = NULL; player2.t_member[2] = 'Y';
					}
				}
				else {
					printf("말 %c를 Y에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", stone_sym); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;//2개말이 업은 경우
						player2.team = player2.stone2; player2.stone2 = NULL; *temp_stone = NULL;
						player2.t_member[0] = 'Y'; player2.t_member[1] = stone_sym;
					}
				}
			}
			if (temp_stone != &(player2.stone3) && *temp_stone == player2.stone3) {
				if (temp_stone == (&player2.team)) {
					printf("말 %c %c를 Z에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", player2.t_member[0], player2.t_member[1]); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player2.team = player2.stone3;
						player2.stone3 = NULL; player2.t_member[2] = 'Z';
					}
				}
				else {
					printf("말 %c를 Z에 업어서 함께 이동할거면 1, 아니면 2를 입력해주세요 : ", stone_sym); scanf("%d", &answer); printf("\n");
					if (answer == 1) {
						c_state = DOUBLE;
						player2.team = player2.stone3; player2.stone3 = NULL; *temp_stone = NULL;
						player2.t_member[0] = 'Z'; player2.t_member[1] = stone_sym;
					}
				}
			}
			if (temp_stone != &(player2.team) && *temp_stone == player2.team) {
				printf("말 %c를 다른 두 말과 업어서, 세말이 모두 함께 이동할거면 1,아니면 2를 입력해주세요 : ", stone_sym); scanf("%d", &answer); printf("\n"); //3개가 모두 업을 경우
				if (answer == 1) {
					c_state = DOUBLE;
					player2.team = *temp_stone;
					*temp_stone = NULL; player2.t_member[2] = stone_sym;
				}
			}
			if (*temp_stone != NULL) {
				if (*temp_stone == player1.stone1 && (player1.stone1 != &head)) {
					printf("Player1의 말A를 잡았습니다."); c_state = CATCH; player1.stone1 = &head;  printf("\n");//잡은 경우
				}
				if (*temp_stone == player1.stone2 && (player1.stone2 != &head)) {
					printf("Player1의 말B를 잡았습니다."); c_state = CATCH; player1.stone2 = &head; printf("\n");
				}
				if (*temp_stone == player1.stone3 && (player1.stone3 != &head)) {
					printf("Player1의 말C를 잡았습니다."); c_state = CATCH; player1.stone3 = &head; printf("\n");
				}
				if (*temp_stone == player1.team) {
					a = player1.t_member[0];
					b = player1.t_member[1];
					if (player1.t_member[2])c = player1.t_member[2];
					printf("Player1의 말 %c %c %c를 잡았습니다.", a, b, c); c_state = CATCH; player1.team = &head; printf("\n");;
				}

				if (c_state == CATCH) {
					printf("player1의 말을 잡았으므로, 한번 더 던질 수 있습니다.\n");
					return CATCH;
					c_state = 0;

				}

			}
		}
	}
	return 0;
}

void print_game(dll_node_ptr list) {
	dll_node_ptr temp = &head; char c1[4], c2[4], c3[4]; int state;
	strcpy(c1, "");
	int i; strcpy(node29.data, "O");
	for (i = 1; i <= 29; i++) {
		if (i == 20) { temp = &node5, temp = temp->d_rlink; }
		else if (i == 25) { temp = &node10, temp = temp->d_rlink; }
		else if (i == 28) { temp = &node22, temp = temp->d_rlink; }
		else temp = temp->rlink;


		if (temp != NULL) {

			if (temp == player1.stone1) { strcpy(c1, "A"); state = 1; }
			if (temp == player1.stone2) { strcpy(c1, "B"); state = 1; }
			if (temp == player1.stone3) { strcpy(c1, "C"); state = 1; }
			if (temp == player1.team) {
				state = 1;
				if (player1.stone1 == NULL&&player1.stone2 == NULL&&player1.stone3 != NULL) { strcpy(c1, "A"), strcpy(c2, "B"), strcat(c1, c2); }
				if (player1.stone1 != NULL&&player1.stone2 == NULL&&player1.stone3 == NULL) { strcpy(c1, "B"), strcpy(c2, "C"), strcat(c1, c2); }
				if (player1.stone1 == NULL&&player1.stone2 != NULL&&player1.stone3 == NULL) { strcpy(c1, "A"), strcpy(c2, "C"), strcat(c1, c2); }
				if (player1.stone1 == NULL&&player1.stone2 == NULL&&player1.stone3 == NULL) { strcpy(c1, "A"), strcpy(c2, "B"), strcpy(c3, "C"), strcat(c1, c2), strcat(c1, c3); }
			}

			if (temp == player1.stone1 && (player1.stone1 == player1.stone2)) { strcpy(c1, "AB"); state = 1; }
			if (temp == player1.stone2 && (player1.stone2 == player1.stone3)) { strcpy(c1, "BC"); state = 1; }
			if (temp == player1.stone3 && (player1.stone1 == player1.stone3)) { strcpy(c1, "AC"); state = 1; }
			if (temp == player1.stone1 && (player1.stone1 == player1.stone2) && (player1.stone1 == player1.stone3)) { strcpy(c1, "ABC"); state = 1; }

			if (temp == player2.stone1) { strcpy(c1, "X"); state = 1; }
			if (temp == player2.stone2) { strcpy(c1, "Y"); state = 1; }
			if (temp == player2.stone3) { strcpy(c1, "Z"); state = 1; }
			if (temp == player2.team) {
				state = 1;
				if (player2.stone1 == NULL&&player2.stone2 == NULL&&player2.stone3 != NULL) { strcpy(c1, "X"), strcpy(c2, "Y"), strcat(c1, c2); }
				if (player2.stone1 != NULL&&player2.stone2 == NULL&&player2.stone3 == NULL) { strcpy(c1, "Y"), strcpy(c2, "Z"), strcat(c1, c2); }
				if (player2.stone1 == NULL&&player2.stone2 != NULL&&player2.stone3 == NULL) { strcpy(c1, "X"), strcpy(c2, "Z"), strcat(c1, c2); }
				if (player2.stone1 == NULL&&player2.stone2 == NULL&&player2.stone3 == NULL) { strcpy(c1, "X"), strcpy(c2, "Y"), strcpy(c3, "Z"), strcat(c1, c2), strcat(c1, c3); }
			}

			if (temp == player2.stone1 && (player2.stone1 == player2.stone2)) { strcpy(c1, "XY"); state = 1; }
			if (temp == player2.stone2 && (player2.stone2 == player2.stone3)) { strcpy(c1, "YZ"); state = 1; }
			if (temp == player2.stone3 && (player2.stone1 == player2.stone3)) { strcpy(c1, "XZ"); state = 1; }
			if (temp == player2.stone1 && (player2.stone1 == player2.stone2) && (player2.stone1 == player2.stone3)) { strcpy(c1, "XYZ"); state = 1; }

			if (state == 1) {
				strcpy(temp->data, "");
				strcat(temp->data, c1);

				state = 0;
			}
			else { strcpy(temp->data, "O"); }

			strcpy(c1, "");

		}
	}
	printf("\n");
	printf("%2s -%2s -%2s- %2s -%2s- %2s\n",node10.data,node9.data,node8.data,node7.data,node6.data,node5.data);
	printf("%2s  %2s          %2s  %2s\n", node11.data, node25.data, node20.data, node4.data);
	printf("%2s    %2s     %2s     %2s\n",node12.data,node26.data,node21.data,node3.data);
	printf("          %2s\n",node22.data);
	printf("%2s    %2s     %2s     %2s\n", node13.data, node23.data, node27.data, node2.data);
	printf("%2s  %2s          %2s  %2s\n", node14.data,node24.data, node28.data, node1.data);
	printf("%2s -%2s -%2s -%2s -%2s- %2s (출발지점)\n\n", node15.data, node16.data, node17.data, node18.data, node19.data, node29.data); 
}