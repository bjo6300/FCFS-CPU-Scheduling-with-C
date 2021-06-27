#ifdef  _MSC_VER
#define _CRT_SECURE_NO_WARNINGS  //fopen, scanf 사용하기 위해 정의
#endif //  _MSC_VER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* node_pointer;
struct node //노드 정의
{
	int type;
	int priority;
	int computing_time;
	int process_id;
	int turn_around_time;
	node_pointer next;
};

typedef struct queue_head* head_pointer;
struct queue_head {
	node_pointer	left_link;
	node_pointer	right_link;
};

head_pointer q_head; // 전역변수로 큐 생성

int arrive_time = 0; // 도착시간(time_quantum)
int end_time = 0;  // 종료시간
int count = 0; //프로세스 개수
double ntt = 0; //normalized turnaround time

void init_queue(void);
int insert_queue(int, int, int, int);
void print_q(void);
void n_time(void);


int main() {
	FILE* fp;
	int type, priority, computing_time, process_id;

	init_queue(); //큐 초기화

	fp = fopen("input_file.txt", "r");  //input_file.txt에서 type, priority, computing_time을 받아옴

	if ((fp = fopen("input_file.txt", "r")) == NULL) {
		printf("현재 디렉토리내에 input_file.txt 파일이 있는지 확인해주세요.\n");
	}
	else {
		while (fscanf(fp, "%d %d %d %d", &type, &process_id, &priority, &computing_time) != EOF) {
			if (type == -1) break;
			else if (type == 1) {
				arrive_time += 20;
				
			}
			else
			{
				insert_queue(type, process_id, priority, computing_time);
				count++;
			}
		}
	}
	print_q();
	n_time();
	printf("\nNormalized turn around time : %lf초\n", ntt/count);
	
	fclose(fp);

	return 0;

}

void init_queue(void) {  // 큐 초기화
	q_head = (head_pointer)malloc(sizeof(struct queue_head));
	q_head->left_link = q_head->right_link = NULL;
}

int insert_queue(int type, int process_id, int priority, int computing_time) {
	node_pointer q = (node_pointer)malloc(sizeof(struct node));

	q->type = type;
	q->process_id = process_id;
	q->priority = priority;
	q->computing_time = computing_time; 
	end_time += computing_time;
	q->turn_around_time = end_time - arrive_time;
	q->next = NULL;

	// 큐에 추가
	if (q_head->right_link == NULL) {  // 맨 앞 노드일때
		q_head->right_link = q;
		q_head->left_link = q;  //left_link는 첫 노드
		return 0;
	}
	else  // 중간 노드일때
		q_head->right_link->next = q;  
	
	q_head->right_link = q;

	return 0;
}

void print_q() {
	node_pointer tmp = (node_pointer)malloc(sizeof(struct node));

	tmp = q_head->left_link;
	printf("process_id\t priority\t computing_time\t turn_around_time\n");
	while (tmp != NULL) {
		printf("%d\t\t %d\t\t %d\t\t %d\t\t \n", tmp->process_id, tmp->priority, tmp->computing_time,tmp->turn_around_time);
		if (tmp->next == NULL) {
			break;
		}
		tmp = tmp->next;
		
	}
}

void n_time() {  // normalized turnaround time

	node_pointer pt = (node_pointer)malloc(sizeof(struct node));

	pt = q_head->left_link; // 처음 인덱스로 이동
	
	while (pt != NULL) {
		ntt = ((double)pt->turn_around_time / (double)pt->computing_time) + ntt;
		pt = pt->next;
	}
}