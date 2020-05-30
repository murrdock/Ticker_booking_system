// action.h file

#ifndef _action_h
#define _action_h

#define PORT 12385
#define PASS_LENGTH 20
#define TRAIN "./db/train"
#define BOOKING "./db/booking"

struct account{
	int id;
	char name[10];
	char pass[PASS_LENGTH];
};

struct train{
	int tid;
	char train_name[20];
	int train_no;
	int av_seats;
	int last_seatno_used;
};

struct bookings{
	int bid;
	int type;
	int acc_no;
	int tr_id;
	char trainname[20];
	int seat_start;
	int seat_end;
	int cancelled;
};

void service_cli(int sock);
int login(int sock);
int signup(int sock);
int menu2(int sock, int id);
int menu1(int sock, int id, int type);
void view_booking(int sock, int id, int type);
void view_booking2(int sock, int id, int type, int fd);
void sigstop_sigkill_handler(int sig);

#endif
